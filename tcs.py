import datetime

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def find_next_rainy_day(date, n, dow):
    current_date = datetime.datetime.strptime(date, '%Y%m%d')
    current_dow = current_date.strftime('%a')
    days_to_next_rain = 0

    while n > 0:
        current_date += datetime.timedelta(days=1)
        current_dow = current_date.strftime('%a')
        current_month = current_date.strftime('%b')
        days_to_next_rain += 1

        if is_prime(days_to_next_rain) and current_month in ['Feb', 'Mar', 'May', 'Jul', 'Nov']:
            if current_dow == dow:
                return f'Yes {days_to_next_rain}'

    return f'No {days_to_next_rain}'

# Input
input_data = input().split()
date = input_data[0]
dow = input_data[1]
n = int(input_data[2])

result = find_next_rainy_day(date, n, dow)
print(result)
