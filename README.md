# hw-Linux


### Tutorial:
https://www.example.com

### Reqs:

```bash
sudo apt install gcc build-essential genisoimage xorriso
```

## Generate ISO:

### 1- Clone

```bash
git clone https://github.com/MainSilent/hw-Linux.git
```

### 2- Initramfs

```bash
gcc -static -o init main.c

echo init | cpio --quiet -H newc -o | gzip -9 -n > initramfs

mv initramfs boot
```

### 3- Image

```bash
xorriso                                                \
    -as mkisofs                                        \
    -iso-level 3                                       \
    -full-iso9660-filenames                            \
    -volid "hw Linux"                                  \
    -eltorito-boot                                     \
        boot/grub/bios.img                             \
        -no-emul-boot                                  \
        -boot-load-size 4                              \
        -boot-info-table                               \
        --eltorito-catalog boot/grub/boot.cat          \
    --grub2-boot-info                                  \
    --grub2-mbr /usr/lib/grub/i386-pc/boot_hybrid.img  \
    -eltorito-alt-boot                                 \
        -e EFI/efiboot.img                             \
        -no-emul-boot                                  \
    -append_partition 2 0xef boot/grub/efiboot.img     \
    -output "hw-Linux.iso"                             \
    -graft-points                                      \
        "boot"                                         \
        /boot/grub/bios.img=boot/grub/bios.img         \
        /EFI/efiboot.img=boot/grub/efiboot.img
```