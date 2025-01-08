/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:29:28 by tforster          #+#    #+#             */
/*   Updated: 2024/12/09 16:02:51 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include "lib/color.hpp"

int	main(int argc, char **argv) {
	system("clear");

	#ifdef LEAK
	std::cout << COP "Argument <w> for WrongCat." ENDL
		"WARNING! It will leak!" RST ENDL;
	std::string	str;
	if (argc == 2 && (str = argv[1]) == "w") {

		std::cout << ENDL BOLD U_LINE COP "Test WrongCat Brain shallow copy:" RST ENDL
			COP "First cat:" RST ENDL;
		WrongCat	cat;
		cat.setIdea("Sleep.");
		std::cout << "Brain Address: " BOLD GRN  << cat.getBrainAddress() << RST ENDL
			"Idea 0: " << cat.getIdea(0) << ENDL
			"Idea 1: " << cat.getIdea(1) << ENDL;

		std::cout << COP "Second cat, " ITALIC "Shallow Copy:" RST ENDL;
		WrongCat	deep_cat(cat);
		std::cout << "Brain Address: " BOLD GRN << deep_cat.getBrainAddress() << RST ENDL
			"Idea 0: " << deep_cat.getIdea(0) << ENDL
			"Idea 1: " << deep_cat.getIdea(1) << ENDL;
		deep_cat.setIdea("Don't bother");
		std::cout << "Idea 1: " << deep_cat.getIdea(1) << ENDL
			COP "Check first cat brain:" RST ENDL
			"Idea 1: " << cat.getIdea(1) << ENDL;

		std::cout << ENDL BOLD U_LINE COP "Test WrongCat destructor order." RST ENDL
			COP "This will lead to a leak in valgrind." RST ENDL;
		WrongAnimal *ptr_cat = new WrongCat();
		delete ptr_cat;

		std::cout << ENDL U_LINE BOLD COP "Automatic " ITALIC "delete." RST ENDL
			COP "WARNING! Double delete of WrongCat Brain." RST ENDL;
		return (EXIT_FAILURE);
	}
	#endif
	(void) argc;
	(void) argv;

	std::size_t	size = 4;
	std::cout << ENDL BOLD U_LINE COP "Test with Animal Array: " << size << RST ENDL;
	Animal	*animal[size];
	for (std::size_t i = 0 ; i < size; i++) {
		if (i < size / 2)
			animal[i] = new Dog();
		else
		 	animal[i] = new Cat();
	}
	for (std::size_t i = 0 ; i < size; i++) {
		std::cout << animal[i]->getType() << " ";
		animal[i]->makeSound();
	}
	std::cout << COP "Manual " ITALIC "delete:" RST ENDL;
	for (std::size_t i = 0 ; i < size; i++)
		delete animal[i];

	std::cout << ENDL BOLD U_LINE COP "Test Dog Brain deep copy:" ENDL
		"First dog:" RST ENDL;
	Dog	dog;
	dog.setIdea("Food!");
	dog.setIdea("Give food!");
	dog.setIdea("More food!");
	dog.setIdea("Even more food!");
	std::cout << "Brain Address: " BOLD GRN << dog.getBrainAddress() << RST ENDL
		"Idea 0: " << dog.getIdea(0) << ENDL
		"Idea 1: " << dog.getIdea(1) << ENDL
		"Idea 2: " << dog.getIdea(2) << ENDL
		"Idea 100: " << dog.getIdea(100) << ENDL;

	std::cout << COP "Second dog, " ITALIC "Deep Copy:" RST ENDL;
	Dog	deep_dog(dog);
	std::cout << "Brain Address: " BOLD GRN << deep_dog.getBrainAddress() << RST ENDL
		"Idea 3: " << deep_dog.getIdea(3) << ENDL
		"Idea 4: " << deep_dog.getIdea(4) << ENDL;
	deep_dog.setIdea("Food food food food!");
	std::cout << "Idea 4: " << deep_dog.getIdea(4) << ENDL
		COP "Check first dog brain:" RST ENDL
		"Idea 4: " << dog.getIdea(4) << ENDL;

	std::cout << ENDL BOLD U_LINE COP "Test Cat Brain deep copy:" ENDL
		"First cat:" RST ENDL;
	Cat	cat;
	cat.setIdea("Sleep.");
	std::cout << "Brain Address: " BOLD GRN << cat.getBrainAddress() << RST ENDL
		"Idea 0: " << cat.getIdea(0) << ENDL
		"Idea 1: " << cat.getIdea(1) << ENDL;

	std::cout << COP "Second cat, " ITALIC "Deep Copy:" RST ENDL;
	Cat	deep_cat(cat);
	std::cout << "Brain Address: " BOLD GRN << deep_cat.getBrainAddress() << RST ENDL
		"Idea 0: " << deep_cat.getIdea(0) << ENDL
		"Idea 1: " << deep_cat.getIdea(1) << ENDL;
	deep_cat.setIdea("Don't bother");
	std::cout << "Idea 1: " << deep_cat.getIdea(1) << ENDL
		"Check first cat brain:" RST ENDL
		"Idea 1: " << cat.getIdea(1) << ENDL;

	std::cout << ENDL BOLD U_LINE COP "Test with Animal and Poly Dog:" << RST ENDL;
	std::cout << COP "Animal:" RST ENDL;
	Animal *ptr_animal = new Animal();
	ptr_animal->makeSound();
	ptr_animal->getBrainAddress();
	ptr_animal->setIdea("idea");
	ptr_animal->getIdea(0);
	delete ptr_animal;
	std::cout << COP "Dog:" RST ENDL;
	Animal *ptr_dog = new Dog();
	ptr_dog->makeSound();
	ptr_dog->getBrainAddress();
	ptr_dog->setIdea("idea");
	std::cout << "Idea 0: " << ptr_dog->getIdea(0) << ENDL;
	delete ptr_dog;

	std::cout << ENDL U_LINE BOLD COP "Automatic " ITALIC "delete." RST ENDL;
	return (EXIT_SUCCESS);
}
