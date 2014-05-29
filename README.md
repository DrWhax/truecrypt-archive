# TrueCrypt Archive

This is a tin foil hat area. Please put on your tin foil hat before proceeding.

Most of the files are from this collection: http://cyberside.net.ee/truecrypt/. A **BIG** thanks to 16systems and CyR for collecting!


## Missing files

At least these files are missing, and there are most likely a lot more files that we don't know about. If you have any of them, or know of other files that have been released by the TrueCrypt developers, please contact me! One idea is that they may be found on magazine CDs.

Most wanted:

* `truecrypt-3.0.zip`
* `truecrypt-3.0-source-code.zip`
* `truecrypt-4.3-source-code.zip.sig`
* `TrueCrypt 5.0 Source.tar.gz.sig`

Not as important:

* `truecrypt-4.2a-fedora-core-4-x86.tar.gz.sig`
* `truecrypt-4.2a-fedora-core-5-x86.tar.gz.sig`
* `truecrypt-4.2a-ubuntu-5.10-x86.tar.gz`
* `truecrypt-4.2a-ubuntu-5.10-x86.tar.gz.sig`
* `truecrypt-4.3a-ubuntu-6.06-x86.tar.gz`
* `truecrypt-4.3a-ubuntu-6.06-x86.tar.gz.sig`
* `truecrypt-4.3a-ubuntu-7.04-x64.tar.gz`
* `truecrypt-4.3a-ubuntu-7.04-x64.tar.gz.sig`
* `truecrypt-4.3a-ubuntu-7.04-x86.tar.gz`
* `truecrypt-4.3a-ubuntu-7.04-x86.tar.gz.sig`
* `truecrypt-4.3a-opensuse-10.2-x86.tar.gz.sig`
* `TrueCrypt 5.0 Leopard Intel.dmg`
* `TrueCrypt 5.0 Leopard Intel.dmg.sig`
* `TrueCrypt 5.0 Leopard PowerPC.dmg`
* `TrueCrypt 5.0 Leopard PowerPC.dmg.sig`
* `TrueCrypt 5.0 Tiger Intel.dmg`
* `TrueCrypt 5.0 Tiger Intel.dmg.sig`
* `TrueCrypt 5.0 Tiger PowerPC.dmg`
* `TrueCrypt 5.0 Tiger PowerPC.dmg.sig`
* `truecrypt-5.0-opensuse-x86.tar.gz.sig`
* `truecrypt-5.0-ubuntu-x86.tar.gz.sig`
* `TrueCrypt 5.0a Leopard Intel.dmg.sig`
* `TrueCrypt 5.0a Leopard PowerPC.dmg`
* `TrueCrypt 5.0a Leopard PowerPC.dmg.sig`
* `TrueCrypt 5.0a Tiger Intel.dmg`
* `TrueCrypt 5.0a Tiger Intel.dmg.sig`
* `TrueCrypt 5.0a Tiger PowerPC.dmg`
* `TrueCrypt 5.0a Tiger PowerPC.dmg.sig`
* `truecrypt-5.1-ubuntu-x86.tar.gz.sig`


## TrueCrypt 7.2

Version 7.2, released 2014-05-28, appears to be the last version of TrueCrypt. The website, forums and all other resources disappeared and was replaced with a scaled-down SourceForge website. The new version seems to be basically 7.1a, but without the ability to create new volumes.

The warnings that accompany version 7.2 claim that TrueCrypt is not secure, and that people should migrate to BitLocker and other solutions.

The authors write that the development was stopped after Microsoft terminated support for Windows XP. This is an interesting claim since the list of planned future features from the old website included support for Windows 8 and UEFI. This is the list before the website was shut down:
```
- Full support for Windows 8
- Ability to encrypt Windows system partitions/drives on UEFI-based computers
- Command line options for volume creation (already implemented in Linux and Mac OS X versions)
- "Raw" CD/DVD volumes
```

This project will keep going, so please help us collect the remaining files. Thank you!


## Past versions

