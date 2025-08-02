#include "menu_logic.h"


void path_choice(char *inputPath, char *outputPath) {
    printf("\nIf you want to compress or decompress something\npaste the absolute path to the file:\n");

    scanf("%s", inputPath);
    printf("\nChoosen file:\n%s\n", inputPath);
}


void action_choice(char *inputPath, char *outputPath) {
    char action_choice;

    printf("\nDo you want to: compress, decompress, go back or exit the program? [c/d/b/e]:\n");
    printf("Your choice:");

    while (scanf(" %c", &action_choice) != 1 ||
           (action_choice != 'c' && action_choice != 'd' && action_choice != 'b' && action_choice != 'e')) {
        printf("Invalid input! Please enter one of [c/d/b/e]:");
    }


    if (action_choice == 'b') {
        printf("Going back to path selection...\n");
        path_choice(inputPath, outputPath);
    }

    if (action_choice == 'e') {
        printf("Goodbye.\nProgram closure..\n");
        exit(0);
    }

    getOutputPath(inputPath, action_choice, outputPath);

    if (action_choice == 'c') {
        compress_file(inputPath, outputPath);
    } else if (action_choice == 'd') {
        decompress_file(inputPath, outputPath);
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
