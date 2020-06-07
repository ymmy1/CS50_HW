from cs50 import get_int
from math import floor

digit1 = 0
digit2 = 0
digit_count = 0
sum_of_double_odds = 0
sum_of_evens = 0
cc_number = get_int("Card Number: ")

while cc_number > 0:
    digit2 = digit1
    digit1 = cc_number % 10
    if digit_count % 2 == 0:
        sum_of_evens += digit1
    else:
        doubled = digit1 * 2
        sum_of_double_odds += (doubled % 10) + (doubled // 10)
    cc_number //= 10
    digit_count += 1
# Validation check
valid = (sum_of_double_odds + sum_of_evens) % 10 == 0
first_two_digits = digit1 * 10 + digit2
# VISA check
if digit1 == 4 and digit_count >= 13 and digit_count <= 16 and valid:
    print("VISA")
# MASTERCARD check
elif first_two_digits >= 51 and first_two_digits <= 55 and digit_count <= 16 and valid:
    print("MASTERCARD")
# AMEX CHECK
elif (first_two_digits == 34 or first_two_digits == 37) and digit_count >= 15 and valid:
    print("AMEX")
else:
    print("INVALID")