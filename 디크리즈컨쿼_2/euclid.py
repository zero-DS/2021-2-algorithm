result=-1
def GCD(m,n):
    global result
    if n!=0: r=m%n
    print("m = %d n = %d"%(m,n))
    if n==0:
        result=m
        return
    m=n
    n=r
    GCD(m,n)
print("최대공약수를 구할 두 수를 입력하세요 : ",end='')
mn=input().split()
m=int(mn[0])
n=int(mn[1])
GCD(m,n)
print("GCD =",result)