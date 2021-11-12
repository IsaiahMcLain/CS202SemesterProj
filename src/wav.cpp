#include "wav.h"


WAV::WAV(){}

bool WAV::loadData(std::string filePath) {
        int headerSize = sizeof(metaData);
        std::ifstream file(filePath, std::ios::binary | std::ios::in);
        if (file.is_open()) {
                file.read((char*)&metaData, headerSize);
                uint16_t buffer[metaData.subchunk2Size];
                file.read((char*)buffer, metaData.subchunk2Size);
                file.close();
                data = buffer;
                return true;
        } else {
                return false;
        }
}

wav_meta WAV::getMetaData() const{
        return metaData;
}

uint16_t* WAV::getData() const{
        return data;
}
