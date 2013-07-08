binary="TCHead.exe"

g++ -static -Os main.cpp -o $binary \
-ansi -Wall -Wextra -std=gnu++0x \
-IC:/boost/include/ \
-IE:/Botan-1.10.1/Botan-1.10.1/build/include/ \
C:/Boost/lib/libboost_program_options-s.a \
E:/Botan-1.10.1/Botan-1.10.1/libbotan-1.10.a

strip $binary

upx --best $binary

