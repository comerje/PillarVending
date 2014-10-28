
#ifndef STRINGFORMATTER_H__
#define STRINGFORMATTER_H__

#include <string>
#include <iomanip>
#include <sstream>

class StringFormatter
{
public:
	static std::string FormatCurrency(int amount)
	{
		std::stringstream ss;
		ss << "$" << std::fixed << std::setprecision(2) << (amount/100.0);
		return ss.str();
	}
};

#endif
