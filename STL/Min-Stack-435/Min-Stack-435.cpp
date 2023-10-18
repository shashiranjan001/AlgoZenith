#include <iostream>
#include <stack>
#include <string>

struct MinStack {
    std::stack<int> main, min;

    void push (int x) {
        main.push(x);
        if (!min.size()) min.push(x);
        else if (min.top() >= x) min.push(x);
    }

    void pop () {
        if (main.size()) {
            if (main.top() == min.top()) {
                min.pop();
            }
            main.pop();
        }
    }

    int top () {
        if (main.size()) return  main.top();
        return -1;
    }

    int getMin () {
        if (main.size()) return min.top();
        return -1;
    }

};

int main () {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int q;
    std::cin >> q;
    MinStack s;
    while(q--) {
        std::string op;
        std::cin >> op;

        if(op == "push") {
            int x;
            std::cin >> x;
            s.push(x);
        }
        else if(op == "pop") {
            s.pop();
        }
        else if(op == "top") {
            std::cout << s.top() << "\n";
        }
        else if(op == "getMin") {
            std::cout << s.getMin() << "\n";
        }
    }
}