/*
 * Matrix.h
 *
 *  Created on: Aug 23, 2014
 *      Author: jgdo
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <cmath>
#include <iostream>

namespace ml {

template<unsigned R, unsigned C, class T>
class Mat {
public:
	
	inline Mat() {
	}
	
	inline Mat(T init) {
		for (unsigned i = 0; i < numel(); i++)
			data[i] = init;
	}
	
	inline static Mat zeros() {
		Mat<R, C, T> m;
		for (unsigned i = 0; i < m.numel(); i++)
			m(i) = 0;
		return m;
	}
	
	inline static Mat ones() {
		Mat<R, C, T> m;
		for (unsigned i = 0; i < m.numel(); i++)
			m(i) = 1;
		return m;
	}
	
	inline static Mat eye() {
		Mat<R, C, T> m;
		for (unsigned i = 0; i < m.numel(); i++)
			m(i) = 0;
		unsigned range = R < C ? R : C;
		for (unsigned i = 0; i < range; i++)
			m(i, i) = 1;
		return m;
	}
	
	template<class T2>
	inline Mat(const Mat<R, C, T2>& other) {
		for (unsigned i = 0; i < numel(); i++)
			data[i] = other.data[i];
	}
	
	inline T& operator()(unsigned r, unsigned c) {
		// TODO range check
		return data[r * C + c];
	}
	
	inline T operator()(unsigned r, unsigned c) const {
		// TODO range check
		return data[r * C + c];
	}
	
	inline T& operator()(unsigned idx) {
		// TODO range check
		return data[idx];
	}
	
	inline T operator()(unsigned idx) const {
		// TODO range check
		return data[idx];
	}
	
	inline unsigned numel() const {
		return R * C;
	}
	
	Mat& operator+=(T val) {
		for (unsigned i = 0; i < numel(); i++)
			data[i] += val;
		return *this;
	}
	
	Mat& operator*=(T val) {
		for (unsigned i = 0; i < numel(); i++)
			data[i] *= val;
		return *this;
	}
	
	Mat& operator-=(T val) {
		for (unsigned i = 0; i < numel(); i++)
			data[i] -= val;
		return *this;
	}
	
	Mat& operator/=(T val) {
		for (unsigned i = 0; i < numel(); i++)
			data[i] /= val;
		return *this;
	}
	
public:
	T data[R * C];
};

template<unsigned R, unsigned C, class T1, class T2>
auto operator+(const Mat<R, C, T1>& lhs, const Mat<R, C, T2>& rhs) -> Mat<R, C, decltype(lhs.data[0] + rhs.data[0])> {
	Mat<R, C, decltype(lhs.data[0] + rhs.data[0])> m;
	for (unsigned r = 0; r < R; r++)
		for (unsigned c = 0; c < C; c++)
			m(r, c) = lhs(r, c) + rhs(r, c);
	return m;
}

template<unsigned R, unsigned C, class T1, class T2>
Mat<R, C, T1>& operator+=(Mat<R, C, T1>& lhs, const Mat<R, C, T2>& rhs) {
	for (unsigned r = 0; r < R; r++)
		for (unsigned c = 0; c < C; c++)
			lhs(r, c) += rhs(r, c);
	return lhs;
}

template<unsigned R, unsigned C, class T1, class T2>
auto operator-(const Mat<R, C, T1>& lhs, const Mat<R, C, T2>& rhs) -> Mat<R, C, decltype(lhs.data[0] - rhs.data[0])> {
	Mat<R, C, decltype(lhs.data[0] - rhs.data[0])> m;
	for (unsigned r = 0; r < R; r++)
		for (unsigned c = 0; c < C; c++)
			m(r, c) = lhs(r, c) - rhs(r, c);
	return m;
}

template<unsigned R, unsigned C, class T1, class T2>
Mat<R, C, T1>& operator-=(Mat<R, C, T1>& lhs, const Mat<R, C, T2>& rhs) {
	for (unsigned r = 0; r < R; r++)
		for (unsigned c = 0; c < C; c++)
			lhs(r, c) -= rhs(r, c);
	return lhs;
}

template<unsigned R, unsigned C, unsigned RC, class T1, class T2>
auto operator*(const Mat<R, RC, T1>& lhs, const Mat<RC, C, T2>& rhs) -> Mat<R, C, decltype(lhs.data[0] * rhs.data[0])> {
	Mat<R, C, decltype(lhs.data[0] * rhs.data[0])> m;
	for (unsigned r = 0; r < R; r++) {
		for (unsigned c = 0; c < C; c++) {
			decltype(lhs.data[0] * rhs.data[0]) sum = 0;
			for (unsigned i = 0; i < RC; i++)
				sum += lhs(r, i) * rhs(i, c);
			
			m(r, c) = sum;
		}
	}
	return m;
}

template<unsigned R, unsigned C, class T, class T2>
Mat<R, C, T> operator+(const Mat<R, C, T>& lhs, T2 rhs) {
	Mat<R, C, T> m;
	for (unsigned i = 0; i < lhs.numel(); i++) {
		m(i) = lhs(i) + rhs;
	}
	
	return m;
}

template<unsigned R, unsigned C, class T, class T2>
Mat<R, C, T> operator-(const Mat<R, C, T>& lhs, T2 rhs) {
	Mat<R, C, T> m;
	for (unsigned i = 0; i < lhs.numel(); i++) {
		m(i) = lhs(i) - rhs;
	}
	
	return m;
}

template<unsigned R, unsigned C, class T, class T2>
Mat<R, C, T> operator*(const Mat<R, C, T>& lhs, T2 rhs) {
	Mat<R, C, T> m;
	for (unsigned i = 0; i < lhs.numel(); i++) {
		m(i) = lhs(i) * rhs;
	}
	
	return m;
}

template<unsigned R, unsigned C, class T, class T2>
Mat<R, C, T> operator*(T2 rhs, const Mat<R, C, T>& lhs) {
	Mat<R, C, T> m;
	for (unsigned i = 0; i < lhs.numel(); i++) {
		m(i) = lhs(i) * rhs;
	}
	
	return m;
}

template<unsigned R, unsigned C, class T>
inline Mat<C, R, T> trans(const Mat<R, C, T>& ref) {
	Mat<C, R, T> m;
	for (unsigned r = 0; r < R; r++)
		for (unsigned c = 0; c < C; c++)
			m(c, r) = ref(r, c);
	
	return m;
}

//! SquareMatrix Inverse. See https://code.google.com/p/smallmatrix/
template<class T>
inline Mat<1, 1, T> inv(const Mat<1, 1, T>& ref) {
	Mat<1, 1, T> m;
// TODO check determ 0
	m(0, 0) = 1.0 / ref(0, 0);
	return m;
}

template<class T>
inline Mat<2, 2, T> inv(const Mat<2, 2, T>& ref) {
	Mat<2, 2, T> res;
	T determ_inv = 1.0 / (ref(0, 0) * ref(1, 1) - ref(1, 0) * ref(0, 1));
// TODO check determ 0
	
	res(0, 0) = ref(1, 1) * determ_inv;
	res(0, 1) = -ref(0, 1) * determ_inv;
	res(1, 0) = -ref(0, 1) * determ_inv;
	res(1, 1) = ref(0, 0) * determ_inv;
	return res;
}

template<class T>
inline Mat<3, 3, T> inv(const Mat<3, 3, T>& ref) {
	T determ;
	T d0 = ref(1, 1) * ref(2, 2) - ref(1, 2) * ref(2, 1);
	T d1 = ref(1, 0) * ref(2, 2) - ref(2, 0) * ref(1, 2);
	T d2 = ref(1, 0) * ref(2, 1) - ref(1, 1) * ref(2, 0);
	determ = ref(0, 0) * d0 - ref(0, 1) * d1 + ref(0, 2) * d2;
	
// TODO check determ 0
	
	T d = T(1) / determ;
	T d3 = ref(0, 1) * ref(2, 2) - ref(2, 1) * ref(0, 2);
	T d4 = ref(0, 0) * ref(2, 2) - ref(2, 0) * ref(0, 2);
	T d5 = ref(0, 0) * ref(2, 1) - ref(2, 0) * ref(0, 1);
	T d6 = ref(0, 1) * ref(1, 2) - ref(1, 1) * ref(0, 2);
	T d7 = ref(0, 0) * ref(1, 2) - ref(1, 0) * ref(0, 2);
	T d8 = ref(0, 0) * ref(1, 1) - ref(1, 0) * ref(0, 1);
	
	Mat<3, 3, T> res;
	res(0, 0) = d0 * d;
	res(0, 1) = -d3 * d;
	res(0, 2) = d6 * d;
	res(1, 0) = -d1 * d;
	res(1, 1) = d4 * d;
	res(1, 2) = -d7 * d;
	res(2, 0) = d2 * d;
	res(2, 1) = -d5 * d;
	res(2, 2) = d8 * d;
	return res;
}
template<class T>
inline Mat<4, 4, T> inv(const Mat<4, 4, T>& ref) {
	T d1201 = ref(1, 0) * ref(2, 1) - ref(1, 1) * ref(2, 0);
	T d1202 = ref(1, 0) * ref(2, 2) - ref(1, 2) * ref(2, 0);
	T d1203 = ref(1, 0) * ref(2, 3) - ref(1, 3) * ref(2, 0);
	T d1212 = ref(1, 1) * ref(2, 2) - ref(1, 2) * ref(2, 1);
	T d1213 = ref(1, 1) * ref(2, 3) - ref(1, 3) * ref(2, 1);
	T d1223 = ref(1, 2) * ref(2, 3) - ref(1, 3) * ref(2, 2);
	T d1301 = ref(1, 0) * ref(3, 1) - ref(1, 1) * ref(3, 0);
	T d1302 = ref(1, 0) * ref(3, 2) - ref(1, 2) * ref(3, 0);
	T d1303 = ref(1, 0) * ref(3, 3) - ref(1, 3) * ref(3, 0);
	T d1312 = ref(1, 1) * ref(3, 2) - ref(1, 2) * ref(3, 1);
	T d1313 = ref(1, 1) * ref(3, 3) - ref(1, 3) * ref(3, 1);
	T d1323 = ref(1, 2) * ref(3, 3) - ref(1, 3) * ref(3, 2);
	T d2301 = ref(2, 0) * ref(3, 1) - ref(2, 1) * ref(3, 0);
	T d2302 = ref(2, 0) * ref(3, 2) - ref(2, 2) * ref(3, 0);
	T d2303 = ref(2, 0) * ref(3, 3) - ref(2, 3) * ref(3, 0);
	T d2312 = ref(2, 1) * ref(3, 2) - ref(2, 2) * ref(3, 1);
	T d2313 = ref(2, 1) * ref(3, 3) - ref(2, 3) * ref(3, 1);
	T d2323 = ref(2, 2) * ref(3, 3) - ref(2, 3) * ref(3, 2);
	
	Mat<4, 4, T> res;
	res(0, 0) = (ref(1, 1) * d2323 - ref(1, 2) * d2313 + ref(1, 3) * d2312);
	res(1, 0) = -(ref(1, 0) * d2323 - ref(1, 2) * d2303 + ref(1, 3) * d2302);
	res(2, 0) = (ref(1, 0) * d2313 - ref(1, 1) * d2303 + ref(1, 3) * d2301);
	res(3, 0) = -(ref(1, 0) * d2312 - ref(1, 1) * d2302 + ref(1, 2) * d2301);
	res(0, 1) = -(ref(0, 1) * d2323 - ref(0, 2) * d2313 + ref(0, 3) * d2312);
	res(1, 1) = (ref(0, 0) * d2323 - ref(0, 2) * d2303 + ref(0, 3) * d2302);
	res(2, 1) = -(ref(0, 0) * d2313 - ref(0, 1) * d2303 + ref(0, 3) * d2301);
	res(3, 1) = (ref(0, 0) * d2312 - ref(0, 1) * d2302 + ref(0, 2) * d2301);
	res(0, 2) = (ref(0, 1) * d1323 - ref(0, 2) * d1313 + ref(0, 3) * d1312);
	res(1, 2) = -(ref(0, 0) * d1323 - ref(0, 2) * d1303 + ref(0, 3) * d1302);
	res(2, 2) = (ref(0, 0) * d1313 - ref(0, 1) * d1303 + ref(0, 3) * d1301);
	res(3, 2) = -(ref(0, 0) * d1312 - ref(0, 1) * d1302 + ref(0, 2) * d1301);
	res(0, 3) = -(ref(0, 1) * d1223 - ref(0, 2) * d1213 + ref(0, 3) * d1212);
	res(1, 3) = (ref(0, 0) * d1223 - ref(0, 2) * d1203 + ref(0, 3) * d1202);
	res(2, 3) = -(ref(0, 0) * d1213 - ref(0, 1) * d1203 + ref(0, 3) * d1201);
	res(3, 3) = (ref(0, 0) * d1212 - ref(0, 1) * d1202 + ref(0, 2) * d1201);
	T determ_inv = 1.0
	        / (ref(0, 0) * res(0, 0) + ref(0, 1) * res(1, 0) + ref(0, 2) * res(2, 0) + ref(0, 3) * res(3, 0));
	
// TODO: check dterm 0
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			res(i, j) *= determ_inv;
	return res;
}

template<class T>
Mat<3, 1, T> cross(const Mat<3, 1, T> u, const Mat<3, 1, T>& v) {
	Mat<3, 1, T> s;
	
	s(0) = u(1) * v(2) - u(2) * v(1);
	s(1) = u(2) * v(0) - u(0) * v(2);
	s(2) = u(0) * v(1) - u(1) * v(0);
	
	return s;
}

template<unsigned R, unsigned C, class T>
std::ostream& operator<<(std::ostream& out, const Mat<R, C, T>& mat) {
	// TODO: multiline matrix
	if (mat.numel() == 0)
		out << "[]";
	else {
		out << "[" << mat(0);
		for (int i = 1; i < mat.numel(); i++) {
			out << ", " << mat(i);
		}
		out << "]";
	}
	return out;
}

typedef Mat<1, 1, float> Mat11f;
typedef Mat<1, 1, double> Mat11d;
typedef Mat<1, 1, int> Mat11i;

typedef Mat<2, 2, float> Mat22f;
typedef Mat<2, 2, double> Mat22d;
typedef Mat<2, 2, int> Mat22i;

typedef Mat<3, 3, float> Mat33f;
typedef Mat<3, 3, double> Mat33d;
typedef Mat<3, 3, int> Mat33i;

typedef Mat<1, 1, float> Vec1f;
typedef Mat<1, 1, double> Vec1d;
typedef Mat<1, 1, int> Vec1i;

typedef Mat<2, 1, float> Vec2f;
typedef Mat<2, 1, double> Vec2d;
typedef Mat<2, 1, int> Vec2i;

typedef Mat<3, 1, float> Vec3f;
typedef Mat<3, 1, double> Vec3d;
typedef Mat<3, 1, int> Vec3i;

template<unsigned R, unsigned C>
using Matf = Mat<R,C,float>;

template<unsigned R, unsigned C>
using Matd = Mat<R,C,double>;

template<unsigned R, unsigned C>
using Mati = Mat<R,C,int>;

template<unsigned R>
using Vecf = Mat<R,1,float>;

template<unsigned R>
using Vecd = Mat<R,1,double>;

template<unsigned R>
using Veci = Mat<R,1,int>;

template<class T>
inline Mat<2, 1, T> makeVec2(T v1, T v2) {
	Mat<2, 1, T> v;
	v(0) = v1;
	v(1) = v2;
	return v;
}

template<class T>
inline Mat<3, 1, T> makeVec3(T v1, T v2, T v3) {
	Mat<3, 1, T> v;
	v(0) = v1;
	v(1) = v2;
	v(2) = v3;
	return v;
}

inline Vec2f makeVec2f(float v1, float v2) {
	return makeVec2<float>(v1, v2);
}

inline Vec3f makeVec3f(float v1, float v2, float v3) {
	return makeVec3<float>(v1, v2, v3);
}

}

#endif /* MATRIX_H_ */
