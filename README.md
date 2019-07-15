# Ubuntu Dragon Kernel 5.3.1-dragon

**This is v5.3.1-dragon stable release**


**Dragon Kernel semantic versioning and give your version numbers meaning:**

Dragon Kernel no longer uses the stable version of the Linux kernel, all builds are based only on the mainline version.

```
major.minor[.maintenance-build]  (Example: 5.3.1-dragon)

major.minor is mainline kernel version,  maintenance build is Dragon kernel version.
```

**This resource is not intended for users who do not understand the difference between Linux distributions, in particular, Cosmic and Disco, and who do not know how to install the system from the Live USB installation on their computer with an additional kernel from PPA, especially those who do not understand how the Linux system and kernel works.**

**Please such people pass by and do not waste either my and your time on what you do not need.**

---

![AVL Kernel](https://dragon-kernel.pro/images/g.jpeg)

[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg)](https://github.com/RichardLitt/standard-readme)
[![Donate with Bitcoin](https://en.cryptobadges.io/badge/micro/1KvWrbLhuzk8DSb2Yq2948bMj3uQvVTQCW)](https://en.cryptobadges.io/donate/1KvWrbLhuzk8DSb2Yq2948bMj3uQvVTQCW)
[![Donate with Ethereum](https://en.cryptobadges.io/badge/micro/0xE42f2d4D4aF888Ac784ED26a68E828475A4712Cb)](https://en.cryptobadges.io/donate/0xE42f2d4D4aF888Ac784ED26a68E828475A4712Cb)

---

 Dragon is a distro kernel replacement built using the best configuration and kernel sources for desktop, multimedia, and gaming workloads.

## Introduction

 By default, Ubuntu systems run with the Ubuntu kernels provided by the Ubuntu repositories.
However it is handy to be able to test with modified upstream kernels to help locate problems
in the Ubuntu kernel patches, or to confirm that upstream has fixed a specific issue. To this end
i now offer select upstream kernel builds. These kernels are made from modified kernel source but
using the Ubuntu kernel configuration files. These are then packaged as Ubuntu .deb files for simple installation.

 Ubuntu’s stock Linux kernel is fine for most users, but because Ubuntu follows a six-month release cycle,
their kernels are always a release or three behind upstream. This can cause problems for users attempting
to install Ubuntu on brand new hardware, or worse, force ultra-nerds to wait to play with the
latest and greatest new kernel features!

 All workstations that I use today — a **Dell Precision M6600 (Sandy Bridge)**, **Dell Inspiron N5010 (Westmere)**.

- boots Dragon kernels instead. Dragon’s kernels mirror the upstream development cycle, and as a bonus, include a number of
exciting optimizations and patches to improve performance and expose up-and-coming features.

 One recent patch pulls in the ability to utilize architecture-specific GCC optimizations when compiling a kernel.
In general, compiler optimizations may not have much effect on runtime performance, however with
something as foundational as a kernel, tiny improvements might add up quickly.

 The Linux kernel is a very large piece of software. It contains drivers and special handling for all sorts
of disparate hardware combinations. By and large, this is a good thing; it allows all sorts of different
machines to boot a Linux kernel without undo fiddling. Pre-compiled kernels — like Ubuntu stock or Dragon — keep
most of this code around because they cannot anticipate the kind of hardware their users might be using.

**Main Features:**

 - Experience a whole new way to interact with your PC like never before.
 - Full kernel adaptation to version Ubuntu Disco.
 - Full kernel adaptation to build GCC 9.1+
 - Optimized to take full advantage of high-performance.
 - Supports all recent 64-bit versions of Debian and Ubuntu-based systems.
 - Tuned CPU for Intel i5/i7/i9/Atom and AMD platform.
 - BMQ CPU Scheduler & Multi-Queue I/O Block Layer w/ BFQ for smoothness and responsiveness.
 - Caching, Virtual Memory Manager and CPU Governor Improvements.
 - General-purpose Multitasking Kernel.
 - Built on the latest GCC 9.1+
 - DRM Optimized Performance.
 - Intel CPUFreq (P-State passive mode).
 - AUFS, APFS, exFAT, BFQ and Ureadahead support available.


**New features Dragon kernel distribution with custom settings:**

**AVL Interactive Tuning**: Tunes the kernel for responsiveness at the cost of throughput and power usage.

**BMQ CPU Scheduler**: Fair process scheduler for gaming, multimedia, and real-time loads.

**Preemptible tree-based hierarchical RCU**: RCU implementation for real-time systems.

**Hard Kernel Preemption**: Most aggressive kernel preemption before requiring real-time patches. Guarantees responsive system under high intensity mixed workload scenarios.

**Budget Fair Queue**: Proper disk scheduler optimized for desktop usage, high throughput / low latency.

**TCP BBR Congestion Control**: Fast congestion control, maximizes throughput, guaranteeing higher speeds than Cubic.

**Smaller TX Net Queues**: Reduced queue size on network devices to combat buffer bloat.

**Ubuntu ureadahead Support**: Compatible with Ubuntu’s readahead.

**Binary Compatibility Cross Distro**: Compatible with Debian Testing and newer as well as latest Ubuntu. Worst case, a package rebuild will be required on older distributions.

**Distribution Kernel Drop-in Replacement**: Proper distribution style configuration supporting broadest selection of hardware. Paravirtualization options enabled to reduce overhead under virtualization.

**Minimal Debugging**: Minimum number of debug options enabled to increase kernel throughput.


---
 
 [![**Meltdown-Spectre**](https://dragon-kernel.pro/images/ibrs3.jpeg)]()
 
## Full security support:
 
 - Indirect Branch Restricted Speculation (IBRS)
 - Indirect Branch Prediction Barrier (IBPB)

 - Spectre Variant 1, bounds check bypass
 - Spectre Variant 2, branch target injection
 - Variant 3, Meltdown, rogue data cache load
 - Variant 3a, rogue system register read
 - Variant 4, speculative store bypass
 - Foreshadow (SGX), L1 terminal fault
 - Foreshadow-NG (OS), L1 terminal fault
 - Foreshadow-NG (VMM), L1 terminal fault
 - Fallout, microarchitectural store buffer data sampling (MSBDS)
 - ZombieLoad, microarchitectural fill buffer data sampling (MFBDS)
 - RIDL, microarchitectural load port data sampling (MLPDS)
 - RIDL, microarchitectural data sampling uncacheable memory (MDSUM)

---

[![**BMQ**](https://dragon-kernel.pro/images/bmq.jpeg)]()

## BMQ CPU Scheduler
 
 - BMQ project from Alfred Chen ([BMQ](http://cchalpha.blogspot.com)).


**Its features:**

BMQ(BitMap Queue) Scheduler is a band new CPU scheduler development from PDS and inspired by the scheduler in zircon project(google).

For more design detail of BMQ, pls reference to Documentation/scheduler/sched-BMQ.txt in the repository.

Here is the list of major user visible difference of BMQ with PDS.

1. *NOT* support SCHED_ISO, pls use "nice --20" instead.
2. *NO* rr_interval, but a compile time kernel config CONFIG_SCHED_TIMESLICE(default 4ms) is available for similar usage. Yet, it is *strongly NOT recommended* to change it.
3. "yield_type" is still supported, but only value 0, 1(default) are available, 2 is still accept from interface, but it's same as value 1. (Will be changed when yield implementation is finalized)
4. BATCH and IDLE tasks are treated as the same policy. They compete CPU with NORMAL policy tasks, but they just don't boost. To control the priority of NORMAL/BATCH/IDLE tasks, simply use nice level.
5. BMQ will auto adjust(boost/deboost) task priority within +/- MAX_PRIORITY_ADJ(default 4) ranges. For example, from top/htop and other cpu monitors program, task of nice level 0 may be saw running as nice in cpu time accounting.

BMQ has been running smoothly on 3 machines(NUC Desktop, NAS file server and 7*24 raspberry pi) for ~1 month. Suspend/Resume on NUC Desktop and NAS file server are tested. BMQ shows promising in Desktop activity and kernel compilation sanity comparing to PDS.

BMQ is simple in design compare to PDS and result in ~20KB less in patch size and ~4KB in compressed kernel binary size.

---

[![**AUFS**](https://dragon-kernel.pro/images/aufs.jpeg)]()
 
## Advanced multi layered Unification File System ([AUFS](https://en.wikipedia.org/wiki/Aufs))
 
 AUFS (short for advanced multi-layered unification filesystem) implements a union mount for Linux file systems.
The name originally stood for AnotherUnionFS until version 2.
 
 - The module AUFS is integrated into the kernel.

---

[![**APFS**](https://dragon-kernel.pro/images/apfs.jpeg)]()
 
## Apple File System ([APFS](https://en.wikipedia.org/wiki/Apple_File_System))
 
 Apple File System (APFS) is a proprietary file system for macOS High Sierra and later version.

 - The module APFS (read only) is integrated into the kernel.

---

[![**exFAT**](https://dragon-kernel.pro/images/exfat_a.jpeg)](https://en.wikipedia.org/wiki/ExFAT)
 

## exFAT - Extended File Allocation Table ([exFAT](https://en.wikipedia.org/wiki/ExFAT))

 **Linux read/write kernel driver for the exFAT(FAT64), FAT12, FAT16 and vfat (FAT32) file systems** 

 exFAT can be used where NTFS is not a feasible solution (due to data-structure overhead), but a greater file-size limit than the standard FAT32 file system (i.e. 4 GiB) is required.
 exFAT has been adopted by the SD Card Association as the default file system for SDXC cards larger than 32 GiB.
 
 - The module ([exFAT v1.2.24-dragon](https://github.com/AndyLavr/exfat-nofuse.git)) is integrated into the kernel.

 - Full adaptation to Kernel v5

 - Support exFat capacity more than 2TB


**Enable exFAT module and install exfat-utils:**

```
Add to /etc/initramfs-tools/modules:

exfat_core
exfat_fs
```

For filesystem creation and manipulation beyond that of the mount command it is necessary to install the exfat-utils package:

```bash
$ sudo add-apt-repository ppa:wip-kernel/exfat-utils
$ sudo apt-get update
$ sudo apt install exfat-utils
$ sudo apt purge exfat-fuse
```

**Usage, formatting:**

To create an exFAT file system, use mkfs.exfat (or the mkexfatfs command, which is synonymous):

```bash
# mkfs.exfat
mkexfatfs 1.3.0
Usage: mkfs.exfat [-i volume-id] [-n label] [-p partition-first-sector] [-s sectors-per-cluster] [-V] <device>

For instance, to create it on a removable device present at /dev/sde1 while assigning "Flash" as the file system label:

# mkfs.exfat -n Flash /dev/sde1
```

---

[![iptables](https://dragon-kernel.pro/images/iptables.jpeg)]()


## Fixes work IPTABLES and UFW for Dragon Kernel

**It is strongly recommended to use the iptables package only from the PPA Linux WIP-Kernel team:**


Step one:


```bash
$ sudo add-apt-repository ppa:wip-kernel/iptables
$ sudo add-apt-repository ppa:wip-kernel/libnftnl
$ sudo apt update
$ sudo apt dist-upgrade -y
```

Package version - iptables (1.8.3+)


Step two:


**WARNING! A temporary solution before updating systemd!**

Be sure to create data symlinks for library! Otherwise, your kernel will not boot properly!

 After upgrading the iptables package, check the symbolic link to the library.
If it is missing  symlink then create it symlink:

```bash
$ cd /lib/x86_64-linux-gnu
$ sudo ln -s libip4tc.so.2.0.0 libip4tc.so
$ sudo ln -s libip4tc.so.2.0.0 libip4tc.so.0
$ sudo ln -s libip6tc.so.2.0.0 libip6tc.so
$ sudo ln -s libip6tc.so.2.0.0 libip6tc.so.0
$ cd /etc
$ sudo rm ./ld.so.cache
$ sudo ldconfig
$ ldconfig -p | egrep libip
        libip6tc.so.2 (libc6,x86-64) => /lib/x86_64-linux-gnu/libip6tc.so.2
        libip6tc.so (libc6,x86-64) => /lib/x86_64-linux-gnu/libip6tc.so
        libip4tc.so.2 (libc6,x86-64) => /lib/x86_64-linux-gnu/libip4tc.so.2
        libip4tc.so (libc6,x86-64) => /lib/x86_64-linux-gnu/libip4tc.so
```


Step three:

 Nftables is a framework by the Netfilter Project that provides packet filtering, network address translation (NAT) and other packet mangling.
Two of the most common uses of nftables is to provide firewall support and NAT, nftables replaces the iptables framework.

 [WiKi nftables](https://wiki.debian.org/nftables)


```bash
$ sudo systemctl stop nftables.service && systemctl disable nftables.service
$ sudo nft flush ruleset
$ sudo apt purge nftables
$ sudo update-alternatives --set iptables /usr/sbin/iptables-legacy
$ sudo update-alternatives --set ip6tables /usr/sbin/ip6tables-legacy
$ sudo update-alternatives --set arptables /usr/sbin/arptables-legacy
$ sudo update-alternatives --set ebtables /usr/sbin/ebtables-legacy
$ sudo apt purge netfilter-persistent iptables-persistent
$ sudo apt install ufw gufw
$ sudo ufw disable
$ sudo touch /etc/rc.local
$ sudo chmod 755 /etc/rc.local
$ sudo chown root:root /etc/rc.local
```

 Add to file **/etc/rc.local**:


```
#!/bin/sh -e
#
# rc.local
#
# This script is executed at the end of each multiuser runlevel.
# Make sure that the script will "exit 0" on success or any other
# value on error.
#
# In order to enable or disable this script just change the execution
# bits.
#
# By default this script does nothing.
#
ufw enable
#
exit 0
```

Change string in file **/etc/default/ufw** ```IPT_MODULES="nf_conntrack_ftp nf_nat_ftp nf_conntrack_netbios_ns"``` to ```IPT_MODULES=""```.


```bash
$ sudo systemctl stop ufw.service && systemctl disable ufw.service
$ sudo systemctl enable rc.local.service && systemctl start rc.local.service
$ sudo ufw status verbose
```

**Use GUFW from your desktop to add and edit firewall rules**


**For professional users, I recommend upgrading systemd to the new version:**


```bash
$ sudo add-apt-repository ppa:wip-kernel/systemd
$ sudo apt update && apt dist-upgrade -y
```

**For professional users, I recommend install [firewalld](https://firewalld.org) tool:**


```bash
$ sudo dpkg -l | grep firewalld
$ sudo apt install firewalld firewall-applet
```

---

[![NVIDIA](https://dragon-kernel.pro/images/nv_drivers.jpeg)]()


## Fixes NVIDIA binary driver - version 390.116

**For kernel v5.2.y and 5.3.y**


Installation instructions for NVIDIA 390.116:


- deinstall all nvidia packages

```bash
#!/bin/bash
#
sudo apt purge libnvidia-cfg1-390 libnvidia-common-390 libnvidia-compute-390 \
	libnvidia-decode-390 libnvidia-encode-390 libnvidia-fbc1-390 \
	libnvidia-gl-390 libnvidia-ifr1-390 libxnvctrl0 nvidia-compute-utils-390 \
	nvidia-dkms-390 nvidia-driver-390 nvidia-kernel-common-390 \
	nvidia-kernel-source-390 nvidia-prime nvidia-settings nvidia-utils-390 \
	screen-resolution-extra xserver-xorg-video-nvidia-390
#
exit 0
```

- install nvidia kernel module source

Driver version -  nvidia-kernel-source-390 (390.116-0ubuntu1)


```bash
# sudo apt install nvidia-kernel-source-390
```

- patching source

[![Download](https://img.shields.io/badge/Download-patch-red.svg)](https://dragon-kernel.pro/patch/nvidia_module-390.116.patch)


```bash
# cd /usr/src

put a patch here

(there should already be a source folder - nvidia-390.116)

# patch -p1 < nvidia_module-390.116.patch
# rm nvidia_module-390.116.patch
```

- install all nvidia packages

```bash
#!/bin/bash
#
sudo apt install libnvidia-cfg1-390 libnvidia-common-390 libnvidia-compute-390 \
	libnvidia-decode-390 libnvidia-encode-390 libnvidia-fbc1-390 \
	libnvidia-gl-390 libnvidia-ifr1-390 libxnvctrl0 nvidia-compute-utils-390 \
	nvidia-dkms-390 nvidia-driver-390 nvidia-kernel-common-390 nvidia-prime \
	nvidia-settings nvidia-utils-390 screen-resolution-extra \
	xserver-xorg-video-nvidia-390
#
exit 0
```

---

[![VIRTUALBOX](https://dragon-kernel.pro/images/virtual_box.jpeg)]()


## Fixed VirtualBox packages 6.0.6

**For kernel 5.3.y**


- Patch for dkms kernel module:

[![Download](https://img.shields.io/badge/Download-patch-red.svg)](https://dragon-kernel.pro/patch/mp-r0drv-linux.c.patch)


Package version - VirtualBox-6.0.6 (6.0.6-dfsg-1)

---


[![haveged](https://dragon-kernel.pro/images/hvg.jpeg)]()


## Fixes booting kernel (Not enough entropy in random pool to proceed)


**HAVEGED** - Generate random numbers and feed linux random device.

The HAVEGE (HArdware Volatile Entropy Gathering and Expansion) algorithum harvests the indirect effects of hardware events on hidden processor state (caches, branch predictors, memory translation tables, etc) to generate a random sequence. The effects of interrupt service on processor state are visible from userland as timing variations in program execution speed. Using a branch-rich calculation that fills the processor instruction and data cache, a high resolution timer source such as the processor time stamp counter can generate a random sequence even on an "idle" system.
In Linux, the hardware events that are the ultimate source of any random number sequence are pooled by the /dev/random device for later distribution via the device interface. The standard mechanism of harvesting randomness for the pool may not be sufficient to meet demand, especially on those systems with high needs or limited user interaction. Haveged provides a daemon to fill /dev/random whenever the supply of random bits in /dev/random falls below the low water mark of the device.

Haveged also provides a direct file system interface to the collection mechanism that is also useful in other circumstances where access to the dev/random interface is either not available or inappropriate.

**It is strongly recommended to use the haveged package only from the PPA Linux WIP-Kernel team:**

```bash
$ sudo add-apt-repository ppa:wip-kernel/hvgd
$ sudo apt update
$ sudo apt install haveged
```

Package version - haveged (1.9.4)

---

[![**Linux Test Project**](https://dragon-kernel.pro/images/ltp_logo.jpeg)](http://linux-test-project.github.io/)

## Kernel tested by - [Linux Test Project](http://linux-test-project.github.io/)

 **Linux Test Project** is a joint project started by SGI, developed and maintained by IBM, Cisco, Fujitsu,
SUSE, Red Hat and others, that has a goal to deliver test suites to the open source community that validate
the reliability, robustness, and stability of Linux. The LTP testsuite contains a collection of tools for
testing the Linux kernel and related features.

---

### Tune IO scheduler

For now, add file /etc/udev/rules.d/60-ssd-scheduler.rules.

You can also add this to file 60-ssd-scheduler.rules:

```
# Non-rotational disks
ACTION=="add|change", KERNEL=="sd[a-z]", ATTR{queue/rotational}=="0", ATTR{queue/scheduler}="bfq"
# Rotational disks
ACTION=="add|change", KERNEL=="sd[a-z]", ATTR{queue/rotational}=="1", ATTR{queue/scheduler}="bfq"
```

and run a command:

```bash
# sudo udevadm control --reload && sudo udevadm trigger
```

---

### Enable ZSWAP 

Zswap is a kernel feature that provides a compressed RAM cache for swap pages

Add to grub.cfg:

```
GRUB_CMDLINE_LINUX="zswap.compressor=lz4 zswap.max_pool_percent=15"

Add to /etc/initramfs-tools/modules:

lz4
lz4_compress
```

and run command:

```bash
$ sudo  update-grub && update-initramfs -u
```

---

## Dragon Kernel Build Howto

This page will describe how to easily build the Dragon Kernel - [Build Dragon Kernel](https://dragon-kernel.pro/build)

---

## Dragon Kernel Guide

This page will describe how to easily build the Dragon Kernel - [Dragon Kernel Guide](https://dragon-kernel.pro/guide)

---


## Install Dragon Kernel

[![Update](https://dragon-kernel.pro/images/intel.jpeg)](https://downloadcenter.intel.com/download/27591/Linux-Processor-Microcode-Data-File)

Update Intel microcode for use IBRS/IBPB:

[![Download](https://img.shields.io/badge/Download-microcode-red.svg)](https://downloadcenter.intel.com/download/27591/Linux-Processor-Microcode-Data-File)


[![**Install**](https://dragon-kernel.pro/images/launchpad.png)](https://launchpad.net/~wip-kernel)


Strong recomended update firmware for you system:

Update Firmware for current Dragon kernel:

[![Download](https://img.shields.io/badge/Download-firmware-red.svg)](https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/snapshot/linux-firmware-20190514.tar.gz)

Update WiFi Firmware for current Dragon kernel:

[![Download](https://img.shields.io/badge/Download-firmware-red.svg)](https://git.kernel.org/pub/scm/linux/kernel/git/iwlwifi/linux-firmware.git/snapshot/linux-firmware-iwlwifi-fw-2019-05-03.tar.gz)


**Sources are on Launchpad. You can see and check them. From these sources, buildbox Launchpad builds packages in a clean environment. Everything is officially and verified by Launchpad and Canonical.**

[Source in the project page menu, click Code](https://launchpad.net/~wip-kernel)

[Source code direct link](https://git.launchpad.net/ubuntu-wip-kernel)

```
 WARNING! 

 You can only use kernel packages that are in PPA if you have a Dragon Team license key!
Without registering with the Dragon Team you need to do the build kernel packages yourself.
If you do not register at Dragon Team, the kernel installed from the PPA will work for only 15 minutes ...

 License activation is possible only on systems installed with LiveDVD/USB Dragon MATE images.
Dragon Team cannot guarantee the maximum support for the operation of the device as it is unknown 
whether the necessary libraries and firmware are installed in the system or not.
```

 - For registration in team [please read information](https://dragon-kernel.pro/licensing).

Install the packages from Launchpad PPA “Linux WIP-Kernel” Team:

 - Installed kernel works only with an activated Dragon Team members license!

**For Dragon GENERIC kernel:**

```bash
$ sudo add-apt-repository ppa:wip-kernel/genv5
$ sudo apt-get update
$ sudo apt install linux-headers-5.3.1-dragon linux-headers-5.3.1-dragon-generic linux-image-unsigned-5.3.1-dragon-generic linux-modules-5.3.1-dragon-generic linux-modules-extra-5.3.1-dragon-generic
$ sudo reboot
```

**For Dragon Lowlatency kernel:**

```bash
$ sudo add-apt-repository ppa:wip-kernel/genv5
$ sudo apt-get update
$ sudo apt install linux-headers-5.3.1-dragon linux-headers-5.3.1-dragon-lowlatency linux-image-unsigned-5.3.1-dragon-lowlatency linux-modules-5.3.1-dragon-lowlatency linux-modules-extra-5.3.1-dragon-lowlatency
$ sudo reboot
```

**For Dragon Sandy Bridge kernel:**

```bash
$ sudo add-apt-repository ppa:wip-kernel/shv5
$ sudo apt-get update
$ sudo apt install linux-headers-5.3.1-dragon linux-headers-5.3.1-dragon-sandybridge linux-image-unsigned-5.3.1-dragon-sandybridge linux-modules-5.3.1-dragon-sandybridge linux-modules-extra-5.3.1-dragon-sandybridge
$ sudo reboot
```

**For Dragon Haswell kernel:**

```bash
$ sudo add-apt-repository ppa:wip-kernel/shv5
$ sudo apt-get update
$ sudo apt install linux-headers-5.3.1-dragon linux-headers-5.3.1-dragon-haswell linux-image-unsigned-5.3.1-dragon-haswell linux-modules-5.3.1-dragon-haswell linux-modules-extra-5.3.1-dragon-haswell
$ sudo reboot
```

**For Dragon Westmere kernel:**

```bash
$ sudo add-apt-repository ppa:wip-kernel/wav5pax
$ sudo apt-get update
$ sudo apt install linux-headers-5.3.1-dragon linux-headers-5.3.1-dragon-westmere linux-image-unsigned-5.3.1-dragon-westmere linux-modules-5.3.1-dragon-westmere linux-modules-extra-5.3.1-dragon-westmere
$ sudo reboot
```

**For Dragon Atom kernel:**

```bash
$ sudo add-apt-repository ppa:wip-kernel/wav5pax
$ sudo apt-get update
$ sudo apt install linux-headers-5.3.1-dragon linux-headers-5.3.1-dragon-atom linux-image-unsigned-5.3.1-dragon-atom linux-modules-5.3.1-dragon-atom linux-modules-extra-5.3.1-dragon-atom
$ sudo reboot
```

- Ready packages are build as they become update and fixed the source

---

[![Donate with Bitcoin](https://en.cryptobadges.io/badge/big/1KvWrbLhuzk8DSb2Yq2948bMj3uQvVTQCW)](https://en.cryptobadges.io/donate/1KvWrbLhuzk8DSb2Yq2948bMj3uQvVTQCW)
[![Donate with Ethereum](https://en.cryptobadges.io/badge/big/0xE42f2d4D4aF888Ac784ED26a68E828475A4712Cb)](https://en.cryptobadges.io/donate/0xE42f2d4D4aF888Ac784ED26a68E828475A4712Cb)

