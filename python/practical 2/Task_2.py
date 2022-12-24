#Task 1
total = 100
print("The total is", total)

print("\n")

#Task 2
total = total + 99
print("The total is now", total)

print("\n")

#Task 3
total -= 1
print("The total is", total)
total *= 4
print("The total is", total)
total /= 2
print("The total is", total)

print("\n")

#Task 4
total = 98.2
count = 5
average = total/count
print("The average is", average)

print("\n")

#Task 5
print(type(False))
print(type(1000))
print(type(100.111))
print(type("Hello"))
print(type(True))
print(type(100 / 5))
print(type(100 // 5))

print("\n")

#Task 6
print("ABC" * 10) 
""" The * operator is multiplying the string operand "ABC" 10 times """

print("\n")

#Task 7
name = "Jenny Maharjan"
address = "Nakkhu"
contact = 1234567809
print("Name :", name)
print("Address:", address)
print("Contact detail:", contact)
print("Length of the name is", len(name))

print("\n")

#Task 8
""" age = input("Enter your age ")
print("in one year your age will be", age + 1) """
#No, this program doesn't work. Here, age returned a string value. Addition between string and integer cannot be done

print("\n")

#Task 9
first_number = int(input("Enter a number: "))
second_number = int(input("Enter another number: "))
print("The product of", first_number, "and", second_number, "is", first_number*second_number)

print("\n")

#Task 10
""" comment = "I would have "thought" you knew better!" """
#syntax error

#Task 11
print("This text includes characters such as \'\\\' \'\"\' and \"\'\",\n\tThis is a new line that starts with a tab\n\t\tThis new line starts with two tabs")

print("\n")

#Task 12
print("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\nHello there!\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\")

print("\n")

#Task 13
print("""This text spans three lines,
and includes both single ('),
and double quotes (").""")

print("\n")

#Task 14
surname = "Palin"
initial = surname[2]
print("The third letter of 'Palin' is", initial)

#Task 15
""" surname = "Palin"
initial = surname[9]
print("The tenth letter of 'Palin' is", initial) """
#Index error

print("\n")

#Task 16
surname = "Palin"
last = surname[-2]
print("The second last letter of 'Palin' is", last)

print("\n")

#Task 17
surname = "Palin"
middle = surname[1:5]
print(middle)

print("\n")

#Task 18
last = surname[:4]
print(last)

print("\n")

#Task 19
primes = [2, 3, 5, 7, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
print("First four prime numbers in the list are", primes[0:4])

print("\n")

#Task 20
names = ["Terry", "John", "Michael", "Eric", "Terry", "Graham"]
names[5:0] = ["Jake", "Felix"]
print(names)

print("\n")

#Task 21
nums = [1,2,3] * 5
#The elements would be repeated 5 times