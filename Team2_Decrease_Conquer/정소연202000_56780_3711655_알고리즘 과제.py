def josephus(n, k, people):
    array = [i for i in range(1,n+1)]

    di = k-1
    while len(array) > 1:
        print(people[di])
        del array[di], people[di]
        length = len(array)
        di = (di+k-1)%length

    print(people[0])

worker = []
worker2 = []

number = int(input("인원수는 몇명인가요?: "))

for i in range(number):
    p = input("사람을 입력해주세요: " )
    worker.append(p)
    worker2.append(p)

factor1= int(input("주중의 constant factor: "))
factor2 = int(input("주말의 constant factor: "))


print("평일 당직")
remains = josephus(number, factor1, worker)
print("주말 당직")
remains = josephus(number, factor2, worker2)
