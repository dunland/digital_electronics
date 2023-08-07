# Install LineageOS on FP3
26.05.2022

https://wiki.lineageos.org/devices/FP3/install

## 1. Read instructions
Read through the instructions at least once before actually following them, so as to avoid any problems due to any missed steps!

## 2. Make sure your computer has adb and fastboot.
Setup instructions can be found here: https://wiki.lineageos.org/adb_fastboot_guide.html

### 2.1 install and setup ADB and fastboot
https://wiki.lineageos.org/adb_fastboot_guide#on-linux

1. Download the Linux zip from Google. ✓
2. Extract it somewhere - ~/opt/adb-fastboot. ✓
3. Add the following to ~/.profile: ✓

```
if [ -d "$HOME/opt/adb-fastboot/platform-tools" ] ; then
 export PATH="$HOME/opt/adb-fastboot/platform-tools:$PATH"
fi
```

4. Log out and back in. ✓
5. You may also need to set up udev rules: see [this repository](https://github.com/M0Rf30/android-udev-rules#installation) for more info ✓

#### 2.1.1 android udev rules ✓
https://github.com/M0Rf30/android-udev-rules#installation

``` bash
# Clone this repository ✓
git clone https://github.com/M0Rf30/android-udev-rules.git
cd android-udev-rules
    
# Copy rules file ✓
sudo cp -v 51-android.rules /etc/udev/rules.d/51-android.rules
    
# OR create a sym-link to the rules file - choose this option if you'd like to
# update your udev rules using git.
sudo ln -sf "$PWD"/51-android.rules /etc/udev/rules.d/51-android.rules
    
# Change file permissions ✓
sudo chmod a+r /etc/udev/rules.d/51-android.rules
    
# Add the adbusers group if it's doesn't already exist ✓
sudo cp android-udev.conf /usr/lib/sysusers.d/
sudo systemd-sysusers

# Add your user to the adbusers group ✓
sudo gpasswd -a $(whoami) adbusers
    
# Restart UDEV ✓
sudo udevadm control --reload-rules
sudo systemctl restart systemd-udevd.service

```

Activate Developer Mode in Fairphone and turn on USB-Debugging: ✓

```
Settings > About Phone > tap build number 10 times
Settings > System > (Advanced) > Developer Options > ON
Settings > System > (Advanced) > Developer Options > USB-Debugging > ON
```

``` bash
# Restart the ADB server (back to Debian again)
adb kill-server
    
# Replug your Android device and verify that USB debugging is enabled in
# developer options 
adb devices
    
# You should now see your device... ✓
```

### 2.2 setting up adb ✓
https://wiki.lineageos.org/adb_fastboot_guide#setting-up-adb
To use adb with your device, you’ll need to enable developer options and USB debugging:

> 1.Open Settings, and select “About”.
> 2. Tap on “Build number” seven times.
> 3. Go back, and select “Developer options”.
> 4. Scroll down, and check the “Android debugging” or “USB debugging” entry under “Debugging”.
> 5. Plug your device into your computer.
> 6. On the computer, open up a terminal/command prompt and type adb devices.
> 7. A dialog should show on your device, asking you to allow usb debugging. Check “always allow”, and choose “OK”.
> 8. If the dialog is not appearing or the list of devices is empty, check if you installed adb properly. 

### 2.3 setting up fastboot

## 3. Enable USB debugging on your device. ✓

## 4. Make sure that your model is actually listed in the “Supported models” section 
[here](https://wiki.lineageos.org/devices/FP3/#supported-models) (exact match required!)  
→ FP3+ ✓

## 5. Unlocking the Bootloader

https://support.fairphone.com/hc/en-us/articles/360048646311-Manage-the-bootloader-of-your-FP3-FP3-

### 5.1 Update to latest software

https://support.fairphone.com/hc/en-us/articles/360048639271-Update-FP3-FP3-to-the-latest-software

updated to Android 11 ✓

### 5.2 Back up your data (✓)

https://support.fairphone.com/hc/en-us/articles/360048843631

### 5.3 get phone information and unlock OEM: ✓

- Find the IMEI 1 of your device ✓
- get the serial number ✓
- get unlock code from here: https://www.fairphone.com/en/bootloader-unlocking-code-for-fairphone-3/
- unlock via Settings → System → Advanced → Developer options → OEM unlocking → on: enter code

### (5.4 prepare Windows system)

is this really necessary? trying to skip this and work with linux..

## 6. Temporarily booting a custom recovery using fastboot

```
adb reboot bootloader
fastboot oem unlock
```
- on Phone: confirm
- → phone erases all data and restarts (Without developer mode activated! :/ )
    should have stopped the process? → nach neustart in frisches system ist bootloader allerdings bereits entsperrt!

```
adb reboot bootloader
fastboot flash boot lineage-18.1-20220523-recovery-FP3.img 
```
✓

## 7. Installing LineageOS from recovery

``` bash
adb reboot bootloader
# device: [apply from adb]
adb sideload lineage-18.1-20220523-nightly-FP3-signed.zip 
```
> Total xfer: 1.00x  
device:  [reboot system now]  
device keeps restarting..  
> cant' load android system. your data may be corrupt. if you continue to get this message, you may need to perform a factory data reset and erase all user data stored on this device.
→ factory reset → lineageos loading screen appears → boot successful!
