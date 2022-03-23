def GCD(a,b):
    while b!=0:
        a,b=b,a%b
    return a
def LCM(a,b):
    result=int((a*b)/GCD(a,b))
    return result
string=input("LCM을 구할 두 수를 입력하세요 : ").split()
print("%d와 %d의 LCM : %d"%(int(string[0]),int(string[1]),LCM(int(string[0]),int(string[1]))))

