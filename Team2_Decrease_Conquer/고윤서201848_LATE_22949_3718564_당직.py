
num = int(input("총 인원수 >>"))
member = []
constant_factor = int(input("상수 입력 >>"))

for i in range(num):
    temp = input("이름 >>")
    member.append(temp)

print("전체 인원 :", member)


result = []
temp = constant_factor - 1


for i in range(num):
    if len(member) > temp: 
        result.append(member.pop(temp)) 
        temp += constant_factor - 1
        
    elif len(member) <= temp:
        temp = temp % len(member)
        result.append(member.pop(temp))
        temp += constant_factor - 1

print("당직 순서 :", result)
