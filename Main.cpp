
#include <vector>
#include "utilfns.h"
#include "sort/mysort.h"
#include "search/mysearch.h"
#include "exercises/allexercises.h"


int SortTest();
int SearchTest();
int ExerciseTest();


int main()
{
	SortTest();
	SearchTest();
	ExerciseTest();
	return 0;

}

int SortTest()
{
	std::vector<int> arrin = { 5, 7, 1, 7, 23, 45, 234, 67, 3, 3, 41, 2 };
	myutil::showvector(arrin);
	myutil::showvector(mysort::myinsertsort(arrin));
	myutil::showvector(mysort::mymergesort(arrin));

	std::vector<int> arrin2 = myutil::genvector(15,15,0,20);
	myutil::showvector(arrin2);
	myutil::showvector(mysort::myinsertsort(arrin2));
	myutil::showvector(mysort::mymergesort(arrin2));

	std::vector<double> arrin3 = myutil::genvector(15, 15, 0.0, 1.0);
	myutil::showvector(arrin3);
	myutil::showvector(mysort::myinsertsort(arrin3));
	myutil::showvector(mysort::mymergesort(arrin3));


	return 0;
}


int SearchTest()
{

	std::vector<int> arrin2 = myutil::genvector(15, 15, 0, 20, myutil::genvecopt::OPT_SORTED);
	myutil::showvector(arrin2);
	std::cout << mysearch::mylinearsearch(arrin2, 10) << std::endl;
	std::cout << mysearch::mylinearsearchequal(arrin2, 10) << std::endl;
	std::cout << mysearch::mylinearsearch(arrin2, 10, mysearch::OPT_BACKWARD) << std::endl;
	std::cout << mysearch::mylinearsearchequal(arrin2, 10, mysearch::OPT_BACKWARD) << std::endl;
	std::cout << mysearch::mybinarysearch(arrin2, 10) << std::endl;
	std::cout << mysearch::mybinarysearchequal(arrin2, 10) << std::endl;

	std::vector<double> arrin3 = myutil::genvector(15, 15, 0.0, 1.0, myutil::genvecopt::OPT_SORTED);
	myutil::showvector(arrin3);
	std::cout << mysearch::mylinearsearch(arrin3, 0.5) << std::endl;
	std::cout << mysearch::mylinearsearchequal(arrin3, 0.5) << std::endl;
	std::cout << mysearch::mylinearsearch(arrin3, 0.5, mysearch::OPT_BACKWARD) << std::endl;
	std::cout << mysearch::mylinearsearchequal(arrin3, 0.5, mysearch::OPT_BACKWARD) << std::endl;
	std::cout << mysearch::mybinarysearch(arrin3, 0.5) << std::endl;
	std::cout << mysearch::mybinarysearchequal(arrin3, 0.5) << std::endl;


	return 0;
}

int ExerciseTest()
{
	std::vector<int> arrin1 = myutil::genvector(5, 5, 0, 10, myutil::genvecopt::OPT_UNIQUE);
	myutil::showvector(arrin1);
	std::cout  << myexercise::checksum2benum(arrin1, 10) << std::endl;
	

	return 0;
}

