/*                 _        ____              */
/*   AC        U  /"\  u U /"___|     AC      */
/*              \/ _ \/  \| | u               */
/*        AC    / ___ \   | |/__    AC        */
/*             /_/   \_\   \____|             */
/* AC           \\    >>  _// \\         AC   */
/*             (__)  (__)(__)(__)             */
/*         github.com/romophic/Compro         */
#include <bits/stdc++.h>
#define int long long
#define double long double
#define rep(i, e) for (int i = 0; i < (e); i++)
#define ALL(var) begin(var), end(var)
using namespace std;
constexpr int INF = 1LL << 60;
constexpr int MOD = 998244353;
template <class T>
bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }
template <class T>
bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
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
    while (n % a == 0)
      ++ex, n /= a;
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
int mop(int a, int n, int mod = LLONG_MAX) {
  int res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
template <int Mod = MOD>
class ModInt {
public:
  int n;
  constexpr ModInt(const int x = 0) noexcept : n(x % Mod) {}
  constexpr int &value() noexcept { return n; }
  constexpr ModInt operator+(const ModInt rhs) const noexcept { return ModInt(*this) += rhs; }
  constexpr ModInt operator-(const ModInt rhs) const noexcept { return ModInt(*this) -= rhs; }
  constexpr ModInt operator*(const ModInt rhs) const noexcept { return ModInt(*this) *= rhs; }
  constexpr ModInt operator/(const ModInt rhs) const noexcept { return ModInt(*this) /= rhs; }
  constexpr ModInt &operator+=(const ModInt rhs) noexcept {
    n += rhs.n;
    if (n >= Mod)
      n -= Mod;
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt rhs) noexcept {
    if (n < rhs.n)
      n += Mod;
    n -= rhs.n;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt rhs) noexcept {
    n = n * rhs.n % Mod;
    return *this;
  }
  constexpr ModInt &operator/=(ModInt rhs) noexcept {
    int exp = Mod - 2;
    while (exp) {
      if (exp % 2)
        *this *= rhs;
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};
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
  void set(int k, const T &x) { seg[k + sz] = x; }
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
  T operator[](const int &k) const { return seg[k + sz]; }
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
  bool merge(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y)
      return false;
    if (-p[x] < -p[y])
      swap(x, y);
    p[x] += p[y], p[y] = x;
    return true;
  }
  bool isSame(int a, int b) { return root(a) == root(b); }
  int root(int a) {
    if (p[a] < 0)
      return a;
    return p[a] = root(p[a]);
  }
  int size(int a) { return -p[root(a)]; }
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
class RollingHash {
public:
  vector<unsigned> hashed, power;
  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long)a * b;
    unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(MOD));
    return m;
  }
  RollingHash(const string &s, unsigned base = 10007) {
    int sz = (int)s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for (int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if (hashed[i + 1] >= MOD)
        hashed[i + 1] -= MOD;
    }
  }
  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + MOD - mul(hashed[l], power[r - l]);
    if (ret >= MOD)
      ret -= MOD;
    return ret;
  }
  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if (ret >= MOD)
      ret -= MOD;
    return ret;
  }
  int LCP(const RollingHash &b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while (high - low > 1) {
      int mid = (low + high) / 2;
      if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
        low = mid;
      else
        high = mid;
    }
    return (low);
  }
};
template <class Type>
class WeightedUnionFind {
public:
  WeightedUnionFind() = default;
  /// @brief 重み付き Union-Find 木を構築します。
  /// @param n 要素数
  explicit WeightedUnionFind(size_t n)
      : m_parentsOrSize(n, -1), m_diffWeights(n) {}
  /// @brief 頂点 i の root のインデックスを返します。
  /// @param i 調べる頂点のインデックス
  /// @return 頂点 i の root のインデックス
  int find(int i) {
    if (m_parentsOrSize[i] < 0)
      return i;
    const int root = find(m_parentsOrSize[i]);
    m_diffWeights[i] += m_diffWeights[m_parentsOrSize[i]];
    // 経路圧縮
    return (m_parentsOrSize[i] = root);
  }
  /// @brief a のグループと b のグループを統合します。
  /// @param a 一方のインデックス
  /// @param b 他方のインデックス
  /// @param w (b の重み) - (a の重み)
  void merge(int a, int b, Type w) {
    w += weight(a);
    w -= weight(b);
    a = find(a);
    b = find(b);
    if (a != b) {
      // union by size (小さいほうが子になる）
      if (-m_parentsOrSize[a] < -m_parentsOrSize[b]) {
        swap(a, b);
        w = -w;
      }
      m_parentsOrSize[a] += m_parentsOrSize[b];
      m_parentsOrSize[b] = a;
      m_diffWeights[b] = w;
    }
  }
  /// @brief (b の重み) - (a の重み) を返します。
  /// @param a 一方のインデックス
  /// @param b 他方のインデックス
  /// @remark a と b が同じグループに属さない場合の結果は不定です。
  /// @return (b の重み) - (a の重み)
  Type diff(int a, int b) {
    return (weight(b) - weight(a));
  }
  /// @brief a と b が同じグループに属すかを返します。
  /// @param a 一方のインデックス
  /// @param b 他方のインデックス
  /// @return a と b が同じグループに属す場合 true, それ以外の場合は false
  bool connected(int a, int b) {
    return (find(a) == find(b));
  }
  /// @brief i が属するグループの要素数を返します。
  /// @param i インデックス
  /// @return i が属するグループの要素数
  int size(int i) {
    return -m_parentsOrSize[find(i)];
  }

private:
  // m_parentsOrSize[i] は i の 親,
  // ただし root の場合は (-1 * そのグループに属する要素数)
  vector<int> m_parentsOrSize;
  // 重み
  vector<Type> m_diffWeights;
  Type weight(int i) {
    find(i); // 経路圧縮
    return m_diffWeights[i];
  }
};
class DirectedGraph {
public:
  struct Edge {
    int to, cost;
  };
  const int N;
  vector<vector<Edge>> g;
  DirectedGraph(int _n) : g(_n), N(_n) {}
  void add(int s, int t, int cost) {
    g[s].push_back({t, cost});
  }
  struct warshallfloyd_return {
    vector<vector<int>> dist, next;
  };
  // O(V^3)
  warshallfloyd_return warshallfloyd() {
    vector<vector<int>> dist(N, vector<int>(N, INF)), next(N, vector<int>(N, INF));
    for (int i = 0; i < N; i++)
      dist[i][i] = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        next[i][j] = j;
    for (int i = 0; i < N; i++)
      for (auto &j : g[i])
        chmin(dist[i][j.to], j.cost);
    for (int k = 0; k < N; k++)
      for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
          if (chmin(dist[i][j], dist[i][k] + dist[k][j]))
            next[i][j] = next[i][k];
    return {dist, next};
  }
  // O(E+VlogV)
  vector<int> dijkstra(int s) {
    vector<int> d(N, INF);
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
  struct bellmanford_return {
    vector<int> path, distances;
    bool hascycle;
  };
  // O(V*E)
  // https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/bellman-ford
  bellmanford_return bellmanford_SPFA(int st, int ed) {
    vector<int> counts(g.size()), distances(g.size(), INF), path;
    vector<bool> inqueue(g.size());
    queue<int> q;
    vector<int> p(g.size(), -1);
    distances[st] = 0;
    q.push(st);
    inqueue[st] = true;
    while (!q.empty()) {
      const int from = q.front();
      q.pop();
      inqueue[from] = false;
      for (const auto &edge : g[from]) {
        const long long d = (distances[from] + edge.cost);
        if (d < distances[edge.to]) {
          distances[edge.to] = d;
          p[edge.to] = from;
          if (!inqueue[edge.to]) {
            q.push(edge.to);
            inqueue[edge.to] = true;
            ++counts[edge.to];
            if (g.size() < counts[edge.to])
              return {vector<int>(), vector<int>(), true};
          }
        }
      }
    }
    if (distances[ed] != INF) {
      for (int i = ed; i != -1; i = p[i])
        path.push_back(i);
      reverse(path.begin(), path.end());
    }
    return {path, distances, false};
  }
  // O(V+E)
  vector<int> topologicalSort() {
    vector<int> d, ind(N);
    for (int i = 0; i < N; i++)
      for (auto e : g[i])
        ind[e.to]++;
    queue<int> que;
    for (int i = 0; i < N; i++)
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
  UndirectedGraph(int _n) : n(_n) {}
  void add(int u, int v, int c) {
    g.push_back({u, v, c});
  }
  // O(ElogV)
  vector<vector<int>> kruskal() {
    UnionFind uf(n);
    vector<vector<int>> res(n);
    sort(g.begin(), g.end(), [](auto &l, auto &r) { return get<2>(l) < get<2>(r); });
    for (auto &[a, b, cost] : g) {
      if (uf.merge(a, b)) {
        res[a].push_back(b);
        res[b].push_back(a);
      }
    }
    return res;
  }
};
struct init {
  init() {
    cin.tie(0)->sync_with_stdio(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(16);
  }
} init;
signed main() {
}
