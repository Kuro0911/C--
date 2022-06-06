/*
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef pair<ll, ll> pll;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void Bfs(int startVertex);
};
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}
void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}
void Graph::Bfs(int startVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    list<int> queue;
    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;
    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << "\n";
        queue.pop_front();
        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Graph g(4);
    g.addEdge(0 , 1);
    g.addEdge(0 , 2);
    g.addEdge(1 , 2);
    g.addEdge(2 , 0);
    g.addEdge(2 , 3);
    g.addEdge(3 , 3);

    g.Bfs(0);

#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}

// ANOTHER WAY KINDA SHIT THO:

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

using namespace std;
struct queue_1
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(queue_1 *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
};
int isEmpty(queue_1 *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
};
void enqueue(queue_1 *q, int val)
{
    if (isFull(q))
        cout << "OVERFLOWW" << endl;
    else
        q->r++;
    q->arr[q->r] = val;
};
int dequeue(queue_1 *q)
{
    int a = -1;
    if (q->f == q->r)
        cout << "UNDERFLOWW" << endl;
    else
        q->f++;
    a = q->arr[q->f];
    return a;
};
int main()
{
    queue_1 q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    //BFS
    int u;
    int i = 0;
    int visited[7];
    memset(visited,0,sizeof(visited));
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    cout<<i;
    visited[i] = 1;
    enqueue(&q,i);//explore
    while(!isEmpty(&q)){

        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0){
                cout<<j;
                visited[j] = 1;
                enqueue(&q,j);
            }
        }
    }
    return 0;
}

*/

// ANOTHER WAY (easy):

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
bool vis[N];
vector<int> adj[N];

int main()
{
    memset(vis, 0, sizeof(vis));
    int m;
    cin >> m;
    int x, y;
    for (int i = 0; i < m - 1; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int node = q.front();

        q.pop();
        cout << node << " ";

        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
    return 0;
}
