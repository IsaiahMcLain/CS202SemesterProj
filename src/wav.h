#ifndef WAV_H
#define WAV_H
#include <string>
#include <fstream>
#include <iostream>

typedef struct  WAV_HEADER
  {
    uint8_t         RIFF[4];        
    uint32_t        chunkSize;      
    uint8_t         WAVE[4];        
     
    uint8_t         fmt[4];         
    uint32_t        subchunk1Size;  
    uint16_t        audioFormat;    
    uint16_t        numOfChan;      
    uint32_t        samplesPerSec;  
    uint32_t        bytesPerSec;    
    uint16_t        blockAlign;     
    uint16_t        bitsPerSample;  
         
    uint8_t         subchunk2ID[4]; 
    uint32_t        subchunk2Size;  
  } wav_meta;


class WAV {

private:  
  wav_meta metaData;
  
public:
  WAV();
  bool loadData(std::string);
  wav_meta getMetaData() const;
};

#endif
