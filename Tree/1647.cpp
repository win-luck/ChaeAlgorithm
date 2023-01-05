#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct KS {int from, to, val;}; // 간선의 출발지, 도착지, 가중치
vector<KS> Edges;
int parent[100001];
int result;

bool comp(KS k1, KS k2){
    return k1.val < k2.val;
} // 오름차순 정렬 조건

int find(int num){
    if(num == parent[num])
        return num;

    return parent[num] = find(parent[num]);
} // 유니온 파인드

int main(){
    int V, E;
    cin >> V >> E;
    for(int i=1; i<=V; i++){ // V개의 집
        parent[i] = i;
    } // 최초에 자신의 부모는 자기 자신임.

    for(int i=0; i<E; i++){ // E개의 길
        KS ks;
        cin >> ks.from >> ks.to >> ks.val;
        Edges.push_back(ks);
    } // 입력

    sort(Edges.begin(), Edges.end(), comp);

    // 모든 집을 연결해준 후, 가장 큰 가중치를 잘라내는 것이 목표다.
    int maxval;
    for(int i=0; i<E; i++){
        int f = find(Edges[i].from); // f번 집과
        int t = find(Edges[i].to); // t번 집을 연결하는 간선이 Edges[i]이다.

        if(t == f)
            continue;

        parent[f] = t; // f번 집은 t번 집과 연결됨.

        result += Edges[i].val;
        maxval = Edges[i].val;
    }

    cout << result-maxval << endl;
    return 0;
}