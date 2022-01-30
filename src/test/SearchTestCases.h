#pragma once

#include "testcommon/utilfns.h"
#include "search/mySearch.h"
#include <vector>

using namespace algo;
using namespace testutil;

namespace SearchTest {

void IntVectorRandomInput()
{
	std::vector<int> arrin2 = genvector(15, 15, 0, 20, genvecopt::OPT_SORTED);
	
	std::cout << "Original Sorted Vector : ";
	showvector(arrin2);

	std::cout << "Linear Search - finding first equal to or larger than 10, forward : ";
	std::cout << mylinearsearch(arrin2, 10) << std::endl;

	std::cout << "Linear Search - Finding first equal to 10, forward : ";
	std::cout << mylinearsearchequal(arrin2, 10) << std::endl;

	std::cout << "Linear Search - Finding first equal to or smaller than 10, backward : ";
	std::cout << mylinearsearch(arrin2, 10, OPT_BACKWARD) << std::endl;

	std::cout << "Linear Search - Finding first equal to 10, backward : ";
	std::cout << mylinearsearchequal(arrin2, 10, OPT_BACKWARD) << std::endl;

	std::cout << "Binary search - Finding first equal to or larger than 10, forward : ";
	std::cout << mybinarysearch(arrin2, 10) << std::endl;

	std::cout << "Binary search - Finding first equal to 10, forward : ";
	std::cout << mybinarysearchequal(arrin2, 10) << std::endl;
}


void DoubleVectorRandomInput()
{
	std::vector<double> arrin2 = genvector(15, 15, 0.0, 1.0, genvecopt::OPT_SORTED);
	
	std::cout << "Original Sorted Vector : ";
	showvector(arrin2);

	std::cout << "Linear Search - finding first equal to or larger than 0.5, forward : ";
	std::cout << mylinearsearch(arrin2, 0.5) << std::endl;

	std::cout << "Linear Search - Finding first equal to 0.5, forward : ";
	std::cout << mylinearsearchequal(arrin2, 0.5) << std::endl;

	std::cout << "Linear Search - Finding first equal to or smaller than 0.5, backward : ";
	std::cout << mylinearsearch(arrin2, 0.5, OPT_BACKWARD) << std::endl;

	std::cout << "Linear Search - Finding first equal to 0.5, backward : ";
	std::cout << mylinearsearchequal(arrin2, 0.5, OPT_BACKWARD) << std::endl;

	std::cout << "Binary search - Finding first equal to or larger than 0.5, forward : ";
	std::cout << mybinarysearch(arrin2, 0.5) << std::endl;

	std::cout << "Binary search - Finding first equal to 0.5, forward : ";
	std::cout << mybinarysearchequal(arrin2, 0.5) << std::endl;

}

}

