#코드 진행은 단순한 코드로만 작성합니다
def checkSimilarity(norm, score, simNorm):
    m=len(norm)
    n=len(score)
    arr=[]
    for i in range(m+1):
        arr.append([])
        for j in range(n+1):
            arr[i].append(0)
    for i in range(1,m+1):
        for j in range(1,n+1):
            if norm[i-1]==score[j-1]:
                arr[i][j]=arr[i-1][j-1]+1
            else:
                if arr[i-1][j]<arr[i][j-1]:
                    arr[i][j]=arr[i][j-1]
                else:
                    arr[i][j]=arr[i-1][j]
    if arr[m][n]>=simNorm:
        print("%s (similar:%d/%d)"%(score,arr[m][n],len(score)))
        
scoreNorm=input("기준 악보 : ")
similarityPercentage=int(input("기준 유사도(%) : "))
similarityNorm=similarityPercentage*len(scoreNorm)/100
N=int(input("입력할 악보 개수 : "))
scoreList=[]
for i in range(N):
    print("%d번째 악보 입력 : "%(i+1),end='')
    scoreList.append(input())
print("=================akbo list=================")
for i in range(N):
    checkSimilarity(scoreNorm,scoreList[i],similarityNorm)
print("===========================================")