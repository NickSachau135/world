signal = true
rednet.open("left")
while true do
	id, message = rednet.receive()
	if(id == 12 or id == 27 or id == 28 and message == "signal") then
		print("Shitass")
		if(signal == true) then
		redstone.setOutput("right", true)
		signal = false
		elseif(signal == false) then
		redstone.setOutput("right", false)
		signal = true
		end
	end
end