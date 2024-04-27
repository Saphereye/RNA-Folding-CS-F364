/**
 * @file rna_folding.hh
 * @author Adarsh Das (saphereye.github.io)
 * @brief RNA folding algorithm implementation
 * @date 2024-04-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include "herrlog.hh"

/**
 * @brief Function to create the DP matrix for RNA folding
 *
 * @param rna_sequence
 * @return int
 */
std::vector<std::vector<int>> create_matrix(
    const std::string& rna_sequence, const int& minimal_loop_length = 0) {
    std::vector<std::vector<int>> dp(rna_sequence.size(),
                                     std::vector<int>(rna_sequence.size(), 0));

    for (size_t k = 1; k < rna_sequence.size(); k++) {
        for (size_t i = 0; i < rna_sequence.size() - k; i++) {
            size_t j = i + k;

            if (j - i >= minimal_loop_length) {
                int rc = INT32_MIN;
                for (size_t t = i; t < j; t++) {
                    rc = std::max(rc, dp[i][t] + dp[t + 1][j]);
                }

                dp[i][j] = std::max(
                    {dp[i + 1][j], dp[i][j - 1],
                     dp[i + 1][j - 1] +
                         (rna_sequence[i] == 'A' && rna_sequence[j] == 'U' ||
                          rna_sequence[i] == 'U' && rna_sequence[j] == 'A' ||
                          rna_sequence[i] == 'C' && rna_sequence[j] == 'G' ||
                          rna_sequence[i] == 'G' && rna_sequence[j] == 'C'),
                     rc});
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return dp;
}

/**
 * @brief Function to calculate number of bonds (theoretical) in the RNA
 * 
 * @param rna_sequence 
 * @param minimal_loop_length 
 * @return int 
 */
int rna_score(const std::string& rna_sequence,
              const int& minimal_loop_length = 0) {
    std::vector<std::vector<int>> dp =
        create_matrix(rna_sequence, minimal_loop_length);
    return dp[0][rna_sequence.size() - 1];
}

/**
 * @brief Function to traceback DP and get the bonds structure
 * 
 * @param nm 
 * @param rna 
 * @param fold 
 * @param i 
 * @param j 
 */
void traceback(const std::vector<std::vector<int>>& nm, const std::string& rna,
               std::vector<std::pair<int, int>>& fold, int i, int j) {
    if (i < j) {
        if (nm[i][j] == nm[i + 1][j]) {  // 1st rule
            traceback(nm, rna, fold, i + 1, j);
        } else if (nm[i][j] == nm[i][j - 1]) {  // 2nd rule
            traceback(nm, rna, fold, i, j - 1);
        } else if (nm[i][j] ==
                   nm[i + 1][j - 1] +
                       (rna[i] == 'A' && rna[j] == 'U' ||
                        rna[i] == 'U' && rna[j] == 'A' ||
                        rna[i] == 'C' && rna[j] == 'G' ||
                        rna[i] == 'G' && rna[j] == 'C')) {  // 3rd rule
            fold.push_back(std::make_pair(i, j));
            traceback(nm, rna, fold, i + 1, j - 1);
        } else {
            for (int k = i + 1; k < j - 1; k++) {
                if (nm[i][j] == nm[i][k] + nm[k + 1][j]) {  // 4th rule
                    traceback(nm, rna, fold, i, k);
                    traceback(nm, rna, fold, k + 1, j);
                    break;
                }
            }
        }
    }
}

/**
 * @brief Function to create the dot-bracket notation from the bonds
 * 
 * @param rna 
 * @param fold 
 * @return std::string 
 */
std::string dot_write(const std::string& rna,
                      const std::vector<std::pair<int, int>>& fold) {
    std::string dot(rna.size(), '.');

    for (const auto& s : fold) {
        dot[std::min(s.first, s.second)] = '(';
        dot[std::max(s.first, s.second)] = ')';
    }

    return dot;
}

/**
 * @brief Creates a DOT script from the RNA sequence and structure and calls graphviz
 * 
 * @param sequence 
 * @param structure 
 */
void dot_bracket_to_dot(const std::string& sequence, const std::string& structure) {
    std::string dot = "graph RNA {\n";
    dot += "  bgcolor=\"transparent\";\n"; // Set the background color to transparent
    dot += "  splines=polyline;\n"; // Use polyline splines for edges
    dot += "  overlap=scale;\n"; // Use Voronoi-based technique to remove node overlaps
    dot += "  size=\"50,50\";\n"; // Limit the size of the output image to 5x5 inches
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::string color;
        switch (sequence[i]) {
            case 'A': color = "red"; break;
            case 'C': color = "blue"; break;
            case 'G': color = "green"; break;
            case 'U': color = "yellow"; break;
        }
        dot += "  " + std::to_string(i) + " [label=\"" + sequence[i] + "\", fontcolor=\"black\", fillcolor=\"" + color + "\", style=filled];\n";
        if (i > 0) { // Add an edge between consecutive bases
            dot += "  " + std::to_string(i - 1) + " -- " + std::to_string(i) + " [color=white, penwidth=10.0];\n";
        }
    }
    std::vector<int> stack;
    for (size_t i = 0; i < structure.size(); ++i) {
        if (structure[i] == '(') {
            stack.push_back(i);
        } else if (structure[i] == ')') {
            int j = stack.back();
            stack.pop_back();
            dot += "  " + std::to_string(j) + " -- " + std::to_string(i) + " [color=lightgrey, penwidth=10.0];\n";
        }
    }
    dot += "}\n";

    // Write the DOT script to a file
    std::ofstream file("rna.dot");
    file << dot;
    file.close();

    // Run the neato program to generate a plot of the graph
    int result = system("neato -Tpng rna.dot -o rna.png");
    if (result != 0) {
        Logger::error("Failed to run the neato program.");
    }
}