#Task 1
names = {"John", "Eric", "Terry", "Michael", "Graham", "Terry"}
print(names,"\n")

#Task 2
sentence = "this is a sentence containing some letters"
unique_letters = {x for x in sentence}
print(unique_letters,"\n")

#Task 3
name = input("Enter your name: ")
if name not in names:
    print("You are not listed in the set of known names\n")
else:
    print("You are listed in the set of kown names\n")

#Task 4
staff = {"Pete", "Kelly", "Jon", "Paul", "Sally", "Sue"}
directors = {"Kelly", "Rupert", "Cyril", "Jon"}
staff = staff.union({"Mark", "Ringo"})
print(staff)
staff = staff.difference({"Mark", "Ringo"})
print("\n",staff)

#Task 5
vowels = set({"a", "e", "i"})
vowels = vowels.update({"o","u"})

#Task 6
managers = {"Kelly", "Jon", "Paul", "Sally", "Sue"}
if managers.issubset(staff):
    print("\nAll managers are staff members\n")
else:
    print("\nAll managers are staff members\n")

#Task 7
import math
roots = {n : math.sqrt(n) for n in range(1,26)}
print(roots,"\n")

#Task 8
stock = {"apple":10, "banana":15, "orange":11}
stock["kiwi"]=10
print(stock,"\n")

#Task 9
stock.popitem()
print(stock,"\n")

#Task 10
for i in roots:
    print("The square root of", i," is", math.sqrt(i))
