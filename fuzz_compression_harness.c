// Fuzz the *compress* path: AFL mutates the input file contents.
// We pass an absolute path to your compressor.

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

// from your codebase:
extern void compress_every_file(const char *path);

static void die(const char *msg){ perror(msg); exit(1); }

int main(int argc, char **argv){
    if(argc != 2){ fprintf(stderr,"usage: %s <file>\n", argv[0]); return 1; }

    char abs_in[PATH_MAX];
    if(!realpath(argv[1], abs_in)) die("realpath");

    // Call directly (no menus / scanf):
    compress_every_file(abs_in);
    return 0;
}
