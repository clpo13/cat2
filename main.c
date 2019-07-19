// cat2 - prints the contents of given files to stdout
// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2018-2019 Cody Logan
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

int main(int argc, char **argv) {
    // TODO: if no arguments are specified, read from stdin
    if (argc > 1) {
        // Print help or version info and then quit
        if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
            printf("%s v%s\n", PROJECT_NAME, PROJECT_VERSION);
            exit(0);
        }
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
            printf("Usage: cat2 file1 file2 ...\n");
            printf("Prints the contents of one or more files to stdout.\n\n");
            printf("  -h, --help     print this message and quit\n");
            printf("  -v, --version  print version number and quit\n");
            exit(0);
        }
    }
    // Read each file specified on the command line
    for (int i = 1; i < argc; i++) {
        // Open the file
        FILE *fp = fopen(argv[i], "r");

        // If the pointer is null, the file couldn't be opened
        if (fp == NULL) {
            printf("cat2: %s: cannot open file\n", argv[i]);
            exit(1);
        }

        // Print the contents of the file line-by-line
        // Returns a null pointer when an error or EOF is encountered
        char line[80];
        while (fgets(line, 80, fp) != NULL) {
            printf("%s", line);
        }

        // Close the file
        fclose(fp);
    }

    return 0;
}
