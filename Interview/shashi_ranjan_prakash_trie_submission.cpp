#include <vector>
#include <iostream>
#include <string>

struct Node {
    Node* childs[26];
    std::unordered_map<std::string, std::string> storage; 

    Node() {
        for (int i = 0; i < 26; i++) {
            childs[i] = NULL;
        }
        storage.clear();
    }
};

struct Trie {
    Node* root;

    Trie() {
        root = NULL;
    }

    void Insert(std::string name, std::string number) {
        Node* current = root;
        for (int i = 0; i < name.length(); i++) {
            if (current->childs[name[i] - 'a'] == NULL) {
                current->childs[name[i] - 'a'] = new Node();
            }
            current = current->childs[name[i] - 'a'];
        }
        current->storage[name] = number;
    }

    void DFS (Node *root, std::unordered_map<std::string, std::string>& results) {
        for (auto i: root->storage) {
            results.insert(i);
        }
        for (int i = 0; i < 26; i++) {
            DFS(root->childs[i], results);
        }
    }

    std::unordered_map<std::string, std::string> Search(std::string prefix) {
        Node* subtreeRoot = findSubtreeRoot(root, prefix);
        std::unordered_map<std::string, std::string> results;
        DFS(root, results);
        return results;
    }

    Node* findSubtreeRoot(Node* root, std::string key) {
        Node* current = root;
        for (int i = 0; i < key.length(); i++) {
            current = current->childs[key[i] - 'a'];
        }
        return current;
    }
};

int main () {

    int n = 5;
    int m = 6;

    std::cin >> n >> m;

    int p[m][n];

    // Trie* t = new Trie();
    // std::string name, number;
    // for (int i = 0; i < 5; i++){
    //     std::cin >> name >> number;
    //     t->Insert(name, number);
    // }

    // std::string prefix;
    // for (int i = 0; i < 5; i++){
    //     std::cin >> prefix;
    //     for (auto i : t->Search(prefix)) {
    //         std::cout << i.first <<  " " << i.second;
    //     }
    //     std::cout << std::endl;
    // }
}


