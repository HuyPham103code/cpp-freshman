//#include<iostream>
//using namespace std;
//struct Node
//{
//	int Value;
//	Node* Link;
//};
//Node *First;
//void Init();
//bool Is_Empty();
//void Push( int x );
//int Pop( int &x );
//void Change( int n, int He );
//int main()
//{
//	int x, n,He;
//	Init();
//	if( Is_Empty() )
//		cout << "stack rong " << endl;
//	else
//		cout << "stack khong rong " << endl;
//	cout << "Nhap so phan tu muon cho vao stack: ";
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
//	cout << "\n\t\tDoi he " << endl;
//	cout << "Nhap so muon doi: ";
//	cin >> n;
//	do
//	{
//		cout << "Nhap he muon doi: ";
//		cin >> He;
//		if( He != 2 && He != 8 && He != 16 )
//			cout << "Nhap sai! Vui long nhap lai! He( 2,8,16 )" << endl;
//	}while( He != 2 && He != 8 && He != 16 );
//	cout << "Sau khi doi " << endl;
//	Change( n,He );
//	cout << endl;
//	system("pause");
//	return 0;
//}
//void Init()
//{
//	First = NULL;
//}
//bool Is_Empty()
//{
//	return First == NULL;
//}
//void Push( int x )
//{
//	Node* p = new Node; // khởi tạo biến p bằng first
//	p->Value = x;
//	p->Link = First; // phần tử mới thêm vào sẽ nằm ở đầu danh sách
//	First = p;
//}
//int Pop( int &x )
//{
//	if( First != NULL ) // có thì mới lấy
//	{
//		Node* p = First;
//		x = p->Value;
//		First = First->Link; //xóa phần tử đầu
//		delete p;
//		return 1;
//	}
//	return 0; //Rỗng thì trả về 0
//}
//void Change( int n, int He )
//{
//	int x;
//	while( n > 0 )
//	{
//		Push( n%He );
//		n /= He;
//	}
//	while( !Is_Empty() )
//	{
//		Pop( x );
//		if( x >= 0 && x <= 9 )
//			cout << x;
//		else
//			cout << (char)(x+55);
//	}
//}