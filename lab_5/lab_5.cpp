#include <iostream>
#define inf 1000000
using namespace std;
int min_top(int** arr,int v) {
    int m=0;
    for (int i = 0; i < v; i++) {
        if (arr[i][1]) {
            m = i; break;
        }
    }

    for (int i = 1; i < v; i++) {
        if (arr[m][0] >= arr[i][0] && arr[i][1]==1) {
            m = i;
        }
    }
    return m;
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    int a, b, c;
    int v = 0;
    cout << "Кiлькiсть вершин графа : ";
    cin >> v;
    int** graph = new int* [v];

    for (int j = 0; j < v; j++) {
        graph[j] = new int[v];
    }

    for (int a = 0; a < v; a++) {
        for (int j = 0; j < v; j++) {
             graph[a][j] = 0;

        }
    }
    cout << "Введiть вагу ребер графа : " << endl;

    while (true) {
        cin >> a;
        if (a == -1) { break; }
        cin >> b;
        cin >> c;
        graph[a-1][b-1] = graph[b-1][a-1] = c;
    }



    int p;
    int** tops = new int*[v];
    for (int j = 0; j < v; j++) {
        tops[j] = new int[2];
    }
    int* tops_path = new int[v];

    cout << "Вихiдна вершина: ";
    cin >> p;

    for (int i = 0; i < v; i++) {
        if (i == p-1) {
            tops[i][0] = 0;
            tops[i][1] = 1;
        }
        else {
            tops[i][0] = inf;
            tops[i][1] = 1;
        }
    }
    tops_path[p-1] = 0;
    


    int m;

    for (int i = 0; i < v; i++) {
        m = min_top(tops, v);
        for (int j = 0; j < v; j++) {
            if (graph[m][j]) {
                if (tops[j][0] > tops[m][0] + (graph[m][j])) {
                    tops[j][0] = tops[m][0] + (graph[m][j]);
                    tops_path[j] = m;
                }
            }

        }
        tops[m][1] = 0;         

    }

    ////шлях
    cout << "Введiть потрiбну вершину: ";
    int k; cin >> k; 
    cout << "Мiнiмальний шлях: ";
    cout << tops[k-1][0];
    cout << endl << k <<" <-- ";
    k--;
    for (int a = 0; tops_path[k] != p-1; a++) {
        cout << tops_path[k]+1 <<" <-- ";
        k = tops_path[k];
    }
    cout << p << endl;


    return 0;
}
