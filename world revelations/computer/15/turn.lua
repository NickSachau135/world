function turningMsg()
    return print("\nTurning \"" .. input .. "\"...")
end


function turn()
    if input == "LEFT" then
        turtle.turnLeft()
        return turningMsg()
    elseif input == "RIGHT" then
        turtle.turnRight()
        return turningMsg()
    elseif input == "BACK" then
        turtle.turnRight()
        turtle.turnRight()
        return turningMsg()
    end
end


running = true
while(running == true) do
      print("Which direction (\"LEFT\", \"RIGHT\", \"BACK\")?")
      input = read():upper()

      if (input == "LEFT" or input == "RIGHT" or input == "BACK") then
          turn()
          running = false
      elseif input == "CANCEL" then
          running = false
      else
          print("\nERROR: Invalid input.\nPlease try again.")
      end
end