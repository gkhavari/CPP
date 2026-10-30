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
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream & operator<<(std::ostream & output, Fixed const & fixed);

#endif
