#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    
    int A[100][100] = {0};

    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        A[u][v] = 1;
        A[v][u] = 1; 
    }

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}

