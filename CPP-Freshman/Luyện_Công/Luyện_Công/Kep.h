////Danh sách liên kết kép
//#include<iostream>
//#include<string>
//#include<iomanip>
//using namespace std;
//struct Student
//{
//	string name,ID;
//	float Score;
//};
//struct Node
//{
//	Student S;
//	Node *Next,*prev;
//};
//Node *First,*Last;
//void Init()
//{
//	First = NULL;
//	Last = NULL;
//}
//Node* Create( float Score, string Name, string ID )
//{
//	Node* p = new Node;
//	p->S.Score = Score;
//	p->S.ID = ID;
//	p->S.name = Name;
//	p->Next = NULL;
//	p->prev = NULL;
//	return p;
//}
//void Add( float Score, string Name, string ID )
//{
//	Node* p = Create( Score,Name,ID );
//	if( First == NULL )
//	{
//		First = p;
//		Last = p;
//		return;
//	}
//	Node *q = First;
//	Node *t = NULL;
//	while( q != NULL && q->S.Score < Score )
//	{
//		t = q;
//		q = q->Next;
//	}
//	if( t == NULL ) // thêm đầu
//	{
//		p->Next = q;
//		q->prev = p;
//		First = p;
//	}
//	else if( q == NULL )//thêm cuối
//	{
//		t->Next = p;
//		p->prev = t;
//		Last = p;
//	}
//	else
//	{
//		t->Next = p;
//		p->prev = t;
//	}
//}
//void Input()
//{
//	Init();
//	float score;
//	string name,id;
//	do
//	{
//		fflush(stdin);
//		cout << "\nEnter ID: ";
//		getline( cin,id );
//		cout << "Enter Name: ";
//		getline( cin,name );
//		cout << "Enter Score( 0 = stop ): ";
//		cin >> score;
//		if( score != 0 )
//			Add( score,name,id );
//	}while( score != 0 );
//}
//void Print_1_Student( float Score, string Name, string ID )
//{
//	cout << left << setw(25) << Name << setw(10) << ID << setw(7) << Score << endl;
//}
//void Print()
//{
//	cout << left << setw(25) << "Name" << setw(10) << "ID" << setw(7) << "Score" << endl;
//	Node *p = First;
//	while( p != NULL )
//	{
//		Print_1_Student( p->S.Score,p->S.name,p->S.ID );
//		p = p->Next;
//	}
//}
//void Print_Score()
//{
//	float a,b;
//	cout << "\n\tEnter 2 Score: ";
//	cin >> a >> b;
//	Node *p = First;
//	cout << left << setw(25) << "Name" << setw(10) << "ID" << setw(7) << "Score" << endl;
//	while( p != NULL )
//	{
//		if( p->S.Score >= a && p->S.Score <= b )
//			Print_1_Student( p->S.Score,p->S.name,p->S.ID );
//		p = p->Next;
//	}
//}
//void Print_Reverse()
//{
//	cout << left << setw(25) << "Name" << setw(10) << "ID" << setw(7) << "Score" << endl;
//	Node *p = Last;
//	while( p != NULL )
//	{
//		Print_1_Student( p->S.Score,p->S.name,p->S.ID );
//		p = p->prev;
//	}
//}
//void Cannel()
//{
//	Node *p = First;
//	while( p != NULL )
//	{
//		Node* q = p;
//		p = p->prev;
//		delete q;
//	}
//}