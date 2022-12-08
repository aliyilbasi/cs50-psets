from cs50 import get_string

text=get_string("Text:")

sentences=0
space=0
letters=0

for i in range(len(text)):
    if " "  in text[i]:
        space += 1
    elif '!'in text[i] or '.'in text[i] or '?'in text[i] :
        sentences += 1
    else:
        letters += 1
        
words=space+1

#print("letters:",letters)
#print("words:",words)
#print("sentences:",sentences)

L=(letters*100)/words
S=(sentences*100)/words
index = 0.0588*L-0.296*S-15.8

print(index)

X = round(index)

if X < 1:
    print("Before Grade 1")
elif X > 16:
    print("Grade 16+")
else:
    print("Grade",X)