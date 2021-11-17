#include "wav.h"


WAV::WAV(){}

bool WAV::loadData(std::string filePath) {
        int headerSize = sizeof(metaData);
        std::ifstream file(filePath, std::ios::binary | std::ios::in);
        if (file.is_open()) {
                file.read((char*)&metaData, headerSize);
                uint32_t buffer[metaData.subchunk2Size];
                file.read((char*)buffer, metaData.subchunk2Size);
                file.close();
                data = buffer;
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
                for (int x = 0; x < metaData.subchunk2Size; x++) {
                        file.write((char*)&data[x], sizeof(data[x]));
                }
                file.close();
                return true;
        } else {
                return false;
        }
}

wav_meta WAV::getMetaData() const{
        return metaData;
}

uint32_t* WAV::getData() const{
        return data;
}
