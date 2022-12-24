#importing choice and randint from random module
from random import choice,randint

#list of operator names and random strings
op_names = ['Jake','Felix', 'Johnny', 'Mark', 'Jackson', 'Jay']
random_strings=['Hmmm', 'Okay','Tell me more','Thankyou','My pleasure']

print("Welcome to Pop Chat\nOne of our operators will be pleased to help you today.")
#User input for email
email = input("Please enter your Poppleton email address: ")

#function to check validity of the entered email
count= 0
    #loop that checks the number of '@' 
for i in email:
    if i=='@':
        count+=1
    #if statement to check email vadility
if not email[-10:] in '@pop.ac.uk' or count>1 or len(email)<13:
    print("Please enter a valid email address")
    exit()

#function to extract username from user email
def user_name(email):
    username = email[:-10]
    username = username.capitalize()
    return username

#function that returns a random operator name
def operator_name(names):
    name = choice(names)
    return name

print("Hi, ",user_name(email)+"! Thankyou, and welcome to PopChat!\nMy name is",operator_name(op_names)+", and it will be my pleasure to help you.")

def net():
    crash = randint(1,10)
    if crash in range(1,3):
        print("*** NETWORK ERROR ***")
        print("Thanks,",user_name(email)+", for using PopChat. See you soon!")
        exit()

#while loop that takes user quiery as input
while True:
    net()
    user_quiery=input(">>>") 
    #multiple if statements
    if 'library' in user_quiery.lower():
        print("The library is closed today.")
    elif 'wifi' in user_quiery.lower():
        print("WiFi is excellent across the campus.")
    elif 'deadline' in user_quiery.lower():
        print("Your deadline has been extended by two working days.")
    elif 'events' in user_quiery.lower():
        print("There are no events scheduled for the month.")
    elif 'class' in user_quiery.lower():
        print("Classes have been canceled for tomorrow.")
    elif 'result' in user_quiery.lower():
        print("Your results have been published.")
    elif 'bye' in user_quiery.lower() or 'exit' in user_quiery.lower():
        break
    #else statement that prints random strings from the list above
    else:
        filler = choice(random_strings)
        print(filler)
    
print("Thanks,",user_name(email)+", for using PopChat. See you soon!")