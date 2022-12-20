////// Searching a key on a B-tree in C++
////
////#include <iostream>
////using namespace std;
////
////class TreeNode {
////  int *keys;
////  int t;
////  TreeNode **C;
////  int n;
////  bool leaf;
////
////   public:
////  TreeNode(int temp, bool bool_leaf);
////
////  void insertNonFull(int k);
////  void splitChild(int i, TreeNode *y);
////  void traverse();
////
////  TreeNode *search(int k);
////
////  friend class BTree;
////};
////
////class BTree {
////  TreeNode *root;
////  int t;
////
////   public:
////  BTree(int temp) {
////    root = NULL;
////    t = temp;
////  }
////
////  void traverse() {
////    if (root != NULL)
////      root->traverse();
////  }
////
////  TreeNode *search(int k) {
////    return (root == NULL) ? NULL : root->search(k);
////  }
////
////  void insert(int k);
////};
////
////TreeNode::TreeNode(int t1, bool leaf1) {
////  t = t1;
////  leaf = leaf1;
////
////  keys = new int[2 * t - 1];
////  C = new TreeNode *[2 * t];
////
////  n = 0;
////}
////
////void TreeNode::traverse() {
////  int i;
////  for (i = 0; i < n; i++) {
////    if (leaf == false)
////      C[i]->traverse();
////    cout << " " << keys[i];
////  }
////
////  if (leaf == false)
////    C[i]->traverse();
////}
////
////TreeNode *TreeNode::search(int k) {
////  int i = 0;
////  while (i < n && k > keys[i])
////    i++;
////
////  if (keys[i] == k)
////    return this;
////
////  if (leaf == true)
////    return NULL;
////
////  return C[i]->search(k);
////}
////
////void BTree::insert(int k) {
////  if (root == NULL) {
////    root = new TreeNode(t, true);
////    root->keys[0] = k;
////    root->n = 1;
////  } else {
////    if (root->n == 2 * t - 1) {
////      TreeNode *s = new TreeNode(t, false);
////
////      s->C[0] = root;
////
////      s->splitChild(0, root);
////
////      int i = 0;
////      if (s->keys[0] < k)
////        i++;
////      s->C[i]->insertNonFull(k);
////
////      root = s;
////    } else
////      root->insertNonFull(k);
////  }
////}
////
////void TreeNode::insertNonFull(int k) {
////  int i = n - 1;
////
////  if (leaf == true) {
////    while (i >= 0 && keys[i] > k) {
////      keys[i + 1] = keys[i];
////      i--;
////    }
////
////    keys[i + 1] = k;
////    n = n + 1;
////  } else {
////    while (i >= 0 && keys[i] > k)
////      i--;
////
////    if (C[i + 1]->n == 2 * t - 1) {
////      splitChild(i + 1, C[i + 1]);
////
////      if (keys[i + 1] < k)
////        i++;
////    }
////    C[i + 1]->insertNonFull(k);
////  }
////}
////
////void TreeNode::splitChild(int i, TreeNode *y) {
////  TreeNode *z = new TreeNode(y->t, y->leaf);
////  z->n = t - 1;
////
////  for (int j = 0; j < t - 1; j++)
////    z->keys[j] = y->keys[j + t];
////
////  if (y->leaf == false) {
////    for (int j = 0; j < t; j++)
////      z->C[j] = y->C[j + t];
////  }
////
////  y->n = t - 1;
////  for (int j = n; j >= i + 1; j--)
////    C[j + 1] = C[j];
////
////  C[i + 1] = z;
////
////  for (int j = n - 1; j >= i; j--)
////    keys[j + 1] = keys[j];
////
////  keys[i] = y->keys[t - 1];
////  n = n + 1;
////}
////
////int main() {
////  BTree t(3);
////  t.insert(8);
////  t.insert(9);
////  t.insert(10);
////  t.insert(11);
////  t.insert(15);
////  t.insert(16);
////  t.insert(17);
////  t.insert(18);
////  t.insert(20);
////  t.insert(23);
////
////  cout << "The B-tree is: ";
////  t.traverse();
////
////  int k = 10;
////  (t.search(k) != NULL) ? cout << endl
////                 << k << " is found"
////              : cout << endl
////                 << k << " is not Found";
////
////  k = 2;
////  (t.search(k) != NULL) ? cout << endl
////                 << k << " is found"
////              : cout << endl
////                 << k << " is not Found\n";
////  system("pause");
////}
//// Inserting a key on a B-tree in C++
//
//
//
//
//
//
//
//
//
//#include <iostream>
//using namespace std;
//
//class Node {
//  int *keys; //khóa
//  int t;
//  Node **C;  // node 
//  int n;
//  bool leaf;
//
//   public:
//  Node(int _t, bool _leaf); // khởi tạo số node 
//
//  void insertNonFull(int k);
//  void splitChild(int i, Node *y);
//  void traverse();
//
//  friend class BTree;
//};
//
//class BTree {
//  Node *root;   //node gốc
//  int t;
//
//   public:
//  BTree(int _t) { // khởi tạo
//    root = NULL;
//    t = _t;
//  }
//
//  void traverse() {
//    if (root != NULL)
//      root->traverse();
//  }
//
//  void insert(int k);
//};
//
//Node::Node(int t1, bool leaf1) {
//  t = t1;
//  leaf = leaf1;
//
//  keys = new int[2 * t - 1]; // số node con tối đa 
//  C = new Node *[2 * t]; //số khóa tối đa
//
//  n = 0; // số nút của 1 node
//}
//
//// Traverse the nodes
//void Node::traverse() {
//	int i;
//	for ( i = 0; i < n; i++) {
//	if (leaf == false) // nếu k có thì next
//		C[i]->traverse();
//	cout << " " << keys[i]; // ngược lại có thì xuất
//	}
//	if (leaf == false)
//	C[i]->traverse();
//}
//
//// Insert the node
//void BTree::insert(int k) {
//  if (root == NULL) { //tree chưa có gì
//    root = new Node(t, true);
//    root->keys[0] = k;
//    root->n = 1;
//  } else {
//    if (root->n == 2 * t - 1) { //nút đã đầy, tiến hành tách
//      Node *s = new Node(t, false);
//
//      s->C[0] = root;
//
//      s->splitChild(0, root);
//
//      int i = 0;
//      if (s->keys[0] < k)
//        i++;
//      s->C[i]->insertNonFull(k);
//
//      root = s;
//    } else
//      root->insertNonFull(k);
//  }
//}
//
//// Insert non full condition
//void Node::insertNonFull(int k) {
//  int i = n - 1;
//
//  if (leaf == true) {
//    while (i >= 0 && keys[i] > k) {
//      keys[i + 1] = keys[i];
//      i--;
//    }
//
//    keys[i + 1] = k;
//    n = n + 1;
//  } else {
//    while (i >= 0 && keys[i] > k)
//      i--;
//
//    if (C[i + 1]->n == 2 * t - 1) {
//      splitChild(i + 1, C[i + 1]);
//
//      if (keys[i + 1] < k)
//        i++;
//    }
//    C[i + 1]->insertNonFull(k);
//  }
//}
//
//// split the child
//void Node::splitChild(int i, Node *y) {
//  Node *z = new Node(y->t, y->leaf);
//  z->n = t - 1;
//
//  for (int j = 0; j < t - 1; j++)
//    z->keys[j] = y->keys[j + t];
//
//  if (y->leaf == false) {
//    for (int j = 0; j < t; j++)
//      z->C[j] = y->C[j + t];
//  }
//
//  y->n = t - 1;
//  for (int j = n; j >= i + 1; j--)
//    C[j + 1] = C[j];
//
//  C[i + 1] = z;
//
//  for (int j = n - 1; j >= i; j--)
//    keys[j + 1] = keys[j];
//
//  keys[i] = y->keys[t - 1];
//  n = n + 1;
//}
//
//int main() {
//  BTree t(2);
//  t.insert(8);
//  t.insert(9);
//  t.insert(10);
//  t.insert(11);
//  t.insert(15);
//  t.insert(16);
//  t.insert(17);
//  t.insert(18);
//  t.insert(20);
//  t.insert(23);
//
//  cout << "The B-tree is: ";
//  t.traverse();
//  system("pause");
//}