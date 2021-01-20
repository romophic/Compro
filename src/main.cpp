//      _        ____   //
//  U  /"\  u U /"___|  //
//   \/ _ \/  \| | u    //
//   / ___ \   | |/__   //
//  /_/   \_\   \____|  //
//   \\    >>  _// \\   //
//  (__)  (__)(__)(__)  //
//  Compro by NULLCT   //

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")

//STL
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
#include <cstdint>
#include <cstdio>
#include <cstdlib>
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
#include <string>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

//Boost
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/irange.hpp>

using boost::irange;
using boost::multiprecision::cpp_int;
using namespace std;

#define int int64_t
#ifdef DEBUG
#define PRINT(var) cout << #var << ": " << __func__ << " " << __LINE__ << "\n  " << var << endl;
#else
#define PRINT(var) ;
#endif
#define REP(var, lim) for (int var = 0; var < (lim); var++)
#define FOR(var, begin, end) for (int var = (begin); var < (end); var++)
#define ALL(var) (var).begin(), (var).end()
#define LEN(var) (static_cast<int>(var.size()))

template <typename T>
ostream &operator<<(ostream &_ostr, const vector<T> &_v);
template <typename T>
ostream &operator<<(ostream &_ostr, const deque<T> &_v);
template <typename T>
ostream &operator<<(ostream &_ostr, const list<T> &_v);
template <typename T, typename Y>
ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v);
template <class... Ts>
ostream &operator<<(ostream &_ostr, const tuple<Ts...> &t);
template <typename T, typename Y>
ostream &operator<<(ostream &_ostr, const map<T, Y> &_v);
template <typename T>
ostream &operator<<(ostream &_ostr, const set<T> &_v);
template <typename T, typename Y>
ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v);
template <typename T>
ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v);

template <typename T>
ostream &operator<<(ostream &_ostr, const vector<T> &_v) {
  _ostr << "v";
  if (_v.empty()) {
    _ostr << "{ }";
    return _ostr;
  }
  _ostr << "{" << *_v.begin();
  for (auto itr = ++_v.begin(); itr != _v.end(); itr++) {
    _ostr << ", " << *itr;
  }
  _ostr << "}";
  return _ostr;
}
template <typename T>
ostream &operator<<(ostream &_ostr, const deque<T> &_v) {
  _ostr << "d";
  if (_v.empty()) {
    _ostr << "{ }";
    return _ostr;
  }
  _ostr << "{" << *_v.begin();
  for (auto itr = ++_v.begin(); itr != _v.end(); itr++) {
    _ostr << ", " << *itr;
  }
  _ostr << "}";
  return _ostr;
}
template <typename T>
ostream &operator<<(ostream &_ostr, const list<T> &_v) {
  _ostr << "l";
  if (_v.empty()) {
    _ostr << "{ }";
    return _ostr;
  }
  _ostr << "{" << *_v.begin();
  for (auto itr = ++_v.begin(); itr != _v.end(); itr++) {
    _ostr << ", " << *itr;
  }
  _ostr << "}";
  return _ostr;
}
template <typename T, typename Y>
ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v) {
  _ostr << "p(" << _v.first << ", " << _v.second << ")";
  return _ostr;
}
template <class... Ts>
ostream &operator<<(ostream &_ostr, const tuple<Ts...> &_v) {
  _ostr << "t[";
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
  _ostr << "]";
  return _ostr;
}
template <typename T, typename Y>
ostream &operator<<(ostream &_ostr, const map<T, Y> &_v) {
  _ostr << "m{";
  for (auto itr = _v.begin(); itr != _v.end(); itr++) {
    _ostr << "(" << itr->first << ", " << itr->second << ")";
    itr++;
    if (itr != _v.end())
      _ostr << ", ";
    itr--;
  }
  _ostr << "}";
  return _ostr;
}
template <typename T, typename Y>
ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v) {
  _ostr << "m{";
  for (auto itr = _v.begin(); itr != _v.end(); itr++) {
    _ostr << "(" << itr->first << ", " << itr->second << ")";
    itr++;
    if (itr != _v.end())
      _ostr << ", ";
    itr--;
  }
  _ostr << "}";
  return _ostr;
}
template <typename T>
ostream &operator<<(ostream &_ostr, const set<T> &_v) {
  _ostr << "s{";
  for (auto itr = _v.begin(); itr != _v.end(); itr++) {
    _ostr << *itr;
    ++itr;
    if (itr != _v.end())
      _ostr << ", ";
    itr--;
  }
  _ostr << "}";
  return _ostr;
}
template <typename T>
ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v) {
  _ostr << "us{";
  for (auto itr = _v.begin(); itr != _v.end(); itr++) {
    _ostr << *itr;
    ++itr;
    if (itr != _v.end())
      _ostr << ", ";
    itr--;
  }
  _ostr << "}";
  return _ostr;
}

