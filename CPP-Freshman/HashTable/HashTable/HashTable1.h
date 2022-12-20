//#include<iostream>
//#include<iomanip>
//#define m 101
//using namespace std;
//struct Node
//{
//	int Key;
//	Node* Next;
//};
//Node* heads[m];
//void init()
//{
//	for( int i = 0; i < m; i++ )
//		heads[i] = NULL;
//}
//Node* create( int k )
//{
//	Node* p = new Node;
//	p->Key = k;
//	p->Next = NULL;
//	return p;
//}
//Node* insertElement( int k )
//{
//	Node* t = heads[k % m]; // tìm key
//	Node* x = create(k);
//	if( t == NULL ) // vị trí đang rỗng
//	{
//		x->Next = t;
//		heads[k % m ] = x;
//	}
//	else if(t->Key >= k )
//	{
//		x->Next = t;
//		heads[k % m] = x;
//	}
//	else
//	{
//		Node* p = t->Next;// node chạy trước t để chèn x vào giữa t và p
//		while( p != NULL && p->Key < k )
//		{
//			t = t->Next;
//			p = t->Next;
//		}
//		t->Next = x;
//		x->Next = p;
//	}
//	return x;
//}
//Node* search( int k )
//{
//	Node* t = heads[k % m];
//	while( t != NULL && t->Key != k )
//		t = t->Next;
//	return t;
//}
//void traverseNode( int k )
//{
//	Node* p = heads[k];
//	while( p != NULL )
//	{
//		cout << p->Key << "-->";
//		p = p->Next;
//	}
//	cout << "NULL" << endl;
//}
//void traverse()
//{
//	for(  int i = 0; i < m; i++ )
//	{
//		if( heads[i] != NULL )
//		{
//			cout << "T[" << i <<  "]:" << setw(10);
//			traverseNode(i);
//		}
//	}
//}
//int remove( int k )
//{
//	Node* t = heads[k % m];
//	Node* p = NULL;
//	while( t != NULL && t->Key != k )
//	{
//		p = t;
//		t = t->Next;
//	}
//	if( t == NULL ){
//		cout << "\nCo cai mit ma xoa " << endl;
//		return 0;
//	}
//	else if( p == NULL ) // đấu xòa 
//	{
//		heads[k%m] = t->Next;
//		delete t;
//	}
//	else
//	{
//		p->Next = t->Next;
//		delete t;
//	}
//	return 1;
//}
//void clearNode( int k )
//{
//	Node* p = heads[k];
//	while( p != NULL )
//	{
//		Node* q = p;
//		p = p->Next;
//		delete q;
//	}
//	heads[k] = NULL;
//}
//void clear()
//{
//	for( int i = 0; i < m; i++ )
//		if( heads[i] != NULL )
//			clearNode(i);
//	cout << "Done!" << endl;
//}