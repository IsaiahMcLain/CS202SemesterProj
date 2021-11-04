#ifndef WAV_H
#define WAV_H
#include <string>
class WAV {

private:
  //Header
  std::string riff; //should contain "RIFF" notice all caps
  int wavSize;
  std::string wave; //should contain "WAVE" notice all caps

  //Format
  std::string fmt; //should contain "fmt " notice trailing space
  int fmtSize;
  short audioFmt;
  short numChannels;
  int smplRate;
  int byteRate;
  short smplAlignment;
  short bitDepth;

  //Data
  std::string data; //should contain "data"
  int dataBytes;
  //std::string bytes; //we should make sure to allocate enough memory after we get dataBytes
public:
  WAV(std::string, int, std::string, std::string, int, short, short, int, int, short, short, std::string, int);
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
