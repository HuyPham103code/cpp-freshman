//#include<iostream>
//#define Max 100
//using namespace std;
//int a[Max],Front, Rear; // đặt các biến
//void Init();
//bool Is_Empty(); 
//bool Is_Full();
//int Push( int x);
//int Pop( int &x );
//int Dao( int x );
//int main()
//{
//	int n,x;
//	Init();
//	if( Is_Empty() )        //Kiểm tra rỗng
//		cout << "Queue rong " << endl;
//	else
//		cout << "Queue khong rong " << endl;
//	if( Is_Full() )         //Kiểm tra đầy
//		cout << "Queue day " << endl;
//	else
//		cout << "Queue chua day " << endl;
//	cout << "Nhap so phan tu muon cho vao Queue: ";
//	cin >> n;
//	for( int i = 0; i < n; i++ )
//	{
//		cout << "So thu " << i+1 << " = ";
//		cin >>x;
//		Push( x );
//	}
//	cout << "\n\t\tXuat stack " << endl;
//	while( !Is_Empty() )
//	{
//		Pop( x );
//		cout << x << "\t";
//	}
//	cout << "\nNhap so muon dao nguoc: ";
//	cin >> n;
//	cout << n << " --> " << Dao(n) << endl;
//	system("pause");
//	return 0;
//}
//void Init()
//{
//	Front = -1;
//	Rear = -1;
//}
//bool Is_Empty()
//{
//	return Front == -1; //Kiểm tra rỗng
//}
//bool Is_Full()
//{
//	return ( Rear - Front ) == ( Max -1 ); //đk đầy ( đầy != tràn )
//}
//int Push( int x )
//{
//	if( Is_Full() ) // Queue đầy không chơi
//		return 0;
//	else   //Chưa đầy thì vào việc
//	{
//		if( Is_Empty() ) //Queue rỗng
//			Front = 0;    // Tăng Front lên 0 tí tăng rear sau
//		if( Rear == Max - 1 ) // bị tràn giả
//		{
//			for( int i = Front; i <= Rear; i++ )
//			{
//				a[i-Front] = a[i]; // Tịnh tiến cho về vị trí đầu tiên
//			}
//			Rear = Max - 1; // tịnh tiến rear Fornt đơn vị
//			Front = 0;  //Nhả front  về 0;
//		}
//		a[++Rear] = x; //nếu không vào đk rỗng,tràn thì cộng bình trg,
//		return 1; 
//	}
//}
//int Pop( int &x )
//{
//	if( Is_Empty() ) //còn cái nịt thì sao lấy
//		return 0;
//	else
//	{
//		x = a[Front++];
//		if( Front > Rear ) //nếu lấy hết rồi thì trả frotn,rear về -1
//			Init();
//		return 1;
//	}
//}
//int Dao( int n )
//{
//	int x,result = 0;
//	while( n > 0 )
//	{
//		Push( n%10 );
//		n /= 10;
//	}
//	while( !Is_Empty() )
//	{
//		Pop(x);
//		result = result*10 + x; 
//	}
//	return result;
//}