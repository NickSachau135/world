local password = "123"


local function openDoor()
    redstone.setOutput("top", true)
    sleep(5)
    redstone.setOutput("top", false)
end
while (true) do
    local input = read("*")
    if (input == pass) then
        print('Correct Password')
        openDoor()
        sleep(5)
        term.clear()
    else
        print('Incorrect Password. Please try again.')
        sleep(1)
        term.clear()
    end
end
