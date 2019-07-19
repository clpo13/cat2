# cat2

[![Build Status](https://travis-ci.org/clpo13/cat2.svg?branch=master)](https://travis-ci.org/clpo13/cat2)

Simple clone of the GNU coreutils program cat(1). Give it a list of files and
it will print their contents to stdout.

## Building

Building from source requires a C compiler and CMake 3.5 or greater. In the
top-level source directory, run the following:

```bash
mkdir build && cd build
cmake ..
make
```

## Running

```text
Usage: cat2 file1 file2 ...
Prints the contents of one or more files to stdout.

  -h, --help     print a brief help message
  -v, --version  output the program version number and license information
```

## TODO

- [ ] print from stdin if no files specified
- [ ] integration and/or unit tests

## License

Copyright 2018-2019 Cody Logan.

This program is released under the terms of the
[Apache License, version 2.0](LICENSE). You may modify it or redistribute it
freely according to the conditions of the license.
