[![Build Status](https://travis-ci.org/mattheuslee/PyConv.svg?branch=master)](https://travis-ci.org/mattheuslee/PyConv)
[![Coverage Status](https://coveralls.io/repos/github/mattheuslee/PyConv/badge.svg?branch=master)](https://coveralls.io/github/mattheuslee/PyConv?branch=master)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/aa64e6f90e65482ebf73fbe5632e8413)](https://www.codacy.com/app/mattheus.lee/PyConv?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=mattheuslee/PyConv&amp;utm_campaign=Badge_Grade)

# __PyConv is an application that converts Python code to other languages.__

## Requires

* `g++` for `C++` compilation. Uses `C++11` features.
* `make`

## Usage

* `make PyConv` makes the PyConv executable
* After this, run `./PyConv`, the output language (currently only `cpp`), followed by pairs of input/output file-paths.
    * An example provided with this repo is `./PyConv cpp ./input/1.py ./output/1.cpp`
* To run the self-tests, run `make test`.

## Credits

* [Catch](https://github.com/philsquared/Catch) for unit testing
* [termcolor](https://github.com/ikalnytskyi/termcolor) for logging colours
