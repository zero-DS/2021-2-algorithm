def josephus(people_list, step):
    step -= 1
    idx = step
    if len(people_list) == 2:
        idx = (step+1) % len(people_list)
        people_list.pop(idx)
    
    if len(people_list) == 1:
        return people_list[0]

    while len(people_list) > 1:
        people_list.pop(idx)
        idx = (idx + step) % len(people_list)
    return people_list[0]

def weekday_form(people_list, people_numbers):
    for i in range (1, people_numbers+1):
        name = input("주간 당직을 신청한 %d 번째 사람의 이름을 입력하세요 >> " %i)
        people_list.append(name)
    return people_list
    
def weekday_assign(people_list, step):
    weekday_list = []
    for i in "월화수목금":
        weekday_people = people_list.copy()
        result = josephus(weekday_people, weekday_step)
        weekday_list.append(result)
        print(i, "요일 당직 >>", result)
        people_list.remove(result)
    return weekday_list

def weekend_form(people_list, people_numbers):
    for i in range (1, people_numbers+1):
        name = input("주말 당직을 신청한 %d 번째 사람의 이름을 입력하세요 >> " %i)
        people_list.append(name)
    return people_list

def weekend_assign(people_list, step):
    weekend_list = []
    for i in "토일":
        weekend_people = people_list.copy()
        result = josephus(weekend_people, weekday_step)
        print(i, "요일 당직 >>", result)
        weekend_list.append(result)
        people_list.remove(result)
    return weekend_list

# 메인
weekday_people_list = []
weekday_people_numbers = int(input("주간 당직 근무를 신청한 사람 수를 입력하세요 >> "))
weekday_people_list = weekday_form(weekday_people_list, weekday_people_numbers)

print("===주간 당직 신청자 명단===")
print(weekday_people_list)
print("==========================")

weekday_step = int(input("(주간 당직) 건너 뛸 스텝 수를 입력하세요 >> "))
print("===주간 당직 배정 결과===")
weekday_assign_result = weekday_assign(weekday_people_list, weekday_step)
print(weekday_assign_result)
print("==========================")

weekend_people_list = []
weekend_people_numbers = int(input("주말 당직 근무를 신청한 사람 수를 입력하세요 >> "))
weekend_people_list = weekend_form(weekend_people_list, weekend_people_numbers)

print("===주말 당직 신청자 명단===")
print(weekend_people_list)
print("==========================")

weekend_step = int(input("(주말 당직) 건너 뛸 스텝 수를 입력하세요 >> "))
print("===주말 당직 배정 결과===")
weekend_assign_result = weekend_assign(weekend_people_list, weekend_step)
print(weekend_assign_result)
print("==========================")

