/*                 _        ____              */
/*   AC        U  /"\  u U /"___|     AC      */
/*              \/ _ \/  \| | u               */
/*        AC    / ___ \   | |/__    AC        */
/*             /_/   \_\   \____|             */
/* AC           \\    >>  _// \\         AC   */
/*             (__)  (__)(__)(__)             */
/*          github.com/NULLCT/Compro          */

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define int long long
#define double long double
#define rep(i, e) for (int i = 0; i < (e); i++)
#define ALL(var) ((var).begin()), ((var).end())
#ifdef DEBUG
#define D(var) cerr << __LINE__ << ":" << #var << " " << var << endl;
#define DD(var) for_each(var.begin(), var.end(), [](const auto &i) { D(i); })
#else
#define D(var) ;
#define DD(var) ;
#endif

using namespace std;

template <class T, size_t S>
ostream &operator<<(ostream &_ostr, const array<T, S> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const vector<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const deque<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const list<T> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v);
template <class... Ts>
ostream &operator<<(ostream &_ostr, const tuple<Ts...> &t);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const map<T, Y> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const multimap<T, Y> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_multimap<T, Y> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const set<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const multiset<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_multiset<T> &_v);

template <class T>
void orange(ostream &_ostr, const T &_v) {
  if (_v.size() == 0)
    return;
  _ostr << *_v.begin();
  for (auto itr = next(_v.begin()); itr != _v.end(); itr++)
    _ostr << " " << *itr;
}
template <class T, size_t S>
ostream &operator<<(ostream &_ostr, const array<T, S> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const vector<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const deque<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const list<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v) {
  _ostr << _v.first << " " << _v.second;
  return _ostr;
}
template <class... Ts>
ostream &operator<<(ostream &_ostr, const tuple<Ts...> &_v) {
  bool first = true;
  apply([&_ostr, &first](auto &&...args) {
    auto print = [&](auto &&val) {
      if (!first)
        _ostr << " ";
      (_ostr << val);
      first = false;
    };
    (print(args), ...);
  },
        _v);
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const map<T, Y> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const multimap<T, Y> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const set<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const multiset<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_multiset<T> &_v) {
  orange(_ostr, _v);
  return _ostr;
}

template <class T, size_t S>
istream &operator>>(istream &_istr, array<T, S> &_v);
template <class T>
istream &operator>>(istream &_istr, vector<T> &_v);
template <class T>
istream &operator>>(istream &_istr, deque<T> &_v);
template <class T, class Y>
istream &operator>>(istream &_istr, pair<T, Y> &_v);

template <class T, size_t S>
istream &operator>>(istream &_istr, array<T, S> &_v) {
  for (auto &i : _v)
    _istr >> i;
  return _istr;
}
template <class T>
istream &operator>>(istream &_istr, vector<T> &_v) {
  for (auto &i : _v)
    _istr >> i;
  return _istr;
}
template <class T>
istream &operator>>(istream &_istr, deque<T> &_v) {
  for (auto &i : _v)
    _istr >> i;
  return _istr;
}
template <class T, class Y>
istream &operator>>(istream &_istr, pair<T, Y> &_v) {
  _istr >> _v.first >> _v.second;
  return _istr;
}