The TrueCrypt website used to offer downloads of _past versions_. This is no longer available since 2014-05-28. They used to offer versions 7.0a, 6.3a and 5.1a for Windows, while only 7.0a and 6.3a for Mac OS X and Linux. I found this interesting note in the version history:

> Note: TrueCrypt 4.3a and 5.1a have been repackaged to contain the latest version of the TrueCrypt License introduced with TrueCrypt 6.0 (the original application and driver binaries of those old versions have not been modified; however, the installer used for those new packages was compiled using the source code of TrueCrypt 6.0, not TrueCrypt 5.1a).

See [License History](doc/License-History.md) for more information.


## Verifying the integrity

There are four signature files that the TrueCrypt developers have released.

1. `TrueCrypt_Team_PGP_public_key.asc`
    * This is the first key, used only for version 1.0 and 1.0a.
    * pgpdump: `Public key creation time - Mon Jan 26 21:02:14 CET 2004`
2. `TrueCrypt_Foundation_PGP_public_key.asc`
    * This key has been used for version 2.0 and later.
    * pgpdump: `Public key creation time - Sun Jun  6 11:13:17 CEST 2004`
3. `TrueCrypt-Foundation-Public-Key.asc`
    * This is the key that is currently available for download at truecrypt.org. As an exercise, make sure that the key in this repo is authentic.
    * This key has the same fingerprint as the previous key, but pgpdump reveals that it is composed differently.
    * Both Foundation keys can verify the same files.
    * Same creation time as the previous key, but the date `Tue Mar 20 22:52:24 CET 2007` can be seen in pgpdump output. Presumably this is when this file was released (the day after 4.3 was released).
4. `TrueCrypt-key.asc` 
    * This file was released with version 7.2. It is actually identical with `TrueCrypt-Foundation-Public-Key.asc`.
    * It was most likely renamed to avoid attention to the _Foundation_, so that people would focus on message that was released along with 7.2.

I am not a cryptography expert, so I do not know the significance the second Foundation key presents. It is evident however, that the TrueCrypt developers have difficulty deciding what they want to call themselves and what email address they use.

1. `TrueCrypt Team <mail@truecrypt.org>`
2. `TrueCrypt Foundation <info@truecrypt-foundation.org>`
3. `TrueCrypt Foundation <contact@truecrypt.org>`

This is all very interesting, but let's get on to verifying the signature files.


### Importing keys

```
gpg --import TrueCrypt_Team_PGP_public_key.asc TrueCrypt-Foundation-Public-Key.asc
```

You can import `TrueCrypt_Foundation_PGP_public_key.asc` too, if you'd like.


### Trust the keys

```
gpg --edit-key "TrueCrypt Team" trust quit
gpg --edit-key "TrueCrypt Foundation" trust quit
```

Select option 5, _I trust ultimately_.


### Verify the files

I made a bash script, like so:

```
#!/bin/bash
for f in *.sig
do
    echo "Verifying '$f'"
    gpg --verify "$f"
    echo
done
```
1. Save as `~/verify-sigs.sh`
2. `chmod +x ~/verify-sigs.sh`
3. `cd truecrypt-archive`
4. Just run `~/verify-sigs.sh` to verify all files.
5. Run `~/verify-sigs.sh &>verification.txt` to save the output to file.

If you don't want a file, you can just run this one-liner:
```
for f in *.sig; do echo "Verifying '$f'"; gpg --verify "$f"; echo; done
```

#### Windows

In Windows you can use this bat script:
```
@echo off
for %%f in (*.sig) do (
    echo Verifying '%%~nf'
    gpg --verify "%%f"
    echo.
)
```
Save it as `verify-sigs.bat` and put it in `PATH`, e.g. the Windows directory.

It can also be useful to associate .sig files with this bat script:
```
@echo off
echo Verifying '%~n1'
echo.
gpg --verify %1
echo.
pause
```
Save it as `verify-sig.bat` and associate .sig files with it. Then simply double-click a .sig file to verify it.


### Delete keys

```
gpg --delete-key TrueCrypt
```

Repeat until all keys are gone.
