This is basically a copy of [the version history page](http://www.truecrypt.org/docs/version-history) on truecrypt.org.

The versions that have been released are: 1.0, 1.0a, 2.0, 2.1, 2.1a, 3.0, 3.0a, 3.1, 3.1a, 4.0, 4.1, 4.2, 4.2a, 4.3, 4.3a, 5.0, 5.0a, 5.1, 5.1a, 6.0, 6.0a, 6.1, 6.1a, 6.2, 6.2a, 6.3, 6.3a, 7.0, 7.0a, 7.1, 7.1a, 7.2.

# 7.2
May 28, 2014

**No official changelog is available.**

* The ability to create new volumes was removed.
* Warnings suggesting that TrueCrypt is insecure was added.


# 7.1a
February 7, 2012

Improvements and bug fixes:

* Minor improvements and bug fixes.  (Windows, Mac OS X, and Linux)


# 7.1
September 1, 2011

New features:

* Full compatibility with 64-bit and 32-bit Mac OS X 10.7 Lion

Improvements and bug fixes:

* Minor improvements and bug fixes.  (Windows, Mac OS X, and Linux)


# 7.0a
September 6, 2010

Improvements:

* Workaround for a bug in some custom (non-Microsoft) drivers for storage device controllers that caused a system crash when initiating hibernation on TrueCrypt-encrypted operating systems.  (Windows 7/Vista/2008/2008R2)
* Other minor improvements.  (Windows, Mac OS X, and Linux)

Bug fixes:

* Minor bug fixes.  (Windows, Mac OS X, and Linux)


# 7.0
July 19, 2010

New features:

* Hardware-accelerated AES (for more information, see the chapter Hardware Acceleration).
  Note: If you want to disable hardware acceleration, select Settings > Performance and disable the option 'Accelerate AES encryption/decryption by using the AES instructions of the processor'.
* A volume can now be configured to be automatically mounted whenever its host device gets connected to the computer (provided that the correct password and/or keyfiles are supplied).  (Windows)
    * Note: For example, if you have a TrueCrypt container on a USB flash drive and you want to configure TrueCrypt to mount it automatically whenever you insert the USB flash drive into the USB port, follow these steps: 1. Mount the volume. 2. Right-click the mounted volume in the drive list in the main TrueCrypt window and select 'Add to Favorites'. 3. The Favorites Organizer window should appear. In it, enable the option 'Mount selected volume when its host device gets connected' and click OK.
    * Also note that TrueCrypt will not prompt you for a password if you have enabled caching of the pre-boot authentication password (Settings > 'System Encryption') and the volume uses the same password as the system partition/drive. The same applies to cached non-system volume passwords.
* Partition/device-hosted volumes can now be created on drives that use a sector size of 4096, 2048, or 1024 bytes (Windows, Linux).  Note: Previously only file-hosted volumes were supported on such drives.
* Favorite Volumes Organizer (Favorites > 'Organize Favorite Volumes' or 'Organize System Favorite Volumes'), which allows you to set various options for each favorite volume. For example, any of them can be mounted upon logon, as read-only or removable medium, can be assigned a special label (which is shown within the user interface instead of the volume path), excluded from hotkey mount, etc. The order in which favorite volumes are displayed in the Favorites Organizer window can be changed and it is the order in which the volumes are mounted (e.g. when Windows starts or by pressing the 'Mount Favorite Volumes' hotkey). For more information, see the chapters Favorite Volumes and System Favorite Volumes.  (Windows)
* The Favorites menu now contains a list of your non-system favorite volumes. When you select a volume from the list, you are asked for its password (and/or keyfiles) (unless it is cached) and if it is correct, the volume is mounted.  (Windows)
Security improvements:
* In response to our public complaint regarding the missing API for encryption of Windows hibernation files, Microsoft began providing a public API for encryption of hibernation files on Windows Vista and later versions of Windows (for more information, see the section TrueCrypt 5.1a in this version history). Starting with this version 7.0, TrueCrypt uses this API to encrypt hibernation and crash dump files in a safe documented way.  (Windows 7/Vista/2008/2008R2)
    * Note: As Windows XP and Windows 2003 do not provide any API for encryption of hibernation files, TrueCrypt has to modify undocumented components of Windows XP/2003 in order to allow users to encrypt hibernation files. Therefore, TrueCrypt cannot guarantee that Windows XP/2003 hibernation files will always be encrypted. Therefore, if you use Windows XP/2003 and want the hibernation file to be safely encrypted, we strongly recommend that you upgrade to Windows Vista or later and to TrueCrypt 7.0 or later. For more information, see the section Hibernation File.

Improvements:

* Many minor improvements.  (Windows, Mac OS X, and Linux)

Bug fixes:

* Minor bug fixes.  (Windows, Mac OS X, and Linux)

Removed features:

* TrueCrypt no longer supports device-hosted volumes located on floppy disks. Note: You can still create file-hosted TrueCrypt volumes on floppy disks.


# 6.3a
November 23, 2009

Improvements and bug fixes:

* Minor improvements and bug fixes.  (Windows, Mac OS X, and Linux)


# 6.3
October 21, 2009

Improvements, bug fixes:

* Full support for Windows 7.
* Full support for Mac OS X 10.6 Snow Leopard.
* The ability to configure selected volumes as 'system favorite volumes'. This is useful, for example, when you have volumes that need to be mounted before system and application services start and before users start logging on. It is also useful when there are network-shared folders located on a TrueCrypt volume and you need to ensure that the network shares will be restored by the system each time it is restarted. For more information, see the chapter System Favorite Volumes.  (Windows)

Improvements and bug fixes:

* 'Favorite' volumes residing within partitions or dynamic volumes will no longer be affected by changes in disk device numbers, which may occur, e.g., when a drive is removed or added. Note: If you use a favorite volume list saved by TrueCrypt 6.2a or earlier and you want to take advantage of this improvement, you need to resave the list using TrueCrypt 6.3.  (Windows)
* Many other minor improvements and bug fixes.  (Windows, Mac OS X, and Linux)


# 6.2a
June 15, 2009

Improvements and bug fixes:

* Improved file container creation speed on systems having issues with write block sizes greater than 64 KB.  (Windows)
* The 'Device not ready' error will no longer occur when the process of decryption of a system partition/drive is finished.  (Windows)
* Other minor improvements and bug fixes.  (Windows, Mac OS X, and Linux)


# 6.2
May 11, 2009

New features:

* The I/O pipeline now uses read-ahead buffering, which improves read performance especially on solid-state drives, typically by 30-50%.  (Windows)

Improvements, bug fixes, and security enhancements:

* The boot loader now supports motherboards with BIOSes that reserve large amounts of base memory (typically for onboard RAID controllers). Note: In order to be able to take advantage of this improvement under Windows Vista, you will have to install Service Pack 1 or higher first. Service Pack 1 for Windows Vista resolved an issue causing a shortage of free base memory during system boot.  (Windows Vista/XP/2008/2003)
* Mounting using the 'Auto-Mount Devices' feature may take significantly less time as partitions containing unencrypted filesystems are now skipped.  (Windows)
* When volumes that are mounted as read-only or removable are saved as favorite volumes, they are mounted as read-only and/or removable when 'Mount Favorite Volumes' is used.
* When a multiple-pass wipe algorithm is selected when performing in-place encryption of a non-system volume, the header areas will be wiped before the encrypted headers are written to the disk. Note: On an existing volume, you can perform such an operation by changing its password and/or keyfiles.  (Windows Vista/2008)
* Many other minor improvements, bug fixes and security enhancements.  (Windows, Mac OS X, and Linux)


# 6.1a
December 1, 2008

Improvements, bug fixes, and security enhancements:

* Minor improvements, bug fixes, and security enhancements.  (Windows, Mac OS X, and Linux)


# 6.1
October 31, 2008

New features:

* Ability to encrypt a non-system partition without losing existing data on the partition. (Windows Vista/2008)
Note: To encrypt a non-system partition in place, click 'Create Volume' > 'Encrypt a non-system partition' > 'Standard volume' > 'Select Device' > 'Encrypt partition in place' and then follow the instructions in the wizard. Please note that this is not supported on Windows XP/2000/2003 as these versions of Windows do not natively support shrinking of a filesystem (the filesystem needs to be shrunk to make space for the volume header and backup header).
* Support for security tokens and smart cards (for more information, see section Security Tokens and Smart Cards in chapter Keyfiles).
* The TrueCrypt boot loader can be prevented from displaying any texts (by selecting Settings > System Encryption and enabling the option 'Do not show any texts in the pre-boot authentication screen').
* The TrueCrypt boot loader can now display a custom message (select Settings > System Encryption and enter the message in the corresponding field) either without any other texts or along with the standard TrueCrypt boot loader texts.
* Pre-boot authentication passwords can now be cached in the driver memory, which allows them to be used for mounting of non-system TrueCrypt volumes (select Settings > System Encryption and enable the option 'Cache pre-boot authentication password').
* Linux and Mac OS X versions: The ability to mount a Windows system partition encrypted by TrueCrypt and to mount a partition located on a Windows system drive that is fully encrypted by a Windows version of TrueCrypt.

Improvements:

* Protection against memory corruption caused by bugs in certain versions of some BIOSes, which prevented the TrueCrypt boot loader from working properly.  (Windows Vista/XP/2008/2003)
* During the process of creation of a hidden operating system, TrueCrypt now securely erases the entire content of the partition where the original system resides after the hidden system has been created. The user is then prompted to install a new system on the partition and encrypt it using TrueCrypt (thus the decoy system is created).
    * Note: Although we are not aware of any security issues (connected with decoy systems) affecting the previous versions of TrueCrypt, we have implemented this change to prevent any such undiscovered security issues (if there are any). Otherwise, in the future, a vulnerability might be discovered that could allow an attacker to find out that the TrueCrypt wizard was used in the hidden-system-creation mode (which might indicate the existence of a hidden operating system on the computer) e.g. by analyzing files, such as log files created by Windows, on the partition where the original system (of which the hidden system is a clone) resides. In addition, due to this change, it is no longer required that the paging file is disabled and hibernation prevented when creating a hidden operating system.
* Many other improvements.  (Windows, Mac OS X, and Linux)

Bug fixes:

* Many minor bug fixes and security improvements.  (Windows, Mac OS X, and Linux)


# 6.0a
July 8, 2008

Resolved incompatibilities / bug fixes:

* On systems where certain inappropriately designed chipset drivers were installed, it was impossible to encrypt the system partition/drive. This will no longer occur.  (Windows Vista/XP/2008/2003)
* Other minor bug fixes.  (Windows, Mac OS X, and Linux)


# 6.0
July 4, 2008

New features:

* Parallelized encryption/decryption on multi-core processors (or multi-processor systems). Increase in encryption/decryption speed is directly proportional to the number of cores and/or processors.
    * For example, if your computer has a quad-core processor, encryption and decryption will be four times faster than on a single-core processor with equivalent specifications (likewise, it will be twice faster on dual-core processors, etc.)
    * [View benchmark results](http://www.truecrypt.org/screenshots2)
* Ability to create and run an encrypted hidden operating system whose existence should be impossible to prove (provided that certain guidelines are followed). For more information, see the section Hidden Operating System.  (Windows Vista/XP/2008/2003)
    * For security reasons, when a hidden operating system is running, TrueCrypt ensures that all local unencrypted filesystems and non-hidden TrueCrypt volumes are read-only. (Data is allowed to be written to filesystems within hidden TrueCrypt volumes.)
    * Note: We recommend that hidden volumes are mounted only when a hidden operating system is running. For more information, see the subsection Security Requirements and Precautions Pertaining to Hidden Volumes.
* On Windows Vista and Windows 2008, it is now possible to encrypt an entire system drive even if it contains extended/logical partitions. (Note that on Windows XP you can encrypt an entire system drive too, but it must contain only primary partitions.)
* New volume format that increases reliability, performance and expandability:
    * Each volume created by this or later versions of TrueCrypt will contain an embedded backup header (located at the end of the volume). Note that it is impossible to mount a volume when its header is damaged (the header contains an encrypted master key). Therefore, embedded backup headers significantly reduce this risk. Also note that a backup header is not a copy of the original volume header because it is encrypted with a different header key derived using a different salt. For more information, see the subsection Tools > Restore Volume Header.
    * Note: If the user fails to supply the correct password (and/or keyfiles) twice in a row when trying to mount a volume, TrueCrypt will automatically try to mount the volume using the embedded backup header (in addition to trying to mount it using the primary header) each subsequent time that the user attempts to mount the volume (until he or she clicks Cancel). If TrueCrypt fails to decrypt the primary header but it successfully decrypts the embedded backup header at the same time, the volume is mounted and the user is warned that the volume header is damaged (and informed as to how to repair it).
    * The size of the volume header area has been increased to 128 KB. This will allow implementation of new features and improvements in future versions and ensures that performance will not be impaired when a TrueCrypt volume is stored on a file system or device that uses a sector size greater than 512 bytes (the start of the data area will always be aligned with the start of a host-filesystem/physical sector).
    * For more information about the new volume format, see the section TrueCrypt Volume Format Specification.
    * Note: Volumes created by previous versions of TrueCrypt can be mounted using this version of TrueCrypt.
* Parallelized header key derivation on multi-core processors (one algorithm per core/thread). As a result, mounting is several times faster on multi-core processors.  (Windows)
* Ability to create hidden volumes under Mac OS X and Linux.
* On Linux, TrueCrypt now uses native kernel cryptographic services (by default) for volumes encrypted in XTS mode. This increases read/write speed in most cases. However, the FUSE driver must still be used when the volume is encrypted in a deprecated mode of operation (LRW or CBC), or when mounting an outer volume with hidden-volume protection, or when using an old version of the Linux kernel that does not support XTS mode.

Improvements:

* Up to 20% faster resuming from hibernation when the system partition/drive is encrypted.  (Windows Vista/XP/2008/2003)
* Many other improvements.  (Windows, Mac OS X, and Linux)

Removed features:

* Encrypted system partitions/drives can no longer be permanently decrypted using the TrueCrypt Boot Loader (however, it is still possible using the TrueCrypt Rescue Disk).  (Windows Vista/XP/2008/2003)
    * Note: This was done in order to reduce the memory requirements for the TrueCrypt Boot Loader, which was necessary to enable the implementation of support for hidden operating systems.

Bug fixes:

* When Windows XP was installed on a FAT16 or FAT32 partition (as opposed to an NTFS partition) and the user attempted to encrypt the system partition (or system drive), the system encryption pretest failed. This will no longer occur.
* Many other minor bug fixes and security improvements (preventing e.g. denial-of-service attacks).  (Windows, Mac OS X, and Linux)

**Note:** TrueCrypt 4.3a and 5.1a have been repackaged to contain the latest version of the TrueCrypt License introduced with TrueCrypt 6.0 (the original application and driver binaries of those old versions have not been modified; however, the installer used for those new packages was compiled using the source code of TrueCrypt 6.0, not TrueCrypt 5.1a).


# 5.1a
March 17, 2008

Improvements:

* Faster booting when the system partition/drive is encrypted (typically by 10%).  (Windows Vista/XP/2008/2003)
* Other minor improvements.  (Windows, Mac OS X, and Linux)

Resolved incompatibilities:

* On computers with certain hardware configurations, resuming from hibernation failed when the system partition was encrypted. Note: If you encountered this problem, the content of RAM may have been saved unencrypted to the hibernation file. You can erase such data, for example, by decrypting the system partition/drive (select System > Permanently Decrypt System Partition/Drive) and then encrypting it again.  (Windows Vista/XP/2008/2003)
    * Remark: As Microsoft does not provide any API for handling hibernation, non-Microsoft developers of disk encryption software are forced to modify undocumented components of Windows in order to allow users to encrypt hibernation files. Therefore, no disk encryption software (except for Microsoft's BitLocker) can guarantee that hibernation files will always be encrypted. At anytime, Microsoft can arbitrarily modify components of Windows (using the auto-update feature of Windows) that are not publicly documented or accessible via a public API. Any such change, or the use of an untypical or custom storage device driver, may cause any non-Microsoft disk encryption software to fail to encrypt the hibernation file. We plan to file a complaint with Microsoft (and if rejected, with the European Commission) about this issue, also due to the fact that Microsoft's disk encryption software, BitLocker, is not disadvantaged by this.
    * [Update 2008-04-02: Although we have not filed any complaint with Microsoft yet, we were contacted (on March 27) by Scott Field, a lead Architect in the Windows Client Operating System Division at Microsoft, who stated that he would like to investigate our requirements and look at possible solutions. We responded on March 31 providing details of the issues and suggested solutions.]
    * [Update 2009-05-10: Since April 2008, we have been working with Microsoft to explore possible ways to solve this issue. We have private access to a draft version of a document specifying the future API, which should allow us to solve the issue on Windows Vista and later versions of Windows. Note: We have been asked not to disclose the content of the document to any third parties, so please do not ask us to send you a copy of the document.]
    * [Update 2010-07-19: Microsoft began providing a public API for encryption of hibernation files on Windows Vista and later versions of Windows. Since version 7.0, TrueCrypt has used this API and therefore has been able to safely encrypt hibernation files under Windows Vista and later versions of Windows. Therefore, if you use Windows XP/2003 and want the hibernation file to be safely encrypted, we strongly recommend that you upgrade to Windows Vista or later and to TrueCrypt 7.0 or later.]
* Workaround for a bug in the BIOS of some Apple computers that prevented users from entering pre-boot authentication passwords and controlling the TrueCrypt Boot Loader.  (Windows Vista/XP/2008/2003)

Bug fixes:

* When the system partition/drive is decrypted under Windows, the original partition table will not be restored. Note: This issue affected users who repartitioned an encrypted system drive and then decrypted it under Windows.  (Windows Vista/XP/2008/2003)
* Other minor bug fixes.  (Windows, Mac OS X, and Linux)


# 5.1
March 10, 2008

New features:

* Support for hibernation on computers where the system partition is encrypted (previous versions of TrueCrypt prevented the system from hibernating when the system partition was encrypted).  (Windows Vista/XP/2008/2003)
* Ability to mount a partition that is within the key scope of system encryption without pre-boot authentication (for example, a partition located on the encrypted system drive of another operating system that is not running).  (Windows Vista/XP/2008/2003)
Note: This can be useful e.g. when there is a need to back up or repair an operating system encrypted by TrueCrypt (from within another operating system).
* Command line options for creating new volumes.  (Linux and Mac OS X)

Improvements:

* Increased speed of AES encryption/decryption (depending on the hardware platform, by 30-140%).  (Windows)
* Faster booting when the system partition/drive is encrypted.  (Windows Vista/XP/2008/2003)
* When the system partition/drive is encrypted, the TrueCrypt Boot Loader is now stored in a compressed form and is, therefore, smaller. If a non-cascade encryption algorithm is used (i.e., AES, Serpent, or Twofish), the TrueCrypt Boot Loader is now small enough so that a backup of the TrueCrypt Boot Loader can be (and is) stored in the first drive track. Whenever the TrueCrypt Boot Loader is damaged, its backup copy is run automatically instead.
    * As a result of this improvement, the following problem will no longer occur: Certain inappropriately designed activation software (used for activation of some third-party software) writes data to the first drive track, thus damaging the TrueCrypt Boot Loader. The affected users had to use the TrueCrypt Rescue Disk to repair the TrueCrypt Boot Loader. This will no longer be necessary after upgrading to this version of TrueCrypt (provided that the system partition/drive is encrypted using a non-cascade encryption algorithm, i.e., AES, Serpent, or Twofish).
    * Note: If your system partition/drive is currently encrypted using a non-cascade encryption algorithm (i.e., AES, Serpent, or Twofish), a backup copy of the TrueCrypt Boot Loader will be automatically stored in the first drive track when you upgrade to this version of TrueCrypt.
* The minimum memory requirements for the TrueCrypt Boot Loader (AES) have been reduced from 42 KB to 27 KB (twenty-seven kilobytes). This allows users to encrypt system partitions/drives on computers where the BIOS reserves a large amount of memory (provided that the AES encryption algorithm is used).  (Windows Vista/XP/2008/2003)
* Many other minor improvements.  (Windows, Mac OS X, and Linux)

Resolved incompatibilities:

* On some computers, when performing the system encryption pretest, Windows failed to display the log-on screen. This will no longer occur.  (Windows Vista/XP/2008/2003)

Bug fixes:

* On some systems, drive letters were not correctly assigned to newly mounted non-system volumes. This will no longer occur.  (Windows)
* Many other minor bug fixes.  (Windows, Mac OS X, and Linux)


# 5.0a
February 12, 2008

Improvements:

* The memory requirements for the TrueCrypt Boot Loader have been reduced by 18 KB (eighteen kilobytes). As a result of this improvement, the following problem will no longer occur on most of the affected computers: The memory requirements of the TrueCrypt Boot Loader 5.0 prevented users of some computers from encrypting system partitions/drives (when performing the system encryption pretest, the TrueCrypt Boot Loader displayed the following error message: Insufficient memory for encryption).

Bug fixes:

* On computers equipped with certain brands of audio cards, when performing the system encryption pretest or when the system partition/drive is encrypted, the sound card drivers failed to load. This will no longer occur.  (Windows Vista/XP/2003)
* It is possible to access mounted TrueCrypt volumes over a network.  (Windows)
* TrueCrypt Rescue Disks created by the previous version could not be booted on some computers. This will no longer occur.  (Windows Vista/XP/2003)
    * Note: If your TrueCrypt Rescue Disk created by TrueCrypt 5.0 cannot be booted on your computer, please upgrade to this version of TrueCrypt and then create a new TrueCrypt Rescue Disk (select 'System' > 'Create Rescue Disk').
* Many other minor bug fixes.  (Windows, Mac OS X, and Linux)


# 5.0
February 5, 2008

New features:

* Ability to encrypt a system partition/drive (i.e. a partition/drive where Windows is installed) with pre-boot authentication (anyone who wants to gain access and use the system, read and write files, etc., needs to enter the correct password each time before the system starts). For more information, see the chapter System Encryption.  (Windows Vista/XP/2003)
* Pipelined operations increasing read/write speed by up to 100%.  (Windows)
* Mac OS X version.
* Graphical user interface for the Linux version of TrueCrypt.
* The TrueCrypt Volume Creation Wizard now allows creation of hidden volumes within NTFS volumes.  (Windows Vista/XP/2003/2008)
* XTS mode of operation, which was designed by Phillip Rogaway in 2003 and which was recently approved as the IEEE 1619 standard for cryptographic protection of data on block-oriented storage devices. XTS is faster and more secure than LRW mode (for more information on XTS mode, see the section Modes of Operation).
    * Note: New volumes created by this version of TrueCrypt can be encrypted only in XTS mode. However, volumes created by previous versions of TrueCrypt can still be mounted using this version of TrueCrypt.
* SHA-512 hash algorithm (replacing SHA-1, which is no longer available when creating new volumes).
Note: To re-encrypt the header of an existing volume with a header key derived using HMAC-SHA-512 (PRF), select 'Volumes' > 'Set Header Key Derivation Algorithm'.

Improvements, bug fixes, and security enhancements:

* The Linux version of TrueCrypt has been redesigned so that it will no longer be affected by changes to the Linux kernel (kernel upgrades/updates).
* Many other minor improvements, bug fixes, and security enhancements.  (Windows and Linux)

If you are using an older version of TrueCrypt, it is strongly recommended that you upgrade to this version.


# 4.3a
May 3, 2007

Improvements:

* Full support for custom screen DPI settings.  (Windows, GUI)
* Other minor improvements.  (Windows and Linux)

Bug fixes:

* Fixed bug that in some cases caused the 'Safely Remove Hardware' function to fail.
* In Windows Vista, it is now possible to read data from file-hosted TrueCrypt volumes located on UDF-formatted media mounted in read-only mode.
* All Volume Creation Wizard GUI elements are now correctly displayed on systems with custom DPI settings.  (Windows, GUI)
* Other minor bug fixes.  (Windows and Linux)

Security improvements:

* Linux: When running without administrator privileges, TrueCrypt automatically attempts to elevate its access rights (if necessary) using the sudo command. The Linux version of TrueCrypt no longer supports the set-euid root mode of execution. These changes also prevent all discovered and undiscovered (if any) security issues related to the set-euid root mode of execution, including an issue affecting all previous Linux versions of TrueCrypt where a local non-administrator user could cause a denial of service or gain administrator privileges.

Miscellaneous:

* If dismount is forced on a TrueCrypt volume when TrueCrypt runs in portable mode, the TrueCrypt driver will not be unloaded when TrueCrypt exits (it will be unloaded only when the system is restarted or shut down). This prevents various problems caused by a bug in Windows (for instance, it would be impossible to start TrueCrypt again as long as there are applications using the dismounted volume).  (Windows)


# 4.3
March 19, 2007

New features:

* Full compatibility with 32-bit and 64-bit Windows Vista:
    * Support for User Account Control (UAC).
    * All .sys and .exe files of TrueCrypt are now digitally signed with the digital certificate of the TrueCrypt Foundation, which was issued by the certification authority GlobalSign.
    * When moving the mouse on a single-CPU computer while reading or writing data to a TrueCrypt volume, the mouse pointer stopped moving for a second every few seconds. This will no longer occur.  (Windows Vista issue)
    * Other minor compatibility-related changes.
* TrueCrypt volume is automatically dismounted if its host device is inadvertently removed.
    * Important: Before you physically remove a device (such as a USB flash drive) where a mounted TrueCrypt volume resides, you should always dismount the volume in TrueCrypt first, and then perform the 'Eject' operation (right-click the host device in the 'Computer' or 'My Computer' list) or use the 'Safely Remove Hardware' function (built in Windows, accessible via the taskbar notification area).
* Ability to write data to file-hosted volumes located on devices that use a sector size other than 512 bytes (e.g., new hard drives, DVD-RAM, some MP3 players and USB flash drives, etc.)
* Support for devices with a GPT partition table (GUID partitions).  (Windows Vista/2003/XP)
* After a partition is successfully encrypted, the drive letter assigned to it (if any) is automatically removed.  (Windows)
* Volume name (label) is displayed in device/partition selector.  (Windows)
* New hotkey: 'Wipe Cache'.  (Windows)
* New command line switch '/q background' for launching the TrueCrypt Background Task.  (Windows)

Improvements:

* Portions of the TrueCrypt device driver redesigned.
* Maximum allowed size of FAT32 volumes increased to 2 TB (note that NTFS volumes can be larger than 2 TB).
* Traveler Disk Setup improved.  (Windows)
* Volumes hosted on read-only media will always be mounted in read-only mode.  (Windows Vista/2003/XP)
* Improved support for big-endian platforms.
* Other minor improvements.  (Windows and Linux)

Bug fixes:

* The built-in FAT format facility now functions correctly on big-endian platforms.
* Improved handling of partitions and devices during volume creation.  (Windows)
* Improved handling of low-memory conditions.  (Windows)
* Fixed bug that rarely caused system errors when dismounting all volumes.  (Windows)
* Tray icon is recreated when Windows Explorer is restarted (e.g. after a system crash).
* Other minor bug fixes.  (Windows and Linux)

Security improvements:

* Improved security of set-euid root mode of execution. Volume can be dismounted only by the user who mounted it or by an administrator (root).  (Linux)

Miscellaneous:

* The option 'Cache passwords and keyfiles in memory' in the password prompt dialog window no longer sets the default setting (to set the default setting, select Settings > Preferences and enable or disable the option 'Cache passwords in driver memory').  (Windows)

Removed features:

* 64-bit block ciphers are being phased out. It is no longer possible to create new volumes encrypted with 64-bit-block encryption algorithms (Blowfish, CAST-128, and Triple DES). Note that it is still possible to mount such volumes.


# 4.2a
July 3, 2006

Bug fixes:

* Writing to a TrueCrypt volume under Linux no longer causes the system to stop responding under certain conditions.
* Occasional application errors no longer occur when selecting a file.  (Windows XP SP2 issue)
* Fixed bug that caused installation of the TrueCrypt driver to fail under certain configurations of 64-bit Windows.
* TrueCrypt volumes mounted in a remote session under Windows 2000 can now be accessed.
* TrueCrypt Volume Creation Wizard no longer blocks hot keys of certain applications.  (Windows)
* Other minor bug fixes.  (Windows and Linux)

Improvements:

* It will not be required to reinstall the TrueCrypt kernel module after every minor Linux kernel update.
* Other minor improvements.  (Windows and Linux)

Security improvements:

* The Linux version of TrueCrypt now uses the TrueCrypt Random Number Generator (ported from the Windows version of TrueCrypt) instead of using only the Linux built-in random number generator. (This change was necessary due to a flaw in the Linux built-in random number generator: Data from the mouse and keyboard, which are the most important sources of random data, are not read by the Linux built-in random number generator when the user has only a USB mouse/keyboard.)
    * Note: The Linux version of TrueCrypt still uses the Linux built-in random number generator. However, it is now merely one of the data sources used by the TrueCrypt random number generator.
* Interactive mount mode, which allows the user to avoid passing sensitive parameters via command line.  (Linux)
* TrueCrypt volume is unmapped if mounting it to a directory fails.  (Linux)
* When the 'Never Save History' option is enabled, TrueCrypt sets its "current directory" to the user's home directory (in portable mode, to the directory from which TrueCrypt was launched) after a container or keyfile is selected via the Windows file selector. Therefore, the Windows file selector will not "remember" the path of the last selected container or keyfile.  (Windows)


# 4.2
April 17, 2006

New features:

* TrueCrypt volumes can now be created under Linux.
* Ability to create a 'dynamic' container whose physical size (actual disk space used) grows as new data is added to it. (Dynamic containers are pre-allocated NTFS sparse files.)
* Volume passwords/keyfiles can be changed under Linux.
* Keyfiles can be created under Linux.
* Volume headers can be backed up and restored under Linux.
* Multiple keyfiles can be selected in the file selector by holding the Control (Ctrl) or Shift key.  (Windows)
* It is now possible to enable and directly set keyfiles by dragging the icon of keyfile(s) or of keyfile search path(s) to the password entry window (Windows only).
* New Linux command line option: -u, --user-mount, which can be used to set default user and group ID of the file system being mounted to the user and group ID of the parent process. Some file systems (such as FAT) do not support user permissions and, therefore, it is necessary to supply a default user and group ID to the system when mounting such file systems.
* The build.sh script can now perform automatic configuration of the Linux kernel source code, which is necessary in order to compile TrueCrypt on Linux. Note that this works only if the installed version of the kernel enables/supports it.
* TrueCrypt volume properties can be viewed under Linux.

Improvements:

* It is now possible to mount a single TrueCrypt volume from multiple operating systems at once (for example, a volume shared over network), provided that the volume is mounted as read-only under each system.  (Windows)
* Current directory is never left set to a removable device after a file (e.g., a container, keyfile, header backup) stored on it is selected via file selector in TrueCrypt. Therefore, it will be possible to 'Safely Remove' the device in such cases.  (Windows)
* Improved security of set-euid root mode of execution.  (Linux)
* Other minor improvements.

Bug fixes:

* It is now possible to dismount volumes that cannot be opened (for example, after disconnecting and reconnecting a USB flash drive formatted as NTFS containing a mounted TrueCrypt volume).
* Fixed bug that sometimes caused the mount process to fail under Linux when one or more TrueCrypt volumes were already mounted.
* Command line argument buffer is now wiped upon exit.  (Windows, command line usage)
* Other minor bug fixes.


# 4.1
November 25, 2005

New features:

* New mode of operation implemented: LRW.
    * LRW mode is more secure than CBC mode and is suitable for disk encryption. LRW mode is to become an IEEE standard for sector-based storage encryption. (For more information on LRW mode, see chapter Technical Details, section Modes of Operation in the documentation).
    * Volumes created by this version of TrueCrypt can be encrypted only in LRW mode. However, volumes created by previous versions of TrueCrypt can still be mounted by this version of TrueCrypt.
    * To prevent a recently discovered attack, which affects plausible deniability, we strongly recommend that you move data from your TrueCrypt volume to a new volume created by this version. Description of the attack: If a series of certain plaintext blocks is written to a mounted volume (i.e., if it is correctly encrypted), it is, with a very high probability, possible to distinguish the volume from random data. This affects volumes created by all versions of TrueCrypt prior to 4.1, except volumes encrypted with AES-Blowfish or AES-Blowfish-Serpent.
* The encryption algorithm test facility (Tools -> Test Vectors) now supports LRW mode.

Improvements:

* AES routines by Dr. Brian Gladman updated to the latest version.
* Improved support for using TrueCrypt under non-administrator accounts on Linux (set-euid root).
* A new instance of TrueCrypt will be created only if necessary.
* Other minor improvements.

Bug fixes:

* Password input field will be correctly wiped after each mount attempt.
* Hidden volume protection now works if set via 'Mount with Options'.
* Containers located on volumes that are accessible only in local user name space can now be mounted.
* The option /keyfile now works if specified with '/auto devices' or '/auto favorites' (command line usage).
* Volumes whose paths contain spaces can be mounted.  (Linux)
* Several localization issues fixed.
* Other minor bug fixes.


# 4.0
November 1, 2005

New features:

* TrueCrypt volumes can now be mounted on Linux. The Linux version of TrueCrypt is available at http://www.truecrypt.org/downloads
* It is now possible to write to outer volume without risking that a hidden volume within it will get damaged (overwritten):
    * When mounting an outer volume, the user can now enter two passwords: One for the outer volume, and the other for a hidden volume within it, which he/she wants to protect. In this mode, TrueCrypt does not actually mount the hidden volume. It only decrypts its header and retrieves information about the size of the hidden volume (from the decrypted header). Then, the outer volume is mounted and any attempt to save data to the area of the hidden volume will be rejected by the driver (until the outer volume is dismounted). For further details, please see the section 'Protection of Hidden Volumes Against Damage' in the documentation.
* Support for the x86-64 (64-bit) platform.
* TrueCrypt now runs on Windows XP x64 Edition (64-bit) and Windows Server 2003 x64.
* Support for big-endian hardware platforms (PowerPC, SPARC, Motorola, etc).
* Full support for keyfiles. Keyfiles provide protection against keystroke loggers and may strengthen protection against brute force attacks. Keyfile is a file whose content is combined with a password. Until correct keyfile is provided, no volume that uses the keyfile can be mounted. Any number of, and any kind of files (for example, .mp3, .jpg, .exe, .avi) may be used as TrueCrypt keyfiles. TrueCrypt never modifies the keyfile contents. Therefore, it is possible to use, for example, five files in your large mp3 collection as TrueCrypt keyfiles (and inspection of the files will not reveal that they are used as keyfiles). TrueCrypt can also generate a file with random content, which can be used as a keyfile. For more information on keyfiles, see the chapter Keyfiles in the documentation.
* Support for language packs (localizations). Language packs may be downloaded at: http://www.truecrypt.org/localizations
* Whirlpool hash algorithm added.
    * The size of the output of this hash algorithm is 512 bits. It was designed by Vincent Rijmen (co-designer of the AES encryption algorithm) and Paulo S. L. M. Barreto. The first version of Whirlpool was published in November 2000. The second version, now called Whirlpool-T, was selected for the NESSIE ("New European Schemes for Signatures, Integrity and Encryption") portfolio of cryptographic primitives (a project organized by the European Union, similar to the AES contest). TrueCrypt uses the third (final) version of Whirlpool, which was adopted by the International Organization for Standardization (ISO) and the IEC in the ISO/IEC 10118-3:2004 international standard.
* Auto-Dismount facility, which can be set to dismount a volume after no data has been written/read to/from it for specified number minutes.
    * It can also be set to dismount all mounted TrueCrypt volumes when:
        * user logs off
        * entering power saving mode
        * screen saver is launched
    * Auto-dismount can be configured and activated in the Preferences (select Settings -> Preferences)
* TrueCrypt settings are not saved to the Windows registry file. Instead, they are stored in XML files in the folder where application data are saved on the system (for example, in C:\Documents and Settings\YourUserName\Application Data\TrueCrypt). In portable mode, the configuration XML files are saved to the folder from which you run the file TrueCrypt.exe.
Note: When you install this version of TrueCrypt, all TrueCrypt settings that were stored by previous versions in the registry file will be automatically removed.
* Tray icon. Right-clicking the tray icon opens a popup menu with the most used functions. Left-clicking the tray icon opens the main TrueCrypt window and puts it into the foreground.
* Optionally, TrueCrypt can now continue running in the background after its main window is closed. This is referred to as TrueCrypt Background Task.
    * When the main TrueCrypt window is closed, the TrueCrypt Background Task handles the following tasks/functions:
        1) Hot keys
        2) Auto-dismount
        3) Notifications (e.g., when damage to hidden volume is prevented)
        4) Tray icon
    * For more information, see the chapter TrueCrypt Background Task in the documentation.
