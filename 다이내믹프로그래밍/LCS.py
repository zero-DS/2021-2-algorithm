def compare(word_a,word_b):
    m=len(word_a)
    n=len(word_b)
    arr=[]
    for i in range(m+1):
        arr.append([])
        for j in range(n+1):
            arr[i].append(0)
    for i in range(1,m+1):
        for j in range(1,n+1):
            if word_a[i-1]==word_b[j-1]:
                arr[i][j]=arr[i-1][j-1]+1
            else:
                if arr[i-1][j]<arr[i][j-1]:
                    arr[i][j]=arr[i][j-1]
                else:
                    arr[i][j]=arr[i-1][j]
    print("%s와 %s의 비교과정 ->"%(word_a,word_b))
    for i in range(1,m+1):
        for j in range(1,n+1):
            print(arr[i][j],end=' ')
        print()
    return arr[m][n]
word=input("LCS를 구할 단어를 입력하세요 : ")
words=input("%s와 비교할 두 단어를 차례대로 입력하세요 : "%(word)).split()
LCS_Result1=compare(word,words[0])
LCS_Result2=compare(word,words[1])
if LCS_Result1<LCS_Result2:
    print("%s는 %s와 더 유사합니다."%(word,words[1]))
elif LCS_Result1>LCS_Result2:
    print("%s는 %s와 더 유사합니다."%(word,words[0]))
else:
    print("%s는 %s, %s와 각각 동등하게 유사합니다."%(word,words[0],words[1]))
    