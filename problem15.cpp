#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<pair<int, int>, ll> m;

ll bfs(int x, int y, int N) {
  if (m[{ x, y }] != 0)
    return m[{x, y}];
  if (x == N)
    return 1;
  if (y == N)
    return 1;

  ll r = bfs(x+1, y, N) + bfs(x, y+1, N);
  m[{x, y}] = r;
  return r;
}

ll search(int N) {
  return bfs(0, 0, N);
}

int main() {
  int N = 20;
  cout << "Paths: " << search(N) << endl;
}
