print("Swallow Speed Analysis: Version 1.0\n")
count = 0
count_U = 0
count_E = 0
speed_E = []
speed_U = []
#while loop for continuous user input
while True:
    reading = input("Enter the Next Reading: ")
    #checks whether a reading was entered or not
    if (len(reading)==0) and count==0:
        print("No readings entered. Nothing to do.")
        exit()
    elif len(reading)>0:
        count+=1
        print("reading saved")
        temp = float(reading[1:])

        #checks if user input was european or british reading
        if reading[0] == 'U':
            speed_U.append(temp)
            count_U+=1
        elif reading[0] == 'E':
            speed_E.append(temp)
            count_E+=1
    if (len(reading)==0) and count>=1:
        break
print("\nResults Summary\n")
print(count, "Reading Analysed.\n")
#loop to convert readings into corresponding values
for  i in speed_E:
    i/=1.61
    #round to 1 decimal point
    z = round(i,1)
    speed_U.append(z)
    #sorts the list in ascending order
    speed_U.sort()
    #sums up the total
    total_U=sum(speed_U)
for i in speed_U:
    i*=1.61
    #round to 1 decimal point
    y = round(i,1)
    speed_E.append(y)
    #sorts the list in ascending order
    speed_E.sort()
    #sums up the total
    total_E = sum(speed_E)
#prints the values
print("Max Speed: ",speed_U[-1]," MPH", speed_E[-1]," KPH")
print("Min Speed: ",speed_U[0]," MPH", speed_E[0]," KPH")
print("Avg Speed: ",total_U/count_U," MPH",total_E/count_E ," KPH")