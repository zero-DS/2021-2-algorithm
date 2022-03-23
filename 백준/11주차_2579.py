N=int(input())
stairs=[0]
for i in range(N):
    stairs.append(int(input()))
arr=[0]*(N+1)

def dp(N,stairs,arr):
    arr[1]=stairs[1]
    if N==1: return
    arr[2]=stairs[1]+stairs[2]
    if N==2: return
    for i in range(3,N+1):
        arr[i]=stairs[i]+max(arr[i-2],arr[i-3]+stairs[i-1])
dp(N,stairs,arr)
print(arr[N])
    
    