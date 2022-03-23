import random
import pandas
import math

def duty_choice(k, arr):
    """당직 짜기"""
    copy_list = arr.copy()
    turn = 0
    duty_order = []
    
    while len(copy_list) > 0:
        turn = (turn + k - 1) % len(copy_list)
        duty_order.append(copy_list.pop(turn))
    
    return duty_order

if __name__ == "__main__":
    N, K_week, K_weekend = map(int, input("직원수 입력 / 평일 constant factor 입력 / 주말 constant factor 입력>> ").split())

    # 직원 명단 생성
    staffs = []
    first_name_samples = "김이박최정강조윤장임"
    middle_name_samples = "민서예지도하주윤채현지"
    last_name_samples = "준윤우원호후서연아은진"
    for i in range(N):
        staffs.append(random.choice(first_name_samples) + random.choice(middle_name_samples) + random.choice(last_name_samples))

    week_order = duty_choice(K_week, staffs)
    weekend_order = duty_choice(K_weekend, staffs)

    # pandas 모듈을 사용하여 보기좋게 출렬
    col_week = ['월요일', '화요일', '수요일', '목요일', '금요일'] # 월요일 -> 금요일 순으로 배치했습니다.
    col_weekend = ['토요일', '일요일'] # 토요일 -> 일요일 순으로 배치했습니다.
    week = []
    weekend = []
    for i in range(math.ceil(N/5)):
        week.append(week_order[i*5:i*5 + 5])
    for j in range(math.ceil(N/2)):
        weekend.append(weekend_order[j*2:j*2 + 2])
    
    print("\n<평일당직>")
    print(pandas.DataFrame(week, columns=col_week))
    print("\n<주말당직>")
    print(pandas.DataFrame(weekend, columns=col_weekend))

    
    
    