#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(Fixed const & other);
	Fixed & operator=(Fixed const & other);
	~Fixed();

	int		getRawBits(void) const;
};

#endif
