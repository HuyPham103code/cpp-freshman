//#include<iostream>
//#include<cstdlib>
//#include<time.h>
//#define Max 50
//using namespace std;
//struct Function
//{
//	int a[Max],b[Max];
//	int n;
//	//Nhập mảng số nguyên
//	void Input()
//	{
//		srand(time(NULL));
//		for( int i = 0; i < n; i++ )
//			a[i] = rand() % 50 + 1;
//	}
//	void Output( int a[] )
//	{
//		for( int i = 0; i < n; i++ )
//			cout << a[i] << "\t";
//		cout << endl;
//	}
//	void Comp()
//	{
//		for( int i = 0; i < n; i++ )
//			b[i] = a[i];
//	}
//	void Menu()
//	{
//		cout << "\t0. Exit " << endl;
//		cout << "\t1. Enter Array " << endl;
//		cout << "\t2. Export Array " << endl;
//		cout << "\t3. InsertionSort " << endl;
//		cout << "\t4. SeclectionSort " << endl;
//		cout << "\t5. InterChangeSort " << endl;
//		cout << "\t6. BubbleSort " << endl;
//		cout << "\t7. Find " << endl;
//		cout << "\t8. Find Binary " << endl;
//		cout << "\t9. Find Binary 2 " << endl;
//		cout << "Enter yout option(0-9): ";
//	}
//	void InsertionSort()
//	{
//		int x,j;
//		Output(b);
//		for( int i = 1; i < n; i++ )
//		{
//			x = a[i];
//			j = i - 1;
//			while( j >= 0 && a[j] > x )
//				{
//					a[j+1] = a[j]; // đẩy các số lớn hơn x ra đằng sau
//					j--;
//				}             
//			a[j+1] = x;
//		}
//		Output(a);
//	}
//	void Swap( int &a, int &b )
//	{
//		int c;
//		c = a;
//		a = b;
//		b = c;
//	}
//	void SelectionSort()
//	{
//		Output(b);
//		int Min_pos;
//		for( int i = 0; i < n-1; i++ )
//		{
//			Min_pos = i;
//			for( int j = i+1; j < n; j++ )
//				if( a[j] < a[Min_pos] ) // tìm vị trí nhỏ nhất trong mảng 
//					Min_pos = j;
//			Swap( a[i], a[Min_pos] );
//		}
//		Output(a);
//	}
//	void InterChangeSort() //như bthg
//	{
//		Output(b);
//		for( int i = 0; i < n-1; i++ )
//			for( int j = i+1; j < n; j++ )
//				if( a[i] > a[j] )
//					Swap( a[i], a[j] );
//		Output(a);
//	}
//	void BubbleSort()
//	{
//		Output(b);
//		for( int i = 0; i < n-1; i++ )
//			for( int j = n-1; j > i; j-- )
//				if( a[j-1] > a[j] )
//					Swap( a[j-1], a[j]);
//		Output(a);
//	}
//	int Search( int x )
//	{
//		Output(a);
//		for( int i = 0; i < n; i++ )
//			if( a[i] == x )
//				return i;
//		return -1;
//	}
//	int BinarySearch( int x, int left, int right ) // đệ quy
//	{
//		if( left > right ) return -1;
//		int mid = (left + right)/2;
//		if( a[mid] == x ) return mid; // tìm thấy thì trả về vị trí tìm thấy
//		if( a[mid] < x ) // x nằm ở bên phải thì cập nhật left
//			return BinarySearch( x, mid+1, right );
//		else
//			return BinarySearch( x, left, mid-1 );
//	}
//	int BinarySearch2( int x )
//	{
//		int left = 0, right = n-1, mid;
//		while( left <= right )
//		{
//			mid = (left+right)/2;
//			if( a[mid] == x ) return mid; // tìm thấy thì trả về vị trí
//			if( a[mid] < x ) // x lớn hơn -> nằm ở bên phải
//				left = mid + 1;
//			else
//				right = mid-1; // x is smaller so it's on the left side
//		}
//		return -1;
//	}
//};