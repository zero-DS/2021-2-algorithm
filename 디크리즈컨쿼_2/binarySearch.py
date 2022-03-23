import random
arr=[]
for i in range(500):
    arr.append(random.randint(0,1000))
arr.sort()
flag=0
def binarySearch(arr, left, right, key):
    global flag
    if left<=right and flag==0:
        mid=int((left+right)/2)
        if arr[mid]<key:
            binarySearch(arr,mid+1,right,key)
        elif arr[mid]>key:
            binarySearch(arr,left,mid-1,key)
        else:
            print("%d 번째에 존재" %(mid))
            flag=1
print(arr)
while True:
    print("index를 알고자 하는 숫자를 입력하세요. 종료하고 싶으면 Q를 입력하세요 : ",end='')
    cmd=input()
    if cmd=='Q':
        print("이진 탐색 종료")
        break
    cmd=int(cmd)
    flag=0
    binarySearch(arr,0,499,cmd)
    if flag==0:
        print("%d는 존재하지 않습니다." %(cmd)) 