#include "wav.h"
#include <cstdlib>

WAV::WAV(){}

bool WAV::compression(double cutOff, double scale) {
	int16_t maxValue = 0;
	for (int x = 0; x < numSamples; x++ ) {
		int16_t sample = readSample(x);
		if (abs(sample) > abs(maxValue))
			maxValue = sample;
	}
	for (int x = 0; x < numSamples; x++) {
		int16_t sample = readSample(x);
		if (abs(sample) > abs(maxValue) * cutOff)
			sample = sample * scale;
			writeSample(x, sample);
	}
	return true;
}

bool WAV::echo() {
	int echoSize = metaData.samplesPerSec/2;
	int numEcho = metaData.subchunk2Size/(echoSize*metaData.bitsPerSample/8);
	int16_t buffer[echoSize];
	for (int x = 0; x < numEcho; x++){
		if (x % 4 == 0) {
			for (int y = 0; y < echoSize; y++) {
				buffer[y] = readSample (y+(x*echoSize));
			}
		} else {
			for (int y = 0; y < echoSize; y++) {
				buffer[y] = buffer[y]/2;
				writeSample(y+(echoSize*x), buffer[y]);
			}
		}

	}
	return true;
}

int16_t WAV::readSample(int32_t index) const{
	if (metaData.bitsPerSample == 16)
		return dataBytes[(index*2)+1]*0x100+dataBytes[index*2];
	else if (metaData.bitsPerSample == 8)
		return dataBytes[index];
	else
		return 0;
}


bool WAV::writeSample(int32_t index, int16_t value) {
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

bool WAV::loPass() {
	int16_t maxValue = 0;
	for (int x = 0; x < numSamples; x++ ) {
		int16_t sample = readSample(x);
		if (abs(sample) > abs(maxValue))
			maxValue = sample;
	}
	for (int x = 0; x < numSamples; x++) {
		int16_t sample = readSample(x);
		if (abs(sample) > abs(maxValue * .75)) writeSample(x, maxValue * .75);
	}
	return true;
}

bool WAV::normalize() {
	int16_t maxValue = 0;
	for (int x = 0; x < numSamples; x++) {
		int16_t sample = readSample(x);
		if (abs(sample) > abs(maxValue))
			maxValue = sample;
	}
	if (metaData.bitsPerSample == 8) {
		double scale = 300.0/abs(maxValue);
		std::cout << "Scale: " << scale << std::endl;
		std::cout << "Max Size: " << maxValue << std::endl;
		gain(scale);
	}
	if (metaData.bitsPerSample == 16) {
		double scale = 500.0/abs(maxValue);
		std::cout << "Scale: " << scale << std::endl;
		std::cout << "Max Size: " << maxValue << std::endl;
		gain(scale);
	}

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
