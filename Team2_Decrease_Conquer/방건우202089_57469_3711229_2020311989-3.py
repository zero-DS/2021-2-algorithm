def jsp(n, k, people):
    arr = [i for i in range(1,n+1)]
    delindex = k-1
    while len(arr) > 1:
        print(people[delindex])
        del arr[delindex], people[delindex]
        delindex = (delindex+k-1)%len(arr)
    print(people[0])

people = []
people2 = []
number = int(input("총 인원수: "))
for i in range(number):
    str = (input("%d번째 사람: " % i))
    people.append(str)
    people2.append(str)
cf_week= int(input("constant factor of weekdays: "))
cf_end = int(input("constant factor of weekends: "))
print("평일 당직")
remains = jsp(number, cf_week, people)
print("주말 당직")
remains = jsp(number, cf_end, people2)

