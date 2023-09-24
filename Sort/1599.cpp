#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
string str;
int n;
vector<pair<string, string> > answer;
map<char, char> m;

bool cmp(pair<string, string> s1, pair<string, string> s2){
    return s1.second < s2.second;
}

void init(){ // 민식어 알파벳과 매핑
    m['a'] = 'a';
    m['b'] = 'b';
    m['k'] = 'c';
    m['d'] = 'd';
    m['e'] = 'e';
    m['g'] = 'f';
    m['h'] = 'g';
    m['i'] = 'h';
    m['l'] = 'i';
    m['m'] = 'j';
    m['n'] = 'k';
    m['z'] = 'l'; // ng를 z로 바꾼다.
    m['o'] = 'm';
    m['p'] = 'n';
    m['r'] = 'o';
    m['s'] = 'p';
    m['t'] = 'q';
    m['u'] = 'r';
    m['w'] = 's';
    m['y'] = 't';
}

string replaceAll(string str){
    size_t start_pos = 0;
	while ((start_pos = str.find("ng", start_pos)) != std::string::npos)
	{
		str.replace(start_pos, 2, "z");
		start_pos += 1;
	}
	return str;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        string tmp = str;
        tmp = replaceAll(tmp); // ng를 z로 바꾼다.
        string transtr = "";
        for(int i=0; i<tmp.size(); i++){
            transtr += m[tmp[i]];
        }
        answer.push_back(make_pair(str, transtr));
    }

    sort(answer.begin(), answer.end(), cmp);
    for(int i=0; i<n; i++){
        cout << answer[i].first << '\n';
    }
    return 0;
}
