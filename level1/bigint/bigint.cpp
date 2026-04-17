#include "bigint.hpp"

bigint::bigint() : _digits("0") {
}

bigint::bigint(unsigned long long value) : _digits() {
	if (value == 0) {
		_digits = "0";
		return;
	}
	while (value > 0) {
		char c = static_cast<char>('0' + (value % 10));
		_digits.insert(_digits.begin(), c);
		value /= 10;
	}
}

bigint::bigint(const bigint& other) : _digits(other._digits) {
}

bigint::~bigint() {
}

bigint& bigint::operator=(const bigint& other) {
	if (this != &other)
		_digits = other._digits;
	return *this;
}

void bigint::normalize() {
	std::size_t i = 0;
	while (i + 1 < _digits.size() && _digits[i] == '0')
		++i;
	if (i > 0)
		_digits.erase(0, i);
}

bigint& bigint::operator+=(const bigint& other) {
	std::string result;
	int i = static_cast<int>(_digits.size()) - 1;
	int j = static_cast<int>(other._digits.size()) - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry) {
		int a = (i >= 0) ? (_digits[i] - '0') : 0;
		int b = (j >= 0) ? (other._digits[j] - '0') : 0;
		int sum = a + b + carry;
		result.insert(result.begin(), static_cast<char>('0' + (sum % 10)));
		carry = sum / 10;
		--i;
		--j;
	}

	_digits = result;
	normalize();
	return *this;
}

bigint bigint::operator+(const bigint& other) const {
	bigint result(*this);
	result += other;
	return result;
}

bigint& bigint::operator++() {
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int) {
	bigint old(*this);
	++(*this);
	return old;
}

bigint& bigint::operator<<=(unsigned int shift) {
	if (_digits == "0")
		return *this;
	_digits.append(shift, '0');
	return *this;
}

bigint bigint::operator<<(unsigned int shift) const {
	bigint result(*this);
	result <<= shift;
	return result;
}

bigint& bigint::operator>>=(unsigned int shift) {
	if (shift >= _digits.size()) {
		_digits = "0";
		return *this;
	}
	_digits.erase(_digits.size() - shift, shift);
	normalize();
	return *this;
}

bigint bigint::operator>>(unsigned int shift) const {
	bigint result(*this);
	result >>= shift;
	return result;
}

bool bigint::operator<(const bigint& other) const {
	if (_digits.size() != other._digits.size())
		return _digits.size() < other._digits.size();
	return _digits < other._digits;
}

bool bigint::operator>(const bigint& other) const {
	return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
	return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
	return !(*this < other);
}

bool bigint::operator==(const bigint& other) const {
	return _digits == other._digits;
}

bool bigint::operator!=(const bigint& other) const {
	return !(*this == other);
}

const std::string& bigint::str() const {
	return _digits;
}

std::ostream& operator<<(std::ostream& os, const bigint& value) {
	os << value.str();
	return os;
}