#Task 1
print(10 < 100)
print(100 != 100)
print(5 >= 50)

print("\n")

#Task 2
my_age = 19
print(my_age < 18)
print(my_age < 21)
print(my_age < 31)

print("\n")

#Task 3
print("a" < "b")
print("b" < "a")
print("John" < "Terry")

print("\n")

#Task 4
print("john" < "Terry")
#lower case j

print("\n")

#Task 5
print(5 < 10.2)
""" print(5 < "Monty")
print(5 < "5") """

print("\n")

#Task 6
age = 30
print(age >=18 and age <=65)
print(age <18 or age >65)
print(not age > 18)

print("\n")

#Task 7
age = 30
print((age >=18 and age <=65) and (not age==30))
print("\n")

#Task 8
height = 160
weight = 45
print(100 < weight and weight < 200)
print(height > 131 and height < 160)

print("\n")

#Task 9
message = "Hello there, my name is John"
print("nam" in message)
print("this" in message)

print("\n")

#Task 10
age_my = 20
if age_my > 17 and age_my < 31:
    print("you are still young!")

print("\n")

#Task 11
if age > 100:
    print("you are very old,")
    print("well done!")
elif age > 80:
    print("you are fairly old")
    print("pretty good!")
elif age > 40:
    print("you are middle aged")
    print("never mind")
elif age >= 30:
    print("you are not very old - yet")
else:
    print("you are young")

print("\n")

#Task 12
name = input("Enter your name: ")
if name == None:
    print("Your name is", name)
else:
    print("Name not entered")

print("\n")

#Task 13
print("you are an adult" if age >=18 else "you are not an adult, yet!")

print("\n")

#Task 14
names_1 = ['Jake', 'Felix', 'Mark', 'Johnny']
for i in names_1:
    print(i)

print("\n")

#Task 15
for num in range(2,11,2):
    print(num, "to the power of", num, "=", num**num)

print("\n")

#Task 16
numbers = [10, 20 , 30, 90, 200, 30, 22, 11]
total = 0
for j in numbers:
    total +=j
    print(total)

print("\n")

#Task 17
numbers = [10, 20 , 30, 90, 200, 30, 22, 11]
total = 0
for j in numbers:
    if j > 100:
        break
    total +=j
    print(total)

print("\n")

#Task 18
numbers = [10, 20 , 30, 90, 200, 30, 22, 11]
total = 0
for j in numbers:
    if j > 100:
        break
    total +=j
    print(total)
    print("all numbers processed")