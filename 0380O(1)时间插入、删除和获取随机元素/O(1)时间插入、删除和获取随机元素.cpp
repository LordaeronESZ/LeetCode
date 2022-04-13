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
    randomizedSet.insert(1); // �򼯺��в��� 1 ������ true ��ʾ 1 ���ɹ��ز��롣
    randomizedSet.remove(2); // ���� false ����ʾ�����в����� 2 ��
    randomizedSet.insert(2); // �򼯺��в��� 2 ������ true ���������ڰ��� [1,2] ��
    cout << randomizedSet.getRandom() << endl; // getRandom Ӧ������� 1 �� 2 ��
    randomizedSet.remove(1); // �Ӽ������Ƴ� 1 ������ true ���������ڰ��� [2] ��
    randomizedSet.insert(2); // 2 ���ڼ����У����Է��� false ��
    cout << randomizedSet.getRandom() << endl; // ���� 2 �Ǽ�����Ψһ�����֣�getRandom ���Ƿ��� 2 ��
}