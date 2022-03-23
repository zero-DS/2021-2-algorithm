#2020314000 이석원

People = 32 #평일 당직
PeopleH = 12 #주말 당직

Josephus = [] #평일
JosephusH=[] #주말

cf = 3
cfH = 5

for i in range(1,33): #평일 당직자 이름 넣기
    Josephus.append(i)

for i in range(33,45): #주말 당직자 이름 넣기
    JosephusH.append(i)

Dangjik = []
DangjikH = []

idx = 0

while len(Josephus) > 0:
    idx = (idx + (cf-1)) % len(Josephus)
    person = Josephus.pop(idx)
    Dangjik.append(str(person))
print("평일 당직자 : ",end = '')
print("<%s>" %(", ".join(Dangjik)))


idx = 0 #인덱스 초기화

while len(JosephusH) > 0:
    idx = (idx + (cfH-1)) % len(JosephusH)
    person = JosephusH.pop(idx)
    DangjikH.append(str(person))

print("주말 당직자 : ",end = '')
print("<%s>" %(", ".join(DangjikH)))