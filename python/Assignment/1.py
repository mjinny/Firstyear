print("\nStop! Who would cross the Bridge of Death Must answer me these questions three, 'ere the other side he see.\n")
name=input("What is your name?\n")
if(name.capitalize()=="Arthur"):
    print("My liege! You may pass!")
else:
    quest=input("What do you seek?\n")
    if ("grail" in quest.lower()):
        colour=input("What is your favourite colour?\n")
        if(colour[0].capitalize()==name[0].capitalize()):
            print("You may pass!")
        else:
            print("Incorrect! You must now face the Gorge of Eternal Peril.")
    else:
        print("Only those who seek the Grail may pass")
