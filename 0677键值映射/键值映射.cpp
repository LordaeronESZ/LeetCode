#include<iostream>
#include<string>
#include<vector>
using namespace std;
class MapSum {
private:
    vector<vector<pair<string, int>>> myMap;
public:
    MapSum() {
        myMap.resize(26);
    }

    void insert(string key, int val) {
        int index = key.front() - 'a';
        int i = 0;
        while (i < myMap[index].size()) {
            if (myMap[index][i].first == key) {
                myMap[index][i].second = val;
                break;
            }
            i++;
        }
        if(i == myMap[index].size())
            myMap[index].emplace_back(make_pair(key, val));
    }

    int sum(string prefix) {
        int res = 0;
        int index = prefix.front() - 'a';
        for (int i = 0; i < myMap[index].size(); i++) {
            if (prefix.size() > myMap[index][i].first.size())
                continue;
            int j = 0;
            for (; j < prefix.size(); j++) {
                if (myMap[index][i].first[j] != prefix[j])
                    break;
            }
            if (j == prefix.size())
                res += myMap[index][i].second;
        }
        return res;
    }
};
int main() {
    MapSum* mapSum = new MapSum();
    mapSum->insert("apple", 3);
    cout << mapSum->sum("ap") << endl;           // return 3 (apple = 3)
    mapSum->insert("app", 2);
    mapSum->insert("apple", 2);
    cout << mapSum->sum("ap") << endl;           // return 5 (apple + app = 3 + 2 = 5)
    return 0;
}