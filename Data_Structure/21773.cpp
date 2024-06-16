#include <iostream>
#include <queue>

struct process {
    int id, val, time;

    process(int a, int b, int c){
        id = a;
        val = c;
        time = b;
    }
};
using namespace std;
int n, t;

struct compare {
    bool operator()(process p1, process p2){
        if(p1.val == p2.val) return p1.id > p2.id;
        return p1.val < p2.val;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int now = 0;
    cin >> t >> n;
    priority_queue<process, vector<process>, compare> pq;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push(process(a, b, c));
    }
    
    while(1){
        now++;
        process top = pq.top();
        pq.pop();
        cout << top.id << '\n';
        top.time--;
        top.val--;

        if(top.time > 0){
            pq.push(top);
        }
        if(now == t) break;
    }
    return 0;
}
