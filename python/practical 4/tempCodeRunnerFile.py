def showMsg(title, body="", prefix="INFO", suffix="."):
    print(prefix,title,body,suffix)
    showMsg("File opened")
showMsg("File not opened", prefix="ERROR" )
showMsg("File missing", body="Insert Disk", suffix="Press return")