#!/bin/python
import sys,os,json

dirs=["source1","source2"]

combined=[]
for i in dirs:
    f=open(i+"/source.json",'r')
    quotes=json.load(f)
    for j in quotes:
        combined.append(j)

json_data=json.dumps(combined)

try :
    os.remove('quotes.json')
except:
   0 

c=open('quotes.json','w')

c.write(json_data)
