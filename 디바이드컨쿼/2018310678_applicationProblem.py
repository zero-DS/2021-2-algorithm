from math import pi
import random
import copy
judge=-1 #심판의 index
name=[] #이름 저장할 배열
arr=[]  #키 저장할 배열

def selectPivot(arr,left,right):
    sum=0
    average=0
    gap=10000000 #그냥 비교하기 위해 매우 큰값으로 초기화
    minGapIdx=-1
    for i in range(left,right+1):
        sum+=arr[i]
    average=sum/(right-left+1)
    for i in range(left,right+1):
        if abs(arr[i]-average)<abs(gap): #기존의 가장 평균에 가까웠던 사람보다 더 가까우면 갱신
            gap=arr[i]-average
            minGapIdx=i
    return minGapIdx  #제일 평균에 가까운 사람의 index 리턴

def pivotDivide(arr,left,right,step):
    global name
    global judge
    if left>=right: return
    pivotIdx=selectPivot(arr,left,right)
    arr[right],arr[pivotIdx] = arr[pivotIdx],arr[right]
    name[right],name[pivotIdx] = name[pivotIdx],name[right]
    low=left
    high=right-1
    while low<=high:
        while low<right and arr[right]>=arr[low] : low+=1
        while high>=left and arr[right]<=arr[high] : high-=1
        if low<=high:
            arr[low],arr[high] = arr[high],arr[low]
            name[low],name[high] = name[high],name[low]
        else:
            arr[low],arr[right] = arr[right],arr[low]
            name[low],name[right] = name[right],name[low]
    pivotDivide(arr,left,low-1,step+1)
    pivotDivide(arr,low+1,right,step+1)
    if step==0 and (right-left+1)%2==1:
        judge=low

def printTeam(arr,teamNum):
    if teamNum%2==0:            #팀인원이 짝수일때
        print("Team A -> ",end='')
        for i in range(0,int(teamNum/2),2):
            print(name[i],":",arr[i],end=' ')
        for i in range(int(teamNum/2),teamNum,2):
            if i+1 < teamNum: print(name[i+1],":",arr[i+1],end=' ')
        print("\nTeam B -> ",end='')
        for i in range(0,int(teamNum/2),2):
            if i+1 < int(teamNum/2): print(name[i+1],":",arr[i+1],end=' ')
        for i in range(int(teamNum/2),teamNum,2):
            print(name[i],":",arr[i],end=' ')
    
    else:                           #팀인원이 홀수일때
        print("Judge -> ",name[judge],":",arr[judge])
        for i in range(judge,teamNum-1):  #심판을 제외
            arr[i]=arr[i+1]
            name[i]=name[i+1]
        teamNum-=1 #제외시켰으니까 총 인원 수 1감소

        print("Team A -> ",end='')
        for i in range(0,int(teamNum/2),2):
            print(name[i],":",arr[i],end=' ')
        for i in range(int(teamNum/2),teamNum,2):
            if i+1 < teamNum: print(name[i+1],":",arr[i+1],end=' ')
        print("\nTeam B -> ",end='')
        for i in range(0,int(teamNum/2),2):
            if i+1 < int(teamNum/2): print(name[i+1],":",arr[i+1],end=' ')
        for i in range(int(teamNum/2),teamNum,2):
            print(name[i],":",arr[i],end=' ')

N=int(input("총 학생의 수를 입력하세요 : "))
print("각 학생의 키는 140~190으로 랜덤하게 부여됩니다.\n%d명의 학생의 이름을 차례대로 입력하세요 : " %N)
for i in range(N): 
    arr.append(random.randint(140,190)) #키 랜덤 배정
    print(i+1,end='')
    name.append(input("번째 학생 : "))    

pivotDivide(arr,0,N-1,0) #퀵정렬
printTeam(arr,N)         #두개로 나눠진 팀 출력. N이 홀수면 judge가 존재