import copy
PRODUCT_COMPANY_NUM = 6
companyCnt=0
productName=["에어컨","실외기","냉장고","보일러","샷시","조명"]
companyName=["A","B","C","D","E","F"]
costArr= [
[0, 0, 0, 0, 0, 0, 0],
[0, 20, 12, 18, 12, 230, 37],
[0, 23, 14, 29, 14, 150, 43],
[0, 17, 16, 15, 12, 300, 40],
[0, 19, 13, 23, 11, 220, 35],
[0, 21, 15, 15, 14, 190, 30],
[0, 25, 14, 16, 13, 280, 31]
]
def selectProduct(pName):
    global costArr,productName,companyCnt
    for i in range(PRODUCT_COMPANY_NUM):
        if productName[i]==pName:
            if costArr[0][i+1]==1:
                print("해당 제품은 이미 입력하셨습니다.")
                return
            costArr[0][i+1]=1
            companyCnt+=1
            return
    for i in range(PRODUCT_COMPANY_NUM):
        print(productName[i],end=' ')
    print("만 입력 가능합니다.")
def selectCompany(c):
    global costArr,companyName
    for i in range(PRODUCT_COMPANY_NUM):
        if c==companyName[i]:
            if costArr[i+1][0]==1:
                print("해당 업체는 이미 입력하셨습니다.")
                return
            costArr[i+1][0]=1
            return
    for i in range(PRODUCT_COMPANY_NUM):
        print(companyName[i],end=' ')
    print("만 입력 가능합니다.")
def getArr(size):
    global costArr
    arr=[]
    for i in range(size):
        arr.append([])
        for j in range(size):
            arr[i].append(0)
    m=0
    n=0
    for i in range(1,PRODUCT_COMPANY_NUM+1):
        if costArr[i][0]==1:
            for j in range(1,PRODUCT_COMPANY_NUM+1):
                if costArr[0][j]==1:
                    arr[m][n]=costArr[i][j]
                    n+=1
            n=0
            m+=1
    return arr

while companyCnt<PRODUCT_COMPANY_NUM:
    pTemp=input("수리할 제품명을 입력하세요 : ")
    if pTemp=='Q': break
    selectProduct(pTemp)
for i in range(companyCnt):
    cTemp=input("원하는 업체 후보 %d은? "%(i+1))
    selectCompany(cTemp[len(cTemp)-1])   
visitedProduct=[0]*companyCnt
companyAssignedToProduct=[-1]*companyCnt
minArr=[]
minCost=-1

def checkFullAssigned(size):
    global visitedProduct
    for i in range(size):
        if visitedProduct[i]==0:
            return 0
    return 1
def checkMin(arr,size):
    global companyAssignedToProduct, minArr, minCost
    sum=0
    for i in range(size):
        sum+=arr[companyAssignedToProduct[i]][i]
    if minCost==-1:
        minCost=sum
        minArr=copy.copy(companyAssignedToProduct)
        return
    if minCost>sum:
        minCost=sum
        minArr=copy.copy(companyAssignedToProduct)
def assign(arr,size,company,product):
    global visitedProduct, companyAssignedToProduct, minArr
    if company==-1:
        for i in range(size):
            if visitedProduct[i]==0:
                assign(arr,size,company+1,i)
        return
    if company<size:
        visitedProduct[product]=1
        companyAssignedToProduct[product]=company
        if checkFullAssigned(size):
            checkMin(arr,size)
            visitedProduct[product]=0
            companyAssignedToProduct[product]=-1
            return
        for i in range(size):
            if visitedProduct[i]==0:
                assign(arr,size,company+1,i)
        visitedProduct[product]=0
        companyAssignedToProduct[product]=-1
def assignStart(size):
    global costArr,productName,companyName,minArr
    arr=getArr(size)
    newProName=[]
    newComName=[]
    for i in range(PRODUCT_COMPANY_NUM):
        if costArr[0][i+1]==1: newProName.append(productName[i])
        if costArr[i+1][0]==1: newComName.append(companyName[i])
    assign(arr,size,-1,0)
    print("업체 추천 조합 : ",end='')
    for i in range(size):
        print("(%s- 업체%c) "%(newProName[minArr[i]],newComName[i]),end=' ')
assignStart(companyCnt)
        