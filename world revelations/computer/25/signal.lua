rednet.open("left")
while true do
    id,message = rednet.receive()
    if(id == 12 and message == "signal") then
        redstone.setOutput("right", true)
        sleep(0.1)
        redstone.setOutput("right", false)
    end
end