//#include<iostream>
//#define Max 100
//using namespace std;
//struct Da_Thuc
//{
//	double a; // hệ số
//	int n; // số mũ
//};
//struct Node
//{
//	Da_Thuc s[Max]; //khai báo mảng đa thức
//	void Menu()
//	{
//		cout << "1. Nhap da thuc " << endl;
//		cout << "2. Xuat da thuc " << endl;
//		cout << "3. Cong 2 da thuc " << endl;
//		cout << "4. Tru 2 da thuc " << endl;
//		cout << "5. Nhan 2 da thuc " << endl;
//		cout << "6. Chia 2 da thuc " << endl;
//		cout << "7. Thoat " << endl;
//	}
//	void Nhap_1_Da_Thuc( int pos) //Thêm đa thức vào đầu mảng
//	{
//		 int Mu,Hso;
//		cout << "Nhap he so a = ";
//		cin >> Hso;
//		cout << "Nhap so mu n = ";
//		cin >> Mu;
//		s[pos].a = Hso;
//		s[pos].n = Mu;
//	}
//	void Nhap( int N ) //Nhập mảng đa thức ( N : số lượng phần tử trong đa thức )
//	{
//		for( int i = 0; i < N; i++ )
//		{
//			cout << "\n\tNhap so thu " << i+1 << endl;
//			Nhap_1_Da_Thuc(i);
//		}
//	}
//	void Xuat( int N) // ( N : số lượng phần tử trong đa thức )
//	{
//		for( int i = 0; i < N; i++ )
//		{
//			cout << s[i].a << "X^" << s[i].n;
//			if( i != N-1 )
//				cout << " + ";
//		}
//		cout << endl;
//	}
//	void Xoa( int pos, int &N )
//	{
//		for( int i = pos; i < N; i++ )
//			s[i] = s[i+1];
//		N--;
//	}
//	void Rut_Gon( int &N) // Rút gọn và sắp xếp đa thức
//	{
//		Da_Thuc tam;
//		for( int i = 0; i < N; i++ )
//		{
//			for( int j = i+1; j < N; j++ )
//			{
//				if( s[i].n < s[j].n ) // đổi chỗ số mũ
//				{
//					tam = s[i];
//					s[i] = s[j];
//					s[j] = tam;
//				}
//				if( s[i].n == s[j].n ) //nếu bằng thì cộng hệ số và xóa 1 thằng đi
//				{
//					s[i].a += s[j].a;
//					Xoa( j,N );
//				}
//			}
//		}
//	}
//};
//// n1: độ dài dt1, n2 độ dài dt2
//void Cong( Da_Thuc DT1[], Da_Thuc DT2[], int n1, int n2 )
//{
//	Node A;
//	int N = n1 + n2;
//	for( int i = 0; i < N; i++ )
//	{
//		A.s[i] = DT1[i]; //chép các phần tử của đa thức 1 vào mảng a
//		if( i == n1 - 1 ) //hết đa thức 1 thì vào đa thức 2
//		{
//			for( int j = 0; j < n2; j++ )
//			{
//				i++;
//				A.s[i] = DT2[j]; //chép các phần tử của đa thức 2 vào mảng a
//			}
//		}
//	}
//	A.Rut_Gon(N);
//	A.Xuat(N);
//}
////trừ 2 đa thức cũng giống cộng 2 đa thức nhưng đa thức thứ 2 phải đổi dấu
//void Tru( Da_Thuc DT1[], Da_Thuc DT2[], int n1, int n2 )
//{
//	Node A;
//	int N = n1 + n2;
//	for( int i = 0; i < N; i++ )
//	{
//		A.s[i] = DT1[i]; //chép các phần tử của đa thức 1 vào mảng a
//		if( i == n1 - 1 ) //hết đa thức 1 thì vào đa thức 2
//		{
//			for( int j = 0; j < n2; j++ )
//			{
//				i++;
//				A.s[i].n = DT2[j].n; //chép các phần tử của đa thức 2 vào mảng a
//				A.s[i].a = -DT2[j].a; //mũ bằng mũ còn hệ số thì thêm dấu trừ
//			}
//		}
//	}
//	A.Rut_Gon(N);
//	A.Xuat(N);
//}
//void Nhan( Da_Thuc DT1[], Da_Thuc DT2[], int n1, int n2 )
//{
//	Node A;
//	int dem = 0;
//	for( int i = 0; i < n1; i++ )
//	{
//		for( int j = 0; j < n2; j++ )
//		{
//			A.s[dem].a = DT1[i].a * DT2[j].a;
//			A.s[dem].n = DT1[i].n + DT2[j].n;
//			dem++;
//		}
//	} 
//	A.Rut_Gon(dem); //vì xử lý xong là đếm đã cộng 1 rồi nên k cần cộng nữa
//	A.Xuat(dem);
//}
//void Chia( Da_Thuc DT1[], Da_Thuc DT2[], int n1, int n2 )
//{
//	Node KQ,A;
//	int i = n1;
//	for( int i = 0; i < n1; i++ ) // gán mảng a cho 
//		A.s[i] = DT1[i];
//	while( i >= n2 )
//	{
//		i--;
//	}
//
//}