#Task 1
from math import sqrt
squares = [4, 9, 16, 25]
for i in squares:
    print("Square root of", i," is",sqrt(i))

#Task2
squares.append(49)
squares.append(64)
squares.append(81)
print("\n",squares)

#Task 3
squares.extend([121,144,169])
print("\n",squares)

#Task 4
squares.insert(0,2)
print("\n",squares)

#Task 5
squares.remove(49)
print("\n",squares)

#Task 6
""" squares.remove(3) """
#error since there is no 3 in the list

#Task 7
squares.pop()
print("\n",squares)

#Task 8
squares.pop(0)
print("\n",squares)

#Task 9
names = [ "Eric", "anna", "Sophie", "sam" ]
names.sort()
print("\n",names)

#Task 10
names.sort(key=lambda name : str.upper(name))
print("\n",names)

#Task 11
squares.reverse()
print("\n",squares)

#Task 12
colours = ["red", "green", "yellow", "blue", "red"]
print("\n Index of 'blue' is ",colours.index("blue"))

#Task 13
colours_2 = colours.copy()
colours.append("grey")
print("\n",colours_2)

#Task 14
cube = [num * num * num for num in range(2,21)]
print("\n",cube)

#Task 15
#Task 16
address = (1234, "line", 5678)

#Task 17
the_one = "Neo",
print("\n",type(the_one))
the_one = ("Neo")
print("\n",type(the_one))

#Task 18
house_num, street, postcode = address





