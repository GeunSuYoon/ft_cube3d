/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d_defines.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geuyoon <geuyoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:07 by geuyoon           #+#    #+#             */
/*   Updated: 2025/05/20 23:03:36 by geuyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_DEFINES_H
# define FT_CUBE3D_DEFINES_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
// map symbol
# define EMPTY		' '
# define SPACE		'0'
# define WALL		'1'
# define PNORTH		'N'
# define PSOUTH		'S'
# define PWEST		'W'
# define PEAST		'E'
# define NEWLINE	'\n'
// p_fix symbol
# define MNORTH	"NO"
# define MSOUTH	"SO"
# define MWEST	"WE"
# define MEAST	"EA"
# define MFC	"F"
# define MCC	"C"
// err code
# define ERR	1
# define WSIZE	1
// err text
# define ETPROARG		"unexpected program argument"
# define ETMAPNAME		"unexpected program argument"
# define ETIMGINFO		"unexpected image infomation"
# define ETCOLINFO		"unexpected color infomation"
# define ETMAPINFO		"unexpected map info"
# define ETMAPSHAPE		"unexpected map shape"
# define ETPLAYERNO		"no player info"
# define ETPLAYERPOS	"unexpected player pos"
# define ETPLAYERDUP	"duplicate player info"
# define ETWINDOWIMG	"Invalid window image"
// display
# define WWRATE 	16
# define WHRATE 	9
# define WSCALE		120
# define WWIDTH		1920
# define WHEIGHT	1080
# define SIZE		100
// player
# define PSIZE		0.3
# define MOVESPEED	0.3
# define ROTSPEED	0.3
// camera value
# define FOV	0.66
// minimap
# define MWIDTH		240
# define MHEIGHT	135
# define MMARGIN	20
# define MPLAYER	3
# define MPLINE		7
// color
# define COLORRED	0xFF0000
# define COLORGREEN	0x00FF00
# define COLORBLUE	0x0000FF
# define COLORWHITE	0xFFFFFF
# define COLORBLACK	0x000000
# define COLORGRAY	0xAAAAAA

#endif
