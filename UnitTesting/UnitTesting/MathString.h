#pragma once
#ifdef UNITTESTING_EXPORTS
#define STRING_API __declspec(dllexport)
#else
#define STRING_API __declspec(dllimport)
#endif

#include <string>
#include <vector>

class STRING_API MathString
{
public:
	MathString() = default;
	~MathString() = default;
	static std::string Concat(std::string str1, std::string str2);
	static std::string Reverse(std::string str);
	static int FindFirst(std::string str, std::string find);
	static std::vector<int> FindAll(std::string str, std::string find);
	static std::string SubstractFirst(std::string str1, std::string sub);
	static std::string SubstractAll(std::string str1, std::string sub);
	static std::vector<std::string> Split(std::string str, char delimiter);
	static std::string OrderAscend(std::string str);
	static std::string OrderDescend(std::string str);
	static bool CheckPalindrome(std::string str);


	static bool AreEqual(std::string str1, std::string str2);
	static bool AreEqual(std::vector<int> vec1, std::vector<int> vec2);
	static bool AreEqual(std::vector<std::string> vec1, std::vector<std::string> vec2);

};


