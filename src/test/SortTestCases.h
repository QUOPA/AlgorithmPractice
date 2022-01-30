#pragma once

#include "testcommon/utilfns.h"
#include "sort/mySort.h"
#include <vector>

using namespace algo;
using namespace testutil;
namespace SortTest
{

void IntVectorFixedInput()
{
	std::vector<int> arrin = { 5, 7, 1, 7, 23, 45, 234, 67, 3, 3, 41, 2 };
	std::cout << "Original Vector : ";
	showvector(arrin);
	std::cout << "After Insert Sort : ";
	showvector(myinsertsort(arrin));
	std::cout << "After Merge Sort : ";
	showvector(mymergesort(arrin));

}

void IntVectorRandomInput()
{
	std::vector<int> arrin2 = genvector(15, 15, 0, 20);
	std::cout << "Original Vector : ";
	showvector(arrin2);
	std::cout << "After Insert Sort : ";
	showvector(myinsertsort(arrin2));
	std::cout << "After Merge Sort : ";
	showvector(mymergesort(arrin2));
}

void DoubleVectorRandomInput()
{
	std::vector<double> arrin3 = genvector(15, 15, 0.0, 1.0);
	std::cout << "Original Vector : ";
	showvector(arrin3);
	std::cout << "After Insert Sort : ";
	showvector(myinsertsort(arrin3));
	std::cout << "After Merge Sort : ";
	showvector(mymergesort(arrin3));
}
}

