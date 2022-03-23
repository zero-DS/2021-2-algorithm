import copy
N=int(input("당직 근무의 총 대상 인원을 입력하세요 : "))
left=N
print("당직 근무 대상의 이름을 입력해주세요 : ",end='')
people_weekday=list(input().split())
people_weekend=copy.copy(people_weekday)
print("평일 당직표 지정을 위한 난수값을 입력해주세요. (1 ~ %d) : " %N, end='')
CF_1=int(input())
print("주말 당직표 지정을 위한 난수값을 입력해주세요. (1 ~ %d) : " %N, end='')
CF_2=int(input())
def modify(people,target):
    global left
    for i in range(target,left-1):
        people[i]=people[i+1]
    people.pop()
    left-=1
def jose(people,target,CF):
    global left
    if left==0: return
    next=target+CF-1
    print(people[target],end=' ')
    modify(people,target)
    if left==0: return
    while next>=left:
        next-=left
    jose(people,next,CF)
print("\n평일 당직 순서 : ",end='')
jose(people_weekday,CF_1-1,CF_1)
left=N
print("\n주말 당직 순서 : ",end='')
jose(people_weekend,CF_2-1,CF_2)

