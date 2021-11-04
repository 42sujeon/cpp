/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:09:27 by sujeon            #+#    #+#             */
/*   Updated: 2021/11/04 18:00:23 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string	Contact::field[5] = {
	"first name",
	"last name",
	"nickname",
	"phone number",
	"darkest secret"
};

Contact::Contact()
{
	// 생성자
}

Contact::~Contact()
{
	// 소멸자
}

void	Contact::get_input()
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << "[" << i + 1 << "] " << field[i] << " : ";
		std::getline(std::cin, this->input[i]);
	}
}

void	Contact::show_list()
{
	for (int i = 0; i < 3; i++)
	{
		if (this->input[i].length() > 10)
		{
			std::string	truncated;
			truncated = this->input[i].substr(0, 9);	// substr(indes, str_length)
			std::cout << truncated << ".";
		}
		else
		{
			std::cout << std::setfill (' ') << std::setw (10);
			std::cout << this->input[i];
		}
		std::cout << "|";
	}
}
