# TrueCrypt Archive

This is a tin foil hat area. Please put on your tin foil hat before proceeding.

Most of the files are from this collection: http://cyberside.net.ee/truecrypt/. A **BIG** thanks to 16systems and CyR for collecting!


## Missing files

At least these files are missing. If you have any of them, or know of other files that have been released by the TrueCrypt developers, please contact me! One idea is that they may be found on magazine CDs.

Most wanted:

* `truecrypt-1.0a-source-code.zip`
* `truecrypt-3.0.zip`
* `truecrypt-3.0.zip.sig`
* `truecrypt-3.0-source-code.zip`
* `truecrypt-3.0-source-code.zip.sig`
* `truecrypt-4.3.zip.sig`
* `truecrypt-4.3-source-code.zip`
* `truecrypt-4.3-source-code.zip.sig`
* `truecrypt-4.3-source-code.tar.gz.sig`
* `TrueCrypt Setup 4.3a.exe.sig` (first re-release, see [License History](https://github.com/stefansundin/truecrypt-archive/wiki/License-History))
* `TrueCrypt Setup 4.3a-2.exe` (second re-release, see [License History](https://github.com/stefansundin/truecrypt-archive/wiki/License-History), released as `TrueCrypt Setup 4.3a.exe`)

Not as important:

* `truecrypt-4.3a-ubuntu-6.06-x86.tar.gz`
* `truecrypt-4.3a-ubuntu-6.06-x86.tar.gz.sig`
* `truecrypt-4.3a-ubuntu-7.04-x64.tar.gz`
* `truecrypt-4.3a-ubuntu-7.04-x64.tar.gz.sig`
* `truecrypt-4.3a-ubuntu-7.04-x86.tar.gz`
* `truecrypt-4.3a-ubuntu-7.04-x86.tar.gz.sig`
* `truecrypt-4.3a-opensuse-10.2-x86.tar.gz.sig`
* `TrueCrypt 5.0 Source.tar.gz.sig`
* `TrueCrypt 5.0 Leopard Intel.dmg`
* `TrueCrypt 5.0 Leopard Intel.dmg.sig`
* `TrueCrypt 5.0 Leopard PowerPC.dmg`
* `TrueCrypt 5.0 Leopard PowerPC.dmg.sig`
* `TrueCrypt 5.0 Tiger Intel.dmg`
* `TrueCrypt 5.0 Tiger Intel.dmg.sig`
* `TrueCrypt 5.0 Tiger PowerPC.dmg`
* `TrueCrypt 5.0 Tiger PowerPC.dmg.sig`
* `truecrypt-5.0-opensuse-x86.tar.gz`
* `truecrypt-5.0-opensuse-x86.tar.gz.sig`
* `truecrypt-5.0-ubuntu-x86.tar.gz.sig`
* `TrueCrypt 5.0a Leopard Intel.dmg.sig`
* `TrueCrypt 5.0a Leopard PowerPC.dmg`
* `TrueCrypt 5.0a Leopard PowerPC.dmg.sig`
* `TrueCrypt 5.0a Tiger Intel.dmg`
* `TrueCrypt 5.0a Tiger Intel.dmg.sig`
* `TrueCrypt 5.0a Tiger PowerPC.dmg`
* `TrueCrypt 5.0a Tiger PowerPC.dmg.sig`
* `TrueCrypt 5.1 Source.tar.gz`
* `TrueCrypt 5.1 Source.tar.gz.sig`
* `truecrypt-5.1-ubuntu-x86.tar.gz`
* `truecrypt-5.1-ubuntu-x86.tar.gz.sig`
* `TrueCrypt 6.3 Mac OS X.dmg.sig`


## Past versions

The TrueCrypt website offers downloads of _past versions_. Currently they offer versions 7.0a, 6.3a and 5.1a for Windows, while only 7.0a and 6.3a for Mac OS X and Linux. I found this interesting note in the version history:

> Note: TrueCrypt 4.3a and 5.1a have been repackaged to contain the latest version of the TrueCrypt License introduced with TrueCrypt 6.0 (the original application and driver binaries of those old versions have not been modified; however, the installer used for those new packages was compiled using the source code of TrueCrypt 6.0, not TrueCrypt 5.1a).

This means that there are two different 4.3a and 5.1a, with different licenses. Presumably 4.3a was offered as a _past versions_ download in the past.

See [License History](https://github.com/stefansundin/truecrypt-archive/wiki/License-History) for more information.


## Verifying the integrity

There are three public keys from the TrueCrypt developers.

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
gpg --delete-key "TrueCrypt"
```

Repeat until all keys are gone.
