/*
open this for a better understanding in the future
https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/


#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

class Graph{
    int V;
    list<pii> *adj;
    public:
        Graph(int V);
        void addEdge(int u , int v , int w);
        void shortestPath(int s);
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<pii> [V];
}
void Graph::addEdge(int u , int v, int w){
    adj[u].push_back(make_pair(v , w));
    adj[v].push_back(make_pair(u , w));
}
void Graph::shortestPath(int src){
    priority_queue<pii , vector<pii> , greater<pii> > pq;
    vector<int> dist(V , INF);

    pq.push(make_pair(0 , src));
    dist[src] = 0 ;
    while (!pq.empty())     
    {
        int u = pq.top().second;
        pq.pop();
        list<pii> :: iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if(dist[v] > dist[u] + weight){
                dist[v] =  dist[u] + weight;
                pq.push(make_pair(dist[v] , v));
            }
        }
    }
    cout<<"Vertex \t\t Distance from source \n";
    for (int i = 0; i < V; i++)
    {
        cout<<i<<"\t\t"<<dist[i]<<"\n";
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V = 9;
    Graph g(V);
  
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
  
    g.shortestPath(0);

    #ifndef ONLINE_JUDGE
    cerr <<"Time :"<<1000*((double)clock()) / (double)CLOCKS_PER_SEC<<"ms";
    #endif
        return 0;
}
*/
//another way;
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

void addEdge(vector<pii> adj[] ,int u,int v,int wt){
    adj[u].push_back(make_pair(v , wt));
    adj[v].push_back(make_pair(u , wt));
}
void shortestPath(vector<pii> adj[], int V , int src){
    priority_queue<pii , vector<pii> , greater<pii> > pq;
    vector<int> dist(V , INF);

    pq.push(make_pair(0 , src));
    dist[src] = 0 ;
    while (!pq.empty())     
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if(dist[v] > dist[u] + weight){
                dist[v] =  dist[u] + weight;
                pq.push(make_pair(dist[v] , v));
            }
        }
    }
    cout<<"Vertex \t\t Distance from source \n";
    for (int i = 0; i < V; i++)
    {
        cout<<i<<"\t\t"<<dist[i]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V = 9;
    vector<pii> adj[V];
  
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
  
    shortestPath(adj, V, 0);

    #ifndef ONLINE_JUDGE
    cerr <<"Time :"<<1000*((double)clock()) / (double)CLOCKS_PER_SEC<<"ms";
    #endif
        return 0;
}