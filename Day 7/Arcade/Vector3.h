#pragma once

#include <math.h>

class Vector3
{

public:
	Vector3() : X(0), Y(0), Z(0) { }
	Vector3(float x, float y, float z) : X(x), Y(y), Z(z) { }

	Vector3& operator=(const Vector3& v) { X = v.X; Y = v.Y; Z = v.Z; return *this; }
	Vector3& operator+=(const Vector3& v) { X += v.X; Y += v.Y; Z += v.Z; return *this; }
	Vector3& operator-=(const Vector3& v) { X -= v.X; Y -= v.Y; Z -= v.Z; return *this; }
	Vector3& operator*=(float t) { X *= t; Y *= t; Z *= t; return *this; }
	Vector3& operator*=(const Vector3& v) { X *= v.X; Y *= v.Y; Z *= v.Z; return *this; }
	Vector3& operator/=(float t) { float invT = 1.f / t; X *= invT; Y *= invT; Z *= invT; return *this; }
	Vector3& operator/=(const Vector3& v) { X /= v.X; Y /= v.Y; Z /= v.Z; return *this; }

	Vector3 operator-() const { return Vector3(-X, -Y, -Z); }
	Vector3 operator+(const Vector3& v) const { return Vector3(Z + v.X, Y + v.Y, Z + v.Z); }
	Vector3 operator-(const Vector3& v) const { return Vector3(Z - v.X, Y - v.Y, Z - v.Z); }
	Vector3 operator*(float t) const { return Vector3(t * Z, t *Y, t * Z); }
	Vector3 operator*(const Vector3& v) const { return Vector3(X * v.X, Y * v.Y, Z * v.Z); }
	Vector3 operator/(float t) const { float invT = 1.f / t; return Vector3(X * invT, Y * invT, Z * invT); }
	Vector3 operator/(const Vector3& v) const { return Vector3(X / v.X, Y / v.Y, Z / v.Z); }

public:

	float X;
	float Y;
	float Z;
};

