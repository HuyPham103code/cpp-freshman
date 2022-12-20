//#include<iostream>
//using namespace std;
//struct Node
//{
//	int Value;
//	Node * Link;
//};
//Node* front,*rear;
//void Init();
//bool Is_Empty();
//void Push( int x );
//int Pop( int &x );
//int main()
//{
//	int n,x;
//	Init();
//	if( Is_Empty() )
//		cout << "Queue dang rong " << endl;
//	else
//		cout << "Hang doi khong rong " << endl;
//	cout << "Nhap so luong phan tu: ";
//	cin >> n;
//	for( int i = 0; i < n; i++ )
//	{
//		cout << "So thu " << i+1 << " = ";
//		cin >> x;
//		Push(x); //thêm x vào hàng đợi
//	}
//	while( !Is_Empty() )
//	{
//		Pop(x);
//		cout << x << "\t";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
//void Init()
//{
//	front = NULL;
//	rear = NULL;
//}
//bool Is_Empty()
//{
//	return front == NULL;
//}
//void Push( int x )
//{
//	Node* p = new Node;
//	p->Value = x;
//	p->Link = NULL;
//	if( rear == NULL ) //Nếu queue rỗng thì cả front và rear đều bằng p
//		front = p;     // vì chỉ có 1 phân tử trong hàng đợi
//	else
//		rear->Link = p; // còn nếu khác rỗng thì thêm vào cuối/ chỉ cập nhật rear
//	rear = p;
//}
//int Pop( int &x )
//{
//	if( front == NULL )
//		return 0;
//	else
//	{
//		Node* p = front;
//		x = p->Value;
//		front = front->Link;
//		if( front == NULL ) // nếu chỉ còn 1 phần tử mà lấy ra hết thì cả 2 thằng đều bằng NULL;
//			rear = NULL;    // cập nhật lại như Init()
//		delete p;
//		return 1;
//	}