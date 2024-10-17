#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define uint unsigned long long
#define int128 __int128
#define uint128 unsigned __int128
#define rep(i, e) for (int i = 0; i < (int)(e); i++)
#define rrep(i, b, e) for (int i = (b); i < (int)(e), i++)
#define all(var) begin(var), end(var)
#define D(e) cerr << "@" << __LINE__ << ": " << e << endl;
#define DD(e)                                                                                                                                \
  for (int i = 0; auto &&j : e)                                                                                                                \
    cerr << "@" << __LINE__ << "[" << i++ << "]: " << j << endl;
using namespace std;
constexpr int INF = 1LL << 60;
constexpr array<int, 4> dx({1, 0, 0, -1}), dy({0, 1, -1, 0});
template <class T> ostream &operator<<(ostream &_ostr, const vector<T> &_v);
template <class T> ostream &operator<<(ostream &_ostr, const deque<T> &_v);
template <class T> ostream &operator<<(ostream &_ostr, const list<T> &_v);
template <class T, class Y> ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v);
template <class... Ts> ostream &operator<<(ostream &_ostr, const tuple<Ts...> &t);
template <class T, class Y> ostream &operator<<(ostream &_ostr, const map<T, Y> &_v);
template <class T, class Y> ostream &operator<<(ostream &_ostr, const multimap<T, Y> &_v);
template <class T, class Y> ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v);
template <class T, class Y> ostream &operator<<(ostream &_ostr, const unordered_multimap<T, Y> &_v);
template <class T> ostream &operator<<(ostream &_ostr, const set<T> &_v);
template <class T> ostream &operator<<(ostream &_ostr, const multiset<T> &_v);
template <class T> ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v);
template <class T> ostream &operator<<(ostream &_ostr, const unordered_multiset<T> &_v);
template <class T> ostream &_orange(ostream &_ostr, const T &_v) {
  _ostr << "[";
  for (bool tr = true; auto &&i : _v)
    _ostr << (tr ? tr = false, "" : ", ") << i;
  return _ostr << "]";
}
template <class T> ostream &operator<<(ostream &_ostr, const vector<T> &_v) { return _orange(_ostr, _v); }
template <class T> ostream &operator<<(ostream &_ostr, const deque<T> &_v) { return _orange(_ostr, _v); }
template <class T> ostream &operator<<(ostream &_ostr, const list<T> &_v) { return _orange(_ostr, _v); }
template <class T, class Y> ostream &operator<<(ostream &_ostr, const pair<T, Y> &_v) {
  return _ostr << "(" << _v.first << ", " << _v.second << ")";
}
template <class... Ts> ostream &operator<<(ostream &_ostr, const tuple<Ts...> &_v) {
  bool tr = true;
  _ostr << "(";
  apply(
      [&_ostr, &tr](auto &&...args) {
        auto print = [&](auto &&val) {
          if (!tr)
            _ostr << ", ";
          _ostr << val;
          tr = false;
        };
        (print(args), ...);
      },
      _v);
  return _ostr << ")";
}
template <class T, class Y> ostream &operator<<(ostream &_ostr, const map<T, Y> &_v) { return _orange(_ostr, _v); }
template <class T, class Y> ostream &operator<<(ostream &_ostr, const multimap<T, Y> &_v) { return _orange(_ostr, _v); }
template <class T, class Y> ostream &operator<<(ostream &_ostr, const unordered_map<T, Y> &_v) { return _orange(_ostr, _v); }
template <class T> ostream &operator<<(ostream &_ostr, const set<T> &_v) { return _orange(_ostr, _v); }
template <class T> ostream &operator<<(ostream &_ostr, const multiset<T> &_v) { return _orange(_ostr, _v); }
template <class T> ostream &operator<<(ostream &_ostr, const unordered_set<T> &_v) { return _orange(_ostr, _v); }
template <class T> ostream &operator<<(ostream &_ostr, const unordered_multiset<T> &_v) { return _orange(_ostr, _v); }
template <class T> istream &operator>>(istream &_istr, vector<T> &_v);
template <class T> istream &operator>>(istream &_istr, deque<T> &_v);
template <class T, class Y> istream &operator>>(istream &_istr, pair<T, Y> &_v);
template <class... Ts> istream &operator>>(istream &_istr, tuple<Ts...> &_v);
template <class T> istream &_irange(istream &_istr, T &_v) {
  for (auto &i : _v)
    _istr >> i;
  return _istr;
}
template <class T> istream &operator>>(istream &_istr, vector<T> &_v) { return _irange(_istr, _v); }
template <class T> istream &operator>>(istream &_istr, deque<T> &_v) { return _irange(_istr, _v); }
template <class T, class Y> istream &operator>>(istream &_istr, pair<T, Y> &_v) { return _istr >> _v.first >> _v.second; }
template <class... Ts> istream &operator>>(istream &_istr, tuple<Ts...> &_v) {
  apply([&_istr](auto &&...args) { ((_istr >> args), ...); }, _v);
  return _istr;
}
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <class T> bool chmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
struct init {
  init() {
    cin.tie(0)->sync_with_stdio(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(16);
  }
} init;
signed main() {}
