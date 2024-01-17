#include<bits/stdc++.h>
using namespace std;

// Types of Binary Trees: 
// (1) Full Binary Tree - 0 or 2 children
// (2) Complete Binary Tree - all levels filled except last, last level nodes are as left as possible
// (3) Perfect Binary Tree - all leaf nodes at the same level
// (4) Balanced Binary Tree - height of tree is at log(n)
// (5) Degenerate Binary Tree - skew tree

// representation in C++ using pointers

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left= right = NULL;
    }
};

// traversal techniques: BFS-> level order / DFS-> inorder, preorder, postorder
/*
            A
           / \
          B   C
         / \ / \
        D  E F  G

BFS: A B C D E F G

PreOrder (root left right): A B D E C F G 

InOrder (left root right): D B E A F C G

PostOrder (left right root): D E B F G C A
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(Node* root) {
        if(root!=NULL){
            res.push_back(root->data);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
    }

    vector<int> inorderTraversal(Node* root) {
        if(root!=NULL){
            inorderTraversal(root->left);
            res.push_back(root->data);
            inorderTraversal(root->right);
        }
        return res;
    }

    vector<int> postorderTraversal(Node* root) {
        if(root!=NULL){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            res.push_back(root->data);
        }
        return res;
    }
   
};

vector<vector<int>> levelorderTraversal(Node* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);
    if(!q.empty()){
        vector<int> level;
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            if(node->left!=NULL){q.push(node->left);}
            if(node->right!=NULL){q.push(node->right);}
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> result = levelorderTraversal(root);

    /*  5
       / \
      2   7
    */

    return 0;
}