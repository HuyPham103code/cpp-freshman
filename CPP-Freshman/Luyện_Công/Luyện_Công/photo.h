//#include<iostream>
//#include<string>
//#include<iomanip>
//using namespace std;
//struct Iphone
//{
//	string Name;
//	int Price;
//};
//Iphone A[5] = {{"Iphone1",5000},{"Iphone3",7000},{"SamSung",10000},{"Cuc_Gach",100},{"Nokia",200}};
//struct Node
//{
//	Iphone S;
//	Node *Next,*Prev;
//};
//Node *First,*Last;
//void Init()
//{
//	First = NULL;
//	Last = NULL;
//}
//Node* Create( int Price, string Name )
//{
//	Node* p = new Node;
//	p->S.Name = Name;
//	p->S.Price = Price;
//	p->Next = NULL;
//	p->Prev = NULL;
//	return p;
//}
//void Add( int Price,string Name )
//{
//	Node* p = Create( Price,Name );
//	if( First == NULL ) // ds chưa có gì
//	{
//		First = p;
//		Last = p;
//		return;
//	}
//	Node* q = First;
//	Node* t = NULL;
//	while( q != NULL && q->S.Price < Price )
//	{
//		t = q;
//		q = q->Next;
//	}
//	if( t == NULL ) // thêm đầu
//	{
//		p->Next = q;
//		q->Prev = p;
//		First = p;
//	}
//	else if( q == NULL ) // thêm cuối
//	{
//		t->Next = p;
//		p->Prev = t;
//		Last = p;
//	}
//	else
//	{
//		t->Next = p;
//		p->Prev = t;
//		p->Next = q;
//		q->Prev = p;
//	}
//}
//void In_Put()
//{
//	Init();
//	int price;
//	int stt = 1;
//	string name;
//	do
//	{
//		fflush(stdin);
//		cout << "\nProduct " << stt << endl;
//		cout << "\tEnter Name: ";
//		cin >> name;
//		cout << "\tEnter price: ";
//		cin >> price;
//		if( price != 0 )
//			Add( price,name );
//		stt++;
//	}while( price != 0 );
//}
//void Print_1_Product( int STT, int Price, string Name )
//{
//	cout << left << setw(7) << STT << setw(20) << Name << setw(10) << Price << endl;
//}
//void Print()
//{
//	int STT = 1;
//	Node* p = First;
//	cout << left << setw(7) << "STT" << setw(20) << "Product" << setw(10) << "Price" << endl;
//	while( p != NULL )
//	{
//		Print_1_Product( STT,p->S.Price,p->S.Name );
//		STT++;
//		p = p->Next;
//	}
//}
//void Cannel()
//{
//	Node* p = First;
//	while( p != NULL )
//	{
//		Node* q = p;
//		p = p->Next;
//		delete q;
//		q = NULL;
//	}
//}
//void Print_Price()
//{
//	int stt=1;
//	float a,b;
//	cout << "\n\tEnter 2 Score: " << endl;
//	cout << "\nPrice 1: ";
//	cin >> a;
//	cout << "\nPrice 2: ";
//	cin >> b;
//	Node *p = First;
//	cout << left << setw(7) << "STT" << setw(20) << "Product" << setw(10) << "Price" << endl;
//	while( p != NULL )
//	{
//		if( p->S.Price >= a && p->S.Price <= b )
//			Print_1_Product( stt,p->S.Price,p->S.Name);
//		p = p->Next;
//		stt++;
//	}
//}
//void Enter()
//{
//	for( int i = 0; i < 5; i++ )
//		Add( A[i].Price,A[i].Name );
//	Print();
//}