#pragma once

#include "subarray/mySubarray.h"
#include "testcommon/utilfns.h"
#include <vector>

using namespace testutil;
using namespace algo;

namespace SubarrayTest
{

void FindingMaxSumSubarrayCase1()
{
	std::vector<int> arrin1 = genvector(15, 15, -10, 10);
	std::cout << "Original Vector : ";
	showvector(arrin1);
	std::cout << "MaxSum Consecutive Subarray Vector devide and conquer: ";
	showvector(myfindconsecmax_dc(arrin1));
	std::cout << "MaxSum Consecutive Subarray Vector linear: ";
	showvector(myfindconsecmax_linear(arrin1));
}

void FindingMaxSumSubarrayCase2()
{
	std::vector<double> arrin2 = genvector(15, 15, -0.5, 0.5);
	std::cout << "Original Vector : ";
	showvector(arrin2);
	std::cout << "MaxSum Consecutive Subarray Vector devide and conquer: ";
	showvector(myfindconsecmax_dc(arrin2));
	std::cout << "MaxSum Consecutive Subarray Vector linear: ";
	showvector(myfindconsecmax_linear(arrin2));
}

}