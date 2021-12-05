
#include <vector>
#include "utilfns.h"
#include "sort/mysort.h"
#include "search/mysearch.h"


int SortTest();

int main()
{
	SortTest();
	
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

