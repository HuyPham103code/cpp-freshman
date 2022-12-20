//#include "Unit1.h"
//int main()
//{
//	Function A;
//	int Choose,x;
//	do
//	{
//		A.Menu();
//		cin >> Choose;
//		system("cls");
//		switch (Choose)
//		{
//		case 1:
//			cout << "\n\t\tEnter Array " << endl;
//			cout << "Enter the number of array: ";
//			cin >> A.n;
//			A.Input();
//			A.Comp();break;
//		case 2:
//			cout << "\n\t\tExport Array " << endl;
//			A.Output(A.a);break;
//		case 3:
//			cout << "\n\t\tInsertion Sort " << endl;
//			A.InsertionSort();break;
//		case 4:
//			cout << "\n\t\tSelection Sort " << endl;
//			A.SelectionSort();break;
//		case 5:
//			cout << "\n\t\tInterChange Sort " << endl;
//			A.InterChangeSort();break;
//		case 6:
//			cout << "\n\t\tBobble Sort " << endl;
//			A.BubbleSort();break;
//		case 7:
//			cout << "\n\t\tSeach normal " << endl;
//			cout << "Enter the number you want to find: ";
//			cin >> x;
//			if( A.Search(x) == -1 )
//				cout << "Not Find! " << endl;
//			else
//				cout << "Find it" << endl;break;
//		case 8:
//			cout << "\n\t\tSeach Bynary " << endl;
//			cout << "Enter the number you want to find: ";
//			cin >> x;
//			if( A.BinarySearch(x,0,A.n-1) == -1 )
//				cout << "Not Find! " << endl;
//			else
//				cout << "Find it" << endl;break;
//		case 9:
//			cout << "\n\t\tSeach Bynary 2 " << endl;
//			cout << "Enter the number you want to find: ";
//			cin >> x;
//			if( A.BinarySearch2(x) == -1 )
//				cout << "Not Find! " << endl;
//			else
//				cout << "Find it" << endl;break;
//		case 0:
//			break;
//		default:
//			cout << "Wrong! please enter again " << endl;
//		}
//	}while( Choose != 0 );
//	system("pause");
//	return 0;
//}