#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define INF 100000
using namespace std;
int n;
string a, temp, b;
vector<pair<char, char> > v;
int dist[123][123];

int main(){

    for(int i=0; i<=122; i++){
        for(int j=0; j<=122; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    } // 최초 간선 초기화

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> temp >> b;
        dist[a[0] - '0'][b[0] - '0'] = 1;
    } // 명제 적용

    for(int k=0; k<=122; k++){
        for(int i=0; i<=122; i++){
            for(int j=0; j<=122; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    } // 플로이드 워셜로 명제 확장

    for(int i=0; i<=122; i++){
        for(int j=0; j<=122; j++){
            if(i != j && dist[i][j] != 0 && dist[i][j] < INF){ // 참인 명제들 담기
                v.push_back(make_pair(i + '0', j + '0'));
            }
        }
    }

    cout << v.size() << '\n'; // 정렬 후 출력
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " => " << v[i].second << '\n';
    }
    return 0;
}