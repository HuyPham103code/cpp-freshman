//#include<iostream>
//#include<string>
//#include<iomanip>
//using namespace std;
////struct of a order;
////ship statue 1: shipped, 0: wait for shipping, -1: Shipping 
//struct Order{
//	int OrderID, TotalProduct, ShipStatus;
//	string DateOfOrder, CustomerName;
//	float TotalOrderValue;
//};
//struct Node{
//	Order Info;
//	Node* Prev, *Next;
//};
//
////list of orders
//int n = 15;
//Order Arr[] = {
//	{68319,10,1,"10032022","KAYLING",100000},
//	{66928,5,0,"01012023","BLAZE",85000},
//	{67832,12,-1,"02012023","CLARE",130000},
//	{65646,8,-1,"21022023","JONAS",90000},
//	{67858,20,0,"14022023","SCARLET",350000},
//	{69062,13,1,"15122022","FRANK",115000},
//	{63679,5,0,"31122022","SANDRINE",65000},
//	{64989,30,-1,"25122019","ADELYN",500000},
//	{65271,17,1,"03032023","WADE",150000},
//	{66564,20,0,"10102022","MADDEN",230000},
//	{68454,7,1,"11112022","TUCKER",95000},
//	{68736,8,-1,"03012023","ADNRES",50000},
//	{69000,21,-1,"24122022","JULIUS",550000},
//	{69324,11,-1,"10032003","MARKER",100000},
//	{69123,11,0,"10032003","Thuong",150000}
//};
//class Orders{
//private:
//	Node* Head,*Tail;
//public:
//	void Init();
//	void Menu();
//	Node* Create(Order x);
//	Node* Search_1_Order(int Key);
//	Order Enter_1_Order();
//	void Add_1_Order();
//	void AddFirst(Order x);
//	string GetDay(string date);
//	string GetMonth(string date);
//	string GetYear(string date);
//	void ImportData();
//	void Display_1_Order(Order x);
//	void Display();
//	void Cancel();
//	void Remove_1_Order(int Key);
//	void Remove();
//	void Search();
//	void Total_In_Day( string date );
//	bool Search_By_Date(string date);
//	void SearchDate();
//	void TotalIncomeDay();
//	bool CompareDate( string date1, string date2 );
//	void SortByDate();
//	string ShippingStatus(int key);
//	//code trên mạng quick sort
//	void _quickSort(Node* l, Node *h);
//	Node* partition(Node *l, Node *h);
//	Node* FindLastNode();
//	void QuickSort();
//	Node* sortAKSortedDLL( Node* head, int k);
//	// heap sort
//	Node* GetFromIndex( int k );
//	void Heapipy( int n, int i );
//	void HeapSort();
//};
////Menu
//void Orders::Menu(){
//	cout << "\n\n************************************************"<<endl; //48
//	cout << "*                    MENU                      *" << endl;
//	cout << "*  1. Import data                              *" << endl;
//	cout << "*  2. Display list                             *" << endl;
//	cout << "*  3. Add a order                              *" << endl;
//	cout << "*  4. Remove a Order                           *" << endl;
//	cout << "*  5. Search a Order                           *" << endl;
//	cout << "*  6. Search a Order by date                   *" << endl;
//	cout << "*  7. Total income in a day                    *" << endl;
//	cout << "*  8. QuickSort descending by day              *" << endl;
//	cout << "*  9. HeapSort descending by total order value *" << endl;
//	cout << "*  0. Exit                                     *" << endl;
//	cout << "************************************************"<<endl;
//
//}
////initialize phead and ptail
//void Orders::Init(){
//	Head = Tail = NULL;
//}
//
////create a new node
//Node* Orders::Create(Order x){
//	Node* p = new Node;
//	if(p){
//		p->Info = x;
//		p->Next = p->Prev = NULL;
//	}
//	return p;
//}
//
////search a order by order id
//Node* Orders::Search_1_Order(int Key){
//	Node* p = Head;
//	while( p && p->Info.OrderID != Key )
//		p = p->Next;
//	return p;
//}
//
////Add order
//void Orders::AddFirst(Order x){
//	if(Search_1_Order(x.OrderID))
//		return;
//	else{
//		Node* p = Create(x);
//		if( !Head )
//			Head = Tail = p;
//		else{
//			Node* i = Head;
//			while( !i && i->Info.TotalOrderValue < p->Info.TotalOrderValue )
//			{
//				if( i->Info.TotalOrderValue == p->Info.TotalOrderValue ){
//					cout << "Duplicate data in the list!" << endl;
//					return;
//				}
//				i = i->Next;
//			}
//			//add fisrt
//			if( i == Head ){
//				p->Next = Head;
//				Head->Prev = p;
//				Head = p;
//			}
//			//add last
//			else if( !i ){
//				Tail->Next = p;
//				p->Prev = Tail;
//				Tail = p;
//			}
//			else{
//				p->Prev = i;
//				p->Next = i->Next;
//				i->Next = p;
//			}
//		}
//	}
//}
//Order Orders::Enter_1_Order(){
//	Order x;
//	cout << "\tEnter order ID: ";
//	cin >> x.OrderID;
//	fflush(stdin);
//	cout << "\tEnter customer name: ";
//	getline( cin, x.CustomerName );
//	cout << "\tEnter day of order: ";
//	getline( cin, x.DateOfOrder );
//	cout << "\tEnter total product: ";
//	cin >> x.TotalProduct;
//	cout << "\tEnter total order value: ";
//	cin >> x.TotalOrderValue;
//	return x;
//}
//void Orders::Add_1_Order(){
//	Order x = Enter_1_Order();
//	AddFirst(x);
//	cout << "Done!" << endl;
//	n++;
//}
////get date
//string Orders::GetDay( string date ){
//	string day;
//	for( int i = 0; i < 2; i++ )
//		day += date[i];
//	return day;
//}
//string Orders::GetMonth( string date ){
//	string month;
//	for( int i = 2; i < 4; i++ )
//		month += date[i];
//	return month;
//}
//string Orders::GetYear( string date ){
//	//string month = date[4] + date[5] + date[6] + date[7];
//	string year;
//	for( int i = 4; i < 8; i++ )
//		year += date[i];
//	return year;
//}
//
////display 1 node on the screen
//void Orders::Display_1_Order(Order x)
//{
//	cout << left << setw(2) << "|" << setw(10) << x.OrderID << setw(2) << "|" << setw(15) << x.CustomerName 
//		<< setw(2) << "|" << GetDay(x.DateOfOrder) << "-" << GetMonth(x.DateOfOrder) << "-" << setw(8) << GetYear(x.DateOfOrder) 
//		<< setw(2) << "|" << setw(15) << x.TotalProduct << setw(2) << "|" << setw(19) << x.TotalOrderValue 
//		<< setw(2) << "|" << setw(15) << ShippingStatus(x.ShipStatus) << setw(2) << "|" << endl;
//	cout << "*-----------*----------------*---------------*----------------*--------------------*----------------*"<<endl;
//}
//void Orders::Display()
//{
//	cout << "\n*-----------*----------------*---------------*----------------*--------------------*----------------*"<<endl;
//	cout << left << setw(2) << "|" << setw(10) << "Order ID" << setw(2) << "|" << setw(15) << "Customer Name" 
//		<< setw(2) << "|" << setw(14) << "Day Of Order" << setw(2) << "|" << setw(15) << "Total Product" << setw(2) << "|"
//		<< setw(19) << "Total Order Value" << setw(2) << "|" << setw(15) << "Shipping status" << setw(2) << "|"<< endl;
//	cout << "*-----------*----------------*---------------*----------------*--------------------*----------------*"<<endl;
//	for( Node* i = Head; i; i = i->Next )
//		Display_1_Order(i->Info);
//}
//
////import data
//void Orders::ImportData(){
//	for( int i = 0; i < n; i++ )
//		AddFirst(Arr[i]);
//}
//
////cancel node
//void Orders::Cancel(){
//	if( Head != NULL ){
//		Node* p = Head;
//		while( !p ){
//			Node* q = p;
//			p = p->Next;
//			delete q;
//			q = NULL;
//		}
//		Head = NULL;
//	}
//}
//
////remove node
//void Orders::Remove_1_Order( int Key ){
//	if (!Head)
//      cout << "List is empty!" << endl;
//	//list have only 1 child
//	else if ( Head == Tail )
//	{
//		delete Head;
//		Init();
//	}
//	else
//	{
//		Node *temp = Head;
//		Head->Next->Prev = NULL;
//		Head = Head->Next;
//		delete temp;
//	}
//}
//void Orders::Remove(){
//	int x;
//	cout << "\tEnter ID that you want to remove: ";
//	cin >> x;
//	Node* p = Head;
//	while( p ){
//		if( p->Info.OrderID == x ){
//			Remove_1_Order(x);
//			cout << "Done!" << endl;
//			n--;
//			return;
//		}
//		p = p->Next;
//	}
//	cout << "Not find this order on the list! please check again! " << endl;
//}
//
////search order
//void Orders::Search(){
//	int x;
//	cout << "\tEnter order ID that you want to find: ";
//	cin >> x;
//	Node* p = Search_1_Order(x);
//	if( p )
//		Display_1_Order(p->Info);
//	else
//		cout << "Can't find this order" << endl;
//}
//bool Orders::Search_By_Date( string date ){
//	Node* p = Head;
//	bool Flag = false;
//	while( p ){
//		if( p->Info.DateOfOrder == date ){
//
//			Display_1_Order( p->Info );
//			Flag = true;
//		}
//		p = p->Next;
//	}
//	return Flag;
//}
//void Orders::SearchDate(){
//	string date;
//	fflush(stdin);
//	cout << "\tEnter the date you want to find: ";
//	getline( cin, date );
//	if( !Search_By_Date( date ) )
//		cout << "can't find any order in that date " << endl;
//}
//
////handle with shipping status
////ship statue 1: shipped, 0: wait for shipping, -1: Shipping 
//string Orders::ShippingStatus( int Key ){
//	if( Key == 1 )
//		return "Shipped";
//	else if( Key == 0 )
//		return "Wait";
//	else
//		return "Shipping";
//}
////total orders value of 1 day
//void Orders::TotalIncomeDay(){
//	string date;
//	float sum = 0;
//	fflush(stdin);
//	cout << "\tEnter the date you want : ";
//	getline( cin, date );
//	Node* p = Head;
//	while( p ){
//		if( p->Info.DateOfOrder == date )
//			sum += p->Info.TotalOrderValue;
//		p = p->Next;
//	}
//	cout << "\tTotal orders value of this day is " << sum << endl;
//}
//
////function compare return true when date1 > date 2
//bool Orders::CompareDate( string date1, string date2 ){
//	if( stoi(GetYear( date1 )) > stoi(GetYear(date2) )) //compare year
//		return true;
//	else if( stoi(GetYear( date1 )) < stoi(GetYear(date2)) )
//		return false;
//	else{ //the year is equal so we compare month
//		if( stoi(GetMonth( date1 )) > stoi(GetMonth(date2)) )
//			return true;
//		else if( stoi(GetMonth( date1 )) < stoi(GetMonth(date2)) )
//			return false;
//		else{ // both year and month are equal so we compare day
//			if( stoi(GetDay( date1 )) > stoi(GetDay(date2)) )
//				return true;
//			else if( stoi(GetDay( date1 )) < stoi(GetDay(date2)) )
//				return false;
//			else
//				return false;
//
//		}
//	}
//}
//Node* Orders::partition(Node *l, Node *h) 
//{ 
//    // set pivot as h element 
//	string x = h->Info.DateOfOrder;     // x date of h
//  
//    // similar to i = l-1 for array implementation 
//	Node *i = l->Prev; 
//  
//    // Similar to "for (int j = l; j <= h- 1; j++)" 
//    for (Node *j = l; j != h; j = j->Next) 
//    { 
//		if ( !CompareDate( x, j->Info.DateOfOrder) )  //nếu x lớn hơn
//        { 
//            // Similar to i++ for array 
//            i = (i == NULL)? l : i->Next; 
//  
//			Order temp = i->Info; // swap i and j
//			i->Info = j->Info;
//			j->Info = temp;
//        } 
//    } 
//    i = (i == NULL)? l : i->Next; // Similar to i++ 
//    Order temp = h->Info; //swap i and h
//	h->Info = i->Info;
//	i->Info = temp; 
//    return i; 
//} 
//void Orders::_quickSort( Node* l, Node *h){
//    if (h != NULL && l != h && l != h->Next) 
//    { 
//        Node *p = partition(l, h); 
//        _quickSort(l, p->Prev); 
//        _quickSort(p->Next, h); 
//    } 
//}
//Node* Orders::FindLastNode(){
//	Node* p = Head;
//	while( p->Next != NULL ){
//		p = p->Next;
//	}
//	return p;
//}
//void Orders::QuickSort() 
//{ 
//    // Find last node 
//    Node *h = FindLastNode(); 
//  
//    // Call the recursive QuickSort 
//    _quickSort(Head, h); 
//	cout << "Done!" << endl;
//} 
//
////heap sort
//Node* Orders::GetFromIndex( int k ){
//	int i = 0;
//	Node* p = Head;
//	while( p != NULL )
//	{
//		if( i == k )
//			return p;
//		p = p->Next;
//		i++;
//	}
//	return p;
//}
//void Orders::Heapipy( int n, int i )
//{
//	int Largest = i;
//	int l = 2 * i + 1;
//	int r = 2 * i + 2;
//	Node* p = GetFromIndex(l); // a[l]
//	Node* q = GetFromIndex(Largest);// a[Largest]
//	Node* t = GetFromIndex(r);// a[r]
//	Node* k = GetFromIndex(i); // a[i]
//	if (l < n &&  p->Info.TotalOrderValue > q->Info.TotalOrderValue){
//		Largest = l;
//		q = p;
//	}
//	if (r < n && t->Info.TotalOrderValue > q->Info.TotalOrderValue){
//		Largest = r;
//		q = t;
//	}
//	if (Largest != i)
//	{
//		//Swap(a[i], a[Largest]);
//		Order temp = k->Info; // swap i and j
//		k->Info = q->Info;
//		q->Info = temp;
//		Heapipy( n, Largest);
//	}
//}
//void Orders::HeapSort()
//{
//	for (int i = n / 2 - 1; i >= 0; i--)
//		Heapipy( n, i);
//	Node* p = GetFromIndex(0); // a[0]
//	Node* q = GetFromIndex(n-1); // a[i]
//	for (int i = n - 1; i >= 0; i--)
//	{
//		Order temp = p->Info; // swap i and j
//		p->Info = q->Info;
//		q->Info = temp;
//		q = q->Prev;
//		Heapipy(i, 0);
//	}
//	cout << "Done!" << endl;
//}
