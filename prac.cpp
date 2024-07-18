#include <bits/stdc++.h>
using namespace std;

#define faster_io                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define float double
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define yes << "YES" << endl
#define no << "NO" << endl
#define all(v) v.begin(), v.end()
const int mod = 1e9 + 7;
// check if number is prime
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

vector<int> sieve(1e6 + 1);
vector<int> smallestprimesieve()
{
    for (int i = 0; i <= 1e6; i++)
    {
        sieve[i] = i;
    }
    for (int i = 2; i * i <= 1e6; i++)
    {
        if (sieve[i] == i)
        {
            for (int j = i * i; j <= 1e6; j += i)
            {
                // we check whether if its not marked by a smaller factor
                if (sieve[j] == j)
                    sieve[j] = sieve[i];
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= 1e6; i++)
    {

        if (sieve[i] == i)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

void divisor()
{
    int n;
    cin >> n;
    int i = 2;
    while (i * i <= n)
    {
        while (n % i == 0)
            n = n / i;
        i += 1;
    }
    if (n > 1)
    {
        // print n
    }
}

vector<int> bfsGraph(int v, vi adj[])
{
    // initialize
    int vis[v] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vi bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void dfsGraph(int node, vi adj[], int vis[], vi &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfsGraph(it, adj, vis, ls);
    }
}

// bool myfunc(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
// {
//     int dist_a = abs(a.first.first - third.first.first) + abs(a.first.second - third.first.second);
//     int dist_b = abs(b.first.first - third.first.first) + abs(b.first.second - third.first.second);

//     return dist_a < dist_b;
// }

int32_t main()
{
    faster_io;
    int t;
    cin >> t;
    int wrongt = 600;
    int wrongtt = 77;
    for (int tt = 1; tt <= t; tt += 1)
    {
        int n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a;
        cin >> b;
        if (t == wrongt && tt == wrongtt)
        {
            cout << n << " " << x << " " << y << endl;
            cout << a << endl;
            cout << b << endl;
        }
        if (t == wrongt)
            continue;
        int cnt = 0;
        int cost = 0;
        int left = n + 1;
        int right = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                cnt += 1;
                left = min(left, i);
                right = max(right, i);
            }
        }
        if (cnt % 2 == 1)
        {
            cost = -1;
        }
        else
        {

            if (cnt > 2)
            {
                cost = (cnt / 2) * y;
            }
            else if (cnt == 2)
            {
                if (left + 1 == right)
                {
                    if (n > 2)
                    {
                        cost = min(2 * y, x);
                    }
                    else
                    {
                        cost = x;
                    }
                }
                else
                {
                    cost = x;
                }
            }
        }

        cout << cost << endl;
    }

    return 0;
}

// 4 1 1 1 1

// 2 1 1 1

// 15 5
// 5 2 3 4 15 6 7 8 9 10 11 12 13 14 1
// 1 2 3 4 5  6 7 8 9 10 11 12 13 14 15
