#include "datafunctions.h"

//Global Constants
const std::string saveLocationG = "default.wav";

void displayMetaData(const std::unique_ptr<WAV>& wavfile1){
	std::cout << std::endl;
	std::cout << std::setw(20) << std::setfill(' ') << "File Meta Data" << std::endl;
	std::cout << *wavfile1 << std::endl;
}

void echo(std::unique_ptr<WAV>& wavfile1){
	std::cout << "Echo applied to file" << std::endl;
	wavfile1->echo();
	saveFileEcho(wavfile1);
}

void gain(std::unique_ptr<WAV>& wavfile1){
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
}

void compression(std::unique_ptr<WAV>& wavfile1){
	std::cout << "File has been compressed" << std::endl;
	wavfile1->compression(.5,.5);
	saveFile(wavfile1);
}

void loPass(std::unique_ptr<WAV>& wavfile1){
	std::cout << "Low pass filter added to file" << std::endl;
	wavfile1->loPass();
	saveFile(wavfile1);
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
	bool check = true;
	if(fileNameArray[length-1] != 'v' && fileNameArray[length-2] != 'a' &&
	fileNameArray[length-3] != 'w' && fileNameArray[length-4] != '.'){
  	check=false;
	}

	if(check)
		wavfile1->writeData(saveLocation);
	else
		wavfile1->writeData(saveLocationG);
}

void saveFileEcho(std::unique_ptr<WAV>& wavfile1){
	std::string saveLocation;
	std::cout << "Please enter a save file name!" << std::endl;
	std::cout << "Otherwise the file will have default.wav as name"
	<< std::endl;
	std::cin >> saveLocation;
	int length = saveLocation.length();
	char fileNameArray [length + 1];
	strcpy(fileNameArray, saveLocation.c_str());
	bool check = true;
	if(fileNameArray[length-1] != 'v' && fileNameArray[length-2] != 'a' &&
	fileNameArray[length-3] != 'w' && fileNameArray[length-4] != '.'){
  	check=false;
	}

	if(check)
		wavfile1->writeData(saveLocation);
	else
		wavfile1->writeData(saveLocationG);
}
