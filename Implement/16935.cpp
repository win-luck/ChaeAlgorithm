#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, m, r;
int arr[101][101];
int tmp[101][101];
vector<int> op;

void copy(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

void rotate(int a){
    memset(tmp, 0, sizeof(tmp));
    if(a == 1){ // 상하반전
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                tmp[i][j] = arr[n-1-i][j];
            }
        }
    } else if(a == 2){ // 좌우반전
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                tmp[i][j] = arr[i][m-1-j];
            }
        }
    } else if(a == 3){ // 우측 90도 회전
        swap(n, m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                tmp[i][j] = arr[m-1-j][i];
            }
        }
    } else if(a == 4){ // 좌측 90도 회전
        swap(n, m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                tmp[i][j] = arr[j][n-1-i];
            }
        }
    } else if(a == 5){
        int a = n/2;
        int b = m/2;

        // 1번 -> 2번
        for(int i=0; i<a; i++){
            for(int j=b; j<m; j++){
                tmp[i][j] = arr[i][j-b];
            }
        }

        // 2번 -> 3번
        for(int i=a; i<n; i++){
            for(int j=b; j<m; j++){
                tmp[i][j] = arr[i-a][j];
            }
        }

        // 3번 -> 4번
        for(int i=a; i<n; i++){
            for(int j=0; j<b; j++){
                tmp[i][j] = arr[i][j+b];
            }
        }

        // 4번 -> 1번
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                tmp[i][j] = arr[i+a][j];
            }
        }
    } else {
        int a = n/2;
        int b = m/2;

        // 1번 -> 4번
        for(int i=a; i<n; i++){
            for(int j=0; j<b; j++){
                tmp[i][j] = arr[i-a][j];
            }
        }

        // 4번 -> 3번
        for(int i=a; i<n; i++){
            for(int j=b; j<m; j++){
                tmp[i][j] = arr[i][j-b];
            }
        }

        // 3번 -> 2번
        for(int i=0; i<a; i++){
            for(int j=b; j<m; j++){
                tmp[i][j] = arr[i+a][j];
            }
        }

        // 2번 -> 1번
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                tmp[i][j] = arr[i][j+b];
            }
        }
    }
    copy();
}

void input(){
    cin >> n >> m >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<r; i++){
        int a;
        cin >> a;
        op.push_back(a);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    for(int i=0; i<op.size(); i++){
        rotate(op[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
