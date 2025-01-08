/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:50:08 by tforster          #+#    #+#             */
/*   Updated: 2024/11/27 20:37:25 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	if (N <= 0) {
		return NULL;
	}

	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].set_nameZombie(name);
	}

	return horde;
}
