#pragma once
#include "testcommon/utilfns.h"
#include "SortTestCases.h"


namespace SortTest
{
void TestSuite()
{
	REGISTERTESTCASE(IntVectorFixedInput)
	REGISTERTESTCASE(IntVectorRandomInput)
	REGISTERTESTCASE(DoubleVectorRandomInput)
}
	
}