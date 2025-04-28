#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Fibonacci[10001] = {0};

void knapSack()
{
    int n, M;
    cin >> n >> M;
    vector<int> W(n+1), V(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> W[i] >> V[i];
    }

    vector<vector<int>> f(n+1, vector<int>(M+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            f[i][j] = f[i-1][j];
            if (j >= W[i]) {
                f[i][j] = max(f[i][j], f[i-1][j-W[i]] + V[i]);
            }
        }
    }
    for(const auto& x : f)
    {
        for(const auto& val : x)
        {
            cout << val << " ";
        }
        cout << '\n';
    }

    cout << "Gia tri lon nhat: " << f[n][M] << endl;


    int j = M;
    cout << "Cac goi hang duoc lay: ";
    for (int i = n; i >= 1; i--) {
        if (f[i][j] != f[i-1][j]) {
            cout << i << " "; 
            j -= W[i];
        }
    }
    cout << endl;
}


void FindFibonacci(int n)
{
    if(n < 0) return;
    for(int i = 2;i<=n;i++)
    {
        Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
    }
    cout << Fibonacci[n];
}

void sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    
    for (int i = 2; i * i <= n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (prime[i])
            cout << i << " ";
    }
}

const int INF = 1e9; // vô cực

struct Edge {
    int to, weight;
};

// void dijktra(int n,int start, vector<vector<Edge>>& adj, vector<int>& d, vector<bool>& visited)
// {
// 	for (int i = 0; i < n; i++) {
//         int u = -1;
//         int minD = INF;
//         for (int j = 0; j < n; j++) {
//             if (!visited[j] && d[j] < minD) {
//                 minD = d[j];
//                 u = j;
//             }
//         }
        
//         if (u == -1) break; 
        
//         visited[u] = true;
        
//         for (auto edge : adj[u]) {
//             int v = edge.to;
//             int w = edge.weight;
//             if (d[v] > d[u] + w) {
//                 d[v] = d[u] + w;
//             }
//         }
//     }
    
//     for (int i = 0; i < n; i++) {
//         cout << "Khoang cach tu " << start << " den " << i << " = ";
//         if (d[i] == INF) cout << "khong co duong di\n";
//         else cout << d[i] << endl;
//     }
// }
int main() {
	
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	#endif
    // int n, m, start;
    // cin >> n >> m >> start;
    
    // vector<vector<Edge>> adj(n);
    // for (int i = 0; i < m; i++) {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     adj[u].push_back({v, w});
    // }
    
    // vector<int> d(n, INF);
    // vector<bool> visited(n, false);
    // d[start] = 0;
    // dijktra(n,start,adj, d,visited);
    // fibonacci[0] = 1; fibonacci[1] = 1;
    // FindFibonacci(2);
    // sieve(100);
    knapSack();
    
    return 0;
}
