I found [an interview with ennead](http://www.wolfmanzbytes.com/windows/70-truecrypt-encryption.html) (one of the TrueCrypt developers) while I was googling around. It's very interesting and I haven't been able to find anything like it.

---

## TrueCrypt Encryption

Saturday, 10 September 2005 23:22 | Written by WolfManz611

This program i picked up a few days ago off of SourceForge .

Some encryption programs i have tried out have been single file encryption of they could do a folder of files. TrueCrypt does that as well as it can do entire hard drives. Along with being able to encrypt drives on the fly it can also basicly emulate a drive in a single file. So for example i may only have a few text files or the like that need encrypting and to encrypt a small section of my drive isn't worth doing. However with TrueCrypt not only can i encrypt my hard drive i can also setup what is known as a container.

This container or file however you want to look at it gets mounted when you take the file and drop it on the TrueCrypt icon. When i say mounted i mean mounted as in a virtual drive. You will see the new drive/file mounted in your explorer. You can do all the same things with this virtual drive that you can do with a real drive except with this one when you close down TrueCrypt.exe file the drive is unmounted and is no longer there to be accessed. This file over time under heavy use will need to be defragmented just as you would a normal drive. 

Once you have a encrypted drive setup you can also put hidden encrypted files into it. These encrypted files have a different password then the main encrypted file they are sitting in. This allows you to setup up a dummy encrypted drive that is made to look good with fake secrete files while you have the real file in the same encrypted drive but is unseen and does not show up.

The program it self is really easy to use , in fact i doubt you could get something easier to use then this program. This program does not have a password recovery option witch means if you loose your password to a encrypted drive or container your shit out of luck. For this very reason make sure you make a password you will not forget. It should also go without saying that with any encryption program its only as strong as your password. So if you have a easy to to guess password or one thats not very random it wont take long for that to be cracked if your files end up in the wrong hands.

Also unlike some programs that are based of a single encryption routine this program has several that you can pick from. If you look in the documentation for this program you will see a run down of the various encryption routines. I choose the default one..

Note: With any encryption program you use you have to make sure your machine is clean prior to you using the software. If you have a trojan on your machine or a key logger then this program or any encryption program will be of no use to you. Same goes for a encryption programs using keyfiles if you have a trojan on your machine you can bet the attacker will have full access to your hard drive and your system. 

If any of you users out there do know of a encryption program that takes keyloggers and trojans into account please let me know i would like to see the software. I think the trojan / key logger is a serious problem that needs to be addressed in any encryption program. Its to easy now a days to have virus scanners and the like and yet still be infected with some unknown trojan do to the latest hole in a IE. 

Overall though this program is a nice program and really easy to use below is a interview i had with one of the lead developers of the program enjoy..

---

**WolfManz611:** Whats your position in the TrueCrypt project?

**Ennead:** I'm 29 and my main project roles are the following: Project Administrator, Developer, and Designer. I am also responsible for the documentation and the website.

**WolfManz611:** How much time have you spent on the TrueCrypt project getting it to where it is today and how many developers are working on it?

**Ennead:** There are currently two main developers (who are also the project administrators) working on TrueCrypt. As for how much time we have spent on the project, I think quite a lot. We usually take a short break after a major release (unless there are major issues that need to be resolved immediately) and then begin working on a new version. A considerable portion of our time is devoted to the work on the project. 

**WolfManz611:** What types of users is a program like this aimed at?

**Ennead:** That's a good question. We're constantly trying to balance things out. On one side you have inexperienced users who require maximum ease of use, simplicity and nice user interface, and on the other side you have "power" users who require sometimes very obscure features, which can scare or confuse inexperienced users. What we're trying to do is find some compromise to satisfy both sides. 

Furthermore, there are single-user (home) vs. multi-user (corporations) issues. For instance, corporations ask us to implement "back-door" access capability in case an employee forgets his or her passphrase, etc. In this respect, our software is aimed more at single users. Despite this, from the emails we receive we know that there are many corporations and government organizations that use TrueCrypt.

**WolfManz611:** Does this program take any kind of counter measures to foil things like keyboard loggers looking for passwords?

**Ennead:** TrueCrypt currently does not offer any active protection against malevolent software. We believe that is the role of anti-virus software. As for keyloggers, the best protection against them will be to use keyfiles. We have already implemented support for keyfiles and the new version should be released soon.

**WolfManz611:** To give the average user a idea of how good the encryption routines are the program uses under the default encryption and assuming the user had used a 20 char mixed password how long would it take to break the encryption with a room full of high end computers?

**Ennead:** I won't tell you exact figures but I can give you an estimate. 20 randomly chosen ASCII characters are roughly equal to a 128-bit key. Let's assume that a single high-end computer is capable of testing 100 TrueCrypt passwords per second. If we link 10,000 such computers together, we will be able to test 1,000,000 passwords per second. Hence, it would take 5395141535403007094485264 years on average to find the correct password.

Note that the above figure is only valid if the password is truly random. If it consisted of words found in a dictionary, pet names, dates of birth, phone numbers, and so forth, it might take less time to find the correct password (brute force attack can be optimized). It is very important to choose a good password.

**WolfManz611:** I noticed you can save passwords to driver memory why save passwords their as opposed to normal memory?

**Ennead:** One of the reasons for that was to allow passwords to be cached even when the TrueCrypt application exits. The driver is independent of the TrueCrypt.exe application.

**WolfManz611:** Is the password in the driver memory retained after a computer restart or power off?

**Ennead:** No, the TrueCrypt driver is shut down when you restart Windows.

**WolfManz611:** Do you think more programs today such as say e-mail clients and the like should use some sort of encryption on their settings and any messages they may keep around?

**Ennead:** Yes, of course. More and more people are beginning to realize that their privacy is something they should safeguard. If your favorite e-mail client does not support encryption, it should at least allow you to configure it in a way that all sensitive files it works with are stored on a TrueCrypt volume (i.e. encrypted on-the-fly).

**WolfManz611:** What are the minimum requirements for your program to work properly?

**Ennead:** I don't think that TrueCrypt is very demanding in this respect. It requires only a few megabytes of free memory and about one megabyte of free disk space.

**WolfManz611:** Do you think do to the way people are getting hacked now a days that the majority of people should employ a program like TrueCrypt to keep their information out of hackers hands?

**Ennead:** Well, if the operating system is infected, then TrueCrypt will not prevent hackers from gaining access to files on a TrueCrypt volume that you mount under the OS. Using some decent anti-virus software is definitely recommended. 

**WolfManz611:** Are you guys working on a Linux version and if so hows that coming along? will it be the same as in features as the windows one or better?

**Ennead:** Yes, while I am currently working on the Windows version, Syncon is finishing the work on a Linux version. It has been in alpha testing for several weeks and it appears to be very stable.

Initially, the two versions will not be equal. For instance, there will be no GUI for the Linux version. However, in future, both versions should be pretty much equal.

**WolfManz611:** How popular is this program and how many users as a guess do you think use the program or have downloaded it?

**Ennead:** According to SourceForge.net statistics and our server logs, about a quarter million people have downloaded TrueCrypt 3.1a so far. There are also many entities, such as the Chip magazine, that host our files on their own servers, so it is actually impossible to estimate how many people have downloaded TrueCrypt.

**WolfManz611:** What programing language is the program in?

**Ennead:** The entire source code is in C except the Serpent routines, which are in assembly. As our aim is to make the source code cross-platform, we plan to replace the assembly code with code written in C entirely. 

**WolfManz611:** Do you have any big features you want to implement in the future if so what are they?

**Ennead:** Yes, we do. But it wouldn't be a surprise if we told you!

**WolfManz611:** How problematic is the windows swap file for a program like this? Does the windows swap file only come into play when witting a file back to the encrypted container or drive or does the swap file compromise files even when reading files from a container or encrypted drive?

**Ennead:** Whenever you open a file stored on a TrueCrypt volume in a program (for example, in a text editor), portion of the file is decrypted in RAM and passed to the program who requested it. TrueCrypt uses the non-paged pool to store cached passwords, encryption keys, IVs and other sensitive volume data, so this data cannot be leaked to paging files. However, TrueCrypt cannot prevent the contents of sensitive files that are opened in RAM from being saved unencrypted to a paging file. Therefore, we strongly recommend that users disable the paging file feature, at least for each session during which they work with sensitive data. 

**WolfManz611:** Do you plan on doing other projects that involve encryption such as a e-mail plug in that are easy to use?

**Ennead:** As regards encryption software, we will probably stay with the on-the-fly disk encryption model, which we consider the most effective.

**WolfManz611:** How does source forge do for your program? does it give you lots of downloads and exposure?

**Ennead:** Well, I estimate that about 5% of TrueCrypt users might have discovered TrueCrypt via SourceForge.net. Overall, SourceForge services are great, but there are things that could be improved. For instance, the security of their web services and performance of their MySQL servers, which were among the reasons why we decided to move the site and forums to our own dedicated server.

---

That was a good interview , i would like to thank Ennead for his time to do this interview. Now if you want to download the latest version of TrueCrypt head on over to their web site and grab a copy. The program by the way is open source and is free.

WolfManz611..