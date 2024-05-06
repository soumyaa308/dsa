#include<iostream>
using namespace std;

class node {
     public:
         int data;
         node *left;
         node *right;
};

class Bst {
public:
        node *root;
    Bst () {
        root = NULL;
    }
    void create ();
    void insert ();
    void postorder (node*);
    void inorder (node*);
    void preorder (node*);
    void search (int key);
    void minimum ();
    int height (node*);
    void mirror (node*);
};

void Bst::create () {
    int ans;
    cout << "\nEnter number of keys to insert: ";
    cin >> ans;
    cout << '\n';
    while (ans--)
        insert();
}

void Bst::inorder (node *root) {
    if (root != NULL) {
        inorder (root -> left);
        cout << " -> " << root -> data;
        inorder (root -> right);
    }
}

void Bst::preorder (node *root) {
    if (root != NULL) {
        cout << " -> " << root -> data;
        preorder (root -> left);
        preorder (root -> right);
    }
}

void Bst::postorder (node *root) {
    if (root != NULL) {
        postorder (root -> left);
        postorder (root -> right);
        cout << " -> " << root -> data;
    }
}

void Bst::insert () {
    node *curr,*temp;
    cout << "Enter data: ";
    curr = new node;
    cin >> curr -> data;
    curr -> left = curr -> right = NULL;

    if (root == NULL)
        root = curr;

    else {
        temp = root;
        while (1) {
            if (curr -> data <= temp -> data) {
                if (temp -> left == NULL) {
                    temp -> left = curr;
                    break;
                }
                else
                    temp = temp -> left;
            }
            else {
                if (temp -> right == NULL) {
                    temp -> right = curr;
                    break;
                }
                else
                    temp = temp -> right;
            }
        }
    }
}

void Bst::search (int key) {
    node *curr;
    curr = root;

    while (curr != NULL) {
        if (curr -> data == key) {
            cout << key << " found";
            break;
        }
        else {
            if (key<curr -> data)
                curr = curr -> left;
            else
                curr = curr -> right;
        }
    }
    if (curr == NULL)
        cout << key << " not found";
}

void Bst::minimum () {
    node *temp = root;
    int min;
    while (temp -> left != NULL) {
        min = temp -> data;
        temp = temp -> left;
        if (temp -> data<min)
            min = temp -> data;
        else
            temp = temp -> left;
    }
    cout << "\nMinimum number is: " << min;
}

int Bst::height (node *root) {
    if (root == NULL)
        return 0;

    else {
        if (height (root -> right) > height (root -> left))
            return (1 + height (root -> right));

        else
            return (1 + height (root -> left));
    }
}

void Bst::mirror (node *root) {
    if (root == NULL)
        return;

    else {
        mirror(root -> left);
        mirror(root -> right);
        swap(root -> left, root -> right);
    }
}

int main () {
    Bst b;
    int key,ch;
    do {
        cout << "\n\n1.Create 2.Insert  3.Search 4.Minimum 5.Height 6.Mirror\n";
        cout << "Your choice [1/2/3/4/5/6] ";
        cin >> ch;
        switch (ch) {
            case 1:
                b.create ();
                break;
            case 2:
                cout << '\n';
                b.insert ();
                break;
//            case 3:
//                cout << "\nInorder   traversal is:";
//                b.inorder (b.root);
//                break;
//            case 4:
//                cout << "\nPreorder  traversal is:";
//                b.preorder (b.root);
//                break;
//            case 5:
//                cout << "\nPostorder traversal is:";
//                b.postorder (b.root);
//                break;
            case 3:
                cout << "\nEnter search key: ";
                cin >> key;
                b.search (key);
                break;
            case 4:
                b.minimum ();
                break;
            case 5:
                cout << "\nHeight of tree: " << b.height (b.root);
                break;
            case 6:
                b.mirror (b.root);
                cout << "\nTree is now mirrored!!!"
                     << "\nInorder   traversal is:";
                b.inorder (b.root);
                cout << "\nPreorder  traversal is:";
                b.preorder (b.root);
                cout << "\nPostorder traversal is:";
                b.postorder (b.root);
                break;
        }
    }while (ch < 10);
    return 0;
}

This C++ code implements a Binary Search Tree (BST) along with various operations such as insertion, searching, finding the minimum element, calculating the height of the tree, and mirroring the tree.

Here's a breakdown of the main components and operations:

node Class: Represents a node in the binary search tree. Each node contains integer data, a pointer to the left child, and a pointer to the right child.
Bst Class: Implements the binary search tree functionality. It includes methods for creating the tree, inserting nodes, traversing the tree in inorder, preorder, and postorder, searching for a key, finding the minimum element, calculating the height of the tree, and mirroring the tree.
create(): Creates the binary search tree by inserting a specified number of keys into the tree.
insert(): Inserts a new node into the binary search tree based on the value of the node's data.
search(): Searches for a key in the binary search tree and prints whether the key is found or not.
minimum(): Finds and prints the minimum element in the binary search tree.
height(): Calculates and returns the height of the binary search tree.
mirror(): Mirrors the binary search tree by swapping the left and right children of each node.
main(): Implements the main program flow, where the user can choose from various operations to perform on the binary search tree using a menu-driven interface.


