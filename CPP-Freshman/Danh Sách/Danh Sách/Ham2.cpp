//#include<iostream>
//#include<iomanip>
//using namespace std;
//struct Node
//{
//	int Value;
//	Node* Link;
//	void Init( Node *&First ) // initialize
//	{
//		First = NULL;
//	}
//	Node* Create( int x ) // tạo 1 phần tử
//	{
//		Node* p = new Node;
//		p->Value = x;
//		p->Link = NULL;
//		return p;
//	}
//	void Export( Node* First ) // Xuất danh sách
//	{
//		Node* p = First;
//		while( p != NULL )
//		{
//			cout << p->Value << "\t";
//			p = p->Link;
//		}
//		cout << endl;
//	}
//	void Add_F( Node *&First, int x ) // Thêm vào đầu danh sách
//	{
//		Node *p = Create( x );
//		p->Link = First;
//		First = p;
//	}
//	void Add_L( Node *&First, int x ) // Thêm vào cuối
//	{
//		Node *q = Create( x );
//		Node *p = First;
//		if( p != NULL ) // danh sách có phần tử
//		{
//			while( p->Link != NULL )
//			{
//				p = p->Link;
//			}
//			p->Link = q;
//		}
//		else        //     danh sách rỗng
//		{
//			First = Create( x );
//		}
//	}
//	Node* Find( Node *First, int x )  // Tìm
//	{
//		Node *p = First;
//		if( p != NULL )
//		{
//			while( p != NULL )
//			{
//				if( p->Value == x )
//					return p;
//				p = p->Link;
//			}
//		}
//		return NULL;
//	}
//	void Del_After( Node* First,int x )
//	{
//		Node* p = Find( First,x );
//		Node *t = p->Link;
//		if( p == NULL ) 
//			return;
//		else
//		{
//			if( p->Link == NULL ) //đằng sau k có gì
//				return;
//			p->Link = (p->Link)->Link;
//			delete t;
//		}
//	}
//	void Remove_F( Node *&First ) // Xóa đầu
//	{
//		Node *p = First;
//		if( First == NULL )//mảng rỗng
//			return;
//		else
//		{
//			First = First->Link;
//			delete p;
//		}
//	}
//	void Remove_L( Node *&First ) // xóa cuối
//	{
//		Node* p = First;
//		Node *q = NULL;
//		if( First != NULL ) // danh sách có phần tử
//		{
//			while( p->Link != NULL )
//			{
//				q = p;
//				p = p->Link;
//			}
//			if( First == p ) // Nếu dòng while k chạy thì chỉ có 1 phần tử
//				First = NULL;
//			else
//				q->Link = NULL; // có nhiều hơn 1 phần tử
//			delete p;
//		}
//		else //danh sách rỗng
//			return;
//	}
//	void Find_And_Remove( Node *&First, int x ) // tìm rồi xóa
//	{
//		if( Find(First,x) == NULL )//Nếu phần tử x không tồn tại
//			return;
//		else
//		{
//			Node *p = First;
//			Node *q = NULL;
//			while( p->Value != x )
//			{
//				q = p; // 1
//				p = p->Link; //2
//			}
//			if( p == First ) // Nếu x nằm ở đầu danh sách
//				First = First->Link;
//			else
//				q->Link = p->Link;
//			delete p;
//		}
//	}
//	void Find_And_Remove_All( Node *&First, int x )
//	{
//		if( Find( First,x ) != NULL )
//		{
//			while( Find( First,x ) != NULL )
//			{
//				Node *p = First;
//				Node *q = NULL;
//				while( p->Value != x )
//				{
//					q = p; 
//					p = p->Link; 
//				}
//				if( p == First ) // Nếu x nằm ở đầu danh sách
//					First = First->Link;
//				else
//					q->Link = p->Link;
//				delete p;
//			}
//		}
//		else
//			return;
//	}
//	void Arrange( Node *&First )
//	{
//		Node *q,*p;
//		p = First;
//		if( First != NULL )
//		{
//			while( p->Link != NULL )
//			{
//				q = p->Link;
//				while( q != NULL ) // tới phần tử cuối cùng
//				{
//					if( p->Value > q->Value ) // Nếu lớn hơn thì đổi chỗ
//					{
//						int c = q->Value;
//						q->Value = p->Value;
//						p->Value = c;
//					}
//					q = q->Link;
//				}
//				p = p->Link;
//			}
//		}
//		else
//			return;
//	}
//	void Huy( Node *&First )
//	{
//		Node *p;
//		while( First != NULL )
//		{
//			p = First;
//			First = First->Link;
//			delete p;
//		}
//		cout << "Done!" << endl;
//	}
//};