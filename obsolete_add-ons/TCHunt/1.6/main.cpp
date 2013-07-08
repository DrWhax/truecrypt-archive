// Copyright 2007-2012 16Systems, LLC. All rights reserved.

// TCHunt is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// TCHunt is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with TCHunt.  If not, see <http://www.gnu.org/licenses/>.

// Email: tchunt@16s.us

// 16 Systems, LLC
// P.O. Box 356
// Blacksburg, VA
// 24063 

// Boost Includes
#include "boost/filesystem/operations.hpp"
#include "boost/program_options.hpp"

// Standard Includes
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>


bool VERBOSE = false;


// The modulo test.
bool modulo( const std::string& file_path, const uintmax_t file_size )
{
	if ( file_size % 512 == 0 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "modulo_true:\t" << file_path << "\t" << file_size << std::endl;
			return true;
		}
		else
			return true;
	}
		
	else
	{
		if ( VERBOSE == true )
		{
			std::cout << "modulo_false:\t" << file_path << "\t" << file_size << std::endl;
			return false;
		}
		else
			return false;
	}
}


// The Chi Squared Distribution test.
bool X2( const std::string& file_path )
{
	// sample_size = bytes read.
	// possibilities = number of possible byte values.
	static const int sample_size = 1024*13;
	static const int possibilities = 256;
	
	double chi = 0.0;
	static const double min = 163.0;
	static const double max = 373.0;
	static const double expected = sample_size/possibilities;
	std::vector<double> observed_frequency;
	
	std::vector<int> sample_bytes;

	std::ifstream fd;
  
	// Open the file in binary mode for reading.
	fd.open (file_path.c_str(), std::ios::binary);
	
	int i = 0;
	if ( fd.is_open() )
	{
		// Read bytes	    
		while ( i < sample_size )
		{
			int c = fd.get();
			sample_bytes.push_back( c );
			++i;
		}
		
		// Close the file
		fd.close();
		
		//std::cout << sample_bytes.size() << std::endl;
	}
	else
	{
		if ( VERBOSE == true )
		{
			std::cout << "X2:\tcannot open file:\t" << file_path << std::endl;
			return false;
		}
		else
			return false;
	}
	
	
	for ( int x = 0; x < possibilities; ++x )
	{
		// Populate observed_frequency
		double num_chars = count( sample_bytes.begin(), sample_bytes.end(), x  );
		observed_frequency.push_back(num_chars);
	}
	
	//std::cout << observed_frequency.size() << std::endl;
	
	//~ The four chi squared calculations
	//~ one = observed - expected
	//~ two = one squared
	//~ three = two/expected (this is individual chi)
	//~ four = sum the individual chi results for one X2 score.
	
	std::vector<double>::iterator it;
	for( it = observed_frequency.begin(); it != observed_frequency.end(); ++it )
	{	
		double observed = *( it );
		double one = observed - expected;
		double two = one * one;
		double three = two / expected;
		chi += three;
	}

	if ( chi < min )
	{
		if ( VERBOSE == true )
		{
			std::cout << "X2_nandom:\t" << file_path << "\t" << chi << std::endl;
			return false;
		}
		else
			return false;
	}
  
	else if ( chi > max )
	{
		if ( VERBOSE == true )
		{
			std::cout << "X2_nandom:\t" << file_path << "\t" << chi << std::endl;
			return false;
		}
		else
			return false;
	}
  
	else
	{
		if ( VERBOSE == true )
		{
			std::cout << "X2_random:\t" << file_path << "\t" << chi << std::endl;
			return true;
		}
		else
			return true;
	}  
}


