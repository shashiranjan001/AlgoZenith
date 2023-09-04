#include <iostream>
#include <vector>
#include <string>

struct node {
    int prefixCount;
    int wendCount;
    std::string wend;
    node* child[26];

    node() {
        prefixCount = 0;
        wendCount = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

struct trie {
    node* root;

    trie() {
        root = new node();
    }

    void insert (std::string s) {
        node* currentNode = root;
        for (int i = 0; i < s.length(); i++) {
            currentNode->prefixCount++;
            if (currentNode->child[s[i] - 'a'] == NULL) {
                currentNode->child[s[i] - 'a'] = new node();
            }
            currentNode = currentNode->child[s[i] - 'a'];
        }
        currentNode->wendCount++;
        currentNode->wend = s;
    }
};

void findKDiff(node* current, int maxDiff, std::string s, int index, std::vector<std::string>& answer) {
    if (maxDiff < 0) return;
    if (index == s.length()) {
        for (int i = 0; i < current -> wendCount; i++) {
            answer.push_back(current->wend);
        }
        return;
    }
    
    for (int i = 0; i < 26; i++) {
        if (current -> child[i] != NULL) {
            findKDiff(current->child[i], maxDiff-(s[index]-'a' != i), s, index+1, answer);
        }
    }
}

void dfs (node* currentNode) {
    for (int i = 0; i < currentNode->wendCount; i++) {
        std::cout << currentNode->wend << ", ";
    }
    if (currentNode->wendCount) std::cout << std::endl;
    for (int i = 0; i < 26; i++) {
        if (currentNode->child[i] != NULL) {
            dfs(currentNode->child[i]);
        }
    }
}

int main () {
    std::ios::sync_with_stdio (0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    trie* t = new trie();
    std::string s;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        t->insert(s);
    }
    dfs(t->root);
    std::cin >> s;
    int k;
    std::cin >> k;
    std::vector<std::string> answer;
    findKDiff(t->root, k, s, 0, answer);
    for (auto it: answer) std::cout << it << " ";
    std::cout << std::endl;
}