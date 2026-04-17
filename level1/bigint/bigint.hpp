#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
private:
	std::string _digits;

	void normalize();

public:
	bigint();
	bigint(unsigned long long value);
	bigint(const bigint& other);
	~bigint();

	bigint& operator=(const bigint& other);

	bigint& operator+=(const bigint& other);
	bigint operator+(const bigint& other) const;

	bigint& operator++();
	bigint operator++(int);

	bigint& operator<<=(unsigned int shift);
	bigint operator<<(unsigned int shift) const;
	bigint& operator>>=(unsigned int shift);
	bigint operator>>(unsigned int shift) const;

	bool operator<(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>=(const bigint& other) const;
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;

	const std::string& str() const;
};

std::ostream& operator<<(std::ostream& os, const bigint& value);

#endif