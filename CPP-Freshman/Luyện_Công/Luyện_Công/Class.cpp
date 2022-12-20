//#include<iostream>
//#include<iomanip>
//using namespace std;
//void Khoi_Tao( char a[][6], int m , int n )
//{
//	for( int i = 0; i < m; i++ )
//		for( int j = 0; j < n; j++ )
//			a[i][j] = '*';
//}
//void Xuat( char a[][6], int m, int n )
//{
//	cout << setw(12) << 'A' << setw(4) << 'B' << setw(4) << 'C' << setw(4) << 'D'
//		<< setw(4) << 'E' << setw(4) << 'F' << endl;
//	for( int i = 0; i < m; i++ )
//	{
//		cout << "Hang" << setw(4) << i+1;
//		for( int j = 0; j < n; j++ )
//			cout << setw(4) << a[i][j];
//		cout << endl;
//	}
//}
//void Xuat_Hang( char a[][6], int m, int n )
//{
//	cout << setw(12) << 'A' << setw(4) << 'B' << setw(4) << 'C' << setw(4) << 'D'
//		<< setw(4) << 'E' << setw(4) << 'F' << endl;
//	for( int i = m; i <n; i++ )
//	{
//		cout << "Hang" << setw(4) << i+1;
//		for( int j = 0; j < 6; j++ )
//			cout << setw(4) << a[i][j];
//		cout << endl;
//	}
//}
//void Dat_Ve( char a[][6], int m, int n, int &Hang, char &Ghe )
//{
//	do
//	{
//		cout << "De nghi chon ve hang: ";
//		cin >> Hang;
//		cout << "De nghi chon ve ghe: ";
//		cin >> Ghe;
//		if( Ghe > 'Z' )
//			Ghe -= 32;
//		if( Hang < 1 || Hang > 13 || Ghe < 'A' || Ghe > 'F' )
//			cout << "Nhap sai Nhap lai!\n";
//	}while( Hang < 1 || Hang > 13 || Ghe < 'A' || Ghe > 'F' );
//	Hang -=1;
//	Ghe = (int)Ghe-65;
//}
//void Tong_Ket_Ve( char a[][6], int m, int n, int Hang, char Ghe )
//{
//	if( a[Hang][Ghe] == '*' )
//	{
//		a[Hang][Ghe] = 'X';
//		cout << "Ban Da Dat ve Thanh Cong " << endl;
//	}
//	else
//		cout << "Dat Ve That Bai!\n";
//}
//void Menu()
//{
//	cout << "\n1/Chon Hang Thuong Gia\n";
//	cout << "2/Chon Hang Pho Thong\n";
//	cout << "3/Chon Hang Tiet Kien\n";
//	cout << "Chon 1,2 Hoac 3: ";
//}
//void Cap( char **a, int m, int n)
//{
//	a = new char *[m];
//	for( int i = 0; i < m; i++ )
//		a[i] = new char [n];
//}
//void Huy( char **a, int m, int n )
//{
//	for( int i = 0; i < m; i++ )
//		delete [] a[i];
//	delete [] a;
//	a = NULL;
//}
//int main()
//{
//	char a[13][6], tt,Ghe;
//	int Chon,Hang;
//	//Cap( a,13,6 );
//	Khoi_Tao( a,13,6 );
//	do
//	{
//		system("cls");
//		cout << "\t\tDat Ve May Bay " << endl;
//		Xuat( a,13,6 );
//		cout << "(*: cho con trong, X: cho da dat.)" << endl;
//		Menu();
//		cin >> Chon;
//		switch (Chon)
//		{
//		case 1:
//			cout << "Dang Tien Hanh Dat Ve Hang Thuong Gia " << endl;
//			Xuat_Hang( a,0,2 );
//			Dat_Ve( a,13,6,Hang,Ghe );
//			if( Hang >= 0 && Hang < 2 )
//			{
//				Tong_Ket_Ve( a,13,6,Hang,Ghe );
//				Xuat_Hang( a,0,2 );
//			}
//			else
//				cout << "Ban cho sai hang! " << endl;
//			break;
//		case 2:
//			cout << "Dang Tien Hanh Dat Ve Hang Pho Thong " << endl;
//			Xuat_Hang( a,2,7 );
//			Dat_Ve( a,13,6,Hang,Ghe );
//			if( Hang >= 2 && Hang < 7 )
//			{
//				Tong_Ket_Ve( a,13,6,Hang,Ghe );
//				Xuat_Hang( a,2,7 );
//			}
//			else
//				cout << "Ban cho sai hang! " << endl;
//			break;
//		case 3:
//			cout << "Dang Tien Hanh Dat Ve Hang Pho Thong " << endl;
//			Xuat_Hang( a,7,13 );
//			Dat_Ve( a,13,6,Hang,Ghe );
//			if( Hang >= 7 && Hang < 13 )
//			{
//				Tong_Ket_Ve( a,13,6,Hang,Ghe );
//				Xuat_Hang( a,7,13 );
//			}
//			else
//				cout << "Ban cho sai hang! " << endl;
//			break;
//		default:
//			cout << "Ban Da Chon Sai! Hay Chon 1,2 Hoac 3\n";
//		}
//		cout << "Ban Co Muon Tiep Tuc Khong( Y/N): ";
//		cin >> tt;
//	}while( tt == 'Y' || tt == 'y' );
//	Xuat( a,13,6 );
//	system("pause");
//	return 0;
//}