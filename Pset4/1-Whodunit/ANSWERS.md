# Questions

## What's `stdint.h`?

It is the library where all file manipulation functions live.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

It helps us to define and standardize the amount of space for each variable.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

-BYTE is 1 byte.
-DWORD is 4 bytes.
-LONG is 4 bytes.
-WORD is 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

According to bmp.h, it should be The file type and it must be BM.


## What's the difference between `bfSize` and `biSize`?

biSize is indicating the size of image, on the other hand bfSize is stating the total file's size including image and headers.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the pointer, which we assigned to our files, can not reach the files somehow, it might become null.

We need to check if the pointer that we got back is not equal to null. If we try and dereference a null pointer recall we will have a segmentation fault.

## Why is the third argument to `fread` always `1` in our code?

Because our bmp.h file includes only one struct for each part of the file.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

Allows us  rewind or fast-forward in a file.

## What is `SEEK_CUR`?

It defines that the offset is relative to the current position indicator.
