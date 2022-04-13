#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> indMap;
    vector<int> valVec;
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (indMap.count(val))
            return false;
        indMap.emplace(val, valVec.size());
        valVec.emplace_back(val);
        return true;
    }

    bool remove(int val) {
        if (!indMap.count(val))
            return false;
        indMap[valVec.back()] = indMap[val];
        swap(valVec[indMap[val]], valVec.back());
        valVec.pop_back();
        indMap.erase(val);
        return true;
    }

    int getRandom() {
        int randomNum = rand();
        int randomInd = randomNum % valVec.size();
        return valVec[randomInd];
    }
};

int main() {
    RandomizedSet randomizedSet;
    randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
    randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    cout << randomizedSet.getRandom() << endl; // getRandom 应随机返回 1 或 2 。
    randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
    cout << randomizedSet.getRandom() << endl; // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
}