#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
const int INF = INT_MAX;
#define V 4

typedef vector<int> Path;

int graphSize;
int minCost = INF;
Path optimalPath;

void tspBnB(int graph[][V], Path& path, int level, int cost) {
  if (level == graphSize) {
    if (graph[path[level - 1]][path[0]] != 0) {
      int totalCost = cost + graph[path[level - 1]][path[0]];
      minCost = min(minCost, totalCost);
      if (totalCost == minCost) {
        optimalPath = path;
      }
    }
  } else {
    for (int i = 0; i < graphSize; i++) {
      if (find(path.begin(), path.begin() + level, i) == path.begin() + level) {
        path[level] = i;
        if (cost + graph[path[level - 1]][i] < minCost) {
          tspBnB(graph, path, level + 1, cost + graph[path[level - 1]][i]);
        }
      }
    }
  }
}

void printPath(){
  cout << "Optimal Path: ";
  for (int i = 0; i < graphSize; i++) {
    cout << optimalPath[i] << " ";
  }
  cout << 0 << endl;
  cout << "Minimum Cost: " << minCost << endl;
}

int main() {
  int graph[][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
  };

  graphSize = V;
  Path path(graphSize);
  path[0] = 0;

  tspBnB(graph, path, 1, 0);
  printPath();
  return 0;
}
