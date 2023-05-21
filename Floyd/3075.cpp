#include <iostream>
#include <cstring>
#include <vector>

#define INF 21474836480000 // 문제가 너무 더럽다.
using namespace std;
int T;
bool flag = true;
int n, p, q;
int a, b, c, residx;
long long int res = INF;
long long int dist[101][101];
vector<int> people;

void init(){ // 초기화
    res = INF;
    residx = 0;
    people.clear();
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
}

void Floyd(){
    for(int k=1; k<=p; k++){
        for(int i=1; i<=p; i++){
            for(int j=1; j<=p; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j] && dist[k][j] != INF & dist[i][k] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        cin >> n >> p >> q; // 미팅하는 사람, 은하의 수, 길의 개수
        init();
        for(int i=0; i<n; i++){
            cin >> a;
            people.push_back(a);
        }

        for(int i=0; i<q; i++){
            cin >> a >> b >> c;
            if(dist[a][b] > c){
                dist[a][b] = c;
            }
            if(dist[b][a] > c){
                dist[b][a] = c;
            }
        }

        Floyd();

        for(int i=1; i<=p; i++){
            long long int sum = 0;
            for(int j=0; j<people.size(); j++){
                if(dist[people[j]][i] >= INF) { // 한번이라도 외딴섬이 있다 -> 아웃
                    flag = false;
                    break;
                }
                sum += dist[people[j]][i] * dist[people[j]][i];
            }
            if(!flag){ // 외딴섬 감지
                flag = true;
                continue;
            }
            if(res > sum){ // 정답 갱신
                res = sum;
                residx = i;
            }
        }
        cout << residx << " " << res << '\n';
    }
    return 0;
}