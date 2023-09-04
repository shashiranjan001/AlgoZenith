#include <iostream>
#include <string>
#include <vector>
#include <stack>

void solve(std::string& s, int ab, int ba) {
    std::string s1 = "ab";
    std::string s2 = "ba";
    if (ab < ba) {
        s1.swap(s2);
        int temp;
        temp = ab;
        ab = ba;
        ba = temp;
    }
    std::stack<char> st;
    long long ans = 0;
    for (auto it: s) {
        if (!st.empty() && st.top() == s1[0] && it == s1[1]) {
            ans += ab;
            st.pop();
        } else {
            st.push(it);
        }
    }
    std::string leftOver = "";
    while (!st.empty()) {
        leftOver += st.top();
        
        st.pop();
    }
    std::reverse(leftOver.begin(), leftOver.end());
    for (auto it: leftOver) {
        if (!st.empty() && st.top() == s2[0] && it == s2[1]) {
            ans += ba;
            st.pop();
        } else {
            st.push(it);
        }
    }
    std::cout << ans << std::endl;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        int x, y;
        std::cin >> s >> x >> y;
        solve(s, x, y);
    }
}