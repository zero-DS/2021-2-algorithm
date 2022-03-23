one_thousand=[]
five_thousand=[]
ten_thousand=[]
fifty_thousand=[]
money_limit=0

def push(type,num):
    if is_full(type):
            print("해당 지폐통이 꽉 차있습니다. 재시도하세요")
            return
    if type==1000:
        for i in range(num):
            one_thousand.append(1000)
    elif type==5000:
        for i in range(num):
            five_thousand.append(5000)
    elif type==10000:
        for i in range(num):
            ten_thousand.append(10000)
    elif type==50000:
        for i in range(num):
            fifty_thousand.append(50000)
    else:
        print("\n올바른 지폐 단위가 아닙니다.\n")

def pop(type,num):
    sum=0
    if is_empty(type):
            print("해당 지폐통이 이미 비어있습니다. 재시도하세요")
            return
    if type==1000:
        for i in range(num):
            sum+=one_thousand.pop()
        return sum
    elif type==5000:
        for i in range(num):
            sum+=five_thousand.pop()
        return sum
    elif type==10000:
        for i in range(num):
            sum+=ten_thousand.pop()
        return sum
    elif type==50000:
        for i in range(num):
            sum+=fifty_thousand.pop()
        return sum
    else:
        print("\n올바른 지폐 단위가 아닙니다.\n")

def count(type):
    if type==1000:
        return len(one_thousand)
    elif type==5000:
        return len(five_thousand)
    elif type==10000:
        return len(ten_thousand)
    elif type==50000:
        return len(fifty_thousand)
    else:
        print("\n올바른 지폐 단위가 아닙니다.\n")

def is_full(type):
    if type==1000:
        if len(one_thousand)==money_limit:
            return True
        else : return False
    elif type==5000:
        if len(five_thousand)==money_limit:
            return True
        else : return False
    elif type==10000:
        if len(ten_thousand)==money_limit:
            return True
        else : return False
    elif type==50000:
        if len(fifty_thousand)==money_limit:
            return True
        else : return False
    else:
        print("\n올바른 지폐 단위가 아닙니다.\n")

def is_empty(type):
    if type==1000:
        if len(one_thousand)==0:
            return True
        else : return False
    elif type==5000:
        if len(five_thousand==0):
            return True
        else : return False
    elif type==10000:
        if len(ten_thousand)==0:
            return True
        else : return False
    elif type==50000:
        if len(fifty_thousand)==0:
            return True
        else : return False
    else:
        print("\n올바른 지폐 단위가 아닙니다.\n")

def print_interface():
    print("====== 자판기 프로그램 ======")
    print("=1. 돈 넣기                 =")
    print("=2. 돈 빼기                 =")
    print("=3. 돈 세기                 =")
    print("=4. 통이 비었는지 확인      =")
    print("=5. 통이 꽉찼는지 확인      =")
    print("=6. 프로그램 종료           =")
    print("=============================")
#main
flag=1
money_limit=int(input("지폐 통의 크기를 입력해주세요: "))
while(flag):
    print_interface()
    cmd=int(input("원하시는 메뉴의 번호를 입력해주세요: "))
    if cmd==1:
        money_type=int(input("넣으시려는 지폐의 종류를 입력하세요: "))
        money_num=int(input("넣으시려는 지폐의 개수를 입력하세요: "))
        push(money_type,money_num)
    elif cmd==2:
        money_type=int(input("뻬려는 지폐의 종류를 입력하세요: "))
        money_num=int(input("빼려는 지폐의 개수를 입력하세요: "))
        print(pop(money_type,money_num),"원 인출되었습니다.")
    elif cmd==3:
        money_type=int(input("세려는 지폐의 종류를 입력하세요: "))
        print(count(money_type),"장 존재합니다.")
    elif cmd==4:
        money_type=int(input("통이 비었는지 확인할 지폐의 종류를 입력하세요: "))
        if is_empty(money_type):
            print("비어있습니다.")
        else:
            print("비어있지 않습니다.")
    elif cmd==5:
        money_type=int(input("통이 꽉찼는지 확인할 지폐의 종류를 입력하세요: "))
        if is_full(money_type):
            print("꽉차있습니다.")
        else:
            print("꽉차있지 않습니다.")
    elif cmd==6:
        print("프로그램을 종료합니다.")
        flag=0
    else:
        print("유효한 메뉴번호가 아닙니다. 재시도하세요")