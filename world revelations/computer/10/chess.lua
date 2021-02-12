--[[ Chess Watch

The fun way to watch Minecraft Chess :)

Written by NitrogenFingers
Art curtosy of NN(1998)
]]--

local monitorSide = "left"
local side = nil

local board = {
  --        a     b     c     d     e     f     g     h
  [8] = { "-C",  "-N",  "-B",  "-Q",  "-K",  "-B",  "-N",  "-C" },
  [7] = { "-p",  "-p",  "-p",  "-p",  "-p",  "-p",  "-p",  "-p" },
  [6] = { " ",  " ",  " ",  " ",  " ",  " ",  " ",  " " },
  [5] = { " ",  " ",  "",  " ",  " ",  " ",  " ",  " " },
  [4] = { " ",  " ",  " ",  " ",  " ",  " ",  " ",  " " },
  [3] = { " ",  " ",  " ",  " ",  " ",  " ",  " ",  " " },
  [2] = { "+p",  "+p",  "+p",  "+p",  "+p",  "+p",  "+p",  "+p" },
  [1] = { "+C",  "+N",  "+B",  "+Q",  "+K",  "+B",  "+N",  "+C" }
  --        a     b     c     d     e     f     g     h
}
local pawnList = {
	"(Q)",
	"/Q\\",
	"==="
}
local knightList = {
	" ,^. ",
	"(QQ'\\",
	"|QQ\\ ",
	"==== "
}
local bishopList = {
	" o  ",
	"(Q/)",
	"/QQ\\",
	"===="
}
local castleList = {
	"WWWW",
	"|QQ|",
	"/QQ\\",
	"===="
}
local queenList = {
	"www",
	"\\Q/",
	"(Q)",
	"/Q\\",
	"==="
}
local kingList = {
	"_+_",
	"\\Q/",
	"(Q)",
	"/Q\\",
	"==="
}

local backboard = {
		" _____     _____     _____     _____     ",
		"|     :::::     :::::     :::::     :::::|",
		"|     :::::     :::::     :::::     :::::|",
		"|     :::::     :::::     :::::     :::::|",
		"|:::::     :::::     :::::     :::::     |",
		"|:::::     :::::     :::::     :::::     |",
		"|:::::     :::::     :::::     :::::     |",
		"|     :::::     :::::     :::::     :::::|",
		"|     :::::     :::::     :::::     :::::|",
		"|     :::::     :::::     :::::     :::::|",
		"|:::::     :::::     :::::     :::::     |",
		"|:::::     :::::     :::::     :::::     |",
		"|:::::     :::::     :::::     :::::     |",
		"|     :::::     :::::     :::::     :::::|",
		"|     :::::     :::::     :::::     :::::|",
		"|     :::::     :::::     :::::     :::::|",
		"|:::::     :::::     :::::     :::::     |",
		"|:::::     :::::     :::::     :::::     |",
		"|:::::     :::::     :::::     :::::     |",
		"|     :::::     :::::     :::::     :::::|",
		"|     :::::     :::::     :::::     :::::|",
		"|     :::::     :::::     :::::     :::::|",
		"|:::::     :::::     :::::     :::::     |",
		"|:::::     :::::     :::::     :::::     |",
		"|:::::_____:::::_____:::::_____:::::_____|"
	}

function printBoard()
	mcall("clear")
	for i = 1, #backboard do
		mcall("setCursorPos", 9,7 + i)
		mcall("write", backboard[i])
	end

	for i = 1, 8 do
		for j = 1, 8 do
			printPiece(board[9-i][j], 13 + (j-1)*5, 10 + (i-1)*3)
		end
	end
end

