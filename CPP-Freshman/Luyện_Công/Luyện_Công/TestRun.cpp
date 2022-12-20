//#include<iostream>
//using namespace std;
//class Node
//{
//	int *keys;
//	int t;
//	Node** C;
//	int n;
//	bool leaf;
//
//public:
//	Node( int _t, bool _leaf );
//	void InsertNonFull( int k );
//	void splitChild( int i, Node* y);
//	void traverse();
//
//	friend class BTree;
//};
//class BTree{
//	Node *root;
//	int t;
//
//public:
//	BTree( int _t ){ //init
//		root = NULL;
//		t = _t;
//	}
//	void traverse(){
//		if( root != NULL )
//			root->traverse();
//	}
//	void Insert(int k);
//};
//Node::Node( int t1, bool leaf1 ){
//	t = t1;
//	leaf = leaf1;
//
//	keys = new int[2*t-1];
//	C = new Node*[2*t];
//	n = 0;
//}
//void Node::traverse(){
//	int i;
//	for( i = 0; i < n; i++ ){
//		if( leaf == false )
//			C[i]->traverse();
//		cout << "   " << keys[i];
//	}
//	if( leaf == false )
//		C[i]->traverse();
//}
//void BTree::Insert( int k ){
//	if( root == NULL ){
//		root = new Node( t,true );
//		root->keys[0] = k;
//		root->n = 1;
//	}
//	else
//		if( root->n == 2*t -1 ){
//			Node* S = new Node(t,false);
//			S->C[0] = root;
//			S->splitChild(0,root);
//			int  i = 0;
//			if( S->keys[0] < k )
//				i++;
//			S->C[i]->InsertNonFull(k);
//			root = S;
//		}
//		else
//			root->InsertNonFull(k);
//}
//void Node::InsertNonFull(int k) {
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
//    C[i + 1]->InsertNonFull(k);
//  }
//}
//
//// split the child
//void Node::splitChild(int i, Node *y) {
//	Node *z = new Node(y->t, y->leaf);
//	z->n = t - 1;
//
//	for (int j = 0; j < t - 1; j++)
//	z->keys[j] = y->keys[j + t];
//
//	if (y->leaf == false) {
//	for (int j = 0; j < t; j++)
//		z->C[j] = y->C[j + t];
//	}
//
//	y->n = t - 1;
//	for (int j = n; j >= i + 1; j--)
//	C[j + 1] = C[j];
//
//	C[i + 1] = z;
//
//	for (int j = n - 1; j >= i; j--)
//	keys[j + 1] = keys[j];
//
//	keys[i] = y->keys[t - 1];
//	n = n + 1;
//}
//int main()
//{
//	BTree t(2);
//	t.Insert(8);
//	t.Insert(9);
//	t.Insert(10);
//	t.Insert(11);
//	t.Insert(15);
//	t.Insert(16);
//	t.Insert(17);
//	t.Insert(18);
//	t.Insert(20);
//	t.Insert(23);
//
//	cout << "The B-tree is: ";
//	t.traverse();
//	system("pause");
//}