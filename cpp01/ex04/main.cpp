/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:43:27 by tnanchen          #+#    #+#             */
/*   Updated: 2022/04/21 19:15:00 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Try : ./occurences files/testfile "occur" "ence"
*/

#include <iostream>
#include <fstream>
#include <string>
#include "FileStreams.hpp"

static int setFileStreams(FileStreams *streams, int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./occurences filename string_to_replace string_to_add" << std::endl;
		return 1;
	}
	streams->inputFileName = av[1];
	streams->outputFileName = streams->inputFileName + ".replace";
	streams->s1 = av[2];
	streams->l1 = streams->s1.length();
	streams->s2 = av[3];
	streams->l2 = streams->s2.length();
	streams->inputFile.open(streams->inputFileName);
	if (streams->inputFile.fail() == true)
	{
		std::cout << "Error while opening " << streams->inputFileName << std::endl;
		return 1;
	}
	streams->outputFile.open(streams->outputFileName);
	if (streams->outputFile.fail() == true)
	{
		std::cout << "Error while generating " << streams->outputFileName << std::endl;
		return 1;
	}
	return 0;
}

int	main(int ac, char **av)
{
	FileStreams streams;
	std::size_t	i;

	if (setFileStreams(&streams, ac, av))
		return (1);
	while (getline(streams.inputFile, streams.buffer))
	{
		i = streams.buffer.find(streams.s1);
		while (i != streams.buffer.npos)
		{
			streams.tmp1 = streams.buffer.substr(0, i);
			streams.tmp2 = streams.buffer.substr(i + streams.l1);
			streams.buffer = streams.tmp1 + streams.s2 + streams.tmp2;
			i = streams.buffer.find(streams.s1);
		}
		streams.outputFile << streams.buffer;
		if (streams.inputFile.eof() == false)
			streams.outputFile << std::endl;
		streams.buffer.clear();
	}
	streams.inputFile.close();
	streams.outputFile.close();
	return 0;
}
