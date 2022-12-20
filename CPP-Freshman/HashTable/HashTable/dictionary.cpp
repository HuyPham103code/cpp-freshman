#include"dictionary.h"
int main()
{
	ifstream ifs("D:\Dictionary.txt",ios::in);
	ofstream ofs("D:\Dictionary.txt",ios::in);
	ifstream ifsQuiz("D:\quizz.txt",ios::in);
	ofstream ofsQuiz("D:\quizz.txt",ios::in);
	Dictionary Eng;
	int Choose;
	string x;
	Node* p;
	Eng.init();
	//quizz
	Quizz a;
	a.len = 0;
	a.InitNode();
	Quizz b;
	b.len = 0;
	b.InitNode();
	do
	{
		Eng.menu();
		cout << "Enter your option: ";
		cin >> Choose;
		system("cls");
		switch(Choose)
		{
		case 1:
			cout << "\n\t\tADD WORD " << endl;
			Eng.insert();break;
		case 2:
			cout << "\n\t\tUPDATE WORD " << endl;
			Eng.update();break;
		case 3:
			cout <<"\n\t\tLOOK UP " << endl;
			fflush(stdin);
			cout << "\n\tEnter word: ";
			getline( cin, x );
			p = Eng.search(x);
			if( p != NULL )
				Eng.displayWord( p );
			else
				cout << "Not found! " << endl;
			break;
		case 4:
			cout << "\n\t\tREMOVE " << endl;
			fflush(stdin);
			cout << "\tEnter word: ";
			getline( cin,x );
			Eng.remove(x);
			break;
		case 5:
			cout << "==========================Cambrige Dictionary=======================" << endl;
			Eng.display();break;
		case 6:
			cout << "\n\t\tread file " << endl;
			Eng.read(ifs);break;
		case 7:
			cout << "\n\t\twrite file " << endl;
			Eng.write(ofs);break;
		case 8:
			cout << "\n\t\tTake Quizz " << endl;
			do
			{
				a.Menu();
				cin >> Choose;
				system("cls");
				switch (Choose)
				{
				case 1:
					cout << "\n\tAdd a vocal to list " << endl;
					a.AddVocal();break;
				case 2:
					cout << "\n\t\tYour Quizz " << endl;
					a.DisplayListVocal();break;
				case 3:
					cout << "\n\t\tRemove " << endl;
					a.DisplayListVocal();
					cout << "Enter word you want to remove: ";
					cin >> x;
					a.DelNode( x );break;
				case 4:
					cout << "\n\t\tYour Quizz " << endl;
					a.Read( ifsQuiz );
					a.DisplayListVocal();break;
				case 5:
					cout << "\n\t\tWrite to file " << endl;
					a.Write( ofsQuiz );
				case 6:
					cout << "\n\t\tIpdate word " << endl;
					a.update();break;
				case 7:
					cout << "\n\t\tQUIZZ " << endl;
					//do{
						cout << "*******************************" << endl;
						cout << "*                             *" << endl;
						cout << left << setw(10) << "*" << setw(6) << "Take Quizz " << "*" << endl;
						cout << "*                             *" << endl;
						cout << "*******************************" << endl;
						RunQuizz( a,b );
						a.InitNode();
					//}while( b.First != NULL );
					break;
				case 8:
					break;
				default:
					cout << "Wrong! please enter again! " << endl;
				}
			}while( Choose != 8 );
			break;
		case 0:
			break;
		default:
			cout << "Wrong! please enter again! " << endl;
		}
	}while( Choose != 0 );
	b.CancelNode();
	a.CancelNode();
	Eng.cancel();
	system("pause");
	return 0;
}