#include<iostream>
#include<string>
#include<unordered_map>
#include<list>
using namespace std;

class AllOne {
private:
    unordered_map<string, int> strCnt;
public:
    AllOne() {
        
    }

    void inc(string key) {
        ++strCnt[key];
    }

    void dec(string key) {
        --strCnt[key];
        if (!strCnt[key])
            strCnt.erase(key);
    }

    string getMaxKey() {
        int maxVal = INT32_MIN;
        string maxKey("");
        for (const auto& p : strCnt) {
            if (p.second > maxVal) {
                maxKey = p.first;
                maxVal = p.second;
            }
        }
        return maxKey;
    }

    string getMinKey() {
        int minVal = INT32_MAX;
        string minKey("");
        for (const auto& p : strCnt) {
            if (p.second < minVal) {
                minKey = p.first;
                minVal = p.second;
            }
        }
        return minKey;
    }
};
int main() {
    AllOne allOne;
    allOne.inc("hello");
    allOne.inc("hello");
    cout << allOne.getMaxKey() << endl; // 返回 "hello"
    cout << allOne.getMinKey() << endl; // 返回 "hello"
    allOne.inc("leet");
    cout << allOne.getMaxKey() << endl; // 返回 "hello"
    cout << allOne.getMinKey() << endl; // 返回 "leet"
    return 0;
}