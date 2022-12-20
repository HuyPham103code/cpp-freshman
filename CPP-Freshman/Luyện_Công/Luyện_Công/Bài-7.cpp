#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;
string Loc( int n )
{
	string a[6] = { "[Bau] ","[Cua] ","[Tom] ","[Ca] ","[Huou] ","[Nai] " };
	switch (n)
	{
	case 1:
		return a[0];
	case 2:
		return a[1];
	case 3:
		return a[2];
	case 4:
		return a[3];
	case 5:
		return a[4];
	case 6:
		return a[5];
	}
}
string Lac( )
{
	int a = rand()%6+1;
	int b = rand()%6+1;
	int c = rand()%6+1;
	string KQ;
	string x = Loc( a );
	string y = Loc( b );
	string z = Loc( c );
	if ( b == c && b == a )
	{
		KQ = "3" + y;
	}
	else if ( b == c )
	{
		KQ = "2" + y + " 1" + x;
	}
	else if ( b == a )
	{
		KQ = "2" + y + " 1" + z;
	}
	else if ( a == c )
	{
		KQ = "2" + x + " 1" + y;
	}
	else 
	{
		KQ = "1" + x + " 1" + y + " 1" + z;
	}
	return KQ;
}
int main()
{
	char z;
	string a;
	ofstream ofs;
	ofs.open( "D:\BauCua.txt",ios::out );
	if( ofs.is_open() )
	{
	do
	{
		a = Lac();
		cout << a;
		ofs << a << endl;
		cout << "\n" << " continue( Y ) / Exit( N ): ";
		cin >> z;
		system("cls");
	}while( z != 'n');
	ofs.close();
	}
	else
		cout << "Khong the mo file " << endl;
	system("pause");
	return 0;
}