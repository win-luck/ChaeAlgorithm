#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int nowleft = 10; // 초기 위치
    int nowright = 12; 
    
    int move[13][13];
    
    // 각 다이얼에서 2까지의 거리
    move[1][2] = move[3][2] = 1;
    move[4][2] = move[6][2] = 2;
    move[7][2] = move[9][2] = 3;
    move[10][2] = move[12][2] = 4; 
    
    // 각 다이얼에서 5까지의 거리
    move[1][5] = move[3][5] = 2;
    move[4][5] = move[6][5] = 1;
    move[7][5] = move[9][5] = 2;
    move[10][5] = move[12][5] = 3; 
    
    // 각 다이얼에서 8까지의 거리
    move[1][8] = move[3][8] = 3;
    move[4][8] = move[6][8] = 2;
    move[7][8] = move[9][8] = 1;
    move[10][8] = move[12][8] = 2; 
    
    // 각 다이얼에서 0까지의 거리
    move[1][0] = move[3][0] = 4;
    move[4][0] = move[6][0] = 3;
    move[7][0] = move[9][0] = 2;
    move[10][0] = move[12][0] = 1; 
    
    // 2, 5, 8, 0 다이얼의 서로간의 거리
    move[2][2] = move[5][5] = move[8][8] = move[0][0] = 0; 
    move[2][5] = move [5][8] = move[8][0] = move[5][2] = move[8][5] = move[0][8] = 1;
    move[2][8] = move[5][0] = move[8][2] = move[0][5] = 2;
    move[2][0] = move[0][2] = 3;
    
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] %3 == 1){ // 1, 4, 7은 왼쪽이 담당
            nowleft = numbers[i];
            answer += 'L';
        } else if(numbers[i] %3 == 0 && numbers[i] != 0){ // 3, 6, 9는 오른쪽이 담당
            nowright = numbers[i];
            answer += 'R';
        } else{ // 2, 5, 8, 0인 경우
            if(move[nowleft][numbers[i]] > move[nowright][numbers[i]]){ // 두 엄지와 다이얼 간 거리 비교
                answer += 'R';
                nowright = numbers[i];
            } else if(move[nowleft][numbers[i]] < move[nowright][numbers[i]]){
                answer += 'L';
                nowleft = numbers[i];
            } else { // 두 거리가 같을 경우 오른손잡이인지 왼손잡이인지 판단
                if(hand == "right"){
                    answer += 'R';
                    nowright = numbers[i];
                } else {
                    answer += 'L';
                    nowleft = numbers[i];
                }
            }
        } 
    }
    return answer;
}