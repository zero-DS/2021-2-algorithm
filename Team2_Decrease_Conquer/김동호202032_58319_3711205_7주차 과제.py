import sys, collections

def Josephus(n, arr, k):
    queue = collections.deque(arr)
    for i in range(n):
        for j in range(k-1):
            queue.append(queue.popleft())
        if i == n-1:
            print(queue.popleft(), end='')
        else:
            print(queue.popleft(), end=', ')

print("평일 당직")
print("총 인원 수")
n = int(input(">> "))
print("사람 명단(띄어쓰기로 구분)")
arr = list(input(">> ").split())
print("constant factor")
k = int(input(">> "))

Josephus(n, arr, k)

print("주말 당직")
print("총 인원 수")
n = int(input(">> "))
print("사람 명단(띄어쓰기로 구분)")
arr = list(input(">> ").split())
print("constant factor")
k = int(input(">> "))

Josephus(n, arr, k)
