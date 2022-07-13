// insert sort
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

void insertSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        int hole = i;
        int val = vec[i];
        while (hole > 0 && vec[hole - 1] > val)
        {
            vec[hole] = vec[hole - 1];
            hole--;
        }
        vec[hole] = val;
    }
    for (auto &x : vec)
    {
        cout << x << " ";
    }
}
void Bubble(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        bool flag = 0;
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] > a[j])
            {
                flag = 1;
                swap(a[i], a[j]);
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    for (auto &x : a)
    {
        cout << x << " ";
    }
}

void binSearch(vector<int> &vec, int low, int hi, int target)
{
    if (low <= hi)
    {
        int mid = (low + hi) / 2;
        if (vec[mid] == target)
        {
            cout << "Found\n";
            return;
        }
        else if (vec[mid] < target)
        {
            binSearch(vec, low, mid - 1, target);
        }
        else
        {
            binSearch(vec, mid + 1, hi, target);
        }
        return;
    }
    cout << "NF\n";
    return;
}
void merge(vector<int> &a, int low, int mid, int hi)
{
    int i = low, k = low;
    int j = mid + 1;
    int temp[101];
    while (i <= mid && j <= hi)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= hi)
    {
        temp[k++] = a[j++];
    }
    for (int x = low; x <= hi; x++)
    {
        a[x] = temp[x];
    }
    return;
}
void mergeSort(vector<int> &a, int low, int hi)
{
    if (low < hi)
    {
        int mid = (low + hi) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, hi);
        merge(a, low, mid, hi);
    }
}
int partition(vector<int> &a, int low, int hi)
{
    int pivot = a[hi];
    int pIndex = low;
    for (int i = low; i < hi; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[hi], a[pIndex]);
    return pIndex;
};
void QuickSort(vector<int> &a, int low, int hi)
{
    if (low >= hi)
    {
        return;
    }
    int p = partition(a, low, hi);
    QuickSort(a, low, p - 1);
    QuickSort(a, p + 1, hi);
}

int MaxSubSum(vector<int> &a, int low, int hi)
{
    if (low == hi)
    {
        return a[low];
    }
    int mid = (low + hi) / 2;
    int L_mss = MaxSubSum(a, low, mid);
    int R_mss = MaxSubSum(a, mid + 1, hi);
    int R_sum = INT_MIN, L_sum = INT_MIN, sum = 0;
    for (int i = mid; i <= hi; i++)
    {
        sum += a[i];
        R_sum = max(R_sum, sum);
    }
    sum = 0;
    for (int i = mid - 1; i >= low; i--)
    {
        sum += a[i];
        L_sum = max(L_sum, sum);
    }
    int ans = max(R_mss, L_mss);
    return (ans, R_sum + L_sum);
}
pair<int, int> MaxMin(vector<int> &a, int st, int ed)
{
    pair<int, int> p;
    if (st == ed)
    {
        p.first = a[st];
        p.second = a[st];
        return p;
    }
    if (st + 1 == ed)
    {
        p.first = min(a[st], a[ed]);
        p.second = max(a[st], a[ed]);
        return p;
    }
    int mid = (st + ed) / 2;
    p.first = min(MaxMin(a, st, mid).first, MaxMin(a, mid + 1, ed).first);
    p.second = max(MaxMin(a, st, mid).second, MaxMin(a, mid + 1, ed).second);
    return p;
}

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};
treeNode *root = NULL;
treeNode *getNewNode(int data)
{
    treeNode *newNode = new treeNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
treeNode *insert(treeNode *root, int info)
{
    if (root == NULL)
    {
        root = getNewNode(info);
        return root;
    }
    else if (info <= root->data)
    {
        root->left = insert(root->left, info);
    }
    else
    {
        root->right = insert(root->right, info);
    }
    return root;
}
void preOrder(treeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void InOrder(treeNode *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
void postOrder(treeNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
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
bool queenSol(int col, int n)
{
    if (col >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, n))
        {
            mat[i][col] = 1;
            if (queenSol(col + 1, n))
            {
                return true;
            }
        }
    }
    return;
}
void solve()
{
    vector<int> vec{5, 4, 3, 2, 1};
    // insertSort(vec);
    // Bubble(vec);
    // binSearch(vec, 0, vec.size() - 1, 6);
    // mergeSort(vec, 0, vec.size() - 1);
    // QuickSort(vec, 0, vec.size() - 1);
    // cout << MaxSubSum(vec, 0, vec.size() - 1);
    // cout << MaxMin(vec, 0, vec.size() - 1).first << " " << MaxMin(vec, 0, vec.size() - 1).second;

    // int n, x;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> x;
    //     root = insert(root, x);
    // }
    // preOrder(root);
    // cout << "\n";
    // InOrder(root);
    // cout << "\n";
    // postOrder(root);

    // for (auto &x : vec)
    // {
    //     cout << x << " ";
    // }
    memset(mat, 0, sizeof(mat));
    queenSol(0, 4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
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