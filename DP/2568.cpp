#include <iostream>
#include <algorithm>
#include <vector>

#define INF 500001

using namespace std;
vector<pair<int, int> > line;
vector<int> LIS, idx, v;

/** 전깃줄이 꼬이다?
 * 출발점(인덱스)가 더 아래인 상태에서 그 인덱스의 도착점보다 위를 가리킬 때
 *  그럼 안 꼬이려면?
 * 항상 이전 인덱스의 도착점보다 더 아래를 가리키면 된다.
 * -> LIS
 * 전깃줄 1과 비교했을 떄 좀 더 매끄러운 자료형과 좀 더 깔끔한 flow가 필요했던 문제. 다음에 또 풀어보자.
 */

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;

    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        line.push_back(make_pair(a, b));
    }

    sort(line.begin(), line.end()); // 인덱스 오름차순 정렬
    LIS.push_back(line[0].second);
	idx.push_back(0);

    for(int i=1; i<n; i++){
        int pos = line[i].second;

        if(LIS.back() < pos){ // 자르지 않아도 되는 LIS 선
            idx.push_back(LIS.size()); // 현재 위치를 저장
            LIS.push_back(pos); // LIS 연장
        } else { // 이후에 잘라야 하는 선
            vector<int>::iterator iter = lower_bound(LIS.begin(), LIS.end(), pos);
            *iter = pos;
            idx.push_back(iter - LIS.begin());
        }
    }

    cout << n - LIS.size() << '\n';
    int now = LIS.size() - 1;
    for(int i = idx.size()-1; i>=0; i--){
        if(idx[i] == now){ // LIS 배열의 원소임을 감지
            now--;
        } else { // 원소가 아닌 것들을 출력해야 함
            v.push_back(line[i].first);
        }
    }

    for(int i=v.size()-1; i>=0; i--){ // 역출력
        cout << v[i] << '\n';
    }
    return 0;
}