#include <iostream>

using namespace std;
long long x1, y1, x2, y2, x3, y3, x4, y4;

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
    long long s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if(s > 0) return 1;
    else if(s == 0) return 0; // 세 점이 일직선 위에 존재
    else return -1;
}

int isCross(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3, pair<long long, long long> p4){
    int line1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int line2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if(line1 == 0 && line2 == 0){ // 두 선분이 일직선 위에 나란히 존재
        if(p1 > p2) swap(p2, p1); // p1-p2-p3-p4 로 일직선 점이 나열되도록 하고, 
        if(p3 > p4) swap (p3, p4);

        if(p3 <= p2 && p1 <= p4){ // 포개는지 여부를 확인한다.
            return 1;
        } else {
            return 0;
        }
    }
    if(line1 <= 0 && line2 <= 0){ // 선분이 서로 교차하는 경우이다.
        return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    pair<long long, long long> p1 = make_pair(x1, y1);
    pair<long long, long long> p2 = make_pair(x2, y2);
    pair<long long, long long> p3 = make_pair(x3, y3);
    pair<long long, long long> p4 = make_pair(x4, y4);

    cout << isCross(p1, p2, p3, p4) << '\n';
    return 0;
}