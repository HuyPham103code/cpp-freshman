//#include<iostream>
//using namespace std;
//struct Node
//{
//	int Value;
//	Node *Prev,*Next;
//	void Menu()
//	{
//		cout << "\n\t\t0. Export List " << endl;
//		cout << "\t\t1. Export List 2" << endl;
//		cout << "\t\t2. Add first on list " << endl;
//		cout << "\t\t3. add last on list " << endl;
//		cout << "\t\t4. Delete first of list " << endl;
//		cout << "\t\t5. delete last of list " << endl;
//		cout << "\t\t6. Find a element of list " << endl;
//		cout << "\t\t7. Del a element af before X  " << endl;
//		cout << "\t\t8. Del a element af after X " << endl;
//		cout << "\t\t9. Arrange list " << endl;
//		cout << "\t\t10. Exit " << endl;
//	}
//};
//Node *First,*Last;
//void Init()
//	{
//		First = NULL;
//		Last = NULL;
//	}
//Node* Create( int x )
//{
//	Node* p = new Node;
//	p->Value = x;
//	p->Prev = NULL;
//	p->Next = NULL;
//	return p;
//}
//void AddF( int x )
//{
//	Node* p = Create(x);
//	if( First == NULL ) //chưa có phần tử nào
//	{
//		First = p;
//		Last = p;
//
//	}
//	else // ds đã có phần tử
//	{
//		First->Prev = p;
//		p->Next = First;
//		First = p;
//	}
//}
//void Export()
//{
//	if( First == NULL )
//		return;
//	else
//	{
//		Node* p = First;
//		while( p != NULL )
//		{
//			cout << p->Value << "\t";
//			p = p->Next;
//		}
//		cout << endl;
//	}
//}
//void Export1()
//{
//	if( Last == NULL )
//		return;
//	else
//	{
//		Node* p = Last;
//		while( p != NULL )
//		{
//			cout << p->Value << "\t";
//			p = p->Prev;
//		}
//		cout << endl;
//	}
//}
//void AddL( int x )
//{
//	Node* p = Create(x);
//	if( First != NULL ) // cho last bằng p
//	{
//		p->Prev = Last;
//		Last->Next = p;
//		Last = p;
//	}
//	else // cả first và last đều bằng p
//	{
//		First = p;
//		Last = p;
//	}
//}
//Node* Find( int x )
//{
//	if( First != NULL )
//	{
//		Node* p = First;
//		while( p != NULL )
//		{
//			if( p->Value == x )
//				return p;
//			p = p->Next;
//		}
//	}
//	return NULL;
//}
//void DelF()
//{
//	if( First != NULL )
//	{
//		Node* q = First;
//		if( First->Next == NULL )
//		{
//			Init();
//		}
//		else
//		{
//			First = First->Next; 
//			First->Prev = NULL;// thì cho nó trỏ về NULL vì xóa đầu
//		}
//		delete q;
//	}
//	// ds không có gì thì return;
//	return; 
//}
//void DelL()
//{
//	if( First != NULL )
//	{
//		Node* p = First;
//		Node* q = NULL;
//		while( p != Last )
//		{
//			q = p;
//			p = p->Next;
//		}
//		if( q == NULL ) // First = Last
//			Init();
//		else
//		{
//			q->Next = NULL; // NHỚ CẬP NHẬT LẠI LAST
//			Last = q;
//		}
//		delete p;
//	}
//	return;
//}
//void Del_Before( int x )
//{
//	Node* p = Find ( x );
//	Node* t = NULL;
//	if( p != NULL ) //thấy thì mới vào việc
//	{
//		Node* q = First;
//		while( q != p)
//		{
//			t = q;
//			q = q->Next;
//		}
//		if( t == NULL ) // X ở ngay đầu thì có gì ở trc nó đâu mà xóa
//			return;
//		else
//		{
//			
//			if( t == First )
//			{
//				First = First->Next;
//				First->Prev = NULL;
//			}
//			else
//			{
//				q->Prev = t->Prev;
//				(t->Prev)->Next = q;
//			}
//			delete t;
//		}
//	}
//	return;
//}
//void Del_After( int x )
//{
//	Node* p = Find(x);
//	if( p != NULL && p != Last ) // p tồn tại và không nằm ở cuối
//	{
//		Node* q = First;
//		while( q != p )
//		{
//			q = q->Next;
//		}
//		if( q == First && q->Next == NULL ) //nếu x nằm ngay đầu và ds chỉ có 2 phần tử
//		{
//			First->Next = NULL;
//			p = Last;
//			Last = First; //mảng chỉ còn 1 phần thử nên First = Last
//		}
//		else
//		{
//			p = p->Next; //Trỏ p về sau, tức là vị trí sẽ xóa
//			q->Next = p->Next;
//			if( p == Last )
//				Last = q;
//			else
//				(p->Next)->Prev = q;
//		}
//		delete p;
//	}
//	return;
//}
//void Huy()
//{
//	if( First != NULL )
//	{
//		Node* p = NULL;
//		while( p != NULL )
//		{
//			p = First;
//			First = First->Next;
//			delete p;
//		}
//	}
//	return;
//}
////void Arrange()
////{
////	int tam;
////	Node* p = First;
////	Node* q = NULL;
////	if(
////}