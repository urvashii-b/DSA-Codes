#include<bits/stdc++.h>
using namespace std;

// conditions for BST: (1) left < node < right, (2) left subtree -> BST, (3) right subtree -> BST
// inorder traversal of BST prints it in ascending order
// generally duplicates not allowed
// why BST? not a degenerate tree -> mostly O(logn) {height of BST}

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// compare root value with desired value
TreeNode* searchBST(TreeNode* root, int val) {
    while(root!=NULL && root->val!=val) {
        root=root->val > val? root->left: root->right;
    }
    return root;
}

// traverse the root till the left most node 
int minVal(TreeNode* root){
	
	if(root==NULL) return -1;
	while(root->left){
		root=root->left;
	}
	return root->val;	
}

// traverse the root till the right most node 
int maxVal(TreeNode* root){
	
	if(root==NULL) return -1;
	while(root->right){
		root=root->right;
	}
	return root->val;	
}

// insertion
TreeNode* insert(){



}

int main(){
    return 0;
}