#decrease and conquer
#당직표 짜기 
#알고리즘 201810510 박시은


def josephus(people, plan, cf):
    employ = []
    for i in people:
        employ.append(i)
    
    i = 0
    while len(employ) > 1:
        i = (i + cf - 1) % len(employ)
        plan.append(employ[i])
        del employ[i]
    plan.append(employ[0])
    return plan

def main():
    people = []
    peopleNum = int(input("인원수를 입력하세요: "))
    cf1 = int(input("평일 당직 constant factor: "))
    cf2 = int(input("주말 당직 constant factor: "))
    for i in range(peopleNum):
        name = input("이름: ")
        people.append(name)
    
    print("직원 목록: ", people)
    daily = []
    weekend = []
    josephus(people, daily, cf1)
    josephus(people, weekend, cf2)

    print("평일 당직 순서: ", daily)
    print("주말 당직 순서: ", weekend)

main()

