/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:30:55 by tforster          #+#    #+#             */
/*   Updated: 2025/01/17 16:24:37 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename Type>
Array<Type>::Array():
	_elements(NULL),
	_size(0) {}

template<typename Type>
Array<Type>::Array(int size) {
	if (size < 0)
		throw std::invalid_argument("Array size is less then zero.");
	std::size_t	u_size = static_cast<std::size_t>(size);
	_elements = new Type[u_size]();
	_size = u_size;
}

template<typename Type>
Array<Type>::Array(const Array &other):
	_elements(new Type[other._size]),
	_size(other._size) {
	for (std::size_t i = 0; i < other._size; i++)
		_elements[i] = other._elements[i];
}

template<typename Type>
Array<Type> &Array<Type>::operator=(const Array &other) {
	if (this != &other) {
		delete[] _elements;
		_elements = new Type[other._size];
		_size = other._size;
		for (std::size_t i = 0; i < other._size; i++)
			_elements[i] = other._elements[i];
	}
	return *this;
}

template<typename Type>
Array<Type>::~Array() {
	delete[] _elements;
}

template<typename Type>
std::size_t Array<Type>::size() const {
	return this->_size;
}

template<typename Type>
const Type &Array<Type>::operator[](const std::size_t &index) const {
	if (index < _size)
		return _elements[index];
	throw (std::out_of_range("Index out of range"));
}

template<typename Type>
Type &Array<Type>::operator[](const std::size_t &index) {
	if (index < _size)
		return _elements[index];
	throw (std::out_of_range("Index out of range"));
}

template<typename Type>
std::ostream &operator<<(std::ostream &os, const Array<Type> &array) {
	std::size_t size = array.size() - 1;
	os << "[";
	for (std::size_t i = 0; i < array.size(); i++) {
		os << array[i];
		if (size != i)
			os << ", ";
	}
	return (os << "]");
}
