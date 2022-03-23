import time
import random
ARR_SIZE=10000
NUM_LIMIT=1000
arr=[]
for i in range(ARR_SIZE):
    arr.append(random.randint(0,NUM_LIMIT-1))
check=[]
for i in range(NUM_LIMIT):
    check.append(0)
def bruteForce():
    global arr,check
    for i in range(ARR_SIZE):
        if check[arr[i]]!=0: continue
        if i==ARR_SIZE-1:
            check[arr[i]]+=1
            break
        check[arr[i]]+=1
        for j in range(i+1,ARR_SIZE):
            if arr[i]==arr[j]:
                check[arr[i]]+=1
def preSorting():
    global arr
    arr.sort()
    cnt=0
    for i in range(ARR_SIZE-1):
        if arr[i]==arr[i+1]:
            cnt+=1
        else:
            print("(%d,%d)"%(arr[i],cnt+1),end='')
            cnt=0
    if arr[ARR_SIZE-1]==arr[ARR_SIZE-2]:
        print("(%d,%d)"%(arr[ARR_SIZE-1],cnt+1),end='')
    else:
        print("(%d,%d)"%(arr[ARR_SIZE-1],1),end='')
        
start1=time.time()
bruteForce()
for i in range(NUM_LIMIT):
    print("(%d,%d)"%(i,check[i]),end='')
end1=time.time()
print("\n")
start2=time.time()
preSorting()
end2=time.time()
print("\nbrute force time : %lf, presorting time : %lf"%(end1-start1,end2-start2))

    