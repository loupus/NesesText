// NesesText.cpp : Defines the entry point for the application.
//

#include "NesesText.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include "win1254_table.hpp"
#include "BackObject.hpp"
using namespace std;


/*
* kontrol
 0xF8 = 1111 1000
 0xF0 = 1111 0000
 0xE0 = 1110 0000
 0x80 = 1000 0000

 eşleşme
 0xF0 = 1111 0000
 0xE0 = 1110 0000
 0xC0 = 1100 0000

 veri
 0x07 = 0000 0111
 0x0F = 0000 1111
 0X1F = 0001 1111

 0X3F = 0000 1111

*/



constexpr uint8_t GetUnitSizeFCp(const char32_t codepoint) noexcept
{
	return 1U + (codepoint >= 0x80) + (codepoint >= 0x800) + (codepoint >= 0x10000);
}

constexpr uint8_t GetUnitSizeFB(const char32_t utf) noexcept
{
	return 1U + (utf > 0x7FF) + (utf > 0xFFFF) + (utf >= 0x1FFFFF);
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



//
//int U8CodeUnit_To_CodePoint(const uint8_t* utf, char32_t& cp)
//{
//
//	if (utf == nullptr) return 0;
//
//	// https://github.com/sheredom/utf8.h/blob/master/utf8.h
//
//
//	uint8_t byte4;
//	uint8_t byte3;
//	uint8_t byte2;
//	uint8_t byte1;
//
//	// 4 bayt 
//	// ilk 5 bite bak 0b11111000 ise 4 bayt işareti var demektir	-- 11110
//	
//	if ((utf << 24 & 0xF8) == 0xF0)
//	{
//		byte4 = (utf << 24 & 0x07);
//		byte3 = (utf << 16 & 0x3F);
//		byte2 = (utf << 8 & 0X3F);
//		byte1 = (utf & 0x3F);
//		cp = byte4 << 18 | byte3 << 12 | byte2 << 6 | byte1;
//	}
//
//	// 3 bayt 
//	// ilk 4 bite bak 0b11100000 ise 3 bayt işareti var demektir	-- 1110
//	else if ((utf << 16 & 0xF0) == 0xE0)
//	{
//		byte3 = (utf << 16 & 0x0F);
//		byte2 = (utf << 8 & 0X3F);
//		byte1 = (utf & 0x3F);
//		cp = byte3 << 12 | byte2 << 6 | byte1;
//	}
//
//	// 2 bayt 
//	// ilk 3 bite bak 0b11000000 ise 2 bayt işareti var demektir	-- 110
//	else if ((utf << 8 & 0xE0) == 0xC0)
//	{
//		byte2 = (utf << 8 & 0X1F);
//		byte1 = (utf & 0x3F);
//		cp = byte2 << 6 | byte1;
//	}
//
//	// 1 bayt 
//
//	if ((utf & 0x80) == 0xC0)
//	{
//		byte2 = (utf & 0X1F);
//		byte1 = (utf & 0x3F);
//		cp = byte3 << 12 | byte2 << 6 | byte1;
//	}
//
//
//
//	cp = 0x0;
//
//	// 1 byte aynen al
//	if (cp <= 0x7F)
//	{
//		utf = 0x7F;
//		return 1;
//	}
//
//	// 2 byte
//	if (cp <= 0x7FF)
//	{
//		byte2 = ((cp >> 6) & 0x1F) | 0xC0;
//		byte1 = (cp & 0x3F) | 0x80;
//		utf = (byte2 << 8) | byte1;
//		return 2;
//	}
//
//	// 3 byte
//	if (cp <= 0xFFFF)
//	{
//		byte3 = ((cp >> 12) & 0x0F) | 0xE0;
//		byte2 = ((cp >> 6) & 0x3F) | 0x80;
//		byte1 = (cp & 0x3F) | 0x80;
//		utf = (byte3 << 16) | (byte2 << 8) | byte1;
//		return 3;
//	}
//
//	// 4 byte
//	if (cp <= 0x10FFFF)
//	{
//		byte4 = ((cp >> 18) & 0x07) | 0xF0;
//		byte3 = ((cp >> 12) & 0x3F) | 0x80;
//		byte2 = ((cp >> 6) & 0x3F) | 0x80;
//		byte1 = (cp & 0x3F) | 0x80;
//		utf = (byte3 << 24) | (byte3 << 16) | (byte2 << 8) | byte1;			// byteları birleştir
//		return 4;
//	}
//
//
//	return -1;
//}

//*****************************************************************************************

uint8_t SizeFromCp(const char32_t& cp)
{
	uint8_t back{ 0 };
	if ((cp & 0xFFFFFF80) == 0x0) return 1; // negation of 7F -last of 1 byte codepoint- in 4 byte
	if ((cp & 0xFFFFF800) == 0x0) return 2; // negation of 7FF -last of 2 byte codepoint- in 4 byte
	if ((cp & 0xFFFF0000) == 0x0) return 3; // negation of FFFF -last of 3 byte codepoint- in 4 byte
	if ((cp & 0xFFE00000) == 0x0) return 4; // negation of 1FFFFF -last of 4 byte codepoint- in 4 byte
	return back;
}

uint8_t SizeFromCodeUnit(const char32_t& cu)
{
	uint8_t back{ 0 };
	if ((cu & 0xFFFFFF80) == 0x0) return 1;
	if ((cu & 0xFFFF2040) == 0x0) return 2;
	if ((cu & 0xFF104040) == 0x0) return 3;
	if ((cu & 0xF8404040) == 0x0) return 4;

	return back;
}


//*****************************************************************************************



BackObject Win1254ToUtf8(const std::string& srcStr, std::string& dstStr)
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
		unitsize = 0;

		if (!(src < 0x0 || src > 0xFF))
		{

			if (src < 0x80)
			{
				dst = src;
				unitsize = 1;
			}
			else
			{
				dst = std::get<1>(win1254ToUtf8[src]);
				unitsize = std::get<2>(win1254ToUtf8[src]);
			}
				
		}
		else
		{
			back.WarnDesc += "invalid char at pos " + std::to_string(i) + " at source string\n";
			/*back.Success = false;
			back.ErrDesc = "invalid character at pos : " + std::to_string(i);
			return back;*/
		}

		//std::cout << "src : " << std::setw(2) << std::hex << (0xff & src) << "\tdst : " << std::setw(2) << std::hex << (0xffffffff & dst) << std::endl;


		//unitsize = SizeFromCodeUnit(dst);

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

BackObject Utf8ToWin1254(const std::string& srcStr, std::string& dstStr)
{
	BackObject back;

	const size_t len = srcStr.length();
	if (len == 0)
	{
		back.Success = false;
		back.ErrDesc = "empty input string";
		return back;
	}
	 char32_t utf;
	 uint8_t dst;
	std::stringstream ss;

	uint8_t byte4;
	uint8_t byte3;
	uint8_t byte2;
	uint8_t byte1;
	uint8_t unitsize = 0;

	


	for (std::size_t i = 0; i < len; i++)
	{
		dst = 0xBF;  // ¿ as replacement char
		byte1 = srcStr[i]; // ilk baytı al

		// 1 bayt
		if ((byte1 & 0x80) == 0x0) // 0b10000000
		{
			dst = byte1;
			unitsize = 1;
		}

		// 2 bayt
		else if ((byte1 & 0xE0) == 0xC0) // 0b11000000
		{
			if (len < i + 2) // 2 bayt char için yer var mı?
			{
				back.WarnDesc += "invalid char at pos " + std::to_string(i) + " at source string\n";
				break;
			}

			byte2 = srcStr[i + 1];  // sonraki byte'ı da al
			if ((byte2 & 0xC0) != 0x80)
			{
				back.WarnDesc += "invalid follow byte " + std::to_string(i + 1) + " at source string\n";
				break;
			}

			utf = (byte1 << 8) | byte2;
			dst = utf8ToWin1254[utf];		// lut'a bak
			unitsize = 2;
			i++;
		}

		// 3 byte
		else if ((byte1 & 0xF0) == 0xE0)		// 0b11100000
		{
			if (len < i + 3) // 3 bayt char için yer var mı?
			{
				back.WarnDesc += "invalid char at pos " + std::to_string(i) + " at source string\n";
				break;
			}
			byte2 = srcStr[i + 1]; 
			byte3 = srcStr[i + 2];
			if((byte2 & 0xC0) != 0x80)
			{
				back.WarnDesc += "invalid follow byte " + std::to_string(i + 1) + " at source string\n";
				break;
			}
			if ((byte3 & 0xC0) != 0x80)
			{
				back.WarnDesc += "invalid follow byte " + std::to_string(i + 2) + " at source string\n";
				break;
			}
			utf = (byte1 << 16) | (byte2 << 8) | byte3;
			dst = utf8ToWin1254[utf];		
			unitsize = 3;
			i += 2;
		}

		else if ((byte1 & 0xF8) == 0xF0)		// 0b11110000
		{
			if (len < i + 4) 
			{
				back.WarnDesc += "invalid char at pos " + std::to_string(i) + " at source string\n";
				break;
			}
			byte2 = srcStr[i + 1];
			byte3 = srcStr[i + 2];
			byte4 = srcStr[i + 3];
			if ((byte2 & 0xC0) != 0x80)
			{
				back.WarnDesc += "invalid follow byte " + std::to_string(i + 1) + " at source string\n";
				break;
			}
			if ((byte3 & 0xC0) != 0x80)
			{
				back.WarnDesc += "invalid follow byte " + std::to_string(i + 2) + " at source string\n";
				break;
			}
			if ((byte4 & 0xC0) != 0x80)
			{
				back.WarnDesc += "invalid follow byte " + std::to_string(i + 3) + " at source string\n";
				break;
			}
			utf = (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4;
			dst = utf8ToWin1254[utf];
			unitsize = 4;
			i += 3;
		}
		else
		{
			back.WarnDesc += "invalid char at pos " + std::to_string(i) + " at source string\n";
			break;
		}
		
		ss << dst;

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
	std::string src, dst;
	//std::string srcfilepath = "win1254.txt"; // ansi (win1254) encoded text file
	//std::string destfilepath = "utf8.txt";

	std::string srcfilepath = "utf8.txt"; // ansi (win1254) encoded text file
	std::string destfilepath = "win1254_2.txt";
	
	src = ReadFile(srcfilepath);
	BackObject back = Utf8ToWin1254(src,dst);
	if (!back.Success)
		std::cout << back.ErrDesc << std::endl;
	WriteFile(dst, destfilepath);

	
	return 0;
}