* When a mounted volume is right-clicked in the drive list (in the main TrueCrypt window), a context menu is opened. From this menu, the user can select functions such as 'Repair Filesystem' or 'Check Filesystem' (front-end to the 'chkdsk' tool).
* Containers stored on a locally mapped network drive can now be mounted.
* Container stored on a remote server can be mounted via UNC path (e.g., \\server\share\volume).
* Option to display password (typed in input field).
* 'Favorite Volumes' facility, which is useful if you often work with more than one TrueCrypt volume at a time and you need each of them to be mounted as the same drive letter every time. For more information, see the chapter 'Main Program Window', section 'Program Menu' in the documentation.
* Functions 'Backup Volume Header' and 'Restore Volume Header' added to the Tools menu. Both the standard volume header and the hidden volume header area are always backed up (copied to the backup file) even if there is no hidden volume within the volume (to preserve plausible deniability of hidden volumes).
Note: If you do not have enough free space to backup all files, we highly recommend that you at least use this facility to backup the volume header, which contains the master key (size of the backup file will be 1024 bytes). If the volume header is damaged, the volume is, in most cases, impossible to mount.
* System-wide hot keys (which can be used, for example, to dismount all TrueCrypt volumes, etc).
* Users can now set actions to perform upon logon to Windows.
    * The actions can be any of the following:
        - Start TrueCrypt
        - Mount all device-hosted TrueCrypt volumes
        - Mount favorite volumes
    * These actions can be enabled in the Preferences (select Settings -> Preferences).
