# cat2

Simple clone of the GNU coreutils program cat(1). Give it a list of files and
it will print their contents to stdout.

## Building

Building from source requires CMake 3.5 or greater. In the top-level source
directory, run the following:

```bash
mkdir build && cd build
cmake ..
make
```

## License

This program is released under the terms of the [GNU GPL version 3](LICENSE)
or any later version. You may modify it or redistribute it freely according
to the conditions of the license.
