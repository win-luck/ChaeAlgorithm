#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

#define INF 987654321
using namespace std;
int n;
map<string, int> m;
double d[31][31];

void init(){
    m.clear();
    memset(d, 0, sizeof(d));
    string str1, str2;
    double val;
    int tmp;

    for(int i=1; i<=n; i++){
        cin >> str1;
        m[str1] = i;
    }

    cin >> tmp;
    for(int i=1; i<=tmp; i++){
        string str1, str2;
        double val;
        cin >> str1 >> val >> str2;
        d[m[str1]][m[str2]] = val;
    }
}

void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j] < d[i][k] * d[k][j]){
                    d[i][j] = d[i][k] * d[k][j];
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int a=1; ; a++){
        cin >> n;
        if(n == 0) break;
        init();
        floyd();
        string answer = (d[1][1] > 1 ? "Yes" : "No");
        cout << "Case " << a << ": " + answer << '\n';
    }
    return 0;
}
