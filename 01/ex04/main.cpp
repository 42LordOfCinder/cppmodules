#include <iostream>
#include <fstream>

std::string	lineReplaced(std::string line, std::string s1, std::string s2) {
	size_t		s1Ind;
	std::string	newLine = line;
	std::string	startTmp;
	std::string	endTmp;

	(void) s2;
	s1Ind = newLine.find(s1);
	while (s1Ind != std::string::npos) {
		startTmp = newLine.substr(0, s1Ind);
		endTmp = newLine.substr(s1Ind + s1.length(), newLine.length() - (s1.length() + s1Ind));
		newLine = startTmp + s2 + endTmp;
		s1Ind = newLine.find(s1);
	}
	return newLine;
}

int	main(int argc, char *argv[]) {
	std::ifstream	fileIn;
	std::ofstream	fileOut;
	std::string		line;

	if (argc != 4) {
		std::cerr << "Expecting 3 arguments" << std::endl;
		return 1;
	}
	fileIn.open(argv[1], std::ios::in);
	if (!fileIn.is_open()) {
		std::cerr << "Error opening file: " << argv[1] << std::endl;
		return 1;
	}
	fileOut.open((std::string(argv[1]) + ".replace").c_str(), std::ios::out);
	if (!fileOut.is_open()) {
		std::cerr << "Could not create replace file" << std::endl;
		fileIn.close();
		return 1;
	}
	while (std::getline(fileIn, line)) {
		fileOut << lineReplaced(line, std::string(argv[2]), std::string(argv[3]));
		fileOut << std::endl;
	}
	fileIn.close();
	fileOut.close();
	return 0;
}
