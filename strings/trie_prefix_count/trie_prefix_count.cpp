#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

    void insert(std::string s) {
        node* currentNode= root;
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

void dfsCount (node* currentNode, int& count) {
    
    for (int i = 0; i < currentNode->wendCount && count >= 0; i++) {
        std::cout << currentNode->wend << ", ";
        count--;
    }

    if (count) {
        for (int i = 0; i < 26; i++) {
            if (currentNode->child[i] != NULL) {
                dfsCount(currentNode->child[i], count);
            }
        }
    }
}

bool findPrefix(node* start, std::string& prefix, int pos) {
    if (pos == prefix.length()) return true;
    if (start -> child[prefix[pos] - 'a'] == NULL) return false;
    return findPrefix(start -> child[prefix[pos] - 'a'], prefix, pos+1);
}

node* findPtr(node* start, std::string& prefix, int pos) {
    if (pos == prefix.length()) return start;
    if (start -> child[prefix[pos] - 'a'] == NULL) return NULL;
    return findPtr(start -> child[prefix[pos] - 'a'], prefix, pos+1);
}


signed main() {
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
    // dfs(t->root);

    std::string prefix;
    std::cin >> prefix;

    int count;
    std::cin >> count;

    // std::cout << findPrefix(t->root, prefix, 0) << std::endl;

    node* prefixPtr = findPtr(t->root, prefix, 0);
    if (prefixPtr != NULL) dfsCount(prefixPtr, count);
    else std::cout << "PrefixPtr is NULL\n";
}