#pragma once

enum MATRIX_UNRARY_OPERATIONS
{
	UNARY_BASE = 0,
	UNARY_TRANSPOSE = 1
};

template <typename T, typename InMatBase>
class myMatrixUnary<T, InMatBase, UNARY_BASE>
{
public:
	myMatrixUnary(InMatBase* pIn) : m_pInMat(pIn) {}

protected:
	InMatBase* m_pInMat;
};


template <typename T, typename InMatBase, int CalcType>
class myMatrixUnary
	: public myMatrixUnary<T, InMatBase, UNARY_BASE>
{
};

template <typename T, typename InMatBase>
class myMatrixUnary<T, InMatBase, UNARY_TRANSPOSE>
	: public myMatrixUnary<T, InMatBase, UNARY_BASE>
	, public myMatrixBase<T, InMatBase>
{
public:
	inline IdxType getRows() const { return m_pInMat->getCols(); }
	inline IdxType getCols() const { return m_pInMat->getRows(); }

protected:
	const T* _v(IdxType r, IdxType, c) const { m_pInMat->_v(c, r); }
	T* _v(IdxType r, IdxType, c) { m_pInMat()->_v(c, r); }

};

