#include <iostream>
#include <sstream>
#include <map>

using namespace std;
map<string, int> m;
int total = 0;

void print(string str){
    double rate = (double)m[str]/total;
    cout << str << " " << m[str] << " ";
    cout.precision(2);
    cout << fixed << rate << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    while(total < 24){
        getline(cin, str);
        stringstream ss(str);
        string tmp;
        bool flag = false;
        while(ss >> tmp){
            m[tmp]++;
            total++;
            flag = true;
        }
        if(!flag) break;
    }
    string arr[7] =  {"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};
    for(int i=0; i<7; i++){
        print(arr[i]);
    }
    cout << "Total " << total << " 1.00";
    return 0;
}
