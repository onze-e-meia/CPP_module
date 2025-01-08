/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:00:38 by tforster          #+#    #+#             */
/*   Updated: 2024/12/09 15:42:19 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstdlib>
#include <iostream>
#include "include/MateriaSource.hpp"
#include "include/Character.hpp"
#include "include/Cure.hpp"
#include "include/Fire.hpp"
#include "include/Ice.hpp"
#include "lib/color.hpp"

int	main() {
	system("clear");
	std::cout << U_LINE BOLD COP "Basic test." RST ENDL;
	std::cout << COP "Create a Source with the " ITALIC "Interface." RST ENDL;
	IMateriaSource	*source00 = new MateriaSource();
	std::cout << COP "Create a Materia " ITALIC "ptr." RST ENDL;
	AMateria		*ice00 = new Ice();
	std::cout << COP "Clone it." RST ENDL;
	AMateria		*ice01 = ice00->clone();

	std::cout << COP "Test NULL " ITALIC "Materia." RST ENDL;
	source00->learnMateria(NULL);
	std::cout << COP "Learn " ITALIC "Ice." RST ENDL;
	source00->learnMateria(ice00);
	std::cout << COP "Try to learn " ITALIC "Ice" RST COP " again." RST ENDL;
	source00->learnMateria(ice00);
	std::cout << COP "Learn the " ITALIC "cloned Ice." RST ENDL;
	source00->learnMateria(ice01);
	std::cout << COP "Learn " ITALIC "Cure and Fire." RST ENDL;
	source00->learnMateria(new Cure());
	source00->learnMateria(new Fire());
	std::cout << COP "Try to learn another " ITALIC "Fire." RST ENDL
		COP "Because Source is full we need to save the pointer to delete it later" ENDL;
	AMateria		*fire00 = new Fire();
	source00->learnMateria(fire00);

	std::cout << ENDL COP "Create two Character with the " ITALIC "Interface." RST ENDL;
	ICharacter	*char00 = new Character();
	ICharacter	*char01 = new Character("Terra");
	std::cout << ENDL COP "Create materia from Source to first Character." RST ENDL;
	char00->equip(source00->createMateria("Ultima"));
	char00->equip(source00->createMateria("ice"));
	char00->equip(source00->createMateria("cure"));
	char00->equip(source00->createMateria("fire"));
	char00->equip(new Fire());
	Fire	fire01;
	char00->equip(&fire01);

	std::cout << ENDL COP "Create materia from Source to second Character." RST ENDL;
	AMateria 	*cure00 = new Cure();
	char01->equip(cure00);
	char01->equip(cure00);

	std::cout << ENDL COP "Use materia." RST ENDL;
	char00->use(0, *char01);
	char00->use(1, *char01);
	char00->use(2, *char01);
	char00->use(3, *char01);
	char00->use(4, *char01);
	char01->use(0, *char00);
	char01->use(1, *char00);

	std::cout << ENDL COP "Unequip CURE from second Character." RST ENDL;
	char01->unequip(0);

	std::cout << ENDL U_LINE BOLD COP "Manual " ITALIC "delete." RST ENDL;
	std::cout << COP "Source." ENDL;
	delete source00;
	std::cout << COP "Fire." ENDL;
	delete fire00;
	std::cout << COP "First Character." ENDL;
	delete char00;
	std::cout << COP "Second Character." ENDL;
	delete char01;
	std::cout << COP "Cure." ENDL;
	delete cure00;


	std::cout << ENDL BOLD U_LINE COP "BASIC test with AMateira *ptr." RST ENDL
		COP "Declare a ptr " ITALIC "AMateria" RST COP " and an object " ITALIC "Character:" RST ENDL;
	AMateria	*m = NULL;
	AMateria	*m00;
	m00 = m;

	ICharacter *char02;
	char02 = new Character();
	std::cout << COP "Try to use Materia:" RST ENDL;
	if (m00)
		m00->use(*char02);
	else
		std::cout << "AMateria pointer is not " ITALIC L_RED "initialized!" RST ENDL;
	std::cout << COP "Instantiate Materia with " BOLD V_BLU "ICE:" RST ENDL;
	m00 = new Ice();
	std::cout << "Get Materia type: " << m00->getType() << ENDL;
	m00->use(*char02);

	std::cout << COP "Clone " BOLD V_BLU "ICE" RST COP " Materia:" RST ENDL;
	AMateria *ice = m00->clone();
	std::cout << "Get Materia type: " << m00->getType() << ENDL;
	ice->use(*char02);

	std::cout << ENDL U_LINE BOLD COP "Manual " ITALIC "delete." RST ENDL;
	delete m00;
	m00 = NULL;
	delete ice;
	delete char02;


	std::cout << ENDL BOLD U_LINE COP "TEST Character " ITALIC "deep copy." RST ENDL;
	std::cout << COP "First Character and equip ICE." ENDL;
	Character	char03("Terra");
	char03.equip(new Ice());
	std::cout << COP "Second Character "  ITALIC "deep copy of first" ENDL;
	Character	char04(char03);
	std::cout << COP "Equip FIRE on fisrt and CURE on Second Character." ENDL;
	char03.equip(new Fire());
	char04.equip(new Cure());
	std::cout << COP "Use." ENDL;
	char03.use(1, char04);
	char04.use(1, char03);

	std::cout << ENDL U_LINE BOLD COP "Automatic " ITALIC "delete." RST ENDL;
	return (EXIT_SUCCESS);

}
