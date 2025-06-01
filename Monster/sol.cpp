#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const char direction[4] = {'R', 'L', 'D', 'U'};
pair<int, int> trace[1005][1005];
char moveStep[1005][1005];
vector<string> a;
int n, m;
queue<pair<int, int>> myqueue;
pair<int, int> start;

void printResult(int x, int y) {
  cout << "YES" << endl;
  vector<char> ans;
  while (x != start.first || y != start.second) {
    ans.push_back(moveStep[x][y]);
    pair<int, int> prev = trace[x][y];
    x = prev.first;
    y = prev.second;
  }
  cout << (int) ans.size() << endl;
  for (int i = (int) ans.size() - 1; i >= 0; i--) {
    cout << ans[i];
  }
}

int main () {
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'M') {
        myqueue.push(make_pair(i, j));
      }
      else if (a[i][j] == 'A') {
        start = make_pair(i, j);
      }
    }
  }
  myqueue.push(start);
  while (!myqueue.empty()) {
    pair<int, int> element = myqueue.front();
    myqueue.pop();
    int x = element.first;
    int y = element.second;
    if ((x == 0 || x == n - 1 || y == 0 || y == m - 1) && a[x][y] == 'A') {
      printResult(x, y);
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int nextx = x + dx[i];
      int nexty = y + dy[i];
      if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && a[nextx][nexty] == '.') {
        a[nextx][nexty] = a[x][y];
        myqueue.push(make_pair(nextx, nexty));
        if (a[x][y] == 'A') {
          trace[nextx][nexty] = make_pair(x, y);
          moveStep[nextx][nexty] = direction[i];
        }
      }
    }
  }
  cout << "NO";
  return 0;
}
