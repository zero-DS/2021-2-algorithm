# # 당직표 짜기
import datetime as dt


lst = []
with open("name_list.txt",'r',encoding="utf-8") as f:
    count=0
    for line in f:
        lst.append(line.rstrip('\n'))   
        count+=1 
    print(count)

#40이하의 수
total = int(input("총 인원 수 : "))
cf = int(input("constant factor : ")) 

weekday = []
holiday = []
mon = ["월","화","수","목","금","토","일"]

def josephus(people,con_f,day):
    cur = 0
    while people:
        cur=(cur+(con_f-1))%len(people)
        day.append(people[cur])
        del people[cur]

def print_holiday(work_list):
    today = dt.datetime.today()
    for name in work_list:
        while today.weekday() < 5:
            today+=dt.timedelta(days=1)
        whatday = today.weekday()
        print(f"{today.month}월 {today.day}일 {mon[whatday]}요일 : {name}")
        today+=dt.timedelta(days=1)

def print_weekday(work_list):
    today = dt.datetime.today()
    for name in work_list:
        while today.weekday()>=5:
            today+=dt.timedelta(days=1)
        whatday = today.weekday()
        print(f"{today.month}월 {today.day}일 {mon[whatday]}요일 : {name}")
        today+=dt.timedelta(days=1)

    
# 평일 당직표
josephus(lst[:total],cf,weekday)

# 주말 당직표
josephus(lst[:total],cf,holiday)

print("======평일 당직표======")
print_weekday(weekday)

print("======주말 당직표======")
print_holiday(holiday)