#import array as remainder
remainder = []
digitlist= []
card_number = int(input("Please enter credit card number:"))
i=0
while card_number != 0:
    remainder.append(card_number % 10)
    card_number = (card_number-remainder[i])
    card_number = card_number/10
    i += 1
print(remainder)

checksum =0

for n in range(1,len(remainder),2):
    digit = 2*remainder[n]

    if digit >= 10:
        remain2 = digit % 10
        digit = (digit-remain2)/10
        digit += remain2

    checksum += digit

top = 0

for n in range(0,len(remainder),2):
    top = top + remainder[n]

finalsum = top + checksum
print(finalsum)

if finalsum % 10 == 0:
    if len(remainder)==15 and remainder[-2]==3 and (remainder[-3]==4 or remainder[-3]==7):
        print("AMEX")
        
    elif len(remainder) == 16 and remainder[-1] == 5:
        print("MASTERCARD")
        
    elif (len(remainder)==13 or len(remainder)==16) and remainder[-1]==4:
        print("VISA")
        
else:
    print("Invalid")
    
