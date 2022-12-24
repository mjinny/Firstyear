#Take user input
number = input("Enter a number: ")
#change the data type to integer
number = int(number)
#display the number entered
print("The numbered entered was", number)
#check if the number is odd or even
if (number % 2 == 0):
    print("That is an even number")
else:
    print("That is an odd number")
