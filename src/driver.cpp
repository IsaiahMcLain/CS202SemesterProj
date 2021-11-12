#include <iostream>
#include "wav.h"
#include <string.h>

std::ostream &operator<<(std::ostream &output, const WAV &wav) {
        wav_meta metaData = wav.getMetaData();
        output << "Chunk ID:            " << metaData.RIFF[0] << metaData.RIFF[1] << metaData.RIFF[2]  << metaData.RIFF[3] << std::endl;
        output << "Chunk Size:          " << metaData.chunkSize << std::endl;
        output << "Format:              " << metaData.WAVE[0] << metaData.WAVE[1] << metaData.WAVE[2] << metaData.WAVE[3] << std::endl;
        output << "Subchunk 1 ID:       " << metaData.fmt[0] << metaData.fmt[1] << metaData.fmt[2] << metaData.fmt[3] << std::endl;
        output << "Subchunk 1 size:     " << metaData.subchunk1Size << std::endl;
        output << "Audio Format:        " << metaData.audioFormat << std::endl;
        output << "Number of Channels:  " << metaData.numOfChan << std::endl;
        output << "Sample Rate:         " << metaData.samplesPerSec << std::endl;
        output << "Byte Rate:           " << metaData.bytesPerSec << std::endl;
        output << "Block Align:         " << metaData.blockAlign << std::endl;
        output << "Bits per Sample:     " << metaData.bitsPerSample << std::endl;
        output << "Subchunk 2 ID:       " << metaData.subchunk2ID[0] << metaData.subchunk2ID[1] << metaData.subchunk2ID[2] << metaData.subchunk2ID[3] << std::endl;
        output << "Subchunk 2 size:     " << metaData.subchunk2Size << std::endl;
        return output;
}

int main()
{

        try {
                WAV wav1;
                wav1.loadData("sampleFiles/sample1MB.wav");
                std::cout << wav1;
        } catch(std::string e) {
                std::cout << e << std::endl;
        }
        return 0;
}

