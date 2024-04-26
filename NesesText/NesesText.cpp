// NesesText.cpp : Defines the entry point for the application.
//

#include "NesesText.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include "win1254_table.hpp"
#include "BackObject.hpp"
using namespace std;


std::string Win1254ToUtf8(std::string trstr)
{
	std::string back;

	const size_t len = trstr.length();

	unsigned char src;
	char32_t dst;
	std::stringstream ss;

	unsigned char byte4;		// byte order soldan sağa ise msb
	unsigned char byte3;
	unsigned char byte2;
	unsigned char byte1;		// byte order soldan sağa ise lsb


	for (int i = 0; i < len; i++)
	{
		src = trstr[i];
	

		if (src < 0x80)
		{
			dst = src;
			back += src;
		}
		else
		{
			dst = std::get<1>(win1254map[src]);			
		}

		//std::cout << std::setfill('0') << std::setw(2) << std::hex << (0xff & (unsigned int)src);
		std::cout << "src : " << std::setw(2) << std::hex << (0xff & src) 
				 <<  "\tdst : " << std::setw(2) << std::hex << (0xffffffff & dst) << std::endl;
	


		// dst kaç byte geldi

		byte4 = (dst & 0xFF000000) >> 24;
		byte3 = (dst & 0x00FF0000) >> 16;
		byte2 = (dst & 0x0000FF00) >> 8;
		byte1 = (dst & 0x000000FF);

		if (byte4 > 0)
			ss << byte4;
		if (byte3 > 0)
			ss << byte3;
		if (byte2 > 0)
			ss << byte2;
		if (byte1 > 0)
			ss << byte1;
	}
	back = ss.str();
	return back;
}

constexpr uint8_t GetUnitSizeFCp(const char32_t codepoint) noexcept
{
	return 1U + (codepoint >= 0x80) + (codepoint >= 0x800) + (codepoint >= 0x10000);
}

constexpr uint8_t GetUnitSizeFB(const char32_t utf) noexcept
{
	return 1U + (utf > 0x7FF) + (utf > 0xFFFF) + (utf >= 0x10000);
}

int UCodePoint_To_8CodeUnit(const char32_t cp, char32_t& utf)
{
	// https://en.wikipedia.org/wiki/UTF-8


	uint8_t byte4;
	uint8_t byte3;
	uint8_t byte2;
	uint8_t byte1;

	/*
	0x1F =  0001 1111				? & 0x1F => sagdan 5 biti al
	0xC0 =  1100 0000				? | 0xC0 => 7. ve 8. bitleri set et, 6. biti resetle, bu 2 bayt olduğunu gösteren işaret

	0x3F =  0011 1111				? & 0x3F => sagdan 6 biti al
	0x80 =  1000 0000				? | 0x80 => byte'ın 8.biti set et, 7. biti resetle, bu da devam byte'ı olduğunu göstermek için

	0x0F =  0000 1111
	0xE0 =  1110 0000				? & 0xE0 => 8.,7.,6. biti set et, 5. biti resetle, bu 3 bayt olduğunu gösterir

	0x07 =  0000 0111
	0xF0 =  1111 0000				? & 0xF0 => 8.,7.,6.,5. biti set et, 4. biti resetle, bu da 4 bayt olduğunu gösterir
	*/

	utf = 0x0;

	// 1 byte aynen al
	if (cp <= 0x7F)
	{
		utf = 0x7F;
		return 1; 
	}

	// 2 byte
	if (cp <= 0x7FF)
	{
		byte2 = ((cp >> 6) & 0x1F) | 0xC0;
		byte1 = (cp & 0x3F) | 0x80;
		utf = (byte2 << 8) | byte1;
		return 2;
	}

	// 3 byte
	if (cp <= 0xFFFF)
	{
		byte3 = ((cp >> 12) & 0x0F) | 0xE0;
		byte2 = ((cp >> 6) & 0x3F) | 0x80;
		byte1 = (cp & 0x3F) | 0x80;
		utf = (byte3 << 16) | (byte2 << 8) | byte1;
		return 3;
	}

	// 4 byte
	if (cp <= 0x10FFFF)
	{
		byte4 = ((cp >> 18) & 0x07) | 0xF0;
		byte3 = ((cp >> 12) & 0x3F) | 0x80;
		byte2 = ((cp >> 6) & 0x3F) | 0x80;
		byte1 = (cp & 0x3F) | 0x80;
		utf = (byte3 << 24) | (byte3 << 16) | (byte2 << 8) | byte1;			// byteları birleştir
		return 4;
	}


	return -1;
}




