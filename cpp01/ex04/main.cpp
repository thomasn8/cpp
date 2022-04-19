#include <iostream>
#include <fstream>
#include <string>
#include "FileStreams.hpp"

/* 
	Create a program that takes three parameters in the following order: a filename and
	two strings, s1 and s2.

	It will open the file <filename> and copies its content into a new file
	<filename>.replace, replacing every occurrence of s1 with s2.
*/

static int open_files(FileStreams *streams, int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./replace_words filename string_to_replace string_to_add" << std::endl;
		return 1;
	}
	streams->inputFileName = av[1];
	streams->outputFileName = streams->inputFileName + ".replace";
	streams->s1 = av[2];
	streams->s2 = av[3];
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

	if (open_files(&streams, ac, av))
		return (1);

	// travailler avec streams.inputFile - streams.s1 - streams.s2 - streams.outputFile
	// ...
	// le principe étant :
	// on read inputFile tant que pas s1 -> en injectant dans outputFile
		// si s1, on injecte s2 dans outputFile
		// on recommence a read inputFile après s1

	return 0;
}
