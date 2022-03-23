import random
arr=[]
ARR_SIZE=500
for i in range(ARR_SIZE):
    arr.append(random.randint(0,ARR_SIZE))
arr.sort()
def IPSearch(left,right,key):
    global arr
    if left>=right:
        if arr[left]==key:
            print("\n%d번째에 %d존재"%(left,key))
            return
        print("찾는 값이 존재하지 않습니다.")
        return
    pos=left+(key-arr[left])*int((right-left)/(arr[right]-arr[left]))
    if(arr[pos]==key):
        print("\n%d번째에 %d존재"%(pos,key))
    elif(arr[pos]<key):
        IPSearch(pos+1,right,key)
    elif(arr[pos]>key):
        IPSearch(left,pos-1,key)
key=int(input("찾고자 하는 값을 입력하세요 : "))
print(arr)
IPSearch(0,ARR_SIZE-1,key)