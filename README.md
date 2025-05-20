# xbps-make: Minimal Package Builder for XBPS
A lightweight, POSIX-compliant Makefile wrapper to automate building packages 
for the XBPS package manager (used in Void Linux). Designed for developers who
want a simple, scriptable interface to streamline package builds without 
complex tooling.

## Features
- Minimal dependecies (coreutils, xbps, bmake, git, curl, sed, tar, gzip)
- Declarative build system
- Hackable for other package managments
- Rebuilds only when necessary

## Usage
```sh
	bmake devel/tcc.src   # download source
	bmake devel/tcc.xbps  # build and make package
	bmake clean           # clean build directory if failed
```

## Options
You can customize behavior with these environment variables:

Variable|Description
--------|------------
MAN=no|Skip installinkg man pages
POSIX=no|Skip installing POSIX-compilant options
BUILDDIR=path|Set custom path to compile `.src` files
CACHEDIR=path|Set custom cache directory fo `.src` files
XBPSDIR=path|Set custom path to output directory for `.xbps` packages

## Warning
- This project is built with `bmake` (NetBSD make). Other POSIX-compliant make tools should work, but haven't been tested.
- *GNU Make is not supported* — its include syntax is incompatible with POSIX make.

## Licence
0BSD – Zero Clause BSD License. See [LICENSE](./LICENSE) for details.
Feel free to use, modify, and share freely — no restrictions.

## Contributing
Contributions are welcome! Feel free to submit issues or pull requests.
For every issue please add a test
