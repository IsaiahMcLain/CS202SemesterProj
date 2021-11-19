#include "wav.h"


WAV::WAV(){}

bool WAV::gain(double gain) {
        for (int x = 0; x < metaData.subchunk2Size; x+=2){
                int16_t sample = dataBytes[x+1]*0x100+dataBytes[x];
                sample = sample*gain;
                dataBytes[x] = (uint8_t)sample;
                dataBytes[x+1] = (sample >> 8);
        }
        return true;
}

bool WAV::loadData(std::string filePath) {
        int headerSize = sizeof(metaData);
        std::ifstream file(filePath, std::ios::binary | std::ios::in);
        if (file.is_open()) {
                file.read((char*)&metaData, headerSize);
                dataBytes = new uint8_t [metaData.subchunk2Size];
                file.read((char*)dataBytes, metaData.subchunk2Size);
                file.close();
                return true;
        } else {
                return false;
        }
}

bool WAV::writeData(std::string filePath) {
        int headerSize = sizeof(metaData);
        std::ofstream file(filePath, std::ios::binary | std::ios::out);
        if (file.is_open()) {
                file.write((char*)&metaData, headerSize);
                for (int x = 0; x < metaData.subchunk2Size; x++)
                        file.write((char*)&dataBytes[x], 1);
                file.close();
                return true;
        } else {
                return false;
        }
}

wav_meta WAV::getMetaData() const{
        return metaData;
}

uint8_t* WAV::getDataBytes() const{
        return dataBytes;
}
