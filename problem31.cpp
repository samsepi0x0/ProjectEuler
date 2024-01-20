#include <bits/stdc++.h>

using namespace std;

int main(){
  int target = 200;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
  vector<vector<int>> ways;
  for(int i = 0; i <= target; i++){
    vector<int> way(8, 1);
    ways.push_back(way);
  }
  for(int i = 0; i <= target; i++) {
    for(int j = 1; j < 8; j++) {
      ways[i][j] = ways[i][j-1];
      if (coins[j] <= i){
        ways[i][j] = ways[i][j] + ways[i - coins[j]][j];
      }
    }
  }
  cout << "Ways: " << ways[target][7] << endl;  
  return 0;
  
}
