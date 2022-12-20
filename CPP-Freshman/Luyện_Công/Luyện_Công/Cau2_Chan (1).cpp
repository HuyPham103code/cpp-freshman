#include <iomanip>
#include <iostream>
#include <string>
#include <limits.h>
#include <fstream>
#define MAX 100
int Matrix[MAX][MAX];
int TEMP[MAX];
using namespace std;
//////////////// BellmanFord
struct Edge {
    int src, dest, weight;
};
struct Graph {
    int V, E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
void addEdge(struct Graph* graph, int src,int dest, int weight, int i)
{
    graph->edge[i].src = src;
    graph->edge[i].dest = dest;
    graph->edge[i].weight = weight;
}
void taoMatran(struct Graph* graph) {
    int V = graph->V;
    int E = graph->E;
    int src, dest, weight;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            Matrix[i][j] = 0;
    ////////
    for (int i = 0; i < E; i++) {
        src = graph->edge[i].src;
        dest = graph->edge[i].dest;
        weight = graph->edge[i].weight;
        Matrix[src][dest] = 1;
    }

}
char intTochar(int x) {
    switch (x) {
    case 0:
        return 'A';
    case 1:
        return 'B';
    case 2:
        return 'C';
    case 3:
        return 'D';
    case 4:
        return 'E';
    case 5:
        return 'F';
    case 6:
        return 'G';
    }
}
int charToint(char c) {
    switch (c) {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'E':
        return 4;
    case 'F':
        return 5;
    case 'G':
        return 6;
    }
    return -1;
}
void printArr(int dist[], int n, int src)
{
    cout << "\n==========================\n";
    cout << "TuDinh DenDinh KhoangCachNganNhat" << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(3) << intTochar(src) << setw(8) << intTochar(i) << setw(15) << dist[i] << endl;
    }
}
void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int* dist = new int[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX
                && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX
            && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return; 
        }
    }
    printArr(dist, V, src);
    return;
}
void Nhapdothi(struct Graph* graph) {
    ifstream ifs("Graph.txt");
    string line;
    bool firstLine = true;
    int vt = 0;
    int row = 0;
    if (ifs.is_open())
    {
        while (!ifs.eof())          // (1)
        {
            row++;
            getline(ifs, line, '\n'); // (2)
            if (row > 2) {
                addEdge(graph, charToint((char)line[0]), charToint((char)line[2]), line[4] - '0', vt);
                //cout << graph->edge[vt].src << "   " << graph->edge[vt].dest << "   " << graph->edge[vt].weight << endl;
                vt++;
            }
        }
    }
    ifs.close();
}
void getVandE(int& v, int& e) {
    ifstream ifs("Graph.txt");
    string line;
    bool firstLine = true;
    e = 0;
    if (ifs.is_open())
    {
        while (!ifs.eof())
        {
            e++;
            if (firstLine) {
                ifs >> v;
                firstLine = false;
            }
            getline(ifs, line); // (2)
        }
    }
    e = e - 2;
    ifs.close();
}
void InitWithOne() {
    for (int i = 0; i < MAX; i++)
        TEMP[i] = 1;
}
void DFS(int src,int V) {
    // xet dinh src
    TEMP[src] = 0;
    cout << src << "->";
    for (int v = 0; v < V; v++)
        if (TEMP[v] == 1 && Matrix[src][v] == 1)
        {
            DFS(v,V);
        }
}
void BFS(int src,int V) {
    int queue[MAX], dau = 0, cuoi = 0;
    for (int i = 0; i < MAX; i++) queue[i] = 0;
    queue[cuoi] = src;
    TEMP[src] = 0;
    cout << src << "->";

    while (dau >= cuoi)
    {
        int p = queue[cuoi];
        cuoi++;
        for (int v = 0; v < V; v++)
            if (TEMP[v] == 1 && Matrix[p][v] == 1)
            {
                dau++;
                queue[dau] = v;
                TEMP[v] = 0;
                cout << v << "->";
            }
    }
}
int KT_ChuaXet(int V) {
    for (int i = 0; i < V; i++)
        if (TEMP[i] == 1) return i;
    return -1;
}
int DemSLT(int V) {
    int slt = 0;
    InitWithOne();
    while (KT_ChuaXet(V) != -1)
    {
        int i = KT_ChuaXet(V);
        DFS(i,V);
        slt++;
    }
    return slt;
}
void Menu() {
    cout << "========== Menu ==========\n";
    cout << "1.Khoi tao do thi, nhap do thi tu file text.\n";
    cout << "2.Duyet do thi theo BFS va DFS.\n";
    cout << "3.Tim so thanh phan lien thong cua do thi.\n";
    cout << "4.Tim duong di ngan nhat theo BellmanFord.\n";
    cout << "8.Xoa man hinh\n";
    cout << "9.Thoat.\n";
    cout << "==========================\n";
}
int main()
{
    int V = 0, E = 0; 
    struct Graph* graph;
    getVandE(V, E);
    graph = createGraph(V, E);
    int choose;
    Menu();
    do {
        cout << "Lua chon chuc nang: ";
        cin >> choose;
        switch (choose) {
            case 1: 
                // dung cho BellmanFord
                Nhapdothi(graph);
                // dung cho DFS va FS
                taoMatran(graph);

                break;
            case 2:
                system("cls");
                Menu();
                // Duyet do thi DFS
                InitWithOne();
                cout << "Duyet do thi DFS: ";
                DFS(0, V);
                cout << endl;
                // Duyet do thi DFS
                InitWithOne();
                cout << "Duyet do thi DFS: ";
                BFS(0, V);
                cout << endl;
                break;
            case 3:
                cout << "\nSo thanh phan lien thong la: " << DemSLT(V) << endl;
                break;
            case 8:
                system("cls");
                Menu();
                break;
            case 4: 
                int edge;
                cout << "Nhap dinh xuat phat (0-" << V << "): ";
                cin >> edge;
                BellmanFord(graph, edge);
        }
    } while (choose != 9);
    system("cls");
    return 0;
}
