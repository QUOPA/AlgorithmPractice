#pragma once

#include "algomatrix/mytypes.h"
#include "algomatrix/matrixUnaryOperations.h"

template <typename T, typename InMatBase, int CalcType>
class myMatrixUnary;

template <typename T, typename Derived>
class myMatrixBase
{
public:
	// read
	inline IdxType getSize() const { return derived()->getSize(); }
	inline IdxType getRows() const { return derived()->getRows(); }
	inline IdxType getCols() const { return derived()->getCols(); }

	// Operations (read / write)
	inline const auto t() const { return myMatrixUnary<T, myMatrixBase, UNARY_TRANSPOSE>(this); }
	inline auto t() { return myMatrixUnary<T, myMatrixBase, UNARY_TRANSPOSE>(this); }

	// assingment (non const only)
	template<typename T, typename OtherMat>
	inline void operator=(const myMatrixBase<T, OtherMat>& rhs) { derived()->operator=(*rhs.derived()); }

protected:
	const T* _v(IdxType r, IdxType c) const { derived()->_v(r,c); }
	T* _v(IdxType r, IdxType c) { derived()->_v(r, c); }

private:
	inline const Derived* derived() const { return static_cast<const Derived*>(this); }
	inline Derived* derived() { return static_cast<Derived*>(this); }
	
};

