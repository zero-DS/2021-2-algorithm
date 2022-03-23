def MontoFri():
    count, num = map(int, input().split())      # 인원 수, constant factor 입력

    josephus = input().split()                  # 사람 명단 입력

    result = []                                 # 당직표를 담을 리스트
    seqNo = num - 1

    while len(josephus):
        if seqNo >= len(josephus):
            seqNo = seqNo % len(josephus)
        else:
            result.append(str(josephus.pop(seqNo)))
            seqNo += (num - 1)

    print("평일 당직표")
    print(result)

def Holiday():
    count, num = map(int, input().split())  # 인원 수, constant factor 입력

    josephus = input().split()  # 사람 명단 입력

    result = []  # 당직표를 담을 리스트
    seqNo = num - 1

    while len(josephus):
        if seqNo >= len(josephus):
            seqNo = seqNo % len(josephus)
        else:
            result.append(str(josephus.pop(seqNo)))
            seqNo += (num - 1)


    print("주말 당직표")
    print(result)

# 실행
MontoFri()
Holiday()


