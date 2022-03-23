global matchCount #한 댓글에서 키워드와 일치한 횟수를 카운트하는 변수
def stringMatching(comment,target): #string matching하는 함수, 키워드와 일치하는 부분이 있으면 그 부분을 '-'로 대체함
    global matchCount
    for i in range(0,len(comment)):
        new=''
        for j in range(0,len(target)):
            if i+j==len(comment) or list(comment)[i+j]!=list(target)[j]: #한 글자라도 다르면 반복문 탈출, 댓글의 다음 글자로
                break
            if j==len(target)-1:
                matchCount+=1
                for k in range(0,i):
                    new=new+list(comment)[k]
                for k in range(i,i+len(target)):
                    new=new+'-'
                for k in range(i+len(target),len(comment)):
                    new=new+list(comment)[k]
                comment=new
    return comment

def censoring(comments, censorTargets): #모든 댓글과 모든 걸러낼 키워드를 조합해가며 string matching을 시도하는 함수
    global matchCount
    for i in range(len(comments)):
        matchCount=0
        for j in range(len(censorTargets)):
            comments[i]=stringMatching(comments[i],censorTargets[j])
        new=''
        if matchCount > 1: #한 댓글에서 키워드를 두 번 이상 걸러냈다면 댓글 전체를 가림
            for k in list(comments[i]):
                new=new+'-'
            comments[i]=new
    

censorTargets=[] #걸러낼 키워드 저장 배열
comments=[] #사용자 댓글 저장 배열

print("~~유해 댓글 필터링 프로그램~~")
num1=int(input("걸러낼 단어 키워드의 개수를 입력하시오 : "))
print("걸러낼 단어 키워드의 입력을 시작합니다. '엔터키'를 누를 때마다 키워드의 입력이 구분됩니다.")
for i in range(num1):
    censorTargets.append(input("입력 : "))

num2=int(input("사용자 댓글의 개수를 입력하시오 : "))
print("사용자 댓글의 입력을 시작합니다. '엔터키'를 누를 때마다 댓글의 입력이 구분됩니다.")
for i in range(num2):
    comments.append(input("입력 : "))

censoring(comments,censorTargets) #걸러내기

print("\n걸러낸 결과 : ",comments)