template <int mod>
class ModInt {
public:
  int n;
  constexpr ModInt(const int x = 0) : n(x % mod) {}
  constexpr ModInt operator+(const ModInt &rhs) {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator-(const ModInt &rhs) {
    return ModInt(*this) -= rhs;
  }
  constexpr ModInt operator*(const ModInt &rhs) {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt operator/(const ModInt &rhs) {
    return ModInt(*this) /= rhs;
  }
  constexpr ModInt &operator+=(const ModInt &rhs) {
    n += rhs.n;
    if (n >= mod)
      n -= mod;
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt &rhs) {
    if (n < rhs.n)
      n += mod;
    n -= rhs.n;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt &rhs) {
    n = n * rhs.n % mod;
    return *this;
  }
  constexpr ModInt &operator/=(const ModInt &rhs) {
    int exp = mod - 2;
    while (exp) {
      if (exp % 2)
        *this *= rhs;
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
  constexpr bool operator==(const ModInt &rhs) {
    return n == rhs.n;
  }
  template <int T>
  friend ostream &operator<<(ostream &_ostr, const ModInt<T> &_v) {
    _ostr << _v.n;
    return _ostr;
  }
  template <int T>
  friend istream &operator>>(istream &_istr, ModInt<T> &_v) {
    int in;cin>>in;
    _v = in;
    return _istr;
  }
};

int mop(int a, int n, int mod) {
  int res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int mop(int a, int n) {
  int res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

template <class T>
class SegmentTree {
public:
  int sz;
  vector<T> seg;
  const function<T(T, T)> f;
  const T M1;
  SegmentTree(int n, const function<T(T, T)> _f, const T &_M1) : f(_f), M1(_M1) {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    seg.assign(2 * sz, _M1);
  }
  void set(int k, const T &x) {
    seg[k + sz] = x;
  }
  void build() {
    for (int k = sz - 1; k > 0; k--)
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
  }
  void update(int k, const T &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1)
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
  }
  // O(log n)
  T query(int a, int b) {
    T L = M1, R = M1;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1)
        L = f(L, seg[a++]);
      if (b & 1)
        R = f(seg[--b], R);
    }
    return f(L, R);
  }
  T operator[](const int &k) const {
    return seg[k + sz];
  }
  template <class C>
  int find_subtree(int a, const C &check, T &M, bool type) {
    while (a < sz) {
      T nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if (check(nxt))
        a = 2 * a + type;
      else
        M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }
  template <class C>
  int find_first(int a, const C &check) {
    T L = M1;
    if (a <= 0) {
      if (check(f(L, seg[1])))
        return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) {
        T nxt = f(L, seg[a]);
        if (check(nxt))
          return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }
  template <class C>
  int find_last(int b, const C &check) {
    T R = M1;
    if (b >= sz) {
      if (check(f(seg[1], R)))
        return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for (b += sz; a < b; a >>= 1, b >>= 1) {
      if (b & 1) {
        T nxt = f(seg[--b], R);
        if (check(nxt))
          return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

class UnionFind {
public:
  int n;
  vector<int> p;
  UnionFind(int _n) : n(_n), p(_n, -1) {}
  int merge(int a, int b) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    int x = root(a), y = root(b);
    if (x == y)
      return x;
    if (-p[x] < -p[y])
      swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return x;
  }
  bool isSame(int a, int b) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    return root(a) == root(b);
  }
  int root(int a) {
    assert(0 <= a && a < n);
    if (p[a] < 0)
      return a;
    return p[a] = root(p[a]);
  }
  int size(int a) {
    assert(0 <= a && a < n);
    return -p[root(a)];
  }
  vector<vector<int>> groups() {
    vector<int> buf(n), size(n);
    for (int i = 0; i < n; i++) {
      buf[i] = root(i);
      size[buf[i]]++;
    }
    vector<vector<int>> res(n);
    for (int i = 0; i < n; i++)
      res[i].reserve(size[i]);
    for (int i = 0; i < n; i++)
      res[buf[i]].push_back(i);
    res.erase(remove_if(res.begin(), res.end(), [&](const vector<int> &v) { return v.empty(); }), res.end());
    return res;
  }
};

class DirectedGraph {
public:
  struct Edge {
    int to, cost;
  };
  int n;
  vector<vector<Edge>> g;

  DirectedGraph(int _n) : g(_n) {
    n = _n;
  }
  void add(int s, int t, int cost) {
    Edge e;
    e.to = t, e.cost = cost;
    g[s].push_back(e);
  }
  // O(V^3)
  vector<vector<int>> warshallfloyd() {
    vector<vector<int>> d(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
      d[i][i] = 0;
    for (int i = 0; i < n; i++)
      for (Edge &j : g[i])
        d[i][j.to] = min(d[i][j.to], j.cost);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
    return d;
  }
  // O(E+VlogV)
  vector<int> dijkstra(int s) {
    vector<int> d(n, INT_MAX);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, s));
    while (!que.empty()) {
      pair<int, int> p = que.top();
      que.pop();
      int v = p.second;
      if (d[v] < p.first)
        continue;
      for (auto e : g[v]) {
        if (d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          que.push(make_pair(d[e.to], e.to));
        }
      }
    }
    return d;
  }
  // O(V*E)
  vector<int> bellmanford(int s) {
    vector<int> d(n, INT_MAX);
    d[s] = 0;
    for (int _ = 0; _ < n; _++) {
      bool upd = false;
      for (int u = 0; u < n; u++)
        if (d[u] < INT_MAX)
          for (const auto &e : g[u]) {
            int v = e.to;
            if (d[v] > d[u] + e.cost)
              d[v] = d[u] + e.cost, upd = true;
          }
      if (!upd)
        return d;
    }
    queue<int> Q;
    for (int u = 0; u < n; u++)
      if (d[u] < INT_MAX)
        Q.emplace(u);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (const auto &e : g[u]) {
        int v = e.to;
        if (d[v] > INT_MIN && (d[u] == INT_MIN || d[v] > d[u] + e.cost))
          d[v] = INT_MIN, Q.emplace(v);
      }
    }
    return d;
  }
  // O(V+E)
  vector<int> topologicalSort() {
    vector<int> d, ind(n);
    for (int i = 0; i < n; i++)
      for (auto e : g[i])
        ind[e.to]++;
    queue<int> que;
    for (int i = 0; i < n; i++)
      if (ind[i] == 0)
        que.push(i);
    while (!que.empty()) {
      int now = que.front();
      d.push_back(now);
      que.pop();
      for (auto e : g[now]) {
        ind[e.to]--;
        if (ind[e.to] == 0)
          que.push(e.to);
      }
    }
    return d;
  }
};

class UndirectedGraph {
public:
  int n;
  vector<tuple<int, int, int>> g;
  UndirectedGraph(int _n) {
    n = _n;
  }
  void add(int u, int v, int c) {
    g.push_back({u, v, c});
  }
  // O(ElogV)
  vector<vector<int>> kruskal() {
    UnionFind uf(n);
    vector<vector<int>> res(n);
    sort(g.begin(), g.end(), [](auto &l, auto &r) { return get<2>(l) < get<2>(r); });
    D(g);
    for (auto &[a, b, cost] : g) {
      if (uf.merge(a, b)) {
        res[a].push_back(b);
        res[b].push_back(a);
      }
    }
    return res;
  }
};

class Range {
  int m_value;
  const int m_end;
  const int m_stride;

public:
  Range(int begin, int end, int stride) : m_value(begin), m_end(end), m_stride(stride) {}
  const int &value() const { return m_value; }
  Range begin() const { return *this; }
  int end() const { return m_end; }
  bool operator!=(const int &value) const {
    return m_stride > 0 ? m_value < value : m_value > value;
  }
  void operator++() { m_value += m_stride; }
  const int &operator*() const { return m_value; }
};
Range range(int end) {
  return {static_cast<int>(0), end, static_cast<int>(1)};
}
Range range(int begin, int end) {
  return {begin, end, static_cast<int>(1)};
}
Range range(int begin, int end, int stride) {
  return {begin, end, stride};
}

template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

vector<int> divisor(int n) {
  vector<int> head, tail;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      head.push_back(i);
      if (i * i != n)
        tail.push_back(n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return head;
}

vector<pair<int, int>> primeFactorize(int n) {
  vector<pair<int, int>> res;
  for (int a = 2; a * a <= n; ++a) {
    if (n % a != 0)
      continue;
    int ex = 0;
    while (n % a == 0) {
      ++ex;
      n /= a;
    }
    res.push_back({a, ex});
  }
  if (n != 1)
    res.push_back({n, 1});
  return res;
}

int dichotomy(int ng, int ok, function<bool(int)> discriminant) {
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    (discriminant(mid) ? ok : ng) = mid;
  }
  return ok;
}

template <class T>
pair<T, T> getLiner(pair<T, T> p0, pair<T, T> p1) {
  T a = (p0.second - p1.second) / (p0.first - p1.first);
  T b = p0.second - (p0.first * a);
  return make_pair(a, b);
}

template <class T>
vector<vector<T>> turnR(const vector<vector<T>> &s) {
  vector<vector<T>> res(s[0].size(), vector<T>(s.size()));
  for (int y = 0; y < s.size(); y++)
    for (int x = 0; x < s[0].size(); x++)
      res[x][s.size() - y - 1] = s[y][x];
  return res;
}

template <class T>
vector<vector<T>> turnL(const vector<vector<T>> &s) {
  vector<vector<T>> res(s[0].size(), vector<T>(s.size()));
  for (int y = 0; y < s.size(); y++)
    for (int x = 0; x < s[0].size(); x++)
      res[s[0].size() - x - 1][y] = s[y][x];
  return res;
}

void solve();

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  solve();
}

void solve() {}
