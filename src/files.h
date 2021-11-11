#ifndef Files_h
#define Files_h

#include <fstream>
#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>

#define NUM_ARGS 2

/**
* Files class - This class creates an object that handles all of the fil.io
**/

class Files {

private:

	/**
	*@param dirent - pointer for reading contents of directory
	*@param dir - pointer for the directory
	*@param wav - compare string for the newfile name the user enters
	*@param flag - flag for if the string compare check fails
	**/
	
	struct dirent* read;
	DIR *dir=NULL;
	std::string wav;
	int flag=0;
public:

	/**
	*@param filenames - vector to hold the filenames inside the directory
	*@param arg - public check for the main to use
	*@param newfile - holds newfile name user chooses
	**/
	
	std::vector<std::string> filenames;
	bool arg=0;
	std::string newfile;
	

	Files();
	

	bool Argvcheck(int argc,char const* argv[]);
	void Readfilenames(char const* argv[]);
	std::string getnewfile();
	bool wavcheck();
	bool DupCheck();


};

#endif