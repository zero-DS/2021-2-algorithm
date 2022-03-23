N=int(input("총 인원 수 입력: "))
K=int(input("constant factor 입력: "))
name=[]     # 사람명단
for i in range(N):
    name.append(input("이름{}입력: ".format(i+1)))
arr = [i for i in range(1,N+1)]    # 맨 처음에 원에 앉아있는 사람들의 인덱스

answer = []   # 제거된 사람들을 넣을 배열
num = 0  # 제거될 사람의 인덱스 번호

for t in range(N):
    num += K-1  
    if num >= len(arr):   # 한바퀴를 돌고 그다음으로 돌아올때를 대비해 값을 나머지로 바꿈  
        num = num%len(arr)
 
    answer.append(name[arr.pop(num)-1])
    
print()
print("당직표 출력")
for i in range(len(answer)):
    print(answer[i], end=' ')
    if i!=len(answer)-1:
        print('->',end=' ')