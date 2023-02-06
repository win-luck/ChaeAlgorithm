#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct KS {int from, to, val;}; // 간선의 출발지, 도착지, 가중치
vector<KS> Edges;
int parent[1001];
char gender[1001];
int N, M;

int find(int num){
    if(num == parent[num])
        return num;
    return parent[num] = find(parent[num]);
} // 유니온 파인드

bool comp(KS k1, KS k2){
    return k1.val < k2.val;
} // 오름차순 정렬 조건

int main(){
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        char c;
        cin >> c;
        gender[i] = c;
        parent[i] = i;
    }

    for(int i=0; i<M; i++){
        KS ks;
        cin >> ks.from >> ks.to >> ks.val;
        if(gender[ks.from] != gender[ks.to]) // 성별이 서로 다른 곳을 연결하는 길만 인정
            Edges.push_back(ks);
    }

    sort(Edges.begin(), Edges.end(), comp);

    int result = 0;
    int count = 0;
    for(int i=0; i<Edges.size(); i++){

        int f = find(Edges[i].from);
        int t = find(Edges[i].to);

        if(f != t){
            parent[f] = t;
            result += Edges[i].val;
            count++; // 경로의 개수
        }
    }
    if(count != N-1) // 경로의 개수가 N-1개가 아니라면 -1 출력
        result = -1;
    cout << result << endl;
    return 0;
}