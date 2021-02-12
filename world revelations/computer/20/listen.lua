rednet.open("right")

id, message = rednet.receive()
if id == 21 and message == "stop" then
    print("yes")
    
    sleep(10)
end

    
