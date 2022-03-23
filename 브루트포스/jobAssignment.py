import time
import copy
arr =[[13, 6, 7, 12, 14, 15, 10, 11, 15, 4],
    [8, 14, 11, 9, 6, 14, 7, 9, 16, 12],
    [10, 8, 10, 10, 8, 15, 11, 5, 7, 9],
    [13, 13, 16, 9, 13, 16, 15, 9, 14, 16],
    [11, 4, 9, 14, 12, 11, 5, 16, 8, 14],
    [7, 10, 12, 13, 4, 11, 16, 12, 15, 9],
    [6, 11, 10, 11, 13, 15, 7, 16, 11, 12],
    [7, 15, 5, 10, 4, 16, 12, 4, 10, 16],
    [5, 14, 10, 15, 8, 8, 8, 14, 14, 4],
    [8, 11, 4, 16, 8, 12, 4, 14, 9, 6]]
visitedJob=[]
personAssignedToJob=[]
minArr=[]
minCost=-1
for i in range(10):
    visitedJob.append(0)
    personAssignedToJob.append(-1)
def checkFullAssigned():
    global visitedJob
    for i in range(10):
        if visitedJob[i]==0:
            return 0
    return 1
def checkMin():
    global personAssignedToJob, arr, minArr, minCost
    sum=0
    for i in range(10):
        sum+=arr[personAssignedToJob[i]][i]
    if minCost==-1:
        minCost=sum
        minArr=copy.copy(personAssignedToJob)
        return
    if minCost>sum:
        minCost=sum
        minArr=copy.copy(personAssignedToJob)
def assign(person,job):
    global visitedJob, personAssignedToJob, minArr
    if person==-1:
        for i in range(10):
            if visitedJob[i]==0:
                assign(person+1,i)
        return
    if person<10:
        visitedJob[job]=1
        personAssignedToJob[job]=person
        if checkFullAssigned():
            checkMin()
            visitedJob[job]=0
            personAssignedToJob[job]=-1
            return
        for i in range(10):
            if visitedJob[i]==0:
                assign(person+1,i)
        visitedJob[job]=0
        personAssignedToJob[job]=-1
start = time.time()
assign(-1,0)
end = time.time()
for i in range(10):
    print("%d번째 job : person %d" %(i+1,minArr[i]+1))
print("-> minimum cost : ",minCost)
print("job assignment time : ",end-start)

