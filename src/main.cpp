//////////////////////////
//      _        ____   //
//  U  /"\  u U /"___|  //
//   \/ _ \/  \| | u    //
//   / ___ \   | |/__   //
//  /_/   \_\   \____|  //
//   \\    >>  _// \\   //
//  (__)  (__)(__)(__)  //
//  Compro by NULLCT   //
//////////////////////////
// STL libs
#include <algorithm>
#include <array>
#include <bitset>
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

// Boost
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/irange.hpp>

#define ALL(LIST) (LIST.begin()), (LIST.end())

using namespace std;
using boost::irange;
using boost::multiprecision::cpp_int;

constexpr int64_t MOD = 1000000007;

class ModNum {
public:
  int64_t num;

  ModNum(long long x = 0) : num((x % MOD + MOD) % MOD) {}

  ModNum operator-() const { return ModNum(-num); }
  ModNum &operator+=(const ModNum &a) {
    if ((num += a.num) >= MOD)
      num -= MOD;
    return *this;
  }
  ModNum &operator-=(const ModNum &a) {
    if ((num += MOD - a.num) >= MOD)
      num -= MOD;
    return *this;
  }
  ModNum &operator*=(const ModNum &a) {
    (num *= a.num) %= MOD;
    return *this;
  }
  ModNum &operator/=(const ModNum &a) { return (*this) *= a.inv(); }

  ModNum operator+(const ModNum &a) const {
    ModNum res(*this);
    return res += a;
  }
  ModNum operator-(const ModNum &a) const {
    ModNum res(*this);
    return res -= a;
  }
  ModNum operator*(const ModNum &a) const {
    ModNum res(*this);
    return res *= a;
  }
  ModNum operator/(const ModNum &a) const {
    ModNum res(*this);
    return res /= a;
  }

  ModNum pow(int64_t t) const {
    if (!t)
      return 1;
    ModNum a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }
  ModNum inv() const { return pow(MOD - 2); }

  friend ostream &operator<<(ostream &os, const ModNum &m) {
    os << m.num;
    return os;
  }
};

class UnionFind {
public:
  vector<int64_t> par;

  UnionFind(int64_t N) : par(N) {
    for (int64_t i = 0; i < N; i++)
      par[i] = i;
  }
  int64_t root(int64_t x) {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }
  void unite(int64_t x, int64_t y) {
    int64_t rx = root(x);
    int64_t ry = root(y);
    if (rx == ry)
      return;
    par[rx] = ry;
  }
  bool isSame(int64_t x, int64_t y) {
    int64_t rx = root(x);
    int64_t ry = root(y);
    return rx == ry;
  }
};

vector<int64_t> divisor(const int64_t &_n) {
  vector<int64_t> head, tail;
  for (int64_t i = 1; i * i <= _n; i++) {
    if (_n % i == 0) {
      head.push_back(i);
      if (i * i != _n)
        tail.push_back(_n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return head;
}

int64_t kadanes(const vector<int64_t> &_ls) {
  int64_t highestMax = 0, currentMax = 0, length = _ls.size();
  for (int64_t i = 0; i < length; i++) {
    currentMax = max(_ls[i], currentMax + _ls[i]);
    highestMax = max(highestMax, currentMax);
  }
  return highestMax;
}

void execution();

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  execution();
  return 0;
}

#define int int64_t
//--------------------------------------------------------------
inline void execution() {}
