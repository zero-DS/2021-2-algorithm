#2020314968_김가연
people1 = []
people2 = []
result1 = []
result2 = []

num1 = int(input("평일 당직 총 인원 수: "))
print("이름을 입력해 주세요")
for i in range (num1):
    name = input()
    people1.append(name)

cf1 = int(input("constant factor: "))
popNum = 0

while len(people1) > 0:
    popNum = (popNum + cf1 - 1) % len(people1)
    popElement = people1.pop(popNum)
    result1.append(str(popElement))

print("평일 당직 순서")
print("<%s>" %(", ".join(result1)))

num2 = int(input("주말 당직 총 인원 수: "))
print("이름을 입력해 주세요")
for i in range(num2):
    name = input()
    people2.append(name)

cf2 = int(input("constant factor: "))

while len(people2) > 0:
    popNum = (popNum + cf2 - 1) % len(people2)
    popElement = people2.pop(popNum)
    result2.append(str(popElement))

print("주말 당직 순서")
print("<%s>" %(", ".join(result2)))

