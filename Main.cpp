
#include "utilfns.h"
#include "sort/mysort.h"


int SortTest();

int main()
{
	
	SortTest();
	

	return 0;

}

int SortTest()
{
	std::vector<int> arrin = { 5, 7, 1, 7, 23, 45, 234, 67, 3, 3, 41, 2 };
	showvector(arrin);
	showvector(mysort::myinsertsort(arrin));
	
	return 0;
}

