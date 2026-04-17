#pragma once

#include <ostream>

class vect2
{
private:
	int values[2];
public:
	vect2();
	vect2(int x, int y);

	int& operator[](int index);
	const int& operator[](int index) const;

	vect2& operator+=(const vect2& other);
	vect2& operator-=(const vect2& other);
	vect2& operator*=(int scalar);
	vect2 operator+(const vect2& other) const;
	vect2 operator-(const vect2& other) const;
	vect2 operator*(int scalar) const;
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;

	vect2 operator-() const;

	vect2 operator++(int);
	vect2& operator++();
	vect2 operator--(int);
	vect2& operator--();
};

vect2 operator*(int scalar, vect2 right);
std::ostream& operator<<(std::ostream& stream, const vect2& value);
