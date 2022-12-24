#importing sys to access command line arguments
import sys
#assigning the number of arguements passed to count and count_1
count = count_1 = len(sys.argv)
total = 0
#Condition to check if agruements were passed
if len(sys.argv)==1:
    print("no arguments provided")
#while loop to calculate the total of the arguements
while count > 1:
    total += float(sys.argv[count])
    count -= 1
print("Total is", total)
#calculates average
average = total/count_1
print("Average is", average)