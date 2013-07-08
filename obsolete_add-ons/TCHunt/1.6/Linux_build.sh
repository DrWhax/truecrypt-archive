#!/bin/sh

echo 'Enter binary name: '
read binary

# build TCHunt on Debian

g++ -static -Os main.cpp -o $binary \
-I/usr/local/include/boost/ \
-ansi -Wall -Wextra -Weffc++ -std=c++0x \
/usr/local/lib/libboost_program_options-s.a \
/usr/local/lib/libboost_filesystem-s.a \
/usr/local/lib/libboost_system-s.a

strip -s $binary

upx --best $binary

echo 'built' $binary

