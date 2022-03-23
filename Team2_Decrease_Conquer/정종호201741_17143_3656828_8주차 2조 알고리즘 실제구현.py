#8주차 2조 알고리즘 실제 구현

#어차피 사람의수는 len함수를 통해 구할수있으므로 인풋에 넣지않음

weekdays=[] #평일 당직 명단
weekdays_order=[] #평일 당직 순서
weekend=[] #주말 당직 명단
weekend_order=[] #주말 당직 순서

for  i in range(1,41):
    weekdays.append(i)

for  i in range(1,41):
    weekend.append(i)


def order_weekdays(weekdays,m,remain): #평일 용 알고리즘
    if len(weekdays)==1:
        print(weekdays)
        weekdays_order.append(weekdays[0])
        return weekdays

    weekdays_copy=weekdays.copy()

    for i in range(len(weekdays)):
        try:
            weekdays_order.append(weekdays[m*i+(m-1-remain)])
            weekdays_copy.remove(weekdays[m*i+(m-1-remain)])
        except IndexError:
            print(weekdays_copy)
            break
    
    remain2=(remain + len(weekdays) % m) %m

    order_weekdays(weekdays_copy,m,remain2)

def order_weekend(weekend,m,remain): #주말용 알고리즘
    if len(weekend)==1:
        print(weekend)
        weekend_order.append(weekend[0])
        return weekend

    weekend_copy=weekend.copy()

    for i in range(len(weekend)):
        try:
            weekend_order.append(weekend[m*i+(m-1-remain)])
            weekend_copy.remove(weekend[m*i+(m-1-remain)])
        except IndexError:
            print(weekend_copy)
            break
    
    remain2=(remain + len(weekend) % m) %m

    order_weekend(weekend_copy,m,remain2)


order_weekdays(weekdays,3,0)

order_weekend(weekend,4,0)

print(weekdays_order)
print(weekend_order)