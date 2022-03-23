class Node:
    def __init__(self, data):
        self.next = None
        self.data = data


class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def enqueue(self, newnode):
        self.size += 1

        if self.rear == None:
            self.rear = newnode
            self.front = newnode

        else:
            self.rear.next = newnode
            self.rear = newnode
    
    def dequeue(self):
        if self.size == 0:
            print("cannot dequeue")
        else:
            self.size -= 1
            #print("dequeue : %s"%(self.front.data))
            temp = self.front.next
            return_val = self.front.data
            del self.front
            self.front = temp
            return return_val
        if self.front == None:
            self.rear = None


queue = Queue()
n = int(input("number : "))
k = int(input("factor : "))

for i in range(1, n+1):
    queue.enqueue(Node(i))


weekday = []
weekend = []

count = 0

while queue.size != 1:
    for i in range(k-1):
        temp = queue.dequeue()
        queue.enqueue(Node(temp))
    input_val = queue.dequeue()
    if count%7 == 5 or count%7 == 6 :
        weekend.append(input_val)
    else:
        weekday.append(input_val)
    count+=1


temp = queue.dequeue()
if count%7 ==5 or count%7 ==6:
    weekend.append(temp)
else:
    weekday.append(temp)
    
print("평일 당직 : ", weekday)
print("주말 당직 : ", weekend)

#제가 구현한 것이 의도하신 바가 맞는지 모르겠습니다..