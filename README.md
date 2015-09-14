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
