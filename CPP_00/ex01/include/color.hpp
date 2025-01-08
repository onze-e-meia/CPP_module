/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:11:29 by tforster          #+#    #+#             */
/*   Updated: 2024/10/14 14:09:43 by tforster         ###   ########.fr       */
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
# define MGT		"\033[35m"
# define CYN		"\033[36m"

// Font Type
# define BOLD		"\033[1m"
# define ITLC		"\033[3m"

// Background Color (Regular)
#define BG_BLK		"\033[48;5;0m"    // Black
#define BG_RED		"\033[48;5;1m"    // Red
#define BG_GRN		"\033[48;5;2m"    // Green
#define BG_YLW		"\033[48;5;3m"    // Yellow
#define BG_BLU		"\033[48;5;4m"    // Blue
#define BG_MGT		"\033[48;5;5m"    // Magenta
#define BG_CYN		"\033[48;5;6m"    // Cyan
#define BG_WHT		"\033[48;5;7m"    // White

// Background Bright Color
#define BG_L_RED	"\033[48;5;124m"
#define BG_L_GRN	"\033[48;5;28m"
#define BG_L_YLW	"\033[48;5;226m"
#define BG_L_BLU	"\033[48;5;32m"
#define BG_L_MGT	"\033[48;5;125m"
#define BG_L_CYN	"\033[48;5;51m"
#define BG_L_WHT	"\033[48;5;255m"

// Background Colors for Shades of Black and Grey
#define BG_DARK_GREY	"\033[48;5;235m"  // Dark Grey
#define BG_GREY			"\033[48;5;240m"  // Medium Grey
#define BG_LIGHT_GREY	"\033[48;5;245m"  // Light Grey
#define BG_CHARCOAL		"\033[48;5;234m"  // Charcoal (Very Dark Grey)
#define BG_BLACK		"\033[48;5;16m"   // True Black
#define BG_SILVER		"\033[48;5;250m"  // Silver (Very Light Grey)

// Reset ALL
# define RST		"\033[0m"

// Font possition
# define CL_LN		"\033[K"
# define UP_LN		"\033[F"

#endif
