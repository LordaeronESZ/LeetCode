#include<iostream>
#include<vector>
using namespace std;

class NumArray {
private:
    vector<int> segmentTree;
    int n;

    void build(int node, int s, int e, vector<int>& nums) {
        if (s == e) {
            segmentTree[node] = nums[s];
            return;
        }
        int m = s + (e - s) / 2;
        build(node * 2 + 1, s, m, nums);
        build(node * 2 + 2, m + 1, e, nums);
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
    }

    void change(int index, int val, int node, int s, int e) {
        if (s == e) {
            segmentTree[node] = val;
            return;
        }
        int m = s + (e - s) / 2;
        if (index <= m) {
            change(index, val, node * 2 + 1, s, m);
        }
        else {
            change(index, val, node * 2 + 2, m + 1, e);
        }
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
    }

    int range(int left, int right, int node, int s, int e) {
        if (left == s && right == e) {
            return segmentTree[node];
        }
        int m = s + (e - s) / 2;
        if (right <= m) {
            return range(left, right, node * 2 + 1, s, m);
        }
        else if (left > m) {
            return range(left, right, node * 2 + 2, m + 1, e);
        }
        else {
            return range(left, m, node * 2 + 1, s, m) + range(m + 1, right, node * 2 + 2, m + 1, e);
        }
    }

public:
    NumArray(vector<int>& nums) : n(nums.size()), segmentTree(nums.size() * 4) {
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        change(index, val, 0, 0, n - 1);
    }

    int sumRange(int left, int right) {
        return range(left, right, 0, 0, n - 1);
    }
};

int main() {
    vector<int> nums = { 1, 3, 5 };
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl; // ·µ»Ø 1 + 3 + 5 = 9
    numArray.update(1, 2);   // nums = [1,2,5]
    cout << numArray.sumRange(0, 2) << endl; // ·µ»Ø 1 + 2 + 5 = 8
}