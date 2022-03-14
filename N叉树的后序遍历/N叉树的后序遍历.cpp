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
    void postorderTraversal(vector<int>& res, Node* root) {
        if (!root)
            return;
        for (const auto& r : root->children) {
            postorderTraversal(res, r);
        }
        res.emplace_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorderTraversal(res, root);
        return res;
    }
};
int main() {
    Solution S;
    Node* root = new Node(1);
    Node* node21 = new Node(3);
    Node* node22 = new Node(2);
    Node* node23 = new Node(4);
    Node* node31 = new Node(5);
    Node* node32 = new Node(6);
    vector<Node*> nodev3 = { node31, node32 };
    node21->children = nodev3;
    vector<Node*> nodev2 = { node21, node22, node23 };
    root->children = nodev2;
    auto res = S.postorder(root);
    for (const auto& re : res) {
        cout << re << " ";
    }
    return 0;
}