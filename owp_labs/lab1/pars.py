import json
class Phone(object):
    def __init__(self , name = None , manufacturer = None , price = None ,rate = None , date = None):
        self.name = name
        self.manufacturer = manufacturer
        self.price = price
        self.rate = rate
        self.date = date

    def parseFromDict(self, dict):
        self.__init__(dict.get("name"), dict.get("manufacturer"), dict.get("price"), dict.get("rate"), dict.get("date"))
        return self

    def toString(self):
        _str = ""
        _str += self.name + '\n'
        _str += self.manufacturer + '\n'
        _str += str(self.price) + '\n'
        _str += str(self.rate) + '\n'
        _str += self.date + '\n'
        return _str

    def toDict(self):
        return {'name': self.name, 'manufacturer': self.manufacturer, 'price': self.price , 'rate':self.rate , 'date' :self.date}

def parseFIle(filename):
    file = open("Phone.json", "r")
    phones = json.load(file);
    print (phones)
    phone_list = []
    for i in phones:
        phone_list.append(Phone().parseFromDict(i))
    file.close()
    return phone_list

def parseRequest(request):
    dictionary = {}
    if request.find('=') == -1:
        return None
    for s in request.split('&'):
        arglist = s.split('=', 1)
        print (arglist);
        dictionary.update({arglist[0] : arglist[1]})
    print (dictionary)
    return dictionary

def getJson(request):
    if request == "all":
        file = open("Phone.json", "r")
        phones = json.load(file);
        return json.dumps(phones, sort_keys=True, indent=0)

    argdict = parseRequest(request)
    if argdict == None:
        return '[{"exception" : "wrong args"}]'
    phonelist = parseFIle("Phone.json")
    newPhoneList = phonelist.copy()
    for phone in phonelist:
        for key, value in argdict.items():
            if key == "name":
                if phone.name != value:
                    print("name")
                    newPhoneList.remove(phone)
                    break
            elif key == "manufacturer":
                if phone.manufacturer != value:
                    print("manufacturer")
                    newPhoneList.remove(phone)
                    break
            elif key[-1:] == '<':
                if key.find("price") == 0:
                    if phone.price >= int(value):
                        print("price<")
                        newPhoneList.remove(phone)
                        break
                elif key.find("rate") == 0:
                    if phone.rate >= int(value):
                        print("rate<" + phone.name)
                        newPhoneList.remove(phone)
                        break
            elif key[-1:] == '>':
                if key.find("rate") == 0:
                    if phone.rate <= int(value):
                        print("rate>" + phone.name)
                        newPhoneList.remove(phone)
                        break
                elif key.find("price") == 0:
                    if phone.price <= float(value):
                        print("price>")
                        newPhoneList.remove(phone)
                        break

            elif key == "date":
                if phone.date != value:
                    print("date")
                    newPhoneList.remove(phone)
                    break
            else:
                return '[{"exception" : "wrong args"}]'
    returnList = []
    for ph in newPhoneList:
        print(ph.toString())
        returnList.append(ph.toDict())
    return json.dumps(returnList, sort_keys=True, indent=0)
#print(getJson("agegt=100&squarelt=100"))



