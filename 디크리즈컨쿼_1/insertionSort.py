print("정렬할 배열을 입력하세요 : ")
arr=input().split()
arr=list(map(int,arr))
N=len(arr)
checkNum=int(input("확인할 숫자를 입력하세요 : "))

def insertionSort(arr,left,right):
    global checkNum
    global N
    if left>right: return
    copy=arr[left]
    if copy==checkNum:
        print(checkNum,"를 삽입정렬하기 직전의 정렬 상태 : ")
        for i in range(N):
            print(arr[i],end=' ')
    
    k=left-1
    for i in range(left-1,-1,-1):
        if arr[i]>=copy:
            arr[i+1]=arr[i]
            k-=1
        else:
            arr[i+1]=copy
            break
    if k==-1: arr[0]=copy
    if copy==checkNum:
        print("\n%d 삽입 직후의 index : %d" %(checkNum,k+1))
    insertionSort(arr,left+1,right)

insertionSort(arr,0,N-1)
print("정렬한 결과 : ")
for i in range(N):
    print(arr[i],end=' ')


