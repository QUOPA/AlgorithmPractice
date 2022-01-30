#pragma once

#include "algomatrix/matrixbase.h"
#include "algomatrix/matrixexceptions.h"
#include <vector>



template <typename T>
class myMatrix : myMatrixBase<T, myMatrix<T>>
{
public:
	myMatrix(const T* & datain, IdxType nRows, IdxType nCols);
	myMatrix(T* && datain, IdxType nRows, IdxType nCols);

	myMatrix(const std::vector<T> & datain, IdxType nRows, IdxType nCols);	

	inline IdxType getSize() const { return m_nRows * m_nCols; }
	inline IdxType getRows() const { return m_nRows; }
	inline IdxType getCols() const { return m_nCols; }

	inline void operator=(const myMatrix<T>& rhs) 
	{
		if (!renewDataMemory(rhs.getSize()))
			throw matrix_rangeerror("Failed to renew data memory of size :" + std::to_string(rhs.getSize()));

		m_nRows = rhs.getRows();
		m_nCols = rhs.getCols();

		std::size_t nSize = rhs.getSize() * sizeof(T);

		memcpy(m_pData, rhs.m_pData, nSize);
	}

	inline void operator=(myMatrix<T> && rhs) 
	{  
		std::swap(m_pData, rhs.m_pData);
		std::swap(m_nRows, rhs.m_nRows);
		std::swap(m_nCols, rhs.m_nCols);
	}

	template<typename T, typename OtherMat>
	inline void operator=(const myMatrixBase<T, OtherMat>& rhs) { rhs; }

	
	

private:
	bool renewDataMemory(IdxType nSize)
	{
		if (m_pData != nullptr)
			delete[] m_pData;
		m_pData = new T[nSize];
		return m_pData != nullptr;
	}

	T* m_pData;
	IdxType m_nRows;
	IdxType m_nCols;
};

template<typename T>
myMatrix<T>::myMatrix(const T*& datain, IdxType nRows, IdxType nCols)
{
	if (nRows <= 0 || nCols <= 0)
		throw matrix_rangeerror("bad row size or column size input");

	m_pData = new T[nRows * nCols];

	for (IdxType r = 0; r < nRows; ++r)
		for (IdxType c = 0; c < nCols; ++c)
			m_pData[r * nCols + c] = datain[r * nCols + c];

}

template<typename T>
myMatrix<T>::myMatrix(T*&& datain, IdxType nRows, IdxType nCols)
{
	if (nRows <= 0 || nCols <= 0)
		throw matrix_rangeerror("bad row size or column size input");

	m_pData = datain;
	datain = nullptr;

}

template<typename T>
myMatrix<T>::myMatrix(const std::vector<T>& datain, IdxType nRows, IdxType nCols)
{
	if (nRows <= 0 || nCols <= 0)
		throw matrix_rangeerror("bad row size or column size input");

	m_pData = new T[nRows * nCols];

	for (IdxType r = 0; r < nRows; ++r)
		for (IdxType c = 0; c < nCols; ++c)
			m_pData[r * nCols + c] = datain[r * nCols + c];
}
