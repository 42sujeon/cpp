#include "Convert.hpp"

/* Orthodox Canonical */
Convert::Convert() {
	_char_type = 0;
	_int_type = 0;
	_float_type = 0;
	_double_type = 0;
}

Convert::Convert(const Convert &src) {
	*this = src;
}

Convert::~Convert() {

}

Convert &Convert::operator=(const Convert &src) {
	_char_type = src._char_type;
	_int_type = src._int_type;
	_float_type = src._float_type;
	_double_type = src._double_type;
	return *this;
}

/* Member Function */
void Convert::convert_input(std::string src) {
	// char
	if (isalpha(src[0]) && src.length() == 1) {
		_char_type = src[0];
		cast_value("char");
		print();
	}

	// int
	// float
	// double

	// Exception
	else
		throw ConversionImpossible();
}

void Convert::cast_value(std::string type) {
	// 정적 캐스팅(static casting)
	if (type == "char") {
		_int_type = static_cast<int>(_char_type);
		_float_type = static_cast<float>(_char_type);
		_double_type = static_cast<double>(_char_type);
	}
	else if (type == "int") {
		_char_type = static_cast<char>(_int_type);
		_float_type = static_cast<float>(_int_type);
		_double_type = static_cast<double>(_int_type);
	}
	else if (type == "float") {
		_char_type = static_cast<char>(_float_type);
		_int_type = static_cast<int>(_float_type);
		_double_type = static_cast<double>(_float_type);
	}
	else if (type == "double") {
		_char_type = static_cast<char>(_double_type);
		_int_type = static_cast<int>(_double_type);
		_float_type = static_cast<float>(_double_type);
	}
}

void Convert::print() {
	// char
	if (' ' <= _char_type && _char_type <= '~') // 32~126
		std::cout << "char: '" << _char_type << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// int
	std::cout << "int: " << _int_type << std::endl;

	// float
	std::cout << std::fixed; // 소수점 한자리로 고정
	std::cout.precision(1);

	std::cout << "float: " << _float_type << "f" << std::endl;

	// double
	std::cout << "double: " << _double_type << std::endl;
}

/* Exception */
const char *Convert::InputError::what() const throw() {
	return "[ Too Many Inputs ]";
}

const char *Convert::ConversionImpossible::what() const throw() {
	return "[ Conversion Impossible ]";
}