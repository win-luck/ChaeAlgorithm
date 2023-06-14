#include <iostream>
#include <algorithm>

using namespace std;
int n, k;

struct nation { // 국가
    int num;
    int g;
    int s;
    int b;
};

bool equalcheck(nation n1, nation n2){ // 메달 수가 동일한지 확인
    if(n1.g == n2.g && n1.s == n2.s && n1.b == n2.b) return true;
    else return false;
}

bool cmp(nation n1, nation n2){ // 정렬 오버라이딩
    if(n1.g == n2.g){
        if(n1.s == n2.s){
            if(n1.b == n2.b){
                return n1.num > n2.num;
            }
            return n1.b > n2.b;
        }
        return n1.s > n2.s;
    }
    return n1.g > n2.g;
}
vector<nation> v;

int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        nation n1;
        cin >> n1.num >> n1.g >> n1.s >> n1.b;
        v.push_back(n1);
    }

    sort(v.begin(), v.end(), cmp); // 메달 내림차순 정렬
    for(int i=1; i<=v.size(); i++){
        if(k == v[i-1].num){
            int a = i-1;
            while(a >= 1 && equalcheck(v[a], v[a-1])){ // 동점자를 추적하여 자신의 공동 등수 여부를 확인
                a--;
            }
            cout << a+1 << '\n';
            break;
        }
    }
    return 0;
}