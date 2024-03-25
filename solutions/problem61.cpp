#include <bits/stdc++.h>

using namespace std;

bool isCyclic(int x, int y) {
  return (x % 100) == (y / 100);
}

int main(){
  vector<pair<int, int>> tri;
  vector<pair<int, int>> sqr;
  vector<pair<int, int>> pen;
  vector<pair<int, int>> hex;
  vector<pair<int, int>> hep;
  vector<pair<int, int>> oct;
  vector<pair<int, int>> allShapes;

  // triangle
  for(int i = 1; ; i++) {
    int r = i*(i+1) / 2;
    if (r >= 10000)
      break;
    else if (r >= 1000) {
      tri.push_back({3, r});
      allShapes.push_back({3, r});
    }
  }
  // square
  for(int i = 1; ; i++) {
    int r = i*i;
    if (r >= 10000)
      break;
    else if (r >= 1000){
      sqr.push_back({4, r});
      allShapes.push_back({4, r});
    }
  }
  // pentagonal
  for(int i = 1; ; i++) {
    int r = i*((3*i) - 1) / 2;
    if (r >= 10000)
      break;
    else if (r >= 1000){
      pen.push_back({5, r});
      allShapes.push_back({5, r});
    }
  }
  // hexagonal
  for(int i = 1; ; i++) {
    int r = i*((2*i) - 1);
    if (r >= 10000)
      break;
    else if (r >= 1000){
      hex.push_back({6, r});
      allShapes.push_back({6, r});    
    }
  }
  // heptagonal
  for(int i = 1; ; i++) {
    int r = i*((5*i) - 3) / 2;
    if (r >= 10000)
      break;
    else if (r >= 1000){
      hep.push_back({7, r});
      allShapes.push_back({7, r});
    }
  }
  // octagonal
  for(int i = 1; ; i++) {
    int r = i*((3*i) - 2);
    if (r >= 10000)
      break;
    else if (r >= 1000){
      oct.push_back({8, r});
      allShapes.push_back({8, r});    
    }
  }
 
  map<pair<int, int>, vector<pair<int, int>>> m;

  for(pair<int, int> x: allShapes) {
    vector<pair<int, int>> temp;
    m[x] = temp;
    for(pair<int, int> y: allShapes) {
      if (x.first != y.first && x.second != y.second){
        if (isCyclic(x.second, y.second))
          m[x].push_back(y);
      }
    }
  }

  for (auto a: tri) {
    for (auto b: m[a]) {
      for (auto c: m[b]) {
        for (auto d: m[c]) {
          for (auto e: m[d]) {
            for (auto f: m[e]) {
              if (isCyclic(f.second, a.second)) {
                set<int> s = {a.first, b.first, c.first, d.first, e.first, f.first};
                if (s.size() == 6) {
                  cout << a.second << "\t" << b.second << "\t" << c.second << "\t" << d.second << "\t" << e.second << "\t" << f.second << endl;
                  cout << a.first << "\t" << b.first << "\t" << c.first << "\t" << d.first << "\t" << e.first << "\t" << f.first << endl;
                  int sum = a.second + b.second + c.second + d.second + e.second + f.second;
                  cout << "Sum: " << sum << endl;
                  return 0;   
                }
              }
            }
          }
        }
      }
    }
  }

  return 0;

}
