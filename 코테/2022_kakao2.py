import math

def solution(n, k):
    result = 0
    flag = 0
    
    input = ""
    while n:
        input = str(n % k) + input
        n = n // k
    input = input.split("0") # 진법 변환 후 0 기준으로 자르기

    for i in input:
        flag = True
        if i.isdigit() and int(i) >= 2: # 공백이 아니면서 2보다 큰 정수
            for j in range(2, int(math.sqrt(int(i))) + 1):
                if((int(i) % j) == 0): # 나누어떨어지면 소수가 아니다.
                    flag = False
                    break

            if(flag == True):
                result += 1     

    return result