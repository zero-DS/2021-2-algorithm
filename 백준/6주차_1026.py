A=[]
B=[]
listnum=int(input())

A=input().split()
B=input().split()
A=list(map(int,A))
B=list(map(int,B))
A.sort()
B.sort(reverse=True)
sum=0
for i in range(listnum):
    sum+=A[i]*B[i]
print(sum)
