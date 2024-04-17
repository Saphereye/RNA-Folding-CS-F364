#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief
 *
 * @param rna_sequence
 * @return int
 *
 * Resources used
 * - https://www.youtube.com/watch?v=hwhLBfA3mgY
 * - https://en.wikipedia.org/wiki/Nussinov_algorithm
 * - https://github.com/ShanSabri/SSFold/blob/master/writeup/wqe.pdf
 * - https://www.cs.cmu.edu/~02710/Lectures/RNALecture2015.pdf
 * - https://rna.informatik.uni-freiburg.de/Teaching/index.jsp?toolName=Nussinov
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

    // for (int i = 0; i < rna_sequence.size(); i++) {
    //     for (int j = 0; j < rna_sequence.size(); j++) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return dp;
}

int rna_score(const std::string& rna_sequence,
              const int& minimal_loop_length = 0) {
    std::vector<std::vector<int>> dp =
        create_matrix(rna_sequence, minimal_loop_length);
    return dp[0][rna_sequence.size() - 1];
}

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

std::string dot_write(const std::string& rna,
                      const std::vector<std::pair<int, int>>& fold) {
    std::string dot(rna.size(), '.');

    for (const auto& s : fold) {
        dot[std::min(s.first, s.second)] = '(';
        dot[std::max(s.first, s.second)] = ')';
    }

    return dot;
}