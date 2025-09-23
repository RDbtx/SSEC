#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "src/lz4file.h"

#define MAX_PATH_LEN 4096



// File compression and decompression
void getOutputPath(const char *inputPath, const char mode, char *outputPath);
void compress_file(const char *inputPath, const char *outputPath);
void decompress_file(const char *inputPath, const char *outputPath);
void compress_every_file(const char *baseInputPath);
void decompress_every_file(const char *baseInputPath);
#endif