* Title bar of the password prompt dialog window now displays path to volume being mounted.
* When the 'Never save history' option is enabled, TrueCrypt clears the registry entries created by the Windows file selector for TrueCrypt. Therefore, the Windows file selector will not remember the path of the last mounted container after you exit TrueCrypt. Note that even when this option is enabled, the file selector will still remember the path, but only until you exit TrueCrypt.
* 'Set Header Key Derivation Algorithm' added to the Volumes menu. It allows the user to re-encrypt a volume header with a header key derived using a different PRF function (e.g., instead of HMAC-SHA-1 you could use HMAC-Whirlpool). Note: Volume header contains master encryption key with which volume is encrypted. Therefore, data stored on the volume will not be lost after this function is used.
* Number of bytes read/written from/to a volume since it was mounted is displayed in the Volume Properties window.
* Preserving container timestamps can now disabled in the Preferences (Settings -> Preferences).
* Command line usage:
    * If '/silent' is specified, interaction with user (prompts, error messages, warnings, etc.) is suppressed.
    * If '/m timestamp' is specified, volume/keyfile timestamps are not preserved.
    * '/keyfile' can be used to specify a keyfile or a keyfile search path.
    * '/auto favorites' can be used to mount favorite volumes.
    * '/auto' is implicit if '/quit' and '/volume' are specified.
    * If '/q preferences' is specified, TrueCrypt loads/saves settings.
