binary="TCHead"

g++ -static -Os main.cpp -o $binary \
-ansi -Wall -Wextra -std=c++0x \
-I/usr/local/include/boost/ \
-I/usr/local/include/botan-1.10/ \
/usr/local/lib/libboost_program_options-s.a \
/usr/local/lib/libbotan-1.10.a \
-pthread

strip $binary

upx --best $binary

