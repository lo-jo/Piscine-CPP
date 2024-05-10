/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:06:39 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/04 08:37:16 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>

int	main(int argc, char **argv)
{
	if(argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return(0);
	}
	else {
		for(int i = 1; i < argc; i++)
		{
			for (int j = 0; j < (int)strlen(argv[i]); j++){
				argv[i][j] = toupper(argv[i][j]);
				std::cout << argv[i][j];
			}
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
