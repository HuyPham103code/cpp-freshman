//#include<iostream>
//#include<iomanip>
//#include"Listbt1.cpp"
//#define Max 100
//using namespace std;
//int main()
//{
//	int Choose,x,pos;
//	List L;
//	cout << "Enter the munber of students: ";
//	cin >> L.n;
//	do
//	{
//		L.Menu();
//		cin >> Choose;
//		system("cls");
//		switch ( Choose )
//		{
//		case 1:
//			cout << "\n\t\tEnter Array " << endl;
//			L.Enter_Array();break;
//		case 2:
//			cout << "\n\t\tExport Array " << endl;
//			L.Export_Array();break;
//		case 3:
//			cout << "\n\t\tFind Number " << endl;
//			cout << "Enter the munber you want to find: ";
//			cin >> x;
//			if( L.Find(x) != -1 )
//				cout << "There is " << x << " in the array " << endl;
//			else
//				cout << x << " not found in the array " << endl;
//			break;
//		case 4:
//			cout << "\n\t\tAdd First  " << endl;
//			cout << "Enter the number you want to add: ";
//			cin >> x;
//			L.AddF(x);
//			cout << "\tArray after add " << endl;
//			L.Export_Array();break;
//		case 5:
//			cout << "\n\t\tAdd Last  " << endl;
//			cout << "Enter the number you want to add: ";
//			cin >> x;
//			L.AddL(x);
//			cout << "\tArray after add " << endl;
//			L.Export_Array();break;
//		case 6:
//			cout << "\n\t\tAdd a number at position i " << endl;
//			cout << "Enter the number you want to add: ";
//			cin >> x;
//			cout << "Enter position you want to add: ";
//			cin >> pos;
//			L.Add_At( x,pos );
//			cout << "\tArray after add " << endl;
//			L.Export_Array();break;
//		case 7:
//			cout << "\n\t\tRemove First " << endl;
//			L.Remove_F();
//			cout << "\tArray after remove " << endl;
//			L.Export_Array();break;
//		case 8:
//			cout << "\n\t\tRemove Last " << endl;
//			L.Remove_L();
//			cout << "\tArray after remove " << endl;
//			L.Export_Array();break;
//		case 9:
//			cout << "\n\t\Remove a number at position i " << endl;
//			cout << "Enter position you want to remove: ";
//			cin >> pos;
//			L.Remove_At( pos );
//			cout << "\tArray after remove " << endl;
//			L.Export_Array();break;
//		case 10:
//			cout << "\t\t10. Find and remove a value at first time" << endl;
//			cout << "Enter the number want to remove in the first time: ";
//			cin >> x;
//			L.Find_And_Remove_First(x);break;
//		case 11:
//			cout << "\t\t11. Find and remove all value x in array" << endl;
//			cout << "Enter the number want to remove in array: ";
//			cin >> x;
//			L.Find_And_Remove_All(x);break;
//		case 0:
//			break;
//		default:
//			cout << "Wrong! Please enter again! " << endl;
//		}
//	}while( Choose != 0 );
//	system("pause");
//	return 0;
//}