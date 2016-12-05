import json
from django.shortcuts import render_to_response ,redirect , render

phone_list = []
'''
def parseFIle(filename):
    file = open("Phone.json", "r")
    phones = json.load(file);
    print (phones)
    for i in phones:
        phone_list.append(Phone().parseFromDict(i))
    file.close()
    print(phone_list)
parseFIle("Phone.json")
'''

def getJson(request):
    file = open("Phone.json", "r")
    phones = json.load(file)
    return phones

def show(request):
    phones = getJson("Phone.json")
    return render( request , "show.html" , {'phones': phones})

def get(request , path):
    phones = getJson("Phone.json")
    phone = {}
    for i in phones:
        if i['id'] == int(path):
            phone = i
            break
    return render(request , "phone.html" , {'phone': phone})

