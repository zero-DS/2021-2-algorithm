import time
import copy
valueArr=[]
weightArr=[]
binary=[]
maxBinary=[]
maxWeight=0
maxValue=0
maxOnes=0
num=int(input("knapsack's item limit 입력 : "))
weightLimit=int(input("item's weight limit 입력 : "))
print("각 item의 weight, value 입력")
for i in range(num):
    print(i+1,"번째 item 입력 :",end='')
    str=input()
    weightArr.append(int(str.split()[0]))
    valueArr.append(int(str.split()[1]))
    binary.append(0)
    maxBinary.append(0)

def printKnapsack(ones):
    if ones==0:
        print("Null")
        return
    global maxWeight
    global maxValue
    global maxOnes
    global binary
    global maxBinary
    global valueArr
    global weightArr
    global weightLimit
    global num
    weightSum=0
    valueSum=0
    cnt=0
    print("{",end='')
    for i in range(num):
        if binary[i]==1:
            weightSum+=weightArr[i]
            valueSum+=valueArr[i]
            print(i+1,end='')
            cnt+=1
            if cnt!=ones:
                print(",",end='')
    print("} ",end='')
    print("Total weight : %d " %weightSum,end='')
    if weightSum<=weightLimit:
        print("Total value : %d " %valueSum)
        if valueSum>=maxValue:
            if not(valueSum==maxValue and weightSum>maxWeight):
                maxValue=valueSum
                maxWeight=weightSum
                maxOnes=ones
                maxBinary=copy.copy(binary)

    else:
        print("not feasible")

def put_into_knapsack(start,p,ones):
    global binary
    if p==1:
        printKnapsack(ones)
    if not(start<num): return
    binary[start]=1
    if start<num:
        put_into_knapsack(start+1,1,ones+1)
    binary[start]=0
    if start<num:
        put_into_knapsack(start+1,0,ones)
start = time.time()
put_into_knapsack(0,1,0)
end = time.time()
print("optimal result -> ",end='')
cnt=0
print("{",end='')
for i in range(num):
    if maxBinary[i]==1:
        print(i+1,end='')
        cnt+=1
        if cnt!=maxOnes:
            print(",",end='')
print("} ",end='')
print("Total weight : %d Total value : %d" %(maxWeight,maxValue))
print("knapsack bruteforce time : ",end-start)
