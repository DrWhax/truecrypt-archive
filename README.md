Installing TrueCrypt on Mac OS X 10.10 (Yosemite) is problematic due to a faulty version check in the installer. The version check is supposed to prevent installations on versions earlier than 10.4.

This is the faulty code in question:
```javascript
function pm_install_check() {
  if(!(system.version.ProductVersion >= '10.4.0')) {
    my.result.title = 'Error';
    my.result.message = 'TrueCrypt requires Mac OS X 10.4 or later.';
    my.result.type = 'Fatal';
    return false;
  }
  return true;
}
```

There is a corrected installer here built by me (Stefan Sundin), but since it's obviously not signed by the TrueCrypt developers, so therefore I suggest that you take the steps below to make your own installer.

The easy way to just install TrueCrypt is to first extract `TrueCrypt 7.1a.mpkg` from `TrueCrypt 7.1a Mac OS X.dmg` and then run this command in the terminal:
```bash
sed -i '' 's/<installation-check .*>//' 'TrueCrypt 7.1a.mpkg/Contents/distribution.dist'
```
You can now double click `TrueCrypt 7.1a.mpkg` and install it.

If you want to create a new dmg archive with this fix, you can perform these steps:

```bash
hdiutil convert 'TrueCrypt 7.1a Mac OS X.dmg' -format UDRW -o 'TrueCrypt 7.1a Mac OS X writable.dmg'
hdiutil attach 'TrueCrypt 7.1a Mac OS X writable.dmg'
sed -i '' 's/<installation-check .*>//' '/Volumes/TrueCrypt 7.1a/TrueCrypt 7.1a.mpkg/Contents/distribution.dist'
hdiutil detach '/Volumes/TrueCrypt 7.1a'
hdiutil convert 'TrueCrypt 7.1a Mac OS X writable.dmg' -format UDBZ -o 'TrueCrypt 7.1a Mac OS X Yosemite.dmg'
rm 'TrueCrypt 7.1a Mac OS X writable.dmg'
```

This just fully disables the version check, so don't install it on Mac OS X 10.3 or earlier!
