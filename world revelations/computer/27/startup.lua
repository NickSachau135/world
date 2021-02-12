-- Startup Message
function startupMsg(message)
    message = tostring(message)
    print(message .. "\n")
end


-- Password
function requirePassword(password, hint)
    os.pullEvent = os.pullEventRaw

    print('Password:')
    local attempts = 1
    local pass = tostring(password)
    local correctPass = false
    local uInput = read("*")
    print("\n")

    while(correctPass == false) do
        if(uInput == pass) then
            correctPass = true
            print("Correct password.")
            sleep(1)
            term.clear()
            term.setCursorPos(1, 1)
        else
            print("Incorrect password, please try again.")
            attempts = attempts + 1
            uInput = read("*")
            print("\n")
        end
    end
end

-- Funcitons
startupMsg("Ilya's Phone")
requirePassword("asdf")
