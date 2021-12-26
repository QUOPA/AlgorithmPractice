#pragma once

#include "exercises/myExercises.h"
#include "utilfns.h"
#include <vector>

using namespace algo;
using namespace testutil;

namespace ExerciseTest
{

void Exercise_2_2_7()
{
	std::vector<int> arrin1 = genvector(5, 5, 0, 10, genvecopt::OPT_UNIQUE);
	std::cout << "Original Vector : ";
	showvector(arrin1);
	std::cout << "Is there pair of elements to whose sum to be 10 ? ";
	std::cout << checksum2benum(arrin1, 10) << std::endl;


}


}
