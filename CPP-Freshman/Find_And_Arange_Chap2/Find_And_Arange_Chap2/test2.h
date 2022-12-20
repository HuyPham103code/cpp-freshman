#include<iostream>
#include<cstdlib>
#include<ctime>
#define Max 50
using namespace std;
struct Test
{
	int a[Max],b[Max];
	int n;
	void Menu()
	{
		cout << "\t1. Enter array " << endl;
		cout << "\t2. Export array " << endl;
		cout << "\t3. Insertion Sort " << endl;
		cout << "\t4. Selection Sort array " << endl;
		cout << "\t5. InterChange Sort " << endl;
		cout << "\t6. Bubbles Sort " << endl;
		cout << "\t7. Search normal " << endl;
		cout << "\t8. Search bynary " << endl;
		cout << "\t0. Exit " << endl;
		cout << "Enter your option(0-8): ";
	}
	void Input()
	{
		srand(time(NULL));
		for( int i = 0; i < n; i++ )
			a[i] = rand() % 50 + 1;
	}
	void Export( int a[] )
	{
		for( int i = 0; i < n; i++ )
			cout << a[i] << "\t";
		cout << endl;
	}
	void SS()
	{
		for( int i = 0; i < n; i++ )
			b[i] = a[i];
	}
	void InsertionSort()
	{
		Export(b);
		int x,j;
		for( int i = 1; i < n; i++ )
		{
			x = a[i]; // stored value that comparing
			j = i-1;
			while( j >= 0 && a[j] > x )
			{
				a[j+1] = a[j];
				j--;
			}
			a[j+1] = x;
		}
		Export(a);
	}
	void Swap( int &a, int &b )
	{
		int c = a;
		a = b;
		b = c;
	}
	void SelectionSort()
	{
		Export(b);
		int Min_Pos;
		for( int i = 0; i < n-1; i++ )
		{
			Min_Pos = i;
			for( int j = i+1; j < n; j++ )
				if( a[j] < a[Min_Pos] )
					Min_Pos = j;
			Swap( a[Min_Pos], a[i] );
		}
		Export(a);
	}
	void InterChangeSort()
	{
		Export(b);
		for( int i = 0; i < n-1; i++ )
			for( int j = i+1; j < n; j++ )
				if( a[i] > a[j] )
					Swap( a[i], a[j] );
		Export(a);
	}
	void BubbleSort() // nổi bọt
	{
		Export(b);
		for( int i = 0; i < n; i++ )
			for( int j = n-1; j > i; j-- ) // đổi 2 số kế bên nhau
				if( a[j-1] > a[j] )
					Swap( a[j-1],a[j] );
		Export(a);
	}
	int Search_Normal( int x )
	{
		for( int i = 0; i < n; i++ )
			if( a[i] == x )
				return i;
		return -1;
	}
	int Search_Binary( int x ) // làm bình thường
	{
		int left = 0, right = n-1, mid;
		while( left >= right)
		{
			mid = (left+right)/2;
			if( a[mid] == x ) return mid; // tìm thấy thì trả về vị trí 
			if( a[mid] < x ) // x lớn hơn => nằm ở bên phải
				left = mid+1;
			else
				right = mid-1;
		}
		return -1;
	}
	int Search3( int x, int left, int right ) // đệ quy
	{
		if( left > right ) return -1; // trường hợp không tìm thấy
		int mid = (left+right)/2;
		if( a[mid] == x ) return mid;// tìm thấy và return vị trí
		if( a[mid] < x ) return Search3( x,mid+1,right );
		else
			return Search3( x,left,mid-1 );
	}
};