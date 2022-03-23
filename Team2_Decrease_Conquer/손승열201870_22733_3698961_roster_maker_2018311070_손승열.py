def roster(res,cf):
    global employee
    ord=list(employee)
    idx=0
    while len(ord)>0:
        idx=(idx+cf-1)%len(ord)
        res.append(ord[idx])
        del ord[idx]
    return
    

wk=["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
employee=[]
weekday=[]
weekend=[]

print("<--- Roster maker --->\n")
n=int(input("> The number of employee : "))
for i in range(n):
    name=input(f"> Name of Employee {i+1} : ")
    employee.append(name)
cfd=int(input("> Rotation Number(weekday) : "))
cfe=int(input("> Rotation Number(weekend) : "))

roster(weekday,cfd)
roster(weekend,cfe)

print("\n> -- Results --\n")
print("> - Weekday -\n")
for i in range(len(weekday)):
    print(wk[i%5],":",weekday[i])
print("\n> - Weekend -\n")
for i in range(len(weekend)):
    print(wk[(i%2)+5],":",weekend[i])