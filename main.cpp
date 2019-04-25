#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BinaryTree {
private:
    struct TreeNode {
        string letter;
        int count;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root;

    void insert(TreeNode *,TreeNode *&);


public:
    BinaryTree() {
        root = nullptr;
    }
    ~BinaryTree(){delete root;};
    void showChars();
    void showChars(TreeNode *data);
    void insertNode(string);
    void displayInOrder(TreeNode *) const;

};

void BinaryTree::insertNode(string x) {
    TreeNode *newNode = new TreeNode;
    newNode->count = 1;
    newNode->letter = x;
    newNode->left = nullptr;
    newNode->right = nullptr;
    insert(newNode, root);
}

void BinaryTree::insert(TreeNode *newNode,TreeNode *&temp ) {
    if (temp == nullptr){
        temp = newNode;
    }
    else if (newNode->letter == temp->letter){
        (temp->count)++;
    }
    else if (newNode->letter < temp->letter){
        insert(newNode,temp->left);
    }
    else{
        insert(newNode,temp->right);
    }
}

void BinaryTree::showChars(){
    displayInOrder(root);
}
void BinaryTree::showChars(TreeNode *data) {
    if (data !=nullptr){
        cout << "showing root: ";
    cout << data->letter << ": " << data->count << endl;
    }
    if(data->left != nullptr){
        cout << "showing left: ";
        showChars(data->left);
    }
    if(data->right != nullptr){
        cout << "showing right: ";
        showChars(data->right);
    }
    else
        cout << "Tree is empty" << endl;
}

void BinaryTree::displayInOrder(TreeNode *nodePtr)const {
    if(nodePtr){
        displayInOrder(nodePtr->left);
        cout << nodePtr->letter <<": " << nodePtr->count << endl;
        displayInOrder(nodePtr->right);
    }
}

string getFile();

int main() {
    BinaryTree tree;
    string fileName = "test.txt";
    ifstream file(fileName.c_str());
    string line;
    string singleLine;
    if (file.is_open()){
        while (getline(file,line)){
            cout << line << endl;
            for (unsigned int i = 0; i < line.length(); i++){
                if(isalpha(line[i])){
                singleLine += line[i];
                }
            }
        }
    }
    else
        cout << "Error opening file" << endl;
    cout << singleLine << endl;
    file.close();
    line = singleLine;
    for (unsigned int i = 0; i < line.length(); i++){
        if (isalpha(line[i])){
                char x = tolower(line[i]);
                string s(1,x);
                tree.insertNode(s);
        }
    }
    for (unsigned int i = 0; i < line.length(); i++){
        if (isalpha(line[i]) && (line[i] == line[i+1])){
                char x = tolower(line[i]);
                string s(1,x);
                string sa;
                int j = 1;
                while(line[i] == line[i+j]){
                j++;
                sa += s;
                }
                tree.insertNode(s + sa);
        }
    }    
    tree.showChars();

    //delete tree;
    return 0;
}

    string getFile(){
        cout << "Which file would you like to choose?" << endl;
        string x;
        cin >> x;
        return x;
    }
