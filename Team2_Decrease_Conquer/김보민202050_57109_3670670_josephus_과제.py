weekday=[]
weekend=[]
week=['mon','tue','wed','thu','fri','sat','sun']     
def josephus_weekday():
    index=constant-1
    i=0
    while i<5:
        print(f"member[{week[i]}]:{weekday.pop(index)}")
        index=(index+constant-1)%len(weekday)
        i+=1
def josephus_weekend():
    index=constant-1
    i=5
    while i<7:
        print(f"member[{week[i]}]:{weekend.pop(index)}")
        index=(index+constant-1)%len(weekend)
        i+=1

num=int(input("평일 당직이 가능한 사람 수: "))

for i in range(num):
    weekday.append(input("평일 당직이 가능한 사람 이름: "))
constant=int(input("constant factor: "))
print('========평일========')
print(weekday)
print('====================')
josephus_weekday()
print('====================')
num=int(input("주말 당직이 가능한 사람 수: "))
for i in range(num):
    weekend.append(input("주말 당직이 가능한 사람 이름: "))
constant=int(input("constant factor: "))
print('========주말========')
print(weekend)
print('====================')
josephus_weekend()

        
