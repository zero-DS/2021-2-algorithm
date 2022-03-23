def karatsuba(x,y):
    B=10
    m=-1
    len1=len(str(abs(x)))
    len2=len(str(abs(y)))
    if len1<len2: m=len1
    else: m=len2
    if m<2: return x*y
    m=int(m/2)

    x1=x//(B**m)
    x0=x%(B**m)
    y1=y//(B**m)
    y0=y%(B**m)

    L=karatsuba(x1,y1)
    N=karatsuba(x0,y0)
    M=L+N-karatsuba((x1-x0),(y1-y0))
    return L*(B**(m*2)) + M*(B**m) + N

x=100
y=2020
print("%d * %d = %d" %(x,y,karatsuba(x,y)))