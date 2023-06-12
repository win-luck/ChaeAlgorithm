#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct student{
    string name;
    int day;
    int month;
    int year;
};
vector<student> v;

bool cmp(student s1, student s2){
    if(s1.year == s2.year){
        if(s1.month == s2.month){
            return s1.day < s2.day;
        }
        return s1.month < s2.month;
    }
    if(s1.month == s2.month){
        return s1.day < s2.day;
    }
    return s1.year < s2.year;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        student s1;
        cin >> s1.name >> s1.day >> s1.month >> s1.year;
        v.push_back(s1);
    }

    sort(v.begin(), v.end(), cmp);
    cout << v.back().name << '\n';
    cout << v.front().name << '\n';
    return 0;
}