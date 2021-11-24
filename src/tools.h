#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include "wav.h"
/**
 * Oveload for '<<' operator to concatonate all meta data in the WAV class in a readable format
 */
std::ostream &operator<<(std::ostream &output, const WAV &wav);
/**
 * Function to compute the power of two integers
 * @param base the number to be raised to the given power
 * @param exp the power the base is to be raised to
 * @return the result of the operation
 */
int pow(int base, int exp);

#endif
