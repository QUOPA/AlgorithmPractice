#pragma once

#include <vector>

namespace mysearch
{

template <typename T>
int mybinarysearchequal(const std::vector<T> & arrin, const T & val);

template <typename T>
int mybinarysearch(const std::vector<T> & arrin, const T & val);

template <typename T>
int _mybinarysearchequalImpl(const std::vector<T> & arrin, const T & val, int idxStart, int idxNextEnd);

template <typename T>
int _mybinarysearchImpl(const std::vector<T> & arrin, const T & val, int idxStart, int idxNextEnd);


template<typename T>
int mybinarysearchequal(const std::vector<T>& arrin, const T & val)
{
	return _mybinarysearchequalImpl(arrin, val, 0, arrin.size());
}

template<typename T>
int mybinarysearch(const std::vector<T>& arrin, const T & val)
{
	return _mybinarysearchImpl (arrin, val, 0, arrin.size());
}

template<typename T>
int _mybinarysearchequalImpl(const std::vector<T>& arrin, const T & val, int idxStart, int idxNextEnd)
{
	if (idxNextEnd - idxStart == 1)
	{
		if (val == arrin[idxStart])
			return idxStart;
		else
			return -1;
	}

	int halfPos = (idxNextEnd + idxStart) / 2;
	if (val < arrin[halfPos]) // left
		return _mybinarysearchequalImpl(arrin, val, idxStart, halfPos);
	else if (arrin[halfPos] < val) // left
		return _mybinarysearchequalImpl(arrin, val, halfPos, idxNextEnd);
	else
		return halfPos;
}

template<typename T>
int _mybinarysearchImpl(const std::vector<T>& arrin, const T & val, int idxStart, int idxNextEnd)
{
	if (idxNextEnd - idxStart == 1)
	{
		if (val > arrin[idxStart])
			return idxStart + 1;
		else
			return idxStart;
	}

	int halfPos = (idxNextEnd + idxStart)/2 ;
	if (val < arrin[halfPos]) // left
		return _mybinarysearchImpl(arrin, val, idxStart, halfPos);
	else if (arrin[halfPos] < val) // left
		return _mybinarysearchImpl(arrin, val, halfPos, idxNextEnd);
	else
		return halfPos;

}

}