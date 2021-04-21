#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void Traversal(TreeNode *root, vector<int>& v){
        if(root->left!=nullptr){
            Traversal(root->left,v);
        }
        v.emplace_back(root->val);
        if(root->right!=nullptr){
            Traversal(root->right,v);
        }
    }

vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root!=nullptr){
            Traversal(root,ans);
        }
        return ans;
}
int main(int argc, char const *argv[]) {
    TreeNode root=TreeNode(0);
    vector<int>ans=inorderTraversal(&root);
    cout<<ans[0]<<endl;
    return 0;
}
