import random
ARR_SIZE=500
arr=[]
for i in range(ARR_SIZE):
    arr.append(random.randint(0,ARR_SIZE-1))

def select(arr,left,right,k):
    if left>=right: return
    pivot=arr[right]#맨 뒤 원소가 피벗
    low=left
    high=right-1
    while low<=high:
        while low<right and pivot>=arr[low] : low+=1
        while high>=left and pivot<=arr[high] : high-=1
        if low<=high : arr[low],arr[high] = arr[high],arr[low]
        else : arr[low],arr[right] = arr[right],arr[low]
    if(k==low):
        print("\n%d번째 원소는 %d"%(k,arr[k]))
    elif(low<k):
        select(arr,low+1,right,k)
    elif(low>k):
        select(arr,left,low-1,k)
        
k=int(input("몇 번째 원소를 찾고 싶은지 입력하세요 : "))
print(arr)
select(arr,0,ARR_SIZE-1,k)