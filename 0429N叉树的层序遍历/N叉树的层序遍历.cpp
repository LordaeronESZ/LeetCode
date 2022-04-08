#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    void search(vector<vector<int>>& res, Node* node, int depth) {
        if (!node)
            return;
        while (res.size() <= depth)
            res.emplace_back(vector<int>());
        res[depth].emplace_back(node->val);
        for (int i = 0; i < node->children.size(); ++i) {
            search(res, node->children[i], depth + 1);
        }

    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        search(res, root, 0);
        return res;
    }
};
int main() {
    Node* node31 = new Node(5);
    Node* node32 = new Node(6);
    Node* node21 = new Node(3, { node31, node32 });
    Node* node22 = new Node(2);
    Node* node23 = new Node(4);
    Node* root = new Node(1, { node21, node22, node23 });
    Solution S;
    auto res = S.levelOrder(root);
    for (const auto& re : res) {
        for (const auto& r : re) {
            cout << r << " ";
        }
        cout << endl;
    }
}