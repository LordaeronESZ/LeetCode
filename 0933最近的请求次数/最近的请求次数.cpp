#include<iostream>
#include<queue>
using namespace std;

class RecentCounter {
private:
    queue<int> Q;
public:
    RecentCounter() {

    }

    int ping(int t) {
        Q.emplace(t);
        while (t - Q.front() > 3000) {
            Q.pop();
        }
        return Q.size();
    }
};

int main() {
    RecentCounter recentCounter;
    cout << recentCounter.ping(1) << endl;     // requests = [1]����Χ�� [-2999,1]������ 1
    cout << recentCounter.ping(100) << endl;   // requests = [1, 100]����Χ�� [-2900,100]������ 2
    cout << recentCounter.ping(3001) << endl;  // requests = [1, 100, 3001]����Χ�� [1,3001]������ 3
    cout << recentCounter.ping(3002) << endl;  // requests = [1, 100, 3001, 3002]����Χ�� [2,3002]������ 3
}