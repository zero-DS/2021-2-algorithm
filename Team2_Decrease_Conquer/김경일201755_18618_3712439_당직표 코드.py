import pandas as pd
df=pd.read_excel('C:/Users/ruddl/OneDrive/문서/name.xlsx')
df_list = df.values.tolist()
df_list2=list()
for i in df_list :
    df_list2.append(i[0][0:3])

df_list2.sort()

print("<컴퓨터교육과 명단>")
for i, v in enumerate(df_list2) :
    print("순서 : {}, 이름 : {}".format(i+1,v))

n=len(df_list2)

def hi(n,k) :
    a= list(range(1,n+1))
    m=k-1
    b=0
    turn=1
    while(len(a)>1) :
        b=((len(a)+b)%k)
        for i in a[m::k] :
            print('Day : ',turn, ' / Person : ',i, df_list2[i-1])
            turn+=1
        del a[m::k]
        m = k - b - 1


    print('Day : ',turn, ' / Person : ',a[0], df_list2[a[0]-1])
    #return a

print("\n컴퓨터교육과 당직 명단은 다음과 같습니다.\n")
hi(n,3)