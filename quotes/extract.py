#!/bin/python
import sys,os,json,random

ls=os.listdir()
dirs=[]

for i in ls:
    if os.path.isdir(i):
        dirs.append(i)

combined=[]
for i in dirs:
    f=open(i+"/quotes.json",'r')
    quotes=json.load(f)
    for j in quotes:
        combined.append(j)

random.shuffle(combined)

json_data=json.dumps(combined,indent=4,sort_keys=True)

try :
    os.remove('quotes.json')
except:
   0 

c=open('quotes.json','w')

c.write(json_data)
