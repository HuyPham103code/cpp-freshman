//#include<iostream>
//#include<iomanip>
//#include<fstream>
//#include<string>
//using namespace std;
//struct Employee
//{
//	string ID,Name;
//	int Gender,Salary;
//};
////thêm vào từ mảng
//Employee a[4] = {{"NV001","Nguyen Van Tuan",1,700000},{"NV002","Le Thi Mai",0,800000}
//	,{"NV002","Le Thi Mai",0,900000},{"NV002","Le Thi Mai",0,500000}};
//struct Node
//{
//	Employee S;
//	Node* Link;
//};
//Node* First;
//void Menu()
//{
//	cout << "\n\t\t1. Read file " << endl;
//	cout << "\t\t2. Export list " << endl;
//	cout << "\t\t3. Export by gender " << endl;
//	cout << "\t\t4. Add 1 employee to list " << endl;
//	cout << "\t\t5. Remove 1 employee from list " << endl;
//	cout << "\t\t6. Write the list of employees to file " << endl;
//	cout << "\t\t0. Exit " << endl;
//	cout << "\tEnter your choice: ";
//}
//void Init()
//{
//	First = NULL;
//}
//Node* Create( Employee S )
//{
//	Node* p = new Node;
//	p->S = S;
//	p->Link = NULL;
//	return p;
//}
//void Add( Employee A ) // add employee
//{
//	Node* p = Create( A );
//	if( First == NULL )
//	{
//		First = p;
//		First->Link = First; return;
//	}
//	Node* q = First;
//	Node* t = NULL;
//	do
//	{
//		t = q;
//		q = q->Link;
//	}while( q != First && q->S.Salary < A.Salary );
//	if( t == First && q->S.Salary >= A.Salary) // add this Node to head of list
//	{
//		Node* temp = First;
//		while( temp->Link != First )
//			temp = temp->Link;
//		temp->Link = p;
//		p->Link = First;
//		First = p;
//	}
//	else if( t->Link == First && q->S.Salary < A.Salary ) // add this Node to last of list
//	{
//		t->Link = p;
//		p->Link = First;
//	}
//	else // normal case
//	{
//		t->Link = p;
//		p->Link = q;
//	}
//}
////thêm vào từ mảng
//void AddFromArray()
//{
//	for( int i = 0; i < 3; i++ )
//		Add(a[i]);
//}
//void ReadFile( ifstream &ifs )
//{
//	if( ifs.is_open() )
//	{
//		Employee A;
//		while( !ifs.eof() )
//		{
//			getline( ifs, A.ID, '%' );
//			getline( ifs, A.Name, '%' );
//			ifs >> A.Gender;
//			ifs.ignore();
//			ifs >> A.Salary;
//			ifs.ignore();
//			Add(A);   //after read 1 employee, we add this one to list
//		}
//		cout << "Done! " << endl;
//		ifs.close();
//	}
//	else
//		cout << "Can't open this file " << endl;
//}
//void WriteFile( ofstream &ofs )
//{
//	if( ofs.is_open() )
//	{
//		if( First != NULL )
//		{
//			Node* p = First;
//			do
//			{
//				ofs << p->S.ID << "%" << p->S.Name << "%" << p->S.Gender << "%" << p->S.Salary << endl;
//				p = p->Link;
//			}while( p != First );
//		}
//		cout << "Done! " << endl;
//	}
//	else
//		cout << "Can't open file " << endl;
//}
//void Export1Employee( Employee S )
//{
//	cout << left << setw(15) << S.ID << setw(30) << S.Name;
//	if( S.Gender )
//		cout << setw(10) << "Male";
//	else
//		cout << setw(10) << "Female";
//	cout << setw(15) << S.Salary << endl;
//}
//void Export()
//{
//	if( First != NULL )
//	{
//		cout << left << setw(15) << "ID" << setw(30) << "Name" << setw(10) 
//			<< "Gender" << setw(15) << "Salary" << endl;
//		Node* p = First;
//		do
//		{
//			Export1Employee(p->S); // export
//			p = p->Link;
//		}while( p != First );
//	}
//	else
//		cout << "\n\tNothing " << endl;
//}
//void Cannel()
//{
//	if( First != NULL )
//	{
//		Node* p = First;
//		do
//		{
//			Node* q = p;
//			p = p->Link;
//			delete q;
//		}while( p != First );
//	}
//}
//void ExportByGender()
//{
//	string gender;
//	fflush(stdin);
//	cout << "Enter gender: ";
//	getline( cin,gender );
//	int Sex = gender == "nam" ||  gender == "Nam" ? 1 : 0;
//	Node *p = First;
//	if( First != NULL )
//	{
//		do
//		{
//			if( p->S.Gender == Sex )
//					Export1Employee( p->S );
//			p = p->Link;
//		}while( p != First );
//	}
//}
//void Add1Employee()
//{
//	Node* p = new Node;
//	fflush(stdin);
//	cout << "\n\tEnter ID: ";
//	getline( cin,p->S.ID );
//	cout << "\tEnter Name: ";
//	getline( cin,p->S.Name );
//	cout << "\tEnter gender( 1: male, 0: female ) ";
//	cin >> p->S.Gender;
//	cout << "\tEnter Salary: ";
//	cin >> p->S.Salary;
//	Add(p->S);
//	delete p;
//	cout << "\n\t\tlist after added " << endl;
//	Export();
//}
//int Search( string ID )
//{
//	if( First == NULL ) return 0;
//	Node* p = First;
//	do
//	{
//		if( p->S.ID == ID )
//			return 1;
//		p = p->Link;
//	}while( p != First );
//	return 0;
//}
//void Remove( string ID )
//{
//	if( First == NULL || !Search(ID) ){
//		cout << "Can't remove " << endl;
//		return;
//	}
//	Node* p = First;
//	Node* q = NULL;
//	do
//	{
//		if( p->S.ID == ID )
//			break;
//		q = p;
//		p = p->Link;
//	}while( p != First );
//	if( q == NULL ) // delete in the head of list
//	{
//		Node* t = First;
//		while( t->Link != First )
//			t = t->Link;
//		if( t->S.ID == ID ) //list have only 1 employee
//		{
//			delete First;
//			First = NULL;return;
//		}
//		First = First->Link;
//		t->Link = First;
//	}
//	else
//		q->Link = p->Link;
//	delete p;
//}