from cs50 import get_float
import math

coins = 0
# while loop
while True:
    n = round(get_float("Change owed: ") * 100)
    if n >= 1:
        break

# finding the number of 25 coins 
for i in range(25, n + 1, 25):
    n = n - 25
    coins = coins + 1
# finding the number of 10¢ coins
for i in range(10, n + 1, 10):
    n = n - 10
    coins = coins + 1
# finding the number of 5¢ coins
for i in range(5, n + 1, 5):
    n = n - 5
    coins = coins + 1
# finding the number of 1¢ coins
for i in range(1, n + 1, 1):
    n = n - 1
    coins = coins + 1
    
print(coins)
exit(0)