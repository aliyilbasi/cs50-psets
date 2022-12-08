import csv
from sys import argv


if len(argv) != 3:
    print("missing command-line argument")
    exit(1)
    
    
with open (argv[1],"r") as file:
    reader=csv.reader(file)
    STR=next(reader)
    STR.pop(0)
    dictSTR = { i : 0 for i in STR }
    
    next(reader)
    for row1 in reader:
        names=row1[0]
    

file.close()

dna_file=open(argv[2],"r")
dnastr=[]
for row2 in dna_file:
    dnastr=row2

dna_file.close()    


for key in dictSTR:
   i=0
   temp=0
   cur_max=0
   while i < len(dnastr) :
        
        
        if  key == dnastr[i:i + len(key)] :
            temp +=1
            cur_max=max(cur_max,temp)
            dictSTR[key] = cur_max
            i += len(key)
         
        else:
             temp=0
             i += 1
         
         
         
        
print(dictSTR)

# i would like to see distribution of DNA codes as dictionary

#names=[]

value = []
for key in dictSTR:
 value.append(dictSTR[key]) 
# print(value)


with open (argv[1],"r") as file:
    
    reader = csv.reader(file)    
    next(reader)
    for row3 in reader:
       line=[int (val) for val in row3[1:]]
       
       if  line == value:
            print(row3[0])
            break
                
       else:
            print("No match")
                
            
            
                
