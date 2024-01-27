#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, m, r;
int arr[301][301];
bool visited[301][301];

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

void rotate(int sx, int sy, int lenx, int leny){
    if(visited[sx][sy]) return;
    int cnt = (lenx)*(leny) - (lenx-2)*(leny-2);
    cnt = r % cnt;

    for(int a=0; a<cnt; a++){
        memset(visited, false, sizeof(visited));

        // 위쪽 (<-)
        int tmp = arr[sx][sy];
        visited[sx][sy] = true;
        for(int i=sy; i<sy+leny-1; i++){
            arr[sx][i] = arr[sx][i+1];
            visited[sx][i] = true;
        }

        // 오른쪽 (업)
        int ypos = sy+leny-1;
        for(int i=sx; i<sx+lenx-1; i++){
            arr[i][ypos] = arr[i+1][ypos];
            visited[i][ypos] = true;
        }

        // 아래쪽 (->)
        int xpos = sx+lenx-1;
        for(int i=ypos; i>sy; i--){
            arr[xpos][i] = arr[xpos][i-1];
            visited[xpos][i] = true;
        }

        // 왼쪽 (다운)
        for(int i=xpos; i>sx+1; i--){
            arr[i][sy] = arr[i-1][sy];
            visited[i][sy] = true;
        }
        arr[sx+1][sy] = tmp;
        visited[sx+1][sy] = true;
    }

    if(lenx > 2 && leny > 2)
        rotate(sx+1, sy+1, lenx-2, leny-2); // 다음 출발점
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    rotate(0, 0, n, m);
    print();
    return 0;
}
