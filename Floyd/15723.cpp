#include <iostream>
#include <algorithm>
#include <string>

#define INF 987654321
using namespace std;
bool dist[27][27];
int n, m;
string str;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) dist[i][j] = true;
            else dist[i][j] = false;
        }
    }
    cin.ignore();
    for(int i=0; i<n; i++){
        getline(cin, str);
        char c1 = str.front();
        char c2 = str.back();
        dist[c1-'a'][c2-'a'] = true;
    }

    for(int k=0; k<26; k++){
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(dist[i][k] && dist[k][j]){
                    dist[i][j] = true;
                }
            }
        }
    }

    cin >> m;
    cin.ignore();
    for(int i=0; i<m; i++){
        int a, b;
        getline(cin, str);
        a = str.front() - 'a';
        b = str.back() - 'a';
        cout << ((dist[a][b]) ? 'T' : 'F') << '\n';
    }
    return 0;
}