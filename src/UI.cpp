#include<iostream> 
#include<iomanip> 
#include<string> 
#include<fstream> 
#include<stdexcept>

//Prototypes
void startMessage(); 
// std::string fileGatherer();  example of function that will get filename 
void menu();  
void ruler(); //Temporary function for formatting purposes
void inputValidation(int userChoice); 
int choiceSelector(int userchoice); 
void menuSelector(int userChoice); 

int main()
{
    ruler(); 
    startMessage(); 
    //std::string fileName; 
    //fileName = fileGatherer(); examples for file I/O 
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
    const int quit = 5; 
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
    
            if(userChoice == quit) {
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
    if(userChoice < 1 || userChoice > 5){
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