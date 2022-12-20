//#include<iostream>
//#include<string>
//#include<iomanip>
//#define Max 100
//using namespace std;
//struct Football
//{
//	string Ma_Cau_Thu,Ten;
//	int Tuoi,So_Huy_Chuong,Thuong;
//};
//void Cap( Football *&T, int n )
//{
//	T = new Football [n];
//}
//void Nhap_1_Cau_Thu( Football &x )
//{
//	fflush(stdin);
//	cout << "Nhap Ma Cau Thu: ";
//	getline( cin,x.Ma_Cau_Thu );
//	fflush(stdin);
//	cout << "Nhap Ten Cau Thu: ";
//	getline( cin,x.Ten );
//	cout << "Nhap Tuoi: ";
//	cin >> x.Tuoi;
//	do
//	{
//	cout << "Nhap So Huy Chuong: ";
//	cin >> x.So_Huy_Chuong ;
//	if( x.So_Huy_Chuong > 2 )
//	{
//		if( x.So_Huy_Chuong > 2 && x.So_Huy_Chuong <= 3 )
//			x.Thuong = 200000;
//		else
//			if( x.So_Huy_Chuong > 3 && x.So_Huy_Chuong <= 5 )
//				x.Thuong = 300000;
//			else
//				x.Thuong = 500000;
//	}
//	else
//		cout << "Nhap Sai! Vui long nhap lai so huy chuong! " << endl;
//	}while( x.So_Huy_Chuong <= 2 );
//}
//void Xuat_1_Cau_Thu( Football x )
//{
//	cout << left << setw(12) << x.Ma_Cau_Thu << setw(25) << x.Ten << setw(10) << x.Tuoi
//		<< setw(14) << x.So_Huy_Chuong << setw(10) << x.Thuong << endl;
//}
//void Nhap_DS( Football *T, int n )
//{
//	for( int i = 0; i < n; i++ )
//	{
//		cout << "\n\tNhap cau thu thu " << i+1 << endl;
//		Nhap_1_Cau_Thu( T[i] );
//	}
//}
//void Xuat_DS( Football *T, int n )
//{
//	cout << left << setw(7) << "STT" << setw(12) << "Ma Cau Thu" << setw(25) << "Ho Ten" << setw(10) << "Tuoi"
//		<< setw(14) << "Huy Chuong" << setw(10) << "Thuong" << endl;
//	for( int i = 0; i < n; i++ )
//	{
//		cout << left << setw(7) << i;
//		Xuat_1_Cau_Thu( T[i] );
//	}
//}
//void Sap_Xep( Football *T, int n )
//{
//	Football Tam;
//	for( int i = 0; i < n-1; i++ )
//	{
//		for( int j = i+1; j < n; j++ )
//			if( T[i].Tuoi < T[j].Tuoi )
//			{
//				Tam = T[i];
//				T[i] = T[j];
//				T[j] = Tam;
//			}
//	}
//	cout << "\n\tDanh Sach Sau Khi Sap Xep " << endl;
//	Xuat_DS( T,n );
//}
//void Huy( Football *&T )
//{
//	delete [] T;
//	T = NULL;
//}
//int main()
//{
//	Football *T;
//	int n;
//	cout << "Nhap so Luong Cau Thu: ";
//	cin >> n;
//	Cap( T,n );
//	cout << "\n\t\tNhap Danh Sach " << endl;
//	Nhap_DS( T,n );
//	cout << "\n\t\tXuat Danh Sach " << endl;
//	Xuat_DS( T,n );
//	cout << "\n\t\tSap Xep Danh Sach " << endl;
//	Sap_Xep( T,n );
//	Huy( T );
//	system("pause");
//	return 0;
//}