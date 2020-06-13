from cs50 import SQL
import sys
import csv

open(f"students.db", "w").close()
db = SQL("sqlite:///students.db")
#  quick check if we have the right input
if len(sys.argv) != 2:
    print("Usage python import.py file.csv")
    exit(1)
# openning the header titles
with open(sys.argv[1], newline='') as f:
    reader = csv.reader(f)
    row1 = next(reader)
# opening file in the dictionary to execute later
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file)
    # create a table in database
    db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")
    # insert loop
    for row in reader:
        # splitting the name value
        splitNames = row[row1[0]].split(" ")
        if len(splitNames) == 2:
            db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)",
                       splitNames[0], splitNames[1],  row[row1[1]], row[row1[2]])
        if len(splitNames) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       splitNames[0], splitNames[1], splitNames[2],  row[row1[1]], row[row1[2]])
    print(f"**{sys.argv[1]} was succusessfully imported to students.db**")
    exit(0)
