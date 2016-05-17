#include <iostream>

using namespace std;

class treeNode {
protected:
	treeNode *left, *right, *parent;
public:
	int value;

	treeNode(int v){value = v; left = NULL; right = NULL;}

	friend class BinarySearchTree;


};

class BinarySearchTree {
private:
	treeNode *root;
	void destroy_tree(treeNode *leaf){
		if (leaf != NULL){
			destroy_tree(leaf->left);
			destroy_tree(leaf->right);
			//destroy_tree(leaf->root);
			delete leaf;
		}
	}

	void insert_h(int key, treeNode *leaf){
		if (key < leaf->value && leaf->left != NULL){
			insert_h(key, leaf->left);
		}
		if (key < leaf->value && leaf->left == NULL){
			leaf->left = new treeNode(key);
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			leaf->left->parent = leaf;
		}
		if (key > leaf->value && leaf->right != NULL){
			insert_h(key, leaf->right);
		}
		if (key > leaf->value && leaf->right == NULL){
			leaf->right = new treeNode(key);
			leaf->right->left = NULL;
			leaf->right->right = NULL;
			leaf->right->parent = leaf;
		}
	}

	treeNode *search_h(int key, treeNode *leaf){
		if (leaf == NULL){
			return NULL;
		}
		else if (leaf->value == key){
			return leaf;
		}
		else if (key < leaf->value){
			return search_h(key, leaf->left);
		}
		else{
			return search_h(key, leaf->right);
		}
	}

	void inOrder_h(treeNode *leaf){
		if (leaf != NULL){
			inOrder_h(leaf->left);
			cout << leaf->value << endl;
			inOrder_h(leaf->right);
		}
	}
public:


	BinarySearchTree(){root = NULL;}

	~BinarySearchTree(){destroy_tree(root);}

	void insert(int key){
		if (root == NULL){
			root = new treeNode(key);
		}
		else {
			insert_h(key, root);
		}
	}

	treeNode *search(int key){search_h(key, root);}

	void remove(int key){
		int z = search_h(key, root);
		treeNode *todelete = NULL;


		if (z == NULL || z->right == NULL){
			todelete = z;
		}

		if (z->left == NULL || z->right == NULL){
			todelete = z;
		}
		else{
			todelete = successor(z);
		}

		if(todelete->left == NULL){
			z = todelete->right;
		}
		else{
			x = todelete->left;
		}

		if(x != NULL){
			x->parent = todelete->parent;
		}

		if(todelete->parent == NULL){
			root = x;
		}
		else{
			if (todelete->parent->left == todelete){
				todelete->parent->left = x;
			}
			else{
				todelete->parent->parent = x;
			}
		}
		if (z != todelete){
			z->value = todelete->value;
		}

		delete todelete;
	}

	void inOrderTraversal(){
		inOrder_h(root);
	}
};

