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
 * -
 * https://en.wikipedia.org/wiki/Nussinov_algorithm#:~:text=The%20Nussinov%20algorithm%20is%20a,Nussinov%20in%20the%20late%201970s.
 * - https://github.com/ShanSabri/SSFold/blob/master/writeup/wqe.pdf
 * - https://www.cs.cmu.edu/~02710/Lectures/RNALecture2015.pdf
 */
int rna_score(std::string rna_sequence) {
    std::vector<std::vector<int>> dp(rna_sequence.size(),
                                     std::vector<int>(rna_sequence.size(), 0));

    for (int len = 2; len <= rna_sequence.size(); len++) {
        for (int i = 0; i < rna_sequence.size() - len + 1; i++) {
            int j = i + len - 1;
            
            int score = 0;
            if (rna_sequence[i] == 'A' && rna_sequence[j] == 'U' ||
                rna_sequence[i] == 'U' && rna_sequence[j] == 'A' ||
                rna_sequence[i] == 'C' && rna_sequence[j] == 'G' ||
                rna_sequence[i] == 'G' && rna_sequence[j] == 'C') {
                score = 1;
            }

            int temp_max = INT32_MIN;
            for (int k = i + 1; k < j; k++) {
                temp_max = std::max(temp_max, dp[i][k] + dp[k + 1][j]);
            }

            dp[i][j] = std::max(std::max(dp[i + 1][j], dp[i][j - 1]),
                                std::max(dp[i + 1][j - 1] + score, temp_max));
        }
    }

    for (int i = 0; i < rna_sequence.size(); i++) {
        for (int j = 0; j < rna_sequence.size(); j++) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return dp[0][rna_sequence.size() - 1];
}