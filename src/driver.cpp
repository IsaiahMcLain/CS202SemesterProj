#include <iostream>
#include "wav.h"
int main()
{
  std::cout << "Hello World!" << std::endl;

  try {
  WAV wav1("RIFF", 7, "WAVE", "fmt ", 7, 7, 7, 7, 7, 7, 7, "data", 7);
  } catch(std::string e) {
    std::cout << e << std::endl;
  }
  return 0;
}
