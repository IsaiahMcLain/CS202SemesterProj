#include<iostream> 
#include<iomanip> 
#include<string> 
#include<fstream> 
#include<stdexcept>
#include"files.h"
#include"wav.h"

//Prototypes
void startMessage(); 
std::string fileGatherer(std::string fileName);  
void menu();  
void ruler(); //Temporary function for formatting purposes
void inputValidation(int userChoice); 
int choiceSelector(int userchoice); 
void menuSelector(int userChoice); 

//Global Constants
const int minMenuChoice = 1; 
const int maxMenuChoice = 5; 

std::ostream &operator<<(std::ostream &output, const WAV &wav) {
        wav_meta metaData = wav.getMetaData();
        for (int x = 0; x < metaData.subchunk2Size/(metaData.bitsPerSample/8); x++){
                if (x % metaData.numOfChan == 0)
                        std::cout << std::endl;
                else
                        std::cout << "\t";
                std::cout << wav.getData()[x];
        }
        std::cout << std::endl;
        output << "Chunk ID:            " << metaData.RIFF[0] << metaData.RIFF[1] << metaData.RIFF[2]  << metaData.RIFF[3] << std::endl;
        output << "Chunk Size:          " << metaData.chunkSize << std::endl;
        output << "Format:              " << metaData.WAVE[0] << metaData.WAVE[1] << metaData.WAVE[2] << metaData.WAVE[3] << std::endl;
        output << "Subchunk 1 ID:       " << metaData.fmt[0] << metaData.fmt[1] << metaData.fmt[2] << metaData.fmt[3] << std::endl;
        output << "Subchunk 1 size:     " << metaData.subchunk1Size << std::endl;
        output << "Audio Format:        " << metaData.audioFormat << std::endl;
        output << "Number of Channels:  " << metaData.numOfChan << std::endl;
        output << "Sample Rate:         " << metaData.samplesPerSec << std::endl;
        output << "Byte Rate:           " << metaData.bytesPerSec << std::endl;
        output << "Block Align:         " << metaData.blockAlign << std::endl;
        output << "Bits per Sample:     " << metaData.bitsPerSample << std::endl;
        output << "Subchunk 2 ID:       " << metaData.subchunk2ID[0] << metaData.subchunk2ID[1] << metaData.subchunk2ID[2] << metaData.subchunk2ID[3] << std::endl;
        output << "Subchunk 2 size:     " << metaData.subchunk2Size << std::endl;
        return output;
}

int main()
{
    ruler(); 
    startMessage(); 
    std::string fileName = " "; 
    fileName = fileGatherer(fileName); 
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

//Calls upon file I/O function and module to handle the opening of a file 
std::string fileGatherer(std::string fileName){
  // fileName = File I/O function call 
  return fileName = "test"; 
}

//Presents the menu for the user to select an option from after they have entered their file name 
void menu(){
    bool exit = true; 
    int userChoice{}; 
    std::string menu = 
    "__________________________________________________________________________________________\n"
    "*                                             **Main Menu**                              *\n"
    "*  1. Display File Metadata                                                              *\n"
    "*  2. Normalize Audio File                                                               *\n"
    "*  3. Add Echo to Audio File                                                             *\n"
    "*  4. Add Gain Adjustment to Audio File                                                  *\n"
    "*  5. Quit Program                                                                       *\n"
    "* Please make a choice 1-5.                                                              *\n"
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
        std::cout << "Please enter a value between 1 and 5 from the menu." << std::endl; 
    }
}

//Function which includes actual menu selection logic and calls function based on case selected
void menuSelector(int userChoice){
    switch(userChoice) {
        case 1: 
            std::cout << "Metadata function called" << std::endl; 
            break; 
        case 2: 
            std::cout << "Normalize function called" << std::endl; 
            break; 
        case 3: 
            std::cout << "Echo function called" << std::endl; 
            break; 
        case 4: 
            std::cout << "Gain function called" << std::endl; 
            break; 
    }
}

//Test purposes only
void ruler(){
    std::cout << "123456789012345678901234567890123456789012345678901234567890" << 
    "123456789012345678901234567890123456789012345678901234567890" << std::endl; 
}