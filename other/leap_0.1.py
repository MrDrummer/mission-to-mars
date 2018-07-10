import datetime

def isLeap(date):
    
    if ((date / 4).is_integer() and not (date / 100).is_integer()) or (date / 400).is_integer():
        print ("date is a Leap Year!")
        return True
    
    return False
    
#isLeap(datetime.datetime.now().year)
print (isLeap(2013))
