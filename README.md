# TrueCrypt Archive

This is a tin foil hat area. Please put on your tin foil hat before proceeding.

Most of the files are from this collection: http://cyberside.net.ee/truecrypt/. A **BIG** thanks to 16systems and CyR for collecting!


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

I am not a cryptograph expert, so I do not know the significance the second Foundation key presents. It is evident however, that the TrueCrypt developers have difficulty deciding what they want to call themselves and what email address they use.

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
  echo "Verifying $f"
	gpg --verify "$f"
	echo
done
```
1. Save as `~/verify-sigs.sh`
2. `chmod +x ~/verify-sigs.sh`
3. `cd truecrypt-archive`
4. Just run `~/verify-sigs.sh` to verify all files.
5. Run `~/verify-sigs.sh &>verification.txt` to save the output to file.


### Delete key

```
gpg --delete-key "TrueCrypt"
```

Repeat until all keys are gone.
