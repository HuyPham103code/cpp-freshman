#include<iostream>
#include<iomanip>
using namespace std;
struct Set
{
	int Value;
	Set* Link;
	Set* First;
	void Init()
	{
		First = NULL;
	}
	Set* Create( int x )
	{
		Set* p = new Set;
		p->Value = x;
		p->Link = NULL;
		return p;
	}
	void Add( int x )
	{
		Set* p = Create(x);
		if( First == NULL ) // danh sách rỗng
			First = p;
		else
		{
			Set* q = First;
			Set* t =NULL;
			while( q != NULL && q->Value <= x )
			{
				if( q->Value == x ) // nếu đã có rồi thì không thêm vào nữa
					return;
				t = q;
				q = q->Link;
			}
			if( t == NULL ) // thêm vào đầu
			{
				p->Link = First;
				First =  p;
			}
			else
			{
				p->Link = q; // thêm p sau t
				t->Link = p;
			}
		}
	}
	void Print()
	{
		if( First == NULL ) return;
		Set* p = First;
		while( p!= NULL )
		{
			cout << setw(5) << p->Value;
			p = p->Link;
		}
		cout << endl;
	}
	void Cannel()
	{
		Set* p = First;
		while( p != NULL )
		{
			Set* q = p;
			p = p->Link;
			delete q;
		}
		First = NULL;
	}
	Set* Search( int x ) // hàm search
	{
		Set* p = First;
		while( p != NULL )
		{
			if( p->Value == x )
				return p;
			p = p->Link;
		}
		return NULL;
	}
};
void Input( Set &A )
{
	A.Init();
	int x;
	cout << "\n\tNhap (0) de STOP! " << endl;
	do
	{
		cout << "Nhap so: ";
		cin >> x;
		if( x != 0 )
			A.Add(x);
	}while( x != 0 );
}
void Hop( Set A, Set B )
{
	Set KQ;
	KQ.Init();
	Set* a = A.First;
	Set* b = B.First;
	while( a != NULL ) // thêm ds a vào kq
	{
		KQ.Add( a->Value );
		a = a->Link;
	}
	while( b != NULL )
	{
		if( A.Search( b->Value ) == NULL ) // b không có trong a
			KQ.Add( b->Value );
		b = b->Link;
	}
	cout << "A u B = ";KQ.Print();
}
void Hieu( Set A, Set B )
{
	Set KQ;
	KQ.Init();
	Set* a = A.First;
	Set* b = B.First;
	while( a != NULL ) 
	{
		if( B.Search( a->Value ) == NULL ) // loại bỏ những thg B trong A
			KQ.Add( a->Value );
		a = a->Link;
	}
	cout << "A / B = ";KQ.Print();
}
void Giao( Set A, Set B )
{
	Set KQ;
	KQ.Init();
	Set* a = A.First;
	Set* b = B.First;
	while( a != NULL ) 
	{
		if( B.Search( a->Value ) != NULL ) // có cả trong A và B
			KQ.Add( a->Value );
		a = a->Link;
	}
	cout << "A n B = ";KQ.Print();
}