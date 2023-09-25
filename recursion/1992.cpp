#include <iostream>

using namespace std;
int map[65][65];

bool validcheck(int x, int y, int n){
    int tmp = map[x][y];
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(tmp != map[i][j]) return false;
        }
    }
    return true;
}

void DC(int x, int y, int n){
    if(validcheck(x, y, n) == true){
        cout << map[x][y];
        return;
    }

    cout << '(';
    n /= 2;
    DC(x, y, n);
    DC(x, y+n, n);
    DC(x+n, y, n);
    DC(x+n, y+n, n);
    cout << ')';
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++){
            map[i][j] = (str[j] - '0');
        }
    }

    DC(0, 0, n);
    return 0;
}
