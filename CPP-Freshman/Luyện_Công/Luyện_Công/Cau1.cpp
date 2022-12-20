//#include "Cau1.h"
//int main(){
//	int op;
//	Orders A;
//	A.Init();
//	do{
//		A.Menu();
//		cout << "Enter your option(0-9): ";
//		cin >> op;
//		system("cls");
//		switch(op){
//			case 1:
//				cout << "\n\t\tImport List " << endl;
//				A.ImportData();
//				cout << "Done!" << endl;
//				break;
//			case 2:
//				cout << "\n\t\tList orders" << endl;
//				A.Display();
//				break;
//			case 3:
//				cout << "\n\t\tAdd a order" << endl;
//				A.Add_1_Order();break;
//			case 4:
//				cout << "\n\t\tRemove a order" << endl;
//				A.Remove();
//				break;
//			case 5:
//				cout << "\n\t\tsearch a order" << endl;
//				A.Search();
//				break;
//			case 6:
//				cout << "\n\t\tsearch a order by date" << endl;
//				A.SearchDate();break;
//			case 7:
//				cout << "\n\t\tTotal income in a day" << endl;
//				A.TotalIncomeDay();
//				break;
//			case 8:
//				cout << "\n\t\tQuickSort descending by day" << endl;
//				A.QuickSort();
//				break;
//			case 9:
//				cout << "\n\t\tHeapSort descending by total order value" << endl;
//				A.HeapSort();
//				break;
//			case 0:
//				break;
//			default:
//				cout << "Wrong! please enter again! " << endl;
//		}
//	}while( op != 0 );
//	A.Cancel();
//	system("pause");
//	return 0;
//}