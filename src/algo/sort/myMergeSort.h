#pragma once

#include <vector>


namespace algo
{
	template <typename T>
	std::vector<T> mymergesort(const std::vector<T> & arrin);

	template <typename T>
	void _mymergesortImpl(std::vector<T> & arrRet, std::vector<T>& arrTmp, int startPos, int endnextPos);

	template <typename T>
	std::vector<T> mymergesort(const std::vector<T> & arrin)
	{
		int insize = arrin.size();
		if (insize == 0)
			return std::vector<T>();
		std::vector<T> arrout = arrin;
		std::vector<T> arrtmp(insize);
		_mymergesortImpl(arrout, arrtmp, 0, insize);
		return arrout;
	}

	template<typename T>
	void _mymergesortImpl(std::vector<T>& arrRet, std::vector<T>& arrTmp,  int startPos, int endnextPos)
	{
		int numElem = endnextPos - startPos;
		if (numElem <= 1)
			return;

		int numHalf = numElem / 2; // floor to get int
		int halfPos = startPos + numHalf;

		_mymergesortImpl(arrRet, arrTmp, startPos, halfPos);
		_mymergesortImpl(arrRet, arrTmp, halfPos, endnextPos);

		// Merging 
		int idxleft = startPos;
		int idxright = halfPos;

		for (int idx = startPos; idx < endnextPos; idx++)
		{
			if (idxleft == halfPos)
				arrTmp[idx] = arrRet[idxright++];
			else if (idxright == endnextPos)
				arrTmp[idx] = arrRet[idxleft++];
			else
				arrTmp[idx] = arrRet[idxleft] < arrRet[idxright] ? arrRet[idxleft++] : arrRet[idxright++];
		}
		for (int idx = startPos; idx < endnextPos; idx++)
		{
			arrRet[idx] = arrTmp[idx];
		}
	}




}