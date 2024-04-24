// NesesText.cpp : Defines the entry point for the application.
//

#include "NesesText.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include "win1254_table.hpp"
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
