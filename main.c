#include "menu/menu_logic.h"
#include <stdbool.h>

int main() {
    char inputPath[MAX_PATH_LEN];
    char outputPath[MAX_PATH_LEN];
    bool working = true;

    while (working) {
        printf("\n---- LZ4 ZIPPER ----\n");
        path_choice(inputPath, outputPath);
        action_choice(inputPath, outputPath);
        working = continue_working_yn();
    }

    return 0;
}
