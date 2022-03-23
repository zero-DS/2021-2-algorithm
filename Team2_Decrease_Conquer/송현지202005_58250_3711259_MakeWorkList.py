class DayList:
    def __init__(self):
        self.Mon=[]
        self.Tue=[]
        self.Wed=[]
        self.Thur=[]
        self.Fri=[]

    def AddPerson(self, name, day):
        if day==0:
            self.Mon.append(name)
        elif day==1:
            self.Tue.append(name)
        elif day==2:
            self.Wed.append(name)
        elif day==3:
            self.Thur.append(name)
        elif day==4:
            self.Fri.append(name)

    def PrintList(self):
        print("Mon >>", self.Mon)
        print("Tue >>", self.Tue)
        print("Wed >>", self.Wed)
        print("Thur >>", self.Thur)
        print("Fri >>", self.Fri)

def MakeWorkList(datalist, const):
    index=0
    cnt=0
    daylist=DayList()
    while len(datalist)>0:
        index=(index+const-1)%(len(datalist))
        daylist.AddPerson(datalist[index], cnt%5)
        cnt=cnt+1
        del datalist[index]
    daylist.PrintList()

peoplelist=[]
"""
#명단이 담긴 txt파일 이름은 입력을 받을 수도 있음
File_name=input("MakeWorkList에 사용할 명단 txt파일 이름 >> )
"""
File_name="NameList.txt"
File=open(File_name, "r", encoding="utf-8")
names=File.read()
peoplelist=names.rstrip("\n").split(",")
File.close()

step=int(input("MakeWorkList에 사용할 const factor 입력 >> "))
MakeWorkList(peoplelist, step)
