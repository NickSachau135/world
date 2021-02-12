running = true


while(running == true) do
    -- Refuel
    print("How much fuel should be used?")
    input = tonumber(read())

    -- If input is invalid
    while(type(input) ~= 'number' or input > 64 or input > 100000 - turtle.getFuelLevel()) do
        print("\nPlease enter a correct value")
        if(type(input) ~= 'number') then
            print("Value must be a number")
        elseif(input > 64) then
            print("Fuel amount must be at most 64") -- Too much work to implement
        elseif(input > 100000 - turtle.getFuelLevel()) then
            print("Total fuel must be <100,000") -- Advanced turtles can only <= 100,000 fuel
        end
        input = tonumber(read())
    end

    turtle.refuel(input)

    if(input == 0) then
        print("\nStopped refuel")
    else
        print("\nRefueled")
    end
    print("Used " .. input .. " coal")

    running = false
end