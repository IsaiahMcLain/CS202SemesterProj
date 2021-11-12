#include "wav.h"


WAV::WAV(){}

bool WAV::loadData(std::string filePath) {
        int headerSize = sizeof(metaData);
        std::ifstream file(filePath, std::ios::binary | std::ios::in);
        if (file.is_open()) {
                file.read((char*)&metaData, headerSize);
                
                file.close();
                return true;
        } else {
                return false;
        }
}

wav_meta WAV::getMetaData() const{
        return metaData;
}
