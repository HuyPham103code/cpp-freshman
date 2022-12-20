#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstdlib>
#define m 101
using namespace std;
struct Word
{
	string english,mean,type;
};
struct Node
{
	Word word;
	Node* link;
};
class Dictionary
{
public:
	Node* heads[m];
	void init();
	void menu();
	int hashFunc( string word );
	Node* create( Word x );
	void insertElement( Word x );
	void insert();
	void displayWord( Node* p );
	void display();
	void remove( string w );
	void standard( string &word );
	void cancelNode( Node* p );
	void cancel();
	Node* search( string word );
	void update();
	void read( ifstream &ifs );
	void write1Word( ofstream &ofs, Word w );
	void write( ofstream &ofs );
	int find( string str, Node *p );
	void lookUp();
	//create a quizz
};
//initialize hash table
void Dictionary::init()
{
	for( int i = 0; i < m; i++ )
		heads[i] = NULL;
}
// menu
void Dictionary::menu()
{
	cout << "\n\t\t1 .Add word " << endl;
	cout << "\t\t2. Update word " << endl;
	cout << "\t\t3. Search " << endl;
	cout << "\t\t4. Delele word " << endl;
	cout << "\t\t5. Display " << endl;
	cout << "\t\t6. read file " << endl;
	cout << "\t\t7. write file " << endl;
	cout << "\t\t8. Take quizze " << endl;
	cout << "\t\t0. Exit " << endl;
}
//standard word
void Dictionary::standard( string &word )
{
	for( int i = 0; i < word.length(); i++ )
		if( word[i] >= 65 && word[i] <= 90 )
			word[i] += 32;
}
//hash word english
int Dictionary::hashFunc( string w )
{
	int key = 0;
	for( int i = 0; i < w.length(); i++ )
		key += (int)tolower(w[i])*(i+1);
	return key % m;
} 
//create node
Node* Dictionary::create( Word x )
{
	Node* p = new Node;
	p->word = x;
	p->link = NULL;
	return p;
}
//insert node available
void Dictionary::insertElement( Word x )
{
	int k = hashFunc(x.english);
	Node* p = create(x);
	Node* t = heads[hashFunc(x.english)];   // hashFunc(x) -> key
	if( t == NULL )
	{
		heads[hashFunc(x.english)] = p; // t = p
		cout << "\tAdded " << heads[hashFunc(x.english)]->word.english << endl;
	}
	else //thêm cuối
	{
		int z =  hashFunc(t->word.english);
		while( t->link != NULL )
		{
			//z =  hashFunc(t->word.english);
			if( t->word.english == p->word.english && t->word.type == p->word.type )
			{
				cout << "Trung tu " << endl;
				break;
			}
			t = t->link;
		}
		if( t->word.english != p->word.english && t->word.type != p->word.type )
		{
			t->link = p;
			cout << "\tAdded " << t->link->word.english << endl;
		}
	}
}
//insert word from keyboard
void Dictionary::insert()
{
	Word w;
	fflush(stdin);
	cout << "\n\tEnter word: ";
	getline( cin,w.english );
	cout << "\tEnter type: ";
	getline( cin,w.type );
	cout << "\tEnter mean: ";
	getline( cin,w.mean );
	insertElement(w);
	cout << "\n\t\tDone" << endl;
}
//search work english
Node* Dictionary::search( string word )
{
	standard(word);
	Node* p = heads[hashFunc(word)];
	if( p != NULL )
	{
		while( p != NULL )
		{
			if( p->word.english == word )
				return p;
			p = p->link;
		}
	}
	return NULL;
}
//print 1 work
void Dictionary::displayWord( Node* p )
{
	while( p != NULL )
	{
		cout << left << p->word.english << "(" << p->word.type << ")" << setw(4)
			<< ":" << p->word.mean << endl;
		p = p->link;
	}
}
//print all words
void Dictionary::display()
{
	int count = 0;
	for( int i = 0; i < m; i++ )
		if( heads[i] != NULL )
		{
			cout << "\n\t===BUCKET " << i << "===" << endl;
			displayWord( heads[i] );
			count++;
		}
		cout << "co " << count << " word " << endl;
}
//cannnel 1 node
void Dictionary::cancelNode( Node* p )
{
	while( p != NULL )
	{
		Node* q = p;
		p = p->link;
		delete q;
	}
	p = NULL;
}
//cannel all nodes
void Dictionary::cancel()
{
	for( int i = 0; i < m; i++ )
		if( heads[i] != NULL )
			cancelNode( heads[i] );
}
void Dictionary::update()
{
	Word w;
	fflush(stdin);
	cout << "\n\tEnter word which wanna update: ";
	getline( cin,w.english );
	cout << "\tEnter type of word: ";
	getline( cin,w.type );
	cout << "\tEnter mean: ";
	getline( cin,w.mean );
	standard(w.english);
	Node *p = search( w.english );
	if( p != NULL )
	{
		p->word.mean = w.mean;
		p->word.type = w.type;
		cout << "\tUpdate successful " << endl;
	}
	else
		cout << "\tNot found! " << endl;
}
void Dictionary::remove( string w)
{
	standard(w);
	Node* p = search(w);
	if( p != NULL ) // tìm thấy
	{
		Node* t = heads[hashFunc(w)];
		Node* q = NULL;
		while( t->word.english != w )
		{
			q = t;
			t = t->link;
		}
		if( q == NULL ) // xóa đầu
		{
			heads[hashFunc(w)] = NULL;
			delete t;
		}
		else
		{
			q->link = t->link;
			delete t;
		}
		cout << "\t\tDone! " << endl;
	}
	else
		cout << "\tNot found! " << endl;
}
void Dictionary::read( ifstream &ifs )
{
	int count(0);
	Word w;
	if( ifs.is_open() )
	{
		while( !ifs.eof() )// not in the end of the lines
		{
			getline( ifs,w.english,'|' );
			getline( ifs,w.type,'|' );
			getline( ifs,w.mean );
			standard(w.english);
			standard(w.mean);
			standard(w.type);
			if( w.english != "..." )
			{
				insertElement(w);
				//cout << "\tAdded " << w.english << endl;
				count++;
			}
		}
		cout << "there are " << count << " words " << endl;
		cout << "Done!" << endl;
		ifs.close();
	}
	else
		cout << "Can't open file! " << endl;
}
void Dictionary::write1Word( ofstream &ofs, Word w )
{
	if( ofs.is_open() )
	{
		ofs << w.english << "|" << w.type << "|" << w.mean << endl;
	}
	else
		cout << "Can't open file! " << endl;
}
void Dictionary::write( ofstream &ofs )
{
	for( int i = 0; i < m; i++ )
		if( heads[i] != NULL )
		{
			Node* p = heads[i];
			while( p != NULL )
			{
				write1Word( ofs,p->word );
				p = p->link;
			}
		}
	if( ofs.is_open() )
	{
		ofs << "...";
		cout << "Done!" << endl;
	}
}
//int Dictionary::find( string str, Node *p )
//{
//	if( p == NULL ) return 0;
//	int i = 0, j = 0;
//	while( p != NULL )
//	{
//		while( p->word.english[i] != '\0' )
//		{
//			if( str[j] == p->word.english[i] )
//			{
//				//keep searching
//				while( p->word.english[i] == str[j] )
//				{
//					i++;
//					j++;
//				}
//				if( j == str.length -1 )
//					return 1;
//			}
//			else{
//				while( p->word.english[i] != ' ' )
//				{
//					i++;
//					if( p->word.english[i] != '\0' )
//						break;
//				}
//			}
//			j = 0;
//		}
//		p = p->link;
//	}
//}
class Quizz
{
public:
	int len;
	Node* First;
	void InitNode();
	Node* CreateNode( Word w );
	int AddNode( Word w );
	int DelNode( string Vocal );
	void DisplayListVocal();
	void CancelNode();
	void Menu();
	Node* Search( string word );
	void update();
	void AddVocal();
	void Read( ifstream &ifs );
	void Write( ofstream &ofs );
	Node* GetNode( int x );
};
void Quizz::Menu()
{
	cout << "\n\t\t1 .Add word to list of quiz " << endl;
	cout << "\t\t2. Display quiz " << endl;
	cout << "\t\t3. Delete " << endl;
	cout << "\t\t4. Read from file txt " << endl;
	cout << "\t\t5. Write to file txt " << endl;
	cout << "\t\t6. Update word " << endl; 
	cout << "\t\t7. Take quizz " << endl;
	cout << "\t\t8. Exit " << endl;
	cout << "Enter your option: ";
}
void Import( Node* a, Node* b )
{
	a = b;
}
void Quizz::InitNode()
{
	First = NULL;
}
Node* Quizz::CreateNode( Word w )
{
	Node* p = new Node;
	p->word = w;
	p->link = NULL;
	return p;
}
int Quizz::AddNode( Word w )
{
	Node* p = CreateNode(w);
	if( First == NULL )
	{
		First = p;
		len++;
		return 1;
	}
	else
	{
		Node* q = First;
		while( q->link != NULL )
			q = q->link;
		q->link = p;
		len++;
		return 1;
	}
	return 0;
}
void Quizz::AddVocal()
{
	Word w;
	fflush(stdin);
	cout << "\n\tEnter word: ";
	getline( cin,w.english );
	cout << "\tEnter type: ";
	getline( cin,w.type );
	cout << "\tEnter mean: ";
	getline( cin,w.mean );
	AddNode( w );
	cout << "\n\t\tDone" << endl;
}
int Quizz::DelNode( string Vocal )
{
	Node* p = First;
	if( p != NULL )
	{
		Node* q = NULL;
		while( p != NULL )
		{
			if( p->word.english == Vocal )
				break;
			q = p;
			p = p->link;
		}
		if( p != NULL ) // tìm thấy
		{
			if( q == NULL )//Xóa đầu
			{
				First = p->link;
				delete p;
			}
			else
			{
				q->link = p->link;
				delete p;
			}
		}
		len--;
	}
	return 0;
}
void Quizz::DisplayListVocal()
{
	Node* p = First;
	if( p != NULL )
	{
		while( p != NULL )
		{
			cout << left << "\t" << p->word.english << "(" << p->word.type << setw(10) << ")"
				<< setw(20) << ":" << p->word.mean << endl;
			p = p->link;
		}
	}
}
void Quizz::CancelNode()
{
	Node* p = First;
	if( p != NULL )
	{
		while( p != NULL )
		{
			Node* q = p;
			p = p->link;
			delete q;
		}
		First = NULL;
	}
}
void Quizz::Read( ifstream &ifs )
{
	int count(0);
	Word w;
	if( ifs.is_open() )
	{
		while( !ifs.eof() )// not in the end of the lines
		{
			getline( ifs,w.english,'|' );
			getline( ifs,w.type,'|' );
			getline( ifs,w.mean );
			if( w.english != "..." && w.english != "" && w.english != "\n" )
			{
				cout << "Vao!" << endl;
				AddNode( w );
				count++;
			}
		}
		if( count > 0 )
		{
			cout << "there are " << count << " words " << endl;
			cout << "Done!" << endl;
		}
		ifs.close();
	}
	else
		cout << "Can't open file! " << endl;
}
void Quizz::Write( ofstream &ofs )
{
	if( ofs.is_open() )
	{
		Node* p = First;
		if( p != NULL )
		{
			while( p != NULL )
			{
				ofs << p->word.english << "|" << p->word.type << "|" << p->word.mean << endl;
				p = p->link;
			}
			cout << "\nDone! " << endl;
		}
	}
	else
		cout << "Can't open file! " << endl;
}
Node* Quizz::Search( string english )
{
	Node* p = First;
	if( p != NULL )
	{
		while( p != NULL )
		{
			if( p->word.english == english )
				return p;
			p = p->link;
		}
	}
	return p;
}
void Quizz::update()
{
	string english;
	Word w;
	cout << "\n\tEnter the word you want to update: ";
	fflush(stdin);
	getline( cin, english );
	Node* p = Search( english );
	if( p != NULL )
	{
		cout << "\n\t\t Update " << endl;
		fflush(stdin);
		cout << "\tEnter word: ";
		getline( cin ,w.english );
		cout << "\tEnter type: ";
		getline( cin,w.type );
		cout << "\tEnter mean: ";
		getline( cin,w.mean );
		p->word = w;
		cout << "Done! " << endl;
	}
	else
		cout << "Can't find this word! " << endl;
}
Node* Quizz::GetNode( int n )
{
	int count = 0;
	Node* p = First;
	if( p != NULL )
	{
		while( p != NULL )
		{
			if( count == n )
				return p;
			count++;
			p = p->link;
		}
	}
	return NULL;
}
void RunQuizz( Quizz a, Quizz b )
{
	b.InitNode();
	srand(time(NULL));
	char k;
	if( a.First == NULL )
		cout << "\nYou don't have any quiz in your list, please add some word to list before you take quizz " << endl;
	Node* p = a.First; // của quiz 1
	while( a.len != 0 )
	{
		int pos = rand() % a.len;
		string w; // use for enter answer
		Node* q = a.GetNode(pos);
		cout << "\n\tlen: " << a.len << endl;
		cout << "\n\tQUESTION is:  " << q->word.mean << endl;
		cout << "vocal = ";
		fflush(stdin);
		getline( cin, w );
		if( q->word.english == w ) cout << "correct! " << endl;
		else
		{
			// add recently read word to array if them incorrect
			b.AddNode( q->word ); //nếu sai thì thêm vào list sai
			cout << "incorrect! " << endl; 
		}
		// del recently read word
		a.DelNode( q->word.english );
		a.DisplayListVocal();
	}

	if( b.First != NULL )
	{
		cout << "\n\tYou have some wrong answer, do you want do test again? (y/n): ";
		cin >> k;
		if( k == 'Y' || k == 'y' )
		{
			RunQuizz( b,a );
		}
		else
			cout << "Bye!!! " << endl;
	}
}