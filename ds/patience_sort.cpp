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

// #####################################################

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &x : v)
        os << x << " ";
    os << endl;
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v)
{
    for (auto it : v)
        os << it << " ";
    return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v)
{
    for (auto it : v)
        os << it.first << " : " << it.second << endl;
    return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v)
{
    os << v.first << " : " << v.second << endl;
    return os;
}

// #####################################################

/**
 * @file
 * @author Vassilii Khachaturov
 * @version $Id: patience_sort.hpp,v 1.5 2006/05/29 15:18:25 vassilii Exp $
 *
 * Patience sort algorithm
 *
 * @todo code in the concept checks/archetypes
 *
 * card_type must be LessThanComparable (total ordering required for patience sorting!)
 *
 * TableType requirements
 *	-# whatever lower_bound needs
 *	-# begin(), end(): ForwardIterator of piles
 *
 * PileType requirements
 *  -# default constructible
 *  -# constructible from a single card const reference
 *		typedef typename PileType::value_type card_type;
 *  -# push_back(const card_type&)
 *  -# assignable, lightweight on a singleton pile
 *  -# whatever lower_bound needs
 *  -# back() implemented or an appropriate pile_less specialization
 *  	XXX do a spec for StickyPile
 */

/**
 * Comparator for two piles according to their top card values.
 * Compares cards using operator<
 */
template <typename pile_type>
struct pile_less : std::binary_function<pile_type, pile_type, bool>
{
    bool operator()(const pile_type &x, const pile_type &y) const
    {
        return x.back() < y.back();
    }
};

/**
 * Comparator for two piles according to their top card values.
 * Compares cards using operator<
 */
template <typename pile_type, typename Compare>
struct pile_comp : std::binary_function<pile_type, pile_type, bool>
{
    Compare comp;
    pile_comp(Compare &c) : comp(c) {}
    bool operator()(const pile_type &x, const pile_type &y) const
    {
        return comp(x.back(), y.back());
    }
};

/**
 * Patience sort algorithm as per Aldous and Diaconis,
 * using binary search to select the leftmost heap for a new card.
 * Compares cards using operator<
 */
template <typename PileType, typename TableType, typename InputIterator>
void patience_sort(TableType &table, InputIterator first, InputIterator last)
{
    typedef PileType pile_type;
    typedef typename PileType::value_type card_type;
    typedef TableType table_type;
    typedef typename table_type::iterator iterator;

    while (first != last)
    {
        pile_type new_pile(*first); // read *first only once! (input iterator)
        // find the leftmost heap with the top card greater
        // than *first , to push *first on it
        iterator pile_p = std::lower_bound(
            table.begin(), table.end(), new_pile,
            pile_less<pile_type>());
        if (pile_p != table.end())
        {
            pile_p->push_back(new_pile.back());
        }
        // ...or allocate a new heap on the right with *first
        else
        {
            table.push_back(new_pile);
        }
        first++;
    }
}

/**
 * A class representing a pile that is sticky, i.e., once a card
 * is put onto its top, it's glued forever. This way, only
 * the top card is actually remembered (O(1) memory per heap).
 * Used by longest_increasing_subsequence().
 *
 * Unfortunately, such heap is impossible to use in more advanced
 * algorithms, such as the Bespamyatnykh and Segal one, for the
 * actual longest increasing subsequence recovery.
 */
template <typename Card>
struct StickyPile
{ // cards stick together when put here :-)
    typedef Card value_type;
    typedef const value_type &const_reference;
    StickyPile(const Card &_card) : card(_card) {}
    void push_back(const Card &_card) { card = _card; }
    const_reference back() const { return card; }

private:
    Card card;
};

/** Find the length of the longest increasing subsequence
 * given by the given iterator range, using patience_sort().
 * Compares cards using operator<
 */
template <typename InputIterator>
size_t longest_increasing_subsequence(
    InputIterator first, InputIterator last)
{
    typedef typename std::iterator_traits<InputIterator>::value_type Card;
    typedef StickyPile<Card> pile_type;
    typedef std::vector<pile_type> table_type;
    table_type table;
    patience_sort<pile_type>(table, first, last);
    return table.size();
}

/** Find the length of the longest increasing subsequence
 * given by the given iterator range, using patience_sort().
 * Compares cards using the given comparator.
 */
template <typename InputIterator, typename Compare>
size_t longest_increasing_subsequence(
    InputIterator first, InputIterator last, Compare comp)
{
    typedef typename std::iterator_traits<InputIterator>::value_type Card;
    typedef StickyPile<Card> pile_type;
    typedef std::vector<pile_type> table_type;
    table_type table;
    patience_sort<pile_type>(table, first, last, comp);
    return table.size();
}

class patience_sort2
{
    vector<int> arr;

public:
    vector<int> getSorted()
    {
        return arr;
    }
    patience_sort2(vector<int> nums)
    {
        vector<int> ans(nums.size(), 0);
        int i = -1, len = 1;
        ans[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            auto st = ans.begin();
            auto ed = ans.begin() + len;
            auto it = lower_bound(st, ed, nums[i]);
            if (it == ans.end())
            {
                ans[len++] = nums[i];
            }
            else
            {
                *it = nums[i];
            }
        }
        cout << ans;
        ans = arr;
    };
};

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
    {
        cin >> x;
    }
    patience_sort2 x(arr);
    x.getSorted();
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
// for (int i = 1; i <= t; i++)
//{
// cout << "Case #" << i << ": " ;
// solve();
//}
#ifndef ONLINE_JUDGE
    cerr << "Time :" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
#endif
    return 0;
}
