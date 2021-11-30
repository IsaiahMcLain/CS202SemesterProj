#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include "wav.h"
#include "tools.h"

//Prototypes
void startMessage();
void menu(WAV& wavfile1, std::string directory);
void debug(); //put code in here and run with "-d" flag to skip ui menu
//void ruler(); //Temporary function for formatting purposes
void inputValidation(int userChoice);
int choiceSelector(int userchoice);
void menuSelector(int userChoice, WAV& wavfile1);

extern bool Argvcheck(char const* argv);

//Global Constants
const int minMenuChoice = 1;
const int maxMenuChoice = 5;
const std::string saveLocationG = "default.wav";

int main(int argc, char* argv[])
{
  WAV wavfile1;
  std::string directory;
    // if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'd'){
    //      debug();
    //      return 0;
    // }
    if(argc == 2){
        wavfile1.loadData(argv[1]);
    }

    if(argc == 1){
        std::cout << "Please enter the directory of your file below" << std::endl;
        std::cin >> directory;

        int length = directory.length();
        char directoryArray [length + 1];
        strcpy(directoryArray, directory.c_str());
        Argvcheck(directoryArray);
    }

    //ruler();
    startMessage();
    menu(wavfile1, directory);

    return 0;
}

//Presents introduction message to user
void startMessage(){
    std::cout << "Welcome to the CS202 Semester Project Digital Audio Workstation." << std::endl;
    std::cout << std::setw(100) << std::setfill('-') << '-' << std::endl;
    std::cout << "This project enables you to edit your audio files." << std::endl;
    std::cout << std::setw(100) << std::setfill('*') << '*' << std::endl;
    std::cout << std::endl;
}

//Presents the menu for the user to select an option from after they have entered their file name
void menu(WAV& wavfile1, std::string directory){
    bool exit = true;
    int userChoice{};
    std::string menu =
    "__________________________________________________________________________________________\n"
    "*                                             **Main Menu**                              *\n"
    "*  1. Display File Metadata                                                              *\n"
    "*  2. Add Echo to Audio File                                                             *\n"
    "*  3. Add Gain Adjustment to Audio File                                                  *\n"
    "*  4. Compress Audio File                                                                *\n"
    "*  5. Quit Program and Save File                                                         *\n"
    "* Please make a choice 1-5.                                                              *\n"
    "__________________________________________________________________________________________\n";

    while(exit){
        std::cout << menu << std::endl;

        std::cin >> userChoice;
        inputValidation(userChoice);

            if(userChoice == maxMenuChoice) {
                exit = false;
                wavfile1.normalize();
                std::string saveLocation;
                std::cout << "Please enter a save file name before you go!" << std::endl;
                std::cout << "Otherwise the file will have default.wav as name"
                << std::endl;
                std::cin >> saveLocation;

                if(saveLocation.length() == 0){
                  wavfile1.writeData(saveLocationG);
                }
                else
                  wavfile1.writeData(saveLocation);
                break;
            }
            else {
                menuSelector(userChoice, wavfile1);
            }
        }
}

//Validates user input and makes sure that an integer on the menu was entered
void inputValidation(int userChoice){
    if(!isdigit(userChoice)){
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
    if(userChoice < minMenuChoice || userChoice > maxMenuChoice){
        std::cout << "Please enter a value between "
        << minMenuChoice <<" and " << maxMenuChoice << " from the menu."
        << std::endl;
    }
}

//Function which includes actual menu selection logic and calls function based on case selected
void menuSelector(int userChoice, WAV& wavfile1){
    switch(userChoice) {
        case 1:
            std::cout << wavfile1;
            break;

        case 2:
            std::cout << "Echo function called" << std::endl;
            break;

        case 3:
        {
            std::cout << "Please enter a value for gain between 0 and 3"
            << std::endl;

            bool exit = true;
            double gainChoice{};

            while(exit){
            std::cin >> gainChoice;
              if(gainChoice > 3 || gainChoice < 0){
                std::cout << "Please enter a value between 0 and 3" << std::endl;
              }
              else{
                exit = false;
              }
            }
            wavfile1.gain(gainChoice);
            break;
        }

        case 4:
          std::cout << "File has been compressed" << std::endl;
          wavfile1.compression(0.5,0.5);
          break;
    }
}

void debug() {
        WAV wav1;
        wav1.loadData("sampleFiles/yes-8-bit-mono.wav");
        std::cout << wav1;
        //wav1.gain(.5); //dont go much over 3
        wav1.normalize();
        //wav1.loPass(0x99); //set the maximium value for any sample
        //wav1.echo();
	//wav1.compression(.5, .5);
	wav1.writeData("test.wav");
}

//Test purposes only
//void ruler(){
//    std::cout << "123456789012345678901234567890123456789012345678901234567890" <<
//    "123456789012345678901234567890123456789012345678901234567890" << std::endl;
//}
