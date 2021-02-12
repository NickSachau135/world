function requirePassword(password, hint)
    os.pullEvent = os.pullEventRaw

    print('Please enter your password:')
    local attempts = 1
    local pass = tostring(password)
    local correctPass = false
    local uInput = read('*')

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
        end
    end
end