* Auto-Mount Devices keeps prompting for a password until a volume is successfully mounted or until cancelled. Warning is displayed after each unsuccessful mount.
* If the Shift key is down when clicking 'Auto-Mount Devices' and if there are cached passwords, then password prompt will be bypassed (mounting will be attempted only with cached passwords).
* It is now possible to run multiple instances of the TrueCrypt application simultaneously.

Improvements:

* Mounting of fragmented file-hosted volumes (containers) takes significantly less time.
* New SHA-1 routines by Brian Gladman, which are approx. three times faster than the original ones (speeds up mounting).
* Enhancements to the random number generator:
    * Hash function output is XORed into the pool (in E4M and the previous versions of TrueCrypt the values produced by a hash function replaced the original values in the pool).
    * Input to hash function will always be the entire pool.
    * Position of the pool cursor does not change when the FastPoll function is applied. This ensures that mouse coordinates are always evenly distributed in the pool (significant particularly when moving the mouse uninterruptedly).
    * Event delta/absolute time will be added modulo 2^32 to the pool at the same position as the event data. (In the previous versions, event delta times were added separately modulo 2^32 to the pool. Delta times provide only a small amount of entropy, particularly when moving the mouse uninterruptedly.)
    * For more information see the chapter Technical Details, section Random Number Generator in the documentation.
    * Important: That we made these enhancements to the random number generator does NOT mean that volumes created using previous versions of TrueCrypt are insecure.
