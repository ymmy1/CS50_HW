import sys
import csv
# future name counter, if equals to length exit(0)
names = {}
if len(sys.argv) == 3:
    # Openning header of csv, to get names of strs
    with open(sys.argv[1], newline='') as f:
        reader = csv.reader(f)
        row1 = next(reader)
        length = len(row1)
    # openning txt file with dna
    file = open(sys.argv[2], 'r')
    text = file.read()
    STRS = {}
    # adding str to dictionary STRS with the highest repetitive number
    for i in range(1, len(row1), 1):
        l = len(row1[i])
        str_count = 0
        highest_str_count = 0
        STR = row1[i]
        z = 0
        while z < len(text):
            found = STR == text[z:z+l]
            if found:
                str_count += 1
                z = z + l
            else:
                if str_count > highest_str_count:
                    highest_str_count = str_count
                str_count = 0
                z += 1
        STRS[STR] = highest_str_count
        # after added to STRS automatically checking for matches
        with open(sys.argv[1], newline='') as csvfile:
            namereader = csv.DictReader(csvfile)
            for row in namereader:
                # if str matched increase the name counter
                if int(STRS[STR]) == int(row[STR]):
                    if row['name'] in names:
                        names[row['name']] = int(names[row['name']]) + 1
                        # if name counter equals to the length of strs, means we matched the dna
                        if names[row['name']] == length - 1:
                            print(row['name'])
                            f.close()
                            file.close()
                            csvfile.close()
                            exit(0)
                    else:
                        names[row['name']] = 1
                else:
                    if row['name'] in names:
                        names[row['name']] = int(names[row['name']]) + 0
                    else:

                        names[row['name']] = 0
    # if no dna was matched
    print("No Match")
    f.close()
    file.close()
    csvfile.close()
    exit(0)
else:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)