#pragma once

#include "matrixExceptions.h"
#include "matrixBase.h"

enum MATRIX_UNRARY_OPERATIONS
{
	UNARY_BASE = 0,
	UNARY_TRANSPOSE = 1
};

template <typename T, typename InMatBase, int CalcType>
class myMatrixUnary;

template <typename T, typename Derived>
class myMatrixBase;

template <typename T, typename InMatBase>
class myMatrixUnary<T, InMatBase, UNARY_BASE>
{
public:
	myMatrixUnary(InMatBase* pIn) : m_pInMat(pIn) {}

protected:
	InMatBase* m_pInMat;
	template <typename T, typename Derived>  friend class myMatrixBase;
};

template <typename T, typename InMatBase>
class myMatrixUnary<T, InMatBase, UNARY_TRANSPOSE>
	: public myMatrixUnary<T, InMatBase, UNARY_BASE>
	, public myMatrixBase<T, myMatrixUnary<T, InMatBase, UNARY_TRANSPOSE> >
{
public:
	myMatrixUnary(InMatBase* pIn) 
		:myMatrixUnary<T, InMatBase, UNARY_BASE >(pIn) {}

	// read
	inline IdxType getRows() const { return m_pInMat->getCols(); }
	inline IdxType getCols() const { return m_pInMat->getRows(); }

	// write only
	template<typename T, typename OtherMat>
	void operator=(const myMatrixBase<T, OtherMat>& rhs)
	{
		if (m_pInMat->getRows() != rhs.getCols())
			throw matrix_rangeerror("error in transpose assignment: the number of rows lhs should be the same with the number of columns of rhs");

		if (m_pInMat->getCols() != rhs.getRows())
			throw matrix_rangeerror("error in transpose assignment: the number of columns lhs should be the same with the number of rows of rhs");

		for (IdxType c = 0; c < m_pInMat->getRows(); ++c)
			for (IdxType r = 0; r < m_pInMat->getCols(); ++r)
				m_pInMat->_v(c, r) = rhs._v(r, c);
	}

protected:
	const T* _v(IdxType r, IdxType c) const { m_pInMat->_v(c, r); }
	T* _v(IdxType r, IdxType c) { m_pInMat->_v(c, r); }
};


template <typename T, typename InMatBase, int CalcType>
class myMatrixUnary
	: public myMatrixUnary<T, InMatBase, UNARY_BASE>
{

};


