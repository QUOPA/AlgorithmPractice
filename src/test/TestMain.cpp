
#include "SortTestSuite.h"
#include "SearchTestSuite.h"
#include "SubarrayTestSuite.h"
#include "ExerciseTestSuite.h"
#include "utilfns.h"


int main()
{
	REGISTERTESTSUITE(SortTest)
	REGISTERTESTSUITE(SearchTest)
	REGISTERTESTSUITE(SubarrayTest)
	REGISTERTESTSUITE(ExerciseTest)

	char buff[256];
	std::cin.getline(buff, 256);

	return 0;
}