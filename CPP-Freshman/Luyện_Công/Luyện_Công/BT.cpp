//#include<iostream>
//#include<string>
//#include<fstream>
//#include "Function.h"
//using namespace std;
//int main()
//{
//	int Choose, vt = 0;
//	Mang SV;
//	SV.dem = 0;
//	SV.Read("SV.txt");
//	do
//	{
//		SV.Menu();
//		cin >> Choose;
//		system("cls"); // Xóa màn hình sau khi chọn chức năng ( cho gọn )
//		switch (Choose)
//		{
//		case 1:
//			cout << "Find 1 Student " << endl;
//			vt = SV.Find();
//			if (vt != -1)
//			{
//				SV.Printf_Head();
//				SV.Export_1_Student(SV.a[vt]);
//			}
//			break;
//		case 2:
//			cout << "Add 1 Student To This List " << endl;
//			SV.Add_Student();
//			system("cls");
//			cout << "Array after add a student " << endl;
//			SV.Prinf_Arr(); break;
//		case 3:
//			cout << "Remove 1 Student From This List " << endl;
//			SV.Del_Student();
//			system("cls");
//			cout << "Array after delete a student " << endl;
//			SV.Prinf_Arr(); break;
//		case 4:
//			cout << "Prinf List By name Ascending " << endl;
//			SV.Name_Ascending();
//			SV.Prinf_Arr(); break;
//		case 5:
//			cout << "Prinf List By Descending Score " << endl;
//			SV.Descending_Score();
//			SV.Prinf_Arr(); break;
//		case 6:
//			cout << "Prinf Students Pass or Failed " << endl;
//			SV.Prinf_Score(); break;
//		case 7:
//			cout << "Export List of Student " << endl;
//			SV.Prinf_Arr(); break;
//		case 0:
//			break;
//		default:
//			cout << "Wrong! Please Choose Again! " << endl;
//		}
//	} while (Choose != 0);
//	system("pause");
//	return 0;
//}
