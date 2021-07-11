#!/bin/python
file=open('quotes.txt','r')

data=file.readlines()

i=0
for line in data:
    i+=1
    if(i%2==0):
        print(i," ",line)
file.close()

