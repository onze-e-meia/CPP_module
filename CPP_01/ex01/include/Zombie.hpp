/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:41:37 by tforster          #+#    #+#             */
/*   Updated: 2024/10/15 16:45:00 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		std::string _nameZombie;

	public:
		Zombie();
		Zombie(const std::string &nameZombie);
		~Zombie();

		void	set_nameZombie(const std::string nameZombie);
		std::string	get_nameZombie(void) const;
		void	announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
