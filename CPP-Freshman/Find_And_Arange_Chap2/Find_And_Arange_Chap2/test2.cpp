#include"test2.h"
int main()
{
	Test A;
	int x,Choose;
	do
	{
		A.Menu();
		cin >> Choose;
		system("cls");
		switch (Choose)
		{
		case 1:
			cout << "\n\tEnter array " << endl;
			cout << "Enter the number of array: ";
			cin >> A.n;
			A.Input();
			A.SS();break;
		case 2:
			cout << "\n\tExport array " << endl;
			A.Export(A.a);break;
		case 3:
			cout << "\n\tInsertion Sort " << endl;
			A.InsertionSort();break;
		case 4:
			cout << "\n\tSelection Sort " << endl;
			A.SelectionSort();break;
		case 5:
			cout << "\n\tInterChange Sort " << endl;
			A.InterChangeSort();break;
		case 6:
			cout << "\n\tBubble Sort " << endl;
			A.BubbleSort();break;
		case 0:
			break;
		default:
			cout << "Wrong! please enter again! " << endl;
		}
	}while( Choose != 0 );
	system("pause");
	return 0;
}