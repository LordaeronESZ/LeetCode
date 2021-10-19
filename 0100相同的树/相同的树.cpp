#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = true;
        Traverse(p, q, res);
        return res;
    }
    void Traverse(TreeNode* p, TreeNode* q, bool& res) {
        if (!res)
            return;
        if (!p || !q) {
            if (p != nullptr || q != nullptr)
                res = false;
            return;
        }
        Traverse(p->left, q->left, res);
        if (p->val != q->val)
            res = false;
        Traverse(p->right, q->right, res);
    }
};
int main() {
    Solution S;
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2), new TreeNode(5));
    auto res = S.isSameTree(p, q);
    cout << res << endl;
    return 0;
}