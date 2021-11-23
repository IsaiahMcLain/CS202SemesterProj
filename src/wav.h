#ifndef WAV_H
#define WAV_H
#include <string>
#include <fstream>
#include <iostream>
typedef struct	WAV_HEADER
{
	uint8_t		RIFF[4];	    
	uint32_t	chunkSize;	    
	uint8_t		WAVE[4];	    
     
	uint8_t		fmt[4];	    
	uint32_t	subchunk1Size;  
	uint16_t	audioFormat;    
	uint16_t	numOfChan;	    
	uint32_t	samplesPerSec;  
	uint32_t	bytesPerSec;    
	uint16_t	blockAlign;     
	uint16_t	bitsPerSample;  
	 
	uint8_t		subchunk2ID[4]; 
	uint32_t	subchunk2Size;
} wav_meta;


class WAV {

private:
	uint8_t* dataBytes;
	wav_meta metaData;
	int32_t numSamples;
	int32_t readSample(int32_t index) const;
	bool writeSample(int32_t index, int32_t value);
public:
	WAV();
	bool loPass(int32_t max);
	bool normalize(int32_t max);
	/**
	 * Applies a gain effect to the data
	 * @return bool if successful
	 * @param gain decimal value to scale the data
	 */
	bool gain(double gain);
	/**
	 * Loads the meta data into the struct and the data into the 8 bit int array
	 * @param filePath direct or relative path to the .wav file
	 */
	bool loadData(std::string filePath);
	/**
	 * Writes the data from the struct and 8 bit int array to the provided file
	 * @param filePath direct or relative path to the .wav file to be made or changed
	 */
	bool writeData(std::string filePath);
	wav_meta getMetaData() const;
	uint8_t* getDataBytes() const;
};

#endif
