//#include<iostream>
//#include<string>
//#include<fstream>
//#include<iomanip>
//#define Max 100
//using namespace std;
//struct SinhVien
//{
//	string ID, LastName, FirstName;
//	double Score1, Score2, A_Score;
//};
//struct Mang
//{
//	SinhVien a[Max];
//	int dem;
//	void Menu()
//	{
//		cout << "======================MENU======================" << endl;
//		cout << "\t\t1. Find 1 Student " << endl;
//		cout << "\t\t2. Add 1 Student To This List " << endl;
//		cout << "\t\t3. Remove 1 Student From This List " << endl;
//		cout << "\t\t4. Prinf List By Name Ascending " << endl;
//		cout << "\t\t5. Prinf List By Descending Score " << endl;
//		cout << "\t\t6. Prinf Students Pass or Failed " << endl;
//		cout << "\t\t7. Export List " << endl;
//		cout << "\t\t0. Exit " << endl;
//		cout << "Please Choose a function( 0-7 ): ";
//	}
//	void Printf_Head()
//	{
//		cout << "-----------------------------------------------------------------------\n";
//		cout << left << setw(10) << "| ID" << setw(15) << "| First Name" << setw(15) << "| Last Name"
//			<< setw(10) << "| Diem1" << setw(10) << "| Diem 2" << setw(10) << "| DiemTB" << "|\n";
//		cout << "-----------------------------------------------------------------------\n";
//	}
//	void Read(char *file) // Đọc file có sẵn theo đề
//	{
//		ifstream docF;
//		docF.open(file, ios::in);
//		if (docF.is_open())
//		{
//			while (!docF.eof())
//			{
//				getline(docF, a[dem].ID, '-');
//				getline(docF, a[dem].FirstName, '-');
//				getline(docF, a[dem].LastName, '-');
//				docF >> a[dem].Score1;
//				docF.ignore();            // Xóa dấu "-"
//				docF >> a[dem].Score2;
//				docF.ignore();           // Xóa kí tự enter trong bộ nhớ đệm
//				a[dem].A_Score = (a[dem].Score1 + a[dem].Score2) / 2;
//				if( a[dem].ID == "..." )
//					break;
//				else
//					dem++;
//			}
//			docF.close();
//		}
//		else
//			cout << "Khong the mo file!\n ";
//	}
//	void Export_1_Student(SinhVien x)
//	{
//		cout << left << "| " << setw(8) << x.ID << "| " << setw(13) << x.FirstName << "| " << setw(13) << x.LastName
//			<< "| " << setw(8) << x.Score1 << "| " << setw(8) << x.Score2 << "| " << setw(8) << x.A_Score << "|\n";
//	}
//	void Prinf_Arr()
//	{
//		Printf_Head();
//		for (int i = 0; i < dem; i++) // xuất thông tin đã đọc được từ file
//		{
//			Export_1_Student(a[i]);
//		}
//		cout << "-----------------------------------------------------------------------\n" << endl;
//	}
//	void Name_Ascending() // sắp xếp tăng dần
//	{
//		SinhVien temp;
//		for (int i = 0; i < dem - 1; i++)
//		{
//			if (a[i].LastName > a[i + 1].LastName) // Nếu tên đằng trc lớn hơn( theo mã ascii ) 
//			{										// của tên đằng sau thì đổi chỗ
//				temp = a[i];
//				a[i] = a[i + 1];
//				a[i + 1] = temp;
//			}
//		}
//	}
//	void Descending_Score()
//	{
//		SinhVien temp;
//		for (int i = 0; i < dem - 1; i++)
//		{
//			if (a[i].A_Score < a[i + 1].A_Score) // Nếu DTB đằng trc nhỏ hơn đằng sau thì đổi chỗ
//			{
//				temp = a[i];
//				a[i] = a[i + 1];
//				a[i + 1] = temp;
//			}
//		}
//	}
//	void Prinf_Score()
//	{
//		Descending_Score();
//		//in dau,rot sau khi danh sach duoc sap xep diem trung binh giam dan
//		Printf_Head();
//		cout << "|                             PASS                                    |\n";
//		cout << "-----------------------------------------------------------------------\n";
//		for (int i = 0; i < dem; i++)
//		{
//			if (a[i].A_Score >= 5)
//			{
//				Export_1_Student(a[i]);
//			}
//		}
//		cout << "-----------------------------------------------------------------------\n";
//		cout << "|                             FAILED                                  |\n";
//		cout << "-----------------------------------------------------------------------\n";
//		for (int i = 0; i < dem; i++)
//		{
//			if (a[i].A_Score < 5)
//			{
//				Export_1_Student(a[i]);
//			}
//		}
//		cout << "-----------------------------------------------------------------------\n" << endl;
//	}
//	int Find()
//	{
//		string id;
//		fflush(stdin);
//		cout << "Nhap vao id sinh vien muon tim: ";
//		getline(cin, id);
//		for (int i = 0; i < dem; i++)
//			if (id == a[i].ID)
//			{
//				return i;
//			}
//		return -1;
//	}
//	void Add_Student()
//	{
//		bool flag;
//		string tmp;
//		double tmp2;
//		cout << "Nhap thong tin sinh vien muon them\n";
//		do
//		{
//			cout << "ID: ";
//			fflush(stdin);
//			getline(cin, tmp);
//			flag = false; // mac dinh co se duoc tat, neu khong trung id se thoat do while
//			for (int i = 0; i < dem; i++)  // tim sinh vien theo id
//				if (tmp == a[i].ID)
//				{
//					cout << "Trung ID vui long nhap lai!\n";
//					flag = true; // Neu trung se bat co de do while chay lai
//				}
//		} while (flag);
//		a[dem].ID = tmp;
//		cout << "First Name: ";
//		fflush(stdin);  // xoa bo nho tam de tiep theo dung getline()
//		getline(cin, tmp);
//		a[dem].FirstName = tmp;
//		cout << "Last Name: ";
//		fflush(stdin);
//		getline(cin, tmp);
//		a[dem].LastName = tmp;
//		cout << "Score1: ";
//		cin >> tmp2;
//		a[dem].Score1 = tmp2;
//		cout << "Score2: ";
//		cin >> tmp2;
//		a[dem].Score2 = tmp2;
//		a[dem].A_Score = (a[dem].Score1 + a[dem].Score2) / 2;
//		dem++;
//	}
//	void Del_Student()
//	{
//		string id;
//		cout << "Nhap ma sv sinh vien muon xoa: ";
//		fflush(stdin);
//		getline(cin, id);
//		for (int i = 0; i < dem; i++)  // tim sinh vien theo id
//			if (id == a[i].ID) // neu tim thay se xoa
//			{
//				for (int j = i; j < dem; j++)
//					a[j] = a[j + 1];
//				dem--;
//				return; // sau khi xoa xong thoat vong lap luon
//			}
//		cout << "Khong tim thay sinh vien trong danh sach " << endl;
//	}
//};
