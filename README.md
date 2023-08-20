# Bills PC

A python library built with pybind to emulate the pc storage of a pokemon game.

In practicality, this is a simple CRUD app using an sqlite database (with the
C source code) exposed to a python library using pybind. You can test it out 
with the `lib_test.py` file, or the `bills-pc.py` file for an interface around
it. 


NOTE: This is mostly a proof of concept to learn how pybind works within c++. 
I haven't used this extensively, and things may not be up to the highest 
standard.

## TO USE
Requirements: Docker

`make create env` to set up the environment to use this in and enter in a tty,
then `python3 lib_test.py` or `python3 bills_pc.py` to run this library.


