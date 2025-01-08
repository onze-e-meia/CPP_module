/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:41:37 by tforster          #+#    #+#             */
/*   Updated: 2024/10/14 19:31:51 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		std::string _nameZombie;

	public:
		// Default constructor
		Zombie(const std::string &nameZombie);

		// Destructor
		~Zombie();

		// Setter methods
		void	set_nameZombie(const std::string nameZombie);

		// Getter methods
		std::string	get_nameZombie(void) const;

		void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
