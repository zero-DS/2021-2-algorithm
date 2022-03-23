arr=[
[0, 1, 1, 1, 0, 0, 0],
[0, 0, 0, 1, 1, 0, 0],
[0, 0, 0, 0, 0, 1, 0],
[0, 0, 1, 0, 0, 1, 1],
[0, 0, 0, 1, 0, 0, 1],
[0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 1, 0]
]
def warshall(size):
    global arr
    for i in range(size):
        for j in range(size):
            for k in range(size):
                if i==j or i==k: continue
                if arr[i][j]==1 and arr[k][i]==1:
                    arr[k][j]=1
size=len(arr)
print("Adjacency Matrix ->")
for i in range(size):
    for j in range(size):
        print(arr[i][j],end=' ')
    print()
warshall(size)
print("Transitive Closure ->")
for i in range(size):
    for j in range(size):
        print(arr[i][j],end=' ')
    print()