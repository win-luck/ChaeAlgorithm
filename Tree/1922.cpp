#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct KS {int from, to, val;}; // 간선의 출발지, 도착지, 가중치
vector<KS> Edges;
int parent[1001];
int N, M;

bool comp(KS k1, KS k2){
    return k1.val < k2.val;
} // 오름차순 정렬 조건

int find(int num){
    if(num == parent[num])
        return num;

    return parent[num] = find(parent[num]);
} // 유니온 파인드

int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    for(int i=0; i<M; i++){
        KS ks;
        cin >> ks.from >> ks.to >> ks.val;
        Edges.push_back(ks);
    }

    sort(Edges.begin(), Edges.end(), comp);

    int result = 0;
    for(int i=0; i<M; i++){
        int f = find(Edges[i].from);
        int t = find(Edges[i].to);

        if(f != t){
            parent[f] = t;
            result += Edges[i].val; // 모든 집을 연결하면서 간선들의 가중치의 합이 최소인 경우를 계산
        }
    }

    cout << result << endl;
    return 0;
}