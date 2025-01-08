/************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:05:58 by tforster          #+#    #+#             */
/*   Updated: 2024/11/28 15:38:45 by tforster         ###   ########.fr       */
/*                                                                            */
/************************************************************************/

#include <cstdlib>
#include <iostream>
#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"
#include "lib/color.hpp"

int	main(void) {
	system("clear");
	// int *leak = new int[42];
	// leak[0] = 0;

	std::cout << BOLD U_LINE COP "Test with Class Animal" RST ENDL;
	std::cout << COP "Call default " ITALIC "constructor:" RST ENDL;
	const Animal	animal;
	std::cout << animal.getType() << " ";
	animal.makeSound();
	std::cout << COP "Using keyword " ITALIC "new:" RST ENDL;
	const Animal	*ref_animal = new Animal();
	std::cout << ref_animal->getType() << " ";
	ref_animal->makeSound();
	std::cout << COP "Manual " ITALIC "delete:" RST ENDL;
	delete ref_animal;

	std::cout << ENDL BOLD U_LINE COP "Test with Class Dog" RST ENDL;
	std::cout << COP "Call default " ITALIC "constructor:" RST ENDL;
	const Dog	dog;
	std::cout << dog.getType() << " ";
	dog.makeSound();
	std::cout << COP "Using keyword " ITALIC "new:" RST ENDL;
	const Animal	*ref_dog = new Dog();
	std::cout << ref_dog->getType() << " ";
	ref_dog->makeSound();
	std::cout << COP "Manual " ITALIC "delete:" RST ENDL;
	delete ref_dog;

	std::cout << ENDL BOLD U_LINE COP "Test with Class Cat" RST ENDL;
	std::cout << COP "Call default " ITALIC "constructor:" RST ENDL;
	const Cat	cat;
	std::cout << cat.getType() << " ";
	cat.makeSound();
	std::cout << COP "Using keyword " ITALIC "new:" RST ENDL;
	const Animal	*ref_cat = new Cat();
	std::cout << ref_cat->getType() << " ";
	ref_cat->makeSound();
	std::cout << COP "Manual " ITALIC "delete:" RST ENDL;
	delete ref_cat;

	std::cout << ENDL BOLD U_LINE COP "Test using " ITALIC  "reference" RST ENDL;
	std::cout << COP "Class " ITALIC "Dog:" RST ENDL;
	const Dog		new_dog;
	std::cout << new_dog.getType() << " ";
	new_dog.makeSound();
	std::cout << COP "Class " ITALIC "Animal:" RST ENDL;
	const Animal	&new_animal = new_dog;
	std::cout << new_animal.getType() << " ";
	new_animal.makeSound();

	std::cout << ENDL BOLD U_LINE COP "Test with Class WrongCat" RST ENDL;

	std::cout << COP "Using keyword " ITALIC "new:" RST ENDL;
	std::cout << COP "Class " ITALIC "WrongAnimal:" RST ENDL;
	const WrongAnimal	*wrong_cat_00 = new WrongCat();
	std::cout << wrong_cat_00->getType() << " ";
	wrong_cat_00->makeSound();

	std::cout << COP "Class " ITALIC "WrongCat:" RST ENDL;
	const WrongCat	*wrong_cat_01 = new WrongCat();
	std::cout << wrong_cat_01->getType() << " ";
	wrong_cat_01->makeSound();
	std::cout << COP "Manual " ITALIC "delete:" RST ENDL;
	delete wrong_cat_00;
	delete wrong_cat_01;

	std::cout << ENDL BOLD COP "Automatic " ITALIC "delete" RST ENDL;
	return (EXIT_SUCCESS);
}
