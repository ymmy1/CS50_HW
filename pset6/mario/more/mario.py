from cs50 import get_int
# While loop
while True:
    n = get_int("Height: ")
    
    if n > 0 and 9 > n:
        # Number of rows
        for i in range(n):
            # Number of spaces
            for s in range(n-1): 
                print(" ", end="")
            # Number of #
            for j in range(i + 1): 
                print("#", end="")
            for s in range(2):
                print(" ", end="")
            for j in range(i + 1): 
                print("#", end="")
            # Decreasing
            n = n - 1 
            print()
        exit(0)