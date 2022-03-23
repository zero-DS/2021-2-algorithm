num=int(input("해결하고자 하는 연립방정식의 미지수의 개수를 입력하세요 : "))
simulEquation=[]
for i in range(num):
    lst=[0]*(num+1)
    simulEquation.append(lst)
for i in range(num):
    print(i+1,"번째 방정식의 계수들을 입력하세요 ex) 2x+3y=5 -> 2 3 5 : ",end='');
    str=input().split()
    for j in range(num+1):
        simulEquation[i][j]=int(str[j])
def GE(sEquation,num):
    for i in range(num):
        for j in range(i+1,num):
            factor=sEquation[j][i]/sEquation[i][i]
            for k in range(i,num+1):
                sEquation[j][k]-=sEquation[i][k]*factor
    print("Gaussian Elimination Result ->")
    for i in range(num):
        for j in range(num+1):
            print("%.2lf "%(sEquation[i][j]),end='')
        print()
    for i in range(num-1,-1,-1):
        for j in range(i-1,-1,-1):
            factor=sEquation[j][i]/sEquation[i][i]
            sEquation[j][i]-=sEquation[i][i]*factor
            sEquation[j][num]-=sEquation[i][num]*factor
GE(simulEquation,num)
print("Answer -> ")
for i in range(num):
    print("x%d = %.2lf"%(i,simulEquation[i][num]/simulEquation[i][i]))
    
