//#include<iostream>
//using namespace std;
//struct Node
//{
//	float info;
//	Node* pLink;
//};
//Node* pFirst;
//void Init()
//{
//	pFirst = NULL;
//}
//void AddL( float x ) // thêm cuối
//{
//	Node* p = new Node;
//	p->info = x;
//	p->pLink = NULL;
//	if( pFirst == NULL )
//		pFirst = p;
//	else
//	{
//		Node* q = pFirst;
//		while( q->pLink != NULL )
//		{
//			q = q->pLink;
//		}
//		q->pLink = p;
//	}
//}
//void Print()
//{
//	if( pFirst != NULL )
//	{
//		Node* p = pFirst;
//		while( p != NULL )
//		{
//			if( int(p->info) % 3 == 0 )
//				cout << p->info << "\t";
//			p = p->pLink;
//		}
//		cout << endl;
//	}
//}
//void Cannel()//giải phóng bộ nhớ
//{
//	if( pFirst == NULL ) return;
//	Node* p = pFirst;
//	while( p != NULL )
//	{
//		Node* q = p;
//		p = p->pLink;
//		delete q;
//	}
//	pFirst = NULL;
//}
//int main()
//{
//	Init();
//	AddL(0);
//	AddL(3);
//	AddL(5);
//	AddL(6);
//	AddL(9);
//	AddL(1);
//	AddL(2);
//	Print();
//	Cannel();
//	system("pause");
//	return 0;
//}