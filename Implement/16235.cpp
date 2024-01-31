#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, k; 
vector<int> trees[11][11];
int s2d2[11][11];
int map[11][11];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {0, -1, 1, 1, -1, -1, 1, 0};

void springsummer(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(trees[i][j].size()){ // spring & summer
                int newe = 0;
                vector<int> tmp;
                sort(trees[i][j].begin(), trees[i][j].end());

                for(int a=0; a<trees[i][j].size(); a++){
                    int now = trees[i][j][a];
                    if(now > map[i][j]){
                        newe += now/2;
                    } else {
                        map[i][j] -= now;
                        tmp.push_back(now+1);
                    }
                }

                trees[i][j].clear();
                for(int a=0; a<tmp.size(); a++){
                    trees[i][j].push_back(tmp[a]);
                }
                map[i][j] += newe;
            }
        }
    }
}

void fallwinter(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int a=0; a<trees[i][j].size(); a++){ // fall
                if(trees[i][j][a] % 5 == 0){
                    for(int p=0; p<8; p++){
                        int nx = i + dx[p];
                        int ny = j + dy[p];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        trees[nx][ny].push_back(1);
                    }
                }
            }
            map[i][j] += s2d2[i][j]; // winter
        }
    }
}

void input(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s2d2[i][j];
            map[i][j] = 5;
        }
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        trees[a-1][b-1].push_back(c);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    while(k--){
        springsummer();
        fallwinter();
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum += trees[i][j].size();
        }
    }
    cout << sum;
    return 0;
}
