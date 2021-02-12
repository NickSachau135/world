os.pullEvent = os.pullEventRaw

local password = "123"

local function openDoor()
    redstone.setOutput("top", true)
    sleep(5)
    redstone.setOutput("top", false)
end

while (true) do
    local input = read("*")
    if (input == password) then
        print('Correct Password')
        openDoor()
        term.clear()
        term.setCursorPos(1, 1)
    else
        print('Incorrect Password. Please try again.')
        sleep(3)
        term.clear()
        term.setCursorPos(1, 1)
    end
end