#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num;
int tree[10001];

void PostOrder(int start, int end){ // 전위순회(루트, 왼, 오)로 처리된 배열을 후위순회(왼, 오, 루트)로 처리해주어야 한다.
    if(start >= end) return;
    if(start == end - 1) { // 영역 내 노드가 단 하나일 때는 그 값만 출력 
        cout << tree[start] << endl;
        return;
    }
    
    int nextindex = start + 1;
    while(nextindex < end){ // 루트보다 큰 수가 나오는 순간부터 그 이후 수들은 루트의 오른쪽에 배치된다.
        if(tree[nextindex] > tree[start]) 
            break;
        nextindex++;
    }

    PostOrder(start+1, nextindex);
    PostOrder(nextindex, end);
    cout << tree[start] << endl;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int index = 0;
    while(cin >> num){
        tree[index++] = num; // 증가된 마지막 인덱스는 값이 없음.
    }

    PostOrder(0, index); // 0~n-1 인덱스까지만 트리의 실제 값이 존재함.
    return 0;
}