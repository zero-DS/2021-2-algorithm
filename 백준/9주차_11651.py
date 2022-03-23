N=int(input())
nums=[]
for i in range(N):
    twonum=input().split()
    temp=[]
    temp.append(int(twonum[1]))
    temp.append(int(twonum[0]))
    nums.append(temp)
    
nums.sort()
for i in range(N):
    print("%d %d"%(nums[i][1],nums[i][0]))
