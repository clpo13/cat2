// cat2 - prints the contents of given files to stdout
// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2018-2019,2023 Cody Logan
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

#define CHUNK_SIZE 1024

void read_stdin() {
    // Read from stdin until an error or EOF is encountered.
    char buf[CHUNK_SIZE];
    while (fgets(buf, CHUNK_SIZE, stdin) != NULL) {
        printf("%s", buf);
    }
}

void read_file(char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "r");

    // If the pointer is null, the file couldn't be opened.
    if (fp == NULL) {
        printf("cat2: %s: cannot open file\n", filename);
        exit(1);
    }

    // Print the contents of the file line-by-line.
    // Returns a null pointer when an error or EOF is encountered.
    char line[CHUNK_SIZE];
    while (fgets(line, CHUNK_SIZE, fp) != NULL) {
        printf("%s", line);
    }

    // Close the file.
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        // If no arguments are specified, read from stdin.
        read_stdin();
        exit(0);
    }

    // Print help or version info and then quit.
    if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
        printf("%s v%s\n", PROJECT_NAME, PROJECT_VERSION);
        exit(0);
    } else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        printf("Usage: cat2 file1 file2 ...\n");
        printf("Prints the contents of one or more files to stdout.\n\n");
        printf("  -h, --help     print this message and quit\n");
        printf("  -v, --version  print version number and quit\n");
        exit(0);
    }

    // Read the contents of each file specified on the command line.
    // If the filename is "-", read from stdin instead.
    for (int i = 1; i < argc; i++) {
        char* fn = argv[i];
        if (strcmp(fn, "-") == 0) {
            read_stdin();
        } else {
            read_file(fn);
        }
    }

    exit(0);
}
