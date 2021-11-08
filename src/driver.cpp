#include <iostream>
#include "wav.h"
#include <string.h>


std::ostream &operator<<(std::ostream &output, const WAV &wav) {
        output << "wavSize: " << wav.getWavSize() << "\nfmtSize: " << wav.getFmtSize() << "\naudioFmt: " << wav.getAudioFmt() << "\nnumChannels: " << wav.getNumChannels() << "\nsmplRate: " << wav.getSmplRate() << "\nbyteRate: " << wav.getByteRate() << "\nsmplAlignment: " << wav.getSmplAlignment() << "\nbitDepth: " << wav.getBitDepth() << "\ndataBytes: " << wav.getDataBytes() << "\n";
        return output;
}

void printHex(const char * hex) {
        for (int x = 0; x < 44; x++) {
                if (x % 4 == 0)
                        printf("\n");
                printf("%x-%c\t", hex[x], hex[x]);
        }
        return;
}

int main()
{

        try {
                WAV wav1("sampleFiles/sample1MB.wav");
                std::cout << wav1;
                printHex(wav1.getMetaTmp());
        } catch(std::string e) {
                std::cout << e << std::endl;
        }
        return 0;
}

