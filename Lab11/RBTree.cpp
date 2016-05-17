#include <iostream>

using namespace std;

enum RBcolor{Red; Black};

class RBTreeNode
{
protected:
	RBTreeNode *left, *right, *parent;
	RBcolor color;
public:
	RBTree(){color = Red};

	friend class RBrecordDict;
	
};

int grandParent(RBTreeNode *n){
	if (n = NULL || n->parent== NULL){
		return NULL;
	}
	else {
		return n->parent->parent;
	}
}

int uncle(RBTreeNode *n){
	g = grandParent(n);
	if (g == NULL){
		return NULL;
	}
	else if (n->parent=g->left){
		return g->right;
	}
	else {
		return g->left;
	}
}

int sibling(RBTreeNode *n){
	if (n->parent == NULL){
		return NULL;
	}
	else if (n==n->parent->left){
		return n->parent->left;
	}
	else {
		return n->parent->left;
	}
}

RBcolor color(RBTreeNode *n){
	if (n==NULL){
		return Black;
	}
	else{
		return n->color;
	}
}

void insert(record *in){
	if (root==NULL){
		root = new RBTreeNode(in);
		insert_fixup(root);
	}
	else{
		insert_h(in, root);
	}
}

void insert_h(record *in, RBTreeNode *n){
	if (data(n) > in){
		if(n->left == NULL){
			n->left = new RBTreeNode(in, n);
			insert_fixup(n->left);
		}
		else{
			insert_h(in, n->left);
		}
	}
	else{
		if(n->right == NULL){
			n->right = new RBTreeNode(in, n);
			insert_fixup(n->right);
		}
		else{
			insert_h(in, n->right);
		}
	}
}