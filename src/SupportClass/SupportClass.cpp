// Implementation of the SupportClass class
#include "../../include/SupportClass.h"

using namespace std;

string SupportClass::showPath(){
	string str = "";
	for (int i = 0; i < index; ++i)
	{
		if (testPath[i] != "")
		{
			str+=testPath[i];
		}
	}

	return str;
}

void SupportClass::cleanPath(){
	for (int i = 0; i < index; ++i)
	{
		testPath[i] = "";
	}
	index =0;
}

const void SupportClass::operator << ( const std::string& s ) const
{
	std::cout<<"reload <<"<<std::endl;
}

const void SupportClass::operator >> ( std::string& s ) const
{
	std::cout<<"reload string>>"<<std::endl;	
}

void SupportClass::operator >> ( int& s ) 
{
	// std::cout<<"reload int>>"<<std::endl;
	// s = 1;	
	string value = supParam.getValueWithKey("yaw_pwm");
	s = atol(value.c_str());
}

const void SupportClass::operator >> ( bool& s ) const
{
	// std::cout<<"reload bool>>"<<std::endl;	
	s = 1;
}