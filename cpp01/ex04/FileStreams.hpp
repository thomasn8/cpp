#ifndef FILESTREAMS_HPP
# define FILESTREAMS_HPP

#include <iostream>
#include <fstream>

class FileStreams
{
	public:
		FileStreams(void);
		~FileStreams();
		std::string 	inputFileName;
		std::string 	outputFileName;
		std::string 	s1;
		std::string		s2;
		std::ifstream	inputFile;
		std::ofstream	outputFile;
	
	private:
		/* data */
};

#endif