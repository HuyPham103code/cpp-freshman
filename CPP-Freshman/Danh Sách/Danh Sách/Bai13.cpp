//#include<iostream>
//using namespace std;
//struct Node
//{
//	int Value;
//	Node* Link;
//};
//Node* First;
//void Menu();
//void Init();
//Node* Create( int x );
//void Export();
//void AddF( int x );
//void AddL( int x );
//void RemoveF();
//void RemoveL();
//int Find( int x );
//void Find_And_Remove( int x );
//int main()
//{
//	Init();
//	int Choose,x;
//	do
//	{
//		Menu();
//		cout << "hay chon 1 chuc nang: ";
//		cin >> Choose;
//		system("cls");
//		switch (Choose)
//		{
//		case 1:
//			cout << "\n\t\tXuat" << endl;
//			Export();break;
//		case 2:
//			cout << "\n\t\them dau " << endl;
//			cout << "Nhap phan tu muon them: ";
//			cin >> x;
//			AddF(x);
//			Export();break;
//		case 3:
//			cout << "\n\t\tthem cuoi " << endl;
//			cout << "Nhap phan tu muon them: ";
//			cin >> x;
//			AddL(x);
//			Export();break;
//		case 4:
//			cout << "\n\t\Xoa dau " << endl;
//			RemoveF();
//			Export();break;
//		case 5:
//			cout << "\n\t\Xoa cuoi " << endl;
//			RemoveL();
//			Export();break;
//		case 6:
//			cout << "\n\t\tTim so " << endl;
//			cout << "Nhap so can tim: ";
//			cin >> x;
//			if( Find( x )  )
//				cout << "Tim thay " << x << " trong danh sach " << endl;
//			else
//				cout << x << " khong co trong danh sach " << endl;
//			break;
//		case 7:
//			cout << "\n\t\tTim va xoa " << endl;
//			cout << "Nhap so muon xoa: ";
//			cin >> x;
//			Find_And_Remove( x );break;
//		case 0:
//			break;
//		}
//	}while( Choose != 0 );
//	system("pause");
//	return 0;
//}
//void Menu()
//{
//	cout << "1. Xuat " << endl;
//	cout << "2. them dau " << endl;
//	cout << "3. them cuoi " << endl;
//	cout << "4. xoa dau " << endl;
//	cout << "5. Xoa cuoi " << endl;
//	cout << "6. Tim " << endl;
//	cout << "7. Tim va xoa  " << endl;
//	cout << "0. thoat" << endl;
//}
//void Init()
//{
//	First = NULL;
//}
//Node* Create( int x )
//{
//	Node* p = new Node;
//	p->Value = x;
//	p->Link = NULL;
//	return p;
//}
//void AddF( int x )
//{
//	Node* p = Create( x );
//	p->Link = First;
//	if( First != NULL ) // danh sách khác rỗng
//	{
//		Node* q = First;
//		while( q->Link != First ) // cập nhật link của thằng cuối cùng vào
//			q = q->Link;          // cái p vừa tạo tức là First mới
//		q->Link = p;
//	}
//	else    //rỗng thì chỏ vào chính nó
//		p->Link = p;
//	First = p;
//}
//void Export()
//{
//	Node* p = First;
//	if( First != NULL )
//	{
//		do
//		{
//			cout << p->Value << "\t";
//			p = p->Link;
//		}while( p != First );
//		cout << endl;
//	}
//}
//void AddL( int x )
//{
//	Node* p = Create(x);
//	p->Link = First; // vì p ở cuối nên sẽ trỏ vào First
//	if( First != NULL ) // nếu có nhiều hơn 1 phần tử
//	{
//		Node*q = First;
//		while( q->Link != First )
//			q = q->Link;
//		q->Link = p; // phần tử ở vị trí cuối cũng chỉ trỏ vào cái Node p vừa mới tạo
//	}
//	else
//	{
//		First = p;
//		First->Link = First; // First quay về First
//	}
//}
//void RemoveF()
//{
//	if( First == NULL )// có 1 phần tử thì khỏi xóa
//		return;
//	else
//	{
//		Node* p = First;
//		Node* q = First;
//		while( q->Link != First )
//			q = q->Link;
//		if( q != p ) // danh sách có nhiều hơn 1 phần tử
//		{
//			First = First->Link;
//			q->Link =  First;
//		}
//		else // có 1 phần tử xóa First đi thì còn NULL
//			First = NULL;
//		delete p;
//	}
//}
//void RemoveL()
//{
//	if( First != NULL )
//	{
//		Node* p = First;
//		Node* q = NULL;
//		while( p->Link != First )
//		{
//			q = p;
//			p = p->Link;
//		}
//		if( p != First ) // có chạy vòng while
//			q->Link = First;
//		else //chỉ có 1 phần tử
//			First = NULL;
//		delete p;
//	}
//	return;
//}
//int Find( int x )
//{
//	Node* p = First;
//	if( First != NULL )
//	{
//		do
//		{
//			if( p->Value == x ) //tìm thấy thì chả về luôn
//					return 1;
//			p = p->Link;
//		}while( p != First );
//	}
//	return 0;
//}
//void Find_And_Remove( int x )
//{
//	if( !Find(x) )
//		cout << "khong tim thay " << x << " trong mang " << endl;
//	else
//	{
//		Node* p = First;
//		Node* q = First;
//		while( p->Value != x ) // cái này là chắc chắn tìm thấy nên khỏi cần đk dừng
//		{
//			q = p;
//			p = p->Link;
//		}
//		if( p == First) // x nằm ở đầu thì xóa đầu
//			RemoveF();
//		else
//		{
//			q->Link = p->Link;
//			delete p;
//		}
//	}
//}