// Skip Certain files based on the file header (up to 4 bytes). 
bool header( const std::string& file_path )
{
	int i = 0;

	std::vector<int> header_bytes;

	std::ifstream fd;
  
	// Open the file in binary mode for reading.
	fd.open (file_path.c_str(), std::ios::binary);

	if (fd.is_open())
	{
		// Read First 4 bytes
		while (i < 4)
		{
			header_bytes.push_back(fd.get());
			++i;
		}
		// Close the file
		fd.close();
	}

	else
	{
		if ( VERBOSE == true )
		{
			std::cout << "header:\tcannot open file:\t" << file_path << std::endl;
			return false;			
		}
		else
			return false;
	}
	
	int byte1, byte2, byte3, byte4;
	byte1 = header_bytes[0];
	byte2 = header_bytes[1];
	byte3 = header_bytes[2];
	byte4 = header_bytes[3];    
	
	// Skip GZIP files
	//
	// Three Byte Header
	// Hex(1f 8b 08) Dec(31 139 8)
	if ( byte1 == 31 and byte2 == 139 and byte3 == 8 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_GZIP:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	
	// Skip RAR files
	//
	// Four Byte Header
	// Hex(52 61 72 21) Dec(82 97 114 33)
	else if ( byte1 == 82 and byte2 == 97 and byte3 == 114 and byte4 == 33 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_RAR:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}

	// Skip GIF files
	//
	// Three Byte Header
	// Hex(47 49 46 38) Dec(71 73 70 56) GIF8
	else if ( byte1 == 71 and byte2 == 73 and byte3 == 70 and byte4 == 56 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_GIF:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip ZIP files
	// 4 byte header Hex(50 4b 03 04) Dec(80 75 3 4)
	else if ( byte1 == 80 and byte2 == 75 and byte3 == 3 and byte4 == 4 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_ZIP:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip VDF files (Virus Database File from Avira)
	// 4 byte header 'Viru' Hex(56 69 72 75) Dec(86 105 114 117)
	else if ( byte1 == 86 and byte2 == 105 and byte3 == 114 and byte4 == 117 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_ZIP:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip .ar | .deb files
	// 4 byte header Hex(21 3c 61 72) Dec(33 60 97 114)
	// Total header is "!<arch>"
	else if ( byte1 == 33 and byte2 == 60 and byte3 == 97 and byte4 == 114 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_AR:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip .cab files
	// 4 byte header Dec(77 83 67 70)
	else if ( byte1 == 77 and byte2 == 83 and byte3 == 67 and byte4 == 70 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_CAB:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip .png files
	// 4 byte header Dec(137 80 78 71)
	else if ( byte1 == 137 and byte2 == 80 and byte3 == 78 and byte4 == 71 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_PNG:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip .jpg files
	// 4 byte header Dec(255 216 255 224)
	else if ( byte1 == 255 and byte2 == 216 and byte3 == 255 and byte4 == 224 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_JPG:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip .xex (xbox 360) files
	// 4 byte header Dec(88 69 88 50)
	else if ( byte1 == 88 and byte2 == 69 and byte3 == 88 and byte4 == 50 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_XEX:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}

	// Skip ID3 files
	// Dec(73 68 51 3)
	else if ( byte1 == 73 and byte2 == 68 and byte3 == 51 and byte4 == 3 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_ID3:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}		
		
	// Skip RIFF
	// Hex(52 49 46 46) Dec(82 73 70 70)
	else if ( byte1 == 82 and byte2 == 73 and byte3 == 70 and byte4 == 70 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_RIFF:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip PDF
	// Hex(25 50 44 46) Dec(37 80 68 70)
	else if ( byte1 == 37 and byte2 == 80 and byte3 == 68 and byte4 == 70 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_PDF:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip BZ2
	// Hex(42 5A 68 39) Dec(66 90 104 57)
	else if ( byte1 == 66 and byte2 == 90 and byte3 == 104 and byte4 == 57 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_BZ2:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip epi
	// Hex(fd 86 a4 c9) Dec(253 134 164 201)
	else if ( byte1 == 253 and byte2 == 134 and byte3 == 164 and byte4 == 201 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_EPI:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// Skip MPQ (World of WarCraft data files)
	// Hex(4d 50 51) Dec(77 80 81)
	else if ( byte1 == 77 and byte2 == 80 and byte3 == 81 )
	{
		if ( VERBOSE == true )
		{
			std::cout << "header_MPQ:\t" << file_path << std::endl;
			return true;
		}
		else
			return true;
	}
	
	// File does not have a known file header.
	else
	{
		if ( VERBOSE == true )
		{
			std::cout << "no_header:\t" << file_path << std::endl;
			return false;
		}
		else
			return false;
	}
  
}


// Iterate through the filesystem applying tests.
void files( const boost::filesystem::path& dir_path, const unsigned int tc_min_file_size )
{
	std::string str_path;
	boost::filesystem::directory_iterator end_itr;
	
	for ( boost::filesystem::directory_iterator itr(dir_path); itr != end_itr; ++itr )
	{
		str_path = itr->path().string();
		
		try
		{
			// Folders
			if ( boost::filesystem::is_directory( itr->status() ) and !boost::filesystem::symbolic_link_exists( itr->path() ) )
			{
				// Recursion
				files( str_path, tc_min_file_size );
			}
		}
    
		catch ( const boost::filesystem::filesystem_error& e ) 
		{
			std::cerr << e.what() << str_path << std::endl; 
		}
  
		try
		{
			// Regular files 
			if ( boost::filesystem::is_regular( itr->status() ) and !boost::filesystem::symbolic_link_exists( itr->path() ) )
			{
				// Get file's size in bytes
				const uintmax_t filesize = boost::filesystem::file_size( itr->path() );
				
				// 1. If the file is above minimum file size, pass it on
				if ( filesize >= tc_min_file_size )
				{				
					// 2. If the file passes the modulo test, pass it on
					if ( modulo( str_path, filesize ) == true )
					{
						// 3. If file passes X2 Test, pass it on
						if ( X2( str_path ) == true )
						{
							// 4. If file has no known header, stop and report it
							if ( header( str_path ) == false )
							{
								std::cout << "Suspect_File:\t" << str_path << std::endl;
							}
						}
					}
				}

				else
				{
					if ( VERBOSE == true )
					{
						std::cout << "Too_Small:\t" << str_path << std::endl;
					}
				}
			}
		} 
    
		catch ( const boost::filesystem::filesystem_error& e ) 
		{
			std::cerr << e.what() << str_path << std::endl;
		}
		  
	}
}


void version()
{
	std::cout << "_/_/_/_/_/    _/_/_/  _/    _/                     _/" << std::endl;
	std::cout << "   _/      _/        _/    _/  _/   _/  _/_/_/  _/_/_/_/" << std::endl;
	std::cout << "  _/      _/        _/_/_/_/  _/   _/  _/    _/  _/" << std::endl;
	std::cout << " _/      _/        _/    _/  _/   _/  _/    _/  _/" << std::endl;
	std::cout << "_/        _/_/_/  _/    _/   _/_/_/  _/    _/    _/_/ v1.6" << std::endl;
}


int main( int argc, char* argv[] )
{
	const unsigned int tc_min_file_size = 15*(1024*1024); // 1024 * 19
	std::string search_path;

	boost::program_options::options_description d("\nAllowed options for TCHunt");
	d.add_options()
	                ("dir,d", boost::program_options::value<std::string>(), "The directory to search (recursive).")
			("help,h", "Print this message and exit.")
	                ("verbose,v", "Print verbose output.")
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

	if ( m.count("verbose") ) 
	{
		VERBOSE = true;
	}

	if ( m.count("dir") )
	{
		search_path = m["dir"].as<std::string>();
		files( search_path, tc_min_file_size );	 		
	}

	return 0;
}
