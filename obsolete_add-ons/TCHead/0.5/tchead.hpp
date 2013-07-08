// Copyright 2011-2012 16Systems, LLC. All rights reserved.

// TCHead is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// TCHead is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with TCHead.  If not, see <http://www.gnu.org/licenses/>.

// Email: TCHead@16s.us

// 16 Systems, LLC
// P.O. Box 356
// Blacksburg, VA
// 24063


// Standard Includes
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>

// Boost Includes
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>

// Botan Crypto Includes
#include <botan/botan.h>
#include <botan/pbkdf2.h>


// Globals
bool brute = false;
bool debug = false;
bool hidden = false;
bool system_volume = false;
bool STDIN = false;
std::string WORD_FILE;

const unsigned int iv_size = 16;
const unsigned int salt_size = 64;
const unsigned int full_header_size = 512;
const unsigned int header_size = 448;

const std::string magic = "54525545"; //hex for 'TRUE'
std::string volume_name = "standard_volume.tc";


inline std::string get_salt( const std::string& full_header_string )
{
	// Always return 64 bytes

	if ( full_header_string.size() != full_header_size ) 
	{
		return std::string ( salt_size, 0 );
	}

	const std::string salt( full_header_string, 0, salt_size );
	return salt;
}


inline std::string get_header( const std::string& full_header_string )
{
	// Always return 448 bytes

	if ( full_header_string.size() != full_header_size ) 
	{
		return std::string ( header_size, 0 );
	}

	const std::string header( full_header_string, salt_size, header_size );
	return header;
}


std::string decrypt_header( const std::string& cipher, const std::string& header, const Botan::SymmetricKey& key, const Botan::InitializationVector& iv )
{
	Botan::Pipe decode( new Botan::Hex_Decoder );
	decode.process_msg( header );
	const std::string encrypted_header = decode.read_all_as_string(0);

	Botan::Pipe decrypt( Botan::get_cipher( cipher, key, iv, Botan::DECRYPTION ) );
	decrypt.process_msg( encrypted_header );
	const std::string decrypted_header = decrypt.read_all_as_string(0);

	Botan::Pipe encode( new Botan::Hex_Encoder );
	encode.process_msg( decrypted_header );
	const std::string hex_decrypted_header = encode.read_all_as_string(0);

	return hex_decrypted_header;
}


bool verify( const std::string& decrypted_header )
{
	// Get checksum bytes (last 256 bytes of the decrypted header)
	const std::string cs_bytes( decrypted_header, 192, 256 );

	Botan::Pipe crc32( new Botan::Hash_Filter("CRC32") );
	crc32.process_msg( cs_bytes );
	const std::string crc = crc32.read_all_as_string(0);

	// Get checksum
	const std::string cs( decrypted_header, 8, 4 );
	
	if ( debug == true )
	{
		std::cout << "cs_bytes_size: " << cs_bytes.size() << std::endl;
		std::cout << "crc: " << crc << std::endl;
		std::cout << "crc_size: " << crc.size() << std::endl;
		std::cout << "cs: " << cs << std::endl;
		std::cout << "cs_size: " << cs.size() << std::endl;
	}

	if ( crc == cs )
	{
		return true;
	}

	else
	{
		return false;
	}
}


std::string get_iv()
{
    // The IV is 16 null bytes
    // This returns the IV in hexidecimal

	const std::string iv( iv_size, '\0' );

	Botan::Pipe encode( new Botan::Hex_Encoder );
	encode.process_msg( iv );
	const std::string hex_iv = encode.read_all_as_string(0);

	if ( debug == true )
	{
		std::cout << "hex_iv: " << hex_iv << std::endl;
	}

	return hex_iv;
}


std::map<std::string, unsigned int> hash_map()
{
    // A map of the hashes used by TC and their rounds.

	std::map<std::string, unsigned int> hashes;

	if ( system_volume == true )
	{
		hashes.insert( std::pair<std::string, unsigned int>( "PBKDF2(HMAC(RIPEMD-160))", 1000 ) );
        return hashes;
	}

	else
	{
		hashes.insert( std::pair<std::string, unsigned int>( "PBKDF2(HMAC(RIPEMD-160))", 2000 ) );
	    hashes.insert( std::pair<std::string, unsigned int>( "PBKDF2(HMAC(SHA-512))", 1000 ) );
	    hashes.insert( std::pair<std::string, unsigned int>( "PBKDF2(HMAC(Whirlpool))", 1000 ) );
        return hashes;
	}
}


std::map<std::string, unsigned int> load_ciphers()
{
	std::map<std::string, unsigned int> Ciphers;

    if ( system_volume == true )
    {
	    Ciphers.insert( std::pair<std::string, unsigned int>( "AES-256/XTS", 1 ) );
	    return Ciphers;
    }

    else
    {
	    Ciphers.insert( std::pair<std::string, unsigned int>( "AES-256/XTS", 1 ) );
	    Ciphers.insert( std::pair<std::string, unsigned int>( "Serpent/XTS", 1 ) );
	    Ciphers.insert( std::pair<std::string, unsigned int>( "Twofish/XTS", 1 ) );
	    return Ciphers;
    }
}


void version()
{
	std::cout << "_/_/_/_/_/    _/_/_/  _/    _/                          _/" << std::endl;
	std::cout << "   _/      _/        _/    _/    _/_/    _/_/_/    _/_/_/" << std::endl;
	std::cout << "  _/      _/        _/_/_/_/  _/____/  _/   _/   _/   _/" << std::endl;
	std::cout << " _/      _/        _/    _/  _/       _/   _/   _/   _/" << std::endl;
	std::cout << "_/        _/_/_/  _/    _/   _/_/_/   _/_/_/    _/_/_/ v0.5" << std::endl << std::endl;
}

