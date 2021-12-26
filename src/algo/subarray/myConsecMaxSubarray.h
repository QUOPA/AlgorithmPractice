#include <vector>

namespace algo 
{

template <typename T>
std::vector<T> myfindconsecmax(const std::vector<T>& arrin);

template <typename T>
void _myfindconsecmaximpl(const std::vector<T>& arrin, int & minidx, int & maxnextidx, int& thesum);

template <typename T>
void _findMaxCrossingSubarray(const std::vector<T>& arrin, int& minidx, int& maxnextidx, int& thesum, int halfidx);


template<typename T>
std::vector<T> myfindconsecmax(const std::vector<T>& arrin)
{
	int minidx = 0; 
	int maxnextidx = arrin.size();
	int thenum = 0;

	_myfindconsecmaximpl(arrin, minidx, maxnextidx, thenum);

	return std::vector<T>(arrin.begin() + minidx, arrin.begin() + maxnextidx);;
}

template<typename T>
void _myfindconsecmaximpl(const std::vector<T>& arrin, int & minidx, int & maxnextidx, int & thesum)
{
	int subarrsize = maxnextidx - minidx;
	if (subarrsize == 1)
	{
		thesum = arrin[minidx];
		return;
	}
	else if (subarrsize < 1)
	{
		throw std::exception("findconsecmaximpl algorithm error");
	}

	int halfleft = (maxnextidx + minidx) /2;
	int minleft = minidx;

	int halfright = halfleft;
	int maxright = maxnextidx;

	int mincenter = minidx;
	int halfcenter = halfleft;
	int maxcenter = maxnextidx;

	int thesumleft = thesum;
	int thesumright = thesum;
	int thesumcenter = thesum;

	_myfindconsecmaximpl(arrin, minleft, halfleft, thesumleft);
	_myfindconsecmaximpl(arrin, halfright, maxright, thesumright);
	_findMaxCrossingSubarray(arrin, mincenter, maxcenter, thesumcenter, halfcenter);

	bool done = false;
	if (thesumleft > thesumright)
	{
		if (thesumleft > thesumcenter)
		{
			thesum = thesumleft;
			minidx = minleft;
			maxnextidx = halfleft;
			done  = true;
		}
	}
	
	else if (thesumright > thesumleft)
	{
		if (thesumright > thesumcenter)
		{
			thesum = thesumright;
			minidx = halfright;
			maxnextidx = maxright;
			done = true;
		}
	}
	if (!done)
	{
		thesum = thesumcenter;
		minidx = mincenter;
		maxnextidx = maxcenter;
	}




}

template<typename T>
void _findMaxCrossingSubarray(const std::vector<T>& arrin, int& minidx, int& maxnextidx, int& thesum, int halfidx)
{
	T maxsum = arrin[halfidx] + arrin[halfidx - 1];
	T tmpmaxsum = maxsum;

	int tmpmin = halfidx - 1;
	for (int idx = halfidx - 2; idx >= minidx; idx--)
	{
		tmpmaxsum += arrin[idx];		
		if (tmpmaxsum > maxsum)
		{
			tmpmin = idx;
			maxsum = tmpmaxsum;
		}
	}

	tmpmaxsum = maxsum;
	int tmpmax = halfidx;
	for (int idx = halfidx + 1; idx <  maxnextidx; idx++)
	{
		tmpmaxsum += arrin[idx];
		if (tmpmaxsum > maxsum)
		{
			tmpmax = idx;
			maxsum = tmpmaxsum;
		}
	}
	minidx = tmpmin;
	maxnextidx = tmpmax +1;
	thesum = maxsum;
}



}