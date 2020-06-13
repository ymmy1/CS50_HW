import sys
from cs50 import SQL

# validating the arguments
if len(sys.argv) != 2:
    print("Usage python roster.py house")
    exit(1)
# setting db
db = SQL("sqlite:///students.db")

stName = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first",
                    sys.argv[1])
# outprint
for i in range(0, len(stName), 1):
    print(stName[i]["first"], end=' ')
    # if person has middle name, print middle name
    if stName[i]["middle"]:
        print(stName[i]["middle"], end=' ')
    print(stName[i]["last"], end=', ')
    print(f"born {stName[i]['birth']}")