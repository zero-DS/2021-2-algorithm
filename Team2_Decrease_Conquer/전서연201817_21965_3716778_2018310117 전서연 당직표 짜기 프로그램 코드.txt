#2018310117 전서연 #당직표 짜기 프로그램
print("<<당직표 짜기 프로그램>>")
print()
num=int(input("총 인원의 수는 몇명인가요? "))
print()
dayfac=int(input("평일 당직표의 constant factor는? "))
endfac=int(input("주말 당직표의 constant factor는? "))
print()
lst=[]
lst2=[]

for i in range(num):
    print(i+1, end="")
    print("번째 사람의 ", end="")
    name=input("이름은? ")
    lst.append(name)
    lst2.append(name)

def josephus(rem):
    remlst=[]
    orderlist=[]

    cnt=1
    while len(lst)!=1:
        for i in lst:
            if cnt%rem==0:
                remlst.append(i)
            cnt+=1

        for j in remlst:
            orderlist.append(j)
            lst.remove(j) #lst에 있는 모든 원소를 비운다.
            remlst=[] #remlst를 재선언한다.
    
    print(orderlist)
    del lst[0]

print()
print("평일 당직 순서: ", end=""), josephus(dayfac)
for i in lst2:
    lst.append(i)

print()
print("주말 당직 순서: ", end=""), josephus(endfac)
