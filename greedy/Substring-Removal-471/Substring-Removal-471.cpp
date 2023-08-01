#include <iostream>
#include <string>
#include <vector>

void solve(std::string& s, int x, int y) {
    int count = 0;
    if (x > y) {
        int i = 0;
        while (i < s.length()-1) {
            if(s[i] == 'a' && s[i+1] == 'b') {
                count += x;
                if (i+2 < s.length()) {
                    s = s.substr(0,i) + s.substr(i+2);
                } else {
                    s = s.substr(0,i);
                }
            } else {
                i++;
            }
        }

        i = 0;
        while (i < s.length()-1) {
            if(s[i] == 'b' && s[i+1] == 'a') {
                count += y;
                if (i+2 < s.length()) {
                    s = s.substr(0,i) + s.substr(i+2);
                } else {
                    s = s.substr(0,i);
                }
            } else {
                i++;
            }
        }
    } else {
        int i = 0;
        while (i < s.length()-1) {
            if(s[i] == 'b' && s[i+1] == 'a') {
                count += y;
                if (i+2 < s.length()) {
                    s = s.substr(0,i) + s.substr(i+2);
                } else {
                    s = s.substr(0,i);
                }
            } else {
                i++;
            }
        }

        i = 0;
        while (i < s.length()-1) {
            if(s[i] == 'a' && s[i+1] == 'b') {
                count += x;
                if (i+2 < s.length()) {
                    s = s.substr(0,i) + s.substr(i+2);
                } else {
                    s = s.substr(0,i);
                }
            } else {
                i++;
            }
        }
    }
    std::cout << count << std::endl;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        int x, y;
        std::cin >> s >> x >> y;
        std::cout << s << " " << x << " " << y << std::endl;
        solve(s, x, y);
    }
}