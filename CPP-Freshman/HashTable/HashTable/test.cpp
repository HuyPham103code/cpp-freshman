//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//void Init( int *&a, int n )
//{
//	a = new int [n];
//}
//void Cancel( int *&a )
//{
//	delete [] a;
//	a = NULL;
//	cout << "Done!" << endl;
//}
//void Input( int *a, int n )
//{
//	for( int i = 0; i < n; i++ )
//		a[i] = i + 1;
//}
//void Display( int *a, int n )
//{
//	for( int i = 0; i < n; i++ )
//		cout << a[i] << "\t";
//	cout << endl;
//}
//void Add( int *&a, int &n, int pos, int x )
//{
//	if( pos >= n ) pos = n;
//	if( n == 0 ) pos = 0;
//	for( int i = n; i > pos; i-- )
//		a[i] = a[i-1];
//	a[pos] = x;
//	n++;
//}
//void Del( int *&a, int &n, int pos )
//{
//	if( pos >= n ) pos = n-1;
//	for( int i = pos; i < n-1; i++ )
//		a[i] = a[i + 1];
//	n--;
//}
//void Menu()
//{
//	cout << "\n\t1. remove " << endl;
//	cout << "\t2. display array " << endl;
//	cout << "\t3. random question " << endl;
//	cout << "\t4. add " << endl;
//	cout << "\t5. display array b " << endl;
//	cout << "\t0. exit " << endl;
//	cout << "Enter your option: ";
//}
//void Import( int *&a, int *&b, int &n, int &n1 )
//{
//	for( int i = 0; i < n1; i++ )
//		a[i] = b[i];
//	n = n1;
//	n1 = 0;
//}
//void RandomQuestion( int *&a, int &n, int *&b, int &n1 )
//{
//	srand(time(NULL));
//	char k;
//	if( n == 0 )
//	{
//		cout << "You are done! " << endl;
//		return;
//	}
//	while( n != 0 )
//	{
//		int pos = rand() % n;
//		int x;
//		cout << "\n\tQUESTION is:  " << a[pos] << endl;
//		cout << "vocal = ";
//		cin >> x;
//		if( x == a[pos] ) cout << "correct! " << endl;
//		else
//		{
//			Add( b,n1,n1,a[pos] );
//			cout << "incorrect! " << endl; 
//		}
//		Del( a,n,pos );
//		Display( a,n );
//	}
//	cout << "You are done! " << endl;
//	cout << "\tDo you want do these wrongs answer again! (y/n): ";
//	cin >> k;
//	if( k == 'Y' || k == 'y' )
//	{
//		Import( a,b,n,n1 );
//		Display( a,n );
//		RandomQuestion( a,n,b,n1 );
//	}
//	else
//		return;
//
//}
//int main()
//{
//	int *a,n,choice,pos,x,*b,n1=0;
//	cout << "Enter the number of array: ";
//	cin >> n;
//	Init( b,n );
//	Init( a,n );
//	Input( a,n );
//	Display( a,n );
//	do
//	{
//		Menu();
//		cin >> choice;
//		system("cls");
//		switch (choice)
//		{
//		case 1:
//			cout << "\n\t\tremove" << endl;
//			cout << "\tEnter the position you want to remove: ";
//			cin >> pos;
//			Del( a,n,pos-1 );
//			Display( a,n );break;
//		case 2:
//			cout << "\n\t\tARRAY " << endl;
//			Display( a,n );break;
//		case 3:
//			cout << "\n\t\trandom question " << endl;
//			RandomQuestion( a,n,b,n1 );
//			break;
//		case 4:
//			cout << "\n\t\tadd" << endl;
//			cout << "\tEnter the position you want to add: ";
//			cin >> pos;
//			cout << "\tEnter value: ";
//			cin >> x;
//			Add( b,n1,pos,x );
//			Display( b,n1 );break;
//		case 5:
//			cout << "\n\t\tARRAY B" << endl;
//			Display( b,n1 );break;
//		case 0:
//			break;
//		default:
//			cout << "\n\tWrong! Enter again " << endl;
//		}
//	}while( choice != 0 );
//	Cancel( a );
//	Cancel( b );
//	system("pause");
//	return 0;
//}