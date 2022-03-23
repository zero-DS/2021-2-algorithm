import time
import random
arr=[]
cnt=0
for i in range(100):
    arr.append(random.randint(1,1000))
def pivotDivide(arr,left,right):
    global cnt
    if left>=right: return
    cnt+=1
    print(cnt,"번째 과정 -> ",end='')
    for i in range(100):
        if i==left : print("[",end='')
        if i==right : print("p",end='')
        if i>=left and i<=right : print(arr[i],end=' ')
        if i==right : print("]")
    pivot=arr[right]#맨 뒤 원소가 피벗
    low=left
    high=right-1
    while low<=high:
        while low<right and pivot>=arr[low] : low+=1
        while high>=left and pivot<=arr[high] : high-=1
        if low<=high : arr[low],arr[high] = arr[high],arr[low]
        else : arr[low],arr[right] = arr[right],arr[low]
    pivotDivide(arr,left,low-1)
    pivotDivide(arr,low+1,right)
start=time.time()
pivotDivide(arr,0,99)
end=time.time()
print("sorted result -> ",arr)
print("quick sort time : ",end-start)