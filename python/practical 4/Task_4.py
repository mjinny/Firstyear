#Task 1
import math
print("Square root of 2401 is", math.sqrt(2401))

#Task 2
from math import log2
print("\nlog base 2 value of 1024 is", log2(1024),"\n")

#Task 3
def displayTwice(msg):
    print(msg)
    print(msg)
displayTwice("Display this message twice.\n")

#Task 4
def displayTwice(msg):
    """Function to display a message twice."""
    print(msg)
    print(msg)
displayTwice("Display this message twice.\n")
help(displayTwice)

#Task 5
def findMax(a,b):
    """Finds the maximum of two values."""
    if ( a > b ):
        max = a
    else:
        max = b
    return max
print("Maximum number is", findMax(5,7))
print("Maximum number is", findMax(9,5))
print("\n")
#Task 6
def mul(a,b=None):
    product=a*b

#Task 7
def someFunc(x, y, z):
    print("x is", x, "\ny is", y, "\nz is", z)
someFunc(4,5,6)
print("\n")
someFunc(z=9,x=5,y=7)

#Task 8
# def showMsg(title, body="", prefix="INFO", suffix="."):
#     print(prefix,title,body,suffix)
#     showMsg("File opened")
# showMsg("File not opened", prefix="ERROR" )
# showMsg("File missing", body="Insert Disk", suffix="Press return")

#Task 9
def calcAve(*numbers):
    total = 0
    for num in numbers:
        total += num
    return total/len(numbers)
print("\nAverage is ",calcAve(1,2,3))
print("\nAverage is ",calcAve(1,2,3,4,5,6,7))

#Task 10
hypot = lambda a,b : math.sqrt(a * a + b * b)
print("\n",hypot(3,4))
print(type(hypot))

#Task 11
to_seconds = lambda hour,second=0 : hour*60*60 + second*60
print("\n",to_seconds(0,2))
print(to_seconds(2))
