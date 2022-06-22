/*
ALGO :finite sequence of instructions of which has a clear meaning and can be performed with a finite amount
of time

Algo should:
    TAKE INPUT ===> ALGO ====> OUTPUT

Properties and characters of ALGO:
1.INPUT
2.OUTPUT
3.FINITENESS
4.DEFINITENESS
5.EFFECTIVENESS
6.CORRECTNESS
7.GENERALITY
8.MULTIPLE AVAILABLITY

#Expressing Algos

Their are 2 ways to express algos:
1.Pseudo Code
2.FlowChart

#Performance Analysis of Algorithm:

Their are 2 ways to perfom Anal algos:
1.Space complexity:
    s(P) = C(constant) + Sp(variable)

2.Time complexity:
    methods:
    1) LineCount stepCount:
        * find steps per execution:
            ->Declatrative statements with no initializations have a step Count of 0 if initiallizations are done
                then stepCount is one
            ->Brakets, comments , the terms such as begin, end, while, for, all have step counter 0
            ->Expressions have a step count of 1
            ->assignment statement , function invocation , return statements and other statements such as break,
                    continue go to all have step count of one
        * Find Frequency of statements
        * Total count is Steps/execution * frequency

#Class of func / order of growth :
    1 < log(n) < root(n) < n < nlog(n) < n^2 < n^3 < n^4 <...< 2^n < 3^n < ... < n^n

BIG O = UPPER BOUND
BIG OMEGA = LOWER BOUND
THETA NOTATION = AVG BOUND

#RECURSION:
    1) SUBSTITUTION METHOD -> FORWARD AND BACKWORD
    2) RECURSION TREE METHOD
    3) MASTERS METHOD

Solve the relation => T(n) = 1 + T(n-1)
                      T(n-1) = 1 + T(n-2)

# Recursion tree / recurrence tree method
T(n) = aT(n/b) + (cn)
n/b = size of subprob
a - number of subprob
cn - cost for dividing and combining

T(n) = 2T(n/2) + n;
cost size of subprob at each lvl
n   | n/2^0
n   |n/2^1
n   |n/2^2
n   |n/2^3...


UNIT 2: DIVIDE AND CONQUER

DIVIDE AND CONQUER : larger problem is divided into smaller sub-problems
                    it works in a top down manner
examples: bs, merge sort , quick sort, matrix multi
-> General structure of divide and conquer:
        DAC(P){
            if(small(P)){
                s(p);
            }else{
                divide P into P1, P2 , P3 .... PK
                apply DAC(P1) , DAC(P2) , ... DAC(PK)
                COMBINE DAC(P1) , DAC(P2) , ... DAC(PK)
            }
        }
-> 3 step method:
    1. Divide
    2. Conquer
    3. Combine
Disadvantages:
    lot of change of control
Bin Search:

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tb ' '
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)x.size())
#define MOD (int)(1e9 + 7)
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;

int n, a[100];
void binSearch(int st, int ed, int ele)
{
    if (st >= ed)
    {
        cout << "NF\n";
        return;
    }
    int md = (ed + st) / 2;
    if (a[md] > ele)
    {
        binSearch(st, md - 1, ele);
    }
    else if (a[md] < ele)
    {
        binSearch(md + 1, ed, ele);
    }
    else
    {
        cout << "found\n";
    }
}
void solve()
{
    int ele;
    cin >> n >> ele;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    binSearch(0, n - 1, ele);
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}

Time :
    Best -> O(1)
    Avg -> O(log n)
    Worst -> O(log n)

MaxMin(a , i , j , max , min){
    if(i == j) then max = min = a[i];
        else if(i = j-1) then
            if(A[i] < A[j]){
                Max = a[j];
                min = a[i];
            }
            else{
                max = a[i]
                min - a[j]
            }
    else
        mid = i + j / 2
    MaxMin(i, mid , max , min)
    MaxMin(mid + 1,  j , max + 1, min - 1)
    if(max < max1) then max = max1;
    if(min < min1) then min = min1;

}
// Maximum/Largest Subarray Sum using divide and conquer
Sol:
    Divide Array into two halves
    Return the max of the following
        a) Maximum sub array sum in left half
        b) Maximum sum array sum in tge right half
        c) max sub array sum such that the sub array crosses the midpoint
            i) Find maximum sum for staring from midpoint and ending at some point on left of mid
            ii) Find maximum sum starting from mid + 1 and ending at some point on right of mid + 1
            iii) finally combine the two return (lhs + rhs = cross sum)
Example:
    -2 , -5 , 6 , -2 | -3 , 1 , 5 , -6
    (- 2 , -5 | 6 ,-2) (-3 , 1 | 5 , -6)
    ((-2 , -5 | 6 , -2) ( -3 , 1 | 5 , -6))
    - 2 | -5  | 6 | -2 | -3 | 1 | 5 | -6
        -2    |   6    |   1  |   5
                6  |   6  |  cs = 7
                ans = 7

=> Algorithm Greedy:
    Solution Set = NULL
    while(sol is not complete ) do
        select a best candidate solution
        if x is a feasable solution then add the solution X to the solution set
        end if
        if(sol is obtained)
            return solution set
        end if
    end while
    end
=> Huffman Encoding Techique
ASCII  ->> 8 bits   }
                        -> Fixed length encoding
UNICODE ->> 16 bits }
the codes are assinged in such a way that a code assigned to one character is a prefix of code any other
character
this is how huffman encoding makes sure that there is no ambiguity when the decoding the generated bit stream
the variable length code assinnged to input characters are called as prefix codes


//Knapsack:
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tb ' '
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)x.size())
#define MOD (int)(1e9 + 7)
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n), w(n);
    for (auto &x : p)
        cin >> x;
    for (auto &x : w)
        cin >> x;
    int ans[n + 1][m + 1];
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j - w[i] > 0)
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - w[i - 1]] + p[i - 1]);
            else
                ans[i][j] = ans[i - 1][j];
        }
        cout << endl;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << ans[i][j] << tb;
        }
        cout << endl;
    }
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}


//UNIT 4

BACKTRACKING : DFS
    it is a systematic way to go through all the possible configurations of a search space in the genral
    case we assume out sol is a vector v = [a1, a2, a3,...an] where each element ai is selected from a finite
    ordered set si
    the basic idea is to build up the solution vector one compoent at a time and use modified criterion func
    to test weather the vector being formed has any chance of success
    main adv is we can ignore all the remaining possible test vectors when we realise that we can not get to
    a sol
    These require constrants which are
    #1 Explicit :-
    these restrict each xi to take values from a given set
    #2 Implicit :-
    These are rules that determine which of the tuples in the sol space satisfy the criterion func thus they
    describe the way xi is reated to each other

n queens
on a n x n board you are to put n queens so that so queen can attack each other

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tb ' '
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)x.size())
#define MOD (int)(1e9 + 7)
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;

int mat[101][101];

bool isSafe(int row, int col, int n)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (mat[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (mat[i][j])
            return false;
    return true;
}
bool getAns(int n, int col)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, n))
        {
            mat[i][col] = 1;
            if (getAns(n, col + 1))
            {
                return true;
            }
            mat[i][col] = 0;
        }
    }
    return false;
}
void printAns(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
void solve()
{
    memset(mat, 0, sizeof(mat));
    int n;
    cin >> n;
    getAns(n, 0);
    printAns(n);
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}

Sub set sum:

basic bactrack we add a node in if we dont get sol we ignore it

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tb ' '
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)x.size())
#define MOD (int)(1e9 + 7)
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;

bool isSubsetSum(int set[], int n, int sm)
{
    if (sm == 0)
        return true;
    if (n == 0)
        return false;
    if (set[n - 1] > sm)
    {
        return isSubsetSum(set, n - 1, sm);
    }
    return isSubsetSum(set, n - 1, sm) || isSubsetSum(set, n - 1, sm - set[n - 1]);
    //add in a global var which stores the res like in n queens problem
}
void solve()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sm = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sm) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}

# HAMILTONIAN CYCLE
    Find all possible ways to visit all the verticies in a graph exactly once

    * articulation point : a junction which connects 2 graphs so if their exists a point like this then we
                do not have a hamiltonian cycle in the graph

    Algo:
    Hamiltonian(k) {
        do{
            nextVert(k);
            if(x[k] == 0) return;
            if(k == n) print(x[1:n]);
            else Hamiltonian(k + 1);
        }while(True)
    }
    nextVert(k){
        do{
            x[k] = (x[k] + 1) % (n + 1);
            if(x[k] == 0) return;
            if((G[x[k - 1] , x[k]])){
                for j = 1 to k - 1 do if(x[j] == x[k]) break;
                if(j == k)
                    if(k < n or (k == n) && G[x[n], x[1]] != 0) return;
            }
        }while(True)
    }


# BRANCH AND BOUND
    it refers to all state space search methods in which all children of the e node are generated before any other
live node can become the e node



# Traveling sales man
#include <bits/stdc++.h>
using namespace std;
#define V 4

int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;
    do
    {
        int current_pathweight = 0;

        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        min_path = min(min_path, current_pathweight);

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main()
{
    // matrix representation of graph
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}

//UNIT 5

# Randomized Algorithms

an algo that uses random numbers to decide what to do next anywhere in its logic is called randomized algo

# classification of random algo
    1) Las Vegas:   these algorithms always produce correct/optimum results time is based on a random value and time is evaluated
as expected value for example randomized quick sort Time(O(n log n))

    2) Monte Carlo: Produce correct or optimum res with some probability these have deterministic running
    time and it is generally easier to find out worst case time complexity as O(E) Another example is Fremet
    method for primality testing

# NP problems: P is a set of problems that can be solved by a deterministic Turing machine in polynimial time
** Np is a set of decision problems that can be solved in pollynomial time via a Lucky alogorithm that always
chooses the correct path among a given set of paths

Np complete are the hardest in np set

*/
