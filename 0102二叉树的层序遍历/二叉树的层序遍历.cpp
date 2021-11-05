#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> res;
        if (root)
            Q.push(root);
        while (!Q.empty()) {
            int currentLevel = Q.size();
            res.emplace_back(vector<int>());
            for (int i = 0; i < currentLevel; i++) {
                root = Q.front();
                Q.pop();
                res.back().emplace_back(root->val);
                if (root->left)
                    Q.push(root->left);
                if (root->right)
                    Q.push(root->right);
            }
        }
        return res;
    }
};
int main() {
    Solution S;
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    auto res = S.levelOrder(root);
    for (const auto& re : res) {
        for (const auto& r : re) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}