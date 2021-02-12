running = true


-- Same as input = input + 1
function incUp(input)
    input = input + 1
    return input
end

-- Check if user cancels movement
function checkCancel(input)
    if (type(input) == 'string' and input:upper() == "CANCEL") then
        running = false
        return running
    end
end

-- Successfully moved
function moveMsg()
    local blocksMoved = inputBlocks + 1 -- So print is same as input
    return print("\nMoving \"" .. inputDirect .. "\" up to " .. blocksMoved .. " available blocks.")
end

-- Obstruction error
function errObstruct()
    return print("\nERROR: Could not move. Block in the way.")
end


while(running == true) do
    -- Check direction
    print("Which direction do you want to move (FORWARD, BACK, UP, DOWN, LEFT, RIGHT)?")
    inputDirect = read():upper()
    checkCancel(inputDirect)
    -- Checks if valid input
    while (inputDirect ~= "FORWARD" and inputDirect ~= "BACK" and inputDirect ~= "UP" and inputDirect ~= "DOWN" and inputDirect ~= "LEFT" and inputDirect ~= "RIGHT") do
        print("\nERROR: Input a valid direction.")
        inputDirect = read():upper()
        checkCancel(inputDirect)
    end

    -- Check blocks
    print("\nHow many blocks do you want to move?")
    inputBlocks = tonumber(read()) - 1 -- Moves extra without -1
    checkCancel(inputBlocks)
    -- Checks if valid input
    while (type(tonumber(inputBlocks)) ~= 'number') do
        print("\nERROR: Input a valid number.")
        inputBlocks = tonumber(read()) - 1 -- Moves extra without -1
        checkCancel(inputBlocks)
    end

    if (inputDirect == "FORWARD") then
        if (turtle.forward() == true) then
            moveMsg()
            for i = 1, inputBlocks do
                turtle.forward()
            end
        else
            errObstruct()
        end
    elseif (inputDirect == "BACK") then
        if (turtle.back() == true) then
            moveMsg()
            for i = 1, inputBlocks do
                turtle.back()
            end
        else
            errObstruct()
        end
    elseif (inputDirect == "UP") then
        if (turtle.up() == true) then
            moveMsg()
            for i = 1, inputBlocks do
                turtle.up()
            end
        else
            errObstruct()
        end
    elseif (inputDirect == "DOWN") then
        if (turtle.down() == true) then
            moveMsg()
            for i = 1, inputBlocks do
                turtle.down()
            end
        else
            errObstruct()
        end
    elseif (inputDirect == "LEFT") then
        turtle.turnLeft()
        if (turtle.forward() == true) then
            moveMsg()
            for i = 1, inputBlocks do
                turtle.forward()
            end
        else
            turtle.turnRight()
            errObstruct()
        end
    elseif (inputDirect == "RIGHT") then
        turtle.turnRight()
        if (turtle.forward() == true) then
            moveMsg()
            for i = 1, inputBlocks do
                turtle.forward()
            end
        else
            turtle.turnLeft()
            errObstruct()
        end
    else
        print("\nERROR: Unknown error.")
    end

    running = false
end