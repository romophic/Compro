/*                 _        ____              */
/*   AC        U  /"\  u U /"___|     AC      */
/*              \/ _ \/  \| | u               */
/*        AC    / ___ \   | |/__    AC        */
/*             /_/   \_\   \____|             */
/* AC           \\    >>  _// \\         AC   */
/*             (__)  (__)(__)(__)             */
/*         github.com/romophic/Compro         */
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define rep(i, e) for (int i = 0; i < (int)(e); i++)
#define all(var) begin(var), end(var)
using namespace std;
constexpr int INF = 1LL << 60;
[[maybe_unused]] constexpr array<int, 4> dx({1, 0, 0, -1}), dy({0, 1, -1, 0});
template <class T>
bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }
template <class T>
bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
struct init {
  init() {
    cin.tie(0)->sync_with_stdio(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(16);
  }
} init;
signed main() {}
