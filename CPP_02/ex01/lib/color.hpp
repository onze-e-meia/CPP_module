/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:11:29 by tforster          #+#    #+#             */
/*   Updated: 2024/11/02 18:17:54 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

# define ENDL		"\n"
# define DENDL		"\n\n"

// Font Color
// Standard
# define BLK		"\033[38;5;0m"
# define RED		"\033[38;5;1m"
# define GRN		"\033[38;5;2m"
# define YLW		"\033[38;5;3m"
# define BLU		"\033[38;5;4m"
# define MGT		"\033[38;5;5m"
# define CYN		"\033[38;5;6m"
# define WHT		"\033[38;5;7m"
// High-itensity
# define H_BLK		"\033[38;5;8m"
# define H_RED		"\033[38;5;9m"
# define H_GRN		"\033[38;5;10m"
# define H_YLW		"\033[38;5;11m"
# define H_BLU		"\033[38;5;12m"
# define H_MGT		"\033[38;5;13m"
# define H_CYN		"\033[38;5;14m"
# define H_WHT		"\033[38;5;15m"
# define N_RED		"\033[38;5;173m"

// Font Type
# define BOLD		"\033[1m"
# define ITALC		"\033[3m"
# define U_LINE		"\033[4m"
# define O_LINE		"\033[53m"
# define BLINK		"\033[5m"
# define REVERSE	"\033[7m"

// Background Color
// Standard
#define BG_BLK		"\033[48;5;0m"
#define BG_RED		"\033[48;5;1m"
#define BG_GRN		"\033[48;5;2m"
#define BG_YLW		"\033[48;5;3m"
#define BG_BLU		"\033[48;5;4m"
#define BG_MGT		"\033[48;5;5m"
#define BG_CYN		"\033[48;5;6m"
#define BG_WHT		"\033[48;5;7m"
// High-itensity
# define BG_H_BLK	"\033[48;5;8m"
# define BG_H_RED	"\033[48;5;9m"
# define BG_H_GRN	"\033[48;5;10m"
# define BG_H_YLW	"\033[48;5;11m"
# define BG_H_BLU	"\033[48;5;12m"
# define BG_H_MGT	"\033[48;5;13m"
# define BG_H_CYN	"\033[48;5;14m"
# define BG_H_WHT	"\033[48;5;15m"
// Grayscale
#define BG_GS_0		"\033[48;5;232m"
#define BG_GS_1		"\033[48;5;236m"
#define BG_GS_2		"\033[48;5;240m"
#define BG_GS_3 	"\033[48;5;244m"
#define BG_GS_4		"\033[48;5;248m"
#define BG_GS_5		"\033[48;5;252m"

// Reset ALL
# define RST		"\033[0m"

// Font possition
# define CL_SCREEN	"\033[2J"
# define CURSOR_HM	"\033[H"
# define CL_LINE	"\033[K"
# define UP_LN		"\033[F"


#endif
