// cat2 - prints the contents of given files to stdout
// Copyright (C) 2018 Cody Logan
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

int main(int argc, char **argv) {
    // TODO: if no arguments are specified, read from stdin
    if (argc > 1) {
        // Print help or version info and then quit
        if (strcmp(argv[1], "--version") == 0 ||
              strcmp(argv[1], "-v") == 0) {
            printf("cat2 v%s - Copyright (C) %s %s\n", PROJECT_VERSION, COPY_YEARS, AUTHORS);
            printf("This is free software, and you are welcome to modify or redistribute it under\n");
            printf("the terms of the GNU GPL Version 3 or later <http://gnu.org/licenses/gpl.html>.\n");
            printf("This program comes with ABSOLUTELY NO WARRANTY to the extent permitted by law.\n");
            exit(0);
        }
        if (strcmp(argv[1], "--help") == 0 ||
              strcmp(argv[1], "-h") == 0) {
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
