-- Startup Message
function startupMsg(message)
    message = tostring(message)
    print(message)
end


-- Password
function requirePassword(password, hint)
    os.pullEvent = os.pullEventRaw

    print('Please enter your password:')
    local attempts = 1
    local pass = tostring(password)
    local correctPass = false
    local uInput = read('*')
    print("\n")

    while(correctPass == false) do
        if(uInput == pass) then
            correctPass = true
            print('Correct password.')
            sleep(1)
            term.clear()
            term.setCursorPos(1, 1)
        else
            if(attempts >=  3) then
                print('Hint: ' .. tostring(hint))
            end
            print('Incorrect password, please try again.')
            attempts = attempts + 1
            uInput = read('*')
            print("\n")
        end
    end
end

-- Funcitons
-- startupMsg('Hello, I am a computer,\nand the person who typed this is really cool.')
requirePassword('wordPASS123', 'No hints lol gtfo')
