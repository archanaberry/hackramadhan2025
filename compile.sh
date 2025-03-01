#!/bin/bash

# Nama output binary
OUTPUT="hack_ramadhan"

# Nama source file
SOURCE="hack_ramadhan.c"

# Pastikan GTK4 dan dependensi tersedia
echo "[INFO] Memeriksa dependensi..."
sudo pacman -S --needed gtk4 xorgproto xorg-xproto xorg-xrandr

# Pastikan PKG_CONFIG_PATH sudah diatur
export PKG_CONFIG_PATH="/usr/lib/pkgconfig:/usr/share/pkgconfig:$PKG_CONFIG_PATH"

# Kompilasi program
echo "[INFO] Mengompilasi $SOURCE..."
gcc -o "$OUTPUT" "$SOURCE" `pkg-config --cflags --libs gtk4`

# Periksa apakah kompilasi berhasil
if [ $? -eq 0 ]; then
    echo "[SUCCESS] Kompilasi berhasil! Jalankan dengan ./$OUTPUT"
else
    echo "[ERROR] Kompilasi gagal!"
fi
