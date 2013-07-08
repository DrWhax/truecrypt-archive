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


// Local Includes
#include "tchead.hpp"


int main( int argc, char * argv[] )
{
	Botan::LibraryInitializer init;

	boost::program_options::options_description d("\nAllowed options for TCHead");

	d.add_options()
		("debug,d", "Enable debugging.")
        ("file,f", boost::program_options::value<std::string>(), "The TrueCrypt file or disk image to decrypt.")
        ("help,h", "Show this help message and exit.")
        ("hidden,H", "Decrypt the hidden volume header.")
        ("Passwords,P", boost::program_options::value<std::string>(), "Path to text file of possible passwords or the string 'stdin' to read from std::cin rather than from a file.")
		("system,s", "Specify system header.")
        ("version,v", "Print version and exit.")
	;

	boost::program_options::variables_map m;

	try
	{
		boost::program_options::store( boost::program_options::parse_command_line( argc, argv, d ), m );
		boost::program_options::notify(m);
	}

	catch ( boost::program_options::unknown_option )
	{
	   	std::cout << d << std::endl;
		return 1;
	}

	if ( m.count("help") or argc == 1 )
	{
		version();
	   	std::cout << d << std::endl;
		return 0;
	}

	if ( m.count("version") )
	{
	   	version();
		return 0;
	}

    std::string WORD;

	if ( m.count("hidden") )
	{
		hidden = true;
	}

	if ( m.count("debug") )
	{
       	debug = true;
	}

	if ( m.count("system") )
	{
       	system_volume = true;
	}

	if ( m.count("file") )
	{
       	volume_name = m["file"].as<std::string>();
	}

	if ( m.count("Passwords") )
	{
        WORD_FILE = m["Passwords"].as<std::string>();

        if ( boost::iequals( WORD_FILE, "stdin" ) )
        {
            STDIN = true;
        }

        else
        {
            STDIN = false;

		    std::ifstream fin ( WORD_FILE.c_str() );

		    if ( !fin.is_open() )
	    	{
	    		std::cout << WORD_FILE << " cannot be opened.\n";
	    		return 1;
	    	}

            fin.close();
        }
	}

	char full_header[full_header_size];

	std::ifstream src ( volume_name.c_str(), std::ios::binary );

    if ( !src.is_open() )
    {
		std::cout << "Cannot open " << volume_name << std::endl;
		return 1;
	}

    if ( system_volume )
    {
        if ( !hidden )
        {
            src.seekg( 31744 );
        }

        else
        {
            std::cerr << "--hidden may not be used with --system\n";
            return 1;
        }
    }

	if ( hidden )
	{
        if ( !system_volume )
        {
            src.seekg( 65536 );
        }

        else
        {
            std::cerr << "--hidden may not be used with --system\n";
            return 1;
        }
	}

	src.read( full_header, full_header_size );
	src.close();

	const std::string full_header_string( full_header, full_header_size );
	const std::string salt = get_salt( full_header_string );
	const std::string header = get_header( full_header_string );

	std::map<std::string, unsigned int> hashes = hash_map();
	std::map<std::string, unsigned int>::const_iterator hit;

	std::map<std::string, unsigned int> ciphers = load_ciphers();

	const Botan::OctetString iv( get_iv() ); 

    if ( STDIN )
    {
        while ( !std::cin.eof() )
        {
            getline( std::cin, WORD );

            if ( !WORD.empty() )
            {
                std::cout << WORD << "\n";

                // redundant code
                for ( hit = hashes.begin(); hit != hashes.end(); ++hit )
                {
                    Botan::PBKDF* pbkdf = Botan::get_pbkdf( hit->first );
                    const Botan::OctetString key = pbkdf->derive_key( 192, WORD, (Botan::byte*)salt.c_str(), salt.size(), hit->second );

                    delete pbkdf;

                    const std::string k1( key.as_string(), 0, 128 );
                    const std::string k2( key.as_string(), 128, 128 );
                    const std::string k3( key.as_string(), 256, 128 );

                    Botan::Pipe pipe( new Botan::Hex_Encoder );
                    pipe.process_msg( full_header_string );
                    pipe.process_msg( header );
                    pipe.process_msg( salt );

                    const std::string hex_full_header = pipe.read_all_as_string(0);
                    const std::string hex_header = pipe.read_all_as_string(1);
                    const std::string hex_salt = pipe.read_all_as_string(2);

                    const Botan::OctetString key_1 = k1;
                    const Botan::OctetString key_2 = k2;
                    const Botan::OctetString key_3 = k3;

                    if ( debug == true )
                    {			
                        std::cout << "key: " << key.as_string() << std::endl;
                        std::cout << "key_1: " << key_1.as_string() << std::endl;
                        std::cout << "key_2: " << key_2.as_string() << std::endl;
                        std::cout << "key_3: " << key_3.as_string() << std::endl;

                        std::cout << "key_1_hex_size: " << key_1.as_string().size() << std::endl;
                        std::cout << "key_2_hex_size: " << key_2.as_string().size() << std::endl;
                        std::cout << "key_3_hex_size: " << key_3.as_string().size() << std::endl;

                        std::cout << "full_header_size: " << sizeof(full_header) << std::endl;
                        std::cout << "full_header_string_size: " << full_header_string.size() << std::endl;

                        std::cout << "hex_full_header_size: " << hex_full_header.size() << std::endl;
                        std::cout << "hex_full_header: " << hex_full_header << std::endl;

                        std::cout << "header_size: " << header.size() << std::endl;
                        std::cout << "hex_header_size: " << hex_header.size() << std::endl;
                        std::cout << "hex_header: " << hex_header << std::endl;

                        std::cout << "salt_size: " << salt.size() << std::endl;
                        std::cout << "hex_salt_size: " << hex_salt.size() << std::endl;
                        std::cout << "hex_salt: " << hex_salt << std::endl;

                        std::cout << "iterations: " << hit->second << std::endl;
                    }

                    std::map<std::string, unsigned int>::const_iterator cit;

                    for ( cit = ciphers.begin(); cit != ciphers.end(); ++cit )
                    {
                        // Decrypt Individual Ciphers
                        if ( cit->second == 1 )
                        {
                            const std::string header_results( decrypt_header( cit->first, hex_header, key_1, iv ) );
                            const std::string test( header_results, 0, 8 ); 			// 64 4

                            if ( test == magic )
                            {
                                Botan::Pipe decode( new Botan::Hex_Decoder );
                                decode.process_msg( header_results );
                                const std::string decrypted_header = decode.read_all_as_string(0);
                                const std::string vol_header_ver( header_results, 8, 4 ); 	// 68 2
                                const std::string min_ver( header_results, 12, 4 );      	// 70 2
                                const std::string hidden_size( header_results, 56, 16 ); 	// 92 8
                                const std::string volume_size( header_results, 72, 16 ); 	// 100 8

                                if ( verify( decrypted_header ) )
                                {
                                    std::cout << "password: " << WORD << std::endl;
                                    std::cout << "volume: " << volume_name << std::endl;
                                    std::cout << "cipher: " << cit->first << std::endl;
                                    std::cout << "hash: " << hit->first << std::endl;
                                    std::cout << "decrypted_header: " << header_results << std::endl;
                                    std::cout << "volume_header_format_version: " << vol_header_ver << std::endl;
                                    std::cout << "minimum_truecrypt_version_required: " << min_ver << std::endl;
                                    std::cout << std::endl;
                                    return 0;
                                }
                            }
                        }

                        // Decrypt Two Cascading Ciphers
                        if ( cit->second == 2 )
                        {
                            ;
                        }

                        // Decrypt Three Cascading Ciphers
                        if ( cit->second == 3 )
                        {
                            ;
                        }
                    }
                }
                // end redundant code
            }
        }
    }

    else
    {
        std::ifstream fp ( WORD_FILE.c_str() );

        while ( !fp.eof() )
        {
            getline( fp, WORD );

            if ( (WORD[0] == '#') or WORD[0] == ' ' )
            {
                continue;
            }
        
            if ( !WORD.empty() )
            {
                std::cout << WORD << "\n";
        
                // redundant code
                for ( hit = hashes.begin(); hit != hashes.end(); ++hit )
                {
                    Botan::PBKDF* pbkdf = Botan::get_pbkdf( hit->first );
                    const Botan::OctetString key = pbkdf->derive_key( 192, WORD, (Botan::byte*)salt.c_str(), salt.size(), hit->second );

                    delete pbkdf;

                    const std::string k1( key.as_string(), 0, 128 );
                    const std::string k2( key.as_string(), 128, 128 );
                    const std::string k3( key.as_string(), 256, 128 );

                    Botan::Pipe pipe( new Botan::Hex_Encoder );
                    pipe.process_msg( full_header_string );
                    pipe.process_msg( header );
                    pipe.process_msg( salt );

                    const std::string hex_full_header = pipe.read_all_as_string(0);
                    const std::string hex_header = pipe.read_all_as_string(1);
                    const std::string hex_salt = pipe.read_all_as_string(2);

                    const Botan::OctetString key_1 = k1;
                    const Botan::OctetString key_2 = k2;
                    const Botan::OctetString key_3 = k3;

                    if ( debug == true )
                    {			
                        std::cout << "key: " << key.as_string() << std::endl;
                        std::cout << "key_1: " << key_1.as_string() << std::endl;
                        std::cout << "key_2: " << key_2.as_string() << std::endl;
                        std::cout << "key_3: " << key_3.as_string() << std::endl;

                        std::cout << "key_1_hex_size: " << key_1.as_string().size() << std::endl;
                        std::cout << "key_2_hex_size: " << key_2.as_string().size() << std::endl;
                        std::cout << "key_3_hex_size: " << key_3.as_string().size() << std::endl;

                        std::cout << "full_header_size: " << sizeof(full_header) << std::endl;
                        std::cout << "full_header_string_size: " << full_header_string.size() << std::endl;

                        std::cout << "hex_full_header_size: " << hex_full_header.size() << std::endl;
                        std::cout << "hex_full_header: " << hex_full_header << std::endl;

                        std::cout << "header_size: " << header.size() << std::endl;
                        std::cout << "hex_header_size: " << hex_header.size() << std::endl;
                        std::cout << "hex_header: " << hex_header << std::endl;

                        std::cout << "salt_size: " << salt.size() << std::endl;
                        std::cout << "hex_salt_size: " << hex_salt.size() << std::endl;
                        std::cout << "hex_salt: " << hex_salt << std::endl;

                        std::cout << "iterations: " << hit->second << std::endl;
                    }

                    std::map<std::string, unsigned int>::const_iterator cit;

                    for ( cit = ciphers.begin(); cit != ciphers.end(); ++cit )
                    {
                        // Decrypt Individual Ciphers
                        if ( cit->second == 1 )
                        {
                            const std::string header_results( decrypt_header( cit->first, hex_header, key_1, iv ) );
                            const std::string test( header_results, 0, 8 ); 			// 64 4

                            if ( test == magic )
                            {
                                Botan::Pipe decode( new Botan::Hex_Decoder );
                                decode.process_msg( header_results );
                                const std::string decrypted_header = decode.read_all_as_string(0);
                                const std::string vol_header_ver( header_results, 8, 4 ); 	// 68 2
                                const std::string min_ver( header_results, 12, 4 );      	// 70 2
                                const std::string hidden_size( header_results, 56, 16 ); 	// 92 8
                                const std::string volume_size( header_results, 72, 16 ); 	// 100 8

                                if ( verify( decrypted_header ) )
                                {
                                    std::cout << "password: " << WORD << std::endl;
                                    std::cout << "volume: " << volume_name << std::endl;
                                    std::cout << "cipher: " << cit->first << std::endl;
                                    std::cout << "hash: " << hit->first << std::endl;
                                    std::cout << "decrypted_header: " << header_results << std::endl;
                                    std::cout << "volume_header_format_version: " << vol_header_ver << std::endl;
                                    std::cout << "minimum_truecrypt_version_required: " << min_ver << std::endl;
                                    std::cout << std::endl;
                                    return 0;
                                }
                            }
                        }

                        // Decrypt Two Cascading Ciphers
                        if ( cit->second == 2 )
                        {
                            ;
                        }

                        // Decrypt Three Cascading Ciphers
                        if ( cit->second == 3 )
                        {
                            ;
                        }
                    }
                }
                // end redundant code
            }
        }

        fp.close();
    }
}

