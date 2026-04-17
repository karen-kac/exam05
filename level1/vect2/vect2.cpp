#include "vect2.hpp"

vect2::vect2()
{
	values[0] = 0;
	values[1] = 0;
}

vect2::vect2(int x, int y)
{
	values[0] = x;
	values[1] = y;
}

int& vect2::operator[](int index)
{
	return values[index];
}

const int& vect2::operator[](int index) const
{
	return values[index];
}

vect2& vect2::operator+=(const vect2& other)
{
	values[0] += other.values[0];
	values[1] += other.values[1];
	return *this;
}

vect2& vect2::operator-=(const vect2& other)
{
	values[0] -= other.values[0];
	values[1] -= other.values[1];
	return *this;
}

vect2& vect2::operator*=(int scalar)
{
	values[0] *= scalar;
	values[1] *= scalar;
	return *this;
}

vect2 vect2::operator+(const vect2& other) const
{
	return vect2(values[0] + other.values[0], values[1] + other.values[1]);
}

vect2 vect2::operator-(const vect2& other) const
{
	return vect2(values[0] - other.values[0], values[1] - other.values[1]);
}

vect2 vect2::operator*(int scalar) const
{
	return vect2(values[0] * scalar, values[1] * scalar);
}

bool vect2::operator==(const vect2& other) const
{
	return values[0] == other.values[0] && values[1] == other.values[1];
}

bool vect2::operator!=(const vect2& other) const
{
	return !(*this == other);
}

vect2 vect2::operator-() const
{
	return vect2(-values[0], -values[1]);
}

vect2 vect2::operator++(int)
{
	vect2 copy(*this);
	++(*this);
	return copy;
}

vect2& vect2::operator++()
{
	++values[0];
	++values[1];
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 copy(*this);
	--(*this);
	return copy;
}

vect2& vect2::operator--()
{
	--values[0];
	--values[1];
	return *this;
}

vect2 operator*(int scalar, vect2 right)
{
	return right * scalar;
}

std::ostream& operator<<(std::ostream& stream, const vect2& value)
{
	stream << "{" << value[0] << ", " << value[1] << "}";
	return stream;
}
