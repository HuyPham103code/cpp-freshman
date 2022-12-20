//#include<iostream>
//using namespace std;
//struct Node
//{
//	int value;
//	Node *Left,*Right;
//};
//int a[12] = { 40,20,50,10,25,43,55,5,15,30,47,60 };
//struct Tree
//{
//	Node* root;
//	void Init()
//	{
//		root = NULL;
//	}
//	Node* Create( int x )
//	{
//		 Node* p = new Node;
//		 p->value = x;
//		 p->Left = NULL;
//		 p->Right = NULL;
//		 return p;
//	}
//	void InsertNode( Node*& p, int x )
//	{
//		if( p == NULL )
//			p = Create(x);
//		else
//		{
//			if( p->value == x ) return;//trùng
//			else
//				if( p->value > x )
//					return InsertNode( p->Left, x );
//				else
//					return InsertNode( p->Right, x );
//		}
//	}
//	void InsertNodeS()
//	{
//		Init();
//		for( int i = 0; i < 12; i++ )
//			InsertNode( root,a[i] );
//	}
//	void LNR( Node* p )
//	{
//		if( p != NULL )
//		{
//			LNR( p->Left );
//			cout << p->value << "\t";
//			LNR( p->Right );
//		}
//	}
//	void NLR( Node* p )
//	{
//		if( p != NULL )
//		{
//			cout << p->value << "\t";
//			NLR( p->Left );
//			NLR( p->Right );
//		}
//	}
//	int Delete( Node*& p , int x )
//	{
//		if( p == NULL )return 0;// 0 tìm thấy
//		if( p->value == x )
//		{
//			Node* tmp = p;
//			if( p->Left == NULL ) p = p->Right;
//			else if( p->Right == NULL ) p = p->Left;
//			else
//				SearchLastLeft( tmp,p->Right );
//			delete tmp;
//			return 1;
//		}
//		if( p->value < x ) return Delete( p->Right,x );
//		if( p->value > x ) return Delete( p->Left,x );
//	}
//	void SearchLastLeft( Node*& p, Node*& q )
//	{
//		if( q->Left == NULL )
//		{
//			p->value = q->value;
//			p = q;
//			q = q->Right;
//		}
//		else
//			SearchLastLeft( p,q->Left );
//	}
//	void LRN( Node* p )
//	{
//		if( p != NULL )
//		{
//			LRN( p->Left );
//			LRN( p->Right );
//			cout << p->value << "\t";
//		}
//	}
//	void Cannel()
//	{
//		for( int i = 0; i < 12; i++ )
//			Delete( root,a[i] );
//		cout << "Done! " << endl;
//	}
//};