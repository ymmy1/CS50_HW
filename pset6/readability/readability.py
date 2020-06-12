import math

letterNumber = 0
wordNumber = 1
sentenceNumber = 0

text = input("Enter Your Text: ")
for i in range(0, len(text), 1):
    letter = text[i]
    space = text[i - 1]
    # Checking if first letter is a letter
    if letter.isalpha() == True:
        letterNumber += 1
    # Checking if space has a symbol or a word in front
    if (letter.isspace() == True and letter.isalpha() == True) or (letter.isspace() == True and letter.isalpha() == False):
        wordNumber += 1
    # "!", "?" and "." symbol check
    if letter == '!' or letter == '?' or letter == '.':
        sentenceNumber += 1
avgNumber = 100 / wordNumber
L = avgNumber * letterNumber
S = avgNumber * sentenceNumber
index = round(0.0588 * L - 0.296 * S - 15.8)
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
