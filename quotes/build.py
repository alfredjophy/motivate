#!/bin/python
import json
import pickle

f=open("quotes.json")
quotes=json.load(f)

q_dat=open("quotes.min","w")

for i in quotes:
    quote=i["quote"]
    author=i["author"]

    q_dat.write("\n`\n")
    q_dat.write(quote)
    q_dat.write("\0")
    q_dat.write("\n`\n")
    q_dat.write(author)
    q_dat.write("\0")
