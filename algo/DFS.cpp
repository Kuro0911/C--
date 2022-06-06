/*
#include <bits/stdc++.h>

using namespace std;
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

class Graph{
    public:
        map<int , bool> visited;
        map<int , list<int>> adj;

        void addEdge(int v,int w);
        void Dfs(int v);
};
void Graph::addEdge(int v , int w){
    adj[v].push_back(w);
}
void Graph::Dfs(int v){
    visited[v] = true;
    cout<<"Visited : "<<v<<"\n";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            Dfs(*i);
        }
    }
     
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Graph g;
    g.addEdge(0 , 1);
    g.addEdge(0 , 2);
    g.addEdge(1 , 2);
    g.addEdge(2 , 0);
    g.addEdge(2 , 3);
    g.addEdge(3 , 3);
    
    cout<<"Following is  the Dfs traversal starting from 2 \n";
    g.Dfs(2);
    #ifndef ONLINE_JUDGE
    cerr <<"Time :"<<1000*((double)clock()) / (double)CLOCKS_PER_SEC<<"ms";
    #endif
        return 0;
}

//ANOTHER WAY:
#include <bits/stdc++.h>
using namespace std;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
void DFS(int i){
    cout<<i<<" ";
        visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if(a[i][j] == 1 && !visited[j])
        DFS(j);
    }
}
int main()
{
    DFS(0); 
    return 0;
}
*/

//ANOTHER WAY:

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];

void dfs(int node){
    vis[node] = true;
    cout<<node<<" ";
    vector<int> :: iterator it;
    for (it = adj[node].begin();it!=adj[node].end();it++)
    {
        if(!vis[*it]){
            dfs(*it);
        }
    }
}
int main(){
    memset(vis,false,sizeof(vis));
    int n,m;
    cin>>n>>m;
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    
    return 0;
}
