/*
USER: zobayer
TASK: ANARC07C
ALGO: simulation
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

int g[1010][1010], n;
bool used[1000010];

int coordToInt(const int &i, const int &j){
  //cout << "n " << n << "i " << i << " j " << j << " ans " << i*n + j << endl;
  return i*n + j+1;
}

int main() {
  int caso = 1;
  while (scanf("%d", &n) && n){
    vector<int> good[n];

    int anillos = (n+1)/2;
    for (int k=0; k<anillos; ++k){
      for (int j=k; j<n-k; ++j){
        good[k].push_back(coordToInt(k, j));
        //cout << "1 added\n" << endl;
      }
      for (int i=k+1; i<=n-k-2; ++i){
        good[k].push_back(coordToInt(i, n-k-1));
        //cout << "2 added\n" << endl;
      }
      for (int j=n-k-1; j>=k; --j){
        good[k].push_back(coordToInt(n-k-1, j));
        //cout << "3 added\n" << endl;
      }
      for (int i=n-k-2; i>k; --i){
        good[k].push_back(coordToInt(i, k));
        //cout << "4 added\n" << endl;
      }
    }
    if (n % 2) good[anillos-1].erase(good[anillos-1].begin());

    //gen
    vector<int> seq[n]; //generar los anillos de la entrada aqui
    for (int i=0; i<=n*n; ++i) used[i] = false;
    bool impossible = false;
    for (int i=0; i<n; ++i){
      for (int j=0; j<n; ++j){
        scanf("%d", &g[i][j]);
        if (used[g[i][j]]) impossible = true;
        used[g[i][j]] = true;
      }
    }
    //generar anillos
    for (int k=0; k<anillos; ++k){
      for (int j=k; j<n-k; ++j){
        seq[k].push_back(g[k][j]);
        //cout << "1 added\n" << endl;
      }
      for (int i=k+1; i<=n-k-2; ++i){
        seq[k].push_back(g[i][n-k-1]);
        //cout << "2 added\n" << endl;
      }
      for (int j=n-k-1; j>=k; --j){
        seq[k].push_back(g[n-k-1][j]);
        //cout << "3 added\n" << endl;
      }
      for (int i=n-k-2; i>k; --i){
        seq[k].push_back(g[i][k]);
        //cout << "4 added\n" << endl;
      }
    }
    if (n % 2) seq[anillos-1].erase(seq[anillos-1].begin());

    if (!impossible){
      for (int k=0; k<anillos; ++k){
        rotate(seq[k].begin(), min_element(seq[k].begin(), seq[k].end()), seq[k].end());
        if (seq[k] != good[k]){
          impossible = true;
          break;
        }
      }
    }
    printf("%d. %s\n", caso++, impossible ? "NO" : "YES" );
  }
  return 0;
}
