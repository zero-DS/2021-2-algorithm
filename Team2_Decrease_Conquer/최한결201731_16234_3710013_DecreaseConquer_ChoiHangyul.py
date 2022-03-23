"""
알고리즘 과제
<Decrease and Conquer>

주제: 당직표 짜기
Josephus Problem (Decrease by constant factor)

INPUT: 총 인원 수, 사람 명단, constant factor
OUTPUT: 당직 인원 명단 (평일 / 주말)
    
"""
# input
day_num = int(input('(평일) 총 인원을 입력하세요: '))
day_c = int(input('(평일) constant factor를 입력하세요: '))
people_day = []
for i in range(day_num):
    people_day.append(input(f'{i+1}번째 평일 근무 명단(이름)을 입력하세요: '))
    
weekend_num = int(input('(주말) 총 인원을 입력하세요: '))
weekend_c = int(input('(주말) constant factor를 입력하세요: '))
people_weekend = []
for i in range(weekend_num):
    people_weekend.append(input(f'{i+1}번째 주말 근무 명단(이름)을 입력하세요: '))
    
# algorithm
def josephus(n, k, name):
    people = [i for i in range(1, n+1)]
    current = 0
    result = []
    for _ in range(n-1):
        current = (current + k - 1) % len(people)
        result.append(name[people[current]-1])
        # print(f'{people[current]}', end='')
        del people[current]
    return result

# output
print('\n<평일 당직 순서>\n')
print(' -> '.join(i for i in josephus(day_num, day_c, people_day)))
print('\n<주말 당직 순서>\n')
print(' -> '.join(i for i in josephus(weekend_num, weekend_c, people_weekend)))
