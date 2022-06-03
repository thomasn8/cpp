#ifndef FILESTREAMS_HPP
# define FILESTREAMS_HPP

#include <iostream>
#include <fstream>

struct FileStreams
{
	FileStreams(void);
	~FileStreams();

	// file names and streams
	std::string 	inputFileName;
	std::string 	outputFileName;
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	
	// strings to replace
	std::string 	s1;
	std::string		s2;
	std::size_t		l1;
	std::size_t		l2;

	// buffer manipulations
	std::string	buffer;
	std::string	tmp1;
	std::string	tmp2;
	std::size_t	i;
};

#endif
