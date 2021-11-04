#include "wav.h"


WAV::WAV(std::string riff, int wavSize, std::string wave, std::string fmt, int fmtSize, short audioFmt, short numChannels, int smplRate, int byteRate, short smplAlignment, short bitDepth, std::string data, int dataBytes) 
: wavSize(wavSize), fmtSize(fmtSize), audioFmt(audioFmt), numChannels(numChannels), smplRate(smplRate), byteRate(byteRate), smplAlignment(smplAlignment), bitDepth(bitDepth), dataBytes(dataBytes)
{
  if (riff == "RIFF")
    WAV::riff = riff;
  else
    throw std::string("RIFF");
  if (wave == "WAVE")
    WAV::wave = wave;
  else
    throw std::string("WAVE");
  if (fmt == "fmt ")
    WAV::fmt = fmt;
  else
    throw std::string("fmt ");
  if (data == "data")
    WAV::data = data;
  else
    throw std::string("data");
  /*WAV::wavSize = wavSize;
  WAV::fmtSize = fmtSize;
  WAV::audioFmt = audioFmt;
  WAV::numChannels = numChannels;
  WAV::smplRate = smplRate;
  WAV::byteRate = byteRate;
  WAV::smplAlignment = smplAlignment;
  WAV::bitDepth = bitDepth;
  WAV::dataBytes = dataBytes;*/
}

int WAV::getWavSize() const {return wavSize;}
int WAV::getFmtSize() const {return fmtSize;}
int WAV::getAudioFmt() const {return audioFmt;}
int WAV::getNumChannels() const {return numChannels;}
int WAV::getSmplRate() const {return smplRate;}
int WAV::getByteRate() const {return byteRate;}
int WAV::getSmplAlignment() const {return smplAlignment;}
int WAV::getBitDepth() const {return bitDepth;}
int WAV::getDataBytes() const {return dataBytes;}
