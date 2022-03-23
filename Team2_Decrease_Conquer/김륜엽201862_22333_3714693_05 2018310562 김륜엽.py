def night_shift(list, factor1, factor2):
    days = ["월요일","화요일","수요일","목요일","금요일","토요일","일요일"]
    shift_list = []
    week = list.copy()
    weekend = list.copy()
    week_idx = 0
    weekend_idx = 0

    input_idx = 0

    while len(week) != 0:
        if(input_idx % 7 == 0):
            print("------ %d 주차 ------"%(input_idx//7 + 1))
        print(days[input_idx%7], end="   ")

        if(input_idx % 7 <= 4):
            week_idx = (week_idx + factor1 - 1) % len(week)
            temp = week.pop(week_idx)
            print(temp)
            shift_list.append(temp)
        else:
            weekend_idx = (weekend_idx + factor2 - 1) % len(weekend)
            temp = weekend.pop(weekend_idx)
            print(temp)
            shift_list.append(temp)

        input_idx+=1

    print("----- 전체 순서 -----")
    print(shift_list)


Arr = ['병장 양병헌', '이병 구성은', '일병 곽승규', '상병 서동현', '일병 나선진', '이병 오승헌', '상병 나선진', '이병 박재혁', '병장 김륜엽', '일병 류승완', '병장 서동원', '병장 김민수', '병장 김정빈', '일병 김민수2', '상병 박규남', '병장 신동수']

night_shift(Arr, 5, 4)