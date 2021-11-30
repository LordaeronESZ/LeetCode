#include<iostream>
#include<vector>
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
private:
    vector<int> targetVec;
public:
    void preorderTraversal(TreeNode* root) {
        if (!root)
            return;
        preorderTraversal(root->left);
        targetVec.emplace_back(root->val);
        preorderTraversal(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        preorderTraversal(root);
        int l = 0, r = targetVec.size() - 1;
        while (l < r) {
            if (targetVec[l] + targetVec[r] == k)
                return true;
            else if (targetVec[l] + targetVec[r] < k)
                l++;
            else
                r--;
        }
        return false;
    }
};
int main() {
    Solution S;
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    int k = 4;
    auto res = S.findTarget(root, k);
    cout << res << endl;
    return 0;
}