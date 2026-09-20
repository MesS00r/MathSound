#ifndef WAV
#define WAV

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

bool wav_init(FILE *file);
void wav_add(FILE *file);

#endif // WAV