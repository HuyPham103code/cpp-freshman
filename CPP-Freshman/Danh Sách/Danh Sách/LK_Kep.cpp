//#include "Ham_LK_Kep.h"
//int main()
//{
//	Node A;
//	int x,Choose;
//	Init();
//	do
//	{
//		A.Menu();
//		cout << "Enter option: ";
//		cin >> Choose;
//		system("cls");
//		if( Choose > 10 || Choose < 0 )
//			cout << "Wrong! Please enter again! " << endl;
//		switch (Choose)
//		{
//		case 0:
//			cout << "\n\t\tExport List 2 " << endl;
//			Export();break;
//		case 1:
//			cout << "\n\t\tExport List " << endl;
//			Export1();break;
//		case 2:
//			cout << "\n\t\tAdd first on list " << endl;
//			cout << "Enter number that you want to add: ";
//			cin >> x;
//			AddF(x);
//			cout << "Done! " << endl;break;
//		case 3:
//			cout << "\n\t\tAdd last on list " << endl;
//			cout << "Enter number that you want to add: ";
//			cin >> x;
//			AddL(x);
//			cout << "Done! " << endl;break;
//		case 4:
//			cout << "\n\t\tDel first on list " << endl;
//			DelF();
//			break;
//		case 5:
//			cout << "\n\t\tAdd last on list " << endl;
//			DelL();
//			break;
//		case 6:
//			cout << "\n\t\tFind a element on list " << endl;
//			cout << "Enter number that you want to find: ";
//			cin >> x;
//			if( Find(x) != NULL )
//				cout << "Find it! " << endl;
//			else
//				cout << "Don't find " << endl;
//			break;
//		case 7:
//			cout << "\n\t\tDelete a element before X " << endl;
//			cout << "Enter X = ";
//			cin >> x;
//			Del_Before( x );
//			break;
//		case 8:
//			cout << "\n\t\tDelete a element after X " << endl;
//			cout << "Enter X = ";
//			cin >> x;
//			Del_After( x );
//			break;
//		}
//	}while( Choose != 10 );
//	Huy();
//	system("pause");
//}