
#include "search/mySearch.h"
#include "sort/mySort.h"
#include <vector>

namespace algo 
{

template <typename T>
bool checksum2benum(const std::vector<T>& arrin, T Num);

template <typename T>
bool checksum2benum(const std::vector<T>& arrin, T Num)
{
	std::vector < T > sortedone = mymergesort(arrin);
	while (true)
	{
		T lastnum = sortedone.back();
		sortedone.pop_back(); // assume different two number
		if (sortedone.empty())
			break;
		if (mybinarysearchequal(sortedone, Num - lastnum) >= 0) // could improve worst case be half
			return true;
		// sortedone.pop_back(); // when allow sum of the same element in the arr

	}
	return false;
}

}

