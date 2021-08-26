#!/bin/python

import json

data=[]

for i in range(1,183) :
    
    name=""
    if i < 10:
        name="00"
    elif i < 100:
        name="0"
    name+=str(i)
    
    f=open(name+".json",'r')
    quotes=json.load(f)
    
    for j in quotes["data"]:
        newQuote={"quote" : j["quote"],"author" : j["author"]}
        data.append(newQuote)

json_data=json.dumps(data,indent=4,sort_keys=True)

k=open("quotes.json","w")
k.write(json_data)


