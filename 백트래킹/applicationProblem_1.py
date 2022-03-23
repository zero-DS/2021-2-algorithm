PRODUCT_NUM = 29
PRODUCT_NAME_LIMIT = 101
productNameArr={
    "더블화이트갈릭팩":22100,"화이트갈릭팩":20600,"바삭킹&모짜볼10,까망베르치즈소스":16000,"몬스터X세트":11700,"통새우X세트":11000,
    "더블화이트갈릭와퍼세트":12200,"스태커2와퍼세트":10200,"기네스콰트로치즈와퍼세트":10700,"콰트로치즈와퍼세트":10100,"베이컨치즈와퍼세트":10100,
    "리얼와퍼세트":9300,"불고기와퍼세트":9300,"치즈와퍼세트":9900,"더블화이트갈릭와퍼":9900,"화이트갈릭와퍼":7900,"스태커2와퍼":9600,
    "리얼와퍼":7000,"치즈와퍼":7600,"통새우와퍼주니어":5800,"와퍼주니어":5200,"치즈와퍼주니어":5500,"앵그리너겟킹4조각":3100,"앵그리너겟킹6조각":4300,
    "치즈프라이":3300,"프렌치프라이(L)":3300,"프렌치프라이(R)":2400,"아이스아메리카노":2200,"코카콜라(L)":2700,"코카콜라(R)":2500
}
selected=[0]*PRODUCT_NUM
foundFlag=0
minOrderprice=int(input("최소주문금액을 입력하세요 : "))
orderPrice=minOrderprice
def printSatisfyingProducts(selected,orderPrice):
    global productNameArr,minOrderprice
    for i in range(PRODUCT_NUM):
        if selected[i]==1:
            print(productNameArr[i][0],end=' ')
    print("-->",end=' ')
    if orderPrice==minOrderprice:
        print("최소주문금액",end=' ')
    print("%d원 만족"%(orderPrice))
def priceSatisfy(selected,orderPrice,sum,currentProduct):
    global productNameArr,foundFlag
    if currentProduct>=PRODUCT_NUM: return
    if sum==orderPrice:
        foundFlag=1
        printSatisfyingProducts(selected,orderPrice)
        return
    if sum>orderPrice: return
    selected[currentProduct]=1
    sum+=productNameArr[currentProduct][1]
    priceSatisfy(selected,orderPrice,sum,currentProduct+1)
    selected[currentProduct]=0
    sum-=productNameArr[currentProduct][1]
    priceSatisfy(selected,orderPrice,sum,currentProduct+1)

productNameArr=sorted(productNameArr.items(),key=lambda x:x[1],reverse=True)
while foundFlag==0:
    selected=[0 for i in range(100)]
    priceSatisfy(selected,orderPrice,0,0)
    if foundFlag==0:
        if orderPrice==minOrderprice: print("최소주문금액인",end=' ')
        print("%d원을 만족하는 조합이 없습니다. 100원 올려서 다시 진행합니다."%(orderPrice))
        orderPrice+=100
