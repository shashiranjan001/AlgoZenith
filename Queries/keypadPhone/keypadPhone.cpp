#include <iostream>
#include <vector>
#include <string>
#include <map>

std::vector<std::string> generateAllCombinations(const std::vector<int>& inp, std::map<int, std::string>& mapping, int level) {
    std::vector<std::string> myCombinations;
    if (level == inp.size()) return myCombinations;
    // 2 3 4 5
    // recAnswer = {"J", "K", "L"}
    // 4: GHI
    std::vector<std::string> recAnswer = generateAllCombinations(inp, mapping, level+1);
    for (int i = 0; i < mapping[inp[level]].length(); i ++) {
        if (recAnswer.size() == 0) {
            recAnswer = std::vector<std::string> (1, "");
        }
        for (auto str: recAnswer) {
            myCombinations.push_back(mapping[inp[level]][i] + str);
        }
    }
    return myCombinations;
}

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> inp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> inp[i];
    }
    // for (int i = 0; i < n; i++) {
    //     std::cout << inp[i];
    // }
    std::map<int, std::string> mapping;
    mapping[2] = "ABC";
    mapping[3] = "DEF";
    mapping[4] = "GHI";
    mapping[5] = "JKL";
    mapping[6] = "MNO";
    mapping[7] = "PQRS";
    mapping[8] = "TUV";
    mapping[9] = "WXYZ";
    std::vector<std::string> allCombinations = generateAllCombinations(inp, mapping, 0);
    for (auto str: allCombinations) {
        std::cout << str << std::endl;
    }
}

// 2 : "A", "B", "C"
// 423: "A", "B", "C" + 
// 3: "D", "E", "F"
// 23 : "AD", "AE", "AF", "BD", "BE", "BF"
// 4: GHI
// 423: "GAD", "GAF", "GBD", "GBE", "GBF", "HAD", "HAF", "HBD", "HBE", "HBF", "IAD", "IAF", "IBD", "IBE", "IBF"
