#include <iostream>
#include <vector>

int rec(std::vector<std::vector<int> >& happiness, int student_position, int mask, std::vector<std::vector<int> >& dp, int students, int ranks) {
    if (student_position == students) return 0;
    if (dp[student_position][mask] != -1) {
        return dp[student_position][mask];
    }
    dp[student_position][mask] = dp[student_position][mask];
    for (int rank = 1; rank < ranks; rank++) {
        if (mask&(1<<rank) == 0) {
            dp[student_position][mask] = 
                std::max(
                    dp[student_position][mask], 
                    happiness[rank][student_position] + 
                    rec(happiness, student_position + 1, mask | (1 << rank), dp, students, ranks)
                );
        }
    }
    return dp[student_position][mask];
}

int main() {
    int ranks, students;
    std::cin >> ranks >> students;
    std::vector<std::vector<int> > happiness(ranks, std::vector<int>(students));
    for (int rank = 0; rank < ranks; rank++) {
        for (int student = 0; student < students; student++) {
            std::cin >> happiness[rank][student];
        }
    }

    //dp (student, rank_mask): what is current max happiness that can be made if we have students from student ... students and we have allocateda mask = rank_mask;
    std::vector<std::vector<int> > dp(students+1, std::vector<int>(1<<ranks, -1));
    std::cout << rec(happiness, 1, 0, dp, students, ranks) << std::endl;
}