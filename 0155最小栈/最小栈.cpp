#include<iostream>
#include<vector>
using namespace std;
class MinStack {
private:
    vector<int> V;
    int minValue;
public:
    MinStack() {
        minValue = INT32_MAX;
    }

    void push(int val) {
        if (val < minValue)
            minValue = val;
        V.emplace_back(val);
    }

    void pop() {
        int temp = V.back();
        V.erase(V.end() - 1);
        if (temp == minValue) {
            minValue = INT32_MAX;
            for (const auto& e : V) {
                if (e < minValue)
                    minValue = e;
            }
        }
    }

    int top() {
        return V.back();
    }

    int getMin() {
        return minValue;
    }
};
int main() {
    MinStack MS;
    MS.push(2147483646);
    MS.push(2147483646);
    MS.push(2147483647);
    cout << MS.top() << endl;
    MS.pop();
    cout << MS.getMin() << endl;
    MS.pop();
    cout << MS.getMin() << endl;
    MS.pop();
    MS.push(2147483647);
    cout << MS.top() << endl;
    cout << MS.getMin() << endl;
    MS.push(-2147483648);
    cout << MS.top() << endl;
    cout << MS.getMin() << endl;
    MS.pop();
    cout << MS.getMin() << endl;
    return 0;
}