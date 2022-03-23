def Josephus(n,people,k):
    key = 0
    temp = k - 1
    order = []
    while people:
        key = (key+temp) % len(people)
        order.append(people.pop(key))

    print('<'+', '.join(map(str, order))+'>')

for i in range(2):
    n=int(input("\n총 인원 수 : "))
    people=input("사람 명단 (각 사람 사이 space 한 칸) : ").split()
    k=int(input("constant factor : "))
    if i==0:
        print("----------평일 당직----------")
    else:
        print("----------주말 당직----------")
    Josephus(n,people,k)

