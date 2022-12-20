//#include<iostream>
//#include<iomanip>
//using namespace std;
//void Cap( char **&a, int m, int n )
//{
//	a = new char *[m];
//	for( int i = 0; i < m; i++ )
//		a[i] = new char [n];
//}
//void Huy( char **&a, int m )
//{
//	for( int i = 0; i < m; i++ )
//		delete [] a[i];
//	delete [] a;
//	a = NULL;
//}
////int CheckingWin( char **a )
////{
////	for( int i = 0; i < 3; i++ )
////	{
////		if( a[i][0] == a[i][1] && a[i][0] == a[i][2] )
////			return Current_Player;
////		if( a[0][i] == a[1][i] && a[0][i] == a[2][i] )
////			return Current_Player;
////	}
////	if( a[0][0] == a[1][1] && a[1][1] == a[2][2] )
////		return Current_Player;
////	if( a[0][2] == a[1][1] && a[1][1] == a[2][0] )
////		return Current_Player;
////	return 0;
////}
//void Set( char **a )
//{
//	a[0][0] = '1';
//	a[0][1] = '2';
//	a[0][2] = '3';
//	a[1][0] = '4';
//	a[1][1] = '5';
//	a[1][2] = '6';
//	a[2][0] = '7';
//	a[2][1] = '8';
//	a[2][2] = '9';
//}
//void Xuat( char **a )
//{
//	cout << "   " << " |" << "   " << " |"  << endl;
//	cout << "   " << a[0][0] << "|" << "   " << a[0][1] << "|" << "   " << a[0][2] << endl;
//	cout << "____|____|____" << endl;
//	cout << "   " << a[1][0] << "|" << "   " << a[1][1] << "|" << "   " << a[1][2] << endl;
//	cout << "____|____|____" << endl;
//	cout << "   " << a[2][0] << "|" << "   " << a[1][1] << "|" << "   " << a[2][2] << endl;
//	cout << "   " << " |" << "   " << " |"  << endl;
//}
//int main()
//{
//	char **a;
//	Cap( a,3,3 );
//	Set( a );
//	Xuat( a );
//	Huy( a,3 );
//	system("pause");
//	return 0;
//}