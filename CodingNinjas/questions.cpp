    template <typename T>
    class BinaryTreeNode {
    public :
	    T data;
	    BinaryTreeNode<T> *left;
	    BinaryTreeNode<T> *right;

	    BinaryTreeNode(T data) {
	        this -> data = data;
	        left = NULL;
	        right = NULL;
	    }
    };

// Lowest Common Ancestor
BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    if(root==nullptr || root->data==node1 || root->data==node2 || root->data==node3 ){
		return root;
	}
	BinaryTreeNode<int>* left = lcaOfThreeNodes(root->left,node1,node2,node3);
	BinaryTreeNode<int>* right = lcaOfThreeNodes(root->right,node1,node2,node3);

	if(left==nullptr){
		return right;
	}
	else if(right==nullptr){
		return left;
	}
	else{
		return root;
	}
}
