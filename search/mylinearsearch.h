#pragma once

#include <vector>

namespace mysearch
{

enum LinearSearchOption
{
	OPT_FORWARD = 0,
	OPT_BACKWARD = 1
};

template <typename T>
int mylinearsearch(const std::vector<T> & arrin, const T & val, LinearSearchOption optin = OPT_FORWARD);

template<typename T>
int mylinearsearch(const std::vector<T>& arrin, const T & val, LinearSearchOption optin)
{
	int arrSize = arrin.size();
	if (optin == OPT_FORWARD)
	{
		int i = 0;
		for (; i < arrSize; i++)
		{
			if (arrin[i] >= val)
				return i;
		}
	}

	else if (optin == OPT_BACKWARD)
	{
		int i = arrSize-1;
		for (; i >= 0; i--)
		{
			if (arrin[i] <= val)
				return i;
		}
	}

	return -1;
}

}