BackObject Win1254ToUtf8_2(const std::string& srcStr, std::string& dstStr)
{
	BackObject back;

	/*
	U+FFFD The replacement character �  often displayed as a black rhombus with a white question mark
	
	*/

	const size_t len = srcStr.length();	
	if (len == 0)
	{
		back.Success = false;
		back.ErrDesc = "empty input string";
		return back;
	}
	uint8_t src;
	char32_t dst;
	std::stringstream ss;

	uint8_t byte4;
	uint8_t byte3;
	uint8_t byte2;
	uint8_t byte1;
	uint8_t unitsize = 0;

	for (std::size_t i = 0; i < len; i++)
	{
		src = srcStr[i];

		dst = 0xFFFF;  // undefined char

		if (!(src < 0x0 || src > 0xFF))
		{

			if (src < 0x80)
				dst = src;
			else
				dst = std::get<1>(win1254map[src]);
		}
		else
		{
			back.WarnDesc += "invalid char at pos " + std::to_string(i) + " at source string";
			/*back.Success = false;
			back.ErrDesc = "invalid character at pos : " + std::to_string(i);
			return back;*/
		}

		//std::cout << "src : " << std::setw(2) << std::hex << (0xff & src) << "\tdst : " << std::setw(2) << std::hex << (0xffffffff & dst) << std::endl;

		//todo byte range'lere göre yap şu işi

		unitsize = GetUnitSize(dst);

		switch (unitsize)
		{
			case 1:
				{
					byte1 = (dst & 0x000000FF);
					ss << byte1;
					break;
				}
			case 2:
				{
					byte2 = (dst & 0x0000FF00) >> 8;
					byte1 = (dst & 0x000000FF);
					ss << byte2;
					ss << byte1;
					break;
				}
			case 3:
				{
					byte3 = (dst & 0x00FF0000) >> 16;
					byte2 = (dst & 0x0000FF00) >> 8;
					byte1 = (dst & 0x000000FF);
					ss << byte3;
					ss << byte2;
					ss << byte1;

					break;
				}
			case 4:
				{
					byte4 = (dst & 0xFF000000) >> 24;
					byte3 = (dst & 0x00FF0000) >> 16;
					byte2 = (dst & 0x0000FF00) >> 8;
					byte1 = (dst & 0x000000FF);
					ss << byte4;
					ss << byte3;
					ss << byte2;
					ss << byte1;
					break;
				}
		}

	}
	back.Success = true;
	dstStr = ss.str();
	return back;
}

std::string ReadFile(std::string fpath)
{
	std::string back;
	if (fpath.empty()) return back;

	std::ifstream  instream;
	std::stringstream ss;


	try
	{
		instream.open(fpath, std::ios_base::in, std::ios_base::binary);
		if (instream.is_open())
		{
			ss << instream.rdbuf();
			back = ss.str();			
		}
	}
	catch (...)
	{

	}
	instream.close();
	instream.clear();

	return back;
}


void WriteFile(std::string txt, std::string fpath)
{
	if (fpath.empty()) return ;
	std::ofstream outstream;

	try
	{
		outstream.open(fpath, std::ios::out | std::ofstream::trunc);
		outstream << txt << std::endl;

	}
	catch (...)
	{
			
	}
	outstream.close();
	outstream.clear();

}

int main()
{
	cout << "Hello" << endl;
	std::string srcfilepath = "win1254.txt"; // ansi (win1254) encoded text file
	std::string destfilepath = "utf8.txt";
	
	std::string src = ReadFile(srcfilepath);
	std::string dest = Win1254ToUtf8(src);
	WriteFile(dest, destfilepath);

	
	return 0;
}
