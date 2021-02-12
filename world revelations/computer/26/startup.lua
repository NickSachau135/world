os.pullEvent = os.pullEventRaw

rednet.open("left")
while true do
	id, message = rednet.receive()
	if(id == 12 or id == 27 or id == 28 and message == "signal") then
		redstone.setOutput("right", true)
		sleep(0.1)
		redstone.setOutput("right", false)
	end
end