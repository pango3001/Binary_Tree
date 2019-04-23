#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BinaryTree {
private:
	struct TreeNode {
		char letter;
		int count;
		TreeNode *left;
		TreeNode *right;

	};

	TreeNode *root;
	
	void insert(TreeNode *&, TreeNode *&);


public:
	BinaryTree() {
		root = nullptr;
	}
	~BinaryTree() {

	}

	void showChars(TreeNode *data);

	void insertNode(char);
	//bool searchNode(char);
	//void remove();

};

void BinaryTree::insertNode(char x) {
	TreeNode *newNode = new TreeNode;
	newNode->count = 1;
	newNode->letter = x;
	newNode->left = nullptr;
	newNode->right = nullptr;

	insert(root, newNode);
}

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
	if (nodePtr == nullptr)
		nodePtr = newNode;
	if (newNode->letter == root->letter) // newNode may need to be nodePtr
		(root->count)++;
	else if (newNode->letter < nodePtr->letter)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
}

void BinaryTree::showChars(TreeNode *data) {
	cout << data->letter << ": " << data->count << endl;
	cout << data->left;
	cout << data->right;
}

int main() {
	string fileName;
	fstream file(fileName.c_str(), ios::in);
	char tempLetter;
	
	BinaryTree tree;
	while (file >> tempLetter)
	{
		tree.root = tree.insertNode(tempLetter);
	}
	tree.insertNode('a');

	tree.showChars();


	return 0;
}