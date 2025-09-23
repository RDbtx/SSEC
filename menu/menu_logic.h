#ifndef MENU_LOGIC_H
#define MENU_LOGIC_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "utility_functions.h"
#include <shlobj.h>

// Maximum path length constant
#define MAX_PATH_LEN 4096

typedef struct {
    char compression_path[MAX_PATH];
    char decompression_path[MAX_PATH];
    bool success;
} FolderPaths;


// Menu logic function declarations
void action_choice(const char *compressionPath, const char *decompressionPath);
FolderPaths folder_creation();
bool continue_working_yn(void);
bool check_folder_creation(const FolderPaths paths);


#endif
