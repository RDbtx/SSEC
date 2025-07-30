#ifndef MENU_LOGIC_H
#define MENU_LOGIC_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "utility_functions.h"

// Maximum path length constant
#define MAX_PATH_LEN 4096

// Menu logic function declarations
void path_choice(char *inputPath, char *outputPath);
void action_choice(char *inputPath, char *outputPath);
bool continue_working_yn(void);

#endif
