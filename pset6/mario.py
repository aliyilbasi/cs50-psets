max = 8
n= int(input("Enter positive number:"))

if n > 0 and n < 9:
    for i in range(n):
        print((max-(n+i))*" ",(i+1)*"#",(i+1)*"#")
