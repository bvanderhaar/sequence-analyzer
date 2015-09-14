# Sequence Analyzer
* Analyzes sequences in [FASTA format](https://en.wikipedia.org/wiki/FASTA_format)

* Usage: -f inputfile
* Options:
* -t outputs time information for running

Prerequisites
=============
* LLVM
* clang++
* clang-format

Sample Output
===========
    Running analysis with file input HIV-1_db.fasta.txt
    Adenine (A) Count (Percentage): 3296 (34.448161%)
    Thymine (T) Count (Percentage): 2058 (21.509197%)
    Cytosine (C) Count (Percentage): 1633 (17.067308%)
    Guanine (G) Count (Percentage): 2209 (23.087375%)
    Read Time: 0.000198
    A Count Time: 0.000002
    T Count Time: 0.000003
    C Count Time: 0.000004
    G Count Time: 0.000004
    Found possible CpG island from character 0 to 400
    Found possible CpG island from character 1 to 401
    Found possible CpG island from character 2 to 402
    Found possible CpG island from character 3 to 403
    Found possible CpG island from character 4 to 404
    Found possible CpG island from character 5 to 405
    Found possible CpG island from character 6 to 406
    Found possible CpG island from character 7 to 407
    Found possible CpG island from character 8 to 408
    Found possible CpG island from character 9 to 409
    Found possible CpG island from character 10 to 410
    Found possible CpG island from character 11 to 411
    Found possible CpG island from character 12 to 412
    Found possible CpG island from character 13 to 413
    Found possible CpG island from character 14 to 414
    Found possible CpG island from character 15 to 415
    Found possible CpG island from character 16 to 416
    Found possible CpG island from character 17 to 417
    Found possible CpG island from character 18 to 418
    Found possible CpG island from character 19 to 419
    Found possible CpG island from character 20 to 420
    Found possible CpG island from character 21 to 421
    Found possible CpG island from character 22 to 422
    Found possible CpG island from character 23 to 423
    Found possible CpG island from character 24 to 424
    Found possible CpG island from character 25 to 425
    Found possible CpG island from character 26 to 426
    Found possible CpG island from character 27 to 427
    Found possible CpG island from character 28 to 428
    Found possible CpG island from character 29 to 429
    Found possible CpG island from character 30 to 430
    Found possible CpG island from character 31 to 431
    Found possible CpG island from character 32 to 432
    Found possible CpG island from character 33 to 433
    Found possible CpG island from character 34 to 434
    Found possible CpG island from character 35 to 435

Description
============
Analyzes a FASTA file for possible CpG islands.  Displays basic statistics about a particular FASTA file.

Approach
========
I used C++ with Clang++ compiler with C++ 14 on OS X Yosemite. Initially, even reading the production file for counts took around 10 seconds on a Macbook Pro from 2015.  I looked for compiler optimizations I could enable.  Starting with clang's L1 optimization (-O1), the solution took less than a second through each for loop.
Looking for more speed, I enabled L2 optimizations (-O2).  The solution now took less than a tenth of a second per for loop.
Initially the code was not mindful of memory, duplicating strings in multiple spots.  I optimized this by using pass-by-ref and only keeping a single string instance of the FASTA file in memory.

I did do some research on Clang/LLVM and GCC.  While I'm an open-source advocate, it appears the world is heading in the direction of LLVM.  In addition, LLVM provides an OpenMP compiler and the performance is comparable to GCC.  Plus, it comes out of the box on my Mac.

While it didn't really affect my decision, two other pluses mentined for LLVM was the friendliness of the license for contributing code, plus more helpful debugging information compared to GCC.
