# InkBox
## About InkBox
InkBox is an open-source, Qt-based eBook reader for Kobo devices that comes as an entire [native open-source OS](https://github.com/Kobo-InkBox/rootfs) and provides support for a number of devices.
(Nickel add-on support has been dropped until further notice.)
<br>
InkBox features:
- Full integrated KoBox X11 subsystem
- ePUB, PDF, pictures and plain text display support
- Versatile configuration options for reading
- muPDF rendering engine for ePUB and PDF files
- Wi-Fi support and web browser
- Encrypted storage with EncFS
- Fast dictionary & local storage search
- Dark mode
- Strict security policy ensuring that only signed software can be run on the device (this, however, can be adapted to your needs by recompiling the [kernel](https://github.com/Kobo-InkBox/kernel))
- Full factory reset option
- Seamless update process
- VNC viewer app
- Search function
- 9 built-in fonts
- Auto-suspend
- Lock screen/passcode
- User-friendly experience
## How do I install InkBox?
You can download precompiled OS/binaries [here](http://23.163.0.39/bundles/inkbox/native/) and standard Nickel add-ons (outdated, unmaintained) are available [here](http://23.163.0.39/bundles/inkbox/nickel/), although support for them has been stopped until further notice. Huge thanks to [@fermino](https://github.com/fermino) for providing free hosting.
<br>

On Windows, use [balenaEtcher](https://www.balena.io/etcher/) to flash the InkBox image file to the Kobo's SD card.

On Linux and MacOS, [balenaEtcher](https://www.balena.io/etcher/) is the easiest option for command-line-reluctant users.
Alternatively, you can also open a terminal and check the device node of the Kobo's SD card with `fdisk -l`. Then `dd` the image to the SD card like this:

```
xzcat inkbox.xz | dd of=/dev/mmcblk0
```

## How do I upgrade InkBox?
To upgrade InkBox, go to http://23.163.0.39/bundles/inkbox/native/update/ and extract the files for your Kobo model onto the `.inkbox` folder in the InkBox USB device (If you don't see the folder, enable hidden files and folders on [Windows](https://support.microsoft.com/en-us/windows/show-hidden-files-0320fe58-0117-fd59-6851-9b7f9840fdb2), [MacOS](https://www.ionos.ca/digitalguide/server/configuration/showing-hidden-files-on-a-mac/), or [Linux](https://phoenixnap.com/kb/show-hidden-files-linux) (this depends on which file browser you use).)

**Note**: Prior to version 1.6, InkBox had to be upgraded one version at a time. If your device's factory image ships with version 1.5, you need to closely follow the upgrade instructions [here](http://23.163.0.39/bundles/inkbox/native/update/1.6/HOWTO-Update).

If you install the Nickel add-on, unpack the 'base' archive in the root of the onboard storage, not in any subfolder inside it.
## I want to learn more about this!
I suggest you visit the [wiki](http://inkbox.ddns.net:40/wiki). The [General information](http://inkbox.ddns.net:40/wiki/index.php?title=General_information) page is a pretty good place to start. Feel free to contribute if you think you have something valuable to add.
## How can I contribute?
If you like this project and want to improve it in some way, feel free to fork this repository or [one of the subprojects this organization hosts](https://github.com/Kobo-InkBox), then make a [pull request](https://github.com/Kobo-InkBox/inkbox/pulls). I'll be happy to review it when I have time.
<br><br>
On the other hand, if you don't have the appropriate coding skills or just want to help in some way, feel free to make a donation at my [PayPal account](https://paypal.me/NicolasMailloux/) or on [LiberaPay](https://liberapay.com/tux-linux/). I'm a student and motivation has been the only thing that has helped me maintain this project for the last months. Developing an entire operating system on my own was not an easy task. I have time, but I like to spend it wisely.
