#include "utility_functions.h"



void getOutputPath(const char *inputPath, const char mode, char *outputPath) {
    char fullPath[MAX_PATH_LEN];
    GetFullPathName(inputPath, MAX_PATH_LEN, fullPath, NULL);

    char *ext = strrchr(fullPath, '.');

    if (mode == 'c') {
        // Add .lz4 extension
        snprintf(outputPath, MAX_PATH_LEN, "%s.lz4", fullPath);
    } else if (mode == 'd') {
        if (ext && strcmp(ext, ".lz4") == 0) {
            // Remove .lz4 extension
            strncpy(outputPath, fullPath, ext - fullPath);
            outputPath[ext - fullPath] = '\0';
        } else {
            // Append _dec if no .lz4
            snprintf(outputPath, MAX_PATH_LEN, "%s_dec", fullPath);
        }
    }
}


void compress_file(const char *inputPath, const char *outputPath) {
    FILE *fin = fopen(inputPath, "rb");
    FILE *fout = fopen(outputPath, "wb");

    if(!fin) {
        printf("%s",inputPath);
        printf("Error input path\n");
        exit(EXIT_FAILURE);
    }

    if(!fout) {
        printf("%s",outputPath);
        printf("Error output path\n");
        exit(EXIT_FAILURE);
    }

    LZ4_writeFile_t *writer;
    if (LZ4F_writeOpen(&writer, fout, NULL)) {
        fprintf(stderr, "LZ4F_writeOpen failed.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[4096];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), fin)) > 0) {
        if (LZ4F_write(writer, buffer, n) != n) {
            fprintf(stderr, "LZ4F_write failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    LZ4F_writeClose(writer);
    fclose(fin);
    fclose(fout);
    printf("\n- %s\nCompressed to:\n- %s\n", inputPath, outputPath);
}


void decompress_file(const char *inputPath, const char *outputPath) {
    FILE *fin = fopen(inputPath, "rb");
    FILE *fout = fopen(outputPath, "wb");

    if(!fin) {
        printf("%s",inputPath);
        printf("Error input path\n");
        exit(EXIT_FAILURE);
    }

    if(!fout) {
        printf("%s",outputPath);
        printf("Error output path\n");
        exit(EXIT_FAILURE);
    }

    LZ4_readFile_t *reader;
    if (LZ4F_readOpen(&reader, fin)) {
        fprintf(stderr, "LZ4F_readOpen failed.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[4096];
    size_t n;
    while ((n = LZ4F_read(reader, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, 1, n, fout);
    }

    LZ4F_readClose(reader);
    fclose(fin);
    fclose(fout);
    printf("\n- %s\nDecompressed to:\n- %s\n", inputPath, outputPath);
}

