#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

#define MAX 20
char A[MAX][MAX];
int n;
char vertex[MAX];

list<int>* adj;

struct Edge
{
	int src, dest, weight;
};

struct Graph
{
	int V, E;
	struct Edge* edge;
};

struct Node {
	int info;
	Node* link;
};

Node* sp;
Node* front, *rear;

void InitStack() {
	sp = NULL;
}

int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void PushS(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int& x)
{
	if (sp != NULL) {
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

void InitQueue() {
	front = NULL;
	rear = NULL;
}

int isEmptyQ() {
	if (front == NULL)
		return 1;
	return 0;
}

void PushQ(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;

	rear = p;
}

int PopQ(int& x)
{
	if (front != NULL) {
		Node* p = front;
		front = p->link;
		x = p->info;
		if (front == NULL) {
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

void InitGraph()
{
	n = 0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile("Graph.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
		}
	}
}

void inputGraph()
{
	cout << "nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "nhap vao dong thu " << i + 1 << ":  ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}

//Xuat ma tran ke do thi
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << "  ";
		cout << endl;
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << "  ";
}

int C[100], bfs[100];
int nbfs = 0;
void InitC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v) // BFS
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if (C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

int dfs[100];
int ndfs = 0;
void DFS(int s) //DFS
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
			PopS(u);
		for (v = 0; v < n; v++)
			if (A[u][v] != 0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}

//Khoi Tao Bellman-Ford
int dist[MAX];
int previous[MAX];
void initBell()
{
	for (int i = 0; i < MAX; i++)
	{
		dist[i] = INT_MAX;
		previous[i] = 0;
	}
}

//BELLMAN-FORD
void BellmanFord(int src) {
	dist[src] = 0;
	for (int k = 0; k < n - 1; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i] != INT_MAX && A[i][j] && dist[j] >(dist[i] + A[i][j])) {
					dist[j] = dist[i] + A[i][j];
					previous[j] = i;
				}
			}
		}
	}

	for (int k = 0; k < n - 1; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (A[i][j] && dist[j] >(dist[i] + A[i][j])) {
					dist[j] = INT_MAX;
					previous[j] = -1;
					cout << "Graph contains negative weight cycle" << endl;
					return;
				}
			}
		}
	}
	cout << "Vertex :\t\t";
	for (int i = 0; i < n; ++i)
		cout << vertex[i] << "\t";
	cout << "\nDistance From Source : \t";
	for (int i = 0; i < n; ++i)
		cout << dist[i] << "\t";
	return;
}

int mininumDist(int dist[], bool Tset[])
{
	int min = INT_MAX, index;

	for (int i = 0; i < 6; i++)
	{
		if (Tset[i] == false && dist[i] <= min)
		{
			min = dist[i];
			index = i;
		}
	}
	return index;
}

//DIJKSTRA
void Dijkstra(int src)
{
	int dist[MAX];
	bool Tset[MAX];

	for (int i = 0; i < n; i++)
	{
		dist[i] = INT_MAX;
		Tset[i] = false;
	}

	dist[src] = 0;

	for (int i = 0; i < n; i++)
	{
		int m = mininumDist(dist, Tset);
		Tset[m] = true;
		for (int i = 0; i < n; i++)
		{
			if (!Tset[i] && A[m][i] && dist[m] != INT_MAX && dist[m] + A[m][i] < dist[i])
				dist[i] = dist[m] + A[m][i];
		}
	}
	cout << "Vertex\t\t Distance from source" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << vertex[i] << "\t\t\t" << dist[i] << endl;
	}

}

//khoi tao E, T
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;

int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;

int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}

