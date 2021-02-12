print("Running turtle.lua\n---------------------------------------\n")
firstRun = true



--Turtle functions

-- Checks fuel amount
function turtledoFuelCheck()
    return print("\nFuel Remaining: " .. turtle.getFuelLevel())
end


-- Refuels
-- input[3] is amount of fuel
function turtledoFuelRefuel(amt)
    if tonumber(amt) ~= nil then
        -- Must be numerical value
        amt = tonumber(amt)

        if (amt < 0 or amt > 64) then
            -- Cannot enter negative, cannot go over fuel limit, cannot do more than 1 stack
            inputError("value")

        elseif (amt > turtle.getItemCount(1)) then
            -- Cannot input greater than there is coal in slot
            inputError("slot")

        else

            if turtle.getSelectedSlot() ~= 1 then
                turtle.select(1)
            end
            turtle.refuel(amt)
            print("\nRefueled. Used " .. amt .. " coal\nFuel Remaining: " .. turtle.getFuelLevel() .. "\n")
        end

    else
        inputError("value")
    end
end


-- Move
-- input[2] is direction
-- input[3] is block amount
function turtleDoMove(direction, blocks)
turtleDoMoveRunning = true
    local function checkError()
            local isObstructed = "\nCould not move further.\nTurtle is obstructed."
            if (direction == "forward" or direction == "left" or direction == "right") then
                if turtle.detect() == true then
                    turtleDoMoveRunning = false
                    return print(isObstructed)
                end
            -- elseif direction == "back" then
            --     if turtle.back() == true then
            --         turtleDoMoveRunning = false
            --         return isObstructed
            --     end
            elseif direction == "up" then
                if turtle.detectUp() == true then
                    turtleDoMoveRunning = false
                    return print(isObstructed)
                end
            elseif direction == "down" then

                if turtle.detectDown() == true then
                    turtleDoMoveRunning = false
                    return print(isObstructed)
                end
            end
        end

    while turtleDoMoveRunning == true do
        local function moveMsg()
            local blocksMoved = blocks + 1
            return print("\nMoving \"" .. direction .. "\" up to " .. blocksMoved .. " available blocks.")
        end

        blocks = blocks - 1
        if(direction == "forward") then
            if (turtle.forward() == true) then
                moveMsg()
                for i = 1, blocks do
                    if turtleDoMoveRunning == true then
                        checkError()
                        turtle.forward()
                    end
                end
            else
                checkError()
            end
        elseif(direction == "right") then
            turtle.turnRight()
            if(turtle.forward() == true) then
                moveMsg()
                for i = 1, blocks do
                    if turtleDoMoveRunning == true then
                        checkError()
                        turtle.forward()
                    end
                end
            else
                checkError()
                turtle.turnLeft()
            end
        elseif(direction == "back") then
            if (turtle.back() == true) then
                moveMsg()
                for i = 1, blocks do
                    if turtleDoMoveRunning == true then
                        -- checkError()
                        turtle.back()
                    end
                end
            else
                checkError()
            end
        elseif(direction == "left") then
            turtle.turnLeft()
            if(turtle.forward() == true) then
                moveMsg()
                for i = 1, blocks do
                    if turtleDoMoveRunning == true then
                        checkError()
                        turtle.forward()
                    end
                end
            else
                checkError()
                turtle.turnRight()
            end
        elseif(direction == "up") then
            if(turtle.up() == true) then
                moveMsg()
                for i = 1, blocks do
                    if turtleDoMoveRunning == true then
                        checkError()
                        turtle.up()
                    end
                end
            else
                checkError()
            end
        elseif(direction == "down") then
            if(turtle.down() == true) then
                moveMsg()
                for i = 1, blocks do
                    checkError()
                    turtle.down()
                end
            else
            checkError()
            end
        end

        turtleDoMoveRunning = false
    end
end


-- Errors
function inputError(type)
    local error = "ERROR: "
    local output = error .. "Unknown error"

    -- Invalid input
    if type == "input" then
        output = error .. "That is not a valid input"

    -- Invalid input command
    elseif type == "command" then
        output = error .. "That command does not exist"

    -- Invalid input value
    elseif type == "value" then
        output = error .. "That is not a valid value"

    -- No of what you need in slot
    elseif type == "slot" then
        output = error .. "There is not enough of that in that slot"

    end
    return print(output)
end



-- Splits a string to a table by " "
function strSplit(inputstr, sep)
    if sep == nil then
        sep = "%s"
    end
    local t={}
    for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
        table.insert(t, str)
    end
    return t
end



-- Grabs input
-- input[1] is parameter caller
-- input[2] is parameter
function checkInput()
    if firstRun ~= true then
        print("\n---------------------------------------\n")
        input = read():lower()
        print("")
        input = strSplit(input, " ")
        return input
    else
        firstRun = false
        input = read():lower()
        input = strSplit(input, " ")
        return input
    end
end



-- Run
checkInput()
running = true
while running == true do


    if (#input == 1 and input[1] == "cancel") then
        running = false
        print("Goodbye")

    elseif (#input == 2 or #input == 3 and input[1] == "fuel") then
        if (#input == 2 and input[2] == "check") then
            turtledoFuelCheck()
            checkInput()
        elseif (#input == 3 and input[2] == "refuel") then
            turtledoFuelRefuel(input[3])
            checkInput()
        else
            -- Did not enter valid input[2]
            inputError("command")
            checkInput()
        end

    elseif (#input == 3 and input[1] == "move") then
        if (input[2] ~= "forward" and input[2] ~= "back" and input[2] ~= "left" and input[2] ~= "right" and input[2] ~= "up" and input[2] ~= "down") then
            inputError("command")
            checkInput()
        elseif (type(tonumber(input[3])) ~= 'number') then
            inputError("value")
            checkInput()
        elseif (tonumber(input[3]) < 0) then
            inputError("value")
            checkInput()
        elseif (tonumber(input[3]) == 0) then
            print("\nDidn't move at all.\nWhy did you try to move 0 blocks you fucking retarded piece of shit")
            checkInput()
        else
            turtleDoMove(input[2], input[3])
            checkInput()
        end

    else
        inputError("command")
        checkInput()
    end
end