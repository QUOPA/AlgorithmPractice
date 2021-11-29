#pragma once

#include <vector>


namespace mysort 
{

template <typename T>
std::vector<T> myinsertsort(const std::vector<T> & arrin);

template <typename T>
std::vector<T> myinsertsort(const std::vector<T> & arrin)
{
	int insize = arrin.size();
	auto arrout = arrin;
	for (int i = 1; i < insize; ++i)
	{
		// finding right place
		auto tobcomprd = arrin[i];
		int idx = i;
		for (int j = i-1; j >= 0; --j)
		{
			if (tobcomprd < arrout[j])
				--idx;
			else
				break;
		}

		// reordering
		for (int j = i; j > idx; --j)
		{
			arrout[j] = arrout[j-1];
		}
		arrout[idx] = tobcomprd;
	}	
	return arrout;

}


}