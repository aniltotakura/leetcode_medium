
product = 1
for i in range(5000,1,-1):
    product = product * i;


for number in range (1, 4999 + 1):  
    if number > 1:  
        for i in range (2, number):  
            if (number % i) == 0:  
                break  
        else:  
            print (product % number)