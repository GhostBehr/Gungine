#pragma once

#include <string>
#include <sstream>

#ifndef VERY_SMALL
#define VERY_SMALL 1.0e-9
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

#ifndef DEGREES_TO_RADIANS
#define DEGREES_TO_RADIANS (M_PI / 180.0f)
#endif

struct Vec3 {
	float x, y, z;

	//inline Vec3() {}
	inline Vec3(float s = 0.0f) : x(s), y(s), z(s) { }
	inline Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }
	inline Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) { }

	// Operators
	// ----------------------------------------------------------------------------
	inline Vec3& operator= (const Vec3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}
	// Unary negative
	inline const Vec3 operator- () const {
		return Vec3(-x, -y, -z);
	}

	// Read Vec3 as array - rvalue
	inline const float operator[] (int index) const {
		return *(&x + index);
	}
	// Write as array - lvalue
	inline float& operator[] (int index) {
		return *(&x + index);
	}

	// Addition / subtraction
	inline const Vec3 operator+ (const Vec3& v) const {
		return Vec3(x + v.x, y + v.y, z + v.z);
	}
	inline const Vec3 operator- (const Vec3& v) const {
		return Vec3(x - v.x, y - v.y, z - v.z);
	}

	// Multiply by scalar
	// scalar * Vec3 written as non-member
	inline const Vec3 operator* (const float s) const {
		return Vec3(x * s, y * s, z * s);
	}

	// Divide by scalar
	inline const Vec3 operator/ (const float s) const {
#ifdef _DEBUG
		if (fabs(s) < VERY_SMALL) {
			std::string errorMsg("Error: Divided by nearly zero");
			throw errorMsg;
		}
#endif
		return Vec3(x / s, y / s, z / s);
	}

	// Add to vector and assign
	inline Vec3& operator+= (const Vec3& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	// Subtract from vector and assign
	inline Vec3& operator-= (const Vec3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	// Multiply by scalar and assign
	inline Vec3& operator*= (const float s) {
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	// Divide by scalar and assign
	inline Vec3& operator/= (const float s) {
		x /= s;
		y /= s;
		z /= s;
		return *this;
	}

	// Logical comparison operators
	inline const bool operator== (const Vec3& v) const {
		return x == v.x && y == v.y && z == v.z;
	}
	inline const bool operator!= (const Vec3& v) const {
		return x != v.x || y != v.y || z != v.z;
	}

	// Return vector as string
	inline std::string toString() const {
		std::stringstream ss;
		ss << "(" << x << ", " << y << ", " << z << ")";
		return ss.str();
	}

	// These are here because they seem more like qualities of the vector than math operations

	// Return magnitude of vector
	inline const float mag() const {
		return std::sqrtf(x * x + y * y + z * z);
	}

	// Returns normal of vector
	static inline const Vec3 normal(const Vec3& v) {
		float mag = v.mag();
		return Vec3(v.x / mag, v.y / mag, v.z / mag);
	}

	// Assigns vector to it's normal
	inline Vec3& normalize() {
		*this = normal(*this);
		return *this;
	}

	// todo: possibly add a zero const or summin'

};

// Multiply Vec3 by scalar in either direction
inline const Vec3 operator* (const float s, const Vec3& v) {
	return v * s;
}