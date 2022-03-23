def greedyChange(money):
    if money<0:
        print("돈이 부족합니다.")
        return
    print("총 거스름돈 -> %d원"%(money))
    units=[50000,10000,5000,1000,500,100,50,10]
    num=[0,0,0,0,0,0,0,0]
    for i in range(len(units)):
        num[i]=int(money/units[i])
        money-=num[i]*units[i]
    for i in range(len(units)):
        print("%5d원 %2d개"%(units[i],num[i]))
prize=int(input("물건의 가격을 입력하세요 : "))
paidMoney=int(input("지불한 가격을 입력하세요 : "))
greedyChange(paidMoney-prize)