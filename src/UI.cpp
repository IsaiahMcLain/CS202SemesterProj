#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <memory>
#include <cstring>
#include "wav.h"
#include "tools.h"

//Prototypes
void startMessage();
void menu(std::unique_ptr<WAV>& wavfile1);
void debug(); //put code in here and run with "-d" flag to skip ui menu
void inputValidation(int userChoice);
//int choiceSelector(int userchoice);
void displayMetaData(const std::unique_ptr<WAV>& wavfile1);
void saveFile(std::unique_ptr<WAV>& wavfile1);
void echo(std::unique_ptr<WAV>& wavfile1);

extern bool Argvcheck(char const* argv);

//Global Constants
const int minMenuChoice = 1;
const int maxMenuChoice = 5;
const std::string saveLocationG = "default.wav";

int main(int argc, char* argv[])
{
	std::unique_ptr<WAV> wavfile1(new WAV);
	std::string directory;
	bool check = false;

	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'd') {
		debug();
		return 0;
	}

	if (argc == 2) {
		check = Argvcheck(argv[1]);
		if(check)
			wavfile1->loadData(argv[1]);
		else {
			std::cout << "file failed to load" << std::endl;
		}
	}

	startMessage();
	bool goOn = true;
	while(true){
			if (argc == 1) {
				std::cout << "Please enter the directory and name of your file below" << std::endl;
				std::cout << "Please make sure to add .wav at the end of your file" << std::endl;
				std::cin >> directory;
				int length = directory.length();
				char directoryArray [length + 1];
				strcpy(directoryArray, directory.c_str());
				check = Argvcheck(directoryArray);
				if(check){
					wavfile1->loadData(directory);
					goOn = false;
					break;
				}
				else
					std::cout << "file failed to load, please re-enter file name." << std::endl;
			}
		}
	displayMetaData(wavfile1);

	menu(wavfile1);



	return 0;
}

//Presents introduction message to user
void startMessage(){
	std::cout << "Welcome to the CS202 Semester Project Digital Audio Workstation." << std::endl;
	std::cout << std::setw(100) << std::setfill('-') << '-' << std::endl;
	std::cout << "This project enables you to edit your audio files." << std::endl;
	std::cout << std::setw(100) << std::setfill('*') << '*' << std::endl;
	std::cout << "Please press enter a 0 to continue or enter a 1 to quit" << std::endl;

	bool check = true;
	int quit{};
	std::cin >> quit;

	while(check){
		if(quit == 0){
			check = false;
			break;
		}
		else if(quit == 1){
			check = false;
			exit(0);
		}
		else{
			std::cout << "Please enter 0 to continue or enter a 1 to quit" << std::endl;
			std::cin >> quit;
		}
	}
}

//Presents the menu for the user to select an option from after they have entered their file name
void menu(std::unique_ptr<WAV>& wavfile1){
	int userChoice{};

	std::string menu =
	"___________________________________________________________________________________________________\n"
	"*						   **Main Menu**				  *\n"
	"*	1. Add Echo to Audio File								  *\n"
	"*	2. Add Gain Adjustment to Audio File							  *\n"
	"*	3. Compress Audio File									  *\n"
	"*	4. Add Low Pass Filter to Audio File							  *\n"
	"*	5. Quit Program								  *\n"
	"*       Please make a choice 1-5.								  *\n"
	"___________________________________________________________________________________________________\n";
	std::cout << menu << std::endl;
	std::cin >> userChoice;
	inputValidation(userChoice);

	switch(userChoice){
		case 1:
			std::cout << "Echo Applied to file" << std::endl;
			wavfile1->echo();
			wavfile1->writeData("test.wav");
			saveFile(wavfile1);
			break;
		case 2:
		{
			std::cout << "Please enter a value for gain between 0 and 3"<< std::endl;
			bool exit = true;
			double gainChoice{};

			while (exit) {
				std::cin >> gainChoice;
					if (gainChoice > 3 || gainChoice < 0) {
						std::cout << "Please enter a value between 0 and 3" << std::endl;
					} else {
							exit = false;
						}
					}
				wavfile1->gain(gainChoice);
				saveFile(wavfile1);
				break;
		}
		case 3:
			std::cout << "File has been compressed" << std::endl;
			wavfile1->compression(.5,.5);
			saveFile(wavfile1);
			break;
		case 4:
			std::cout << "Low pass filter added to file" << std::endl;
			wavfile1->loPass();
			saveFile(wavfile1);
			break;
		case 5:
			exit(0);
			break;
	}
}

void displayMetaData(const std::unique_ptr<WAV>& wavfile1){
	std::cout << std::endl;
	std::cout << std::setw(20) << std::setfill(' ') << "File Meta Data" << std::endl;
	std::cout << *wavfile1 << std::endl;
}

//Validates user input and makes sure that an integer on the menu was entered
void inputValidation(int userChoice) {
	if (!isdigit(userChoice)) {
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
	if (userChoice < minMenuChoice || userChoice > maxMenuChoice) {
		std::cout << "Please enter a value between "
		<< minMenuChoice <<" and " << maxMenuChoice << " from the menu."
		<< std::endl;
	}
}

void saveFile(std::unique_ptr<WAV>& wavfile1){
	wavfile1->normalize();
	std::string saveLocation;
	std::cout << "Please enter a save file name!" << std::endl;
	std::cout << "Otherwise the file will have default.wav as name"
	<< std::endl;
	std::cin >> saveLocation;
	int length = saveLocation.length();
	char fileNameArray [length + 1];
	strcpy(fileNameArray, saveLocation.c_str());
	bool check = Argvcheck(fileNameArray);

	if (check)
		wavfile1->writeData(saveLocation);
	else
		wavfile1->writeData(saveLocationG);
}

void echo(std::unique_ptr<WAV>& wavfile1){
	std::cout << "Echo applied to file" << std::endl;
	wavfile1->echo();
	saveFile(wavfile1);
}

void debug() {
	WAV wav1;
	wav1.loadData("sampleFiles/sample2MB.wav");
	std::cout << wav1;
	//wav1.gain(.5); //dont go much over 3
	//wav1.normalize();
	//wav1.loPass(); //set the maximium value for any sample
	wav1.echo();
	//wav1.compression(.5, .5);
	wav1.writeData("test.wav");
}
