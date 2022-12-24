# from random import choice, randint
# # x=0
# # list_1=[]
# # if type(x)==int:
# #     x=input("enter an integer: ")
# #     list_1.append(x)
# #     print(list_1)
# # answers = ['yes', 'no','maybe', 'nil']
# # email= "jen@pop.ac.uk"
# # def user_name(email):
# #     username = email[:-10]
# #     username = username.capitalize()
# #     return username
# # print(user_name(email))
# op_names = ['Jake','Felix', 'Johnny', 'Mark', 'Jackson', 'Jay']
# # def operator_name(names):
# #     name = choice(names)
# #     return name
# # print(operator_name(op_names))
# # def operator_name(*op_names):
# #     name = choice(op_names)
# #     return name
# # print(operator_name(op_names))
# filler_string = choice(op_names)
# print(filler_string)
# def check():
#     crash = randint(1,11)
#     print(crash)

# check()

temperature = 21
pressure = 1010
humidity =41
MESSAGE="T: {:4f}C\nP: {:4f}hPa\nH: {:4f}%".format(temperature, pressure, humidity)
print(MESSAGE)
