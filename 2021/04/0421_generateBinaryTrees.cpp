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


vector<TreeNode *> generate(int left,int right){
    vector<TreeNode *>ans;
    if(left>right){
        ans.push_back(nullptr);
        return ans;
    }
    for(int i=left;i<=right;i++){
        vector<TreeNode *>left_nodes=generate(left,i-1);
        vector<TreeNode *>right_nodes=generate(i+1,right);
        for(TreeNode *left_node:left_nodes){
            for(TreeNode *right_node:right_nodes){
                TreeNode *t=new TreeNode(i);
                t->left=left_node;
                t->right=right_node;
                ans.push_back(t);
            }
        }
    }
    return ans;
}

vector<TreeNode*> generateTrees(int n) {
    if(n)
        return generate(1,n);
    else
        return vector<TreeNode *>{};
}

int main(int argc, char const *argv[]) {
    int n;
    while(cin>>n){
        vector<TreeNode *>ans=generateTrees(n);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
