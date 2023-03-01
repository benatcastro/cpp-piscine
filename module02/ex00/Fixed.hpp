#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
    public:
        Fixed(void);                        // Default constructor
        Fixed(const Fixed &obj);            // Copy constructor
        ~Fixed();                           // Destructor
        Fixed   &operator=(Fixed &obj);      // Assignment operator
        int     getRawBits(void);
        void    setRawBits(int const raw);
    private:
        int                 fixedValue;
        static const int    bits;
};
#endif