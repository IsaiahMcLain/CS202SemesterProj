#ifndef WAV_H
#define WAV_H
#include <string>
#include <fstream>
#include <iostream>

class WAV {

private:
       char metaTmp[44]; 
  //Header
  char riff[4]; //should contain "RIFF" notice all caps
  //int wavSize;
  char wave[4]; //should contain "WAVE" notice all caps

  //Format
  char fmt[4]; //should contain "fmt " notice trailing space
  int fmtSize;
  short audioFmt;
  short numChannels;
  int smplRate;
  int byteRate;
  short smplAlignment;
  short bitDepth;

  //Data
  char data[4]; //should contain "data"
  int dataBytes;
  //std::string bytes; //we should make sure to allocate enough memory after we get dataBytes
public:
  int wavSize;
  WAV(std::string);
  //WAV(std::string, int, std::string, std::string, int, short, short, int, int, short, short, std::string, int);
  const char* getMetaTmp() const;
  int getWavSize() const;
  int getFmtSize() const;
  int getAudioFmt() const;
  int getNumChannels() const;
  int getSmplRate() const;
  int getByteRate() const;
  int getSmplAlignment() const;
  int getBitDepth() const;
  int getDataBytes() const;
};

#endif
