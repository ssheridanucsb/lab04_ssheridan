// intbst.cpp
// Implements class IntBST
// Samuel Sheridan August 23, 2019

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) { }

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}


// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << ' ';
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if(!n) return;
    printInOrder(n->left);
    cout << n->info << ' ';
    printInOrder(n->right);
    return;
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if(!n) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << ' ';
    return;
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
  if(n){
    return n->info + sum(n->right) + sum(n->left);
  }
    return 0; // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
  if(n){
    return 1 + count(n->right) + count(n->left);
  }
    return 0;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if(n){
      //check for value
      if(n->info == value){
        return n;
      }
      //if the value is smaller go left
      else if(n->info > value){
        return getNodeFor(value, n->left);
      }
      //if the value is larger go right
      else if(n->info < value){
        return getNodeFor(value, n->right);
      }

      }
    return 0; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if(getNodeFor(value, root)) return true;
    return false;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
  Node *n = getNodeFor(value, root);
  if(n==0 || root==0) return 0;
  //if theres a left node get the max of tree
  if(n->left){
    if(n->left->right==0) return n->left;

    n=n->left->right;
    while(n->right){
      n = n->right;
    }
    return n;
  }
  else{
    Node *t = n->parent;
    while(t && t->info >= value){
      t = t->parent;
    }
    return t;
  }

  }





// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
  if(!contains(value)) return 0;
  Node *n = getPredecessorNode(value);
  if(!n) return 0;
  return n->info;

}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
  Node *n = getNodeFor(value, root);
  if(n==0 || root==0) return 0;

  if(n->right){
    if(n->right->left==0) return n->right;

    n=n->right->left;
    while(n->left){
      n = n->left;
    }
    return n;
  }
  else{
    Node *t = n->parent;
    while(t && t->info <= value){
      t=t->parent;
    }
    return t;
  }
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
  if(!contains(value)) return 0;
  Node* n = getSuccessorNode(value);
  if(!n) return 0;
  return n->info;


}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    if(!contains(value)) return false;
    if(root->info==value && root->right==0 && root->left==0){
      delete root;
      root=0;
    }
    remove(value, root);
    return true;
}

IntBST::Node* IntBST::remove(int value, Node* p){
  if(!p) return 0;
  //search for the node
  Node* n = getNodeFor(value, p);

  //if the node is a leaf delete the leaf
  if(n->right==0 && n->left==0){
    //if its the right child;
    if(n->parent->right==n){
      n->parent->right=0;
    }
    //if its the left child
    else{
      n->parent->left=0;
    }
    delete n;
    return 0;

  }
  //if the node has 1 child bypass the child
  else if(n->right==0 || n->left==0){
    //if no right child
    if(n->right==0){
      if(n->parent->info > value){
        n->parent->left = n->left;
      }
      else{
        n->parent->right = n->left;
      }
    }
    //if no left child
    else{
      if(n->parent->info > value){
        n->parent->left = n->right;
        }
      else{
        n->parent->right = n->right;
        }
      }


    delete n;
    return 0;
  }
  //if the node has 2 children replace with its successor
  else{
    int s = getSuccessor(value);
    n->info = s;
    remove(s, n->right);
  }

}
