#pragma once

#include <map>
#include <string>

#define SDK_EXPORTS
#ifdef SDK_EXPORTS
#define SDK_API __declspec(dllexport)
#else
#define SDK_API __declspec(dllimport)
#endif

using namespace std;

class SDK_API DataSetRow{
public:
	string GetString(string);
	float  GetFloat(string);
	int	   GetInt32(string);

	int Set(string, string);
	void clear();
private:
	map<string, string> _mFields;
};
