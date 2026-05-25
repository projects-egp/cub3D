/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:32:53 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/25 20:39:19 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include "../libft/complete_libft.h"
# include "struct_map.h"
# include "error_messages.h"
# include "image.h"
# include "parse.h"
# include "clean.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>/*For uint_32, used to store colors. This integer
		      guarantees that integer is unsigned and has 4 bytes.
		      Needed because we use 24 bytes to store color*/
# include <math.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

#endif
