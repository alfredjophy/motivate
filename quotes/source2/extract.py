#!/bin/python

import json

f=open("1.json",'r')
quotes=json.load(f)

data=[]

for i in quotes:
    newQuote={"quote" : i["body"],"author": i["source"]}
    data.append(newQuote)
json_data=json.dumps(data)

print(json_data)


