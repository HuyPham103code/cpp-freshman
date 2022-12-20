//#include<iostream>
//#define Max 100
//using namespace std;
//struct To_Hop
//{
//	int x;
//};
//struct Node
//{
//	To_Hop a[Max];
//	int n;
//	void Nhap()
//	{
//		for( int i = 0; i < n; i++ )
//		{
//			cout << "Nhap so thu " << i+1 << " = ";
//			cin >> a[i].x;
//		}
//	}
//	void Xuat()
//	{
//		for( int i = 0; i < n; i++ )
//			cout << a[i].x << "\t";
//	}
//};
//void Xoa( Node &S, int pos )
//{
//	for( int i = pos; i < S.n; i++ )
//		S.a[i].x = S.a[i+1].x;
//	S.n--;
//}
//void Rut_Gon( Node &S )
//{
//	int tam;
//	for( int i = 0; i < S.n; i++ )
//	{
//		for( int j = i+1; j < S.n; j++ )
//		{
//			if( S.a[i].x > S.a[j].x )
//			{
//				tam = S.a[i].x;
//				S.a[i].x = S.a[j].x;
//				S.a[j].x = tam;
//			}
//			if( S.a[i].x == S.a[j].x )
//				Xoa( S,j );
//		}
//	}
//}
//// Giao của 2 tổ hợp
//void Giao( Node A, Node B )
//{
//	Node C;
//	int dem = 0;
//	for( int i = 0; i < A.n; i++ )
//	{
//		for( int j = 0; j < B.n; j++ )
//		{
//			if( A.a[i].x == B.a[j].x )
//			{
//				C.a[dem].x = A.a[i].x;
//				dem++;
//			}
//		}
//	}
//	C.n = dem;
//	if( C.n == 0 )
//		cout << "Khong co phan ti giao " << endl;
//	else
//		C.Xuat();
//}
//// a/b = { ... }
//void Hieu(  Node A, Node B )
//{
//	//Node C;
//	for( int i = 0; i < A.n; i++ )
//	{
//		for(int j = 0; j < B.n; j++ )
//		{
//			if( A.a[i].x == B.a[j].x )
//				Xoa( A,i );
//		}
//	}
//	Rut_Gon( A );
//	A.Xuat();
//}