import time
print("곱셈을 할 두 수를 입력하세요 : ",end='')
two=input().split()
N=int(two[0])
M=int(two[1])
sum=0
def RPM(n,m):
    global sum
    if n==1:
        sum+=m
        return
    if n%2==0:
        RPM(n/2,m*2)
    else:
        sum+=m
        RPM((n-1)/2,m*2)
start1=time.time()
general=N*M
end1=time.time()
start2=time.time()
RPM(N,M)
end2=time.time()
print("%d X %d = %d" %(N,M,sum))
print("일반 곱셈 실행 시간 x 100 : ",(end1-start1)*100)
print("Russian Peasant 곱셈 실행 시간 x 100: ",(end2-start2)*100)