local blocksSmelted = 0
local blocks = tonumber(read())
redstone.setOutput("right", true)
blocks = blocks - 11
while (true) do
  print("Smelting")
  sleep(0.01)
  term.clear()
  term.setCursorPos(1,1)
  if(redstone.getInput("front") == true) then
    sleep(0.01)
    if(redstone.getInput("front") == false) then
      blocksSmelted = blocksSmelted + 1
      print(blocksSmelted)
      if (blocksSmelted == blocks) then
        redstone.setOutput("right", false)
      end
    end
  end
end

