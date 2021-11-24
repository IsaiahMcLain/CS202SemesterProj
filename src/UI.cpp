#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept>
#include "wav.h"
#include "tools.h"

//Prototypes
void startMessage();
void menu();
void debug(); //put code in here and run with "-d" flag to skip ui menu
//void ruler(); //Temporary function for formatting purposes
void inputValidation(int userChoice);
int choiceSelector(int userchoice);
void menuSelector(int userChoice);

//Global Constants
const int minMenuChoice = 1;
const int maxMenuChoice = 4;

int main(int argc, char* argv[])
{
    // if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'd'){
    //     debug();
    //     return 0;
    // }
    if(argc == 2){
        WAV wavfile1;
        wavfile1.loadData(argv[1]);
        //fileGatherer(argv[1]);
        std::cout << "Command called where .wav was added" << std::endl;
    }

    if(argc == 1){
        std::cout << "Please enter the directory of your file below" << std::endl;
        //Argvcheck(argv[0]);
    }

    //ruler();
    startMessage();
    // std::string fileName = " ";
    //fileName = fileGatherer(fileName);
    menu();

    return 0;
}

//Presents introduction message to user
void startMessage(){
    std::cout << "Welcome to the CS202 Semester Project Digital Audio Workstation." << std::endl;
    std::cout << std::setw(100) << std::setfill('-') << '-' << std::endl;
    std::cout << "This project enables you to edit your audio files." << std::endl;
    std::cout << "Please enter the name of your file below. It must be a .wav file." << std::endl;
    std::cout << "Please include .wav in your filename" << std::endl;
    std::cout << std::setw(100) << std::setfill('*') << '*' << std::endl;
    std::cout << std::endl;
}

//Presents the menu for the user to select an option from after they have entered their file name
void menu(){
    bool exit = true;
    int userChoice{};
    std::string menu =
    "__________________________________________________________________________________________\n"
    "*                                             **Main Menu**                              *\n"
    "*  1. Display File Metadata                                                              *\n"
    "*  2. Add Echo to Audio File                                                             *\n"
    "*  3. Add Gain Adjustment to Audio File                                                  *\n"
    "*  4. Quit Program                                                                       *\n"
    "* Please make a choice 1-4.                                                              *\n"
    "__________________________________________________________________________________________\n";

    while(exit){
        std::cout << menu << std::endl;

        std::cin >> userChoice;
        inputValidation(userChoice);

            if(userChoice == maxMenuChoice) {
                exit = false;
                break;
            }
            else {
                menuSelector(userChoice);
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
        << minMenuChoice <<" and " << maxMenuChoice << " 4 from the menu."
        << std::endl;
    }
}

//Function which includes actual menu selection logic and calls function based on case selected
void menuSelector(int userChoice){
  WAV wav1; //For dedugging purposes will be moved
  wav1.loadData("sampleFiles/yes-8-bit-mono.wav");
    switch(userChoice) {
        case 1:
            std::cout << wav1;
            break;
        case 2:
            std::cout << "Echo function called" << std::endl;
            break;
        case 3:
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
            wav1.gain(gainChoice);
            break;
    }
}

void debug() {
        WAV wav1;
        wav1.loadData("sampleFiles/yes-8-bit-mono.wav");
        std::cout << wav1;
        //wav1.gain(.5); //dont go much over 3
        //wav1.normalize(0x9000); //the int passed in here is the value to normalize to or the max value you want 0xffff is max.. or maybe 0xefff
        wav1.loPass(0x99); //set the maximium value for any sample
        wav1.writeData("test.wav");
}

//Test purposes only
//void ruler(){
//    std::cout << "123456789012345678901234567890123456789012345678901234567890" <<
//    "123456789012345678901234567890123456789012345678901234567890" << std::endl;
//}
