#include <iostream>
#include <vector>
#include <string>

std::vector<int> kmp(std::string s) {
    std::vector<int> kmpArr(s.length() + 1);
    int i = 0, j = -1;
    kmpArr[0] = j;
    while (i < s.length()) {
        while (j != -1 && s[i] != s[j]) {
            j = kmpArr[j];
        }
        i++;
        j++;
        kmpArr[i] = j;
    }
    return kmpArr;
}

signed main () {
    std::string s, p;
    std::cin >> s >> p;
    std::vector<int> kmpArr = kmp(p + "#" + s);
    int answer = 0;
    for (int i = 0; i < kmpArr.size(); ++i) {
        std::cout << i << ":" << kmpArr[i] << std::endl;
        if (kmpArr[i] == p.size()) answer++;
    }
    std::cout << "Answer = " << answer << std::endl;
}