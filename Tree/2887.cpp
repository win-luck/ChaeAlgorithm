#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

// 1647번과 유니온 파인드 연습 시 다시 풀어보기
using namespace std;

typedef struct pos{
    int x;
    int y;
    int z;
    int nums; 
    pos(int X, int Y, int Z, int I) : x(X), y(Y), z(Z), nums(I) {}
};

typedef struct E{
    int dist;
    int from;
    int to;
    E(int d, int i, int j) : dist(d), from(i), to(j) {}
};

int n, result;
int counts;
int parent[100001];
vector<pos> map;
vector<E> distancelist;

int Find(int num){
    if(num == parent[num])
        return num;

    return parent[num] = Find(parent[num]);
} // 간선의 부모를 찾는 유니온 파인드 적용

bool cmpx(pos e1, pos e2){
    return e1.x < e2.x;
}

bool cmpy(pos e1, pos e2){
    return e1.y < e2.y;
}

bool cmpz(pos e1, pos e2){
    return e1.z < e2.z;
}

bool cmpd(E e1, E e2){
    return e1.dist < e2.dist;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        parent[i] = i;
    } // 자기 자신의 부모는 최초에 자기 자신임. 연결되면서 부모를 정한다.

    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        map.push_back(pos(a, b, c, i));
    } // i번째 행성의 x좌표, y좌표, z좌표

    sort(map.begin(), map.end(), cmpx); // x값 오름차순으로 행성 정렬
    for(int i=0; i<n-1; i++){
        distancelist.push_back(E(abs(map[i+1].x - map[i].x), map[i].nums, map[i+1].nums)); // x값 오름차순인 행성 n-1개 삽입
    }

    sort(map.begin(), map.end(), cmpy); // y값 오름차순으로 행성 정렬
    for(int i=0; i<n-1; i++){
        distancelist.push_back(E(abs(map[i+1].y - map[i].y), map[i].nums, map[i+1].nums)); // y값 오름차순인 행성 n-1개 삽입
    }

    sort(map.begin(), map.end(), cmpz); // z값 오름차순으로 행성 정렬
    for(int i=0; i<n-1; i++){
        distancelist.push_back(E(abs(map[i+1].z - map[i].z), map[i].nums, map[i+1].nums)); // z값 오름차순인 행성 n-1개 삽입
    }

    sort(distancelist.begin(), distancelist.end(), cmpd); // Kruskal 알고리즘을 위한 정렬

    for(int i=0; i < distancelist.size(); i++){
        int a = Find(distancelist[i].from);
        int b = Find(distancelist[i].to);
        if(a != b){ // 부모가 다르면(사이클이 형성되지 않는다면) 연결하고 그 값을 결과에 더해줌.
            parent[a] = b;
            result += distancelist[i].dist;
        }
    }

    cout << result << endl;
}