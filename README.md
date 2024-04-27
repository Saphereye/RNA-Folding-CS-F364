# RNA Folding simulation

## Introduction

This project deals with finding the theoretical amount of bonds given an RNA sequence.

<img src="demo.png" alt="Demo of the program" style="width:25%;">

The image demonstrates the visualization of bonds in the RNA using our DP algorithm.

## Comparison against ground truth

We ran the algorithm on 5 sequence, these are the results in comparison with ground truth:

| RNA Name                                                         | RNA Length | Number of bonds (mll=0) | Number of bonds (mll=4) | Ground truth | Dot-bracket similarity (mll=4) |
|------------------------------------------------------------------|------------|-------------------------|-------------------------|--------------|--------------------------------|
| Homo sapiens (human) RNA, U5D small nuclear 1 (RNU5D-1)          | 100        | 41                      | 37                      | 23           | 67%                            |
| Homo sapiens (human) small nucleolar RNA, C/D box 43 (SNORD43)   | 62         | 25                      | 20                      | 2            | 38.71%                         |
| Homo sapiens (human) microRNA hsa-mir-921 precursor              | 56         | 23                      | 19                      | 18           | 71.43%                         |
| Homo sapiens U7 small nuclear RNA                                | 44         | 18                      | 13                      | 11           | 63.64%                         |
| Homo sapiens (human) small nucleolar RNA, H/ACA box 81 (SNORA81) | 177        | 80                      | 63                      | 36           | 62.15%                         |

## Files

Here are the main files in the project:

- [main.cpp](main_8cpp.html)
- [rna_folding.cpp](rna__folding_8hh.html)