* File-hosted volumes are pre-allocated before they are formatted. Therefore, containers are created faster and less fragmented.
* When TrueCrypt re-encrypts a volume header (for example, when changing a password), the original volume header is first overwritten 35 times with random data to prevent adversaries from using techniques such as magnetic force microscopy to recover the overwritten header.
* Traveler disk can be created when TrueCrypt is running in portable mode.
* TrueCrypt warns if automatic mounting of new volumes is disabled in Windows and informs the user how to enable this functionality.
* Other minor improvements.

Bug fixes:

* Hidden volume password can now be changed on all types of removable media (e.g., all types of USB memory sticks).
* When changing a password and an error occurs during the creation of a new volume header, the header will not be written and the error will be reported.
* FAT file system created by TrueCrypt will have the same properties as FAT file system created by Windows.
* Drive list will be updated whenever drive letter assignments change.
* If an error occurs, TrueCrypt returns exit code 1, otherwise it returns 0 (command line usage).
* Password specified on command line (/p) now also works with '/a devices' (command line usage).
* Other minor bug fixes.

Miscellaneous:

* Size of the random number generator pool increased from 256 to 320 bytes.
* The command line option '/quiet' has been renamed to '/quit'.
* The Serpent routines written in assembly have been replaced with routines written in C, so that the whole source code is more portable.


