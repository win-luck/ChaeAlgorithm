#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int n, m;
long long val;
string str1, str2;
vector<pair<long long, pair<string, string> > > v;
map<string, string> parent;

string find(string s){
    if(parent[s] == "") return s;
    return parent[s] = find(parent[s]);
} // 

bool cmp(pair<long long, pair<string, string> >  p1, pair<long long, pair<string, string> >  p2){
    return p1.first > p2.first;
} // 거리 내림차순

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num = 0;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(long long i=0; i<m; i++){
            cin >> str1 >> str2 >> val;
            v.push_back(make_pair(val, make_pair(str1, str2)));
        }
        string start, end;
        cin >> start >> end;
        sort(v.begin(), v.end(), cmp);

        long long ans = 1e9;
        for(long long i=0; i<v.size(); i++){
            string a = find(v[i].second.first);
            string b = find(v[i].second.second);
            long long c = v[i].first;

            if(a != b){
                parent[a] = b;
                if(ans > c) ans = c;
            }

            if(find(start) == find(end)){
                cout << "Scenario #" << ++num << '\n';
                cout << ans << " tons\n\n";
                break;
            }
        }
        v.clear();
        parent.clear();
    }
    return 0;
}