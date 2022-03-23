class exam:
    def __init__(self,examName,startTime,endTime,peopleNum):
        self.examName=examName
        self.startTime=startTime
        self.endTime=endTime
        self.peopleNum=peopleNum
class classRoom:
    def __init__(self,classRoomNum):
        self.exams=[]
        self.examsInClassRoom=0
        self.classRoomNum=classRoomNum
        self.vacancy=1
def bubbleSort(examArr,examNum):
    for i in range(examNum-1):
        for j in range(examNum-1):
            if examArr[j].startTime > examArr[j+1].startTime:
                examArr[j],examArr[j+1]=examArr[j+1],examArr[j]
            elif examArr[j].startTime == examArr[j+1].startTime and examArr[j].endTime > examArr[j+1].endTime:
                examArr[j],examArr[j+1]=examArr[j+1],examArr[j]
def renewClassRoom(classRoomArr,currentTime,ventTime,currentPeopleNum):
    k=-1
    if currentPeopleNum<=20: k=0
    elif currentPeopleNum<=30: k=10
    elif currentPeopleNum<=60: k=20
    else: return
    for i in range(k,k+10):
        if classRoomArr[i].examsInClassRoom==0: continue
        if currentTime>=classRoomArr[i].exams[classRoomArr[i].examsInClassRoom-1].endTime + ventTime:
            classRoomArr[i].vacancy=1
def determineClassRoom(exam,classRoomArr):
    if exam.peopleNum<=20:
        for i in range(0,10):
            if classRoomArr[i].vacancy==1:
                classRoomArr[i].vacancy=0
                classRoomArr[i].exams.append(exam)
                classRoomArr[i].examsInClassRoom+=1
                break
    elif exam.peopleNum<=30:
        for i in range(10,20):
            if classRoomArr[i].vacancy==1:
                classRoomArr[i].vacancy=0
                classRoomArr[i].exams.append(exam)
                classRoomArr[i].examsInClassRoom+=1
                break
    elif exam.peopleNum<=60:
        for i in range(20,30):
            if classRoomArr[i].vacancy==1:
                classRoomArr[i].vacancy=0
                classRoomArr[i].exams.append(exam)
                classRoomArr[i].examsInClassRoom+=1
                break
    else:
        classRoomArr[30].exams.append(exam)
        classRoomArr[30].examsInClassRoom+=1
examNum=int(input("총 시험의 수를 입력하세요 : "))
ventTime=int(input("강의실을 환기할 시간을 정해주세요 : "))
examArr=[]
classRoomArr=[]
minimumClassRoom=0
for i in range(31):
    classRoomArr.append(classRoom(i+1))
for i in range(examNum):
    print("강의명, 시험의 시작 시간, 끝나는 시간, 시험인원을 차례대로 입력해주세요 : ",end='')
    string=input().split()
    examArr.append(exam(string[0],int(string[1]),int(string[2]),int(string[3])))
bubbleSort(examArr,examNum)
for i in range(examNum):
    renewClassRoom(classRoomArr,examArr[i].startTime,ventTime,examArr[i].peopleNum)
    determineClassRoom(examArr[i],classRoomArr)
for i in range(30):
    if classRoomArr[i].examsInClassRoom!=0: minimumClassRoom+=1
print("총 %d개 강의실이 필요합니다."%(minimumClassRoom),end='')
for i in range(30):
    if classRoomArr[i].examsInClassRoom!=0:
        print("\nCLASS %d : "%(classRoomArr[i].classRoomNum),end='')
        for j in range(classRoomArr[i].examsInClassRoom):
            print("%s(%d-%d) "%(classRoomArr[i].exams[j].examName,classRoomArr[i].exams[j].startTime,classRoomArr[i].exams[j].endTime),end='')
if classRoomArr[30].examsInClassRoom!=0:
    print("\n온라인 : ",end='')
    for j in range(classRoomArr[30].examsInClassRoom):
        print("%s(%d-%d) "%(classRoomArr[30].exams[j].examName,classRoomArr[30].exams[j].startTime,classRoomArr[30].exams[j].endTime),end='')

