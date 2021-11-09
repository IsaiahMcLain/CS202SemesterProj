#include <iostream>
#include "wav.h"
#include <string.h>


std::ostream &operator<<(std::ostream &output, const WAV &wav) {
        output << "wavSize: " << wav.getWavSize() << "\nfmtSize: " << wav.getFmtSize() << "\naudioFmt: " << wav.getAudioFmt() << "\nnumChannels: " << wav.getNumChannels() << "\nsmplRate: " << wav.getSmplRate() << "\nbyteRate: " << wav.getByteRate() << "\nsmplAlignment: " << wav.getSmplAlignment() << "\nbitDepth: " << wav.getBitDepth() << "\ndataBytes: " << wav.getDataBytes() << "\n";
        return output;
}

void printHex(const unsigned char * hex, int number) {
        for (int x = 0; x < number; x++) {
                if (x % 8 == 0)
                        printf("\n");
                printf("%x\t", hex[x]);
        }
        return;
}

int main()
{

        try {
                WAV wav1("sampleFiles/sample5MB.wav");
                std::cout << wav1;
                printHex(wav1.getDataChunk(), wav1.getDataBytes());
        } catch(std::string e) {
                std::cout << e << std::endl;
        }
        return 0;
}

