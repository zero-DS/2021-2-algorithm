N=int(input("총 인원 수를 입력하세요 : "))

people = list()
for person in range(0,N):
    temp=str(input("사람을 입력하세요 : "))
    people.append(temp)

constant_factor=int(input("순회할 constant factor를 입력하세요 : "))
constant_factor_count = 0

day = 1
index = 0

while len(people) > 0:
    constant_factor_count += 1
    if index == len(people):
        index = 0
    if constant_factor == constant_factor_count:
        print(day,end="")
        print("일 당번 : ", end="")
        print(people[index])
        del people[index]
        constant_factor_count = 0
        day += 1
    else:
        index += 1