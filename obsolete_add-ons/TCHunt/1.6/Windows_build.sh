#!/bin/sh

echo 'Enter binary name: '
read binary

# build TCHunt in MingW on Windows

g++ -static -Os main.cpp -o $binary \
-Ic://Boost/include/ \
c://Boost/lib/libboost_program_options-s.a \
c://Boost/lib/libboost_filesystem-s.a \
c://Boost/lib/libboost_system-s.a

strip -s $binary

upx --best $binary

echo 'built' $binary
