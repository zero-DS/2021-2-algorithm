tree = [-1,60,41,74,16,53,65,-1,-1,25,46,55,63,70,-1,-1,-1,-1,-1,-1,42,-1,-1,-1,62,64,-1,-1,-1,-1,-1,-1]
def traversal(start,type):
    global tree
    if tree[start]==-1: return

    if type==0: print(tree[start],end=' ')
    if start*2<len(tree): traversal(start*2,type)
    if type==1: print(tree[start],end=' ')
    if start*2+1<len(tree): traversal(start*2+1,type)
    if type==2: print(tree[start],end=' ')
def printTree(start):
    global tree
    if tree[start]==-1:
        print("N",end='')
        return
    print(tree[start],end='')
    if start*2<32: 
        print("(",end='')
        printTree(start*2)
        print(",",end='')
    if start*2+1<32:
        printTree(start*2+1)
        print(")",end='')

printTree(1)
print("\n전위순회 : ",end='')
traversal(1,0)
print("\n중위순회 : ",end='')
traversal(1,1)
print("\n후위순회 : ",end='')
traversal(1,2)