/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:11:29 by tforster          #+#    #+#             */
/*   Updated: 2024/10/12 15:44:33 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

// Font Color
# define BLK		"\033[30m"
# define RED		"\033[31m"
# define GRN		"\033[32m"
# define YLW		"\033[33m"
# define BLU		"\033[34m"
# define L_BLU		"\033[94m"
# define MGT		"\033[35m"
# define CYN		"\033[36m"

// Font Type
# define BOLD		"\033[1m"
# define ITLC		"\033[3m"

// Background Color
# define BG_BLK		"\033[48;5;2m"
# define BG_RED		"\033[48;5;0m"
# define BG_GRM		"\033[48;5;1m"
# define BG_YLW		"\033[48;5;3m"
# define BG_BLU		"\033[48;5;4m"
# define BG_MGT		"\033[48;5;5m"
# define BG_CYN		"\033[48;5;6m"
# define BG_WHT		"\033[48;5;7m"

// Reset ALL
# define RST		"\033[0m"

// Font possition
# define CL_LN		"\033[K"
# define UP_LN		"\033[F"

#endif
