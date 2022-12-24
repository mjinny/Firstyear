""" def send_output(**details):
    if a>b:
        return b
    else:
        return a
a=int(input("Enter a number: "))        
b=int(input("Enter another number: "))
print("The smallest number is ", send_output(a,b))"""
# def print_header(msg):
#     """Displays message prefixed by '*****'."""
#     print('*****',msg)
# print_header("This message is prefixed")
def shouldContinue(prompt, answer=False):
    print(prompt, answer)
answer=shouldContinue("Do you want to continue?")
shouldContinue("Do you want to continue","No")