function printPiece(piece, x, y)
	white = false
	if string.find(piece, "+") == 1 then white = true end

	piece = string.sub(piece, 2)
	list = nil

	if piece == "p" then list = pawnList
	elseif piece == "N" then list = knightList
	elseif piece == "B" then list = bishopList
	elseif piece == "C" then list = castleList
	elseif piece == "Q" then list = queenList
	elseif piece == "K" then list = kingList
	else return end

	for i=1,#list do
		local nextString = list[i]
		while nextString:find("Q") do
			if white then
				nextString = string.gsub(nextString, "Q", "#")
			else
				nextString = string.gsub(nextString, "Q", " ") end
		end
		mcall("setCursorPos", x - #nextString/2, y - #list + i)
		mcall("write", nextString)
	end
end

--A combination of the parseInput and the essentials of the makeMove method from chess.lua
function makeMove(input)
	local oldx = convertLetterToCoordinate(string.sub(input, 1, 1))
	local oldy = tonumber(string.sub(input, 2, 2))
	local newx = convertLetterToCoordinate(string.sub(input, 4, 4))
	local newy = tonumber(string.sub(input, 5, 5))

	if not oldx or not oldy or not newx or not newy then return end

	local oldsub = board[oldy][oldx]
	local newsub = board[newy][newx]

	board[newy][newx] = board[oldy][oldx]
	board[oldy][oldx] = " "

	--en passant is handled here
	if board[newy][newx] == " " and math.abs(oldx-newx) == 1 and
	  board[oldy][oldx]:sub(2) == "p" and board[oldy][newx]:sub(2) == "p" then
		board[oldy][newx] = " "
	end

	--Castling is handled here
	if board[newy][newx] == "+K" then
		if newx - oldx == 2 then
			board[1][6] = board[1][8]
			board[1][8] = " "
		elseif newx - oldx == -2 then
			board[1][4] = board[1][1]
			board[1][1] = " "
		end
	end
	if board[newy][newx] == "-K" then
		blackKing = { x = newx, y = newy }
		if newx - oldx == 2 then
			board[8][6] = board[8][8]
			board[8][8] = " "
		elseif newx - oldx == -2 then
			board[8][4] = board[8][1]
			board[8][1] = " "
		end
	end
end

function convertLetterToCoordinate(input)
  if input=="a" then return 1
  elseif input=="b" then return 2
  elseif input=="c" then return 3
  elseif input=="d" then return 4
  elseif input=="e" then return 5
  elseif input=="f" then return 6
  elseif input=="g" then return 7
  elseif input=="h" then return 8
  else return nil end
end

--Runs a term application on the monitor. A time-saving method, and we only ever use 3 parameters.
function mcall(f,p1,p2,p3)
	peripheral.call(monitorSide, f, p1, p2, p3)
end

--Finds the side the modem is on, and opens it
function openModem()
	for i=1,#rs.getSides() do
		if peripheral.isPresent(rs.getSides()[i]) and peripheral.getType(rs.getSides()[i]) == "modem" then
			side = rs.getSides()[i]
			rednet.open(side)
			return true
		end
	end
	return false
end
--Finds the side the monitor is on
function findMonitor()
	for i=1,#rs.getSides() do
		if peripheral.isPresent(rs.getSides()[i]) and peripheral.getType(rs.getSides()[i]) == "monitor" then
			monitorSide = rs.getSides()[i]
			return true
		end
	end
	return false
end

--This promotes a pawn from a network message
function handleRemotePawnPromotion(msg)
	local x = tonumber(string.sub(msg, 1, 1))
	local y = tonumber(string.sub(msg, 2, 2))
	local piece = string.sub(msg, 3)

	board[y][x] = piece
	movesMade[#movesMade].promotion = string.sub(msg, 4)
end

function runMonitor()
	while true do
		printBoard()
		local proMsg = nil
		local key,msg = rednet.receive()
		if msg == "#Q" then
			break
		elseif string.find(msg, "#P") == 1 then
			proMsg = string.sub(msg, 3)
		else
			makeMove(msg)
			if proMsg then handleRemovePawnPromotion(proMsg) end
		end
	end

end

function prepareMonitor()

	--This short program is used for monitor displays
	term.write("Enter ID of host: ")
	local number = tonumber(io.read())
	if not number then
		print("Bad input!")
		return
	end

	if not openModem() then
		print("No modem on your computer!")
		return
	end

	if not findMonitor() then
		print("No monitor on your computer!")
		return
	end

	rednet.send(number, "#M")
	local key,msg = rednet.receive(5)

	if not key then
		print("No response.")
		return
	end

	if msg == "#Y" then
		print("Accepted- starting monitor application")
		runMonitor()
	end
end

prepareMonitor()

