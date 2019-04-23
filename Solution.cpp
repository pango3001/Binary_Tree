#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct node
{
	char data;
	int count;
	node * left;
	node *right;
};

//to create a new node 
node* create_node(char ch)
{
	node *new_node = new node;
	new_node->data = ch;
	new_node->count = 1;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

//function to insert a data in new node
node * insert_data(node *root, char ch)
{
	if (root == NULL) {
		return create_node(ch);
	}

	if (ch == root->data) {
		(root->count)++;
		return root;
	}

	if (ch<root->data)
		root->left = insert_data(root->left, ch);
	else
		root->right = insert_data(root->right, ch);

	return root;
}

//preorder traversal of BST(binary search tree)
void display(node* temp)
{
	if (temp == NULL)
		return;
	cout << temp->data << " ";
	cout << temp->count << endl;
	display(temp->left);
	display(temp->right);
}

int main()
{
	string file_name; char ch;
	cout << "enter file name\n";
	cin >> file_name;
	fstream file(file_name.c_str(), ios::in);
	node* root;
	root = NULL;
	//reading characters from a file
	while (file >> ch)
	{
		root = insert_data(root, ch);
	}

	file.close();
	display(root);
	return 0;
}