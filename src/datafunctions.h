#ifndef DATAFUNCTIONS_H_
#define DATAFUNCTIONS_H_

#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <fstream>
#include <cstring>
#include "tools.h"

/**
 * Dereferences smart pointer to display the file's meta data to user.
 * @param wavfile1 which is a dynamically allocated object of type WAV which is displayed
 */
void displayMetaData(const std::unique_ptr<WAV>& wavfile1);

/**
 * Adds echo from wav.cpp echo method to wavfile1 object
 * @param wavfile1 dynamic object which has echo added to it
 */
void echo(std::unique_ptr<WAV>& wavfile1);

/**
 * Adds gain from wav.cpp gain method to wavfile1 object
 * @param wavfile1 dynamic object which has echo added to it
 */
void gain(std::unique_ptr<WAV>& wavfile1);

/**
 * Adds compression from wav.cpp compression method to wavfile1 object
 * @param wavfile1 dynamic object which has compression added to it
 */
void compression(std::unique_ptr<WAV>& wavfile1);

/**
 * Adds lopas filter from wav.cpp lopass method to wavfile1 object
 * @param wavfile1 dynamic object which has a lowpass filter added to it
 */
void loPass(std::unique_ptr<WAV>& wavfile1);

/**
 * Saves file that user opended and added effects to. Checks to make sure user spelt
 * file name and type correctly, if not it sets default.wav as the file name. Also normalizes
 * the audio automatically by using the normalize method from wav.cpp.
 * @param wavfile1 dynamic object which is saved to the user's computer
 */
void saveFile(std::unique_ptr<WAV>& wavfile1);

/**
 * Saves file that user opended and added effects to (for ech only). Checks to make sure user spelt
 * file name and type correctly, if not it sets default.wav as the file name. Does not have normalization
 * added to it as we could not get echo and normalization working together in time.
 * @param wavfile1 dynamic object which is saved to the user's computer
 */
void saveFileEcho(std::unique_ptr<WAV>& wavfile1);


#endif //DATAFUNCTIONS_H_
