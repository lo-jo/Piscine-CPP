/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:52:06 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/21 14:52:07 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
#define PARSING_HPP

#include "BitcoinExchange.hpp"

bool is_valid_value(std::string const line);
bool	is_valid_date(std::string const line);
bool	is_digits(std::string &str);
bool	is_valid_format(std::string line);
bool	is_empty_file(std::string path);

#endif