void XoaViTriE(int i)
{
	for (int j = 0; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}

void XoaCanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
		if (E1[i] == u && E2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
}

//PRIM
void prim(int s)
{
	int u = s, min, i, d1, d2;
	while (nT < n - 1)
	{
		for (int v = 0; v < n; v++)
			if (A[u][v] != 0)
				if (TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = A[u][v];
					nE++;
				}
		for (int i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}
		for (int i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
				if (min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = A[d1][d2];
		A[d1][d2] = 0;
		A[d2][d1] = 0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}
}

void output(bool VertexName)
{
	int tong = 0;
	for (int i = 0; i < nT; i++)
	{
		if (VertexName)
			cout << endl << "(" << vertex[T1[i]] << ", " << vertex[T2[i]] << ") = " << wT[i];
		else
			cout << endl << "(" << T1[i] << ", " << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\n Tong = " << tong;
}

void TapE()
{
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (A[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = A[i][j];
				A[i][j] = 0;
				A[j][i] = 0;
				nE++;
			}
}

int TonTai2(int E, int T[], int nT)
{
	for (int i = 0; i < nT; i++)
	{
		if (E == T[i])
			return 1;
	}
	return 0;
}

void Swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void SapXepE()
{
	for (int i = 0; i < nE - 1; i++)
		for (int j = i + 1; j < nE; j++)
			if (wE[i] > wE[j])
			{
				Swap(wE[i], wE[j]);
				Swap(E1[i], E1[j]);
				Swap(E2[i], E2[j]);
			}
}

//So thanh phan lien thong do thi
int connectedComponents()
{
	int visited[MAX];
	int nV = 0;
	int i = 0, j = 0;
	int nC = 0;

	while (nV < n)
	{
		for (j = 0; j < n; j++)
		{
			if (A[i][j] != 0 && visited[j] != 1)
			{
				visited[j] = 1;
				nV++;
				i = j;
				break;
			}
		}
		if (j >= n && i < n - 1)
		{
			i++;
			visited[i] = 1;
			nV++;
			nC++;
		}
	}
	return nC;
}

//KRUSKAL
void kruskal()
{
	for (int i = 0; i < nE; i++)
	{
		if (TonTai2(E1[i], T1, nT) == 1 && TonTai2(E2[i], T2, nT) == 1)
			continue;
		if (TonTai2(E1[i], T2, nT) == 1 && TonTai2(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1)
			break;
	}
}

void outputE(bool VertexName)
{
	int tong = 0;
	for (int i = 0; i < nE; i++)
	{
		if (VertexName)
			cout << endl << "(" << vertex[E1[i]] << "," << vertex[E2[i]] << ") = " << wE[i];
		else
			cout << endl << "(" << E1[i] << "," << E2[i] << ") = " << wE[i];
		tong += wE[i];
	}
	cout << "\n Tong = " << tong;
}

int main()
{
	int choice, x;
	system("cls");
	cout << "/-----------/ DO THI /------------/" << endl;
	cout << "1. Khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE tu file text" << endl;
	cout << "3. Nhap MA TRAN KE" << endl;
	cout << "4. Xuat MA TRAN KE" << endl;
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK" << endl;
	cout << "6. Duyet do thi theo chieu sau DFS - DSLK" << endl;
	cout << "7. Tim so thanh phan lien thong cua Do Thi" << endl;
	cout << "8. Duong di ngan nhat theo Bellman-Ford " << endl;
	cout << "9. Duong di ngan nhat theo Dijkstra " << endl;
	cout << "10. Tim CAY KHUNG TOI THIEU bang thuat toan Prim" << endl;
	cout << "11. Tim CAY KHUNG TOI THIEU bang thuat toan Kruskal " << endl;
	cout << "0. Thoat ra" << endl;
	do
	{
		cout << "\nXin hay chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MA TRAN KE tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQueue();
			InitC();
			cout << "Vui long nhap vao dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet theo BFS: " << endl;
			output(bfs, n);
			break;
		case 6:
			InitStack();
			InitC();
			cout << "Vui long nhap vao dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet theo DFS: " << endl;
			output(dfs, n);
			break;
		case 7:
			connectedComponents();
			cout << "so thanh phan lien thong = " << connectedComponents() << endl;
			break;
		case 8:
			cout << "\nVui long nhap vao dinh: ";
			cin >> x;
			initBell();
			BellmanFord(x);
			break;
		case 9:
			cout << "\nVui long nhap vao dinh: ";
			cin >> x;
			Dijkstra(x);
			break;
		case 10:
			cout << "Vui long nhap vao dinh xuat phat: ";
			cin >> x;
			prim(x);
			cout << "Cay khung toi thieu voi Prim: " << endl;
			output(true);
			break;
		case 11:
			nT = 0;
			TapE();
			SapXepE();
			kruskal();
			cout << "Cay khung toi thieu voi Kruskal: " << endl;
			output(true);
			break;
		case 0:
			cout << "Byeeeeee nhaaaaa ... !" << endl;
			break;
		default:
			break;
		}
	} while (choice != 0);
	system("pause");
	return 0;
}


