/*                 _        ____              */
/*   AC        U  /"\  u U /"___|     AC      */
/*              \/ _ \/  \| | u               */
/*        AC    / ___ \   | |/__    AC        */
/*             /_/   \_\   \____|             */
/* AC           \\    >>  _// \\         AC   */
/*             (__)  (__)(__)(__)             */
/*          github.com/NULLCT/Compro          */
/*            Copyriaht (c) NULLCT            */
/*   Code is written at the bottom function   */

#pragma GCC optimize("O3")

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
#define ALL(var) ((var).begin()), ((var).end())
#ifdef DEBUG
#define D(var) cout << "(\e[34m" << #var << "\e[0m \e[2m@" << __LINE__ << "\e[0m): \e[36m\e[1m" << var << "\e[0m" << endl;
#else
#define D(var) ;
#endif

using namespace std;

constexpr int MOD = 1000000007;

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
template <class T>
ostream &operator<<(ostream &_ostr, const set<T> &_v);
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v);
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v);

template <class T>
void dumpFromRangeList(ostream &_ostr, const T &_v) {
  _ostr << "{";
  for (auto itr = _v.begin(); itr != _v.end(); itr++) {
    _ostr << *itr;
    if (next(itr) != _v.end())
      _ostr << ",";
  }
  _ostr << "}";
}
template <class T>
ostream &operator<<(ostream &_ostr, const vector<T> &_v) {
  _ostr << "v";
  dumpFromRangeList(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const deque<T> &_v) {
  _ostr << "d";
  dumpFromRangeList(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const list<T> &_v) {
  _ostr << "l";
  dumpFromRangeList(_ostr, _v);
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v) {
  _ostr << "p{" << _v.first << "," << _v.second << "}";
  return _ostr;
}
template <class... Ts>
ostream &operator<<(ostream &_ostr, const tuple<Ts...> &_v) {
  _ostr << "t{";
  bool first = true;
  apply([&_ostr, &first](auto &&... args) {
    auto print = [&](auto &&val) {
      if (!first)
        _ostr << ",";
      (_ostr << val);
      first = false;
    };
    (print(args), ...);
  },
        _v);
  _ostr << "}";
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const map<T, Y> &_v) {
  _ostr << "m";
  dumpFromRangeList(_ostr, _v);
  return _ostr;
}
template <class T, class Y>
ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v) {
  _ostr << "um";
  dumpFromRangeList(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const set<T> &_v) {
  _ostr << "s";
  dumpFromRangeList(_ostr, _v);
  return _ostr;
}
template <class T>
ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v) {
  _ostr << "us";
  dumpFromRangeList(_ostr, _v);
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

class ModNum {
public:
  int num;

  ModNum(int v = 0) : num(v % MOD) {
    if (num < 0)
      num += MOD;
  }
  int getmod() { return MOD; }
  ModNum operator-() const { return num ? MOD - num : 0; }
  ModNum operator+(const ModNum &r) {
    return ModNum(*this) += r;
  }
  ModNum operator-(const ModNum &r) {
    return ModNum(*this) -= r;
  }
  ModNum operator*(const ModNum &r) {
    return ModNum(*this) *= r;
  }
  ModNum operator/(const ModNum &r) {
    return ModNum(*this) /= r;
  }
  ModNum &operator+=(const ModNum &r) {
    num += r.num;
    if (num >= MOD)
      num -= MOD;
    return *this;
  }
  ModNum &operator-=(const ModNum &r) {
    num -= r.num;
    if (num < 0)
      num += MOD;
    return *this;
  }
  ModNum &operator*=(const ModNum &r) {
    num = num * r.num % MOD;
    return *this;
  }
  ModNum &operator/=(const ModNum &r) {
    int a = r.num, b = MOD, u = 1, v = 0;
    while (b) {
      int t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    num = num * u % MOD;
    if (num < 0)
      num += MOD;
    return *this;
  }
  bool operator==(const ModNum &r) {
    return this->num == r.num;
  }
  bool operator!=(const ModNum &r) {
    return this->num != r.num;
  }
  ModNum modpow(const ModNum &a, int n) {
    if (n == 0)
      return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1)
      t = t * a;
    return t;
  }
  friend ostream &operator<<(ostream &os, const ModNum &x) {
    return os << x.num;
  }
};

class SuccinctIndexableDictionary {
public:
  size_t length;
  size_t blocks;
  vector<unsigned> bit, sum;

  SuccinctIndexableDictionary() {
  }
  SuccinctIndexableDictionary(size_t _length) {
    length = _length;
    blocks = (length + 31) >> 5;
    bit.assign(blocks, 0U);
    sum.assign(blocks, 0U);
  }
  void set(int k) {
    bit[k >> 5] |= 1U << (k & 31);
  }
  void build() {
    sum[0] = 0U;
    for (int i = 1; i < blocks; i++) {
      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
    }
  }
  bool operator[](int k) const {
    return (bool((bit[k >> 5] >> (k & 31)) & 1));
  }
  int rank(int k) {
    return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
  }
  int rank(bool val, int k) {
    return (val ? rank(k) : k - rank(k));
  }
  int select(bool val, int k) {
    if (k < 0 || rank(val, length) <= k)
      return (-1);
    int low = 0, high = length;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      if (rank(val, mid) >= k + 1)
        high = mid;
      else
        low = mid;
    }
    return (high - 1);
  }
  int select(bool val, int i, int l) {
    return select(val, i + rank(val, l));
  }
};

template <class T, int MAXLOG>
struct WaveletMatrix {
  size_t length;
  SuccinctIndexableDictionary matrix[MAXLOG];
  int zs[MAXLOG];
  int buff1[MAXLOG], buff2[MAXLOG];

  int freq_dfs(int d, int l, int r, T val, T a, T b) {
    if (l == r)
      return 0;
    if (d == MAXLOG)
      return (a <= val && val < b) ? r - l : 0;
    T nv = 1ULL << (MAXLOG - d - 1) | val, nnv = ((1ULL << (MAXLOG - d - 1)) - 1) | nv;
    if (nnv < a || b <= val)
      return 0;
    if (a <= val && nnv < b)
      return r - l;
    int lc = matrix[d].rank(1, l), rc = matrix[d].rank(1, r);
    return freq_dfs(d + 1, l - lc, r - rc, val, a, b) +
           freq_dfs(d + 1, lc + zs[d], rc + zs[d], nv, a, b);
  }
  WaveletMatrix(vector<T> data) {
    length = data.size();
    vector<T> l(length), r(length);
    for (int depth = 0; depth < MAXLOG; depth++) {
      matrix[depth] = SuccinctIndexableDictionary(length + 1);
      int left = 0, right = 0;
      for (int i = 0; i < length; i++) {
        bool k = (data[i] >> (MAXLOG - depth - 1)) & 1;
        if (k)
          r[right++] = data[i], matrix[depth].set(i);
        else
          l[left++] = data[i];
      }
      zs[depth] = left;
      matrix[depth].build();
      swap(l, data);
      for (int i = 0; i < right; i++)
        data[left + i] = r[i];
    }
  }
  T access(int k) {
    int ret = 0;
    bool bit;
    for (int depth = 0; depth < MAXLOG; depth++) {
      bit = matrix[depth][k];
      ret = (ret << 1) | bit;
      k = matrix[depth].rank(bit, k) + zs[depth] * bit;
    }
    return (ret);
  }
  int rank(T val, int k) {
    int l = 0, r = k;
    for (int depth = 0; depth < MAXLOG; depth++) {
      buff1[depth] = l, buff2[depth] = r;
      bool bit = (val >> (MAXLOG - depth - 1)) & 1;
      l = matrix[depth].rank(bit, l) + zs[depth] * bit;
      r = matrix[depth].rank(bit, r) + zs[depth] * bit;
    }
    return (r - l);
  }
  int select(T val, int kth) {
    rank(val, length);
    for (int depth = MAXLOG - 1; depth >= 0; depth--) {
      bool bit = (val >> (MAXLOG - depth - 1)) & 1;
      kth = matrix[depth].select(bit, kth, buff1[depth]);
      if (kth >= buff2[depth] || kth < 0)
        return (-1);
      kth -= buff1[depth];
    }
    return (kth);
  }
  int select(T val, int k, int l) {
    return select(val, k + rank(val, l));
  }
  int quantile(int left, int right, int kth) {
    if (right - left <= kth || kth < 0)
      return (-1);
    T ret = 0;
    for (int depth = 0; depth < MAXLOG; depth++) {
      int l = matrix[depth].rank(1, left);
      int r = matrix[depth].rank(1, right);
      if (r - l > kth) {
        left = l + zs[depth];
        right = r + zs[depth];
        ret |= 1ULL << (MAXLOG - depth - 1);
      } else {
        kth -= r - l;
        left -= l;
        right -= r;
      }
    }
    return ret;
  }
  int rangefreq(int left, int right, T lower, T upper) {
    return freq_dfs(0, left, right, 0, lower, upper);
  }
};

template <class T>
class SegmentTree {
public:
  int sz;
  vector<T> seg;
  const function<T(T, T)> f;
  const T M1;

  SegmentTree(int n, const function<T(T, T)> f, const T &M1) : f(f), M1(M1) {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    seg.assign(2 * sz, M1);
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
  vector<int> par;

  UnionFind() : n(0) {}
  UnionFind(int _n) : n(_n), par(_n, -1) {}
  int merge(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y)
      return x;
    if (-par[x] < -par[y])
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return x;
  }
  bool isSame(int a, int b) {
    return root(a) == root(b);
  }
  int root(int a) {
    if (par[a] < 0)
      return a;
    return par[a] = root(par[a]);
  }
  int size(int a) {
    return -par[root(a)];
  }
  vector<vector<int>> groups() {
    vector<int> leader_buf(n), group_size(n);
    for (int i = 0; i < n; i++) {
      leader_buf[i] = root(i);
      group_size[leader_buf[i]]++;
    }
    vector<vector<int>> result(n);
    for (int i = 0; i < n; i++)
      result[i].reserve(group_size[i]);
    for (int i = 0; i < n; i++)
      result[leader_buf[i]].push_back(i);
    result.erase(remove_if(result.begin(), result.end(), [&](const vector<int> &v) { return v.empty(); }), result.end());
    return result;
  }
};

class DirectedGraph {
public:
  struct Edge {
    int to, cost;
  };
  int n;
  vector<int> d;
  vector<vector<Edge>> g;

  DirectedGraph(int _n) : g(_n), d(_n) {
    n = _n;
  }
  void add_edge(int s, int t, int cost) {
    Edge e;
    e.to = t, e.cost = cost;
    g[s].push_back(e);
  }
  void dijkstra(int s) {
    fill(d.begin(), d.end(), INT_MAX);
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
  }
};

class UndirectedGraph {
public:
  int n;
  vector<pair<int, int>> ev;
  vector<pair<int, int>> cv;

  UndirectedGraph(int _n) {
    n = _n;
  }
  void add_edge(int u, int v, int c) {
    int eid;
    eid = ev.size();
    ev.push_back(make_pair(u, v));
    cv.push_back(make_pair(c, eid));
  }
  int calc_valonly(void) {
    vector<pair<int, int>> tmp;
    return calc(tmp);
  }
  int calc(vector<pair<int, int>> &used_edge) {
    UnionFind uf(n);
    int res;
    int c;
    int eid, u, v;
    res = 0;
    sort(cv.begin(), cv.end());
    for (pair<int, int> p : cv) {
      c = p.first;
      eid = p.second;
      u = ev[eid].first;
      v = ev[eid].second;
      if (uf.root(u) != uf.root(v)) {
        res += c;
        uf.merge(u, v);
        used_edge.push_back(pair<int, int>(u, v));
      } else if (c < 0)
        res += c;
    }
    if (uf.groups().size() != 1)
      return -1;
    return res;
  }
};

class Range {
  struct Cnt {
    int n;
    int add = 1;
    int operator*() { return n; }
    bool operator!=(const Cnt &_n) { return n < _n.n; }
    void operator++() { n += add; }
  };
  Cnt st, ed;

public:
  Range(const int &_ed) : st({0}), ed({_ed}) {}
  Range(const int &_st, const int &_ed) : st({_st}), ed({_ed}) {}
  Range(const int &_st, const int &_ed, const int &_add) : st({_st, _add}), ed({_ed, _add}) {}
  Cnt &begin() { return st; }
  Cnt &end() { return ed; }
};

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

vector<int> divisor(const int _n) {
  vector<int> head, tail;
  for (int i = 1; i * i <= _n; i++) {
    if (_n % i == 0) {
      head.push_back(i);
      if (i * i != _n)
        tail.push_back(_n / i);
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

void execution();

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  execution();
}

void execution() {}
