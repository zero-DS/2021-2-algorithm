import time
import random
import sys
sys.setrecursionlimit(10**5)
sorted=[]
mergeCnt=0
arr=[]
for i in range(50):
    arr.append(random.randint(1,100))
    sorted.append(0)

def mergeNsort(arr,left,mid,right):
    global sorted,mergeCnt
    i=left
    j=mid+1
    s=left
    while True:
        if arr[i]<arr[j]:
            sorted[s]=arr[i]
            i+=1
            s+=1
        else :
            sorted[s]=arr[j]
            j+=1
            s+=1
        if i>mid or j>right:
            break
    if i>mid:
        for k in range(j,right+1):
            sorted[s]=arr[k]
            s+=1
    elif j>right:
        for k in range(i,mid+1):
            sorted[s]=arr[k]
            s+=1
    for k in range(left,right+1):
        arr[k]=sorted[k]

    mergeCnt+=1
    print(mergeCnt,"번째 merge -> ",end='')
    for i in range(50):
        if i==left:
            print("[",end='')
        print(arr[i],end='')
        if i==right:
            print("]",end='')
        else :
            print(" ",end='')
    print()

def divide(arr,left,right):
    if left<right:
        mid=int((left+right)/2)
        divide(arr,left,mid)
        divide(arr,mid+1,right)
        mergeNsort(arr,left,mid,right)

start = time.time()
divide(arr,0,49)
end = time.time()
print("\nsorted result -> ",arr)
print("merge sort time : ",end-start)