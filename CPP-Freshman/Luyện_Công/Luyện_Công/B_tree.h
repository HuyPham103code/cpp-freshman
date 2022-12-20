//#pragma once
//#include<iostream>
//using namespace std;
//struct Node {
//	int info;
//	Node* left, * right;
//};
//struct Tree {
//	Node* root;
//	void init() {
//		root = NULL;
//	}
//	void InsertNode(Node*& p, int x) {
//		if (p == NULL) {
//			p = new Node;
//			p->info = x;
//			p->left = p->right = NULL;
//		}
//		else {
//			if (p->info == x) return;
//			else if (p->info > x)
//				return InsertNode(p->left, x);
//			else
//				return InsertNode(p->right, x);
//		}
//	}
//	void InsertNodes() {
//		init();
//		int x;
//		do {
//			cout << "Nhap x:";
//			cin >> x;
//			if (x > 0) InsertNode(root, x);
//		} while (x != 0);
//	}
//	void InsertFromArr() {
//		int a[12] = { 40, 20, 50, 10, 25, 43, 53, 6, 15, 30, 47, 60 };
//		for (int i = 0; i < 12; i++)
//			InsertNode(root, a[i]);
//	}
//	void Traverse() {
//		cout << "Duyet LNR: ";
//		LNR(root);
//		cout << endl;
//		cout << "Duyet NLR: ";
//		NLR(root);
//		cout << endl;
//		cout << "Duyet LRN: ";
//		LRN(root);
//		cout << endl;
//	}
//	int sumchild(Node *p) {                         // tổng con
//			if (p == NULL)
//				return 0;
//			return (p->info + sumchild(p->left) + sumchild(p->right));
//	}
//	Node* search(Node* p, int x) {                  // tìm
//		if (p != NULL) {
//			if (p->info == x) return p;
//			else
//				if (x > p->info)
//					return search(p->right, x);
//				else
//					return search(p->left, x);
//		}
//		return NULL;
//	}
//	void LNR(Node* p) {
//		if (p != NULL) {
//			LNR(p->left);
//			cout << p->info << "\t";
//			LNR(p->right);
//		}
//	}
//	void NLR(Node* p) {
//		if (p != NULL) {
//			cout << p->info << "\t";
//			NLR(p->left);
//			NLR(p->right);
//		}
//	}
//	void LRN(Node* p) {
//		if (p != NULL) {
//			LRN(p->left);
//			LRN(p->right);
//			cout << p->info << "\t";
//		}
//	}
//	int Delete(Node*& p, int x) {          // Xóa
//		if (p == NULL) return 0;
//		if (p->info == x) {
//			Node* tmp = p;
//			if (p->left == NULL) p = p->right;
//			else if (p->right == NULL) p = p->left;
//			else
//				searchLastLeft(tmp, p->right);
//			delete tmp;
//			return 1;
//		}
//		if (p->info < x) return Delete(p->right, x);
//		if (p->info > x) return Delete(p->left, x);
//	}
//	void searchLastLeft(Node*& p, Node*& q) {   // tìm tận cùng trái
//		if (q->left == NULL) {
//			p->info = q->info;
//			p = q;
//			q = q->right;
//		}
//		else
//			searchLastLeft(p, q->left);
//	}
//	bool isLeaf(Node* p)          //kiểm tra nút lá
//	{
//		if (p == NULL)
//			return false;
//		if (p->left == NULL && p->right == NULL)
//			return true;
//		return false;
//	}
//	int leafSum(Node* p) {       //tổng nút lá
//		if (p == NULL) return 0;
//		if (p->left == NULL && p->right == NULL)
//		{
//			return p->info;
//		}
//		return (leafSum(p->left) + leafSum(p->right));
//	}
//	int GetHeight(Node* t){           //chiều cao của cây
//		/*{
//			int left = CalHeight( root->Left ) + 1;
//			int right = CalHeight( root->Right ) + 1;
//			return left > right ? left : right;
//		}
//		return 0;*/
//	}
//	int FindMax(Node* t)        //tìm max
//	{
//		if (t->right == NULL)
//		{
//			return t->info;
//		}
//		return FindMax(t->right);
//	}
//	int FindMin(Node* t)      //tìm min
//	{
//		if (t->left == NULL)
//		{
//			return t->info;
//		}
//		return FindMin(t->left); 
//	}
//	int SumTwoChild(Node* p) {     //tổng 2 con
//		if (p != NULL)
//		{
//			int a = SumTwoChild(p->left);
//			int b = SumTwoChild(p->right);
//			if (p->left != NULL && p->right != NULL)
//				return p->info + a + b;
//			return a + b;
//		}
//		return 0;
//	}
//	int SumOneChild(Node* p) {    //tổng 1 con
//		if (p != NULL)
//		{
//			int a = SumOneChild(p->left);
//			int b = SumOneChild(p->right);
//			if ((p->left == NULL && p->right != NULL ) || (p->left != NULL && p->right == NULL))
//				return p->info + a + b;
//			return a + b;
//		}
//		return 0;
//	}
//	int sumlessNode( int vt) {    //tổng các nút nhỏ hơn
//		Node* p = search(root, vt);
//		int kq = 0;
//		if (p != NULL) {
//			kq = sumchild(p);
//			kq -= p->info;
//		}
//		return kq;
//	}
//	bool isNT(int n) {     //kt nguyên tố
//		if (n <= 1)
//			return false;
//		for (int i = 2; i < n; i++)
//			if (n % i == 0)
//				return false;
//		return true;
//	}
//	int CountOneChild(Node* p){    //đếm 1 con
//		if (p != NULL)
//		{
//			int a = CountOneChild(p->left);
//			int b = CountOneChild(p->right);
//			if  ((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL)) 
//				return (a + b + 1);
//			return (a + b);
//		}
//		return 0;
//	}
//	int SumLess(Node* p,int x)     //tổng con
//	{
//		if (p != NULL)
//		{
//			int a = SumLess(p->left,x);
//			int b = SumLess(p->right,x);
//			if (p->info < x)
//				return (a + b + p->info);
//			return (a + b);
//		}
//		return 0;
//	}
//	int getLevelUtil(Node* p, int info, int level)   //lấy nút thứ mấy
//	{
//		if (p == NULL)
//			return 0;
//		if (p->info == info)
//			return level;
//		int downlevel
//			= getLevelUtil(p->left, info, level + 1);
//		if (downlevel != 0)
//			return downlevel;
//		downlevel = getLevelUtil(p->right, info, level + 1);
//		return downlevel;
//	}
//	int getLevel(Node* p, int info) // lấy nút
//	{
//		return getLevelUtil(p, info, 1);
//	}
//	void printlevel(Node* p, int desired, int current){ // in theo nút
//		if ( p != NULL )
//		{
//			if (desired == current)
//				cout << n->info << "\t";
//			else
//			{
//				printlevel(n->left, desired, current + 1);
//				printlevel(n->right, desired, current + 1);
//			}
//		}
//	}
//	void sumInLevel(Node* p, int desired, int current, int& sum) { // tổng nút
//		if (p != NULL) {
//			current++;
//			sumInLevel(p->left, desired, current,sum);
//			if (current == desired)
//				sum += p->info;
//			sumInLevel(p->right, desired, current,sum);
//		}
//	}
//	void countNodeUnderLevel(Node* p, int desired, int current, int& count) {
//		if (p != NULL) {
//			current++;
//			countNodeUnderLevel(p->left, desired, current, count);
//			if (current > desired)
//				count ++;
//			countNodeUnderLevel(p->right, desired, current, count);
//		}
//	}
//	void tinhmuc(Node *p, int k, int tam,int &sum)
//	{
//		if (p != NULL)
//		{
//			k++;
//			tinhmuc(p->left, k, tam,sum);
//			if (k > tam)
//				sum++;
//			tinhmuc(p->right, k, tam,sum);
//		}
//	}
//};
