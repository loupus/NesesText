#pragma once
#include <string>
#include <iostream>
#include <typeinfo>
#include <any>
struct BackObject
{
	bool Success = true;
	int ErrCode = 0;
	std::string ErrDesc;
	std::string WarnDesc;
	std::any AnyValue;
	friend std::ostream& operator << (std::ostream& out, const BackObject& c)
	{
		out << "Success: " << c.Success << std::endl
			<< "ErrCode: " << c.ErrCode << std::endl
			<< "ErrDesc: " << c.ErrDesc << std::endl
			<< "Value: " << (c.AnyValue.type() == typeid(std::string) ? std::any_cast<std::string>(c.AnyValue) : "") << std::endl;
		return out;
	}
};