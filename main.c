#include "menu/menu_logic.h"
#include <stdbool.h>

int main() {

    const FolderPaths paths = folder_creation("LZ4_COMPRESSION", "LZ4_DECOMPRESSION");
    if (!check_folder_creation(paths)) return 1;
    bool working = true;

    while (working) {
        printf("\n---- LZ4 ZIPPER ----\n");
        action_choice(paths.compression_path, paths.decompression_path);
        working = continue_working_yn();
    }

    return 0;
}
