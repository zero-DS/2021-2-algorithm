names = [
    '민석', '창희', '태완', '연준', '용주', '보민',
    '소미', '서준', '예준', '도윤', '시우', '주원',
    '하준', '지호', '지후', '서연', '서윤', '지우',
    '서현', '하윤', '윤서', '지유', '지민', '채원',
    '지윤', '은서', '수아', '다은', '예은', '지아'
]
count = len(names) # 30
weekdays_ids = [i for i in range(count)]
weekends_ids = [i for i in range(count)]
constant = 3 # random.randint(1, 10)

members_order = []

# joshephus problem을 이용하여 풀려하였으나, 그렇게 하면 과정이 
# 출력되지 못해 다른 방식으로 구현합니다.

# 뽑히는 순서를 members_order에 차례대로 담아주기로 하였습니다.
def modified_josephus(arr, k, cursor):   
    newCount = len(arr) 
    newCursor = (cursor+k-1) % newCount 
    if len(arr) == 1:
        return members_order.append(arr.pop(newCursor))
    members_order.append(arr.pop(newCursor))
    return modified_josephus(arr, k, newCursor)

modified_josephus(weekdays_ids, constant, 0)

# 평일 당번과 주말 당번을 따로 따로 담아주었습니다.
weekdays_order = [[] for i in range(5)]
weekends_order = [[] for i in range(2)]

for i in range(count):
    if i%5 == 0:
        weekdays_order[0].append(members_order[i])
    elif i%5 == 1:
        weekdays_order[1].append(members_order[i])
    elif i%5 == 2:
        weekdays_order[2].append(members_order[i])
    elif i%5 == 3:
        weekdays_order[3].append(members_order[i])
    elif i%5 == 4:
        weekdays_order[4].append(members_order[i])

for i in range(count):
    if i%2 == 0:
        weekends_order[0].append(members_order[i])
    elif i%2 == 1:
        weekends_order[1].append(members_order[i])

# 평일 당직표 출력해주기
print("<<< 평일 당직표 >>>\n")
for i in range(5):
    if i%5 == 0:
        print("월요일: ", end='')
        for j in range(len(weekdays_order[0])):
            print(names[weekdays_order[0][j]], end=' ')
        print("\n")
    elif i%5 == 1:
        print("화요일: ", end='')
        for j in range(len(weekdays_order[1])):
            print(names[weekdays_order[1][j]], end=' ')
        print("\n")
    elif i%5 == 2:
        print("수요일: ", end='')
        for j in range(len(weekdays_order[2])):
            print(names[weekdays_order[2][j]], end=' ')
        print("\n")
    elif i%5 == 3:
        print("목요일: ", end='')
        for j in range(len(weekdays_order[3])):
            print(names[weekdays_order[3][j]], end=' ')
        print("\n")
    elif i%5 == 4:
        print("금요일: ", end='')
        for j in range(len(weekdays_order[4])):
            print(names[weekdays_order[4][j]], end=' ')
        print("\n")

# 주말 당직표 출력해주기
print("\n<<< 주말 당직표 >>>\n")
for i in range(2):
    if i%2 == 0:
        print("토요일: ", end='')
        for j in range(len(weekends_order[0])):
            print(names[weekends_order[0][j]], end=' ')
        print("\n")
    else:
        print("일요일: ", end='')
        for j in range(len(weekends_order[1])):
            print(names[weekends_order[1][j]], end=' ')