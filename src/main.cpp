#include <iostream>
#include "wav.h"
#include "datafunctions.h"

//Prototypes

/**
 * Displays start message to user and asks them to either quit program or continue
 * @return bool if user decides to quit
 */
bool startMessage();

/**
 * Displays menu to user and asks them which function would they like to apply to their file
 * @param wavfile1 used as menu calls all functions that work with the file and it needs to be passed through
 */
void menu(std::unique_ptr<WAV>& wavfile1);

/**
 * Displays start message to user and asks them to either quit program or continue
 * @param userChoice used to hold what the user chose option wise and goes through a switch statement
 */
void inputValidation(int userChoice);

/**
 * Was used as a means in our code to bypass UI to test methods and file IO for our program
 */
void debug(); //put code in here and run with "-d" flag to skip ui menu

extern bool Argvcheck(char const* argv);

//Global Constants
const int minMenuChoice = 1;
const int maxMenuChoice = 5;

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

bool endProgram = true;
while(true){
	endProgram = startMessage();
	if(endProgram){
		break;
	}
		bool goOn = true;
		while(goOn){
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
					}
					else
						std::cout << "file failed to load, please re-enter file name." << std::endl;
					}
				}
				displayMetaData(wavfile1);

				menu(wavfile1);
			}
	return 0;
}

//Presents introduction message to user
bool startMessage(){
	std::cout << "Welcome to the CS202 Semester Project Digital Audio Workstation." << std::endl;
	std::cout << std::setw(100) << std::setfill('-') << '-' << std::endl;
	std::cout << "This project enables you to edit your audio files." << std::endl;
	std::cout << std::setw(100) << std::setfill('*') << '*' << std::endl;
	std::cout << "Please press enter a 0 to continue or enter a 1 to quit" << std::endl;

	bool check = true;
	int quit{};
	std::cin >> quit;

	inputValidation(quit);

	while(check){
		if(quit == 0){
			check = false;
			return false;
		}
		else if(quit == 1){
			check = false;
			return true;
		}
		else{
			std::cout << "Please enter 0 to continue or enter a 1 to quit" << std::endl;
			std::cin >> quit;
		}
	}
	return false;
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
	"*       Please make a choice 1-5.								  *\n"
	"___________________________________________________________________________________________________\n";
	std::cout << menu << std::endl;
	std::cin >> userChoice;

	inputValidation(userChoice);

	switch(userChoice){
		case 1:
			echo(wavfile1);
			break;
		case 2:
			gain(wavfile1);
			break;
		case 3:
			compression(wavfile1);
			break;
		case 4:
			loPass(wavfile1);
			break;
	}
}

//Validates user input and makes sure that an integer on the menu was entered
void inputValidation(int userChoice) {
	if (!isdigit(userChoice)) {
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
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
