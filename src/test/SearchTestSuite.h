#pragma once

#include "SearchTestCases.h"
#include "testcommon/utilfns.h"


namespace SearchTest
{

void TestSuite()
{
	REGISTERTESTCASE(IntVectorRandomInput)
	REGISTERTESTCASE(DoubleVectorRandomInput)
}

}