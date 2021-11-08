#include "wav.h"
#include "hex.h"

/*WAV::WAV(std::string riff, int wavSize, std::string wave, std::string fmt, int fmtSize, short audioFmt, short numChannels, int smplRate, int byteRate, short smplAlignment, short bitDepth, std::string data, int dataBytes) 
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
}*/

WAV::WAV(const std::string fileDir) {
        std::ifstream file (fileDir, std::ifstream::binary | std::ifstream::in);
        if (file.is_open()){
                file.read(metaTmp, 44);
                file.close();
        }
        int x = 0;
        for (; x < 4; x++) {
                WAV::riff[x] = metaTmp[x];
        }
        for (x = 8 ; x < 12; x++) {
                WAV::wave[x-12] = metaTmp[x];
        }
        for(x = 12; x < 16; x++) {
                WAV::fmt[x-16] = metaTmp[x];
        }
        for(x = 36; x < 40; x++) {
                WAV::data[x-40] = metaTmp[x];
        }
        WAV::wavSize = cptod(metaTmp, 4, 8);
        WAV::fmtSize = cptod(metaTmp, 16, 20);
        WAV::audioFmt = cptod(metaTmp, 20, 22);
        WAV::numChannels = cptod(metaTmp, 22, 24);
        WAV::smplRate = cptod(metaTmp, 24, 28);
        WAV::byteRate = cptod(metaTmp, 28, 32);
        WAV::smplAlignment = cptod(metaTmp, 32, 34);
        WAV::bitDepth = cptod(metaTmp, 34, 36);
        WAV::dataBytes = cptod(metaTmp, 40, 44);
}

const char * WAV::getMetaTmp() const {return metaTmp;}
int WAV::getWavSize() const {return wavSize;}
int WAV::getFmtSize() const {return fmtSize;}
int WAV::getAudioFmt() const {return audioFmt;}
int WAV::getNumChannels() const {return numChannels;}
int WAV::getSmplRate() const {return smplRate;}
int WAV::getByteRate() const {return byteRate;}
int WAV::getSmplAlignment() const {return smplAlignment;}
int WAV::getBitDepth() const {return bitDepth;}
int WAV::getDataBytes() const {return dataBytes;}
