//#include<iostream>
//#include<string>
//using namespace std;
//struct Bank
//{
//	private:
//		string Name[10],AccountNumber[10],TK[10],MK[10];
//		int deposit[10],withdraw[10],SL, position;
//		int initial[10];
//	public:
//		Bank()
//		{
//			initial[0] = 0;
//			initial[1] = 0;
//			initial[2] = 0;
//			initial[3] = 0;
//			initial[4] = 0;
//			initial[5] = 0;
//			initial[6] = 0;
//			initial[7] = 0;
//			initial[8] = 0;
//			initial[9] = 0;
//			SL = 0;
//		}
//		void Menu1();
//		void Menu2();
//		void Create_Account();
//		void Deposit( int n );
//		void Withdraw( int n );
//		void Checking( int n );
//		void Accountholder_Detail( int n );
//		bool Log_In();
//		int Get_Position();
//};
//void Bank::Menu1()
//{
//	cout << "\n\t\tBANL MANAGEMENT " << endl;
//	cout << "1. Dang Nhap " << endl;
//	cout << "2. Tao 1 tai khoan " << endl;
//	cout << "3. Thoat " << endl;
//}
//void Bank::Menu2()
//{
//	cout << "\n\t\tBANL MANAGEMENT " << endl;
//	cout << "\t1.Nap tien " << endl;
//	cout << "\t2.Kiem Tra So Du " << endl;
//	cout << "\t3.Rut Tien " << endl;
//	cout << "\t4.Chi tiet tai khoan " << endl;
//	cout << "\t5.Thoat " << endl;
//}
//void Bank::Create_Account()
//{
//	fflush(stdin);
//	cout << "Nhap Tai Khoan: ";
//	getline( cin,TK[SL] );
//	fflush(stdin);
//	cout << "Nhap Mat Khau: ";
//	getline( cin,MK[SL] );
//	fflush(stdin);
//	cout << "Nhap Ten: ";
//	getline( cin,Name[SL] );
//	fflush(stdin);
//	cout << "Nhap So Tai Khoan: ";
//	getline( cin,AccountNumber[SL] );
//	initial[SL] = 0;
//	deposit[SL] = 0;
//	withdraw[SL] = 0;
//	SL++;
//}
//bool Bank::Log_In()
//{
//	string tk,mk;
//	fflush(stdin);
//	cout << "Nhap Tai Khoan: ";
//	getline( cin,tk );
//	fflush(stdin);
//	cout << "Nhap Mat khau: ";
//	getline( cin,mk );
//	for( int i = 0; i < SL; i++ )
//	{
//		if( tk == TK[i] && mk == MK[i] )
//		{
//			position = i;
//			return true;
//		}
//	}
//	return false;
//}
//void Bank::Deposit( int n )
//{
//	cout << "Enter Deposit: $ ";
//	cin >> deposit[n];
//	initial[n] += deposit[n];
//}
//int Bank::Get_Position()
//{
//	return position;
//}
//void Bank::Withdraw( int n )
//{
//	cout << "Enter Withdraw: $ ";
//	cin >> withdraw[n];
//	initial[n] -= withdraw[n];
//}
//void Bank::Checking( int n )
//{
//	cout << "So du kha dung: $" << initial[n] << endl;
//}
//void Bank::Accountholder_Detail( int n )
//{
//	cout << "\t\tName: " << Name[n] << endl;
//	cout << "\t\tTK: " << TK[n] << endl;
//	cout << "\t\tMK: " << MK[n] << endl;
//	cout << "\t\tSTK: " << AccountNumber[n] << endl;
//	cout << "\tSo du: $ " << initial[n];
//	cout << "\tDa gui: $ " << deposit[n];
//	cout << "\tDa rut: $ " << withdraw[n] << endl;
//} 
//int main()
//{
//	Bank B;
//	int Choose1,Choose2;
//	int pos;
//	do
//	{
//		B.Menu1();
//		cout << "Chon (1-3): ";
//		cin >> Choose1;
//		system("cls");
//		switch ( Choose1 )
//		{
//		case 1:
//			if( B.Log_In() )
//			{
//				pos = B.Get_Position();
//				do
//				{
//					B.Menu2();
//					cout << "Chon (1-5): ";
//					cin >> Choose2;
//					system("cls");
//					switch ( Choose2 )
//					{
//					case 1:
//						B.Deposit( pos );
//						break;
//					case 2:
//						B.Checking( pos );
//						break;
//					case 3:
//						B.Withdraw( pos );
//						break;
//					case 4:
//						B.Accountholder_Detail( pos );
//						break;
//					}
//					if( Choose2 < 1 || Choose2 > 5 )
//						cout << "Vui Long Chon Lai " << endl;
//				}while( Choose2 != 5 );
//				break;
//			}
//			else
//			{
//				cout << "Dang Nhap That Bai " << endl;break;
//			}
//		case 2:
//			cout << "\t\tTao Tai Khoan " << endl;
//			B.Create_Account();break;
//		}
//		if( Choose1 < 1 || Choose1 > 3 )
//					cout << "Vui Long Chon Lai " << endl;
//	}while( Choose1 != 3 );
//	system("pause");
//	return 0;
//}