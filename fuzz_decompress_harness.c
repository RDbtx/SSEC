// Fuzz the *decompress* path: AFL mutates an .lz4 file.
// Start with at least one valid .lz4 seed so you reach deeper code.

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

extern void decompress_every_file(const char *path);

static void die(const char *msg){ perror(msg); exit(1); }

int main(int argc, char **argv){
    if(argc != 2){ fprintf(stderr,"usage: %s <lz4_file>\n", argv[0]); return 1; }

    char abs_in[PATH_MAX];
    if(!realpath(argv[1], abs_in)) die("realpath");

    decompress_every_file(abs_in);
    return 0;
}
