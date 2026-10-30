#ifndef FIXED_HPP
#define FIXED_HPP

#include <iosfwd>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const & other);
	Fixed & operator=(Fixed const & other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed & operator++();
	Fixed operator++(int);
	Fixed & operator--();
	Fixed operator--(int);

	static Fixed & min(Fixed & first, Fixed & second);
	static Fixed const & min(Fixed const & first, Fixed const & second);
	static Fixed & max(Fixed & first, Fixed & second);
	static Fixed const & max(Fixed const & first, Fixed const & second);
};

//insertion operator
std::ostream & operator<<(std::ostream & output, Fixed const & fixed);

//comparison operators
bool operator>(Fixed const & lhs, Fixed const & rhs);
bool operator<(Fixed const & lhs, Fixed const & rhs);
bool operator>=(Fixed const & lhs, Fixed const & rhs);
bool operator<=(Fixed const & lhs, Fixed const & rhs);
bool operator==(Fixed const & lhs, Fixed const & rhs);
bool operator!=(Fixed const & lhs, Fixed const & rhs);

//arithmetic operators
Fixed operator+(Fixed const & lhs, Fixed const & rhs);
Fixed operator-(Fixed const & lhs, Fixed const & rhs);
Fixed operator*(Fixed const & lhs, Fixed const & rhs);
Fixed operator/(Fixed const & lhs, Fixed const & rhs);

#endif
