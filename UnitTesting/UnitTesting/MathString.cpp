#include "pch.h"
#include "MathString.h"

std::string MathString::Concat(std::string str1, std::string str2)
{
    return str1 + str2;
}

std::string MathString::Reverse(std::string str)
{
	size_t count = str.size();
	for (int i = 0; i < count / 2; i++)
	{
		str[i] ^= str[count - 1 - i];
		str[count - 1 - i] ^= str[i];
		str[i] ^= str[count - 1 - i];
	}
	return str;
}

std::string MathString::SubstractFirst(std::string str1, std::string sub)
{
    int index = FindFirst(str1, sub);
    std::string subString;
    for (int i = 0; i < str1.size(); i++)
    {
        if (i == index)
        {
            i += sub.size();
            if (i >= str1.size())
            {
                break;
            }
        }
        subString += str1[i];
    }
    return subString;
}

std::string MathString::SubstractAll(std::string str1, std::string sub)
{
	std::vector<int> indices = FindAll(str1, sub);
    int indexOffset = 0;
	std::string subString;
	for (int i = 0; i < str1.size(); i++)
	{
		if (indexOffset < indices.size() && i == indices[indexOffset])
		{
			i += sub.size();
			if (i >= str1.size())
			{
				break;
			}
            indexOffset++;
		}
		subString += str1[i];
	}
	return subString;
}

int MathString::FindFirst(std::string str, std::string find)
{
    int index = -1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == find[0])
        {
            bool equal = true;
            for (int j = 0; j < find.size(); j++)
            {
                if (str[i + j] != find[j])
                {
                    equal = false;
                    break;
                }
            }
            if (equal)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

std::vector<int> MathString::FindAll(std::string str, std::string find)
{
	std::vector<int> indices;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == find[0])
		{
			bool equal = true;

			for (int j = 0; j < find.size(); j++)
			{
				if (str[i + j] != find[j])
				{
					equal = false;
					break;
				}
			}
			if (equal)
			{
				indices.push_back(i);
                i += find.size() - 1;
			}
		}
	}
	return indices;
}

std::vector<std::string> MathString::Split(std::string str, char delimiter)
{
	std::vector<std::string> subs;
    std::string temp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == delimiter)
        {
            subs.push_back(temp);
            temp = "";
        }
        else
        {
            temp += str[i];
        }
    }
    subs.push_back(temp);
    return subs;
}

std::string MathString::OrderAscend(std::string str)
{
    std::vector<int> bucket(255);
    for (int i = 0; i < str.size(); i++)
    {
        bucket[str[i]]++;
    }
    std::string res;
	for (int i = 0; i < bucket.size(); i++)
	{
		for (int j = 0; j < bucket[i]; j++)
        {
            res += char(i);
        }
	}
    return res;
}

std::string MathString::OrderDescend(std::string str)
{
	std::vector<int> bucket(255);
	for (int i = 0; i < str.size(); i++)
	{
		bucket[str[i]]++;
	}
	std::string res;
	for (int i = bucket.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < bucket[i]; j++)
		{
			res += char(i);
		}
	}
	return res;
}

bool MathString::CheckPalindrome(std::string str)
{
	for (int i = 0; i < str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - i - 1])
		{
			return false;
		}
	}
	return true;
}

bool MathString::AreEqual(std::string str1, std::string str2)
{
	for (int i = 0; i < str1.size(); i++)
	{
		if (str2.size() < i && str1[i] != str2[i])
		{
			return false;
		}
	}
	return str1.size() == str2.size();
}

bool MathString::AreEqual(std::vector<int> vec1, std::vector<int> vec2)
{
	for (int i = 0; i < vec1.size(); i++)
	{
		if (vec2.size() < i && vec1[i] != vec2[i])
		{
			return false;
		}
	}
	return vec1.size() == vec2.size();
}

bool MathString::AreEqual(std::vector<std::string> vec1, std::vector<std::string> vec2)
{
	for (int i = 0; i < vec1.size(); i++)
	{
		if (vec2.size() < i && vec1[i] != vec2[i])
		{
			return false;
		}
	}
	return vec1.size() == vec2.size();
}
