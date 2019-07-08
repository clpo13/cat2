# cat2

[![Build Status](https://travis-ci.org/clpo13/cat2.svg?branch=master)](https://travis-ci.org/clpo13/cat2)

Simple clone of the GNU coreutils program cat(1). Give it a list of files and
it will print their contents to stdout.

## Building

Building from source requires GNU Autotools. In the top-level source
directory, run the following:

```bash
autoreconf -iv
./configure
make
```

## Running

```text
Usage: cat2 file1 file2 ...
Prints the contents of one or more files to stdout.

  --help     prints a brief help message
  --version  outputs the program version number and license information
```

## License

Copyright (c) 2018-2019 Cody Logan

This program is released under the terms of the [GNU GPL version 3](LICENSE)
or any later version. You may modify it or redistribute it freely according
to the conditions of the license.
