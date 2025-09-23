#include "menu_logic.h"


void action_choice(const char *compressionPath, const char *decompressionPath) {
    char choice;

    printf("\nDo you want to: compress, decompress or exit the program? [c/d/e]:\n");
    printf("Your choice: ");

    while (scanf("%c", &choice) != 1 ||
           (choice != 'c' && choice != 'd' && choice != 'e')) {
        printf("Invalid input! Please enter one of [c/d/e]: ");
    }

    if (choice == 'e') {
        printf("Goodbye.\nProgram closure..\n");
        exit(0);
    }

    if (choice == 'c') {
        compress_every_file(compressionPath);
    } else if (choice == 'd') {
        decompress_every_file(decompressionPath);
    }
}


bool continue_working_yn() {
    char work_state;

    printf("\nDo you want to exit? [y/n]:\n");
    printf("Your choice:");
    while (scanf(" %c", &work_state) != 1 || (work_state != 'y' && work_state != 'n')) {
        printf("Invalid input. Enter 'y' or 'n':");
    }

    if (work_state == 'y') {
        printf("\nGoodbye.\nProgram closure..\n");
        return false;
    }

    printf("\n");
    return true;
}

FolderPaths folder_creation() {
    const char *compression = "LZ4_COMPRESSION";
    const char *decompression = "LZ4_EXTRACTION";
    FolderPaths fp = {{0}, {0}, false};

    printf("\n\n---- UTILITY CREATION ----\n\nStaging folder creation...\n");

    char desktopPath[MAX_PATH];
    if (!SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktopPath))) {
        printf("Failed to get Desktop path.\n");
        return fp;
    }

    if (snprintf(fp.compression_path, sizeof(fp.compression_path), "%s\\%s", desktopPath, compression) < 0) {
        printf("Path formatting error (compression).\n");
        return fp;
    }
    if (snprintf(fp.decompression_path, sizeof(fp.decompression_path), "%s\\%s", desktopPath, decompression) < 0) {
        printf("Path formatting error (decompression).\n");
        return fp;
    }

    bool ok1 = (CreateDirectoryA(fp.compression_path, NULL) || GetLastError() == ERROR_ALREADY_EXISTS);
    if (ok1) printf("Compression folder ready at: %s\n", fp.compression_path);
    else printf("Failed to create '%s'. Error: %lu\n", fp.compression_path, GetLastError());

    SetLastError(0);
    bool ok2 = (CreateDirectoryA(fp.decompression_path, NULL) || GetLastError() == ERROR_ALREADY_EXISTS);
    if (ok2) printf("Extraction folder ready at: %s\n", fp.decompression_path);
    else printf("Failed to create '%s'. Error: %lu\n", fp.decompression_path, GetLastError());

    fp.success = ok1 && ok2;
    return fp;
}

bool check_folder_creation(const FolderPaths paths) {
    if (!paths.success) {
        printf("Folder creation failed.\n");
        return false;
    }
    else return true;
}
