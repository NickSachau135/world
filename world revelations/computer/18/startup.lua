os.pullEvent = os.pullEventRaw

function sound()

    local speaker = peripheral.find("speaker")
    local playing = true
    while playing do
        print("Playing Torture")
        speaker.playSound('twilightforest:mob.mosquito.mosquito', 3, 2)
        sleep(0.1)
        if (redstone.getInput("left") == true) then
            playing = false
            print("yes")
        end
    end
    while playing == false do
        print("Not Playing Torture")
        sleep(0.1)
        if (redstone.getInput("left") == true) then
            playing = true
            sound()
        end
    end
end

sound()