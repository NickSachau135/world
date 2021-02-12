rednet.open("left")
id,message = rednet.receive()
if(id == 12 and message == "signal") then
    redstone.setOutput("right", true)
    sleep(0.3)
    redstone.setOutput("right", false)
end
