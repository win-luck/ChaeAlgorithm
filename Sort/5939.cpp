#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct t{
    int a;
    int b;
    int c;
    t(int s1, int s2, int s3){
        a = s1;
        b = s2;
        c = s3;
    }
};
vector<t> v;
int n;

bool cmp(t p1, t p2){
    if(p1.a == p2.a){
        if(p1.b == p2.b){
            return p1.c < p2.c;
        }
        return p1.b < p2.b;
    }
    return p1.a < p2.a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        int str1, str2, str3;
        cin >> str1 >> str2 >> str3;
        v.push_back(t(str1, str2, str3));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; i++){
        cout << v[i].a << " " << v[i].b << " " << v[i].c << '\n';
    }
}
