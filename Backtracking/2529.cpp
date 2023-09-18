#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
char inequal[11];
int str[11];
bool visited[11];
int n;
long long maxval = 0, minval = 9999999999;

void validcheck(){
    long long tmp = 0;
    long long len = 1;

    for(int i=0; i<n; i++){
        if(inequal[i] == '<'){
            if(str[i] > str[i+1])
                return;
        }
        if(inequal[i] == '>'){
            if(str[i] < str[i+1])
                return;
        }
    }

    for(int i=n; i>=0; i--){
        tmp += len * str[i];
        len *= 10;
    }

    if(maxval < tmp){
        maxval = tmp;
    }
    if(minval > tmp){
        minval = tmp;
    }
}

void DFS(int cnt){
    if(cnt == n + 1){
        validcheck();
        return;
    }

    for(int i=0; i<10; i++){
        if(!visited[i]){
            visited[i] = true;
            str[cnt] = i;
            DFS(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> inequal[i];
    }

    for(int i=0; i<10; i++){
        str[0] = i;
        visited[i] = true;
        DFS(1);
        visited[i] = false;
    }

    string maxstr = to_string(maxval);
    string minstr = to_string(minval);

    if(maxstr.size() < n+1){
        reverse(maxstr.begin(), maxstr.end());
        for(int i=0; i<n+1-maxstr.size(); i++){
            maxstr += '0';
        }
        reverse(maxstr.begin(), maxstr.end());
    }
    if(minstr.size() < n+1){
        reverse(minstr.begin(), minstr.end());
        for(int i=0; i<n+1-minstr.size(); i++){
            minstr += '0';
        }
        reverse(minstr.begin(), minstr.end());
    }
    cout << maxstr << '\n';
    cout << minstr << '\n';
    return 0;
}
