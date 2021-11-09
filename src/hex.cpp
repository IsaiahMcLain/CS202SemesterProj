#include "hex.h"
#include <iostream>
int cptod (const unsigned char *  orig, int start, int end) {
        int output = 0;
        for (int x = start; x < end; x ++) {

                output += orig[x] * pow(16, (x-start)*2);
        }
        return output;
}

int pow (int base, int exp) {
        int result = 1;
        if (exp == 0) {
                return 1;
        }
        for (int x=0; x < exp; x++) {
               result = result * base;
        }
        return result;
}
