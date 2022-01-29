#pragma once

#include "algomatrix/matrixbase.h"
#include "algomatrix/matrixexceptions.h"
#include <vector>

template <typename T>
class myMatrix : myMatrixBase<T, myMatrix>
{
public:
	myMatrix(const T* & datain, IdxType nRows, IdxType nCols);
	myMatrix(T* && datain, IdxType nRows, IdxType nCols);

	myMatrix(const std::vector<T> & datain, IdxType nRows, IdxType nCols);	

	inline IdxType getSize() const { return m_nRows * m_nCols; }
	inline IdxType getRows() const { return m_nRows; }
	inline IdxType getCols() const { return m_nCols; }

	

private:
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
			m_pData[r * nCols + c] = datain[r * nCols + c]

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
			m_pData[r * nCols + c] = datain[r * nCols + c]
}
