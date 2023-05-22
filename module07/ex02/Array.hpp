#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {

public:
	Array():_array(new T), _len(0) {
		std::cout << "Empty array constructed\n";
	}

	Array(unsigned int n):_array(new T[n]), _len(n) {

		std::cout << "Array constructed with size: " << n << "\n";
	}

	Array(const Array &obj):_array(new T[obj._len]), _len(obj._len) {
		std::cout << "Array constructed by copy\n";

		for (unsigned int i = 0; i < obj._len; i++)
			this->_array[i] = obj._array[i];
	}

	~Array() {

		delete [] _array;
		std::cout << "Destructing array\n";
	}

	Array &operator=(const Array &obj) {
		std::cout << "operator= \n";

		delete [] this->_array;
		this->_array = new T[obj._len];

		for (unsigned int i = 0; i < obj._len; i++)
			this->_array[i] = obj._array[i];
	}

	T &operator[](std::size_t idx) {
		// std::cout << "idx: " << idx << " len: " << _len << std::endl;
		if (idx > this->_len)
			throw (std::invalid_argument("Error accesing array, bad index"));
		return (this->_array[idx]);
	}


private:
	T			*_array;
	std::size_t	_len;
};

#endif
