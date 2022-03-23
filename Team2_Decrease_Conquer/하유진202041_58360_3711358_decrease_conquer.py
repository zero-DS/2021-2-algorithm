def josephus(num, rem, arr):
    remlst = []
    cnt = 1
    while len(arr) != 1:
        for i in arr:
            if cnt % rem == 0:
                remlst.append(i)
            cnt += 1

        for j in remlst:
            print(j)
            arr.remove(j)
            remlst = []


arr1 = []
arr2 = []

people_num = int(input("number of people: "))
for i in range(people_num):
    name = input("name: ")
    arr1.append(name)
    arr2.append(name)

num1 = int(input("constant factor for weekday: "))
josephus(people_num, num1, arr1)

num2 = int(input("constant factor for weekend: "))
josephus(people_num, num2, arr2)
