# My Project Documentation

## Introduction

This project deals with finding the theoretical amount of bonds given an RNA sequence.

<img src="demo.png" alt="Demo of the program" style="width:25%;">

The image demonstrates the visualization of bonds in the RNA using our DP algorithm.

## Comparison against ground truth

We ran the algorithm on 5 sequence, these are the results in comparison with ground truth:

| RNA Name                                                         | RNA Length | Our algorithm (min loop len: 0) | Our algorithm (min loop len: 5) | Ground truth |
|------------------------------------------------------------------|------------|---------------------------------|---------------------------------|--------------|
| Homo sapiens (human) small nucleolar RNA, H/ACA box 91 (SNORA91) | 178        | 76                              | 64                              | 59           |
| Homo sapiens (human) ABR antisense RNA 1 (ABR-AS1)               | 994        | 439                             | 364                             |              |
| Homo sapiens (human) piR-61154                                   | 26         | 9                               | 8                               |              |
| Homo sapiens (human) RNA, U5D small nuclear 1 (RNU5D-1)          | 100        | 41                              | 37                              | 23           |
| Thermus thermophilus 5S rRNA                                     | 122        | 53                              | 44                              |              |

## Files

Here are the main files in the project:

- [main.cpp](main_8cpp.html)
- [rna_folding.cpp](rna__folding_8hh.html)