//#include<iostream>
//using namespace std;
//#define n 12
//struct Node
//{
//	int Value;
//	Node *Left,*Right;
//};
//int a[n] = { 40,20,50,10,25,43,55,5,15,30,47,60 };
//struct Tree
//{
//	Node* root;
//	void Init()
//	{
//		root = NULL;
//	}
//	Node* Create( int x )
//	{
//		Node* p = new Node;
//		p->Value = x;
//		p->Left = NULL;
//		p->Right = NULL;
//		return p;
//	}
//	void Add( Node *&p, int x )
//	{
//		if( p == NULL )
//		{
//			p = Create( x );
//			return;
//		}
//		else
//			if( p->Value == x ) return; // trùng
//				else if( p->Value > x )
//					return Add( p->Left,x );
//				else
//					return Add( p->Right, x );
//	}
//	void AddArr()
//	{
//		Init();
//		for( int i = 0; i < n; i++ )
//			Add( root,a[i] );
//	}
//	void LNR( Node *p )
//	{
//		if( p != NULL )
//		{
//			LNR( p->Left );
//			cout << p->Value << "\t";
//			LNR( p->Right );
//		}
//	}
//	void LRN( Node * p )
//	{
//		if( p != NULL )
//		{
//			LRN( p->Left );
//			LRN( p->Right );
//			cout << p->Value << "\t";
//		}
//	}
//	void NLR( Node * p )
//	{
//		if( p != NULL )
//		{
//			cout << p->Value << "\t";
//			NLR( p->Left );
//			NLR( p->Right );
//		}
//	}
//	Node* Search( Node* p, int x )
//	{
//		if( p != NULL )
//		{
//			if( p->Value == x ) return p;
//			else 
//				if( p->Value < x ) return Search( p->Right,x );
//				else return Search( p->Left,x );
//		}
//		return NULL;
//	}
//	int SumChild( Node* p )
//	{
//		if( p != NULL )
//			return p->Value + SumChild( p->Left ) + SumChild( p->Right );
//		return 0;
//	}
//	int SumChildNode( int x )
//	{
//		Node* p = Search( root,x );
//		int Sum = 0;
//		if( p != NULL )
//		{
//			Sum = SumChild( p );
//			return Sum;
//		}
//		return 0;
//	}
//	void SearchLastLeft( Node*& p, Node*& q )
//	{
//		if( q->Left == NULL )
//		{
//			p->Value = q->Value;
//			p = q;
//			q = q->Right;
//		}
//		else
//			SearchLastLeft( p,q->Left );
//	}
//	int Delete( Node*& p, int x )
//	{
//		if( p == NULL ) return 0;
//		if( p ->Value == x )
//		{
//			Node* tmp = p;
//			if( p->Left == NULL ) p = p->Right;
//			else if( p->Right == NULL ) p = p->Left;
//			else
//				SearchLastLeft( tmp,p->Right );
//			delete tmp;
//			return 1;
//		}
//		if( p->Value < x ) return Delete( p->Right,x );
//		if( p->Value > x ) return Delete( p->Left,x );
//	}
//	void DeleteNode()
//	{
//		for( int i = 0; i < n; i++ )
//			Delete( root,a[i] );
//		cout << "Done! " << endl;
//	}
//	void RNL( Node* p)
//	{
//		if( p != NULL )
//		{
//			RNL( p->Right );
//			cout << p->Value << "\t";
//			RNL( p->Left );
//		}
//	}
//	void PrintLever( Node* p, int Desired, int Current ) //duyệt theo mức
//	{
//		if( p != NULL )
//		{
//			if( Current == Desired )
//			cout << p->Value << "\t";
//			else
//			{
//				PrintLever( p->Left,Desired,Current+1 );
//				PrintLever( p->Right,Desired,Current+1 );
//			}
//		}
//	}
//	void CountLeaf( Node* p, int &Count )
//	{
//		if( p != NULL )
//		{
//			if( p->Left == NULL && p->Right == NULL )
//				Count++;
//			CountLeaf( p->Left, Count );
//			CountLeaf( p->Right, Count );
//		}
//	}
//	void CountOneChild( Node* p, int &Count )
//	{
//		if( p != NULL )
//		{
//			if( p->Left == NULL && p->Right != NULL || p->Right == NULL && p->Left != NULL )
//				Count++;
//			CountOneChild( p->Left,Count );
//			CountOneChild( p->Right,Count );
//		}
//	}
//	int CalHeight( Node* root )
//	{
//		if( root != NULL )
//		{
//			int left = CalHeight( root->Left ) + 1;
//			int right = CalHeight( root->Right ) + 1;
//			return left > right ? left : right;
//		}
//		return 0;
//	}
//};