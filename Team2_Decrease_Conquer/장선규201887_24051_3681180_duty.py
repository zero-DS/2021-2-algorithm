def duty(people, k, is_weekend):
    day = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]
    week_type = "Weekdays"

    if is_weekend:
        day = ["Sunday", "Saturday"]
        week_type = "Weekend"

    DAYS = len(day)

    cycle = []
    p_list = people.copy()
    i = 0
    while p_list:
        i = (i + k - 1) % len(p_list)
        cycle.append(p_list.pop(i))

    loop = len(cycle) * DAYS if len(cycle) % DAYS else len(cycle)
    print(f"\n<{week_type} duty cycle>")
    for i in range(loop):
        print(f"{day[i%DAYS]}: {cycle[i%len(cycle)]}", end=" | ")
        if i % DAYS == DAYS - 1:
            print()
    print(".\n.\n.\n")


if __name__ == "__main__":
    n = int(input("N: "))
    people = []
    for i in range(n):
        people.append(input(f"person {i+1} name: "))

    k = int(input("Weekdays constant factor: "))
    duty(people, k, is_weekend=False)

    k = int(input("Weekend constant factor: "))
    duty(people, k, is_weekend=True)
