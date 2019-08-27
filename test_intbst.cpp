#include "intbst.h"

#include <iostream>
using namespace std;


int main(){

  IntBST testTree;
  testTree.insert(5);
  testTree.insert(9);
  testTree.insert(10);
  testTree.insert(8);
  testTree.insert(6);
  testTree.insert(7);
  testTree.insert(2);
  testTree.insert(1);
  testTree.insert(3);
  testTree.insert(4);

  cout << "Correct In Order: 1 2 3 4 5 6 7 8 9 10" << endl;
  cout << "Pre Order: ";
  testTree.printPreOrder();
  cout << endl;
  cout << "In Order: ";
  testTree.printInOrder();
  cout << endl;
  cout << "Post Order: ";
  testTree.printPostOrder();
  cout << endl;
  //test contains
  if(testTree.contains(3) && !testTree.contains(11)){
    cout << "contains passed" << endl;
  }
  else{
    cout << "contains failed" << endl;
  }

  cout << "Sum: " << testTree.sum() << endl;
  cout << "Count: " << testTree.count() << endl;

  cout << "predecessor to 10: " << testTree.getPredecessor(10) << endl;
  cout <<  "successor to 10: " << testTree.getSuccessor(10) << endl;
  cout << "predecessor to 9: " << testTree.getPredecessor(9) << endl;
  cout <<  "successor to 9: " << testTree.getSuccessor(9) << endl;
  cout << "predecessor to 8: " << testTree.getPredecessor(8) << endl;
  cout <<  "successor to 8: " << testTree.getSuccessor(8) << endl;
  cout << "predecessor to 7: " << testTree.getPredecessor(7) << endl;
  cout <<  "successor to 7: " << testTree.getSuccessor(7) << endl;
  cout << "predecessor to 6: " << testTree.getPredecessor(6) << endl;
  cout <<  "successor to 6: " << testTree.getSuccessor(6) << endl;
  cout << "predecessor to 5: " << testTree.getPredecessor(5) << endl;
  cout <<  "successor to 5: " << testTree.getSuccessor(5) << endl;
  cout << "predecessor to 4: " << testTree.getPredecessor(4) << endl;
  cout <<  "successor to 4: " << testTree.getSuccessor(4) << endl;
  cout << "predecessor to 3: " << testTree.getPredecessor(3) << endl;
  cout <<  "successor to 3: " << testTree.getSuccessor(3) << endl;
  cout << "predecessor to 2: " << testTree.getPredecessor(2) << endl;
  cout <<  "successor to 2: " << testTree.getSuccessor(2) << endl;
  cout << "predecessor to 1: " << testTree.getPredecessor(1) << endl;
  cout <<  "successor to 1: " << testTree.getSuccessor(1) << endl;

  //remove root test;
  cout << "Removing the root i.e. 5" << endl;
  testTree.remove(5);
  cout << "new pre order: ";
  testTree.printPreOrder();
  cout << endl;

  //remove a a leaf;
  cout << "Removing a leaf i.e  1" << endl;
  testTree.remove(1);
  testTree.printPreOrder();
  cout << endl;

  //remove a node with two children
  cout << "Removing a node with two children i.e 9" << endl;
  testTree.remove(9);
  testTree.printPreOrder();
  cout<<endl;




  return 0;
}
