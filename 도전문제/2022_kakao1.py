from collections import defaultdict

def solution(id_list, report, k):
    answer_dict = defaultdict(list)
    answer = dict() # count get reported mail
    result = []

    for i in id_list:
        answer[i] = 0

    for i in list(set(report)):
        id_reporter, id_reported = i.split(" ")
        answer_dict[id_reported].append(id_reporter) 
        # 피신고자 = {신고자1, 신고자2}의 형태로 저장

    for i in range(len(id_list)):
        if(len(answer_dict[id_list[i]]) >= k): # 신고횟수 도달 시 신고자들 메일 +1
            for j in answer_dict[id_list[i]]:
                answer[j] += 1

    for i in id_list:
        for key, value in answer.items():
            if key == i: # 
                result.append(value)

    return result