# 3.1a
February 7, 2005

Bug fixes:

* Volumes mounted as removable media can now be checked/repaired ('chkdsk.exe'), defragmented, formatted, etc.
* Volume Creation Wizard now respects default mount options set via Tools > Preferences.
* Fixed bug that caused mount/dismount to fail on some systems.
* The TrueCrypt uninstaller is now always installed during installation.
* Relative paths can be used with the /volume option (command line usage).
* Drive A: will no longer disappear from Windows Explorer (e.g., 'My Computer' list) after 'Dismount All'.
* Other minor bug fixes.

Improvements:

* When running in portable mode, the TrueCrypt driver will be unloaded when no longer needed (e.g., when the main application and/or the last instance of the Volume Creation Wizard is closed and no TrueCrypt volumes are mounted).
* Access mode (read-only or read-write) is now displayed in the volume properties dialog.
* Other minor improvements.


# 3.1
January 22, 2005

Improvements:

* Partitions/devices that are already in use by another driver (usually an anti-virus utility) can now be mounted.
* It is now possible to run multiple instances of the TrueCrypt Volume Creation Wizard.

New features:

* TrueCrypt can now run in portable mode, which means that it does not have to be installed on the operating system under which it is run. There are two ways to run TrueCrypt in portable mode:
    1) After you unpack the binary distribution archive, you can directly run 'TrueCrypt.exe'.
    2) You can use the new 'Traveler Disk Setup' facility (accessible from the 'Tools' menu) to prepare a special traveler disk and launch TrueCrypt from it. This facility can also configure a traveler disk in a way that when it is inserted, TrueCrypt is automatically started or a specified volume is mounted (note that this works only when the traveler disk is a removable medium such as a CD or DVD; Windows XP SP2 is required in case of USB memory sticks).