template <int MOD>
class ModNum {
public:
  int num;

  constexpr ModNum(int v = 0) noexcept : num(v % MOD) {
    if (num < 0)
      num += MOD;
  }
  constexpr int getmod() { return MOD; }
  constexpr ModNum operator-() const noexcept { return num ? MOD - num : 0; }
  constexpr ModNum operator+(const ModNum &r) const noexcept {
    return ModNum(*this) += r;
  }
  constexpr ModNum operator-(const ModNum &r) const noexcept {
    return ModNum(*this) -= r;
  }
  constexpr ModNum operator*(const ModNum &r) const noexcept {
    return ModNum(*this) *= r;
  }
  constexpr ModNum operator/(const ModNum &r) const noexcept {
    return ModNum(*this) /= r;
  }
  constexpr ModNum &operator+=(const ModNum &r) noexcept {
    num += r.num;
    if (num >= MOD)
      num -= MOD;
    return *this;
  }
  constexpr ModNum &operator-=(const ModNum &r) noexcept {
    num -= r.num;
    if (num < 0)
      num += MOD;
    return *this;
  }
  constexpr ModNum &operator*=(const ModNum &r) noexcept {
    num = num * r.num % MOD;
    return *this;
  }
  constexpr ModNum &operator/=(const ModNum &r) noexcept {
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
  constexpr bool operator==(const ModNum &r) const noexcept {
    return this->num == r.num;
  }
  constexpr bool operator!=(const ModNum &r) const noexcept {
    return this->num != r.val;
  }
  friend constexpr ostream &operator<<(ostream &os, const ModNum<MOD> &x) noexcept {
    return os << x.num;
  }
  friend constexpr ModNum<MOD> modpow(const ModNum<MOD> &a, int n) noexcept {
    if (n == 0)
      return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1)
      t = t * a;
    return t;
  }
};

class UnionFind {
public:
  int n;
  vector<int> par;

  UnionFind() : n(0) {}
  UnionFind(int _n) : n(_n), par(_n, -1) {}
  int merge(int a, int b) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
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
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    return root(a) == root(b);
  }
  int root(int a) {
    assert(0 <= a && a < n);
    if (par[a] < 0)
      return a;
    return par[a] = root(par[a]);
  }
  int size(int a) {
    assert(0 <= a && a < n);
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

int kadanes(vector<int>::iterator _begin, const vector<int>::iterator _end) {
  int highestMax = 0, currentMax = 0;
  for (; _begin < _end; _begin++) {
    currentMax = max(*_begin, currentMax + *_begin);
    highestMax = max(highestMax, currentMax);
  }
  return highestMax;
}

int dichotomy(int ng, int ok, function<bool(int)> discriminant) {
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    (discriminant(mid) ? ok : ng) = mid;
  }
  return ok;
}

void execution();

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  execution();
  return 0;
}

//--------------------------------------------------------------
inline void execution() {}
