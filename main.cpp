//////////////////////////
//      _        ____   //
//  U  /"\  u U /"___|  //
//   \/ _ \/  \| | u    //
//   / ___ \   | |/__   //
//  /_/   \_\   \____|  //
//   \\    >>  _// \\   //
//  (__)  (__)(__)(__)  //
//  Compro by NULL_CT©  //
//////////////////////////
// STL libs
#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <chrono>
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

#define REP(I, LIM) for (int I = 0; I < (LIM); I++)
#define ALL(LIST) (LIST.begin()), (LIST.end())

using namespace std;
using boost::irange;
using boost::multiprecision::cpp_int;

typedef long long ll;

const int MOD = 1000000007;

vector<ll> divisor(ll &_n) {
  vector<ll> head, tail;
  for (long i = 1; i * i <= _n; i++) {
    if (_n % i == 0) {
      head.push_back(i);
      if (i * i != _n)
        tail.push_back(_n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return head;
}

ll kadanes(vector<ll> &_ls) {
  ll highestMax = 0, currentMax = 0, length = _ls.size();
  for (ll i = 0; i < length; i++) {
    currentMax = max(_ls[i], currentMax + _ls[i]);
    highestMax = max(highestMax, currentMax);
  }
  return highestMax;
}

class UnionFind {
public:
  vector<ll> par;

  UnionFind(ll N) : par(N) {
    for (ll i = 0; i < N; i++)
      par[i] = i;
  }
  ll root(ll x) {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }
  void unite(ll x, ll y) {
    ll rx = root(x);
    ll ry = root(y);
    if (rx == ry)
      return;
    par[rx] = ry;
  }
  bool same(ll x, ll y) {
    ll rx = root(x);
    ll ry = root(y);
    return rx == ry;
  }
};

void execution();

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  // cout<<fixed<<setprecision(20);

  execution();
  return 0;
}

/*----------------------------*/

void execution(){

}

