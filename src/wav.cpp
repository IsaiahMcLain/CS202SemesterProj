#include "wav.h"
#include <cstdlib>

WAV::WAV(){}

int32_t WAV::readSample(int32_t index) const{
	if (metaData.bitsPerSample == 16)
		return dataBytes[(index*2)+1]*0x100+dataBytes[index*2];
	else if (metaData.bitsPerSample == 8)
		return dataBytes[index];
}


bool WAV::writeSample(int32_t index, int32_t value) {
	if (metaData.bitsPerSample == 16) {
		dataBytes[index*2] = (uint8_t)value;
		dataBytes[(index*2)+1] = (value >> 8);
		return true;
	}
	else if (metaData.bitsPerSample == 8) {
		dataBytes[index] = (uint8_t)value;
		return true;
	}
	return false;
}

bool WAV::loPass(int32_t max) {
	for (int x = 0; x < numSamples; x++) {
		int16_t sample = readSample(x);
		if (sample > abs(max)) writeSample(x, max);
	}
	return true;
}

bool WAV::normalize(int32_t max) {
	int16_t maxValue = 0;
	for (int x = 0; x < metaData.subchunk2Size; x += 2) {
		int32_t sample = readSample(x);
		if (abs(sample) > abs(maxValue))
			maxValue = sample;
	}
	double scale = max/maxValue;
	gain(scale);
	return true;
}

bool WAV::gain(double gain) {
	int32_t y = 0;
	for (int32_t x = 0; x < numSamples; x++) {
		int16_t sample = readSample(x);
		sample = sample*gain;
		writeSample(x, sample);
	}
	return true;
}

bool WAV::loadData(std::string filePath) {
	int headerSize = sizeof(metaData);
	std::ifstream file(filePath, std::ios::binary | std::ios::in);
	if (file.is_open()) {
		file.read((char*)&metaData, headerSize);
		numSamples = metaData.subchunk2Size/(metaData.bitsPerSample/8);
		dataBytes = new uint8_t[metaData.subchunk2Size];
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
