//#include"test1.h"
//int main()
//{
//	ifstream ifs("D:\Data.txt",ios::in);
//	ofstream ofs("D:\Data1.txt",ios::out);
//	string str;
//	Init();
//	int Choose;
//	do
//	{
//		Menu();
//		cin >> Choose;
//		system("cls");
//		switch (Choose)
//		{
//		case 1:
//			cout << "\n\t\tRead file " << endl;
//			ReadFile(ifs);
//			break;
//		case 2:
//			cout << "\n\t\tList " << endl;
//			Export();break;
//		case 3:
//			cout << "\n\t\tExport by gender " << endl;
//			ExportByGender();break;
//		case 4:
//			Add1Employee();break;
//		case 5:
//			cout << "\n\t\tRemove 1 employee " << endl;
//			cout << "\tEnter ID: ";
//			fflush(stdin);
//			getline( cin,str );
//			Remove( str );
//			Export();break;
//		case 6:
//			cout << "\n\t\tWrite list to file " << endl;
//			WriteFile(ofs);break;
//		case 0:break;
//		}
//	}while( Choose != 0 );
//	Cannel();
//	system("pause");
//	return 0;
//}