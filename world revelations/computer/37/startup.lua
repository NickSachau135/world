os.pullEvent = os.pullEventRaw

local speaker = peripheral.find("speaker")

while true do
    if (redstone.getInput("left") == true) then
        print("Playing Torture")
        speaker.playSound('twilightforest:mob.mosquito.mosquito', 3, 2)
        sleep(0.1)
    end
    if(redstone.getInput("left") == false) then
        print("Not Playing Torture")
        sleep(0.1)
    end
end