* Volumes can now be mounted as read-only. This can be set in the newly implemented 'Mount Options' dialog, which can be opened from the password entry dialog or by holding Control while clicking 'Mount'. (Command line usage: '/mountoption ro')
* Volumes can now be mounted as removable media (for example to prevent Windows from creating the 'Recycled' and/or 'System Volume Information' folders on the volume). This can be set in the newly implemented 'Mount Options' dialog, which can be opened from the password entry dialog or by holding Control while clicking 'Mount'. (Command line usage: '/mountoption rm')
* Default mount options can be configured in the main program preferences (Tools -> Preferences).
* 'Refresh Drive Letters' function added to the tools menu. It can be used when Windows Explorer fails to register a newly mounted volume (for example when it is not shown in the 'My Computer' list).
* Volume can now be selected by dragging its icon to the TrueCrypt program window (this also allows to avoid the Windows file selector).
* '/auto devices' auto-mounts all device/partition-hosted TrueCrypt volumes (command line usage).

Bug fixes:

* The 'Auto-Mount Devices' facility will not mount 'phantom' partitions on some removable media (e.g. USB memory sticks).
* In some cases TrueCrypt did not use all available space on some removable media (such as USB memory sticks).
    * Remark: This bug was inherited from E4M, so it applies also to volumes created by E4M.
    * Warning: Note that this means it will not be possible to mount hidden volumes (does not apply to file-hosted containers) created with TrueCrypt 3.0 or 3.0a that are located on some removable media, e.g., some USB memory sticks, (because the expected position of a hidden volume changes with the size of its host volume). If that is the case, please before upgrading to TrueCrypt 3.1, move your files to a temporary TrueCrypt volume on a non-removable medium or to a non-hidden volume on a removable medium and move the data from the old hidden volume to this temporary one. Then install TrueCrypt 3.1, create a new hidden volume and move your files from the temporary volume to it.
* Freezing caused by applications not responding to drive change messages when mounting/dismounting TrueCrypt volumes will no longer occur.
* Users are now prevented from setting a too small cluster size when creating a FAT volume (which caused various problems).
* The command line parser no longer causes TrueCrypt to crash.
* Other minor bug fixes.


# 3.0a
December 11, 2004

Bug fixes:

* Data corruption will not occur when data is written to a volume encrypted with Twofish or Serpent while another TrueCrypt volume is mounted (applies also to volumes encrypted using a cascade of ciphers, out of which one is Twofish or Serpent).
* Other minor bug fixes.


# 3.0
December 10, 2004

New features:

* Ability to create and mount a hidden TrueCrypt volume (file container or partition/device). This allows solving situations where the user is forced by an adversary to reveal the password and cannot refuse to do so (for example, due to extortion).
    * The principle is that a TrueCrypt volume is created within another TrueCrypt volume (within the free space on the volume). Even when the outer volume is mounted, it is impossible to tell whether there is a hidden volume within it or not, because free space on any TrueCrypt volume is always filled with random data when the volume is created and no part of the hidden volume can be distinguished from random data.
    * The password for the hidden volume must be different from the password for the outer volume. To the outer volume, (before creating the hidden volume within it) you should copy some sensitive-looking files that you do NOT really want to hide. These files will be there for anyone who would force you to hand over the password. You will reveal only the password for the outer volume, not for the hidden one. Files that are really sensitive will be stored on the hidden volume.
    * As it is very difficult or even impossible for an inexperienced user to set the size of the hidden volume such that the hidden volume does not overwrite any data on the outer volume, the Volume Creation Wizard automatically scans the cluster bitmap of the outer volume (before the hidden volume is created within it) and determines the maximum possible size of the hidden volume.
    * For more information, refer to http://www.truecrypt.org/hiddenvolume
* Serpent encryption algorithm (256-bit key)
* Twofish encryption algorithm (256-bit key)
* Forced/"brutal" dismount (allows dismounting a volume containing files being used by the system or an application).
* Cascades of ciphers added (e.g., AES-Twofish-Serpent, AES-Blowfish, etc.) Each of the ciphers in a cascade uses its own encryption key (the keys are mutually independent).
* Ability to mount a TrueCrypt volume that is being used by the system or an application (shared access mode).
* Ability to encrypt devices/partitions that are being used by the system or an application.
* The 'Select Device' dialog and the 'Auto-Mount Partitions' facility now support devices that do not contain any partitions.
* Encryption Algorithm Benchmark facility added to the Tools menu and to the Volume Creation Wizard.
* A warning is displayed if Caps Lock is on when creating a new volume or changing a password.
* When /l is omitted and /a is used, the first free drive letter is used (command line usage)
* New command line option: /force or /f enables forced ("brutal") dismount or mounting in shared mode (i.e., without exclusive access).
* Drive letters are now displayed in the 'Select Device' window.

Bug fixes:

* 'Blue screen' errors (system crashes) will not occur when dismounting a volume (remark: this bug also affects E4M).
* The 'Select Device' dialog will display also partitions being used by the system or an application.
* If the size of a partition/device was not a multiple of 1024 bytes, its last sector (512 bytes) was not used for TrueCrypt volume (the volume was 512 bytes shorter than the partition/device).
    * Remark: This bug was inherited from E4M, so it applies also to encrypted partitions/devices created by E4M.
* FAT volumes that are exactly 129 MB in size will not have zero size of free space (129-MB FAT volumes created by the previous versions had no free space available).
* Users without administrator privileges can now create file containers under Windows Server 2003.
* Other minor bug fixes.

Improvements:

* The timestamp of a container (the date and time that the container was last modified) will not be updated when TrueCrypt accesses the container (i.e., after dismounting, creating a hidden volume within it, or changing the password).
* The TrueCrypt Service is no longer necessary and has been removed because its functions are now handled by the TrueCrypt driver.
* When 'Never save history' is checked, Windows is prevented from saving the file names of the last accessed file containers to the 'Recent Documents' and File Selector history.
* Other minor improvements.

Miscellaneous:

* TrueCrypt has been successfully tested on the Windows "Longhorn" operating system (beta version of the future successor to Windows XP).


# 2.1a
October 1, 2004

Removed Features:

* IDEA encryption algorithm removed. This allows non-profit and profit organizations to use TrueCrypt without having to obtain a separate license for IDEA (according to the IDEA license, any use of software containing the IDEA algorithm by a non-profit or profit organization is considered as use for commercial purposes, and is subject to a license from MediaCrypt AG).
    * Important: TrueCrypt volumes encrypted using the IDEA encryption algorithm cannot be mounted using TrueCrypt 2.1a. If you have such a volume, before upgrading to TrueCrypt 2.1a, please create a new TrueCrypt volume using a cipher other than IDEA and move your files to this new volume.


