#include <iostream>
#include <string>
#include <vector>

struct node {
    int badCount;
    node* childs[26];
    node() {
        for (int i = 0; i < 26; i++) {
            childs[i] = nullptr;
        }
        badCount = 0;
    }
};

struct trie {
    node* root;
    trie() {
        root = new node();
    }
    void insert(std::string s, int* bad) {
        node* curr = root;
        int currBad = 0;
        for (int i = 0; i < s.length(); i++) {
            if(curr->childs[s[i] - 'a'] == nullptr) {
                curr->childs[s[i] - 'a'] = new node();
            }
            curr = curr->childs[s[i]-'a'];
            if (bad[s[i]-'a']) currBad++;
            curr -> badCount = currBad;
        }
    }
};

int dfs(node* curr, int k) {
    if (curr->badCount > k) return 0;
    int goodSum = 1;
    for (int i = 0; i < 26; i++) {
        if (curr->childs[i] != nullptr) {
            goodSum += dfs(curr->childs[i], k);
        }
    }
    return goodSum;
}

signed main (){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::string s, b;
    int k;
    std::cin >> s >> b;
    int bad[26];
    for (int i = 0; i < 26; i ++) { 
        if (s[i] == '0') bad[i] = 1;
        else bad[i] = 0;
    }
    std::cin >> k;
    trie* t = new trie();
    for (int i = 0; i < s.length(); i++) {
        t->insert(s.substr(i), bad);
    }
    std::cout << dfs(t->root, k) - 1 << std::endl;
}