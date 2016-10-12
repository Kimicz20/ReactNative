#include "../../include/Parameter.h"
using namespace std;

string Parameter::getValueWithKey(string key){
	
	for (std::map<string,string>::iterator it = testCaseMap.begin();it != testCaseMap.end();it++)
	{
		if (it->first == key)
		{
			return it->second;
		}
	}
	return "";
}

bool Parameter::isInMap(string key){
	if (getValueWithKey(key) == "")
	{
		return false;
	}
	return true;
}

