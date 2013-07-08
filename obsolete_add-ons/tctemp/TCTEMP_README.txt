TCTEMP

Description: TCTEMP automates the process of using TrueCrypt to on-the-fly 
encrypt temporary files and print spooler files. TCTEMP creates new random 
keys and a new random password for a TrueCrypt volume during Windows startup. 
It then mounts the TrueCrypt volume and initializes the volume's file system. 
The file system is initialized by copying the contents of an image file to 
the TrueCrypt volume. Only those sectors are copied to the TrueCrypt volume 
which are required to replicate the file system. The initialization procedure 
should therefore be as fast as using quick-format.

Note: A more secure and more reliable method to encrypt temporary files (and 
also the Windows paging file) is to encrypt the system partition. TCTEMP is 
only then a preferable method if system encryption is not an option.

Project Start: February 2006

Public Project Key: tctemp_public_key.asc

Fingerprint of the Public Project Key: 75EB 6BC2 01B7 F6E7 4BD7  CC58 4A5F C393 19EE 6E69

Contact: racoon.tc@gmail.com

Other Projects: TCGINA, TCUSER (see TCTEMP.PDF V1.22 for public project key fingerprints)

Free Web Hosting: http://www.000webhost.com/

        | Required  |                                          |
 TCTEMP | TrueCrypt |      Windows Vista/XP/2000/2003/2008,    |
Version | version   |  Windows Vista/XP/2003/2008 x64 Edition  | Source Code
--------+-----------+------------------------------------------+------------------
  1.11  | 5.1a/5.1  |            Download (188 KB)             | Download (138 KB)
--------+-----------+------------------------------------------+------------------
        | Required  |                                          |
 TCTEMP | TrueCrypt |     Windows 7/Vista/XP/2000/2003/2008,   |
Version | version   | Windows 7/Vista/XP/2003/2008 x64 Edition | Source Code
--------+-----------+------------------------------------------+------------------
  1.18  | 6.3a/6.3  |            Download (187 KB)             | Download (122 KB)
  1.22  | 7.0–7.1a  |            Download (184 KB)             | Download (140 KB)

