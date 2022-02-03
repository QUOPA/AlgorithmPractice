#pragma once

#include "algomatrix/matrix.h"
#include "algomatrix/matrixUtils.h"
//#include "algomatrix/matrixUnaryOperations.h"

namespace unaryoperation
{

void transpose()
{
	std::vector<int> vecDoubles = { 3, 0, 10, 5, 9, 4, 2,3, 1, -1 };
	myMatrix<int> matD(vecDoubles, 2, 5);
	std::cout << matD;
	
	auto matD_T = matD.t();
	std::cout << matD_T << std::endl;

	myMatrix<int> matD_TConcrete = matD_T;


	const myMatrix<int> CmatD(vecDoubles, 2, 5);
	
	auto CmatD_T = CmatD.t();
	

}

}
