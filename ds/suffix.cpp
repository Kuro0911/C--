//1;
/*
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    //k == 0
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++)
        a[i] = {s[i], i};
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
        p[i] = a[i].second;

    c[p[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i].first == a[i - 1].first)
        {
            c[p[i]] = c[p[i - 1]];
        }
        else
        {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n)
    {
        //k --> k + 1
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
            p[i] = a[i].second;

        c[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
            {
                c[p[i]] = c[p[i - 1]];
            }
            else
            {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}


//********************USING RADIX SORT N LOG N TIME*********************


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void radix_sort(vector<pair<pair<int, int>, int>> &a)
{
    int n = a.size();
    {

        vector<int> cnt(n);
        for (auto x : a)
        {
            cnt[x.first.second]++;
        }
        vector<pair<pair<int, int>, int>> new_a(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++)
        {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : a)
        {
            int i = x.first.second;
            new_a[pos[i]] = x;
            pos[i]++;
        }

        a = new_a;
    }
    {

        vector<int> cnt(n);
        for (auto x : a)
        {
            cnt[x.first.first]++;
        }
        vector<pair<pair<int, int>, int>> new_a(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++)
        {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : a)
        {
            int i = x.first.first;
            new_a[pos[i]] = x;
            pos[i]++;
        }
        a = new_a;
    }
};

void solve()
{
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    //k == 0
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++)
        a[i] = {s[i], i};
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
        p[i] = a[i].second;

    c[p[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i].first == a[i - 1].first)
        {
            c[p[i]] = c[p[i - 1]];
        }
        else
        {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n)
    {
        //k --> k + 1
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        radix_sort(a);

        for (int i = 0; i < n; i++)
            p[i] = a[i].second;

        c[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
            {
                c[p[i]] = c[p[i - 1]];
            }
            else
            {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}


//***********************EVEN BETTER WAY count_sort ***********************

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void count_sort(vector<int> &p, vector<int> &c)
{
    int n = p.size();
    vector<int> cnt(n);
    for (auto x : c)
    {
        cnt[x]++;
    }
    vector<int> new_p(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : p)
    {
        int i = c[x];
        new_p[pos[i]] = x;
        pos[i]++;
    }
    p = new_p;
};

void solve()
{
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    //k == 0
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++)
        a[i] = {s[i], i};
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
        p[i] = a[i].second;

    c[p[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i].first == a[i - 1].first)
        {
            c[p[i]] = c[p[i - 1]];
        }
        else
        {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n)
    {
        //k --> k + 1
        for (int i = 0; i < n; i++)
        {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort(p, c);

        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if (now == prev)
            {
                c_new[p[i]] = c_new[p[i - 1]];
            }
            else
            {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}

**************** LCP(longest common prefix) OF STRINGS ******************

*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void count_sort(vector<int> &p, vector<int> &c)
{
    int n = p.size();
    vector<int> cnt(n);
    for (auto x : c)
    {
        cnt[x]++;
    }
    vector<int> new_p(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : p)
    {
        int i = c[x];
        new_p[pos[i]] = x;
        pos[i]++;
    }
    p = new_p;
};

void solve()
{
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    //k == 0
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++)
        a[i] = {s[i], i};
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
        p[i] = a[i].second;

    c[p[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i].first == a[i - 1].first)
        {
            c[p[i]] = c[p[i - 1]];
        }
        else
        {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n)
    {
        //k --> k + 1
        for (int i = 0; i < n; i++)
        {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort(p, c);

        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if (now == prev)
            {
                c_new[p[i]] = c_new[p[i - 1]];
            }
            else
            {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }

    vector<int> lcp(n);
    int z = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int pi = c[i];
        int j = p[pi - 1];
        //lcp of these 2 suffixes;
        while (s[i + z] == s[j + z]) z++;
        lcp[pi] = z;
        z = max(z - 1, 0);
    }
    for (int i = 0; i < n; i++)
    {
        cout << lcp[i] << " " << p[i] << " " << s.substr(p[i], n - p[i]) << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}