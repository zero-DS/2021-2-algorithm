N=int(input())
K=0
numbers=[]
for i in range(N):
    numbers.append(input())
length=len(numbers[0])
def cutcmp(arr,size):
    global length, N, K
    if size>length: return
    proceed=0
    for i in range(0,N-1):
        for j in range(i+1,N):
            temp1=(arr[i])[length-1:length-size-1:-1]
            temp2=(arr[j])[length-1:length-size-1:-1]
            if temp1==temp2: 
                proceed=1
                break
        if proceed==1: break
    if proceed==0:
        K=size
        return
    else:
        if size==length: K=size
        cutcmp(arr,size+1)
cutcmp(numbers,1)
print(K)