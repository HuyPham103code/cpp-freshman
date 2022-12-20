//#include<iostream>
//#include<iomanip>
//#define Max 100
//using namespace std;
//struct List
//{
//	int a[Max];
//	int n;
//	void Menu()
//	{
//		cout << "\n\t\t1. Enter Array" << endl;
//		cout << "\t\t2. Export Array" << endl;
//		cout << "\t\t3. Find a value" << endl;
//		cout << "\t\t4. Add a value at first of list" << endl;
//		cout << "\t\t5. Add a value at last of list" << endl;
//		cout << "\t\t6. Add a value at a position at list" << endl;
//		cout << "\t\t7. Remove a value at first of list" << endl;
//		cout << "\t\t8. Remove a value at last of list" << endl;
//		cout << "\t\t9. Remove a value at a position at list" << endl;
//		cout << "\t\t10. Find and remove a value at first time" << endl;
//		cout << "\t\t11. Find and remove all value x in array" << endl;
//		cout << "\t\t0. Exit" << endl;
//		cout << "phease choose a option(0-11): ";
//	}
//	void Enter_Array()
//	{
//		for( int i = 0; i < n; i++ )
//		{
//			cout << "a["<<i+1<<"] = ";
//			cin >> a[i];
//		}
//	}
//	void Export_Array()
//	{
//		for( int i = 0; i < n; i++ )
//			cout << a[i] << "\t";
//		cout << endl;
//	}
//	int Find( int x )
//	{
//		for( int i = 0; i < n; i++ )
//			if( a[i] == x )
//				return i;
//		return -1; // không thầy thì về -1, thấy thì trả về vị trí 
//	}
//	void AddF( int x )
//	{
//		if( n >= 100 ) return; // full mảng r chỗ đâu mà thêm
//		for( int i = n; i > 0; i-- )
//			a[i] = a[i-1];
//		a[0] = x;
//		n++;
//	}
//	void AddL( int x )
//	{
//		if( n >= 100 ) return; // mảng full
//		a[n] = x;
//		n++;
//	}
//	void Add_At( int x, int pos )
//	{
//		if( n >= 100 || pos < 0 || pos > 100 )return; // điều kiện cho vị trí (0-100)
//		if( pos > n ) pos = n;//  nhập vị trí lớn hơn n thì nó nó nằm cuối
//		for( int i = n; i >= pos; i-- )
//			a[i] = a[i-1];
//		a[pos] = x;
//		n++;
//	}
//	void Remove_F()
//	{
//		if( n== 0 )return; // mảng rỗng
//		for( int i = 0; i < n; i++ )
//			a[i] = a[i+1];
//		n--;
//	}
//	void Remove_L()
//	{
//		if( n<= 0)return; //Mảng 0 có phần tử thì sao xóa
//		if( n== 0 )return;
//		n--;
//	}
//	void Remove_At( int pos )
//	{
//		if( n <= 0)return; // Mảng rỗng thì k xóa được
//		if( pos > n ) pos = n-1; //vị trí muốn xóa lớn hơn n thì cho mằng vị trí cuối cùng luôn
//		if( pos < 0 ) pos = 0; // vị trí muốn xóa nhỏ hơn 0 thì cứ cho bằng 0
//		for( int i = pos; i < n; i++ )
//			a[i] = a[i+1];
//		n--;
//	}
//	void Find_And_Remove_First( int x ) // xóa lần đầu gặp
//	{
//		int pos = Find(x);
//		if( pos != 1 )
//			Remove_At( pos );
//		else
//			cout << "Khong tim thay phan tu " << x << " de xoa " << endl;
//	}
//	void Find_And_Remove_All( int x ) // xóa lần sau cùng gặp
//	{
//		int pos = Find(x);
//		if( pos != -1 )
//		while( pos != -1 )
//		{
//			Remove_At( pos );
//			pos = Find(x);
//		}
//		else
//			cout << "Khong tim thay phan tu " << x << " de xoa " << endl;
//	}
//};