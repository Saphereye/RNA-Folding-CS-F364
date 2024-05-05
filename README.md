# RNA Folding simulation

## Introduction

This project finds the theoretical amount of bonds given an RNA sequence.

<div style="text-align:center;"><img src="https://github.com/Saphereye/RNA-Folding-CS-F364/blob/main/assets/demo.png" alt="Demo of the program" style="width:30%;"></div>

The image demonstrates the visualization of bonds in the RNA using our DP algorithm.

## Brief Description of the Algorithm

This algorithm is a dynamic programming approach for predicting RNA sequences' secondary structure. It aims to maximize the number of non-crossing base pairs based on the assumption that the more the base pairs, the more stable the RNA molecule is.

The algorithm uses a 2D matrix to store the number of base pairs for every possible substring of the RNA sequence. The matrix is filled in a bottom-up manner, where each cell (i, j) represents the maximum number of base pairs that can be formed in the substring from index i to j.

The algorithm considers three possibilities to fill each cell:

1. The number of base pairs if the current base pairs with the base at the end of the substring.
2. The number of base pairs if the current base does not pair with any base.
3. The maximum number of base pairs can be formed by bifurcating the substring at any possible position.

The cell is filled with the maximum of these three possibilities. The final solution is present in the cell (0, n-1), where n is the length of the RNA sequence.

The algorithm also includes a traceback procedure to recover the optimal structure.

## Comparison against ground truth

We ran the algorithm on 5 sequences, and these are the results in comparison with ground truth:

| RNA Name                                                         | RNA Length | Our algorithm (# of bonds) | Ground truth (# of bonds) |
|------------------------------------------------------------------|------------|----------------------------|---------------------------|
| Homo sapiens (human) RNA, U5D small nuclear 1 (RNU5D-1)          | 100        | 33                         | 23                        |
| Homo sapiens (human) small nucleolar RNA, C/D box 43 (SNORD43)   | 62         | 19                         | 2                         |
| Homo sapiens (human) microRNA hsa-mir-921 precursor              | 56         | 17                         | 18                        |
| Homo sapiens U7 small nuclear RNA                                | 44         | 13                         | 11                        |
| Homo sapiens (human) small nucleolar RNA, H/ACA box 81 (SNORA81) | 177        | 61                         | 36                        |

Here, we considered the minimum loop length to be 4, i.e. if adding a bond creates a loop of nucleotides, there must be at least 4 nucleotides between the start and end of the bond.

## Timing analysis
| % time | cumulative seconds | self seconds | calls | self ms/call | total ms/call | name                                                                                                                                                                                       |
|--------|--------------------|--------------|-------|--------------|---------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 50.00  | 0.02               | 0.02         | 1     | 20.00        | 20.00         | stbi__do_zlib(stbi__zbuf*, char*, int, int, int)                                                                                                                                           |
| 50.00  | 0.04               | 0.02         | 1     | 20.00        | 20.00         | stbi__create_png_image_raw(stbi__png*, unsigned char*, unsigned int, int, unsigned int, unsigned int, int, int)                                                                            |
| 0.00   | 0.04               | 0.00         | 1121  | 0.00         | 0.00          | std::__cxx11::basic_string, std::allocator >::_M_replace(unsigned long, unsigned long, char const*, unsigned long)                                                                         |
| 0.00   | 0.04               | 0.00         | 1035  | 0.00         | 0.00          | std::__cxx11::basic_string, std::allocator >::_M_mutate(unsigned long, unsigned long, char const*, unsigned long)                                                                          |
| ... | ... | ... | ... | ... | ... | ... |

## Files

Here are the main files in the project:

- [main.cpp](https://saphereye.github.io/RNA-Folding-CS-F364/main_8cpp.html)
- [rna_folding.cpp](https://saphereye.github.io/RNA-Folding-CS-F364/rna__folding_8hh.html)

The documentation can be found [here](https://saphereye.github.io/RNA-Folding-CS-F364/).

## Project Group
This project was done with the contributions of

| **Name**             | **Id**        |
|----------------------|---------------|
| Adarsh Das           | 2021A7PS1511H |
| Divyateja Pasupuleti | 2021A7PS0075H |
| Kumarasamy Chelliah  | 2021A7PS0096H |
| Manan Gupta          | 2021A7PS2091H |
