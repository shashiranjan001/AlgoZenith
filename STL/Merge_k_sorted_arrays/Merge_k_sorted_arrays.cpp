#include <vector>
#include <iostream>
#include <queue>

int main () {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int> > input(n, std::vector<int>(m));
	for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m;  ++j) {
            std::cin >> input[i][j];
        }
    }
    std::vector<int> answer;
    std::priority_queue<std::pair<int, int> > pq;
    for (int i = 0; i < n; ++i) {
	    pq.push(std::make_pair(0-input[i][0], i));
    }
    std::vector<int> pointers(n, 0);
    while (pq.size()) {
	    std::pair<int, int> topElement = pq.top();
	    pq.pop();
	    answer.push_back(0-topElement.first);
	    pointers[topElement.second]++;
	    if (pointers[topElement.second] < m) {
		    pq.push(std::make_pair(0-input[topElement.second][pointers[topElement.second]], topElement.second));
	    }
    }
    for (auto it: answer) {
        std::cout << it << std::endl;
    }
}
