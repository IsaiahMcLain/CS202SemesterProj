#include "wav.h"


WAV::WAV(std::string riff, int wavSize, std::string wave, std::string fmt, int fmtSize, short audioFmt, short numChannels, int smplRate, int byteRate, short smplAlignment, short bitDepth, std::string data, int dataBytes) 
{
if (riff == "RIFF")
  riff = riff;
else
  throw std::string("RIFF");
if (wave == "WAVE")
  wave = wave;
else
  throw std::string("WAVE");
if (fmt == "fmt ")
  fmt = fmt;
else
  throw std::string("fmt ");
if (data == "data")
  data = data;
else
  throw std::string("data");

}
