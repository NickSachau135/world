local speaker = peripheral.find("speaker")
local playing = true
function sound()
    while playing do
        speaker.playSound('twilightforest:mob.mosquito.mosquito', 3, 2)
        sleep(0.1)
        if (redstone.getInput("left", true)) then
            if playing == true then
                playing = false
            end
        end
    end
    while playing == false do
        if (redstone.getInput("left", true)) then
            playing = true
        end
    end
end

