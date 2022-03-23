class min_heap:
    def __init__(self,name):
        self.heap=[None]
        self.name=name
    def input(self,data):
        self.heap.append(data)
        i=len(self.heap)-1
        while i>1:
            if self.heap[i]<self.heap[i//2]:
                self.heap[i],self.heap[i//2]=self.heap[i//2],self.heap[i]
                i=i//2
            else: break
    def delete(self):
        size=len(self.heap)-1
        if size==0: return 0
        value=self.heap[1]
        self.heap[1]=self.heap[size]
        self.heap.pop()
        if size!=0: size=size-1
        i=1
        while i<=size:
            j=i*2
            if j+1>size: break
            if self.heap[i] < self.heap[j] and self.heap[i] < self.heap[j+1]: break
            if self.heap[j] > self.heap[j+1]: j=j+1
            self.heap[i],self.heap[j]=self.heap[j],self.heap[i]
            i=j
        return value
    def print(self):
        for i in range(len(self.heap)):
            print(self.heap[i],end=' ')
class heapSET:
    def __init__(self):
        self.heaplist=[]
        self.size=0
    def newProduct(self,name):
        self.heaplist.append(min_heap(name))
        self.size+=1

def bubbleSort(namearr,datearr,n):
    for i in range(n-1):
        for j in range(n-1):
            if namearr[j] > namearr[j+1]:
                namearr[j],namearr[j+1]=namearr[j+1],namearr[j]
                datearr[j],datearr[j+1]=datearr[j+1],datearr[j]

names=[]
expDate=[]
hset=heapSET()
N=int(input())
for i in range(N):
    lst=input().split()
    names.append(lst[0])
    expDate.append(int(lst[1]))
bubbleSort(names,expDate,N)
hset.newProduct(names[0])
hset.heaplist[hset.size-1].input(expDate[0])
for i in range(1,N):
    if names[i]!=names[i-1]:
        hset.newProduct(names[i])
        hset.heaplist[hset.size-1].input(expDate[i])
    else:
        hset.heaplist[hset.size-1].input(expDate[i])
print("찾으시려는 품목은 \"G 품목명\"으로 입력, 프로그램을 종료하려면 \"Q\"입력")
while True:
    foundName=0
    cmd=input().split()
    if cmd[0]=='Q':
        break
    elif cmd[0]=='G':
        for i in range(hset.size):
            if cmd[1]==hset.heaplist[i].name:
                deleted=hset.heaplist[i].delete()
                if deleted==0: print("-> 없어요!")
                else: print("->",hset.heaplist[i].name,deleted)
                foundName=1
                break
        if foundName==0:
            print("-> 없어요!")
    


