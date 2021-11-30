#include <fstream>
#include <string>
#include <iostream>

bool Argvcheck(char const* argv){

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
