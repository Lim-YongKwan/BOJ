#include<iostream>
#include<vector>

using namespace std;

class Binary_tree {
	int data;
	Binary_tree* left;
	Binary_tree* right;

public:

	Binary_tree();

	Binary_tree(int);

	Binary_tree* Insert(Binary_tree*, int);

	void postorder(Binary_tree*);
};

Binary_tree::Binary_tree()
	:data(0)
	, left(NULL)
	, right(NULL)
{
}

Binary_tree::Binary_tree(int value) {
	data = value;
	left = right = NULL;
}

Binary_tree* Binary_tree::Insert(Binary_tree* root, int value) {
	if (!root) {
		return new Binary_tree(value);
	}

	if (value > root->data) {
		root->right = Insert(root->right, value);
	}
	else {
		root->left = Insert(root->left, value);
	}
	return root;
}

void Binary_tree::postorder(Binary_tree* root) {
	if (!root) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << endl;
}

int main() {

	//binary tree를 만들자.
	//node left right 

	Binary_tree b, *root =NULL;
	int n;
	while (cin>>n)
	{
		root = b.Insert(root, n);
	}
	b.postorder(root);
	return 0;
}