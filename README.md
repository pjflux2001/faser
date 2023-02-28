# faser

## How to run :
Step 1: 
```
g++ compress.cpp -lz
```
-lz flag allows to link the zlib library 

** *in case zlib is missing*, follow this [link](https://stackoverflow.com/questions/18148075/compilation-error-missing-zlib-h)

Step 2:
```
./a.out input.txt
```
replace input.txt with file of your choice

## Test run :
```
flux@flux-ThinkPad-L13-Gen-2:~/faser$ g++ compress.cpp -lz
flux@flux-ThinkPad-L13-Gen-2:~/faser$ ./a.out input.txt 
Input file size: 8956 bytes
Output file size: 4282 bytes
Compression ratio: 2.09155
flux@flux-ThinkPad-L13-Gen-2:~/faser$ cat /dev/random > input.txt 
^C
flux@flux-ThinkPad-L13-Gen-2:~/faser$ ^C
flux@flux-ThinkPad-L13-Gen-2:~/faser$ ls -lh
total 1.2G
-rwxrwxr-x 1 flux flux  32K Feb 28 11:43 a.out
-rw-rw-r-- 1 flux flux 1.6K Feb 28 11:40 compress.cpp
-rw-rw-r-- 1 flux flux 1.2G Feb 28 11:48 input.txt
-rw-rw-r-- 1 flux flux    8 Feb 28 11:41 README.md
flux@flux-ThinkPad-L13-Gen-2:~/faser$ ./a.out input.txt 
Error: Unable to compress input data. zlib error code: -5
flux@flux-ThinkPad-L13-Gen-2:~/faser$ 
```

** code works fine with standard file input - requires modification to cover stream seek from files like /dev/random
