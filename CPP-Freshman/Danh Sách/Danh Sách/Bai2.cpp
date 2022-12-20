//#include<iostream>
//#include"ham2.cpp"
//using namespace std;
//int main()
//{
//	Node* First;
//	Node a;
//	First = NULL;
//	a.Init( First );
//	int x;
//	do
//	{
//		cout << "Nhap Danh Sach: ";
//		cin >> x;
//		if( x != 0 )
//			a.Add_L( First,x );
//	}while( x != 0 );
//	cout << "Danh sach da nhap: " << endl;
//	a.Export( First ); // Xuất danh sách đã nhập
//	cout << "Muon tim gi: ";
//	cin >> x;
//	if( a.Find( First,x ) != NULL )
//		cout << "tim thay " << endl;
//	cout << "\nNhap phan tu muon xoa truoc: ";
//	cin >> x;
//	a.Del_After( First,x );
//	cout << "\nMang sau khi xoa " << endl;
//	a.Export( First );
//	//cout << "Nhap phan tu vao dau danh sach: "; // Thêm 1 phần tử vào đầu danh sách
//	//cin >> x;
//	//a.Add_F( First,x );
//	//a.Export( First ); // thêm xong rồi xuất lại danh sách
//	//cout << "Nhap phan tu vao cuoi danh sach: "; // Thêm 1 phần tử vào cuối danh sách
//	//cin >> x;
//	//a.Add_L( First,x );
//	//a.Export( First ); // thêm xong rồi xuất lại danh sách
//	//cout << "Danh sach sau khi xoa phan tu dau: " << endl;
//	//a.Remove_F( First ); // Xóa phần tử đầu
//	//a.Export( First );
//	//cout << "Danh sach sau khi xoa phan tu cuoi: " << endl;
//	//a.Remove_L( First ); // Xóa phần tử cuối
//	//a.Export( First );
//	//cout << "Nhap gia tri can xoa: "; // Tìm và xóa phần tử
//	//cin >> x;
//	//a.Find_And_Remove_All( First,x );
//	//a.Export( First );
//	//cout << "Danh sach da co thu tu: " << endl;
//	//a.Arrange ( First );
//	//a.Export( First );
//	a.Huy( First );
//	system("pause");
//	return 0;
//}