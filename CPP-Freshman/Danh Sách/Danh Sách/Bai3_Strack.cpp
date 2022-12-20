//#include<iostream>
//#include<string>
//#define Max 100
//using namespace std;
//struct Stack
//{
//	int a[Max];
//	int Top;
//};
//Stack S;
//void Init();
//bool Is_Empty();
//bool Is_Full();
//void Push( int x );
//int Pop( int &x );
//string Change( int n, int He );
//void Menu();
//int main()
//{
//	int x,n,Choose;
//	int He;
//	do
//	{
//		Menu();
//		cin >> Choose;
//		system("cls");
//		switch (Choose )
//		{
//		case 1:
//			cout << "\n\t\tKhoi tao " << endl;
//			Init();
//			cout << "\n\t\tDONE!" << endl;break;
//		case 2:
//			cout << "\n\t\tKiem tra rong " << endl;
//			if( Is_Empty() )
//				cout << "Dang rong that " << endl;
//			else
//				cout << "khong rong dau nha " << endl;
//			break;
//		case 3:
//			cout << "\n\t\tKiem tra day " << endl;
//			if( Is_Full() )
//				cout << "Dang da day " << endl;
//			else
//				cout << "Chua day nha " << endl;
//			break;
//		case 4:
//			cout << "\n\t\tThem phan tu vao strack " << endl;
//			cout << "Nhap phan tu muon them: ";
//			cin >> x;
//			Push(x);break;
//		case 5:
//			cout << "\n\t\tXuat danh sach " << endl;
//			while( S.Top != -1 )
//			{
//				Pop(x);
//				cout << x << "\t" << endl;
//			}
//			cout << endl;break;
//		case 6:
//			cout << "\n\t\tDoi bit " << endl;
//			cout << "Nhap so muon doi: ";
//			cin >> n;
//			do
//			{
//			cout << "Nhap he muon chuyen: ";
//			cin >> He;
//			if( He != 2 && He != 8 && He != 16 )
//				cout << "Nhap sai! Vui Long Nhap( 2-8-16 ) " << endl;
//			}while( He != 2 && He != 8 && He != 16 );
//			cout << "So sau khi doi: " << Change(n,He) << endl;
//			break;
//		case 0:
//			break;
//		default:
//			cout << "Nhap sai! Nhap lai " << endl;
//		}
//	}while( Choose != 0 );
//	system("pause");
//	return 0;
//}
//void Init()
//{
//	S.Top = -1;
//}
//bool Is_Empty()
//{
//	return S.Top < 0;
//}
//bool Is_Full()
//{
//	return S.Top == Max;
//}
//void Push( int x )
//{
//	if( S.Top == Max )
//		return;
//	S.a[++S.Top] = x;
//}
//int Pop( int &x )
//{
//	if( S.Top != -1 )
//	{
//		x = S.a[S.Top--];
//		return 1;
//	}
//	return 0;
//}
//void Menu()
//{
//	cout << "\n\t\t1. Khoi tao strack " << endl;
//	cout << "\t\t2. Kiem tra strack co rong khong " << endl;
//	cout << "\t\t3. Kiem tra stack da day chua " << endl;
//	cout << "\t\t4. Them phan tu vao stack " << endl;
//	cout << "\t\t5. Lay phan tu tu stack ra " << endl;
//	cout << "\t\t6. doi so " << endl;
//	cout << "\t\t0. Thoat " << endl;
//	cout << "Chon 1 chuc nang( 0-6 ): ";
//}
//string Change( int n, int He )
//{
//	int Dem = 0,x;
//	char C[16]="";
//	while( n > 0 )
//	{
//		Push(n%He);
//		n /= He;
//	}
//	while( !Is_Empty() )
//	{
//		Pop(x);
//		if( x >= 0 && x <= 9 )
//			C[Dem] = x;
//		else
//			C[Dem] = (char)(x+55);
//	}
//	return C;
//}