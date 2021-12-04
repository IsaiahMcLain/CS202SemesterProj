#include <fstream>
#include <string>
#include <iostream>

/**
 * Displays start message to user and asks them to either quit program or continue
 * @return bool if file is opended corretly
 * @param argv takes character array from main which is the file name and location
 */
bool Argvcheck(char const* argv) {

	std::string Filename(argv);

	std::ifstream myFile;

	myFile.open(Filename);

	if (myFile.is_open()){
		myFile.close();

		if (Filename[Filename.length()-1]== 'v' && Filename[Filename.length()-2]== 'a' &&Filename[Filename.length()-3]== 'w' &&Filename[Filename.length()-4]== '.'){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}
