#pragma once

#include <vector>

namespace algo
{

enum LinearSearchOption
{
	OPT_FORWARD = 0,
	OPT_BACKWARD = 1
};


// finding the index at which the given value val is found, in the array arrin.
// if not found returns -1
template <typename T>
int mylinearsearchequal(const std::vector<T> & arrin, const T & val, LinearSearchOption optin = OPT_FORWARD);

// finding position of given value val between the two adjecent elements n1, n2 in arrin where n1 < val <= n2
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
		int i = arrSize - 1;
		for (; i >= 0; i--)
		{
			if (arrin[i] <= val)
				return i+1;
		}
	}

	return -1;
}

template<typename T>
int mylinearsearchequal(const std::vector<T>& arrin, const T & val, LinearSearchOption optin)
{
	int arrSize = arrin.size();
	if (optin == OPT_FORWARD)
	{
		int i = 0;
		for (; i < arrSize; i++)
		{
			if (arrin[i] == val)
				return i;
			else if (arrin[i] > val)
				return -1;
		}
	}

	else if (optin == OPT_BACKWARD)
	{
		int i = arrSize-1;
		for (; i >= 0; i--)
		{
			if (arrin[i] == val)
				return i;
			else if (arrin[i] < val)
				return -1;
		}
	}

	return -1;
}

}