# 2.1
June 21, 2004

New features:

* RIPEMD-160 hash algorithm added. The user can now select which hash algorithm TrueCrypt will use (SHA-1 or RIPEMD-160).
    * Note: RIPEMD-160, which was designed by an open academic community, represents a valuable alternative to SHA-1 designed by the NSA and NIST. In the previous versions there was a risk that the whole program would be practically useless, should a major weakness be found in SHA-1. The user-selected hash algorithm is used by the random number generator when creating new volumes, and by the header key derivation function (HMAC based on a hash function, as specified in PKCS #5 v2.0). The random number generator generates the master encryption key, salt, and the values used to create IV and 'whitening' values.
* When changing a volume password, the user can now select the HMAC hash algorithm that will be used in deriving the new volume header key.
* It is now possible to create NTFS TrueCrypt volumes and unformatted TrueCrypt volumes. This enhancement also removes the 2048 GB volume size limit. (Only FAT volumes can be created using the previous versions of TrueCrypt. Any FAT volume, encrypted or not, cannot be over 2048 GB.)
* Header key content is now displayed in the Volume Creation Wizard window (instead of salt).
* Random pool, master key, and header key contents can be prevented from being displayed in the Volume Creation Wizard window.

Bug fixes:

* When there is a mounted TrueCrypt container that is stored in another TrueCrypt container, it will be possible to dismount both of them using the 'Dismount All' function, and 'blue screen' errors will not occur upon system shutdown.
* Minor bug fixes to command line handling.

Improvements:

* Several minor improvements to the driver.


# 2.0
June 7, 2004

Bug fixes:

* Data corruption will no longer occur when a TrueCrypt partition is subjected to heavy parallel usage (usually when copying files to or from a TrueCrypt partition). This also fixes the problem with temporarily inaccessible files stored in TrueCrypt partitions.
    * Note: File-hosted volumes were not affected by this bug.
* After dismounting and remounting a volume, its file system will be correctly recognized by the operating system and it will be possible to reuse the same drive letter (Windows 2000 issue).
* The main program window will not be displayed when run in quiet mode (command line usage).
* Two password entry attempts are no longer necessary to be able to mount a volume (command line usage).
* All partitions will be visible to TrueCrypt even if one of them is inaccessible to the operating system (an inaccessible partition made all successive partitions on the hard disk unavailable to TrueCrypt).
* Relative path can be specified when mounting a file-hosted volume (command line usage).
* Incorrect passwords are reported when auto-mounting (command line usage).

New features:

* AES-256 (Rijndael) encryption algorithm.
* The command line option /dismountall was renamed to /dismount which can now be also used to dismount a single volume by specifying its drive letter.

Improvements:

* Memory pages containing TrueCrypt volume encryption keys and whitening seeds are now locked to prevent them from being swapped to the Windows page file.
* The state of the random pool will never be exported directly so the pool contents will not be leaked (remark: this bug also affects E4M).


# 1.0a
February 3, 2004

Removed features:

* TrueCrypt no longer supports Windows 98/ME.


# 1.0
February 2, 2004

Note: TrueCrypt 1.0 is based on E4M (Encryption for the Masses). Therefore, the following list contains differences between E4M 2.02a and TrueCrypt 1.0 (minor differences have been omitted).

Improvements:

* Windows XP/2000 support.
* The maximum volume size is 18,446,744,073 GB.
    * Note: File system, hardware connection standard, and operating system limitations have to be taken into account when determining maximum volume size.
* Plausible deniability. It is impossible to identify a TrueCrypt container or partition. Until decrypted, a TrueCrypt volume appears to consist of nothing more than random data (it does not contain any "signature"). Therefore, it should be impossible to prove that a file, a partition or a device is a TrueCrypt volume and/or that it has been encrypted. To achieve plausible deniability, the format of the volume and the encryption process had to be significantly changed.
* The salt is 64 bytes long now.
* The iteration count of the key derivation function increased to 2,000.
* Free space is filled with random data during volume creation, instead of filling it with zeroes. This reduces the amount of predictable plaintext and, in future, will increase the level of plausible deniability of hidden volumes.
* Up to 32 partitions per physical disk drive can be encrypted now. (Windows XP/2000)
* The minimum volume password length has been increased to 12 characters.
* The maximum volume password length has been decreased from 100 to 64 characters. This was necessary to avoid the following: When a password longer than 64 characters was passed to HMAC-SHA-1, the whole password was first hashed using SHA-1 and the resultant 160-bit value was then used instead of the original password (which complies with HMAC-SHA-1 specification), thus the password length was in fact reduced.

Bug fixes:

* Sector scrambling algorithm flaw fixed. Two or more disk sectors to be encrypted consisting of the same values (e.g. filled with zeroes), after being encrypted by E4M, start with the same 8-byte sequence of values (i.e. the first eight bytes of any of these encrypted sectors contain the same values as the first eight bytes of any other of these encrypted sectors). If this had not been fixed, the plausible deniability would not have been possible.
* TrueCrypt volumes can be dismounted (Windows XP issue).
* "Blue screen" errors no longer occur during Windows shutdown when there is one or more mounted TrueCrypt volumes.
* Drive geometry is calculated correctly now (chkdsk.exe and format.exe do not fail anymore).
* A TrueCrypt volume can be reformatted as FAT32 or NTFS using the Windows built-in format tool (Windows XP/2000 issue).
* Windows Check Disk can now be used on TrueCrypt volumes (Windows XP/2000 issue).
* Windows Disk Defragmenter can now be used on encrypted volumes (Windows XP/2000 issue).

New features:

* New IV (initialization vector) generation algorithm (see the documentation for more information).
* Every 8 bytes of each sector (after the sector is encrypted) are XORed with a random 64-bit value, which is unique to each sector and volume (sector is 512 bytes long). This makes obtaining a plaintext/ciphertext pair a bit more difficult.
* New function to clear the volume history.
* When selecting a partition/device, the sizes and file system types of available partitions/devices are displayed.  (Windows XP/2000)
* List of mounted TrueCrypt volumes now contains their sizes and encryption algorithms used.  (Windows XP/2000)
* Free volume space is reported (in 'My Computer' list etc.)
* Windows XP format facilities do not support formatting volumes larger than 32 GB as FAT32. However, with TrueCrypt Volume Creation Wizard it is now possible to create FAT32 volumes larger than 32 GB.
* New function that allows multiple TrueCrypt partitions to be mounted provided that their correct password(s) has/have been entered (this includes the cached passwords, if there are any).
* Quick format (partitions/devices only)
* Cluster size selection (when creating new volumes)
* Volume properties can now be examined (encryption algorithm, volume creation time, last password change time etc.)
* New function to dismount all mounted TrueCrypt volumes.
* New command line options to dismount all mounted TrueCrypt volumes: /d and /dismountall
* HMAC-SHA1 and CRC-32 algorithm tests are now included in the self-test facility.
* Program menu and Preferences window added.
* Custom user interface fonts supported.
* Optionally, the TrueCrypt installer can now create System Restore points (Windows XP/ME).
* Password input field is wiped after a correct volume password has been entered.
* New graphics, icons, user interface.
* New documentation.

Removed features:

* E4M and SFS volumes are no longer supported.
* DES cipher removed.
* HMAC-MD5 removed (to be replaced by HMAC-RIPEMD-160).
