#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int n;
double point;
string al, str;
double sum = 0;
int pointsum = 0;
vector<string> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<20; i++){
        cin >> str >> point >> al;
        if(al == "P") continue;
        if(al == "A+"){
            sum += point * 4.5;
        } else if(al == "A0"){
            sum += point * 4.0;
        } else if(al == "B+"){
            sum += point * 3.5;
        } else if(al == "B0"){
            sum += point * 3.0;
        } else if(al == "C+"){
            sum += point * 2.5;
        } else if(al == "C0"){
            sum += point * 2.0;
        } else if(al == "D+"){
            sum += point * 1.5;
        } else if(al == "D0"){
            sum += point * 1.0;
        } 
        pointsum += point;
    }
    sum /= pointsum;
    cout << fixed;
    cout.precision(5);
    cout << sum;
    return 0;
}