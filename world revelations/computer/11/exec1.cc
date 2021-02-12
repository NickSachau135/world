os.loadAPI(fs.getDir(shell.getRunningProgram()).."/apis/blittle")
os.loadAPI(fs.getDir(shell.getRunningProgram()).."/apis/ascii")

local file = fs.open(fs.getDir(shell.getRunningProgram()).."/sv.cc","r")
local SVData = file.readLine()

Money = ascii.fromBinary(SVData)

file.close()

local CurrentDir = shell.dir()

local count = 1

local pod = 0

local Directory = ""

local CodeTry = 0

local CodeString = ""

local flowercard = blittle.load(fs.getDir(shell.getRunningProgram()).."/textures/flower.nfmp")

local pikecard = blittle.load(fs.getDir(shell.getRunningProgram()).."/textures/pike.nfmp")

local PikeCard = blittle.load(fs.getDir(shell.getRunningProgram()).."/textures/pike.nfmp")

local heartcard = blittle.load(fs.getDir(shell.getRunningProgram()).."/textures/heart.nfmp")

local starcard = blittle.load(fs.getDir(shell.getRunningProgram()).."/textures/star.nfmp")

local diamondcard = blittle.load(fs.getDir(shell.getRunningProgram()).."/textures/diamond.nfmp")

local clovercard = blittle.load(fs.getDir(shell.getRunningProgram()).."/textures/clover.nfmp")

local backside = blittle.load(fs.getDir(shell.getRunningProgram()).."/textures/backside/backside.nfmp")   

local NoCard = blittle.load(fs.getDir(shell.getRunningProgram()).."/textures/NoCard.nfmp")

local rf_str = ""

local fl_str = ""

local foak_str = ""

local toak_str = ""

local tp_str = ""

local op_str = ""

local FlowerAmmount = 0

local PikeAmmount = 0

local HeartAmmount = 0

local StarAmmount = 0

local DiamondAmmount = 0

local CloverAmmount = 0

local Reward = 0

local op_reward = 2

local tp_reward = 3

local toak_reward = 4

local fl_reward = 6

local foak_reward = 8

local rf_reward = 16

local Winner = ""

local HasCardsSelected = false

local CardsOrganized = false

local HasNewCards = false

local NewCardsAnim = false

local NewCardsAnimTable = {}

local NewCardsP1 = {}

local CardsP1 = {"NoCard","NoCard","NoCard","NoCard","NoCard"}

local CardsP1Images = {NoCard,NoCard,NoCard,NoCard,NoCard}

local CardsP1Organized = {}

local CardsP1OrganizedImages = {}

local CardsP1Ammount = {}

local CardsP1OrganizedImages = {}

local CardsP1Organized_str = ""

local CardsP1Set = ""

local CardsP1Worth = 0

local rf_str_p2 = ""

local fl_str_p2 = ""

local foak_str_p2 = ""

local toak_str_p2 = ""

local tp_str_p2 = ""

local op_str_p2 = ""

local NewCardsP2 = {}

local CardsP2 = {"NoCard","NoCard","NoCard","NoCard","NoCard"}

local CardsP2Images = {NoCard,NoCard,NoCard,NoCard,NoCard}

local NewCardsAnimP2 = false

local CardsOrganizedP2 = false

local CardsP2Organized_str = ""

local CardsP2Set = ""

local CardsP2Worth = 0

local CardsP2Organized = {}

local CardsP2OrganizedImages = {}

local CardsP2Ammount = {[1] = 0,[2] = 0,[3] = 0,[4] = 0,[5] = 0,[6] = 0}

local CardsExchangeP2 = {[1] = false,[2] = false,[3] = false,[4] = false,[5] = false,[6] = false}

local CardsRevealP2 = true

local FlowerAmmountP2 = 0

local PikeAmmountP2 = 0

local HeartAmmountP2 = 0

local StarAmmountP2 = 0

local DiamondAmmountP2 = 0

local CloverAmmountP2 = 0

local CardsSelected = {[1] = false, [2] = false, [3] = false, [4] = false, [5] = false}

local CardsSelectedType = {}

local ButtonsOn = true

DrawText = function(x, y, backColor, color, text)

if x==textutils.unserialize("centered") then

x = 25 - #text / 2

end

if y==textutils.unserialize("centered") then

y = 10

end

term.setCursorPos(x,y)
term.setBackgroundColor(backColor)
term.setTextColor(color)
term.write(text)

end

function sounds(sound)

if sound=="click" then

redstone.setOutput("left",true)

sleep(0.20)

redstone.setOutput("left",false)

elseif sound=="reveal" then

redstone.setOutput("right",true)

sleep(0.20)

redstone.setOutput("right",false)

elseif sound=="harp" then

redstone.setOutput("right",true)

sleep(0.20)

redstone.setOutput("right",false)

elseif sound=="bass" then

redstone.setOutput("back",true)

sleep(0.20)

redstone.setOutput("back",false)

end
  end

function Save()

local file = fs.open(fs.getDir(shell.getRunningProgram()).."/sv.cc","w")

file.write(ascii.toBinary(tostring(Money)))

file.close()

end

function drawGUI()

term.setBackgroundColor(colors.green)

term.clear()

if #CardsP1 >=1 then

sCount = 1

count = 1

end

for i = 1,#CardsP1 do

if NewCardsAnim==true and CardsSelected[i] then

blittle.draw(CardsP1Images[i],5+count,12)

count = count + 8

sCount = sCount + 1

elseif CardsSelected[i] then

blittle.draw(CardsP1Images[i],5+count,11)

count = count + 8

sCount = sCount + 1

elseif CardsOrganized then

blittle.draw(CardsP1OrganizedImages[i],5+count,12)

count = count + 8

sCount = sCount + 1

elseif CardsP1[i]=="backside" then

blittle.draw(backside,5+count,12)

count = count + 8

sCount = sCount + 1

else

blittle.draw(CardsP1Images[i],5+count,12)

count = count + 8

sCount = sCount + 1

end
  end
  
count = 1

for i = 1,#CardsP2 do

if NewCardsAnimP2==true and not CardsRevealP2 then

if CardsP2Images[i]==NoCard then

blittle.draw(NoCard,5+count,3)

count = count + 8

sCount = sCount + 1

else

blittle.draw(backside,5+count,3)

count = count + 8

end

elseif not CardsRevealP2 then

blittle.draw(backside,5+count,3)

count = count + 8

elseif CardsOrganizedP2 then

blittle.draw(CardsP2OrganizedImages[i],5+count,3)

count = count + 8

sCount = sCount + 1

elseif CardsP2[i]=="backside" then

blittle.draw(backside,5+count,3)

count = count + 8

sCount = sCount + 1

else

blittle.draw(CardsP2Images[i],5+count,3)

count = count + 8

sCount = sCount + 1

end
  end
	
paintutils.drawPixel(6,1,colors.yellow)

DrawText(1,1,colors.green,colors.black,"Pod: ")

DrawText(6,1,colors.yellow,colors.black,"$")

DrawText(7,1,colors.green,colors.black,pod)

DrawText(1,10,colors.green,colors.black,"Money: ")

DrawText(8,10,colors.yellow,colors.black,"$")

DrawText(9,10,colors.green,colors.black,Money)

if ButtonsOn then

DrawText(15,10,colors.orange,colors.blue," Bet ")

if CardsSelected[1] or CardsSelected[2] or CardsSelected[3] or CardsSelected[4] or CardsSelected[5] then  

HasCardsSelected = true

DrawText(23,10,colors.orange,colors.blue," Draw ")

else

DrawText(23,10,colors.orange,colors.blue," Hold ")

end

DrawText(32,10,colors.orange,colors.blue," Quit ")

DrawText(41,10,colors.orange,colors.blue," Help ")

end

end

function play()

while true do 

if CodeString=="200,200,208,208,203,205,203,205,48,30," then

if CodeTry==0 then

term.setCursorPos(1,18)

term.setTextColor(colors.white)

term.setBackgroundColor(colors.green)

textutils.slowPrint("Oh sorry, we're you expecting a cheat for maybe    9999 coins?")

sleep(1)

term.setCursorPos(13,18)

textutils.slowPrint("Or perhaps a cheat to see the other    player's cards?")

sleep(1)

term.setCursorPos(17,18)

textutils.slowPrint("Well, too bad.")

sleep(1)

CodeString = ""

CodeTry = CodeTry + 1

drawGUI()

elseif CodeTry==1 then

term.setCursorPos(1,18)

term.setTextColor(colors.white)

term.setBackgroundColor(colors.green)

textutils.slowPrint("Like I said, there are no cheats in this game. Stop trying!")

sleep(1)

CodeString = ""

CodeTry = CodeTry + 1

drawGUI()

elseif CodeTry==2 then

term.setCursorPos(1,18)

term.setTextColor(colors.white)

term.setBackgroundColor(colors.green)

textutils.slowPrint("You really are presistent are you?")

sleep(1)

term.setCursorPos(36,18)

term.setTextColor(colors.white)

term.setBackgroundColor(colors.green)

textutils.slowPrint("Look at your    money.")

sleep(1)

drawGUI()

DrawText(1,10,colors.green,colors.black,"Money: ")

DrawText(8,10,colors.yellow,colors.black,"$")

DrawText(9,10,colors.green,colors.black,"0   ")

sleep(2)

term.setCursorPos(1,18)

term.setTextColor(colors.white)

term.setBackgroundColor(colors.green)

textutils.slowPrint("Did it scare you?")

sleep(1)

term.setCursorPos(19,18)

term.setTextColor(colors.white)

term.setBackgroundColor(colors.green)

textutils.slowPrint("Good, don't cheat again!")

sleep(1)

CodeString = ""

drawGUI()

CodeTry = CodeTry + 1

elseif CodeTry==3 then

drawGUI()

end

elseif #CodeString > 38 then

CodeString = ""

end

local e = {os.pullEvent()}
  
if e[1]=="key" and e[1]~="key_up" then

CodeString = CodeString..e[2]..","
  
elseif e[1]=="mouse_click" and e[2]==1 then 

CodeString = ""

if e[3] >=32 and e[3] <=37 and e[4]==10 then

Money = Money + pod

Save()

term.setCursorPos(1,1)

term.setTextColor(colors.white)

term.setBackgroundColor(colors.black)

term.clear()

shell.setDir(CurrentDir)

error()

elseif e[3] >=15 and e[3] <=19 and e[4]==10 then 
  
if pod==5 then

sounds("bass")

DrawText(7,1,colors.green,colors.red,pod)

sleep(0.1)

DrawText(7,1,colors.green,colors.black,pod)

sleep(0.1)

DrawText(7,1,colors.green,colors.red,pod)

sleep(0.1)

DrawText(7,1,colors.green,colors.black,pod)

elseif Money==0 then 

sounds("bass")

DrawText(9,10,colors.green,colors.red,Money)

sleep(0.1)

DrawText(9,10,colors.green,colors.black,Money)

sleep(0.1)

DrawText(9,10,colors.green,colors.red,Money)

sleep(0.1)

DrawText(9,10,colors.green,colors.black,Money)

else
  
Money = Money - 1

pod = pod + 1
  
Save()

sounds("click")
  
drawGUI()

end
  
elseif e[3] >=23 and e[3] <=28 and e[4]==10 and HasCardsSelected then

ButtonsOn = false

sounds("harp")

ShuffleCards("draw")
  
elseif e[3] >=23 and e[3] <=28 and e[4]==10 and not HasCardsSelected then
  
HasCardsSelected = false
  
ButtonsOn = false
  
sounds("harp")

ShuffleCardsP2()
  
return OrganizeCards()
  
elseif e[3] >=41 and e[3] <=46 and e[4]==10 then

Help()
  
--[card 1]--
  
elseif e[3] >=6 and e[3] <=12 and e[4] >=12 and e[4] <=17 and not CardsSelected[1] then

HasCardsSelected = true

CardsSelected[1] = true

drawGUI()

elseif e[3] >=6 and e[3] <=12 and e[4] >=11 and e[4] <=16 and CardsSelected[1] then

HasCardsSelected = false

CardsSelected[1] = false

drawGUI()

--[card 2]--

elseif e[3] >=14 and e[3] <=20 and e[4] >=12 and e[4] <=17 and not CardsSelected[2] then

HasCardsSelected = true

CardsSelected[2] = true

drawGUI()

elseif e[3] >=14 and e[3] <=20 and e[4] >=11 and e[4] <=16 and CardsSelected[2] then

HasCardsSelected = false

CardsSelected[2] = false

drawGUI()
  
--[card 3]--
  
elseif e[3] >=22 and e[3] <=28 and e[4] >=12 and e[4] <=17 and not CardsSelected[3] then

HasCardsSelected = true

CardsSelected[3] = true

drawGUI()

elseif e[3] >=22 and e[3] <=28 and e[4] >=11 and e[4] <=16 and CardsSelected[3] then

HasCardsSelected = false

CardsSelected[3] = false

drawGUI()
  
--[card 4]--  
  
elseif e[3] >=30 and e[3] <=36 and e[4] >=12 and e[4] <=17 and not CardsSelected[4] then

HasCardsSelected = true

CardsSelected[4] = true

drawGUI()

elseif e[3] >=30 and e[3] <=36 and e[4] >=11 and e[4] <=16 and CardsSelected[4] then

HasCardsSelected = false

CardsSelected[4] = false

drawGUI()

--[card 5]--

elseif e[3] >=38 and e[3] <=44 and e[4] >=12 and e[4] <=17 and not CardsSelected[5] then

HasCardsSelected = true

CardsSelected[5] = true

drawGUI()
  
elseif e[3] >=38 and e[3] <=44 and e[4] >=11 and e[4] <=16 and CardsSelected[5] then

HasCardsSelected = false

CardsSelected[5] = false

drawGUI()
  
end
  end
    end
	  end
  
function ShuffleCards(boolean)

if boolean==textutils.unserialise("") then

CardsP1 = {}

CardsP1Images = {}

CardsP2 = {}

CardsP2Images = {}

local count = 0

for i = 1,5 do

local P1CardsDecide = math.random(1,6)

if P1CardsDecide==1 then

table.insert(CardsP1Images,i,flowercard)

table.insert(CardsSelectedType,i,"Flower")

table.insert(CardsP1,i,"flowercard")

FlowerAmmount = FlowerAmmount + 1

elseif P1CardsDecide==2 then

table.insert(CardsP1Images,i,pikecard)

table.insert(CardsSelectedType,i,"Pike")

table.insert(CardsP1,i,"pikecard")

PikeAmmount = PikeAmmount + 1

elseif P1CardsDecide==3 then

table.insert(CardsP1Images,i,heartcard)

table.insert(CardsSelectedType,i,"Heart")

table.insert(CardsP1,i,"heartcard")

HeartAmmount = HeartAmmount + 1

elseif P1CardsDecide==4 then

table.insert(CardsP1Images,i,starcard)

table.insert(CardsSelectedType,i,"Star")

table.insert(CardsP1,i,"starcard")

StarAmmount = StarAmmount + 1

elseif P1CardsDecide==5 then

table.insert(CardsP1Images,i,diamondcard)

table.insert(CardsSelectedType,i,"Diamond")

table.insert(CardsP1,i,"diamondcard")

DiamondAmmount = DiamondAmmount + 1

elseif P1CardsDecide==6 then

table.insert(CardsP1Images,i,clovercard)

table.insert(CardsSelectedType,i,"Clover")

table.insert(CardsP1,i,"clovercard")

CloverAmmount = CloverAmmount + 1

end
  end

for i = 1,5 do

local P2CardsDecide = math.random(1,6)

if P2CardsDecide==1 then

table.insert(CardsP2Images,i,flowercard)

table.insert(CardsP2,i,"flowercard")

FlowerAmmountP2 = FlowerAmmountP2 + 1

elseif P2CardsDecide==2 then

table.insert(CardsP2Images,i,pikecard)

table.insert(CardsP2,i,"pikecard")

PikeAmmountP2 = PikeAmmountP2 + 1

elseif P2CardsDecide==3 then

table.insert(CardsP2Images,i,heartcard)

table.insert(CardsP2,i,"heartcard")

HeartAmmountP2 = HeartAmmountP2 + 1

elseif P2CardsDecide==4 then

table.insert(CardsP2Images,i,starcard)

table.insert(CardsP2,i,"starcard")

StarAmmountP2 = StarAmmountP2 + 1

elseif P2CardsDecide==5 then

table.insert(CardsP2Images,i,diamondcard)

table.insert(CardsP2,i,"diamondcard")

DiamondAmmountP2 = DiamondAmmountP2 + 1

elseif P2CardsDecide==6 then

table.insert(CardsP2Images,i,clovercard)

table.insert(CardsP2,i,"clovercard")

CloverAmmountP2 = CloverAmmountP2 + 1

end
  end

CardsP2Ammount[1] = tonumber(StarAmmountP2)

CardsP2Ammount[2] = tonumber(DiamondAmmountP2)

CardsP2Ammount[3] = tonumber(HeartAmmountP2)

CardsP2Ammount[4] = tonumber(FlowerAmmountP2)

CardsP2Ammount[5] = tonumber(CloverAmmountP2)

CardsP2Ammount[6] = tonumber(PikeAmmountP2)
  
Money = Money - 1

pod = pod + 1

Save()

sleep(0.3)

drawGUI()

sounds("reveal")

return play()

elseif boolean=="draw" then

--Replace selected card with noting

for i = 1,5 do

if CardsP1[i]=="starcard" and CardsSelected[i] then

StarAmmount = StarAmmount - 1

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,NoCard)

elseif CardsP1[i]=="diamondcard" and CardsSelected[i] then

DiamondAmmount = DiamondAmmount - 1

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,NoCard)

elseif CardsP1[i]=="flowercard" and CardsSelected[i] then

FlowerAmmount = FlowerAmmount - 1

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,NoCard)

elseif CardsP1[i]=="clovercard" and CardsSelected[i] then

CloverAmmount = CloverAmmount - 1

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,NoCard)

elseif CardsP1[i]=="pikecard" and CardsSelected[i] then

PikeAmmount = PikeAmmount - 1

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,NoCard)

elseif CardsP1[i]=="heartcard" and CardsSelected[i] then

HeartAmmount = HeartAmmount - 1

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,NoCard)

else

i = i + 1

end
  end

NewCardsAnim = true
  
drawGUI()
  
--Replace nothing with backside

sleep(1)
  
for i = 1,5 do

if CardsP1[i]=="starcard" and CardsSelected[i] then

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,backside)

sleep(0.30)

sounds("click")

drawGUI()

elseif CardsP1[i]=="diamondcard" and CardsSelected[i] then

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,backside)

sleep(0.30)

sounds("click")

drawGUI()

elseif CardsP1[i]=="flowercard" and CardsSelected[i] then

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,backside)

sleep(0.30)

sounds("click")

drawGUI()

elseif CardsP1[i]=="clovercard" and CardsSelected[i] then

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,backside)

sleep(0.30)

sounds("click")

drawGUI()

elseif CardsP1[i]=="pikecard" and CardsSelected[i] then

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,backside)

sleep(0.30)

sounds("click")

drawGUI()

elseif CardsP1[i]=="heartcard" and CardsSelected[i] then

table.remove(CardsP1Images,i)

table.insert(CardsP1Images,i,backside)

sleep(0.30)

sounds("click")

drawGUI()

else

i = i + 1

end
  end
  
HasCardsSelected = false

count = 1

sCount = 1

drawGUI()

sleep(0.5)

count = 0

for i = 1,5 do

--[if not cards selected]--

if CardsP1[i]=="starcard" and not CardsSelected[i] then

table.insert(NewCardsP1,i,"starcard")

elseif CardsP1[i]=="diamondcard" and not CardsSelected[i] then

table.insert(NewCardsP1,i,"diamondcard")

elseif CardsP1[i]=="heartcard" and not CardsSelected[i] then

table.insert(NewCardsP1,i,"heartcard")

elseif CardsP1[i]=="flowercard" and not CardsSelected[i] then

table.insert(NewCardsP1,i,"flowercard")

elseif CardsP1[i]=="clovercard" and not CardsSelected[i] then

table.insert(NewCardsP1,i,"clovercard")

elseif CardsP1[i]=="pikecard" and not CardsSelected[i] then

table.insert(NewCardsP1,i,"pikecard")

--[else]--

elseif CardsSelected[i] then

local P1CardsDecide = math.random(1,6)

if P1CardsDecide==1 and CardsSelected[i] then

table.insert(NewCardsP1,i,"flowercard")

FlowerAmmount = FlowerAmmount + 1

elseif P1CardsDecide==2 and CardsSelected[i] then

table.insert(NewCardsP1,i,"pikecard")

PikeAmmount = PikeAmmount + 1

elseif P1CardsDecide==3 and CardsSelected[i] then

table.insert(NewCardsP1,i,"heartcard")

HeartAmmount = HeartAmmount + 1

elseif P1CardsDecide==4 and CardsSelected[i] then

table.insert(NewCardsP1,i,"starcard")

StarAmmount = StarAmmount + 1

elseif P1CardsDecide==5 and CardsSelected[i] then

table.insert(NewCardsP1,i,"diamondcard")

DiamondAmmount = DiamondAmmount + 1

elseif P1CardsDecide==6 and CardsSelected[i] then

table.insert(NewCardsP1,i,"clovercard")

CloverAmmount = CloverAmmount + 1

end
  end
    end

--[set's the image table]--
	
CardsP1Images = {}
	
for i = 1,5 do

if NewCardsP1[i]=="starcard" then

table.insert(CardsP1Images,i,starcard)

elseif NewCardsP1[i]=="diamondcard" then

table.insert(CardsP1Images,i,diamondcard)

elseif NewCardsP1[i]=="heartcard" then

table.insert(CardsP1Images,i,heartcard)

elseif NewCardsP1[i]=="flowercard" then

table.insert(CardsP1Images,i,flowercard)

elseif NewCardsP1[i]=="clovercard" then

table.insert(CardsP1Images,i,clovercard)

elseif NewCardsP1[i]=="pikecard" then

table.insert(CardsP1Images,i,pikecard)
	
end
  end
    end

for i = 1,5 do

if CardsSelected[i] then

CardsSelected[i] = false

end
  end

NewCardsAnim = false
  
HasNewCards = true
  
sounds("reveal")
  
drawGUI()

sleep(1)

return ShuffleCardsP2()

end

function ShuffleCardsP2()

--[~Shuffle's Player 2's cards]--

for i = 1,6 do

if CardsP2Ammount[i]==1 then

CardsExchangeP2[i] = true

else

i = i + 1

end
  end

if CardsExchangeP2[1] and CardsExchangeP2[2] and CardsExchangeP2[3] and CardsExchangeP2[4] and CardsExchangeP2[5] and CardsExchangeP2[6] then

return OrganizeCards()
 
end
 
for i = 1,6 do

if CardsExchangeP2[i]==true then

count = i

if count==1 then --star

if CardsP2Images[1]==starcard then

table.remove(CardsP2Images,1)
table.insert(CardsP2Images,1,NoCard)

elseif CardsP2Images[2]==starcard then

table.remove(CardsP2Images,2)
table.insert(CardsP2Images,2,NoCard)

elseif CardsP2Images[3]==starcard then

table.remove(CardsP2Images,3)
table.insert(CardsP2Images,3,NoCard)

elseif CardsP2Images[4]==starcard then

table.remove(CardsP2Images,4)
table.insert(CardsP2Images,4,NoCard)

elseif CardsP2Images[5]==starcard then

table.remove(CardsP2Images,5)
table.insert(CardsP2Images,5,NoCard)

end

elseif count==2 then --diamond

if CardsP2Images[1]==diamondcard then

table.remove(CardsP2Images,1)
table.insert(CardsP2Images,1,NoCard)

elseif CardsP2Images[2]==diamondcard then

table.remove(CardsP2Images,2)
table.insert(CardsP2Images,2,NoCard)

elseif CardsP2Images[3]==diamondcard then

table.remove(CardsP2Images,3)
table.insert(CardsP2Images,3,NoCard)

elseif CardsP2Images[4]==diamondcard then

table.remove(CardsP2Images,4)
table.insert(CardsP2Images,4,NoCard)

elseif CardsP2Images[5]==diamondcard then

table.remove(CardsP2Images,5)
table.insert(CardsP2Images,5,NoCard)

end

elseif count==3 then --heart

if CardsP2Images[1]==heartcard then

table.remove(CardsP2Images,1)
table.insert(CardsP2Images,1,NoCard)

elseif CardsP2Images[2]==heartcard then

table.remove(CardsP2Images,2)
table.insert(CardsP2Images,2,NoCard)

elseif CardsP2Images[3]==heartcard then

table.remove(CardsP2Images,3)
table.insert(CardsP2Images,3,NoCard)

elseif CardsP2Images[4]==heartcard then

table.remove(CardsP2Images,4)
table.insert(CardsP2Images,4,NoCard)

elseif CardsP2Images[5]==heartcard then

table.remove(CardsP2Images,5)
table.insert(CardsP2Images,5,NoCard)

end

elseif count==4 then --flower

if CardsP2Images[1]==flowercard then

table.remove(CardsP2Images,1)
table.insert(CardsP2Images,1,NoCard)

elseif CardsP2Images[2]==flowercard then

table.remove(CardsP2Images,2)
table.insert(CardsP2Images,2,NoCard)

elseif CardsP2Images[3]==flowercard then

table.remove(CardsP2Images,3)
table.insert(CardsP2Images,3,NoCard)

elseif CardsP2Images[4]==flowercard then

table.remove(CardsP2Images,4)
table.insert(CardsP2Images,4,NoCard)

elseif CardsP2Images[5]==flowercard then

table.remove(CardsP2Images,5)
table.insert(CardsP2Images,5,NoCard)

end

elseif count==5 then --clover

if CardsP2Images[1]==clovercard then

table.remove(CardsP2Images,1)
table.insert(CardsP2Images,1,NoCard)

elseif CardsP2Images[2]==clovercard then

table.remove(CardsP2Images,2)
table.insert(CardsP2Images,2,NoCard)

elseif CardsP2Images[3]==clovercard then

table.remove(CardsP2Images,3)
table.insert(CardsP2Images,3,NoCard)

elseif CardsP2Images[4]==clovercard then

table.remove(CardsP2Images,4)
table.insert(CardsP2Images,4,NoCard)

elseif CardsP2Images[5]==clovercard then

table.remove(CardsP2Images,5)
table.insert(CardsP2Images,5,NoCard)

end

elseif count==6 then --pike

if CardsP2Images[1]==pikecard then

table.remove(CardsP2Images,1)
table.insert(CardsP2Images,1,NoCard)

elseif CardsP2Images[2]==pikecard then

table.remove(CardsP2Images,2)
table.insert(CardsP2Images,2,NoCard)

elseif CardsP2Images[3]==pikecard then

table.remove(CardsP2Images,3)
table.insert(CardsP2Images,3,NoCard)

elseif CardsP2Images[4]==pikecard then

table.remove(CardsP2Images,4)
table.insert(CardsP2Images,4,NoCard)

elseif CardsP2Images[5]==pikecard then

table.remove(CardsP2Images,5)
table.insert(CardsP2Images,5,NoCard)

end

else

i = i + 1

end
  end
    end

NewCardsAnimP2 = true
	
drawGUI()
  
sleep(1)

CardsExchangeP2 = {[1] = false,[2] = false,[3] = false,[4] = false,[5] = false,[6] = false}

for i = 1,6 do

if CardsP2Images[i]==NoCard then

CardsExchangeP2[i] = true

else

i = i + 1

end
  end

for i = 1,6 do

if CardsP2[i]=="starcard" and CardsP2Images[i]==NoCard then

table.remove(CardsP2Images,i)

table.insert(CardsP2Images,i,backside)

StarAmmountP2 = StarAmmountP2 - 1

sleep(0.30)

sounds("click")

drawGUI()

elseif CardsP2[i]=="diamondcard" and CardsP2Images[i]==NoCard then

table.remove(CardsP2Images,i)

table.insert(CardsP2Images,i,backside)

DiamondAmmountP2 = DiamondAmmountP2 - 1

sleep(0.30)

sounds("click")

drawGUI()

elseif CardsP2[i]=="flowercard" and CardsP2Images[i]==NoCard then

table.remove(CardsP2Images,i)

table.insert(CardsP2Images,i,backside)

FlowerAmmountP2 = FlowerAmmountP2 - 1

sleep(0.30)

sounds("click")

drawGUI()

elseif CardsP2[i]=="clovercard" and CardsP2Images[i]==NoCard then

table.remove(CardsP2Images,i)

table.insert(CardsP2Images,i,backside)

CloverAmmountP2 = CloverAmmountP2 - 1

sleep(0.30)

sounds("click")

drawGUI()

elseif CardsP2[i]=="pikecard" and CardsP2Images[i]==NoCard then

table.remove(CardsP2Images,i)

table.insert(CardsP2Images,i,backside)

PikeAmmountP2 = PikeAmmountP2 - 1

sleep(0.30)

sounds("click")

drawGUI()

elseif CardsP2[i]=="heartcard" and CardsP2Images[i]==NoCard then

table.remove(CardsP2Images,i)

table.insert(CardsP2Images,i,backside)

HeartAmmountP2 = HeartAmmountP2 - 1

sleep(0.30)

sounds("click")

drawGUI()

else

i = i + 1

end
  end

drawGUI()

sleep(0.5)
 
for i = 1,6 do

--[if not cards selected]--

if CardsP2[i]=="starcard" and not CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"starcard")

elseif CardsP2[i]=="diamondcard" and not CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"diamondcard")

elseif CardsP2[i]=="heartcard" and not CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"heartcard")

elseif CardsP2[i]=="flowercard" and not CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"flowercard")

elseif CardsP2[i]=="clovercard" and not CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"clovercard")

elseif CardsP2[i]=="pikecard" and not CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"pikecard")

--[else]--

elseif CardsExchangeP2[i] then

local P1CardsDecide = math.random(1,6)

if P1CardsDecide==1 and CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"flowercard")

FlowerAmmountP2 = FlowerAmmountP2 + 1

elseif P1CardsDecide==2 and CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"pikecard")

PikeAmmountP2 = PikeAmmountP2 + 1

elseif P1CardsDecide==3 and CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"heartcard")

HeartAmmountP2 = HeartAmmountP2 + 1

elseif P1CardsDecide==4 and CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"starcard")

StarAmmountP2 = StarAmmountP2 + 1

elseif P1CardsDecide==5 and CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"diamondcard")

DiamondAmmountP2 = DiamondAmmountP2 + 1

elseif P1CardsDecide==6 and CardsExchangeP2[i] then

table.insert(NewCardsP2,i,"clovercard")

CloverAmmountP2 = CloverAmmountP2 + 1

end
  end
    end
	
CardsP2Images = {}
	
for i = 1,6 do

if NewCardsP2[i]=="starcard" then

table.insert(CardsP2Images,i,starcard)

elseif NewCardsP2[i]=="diamondcard" then

table.insert(CardsP2Images,i,diamondcard)

elseif NewCardsP2[i]=="heartcard" then

table.insert(CardsP2Images,i,heartcard)

elseif NewCardsP2[i]=="flowercard" then

table.insert(CardsP2Images,i,flowercard)

elseif NewCardsP2[i]=="clovercard" then

table.insert(CardsP2Images,i,clovercard)

elseif NewCardsP2[i]=="pikecard" then

table.insert(CardsP2Images,i,pikecard)
	
end
  end
 
return OrganizeCards()

end
  
function begin()

ButtonsOn = false

drawGUI() 

local count = 1

sleep(0.5)

repeat

table.remove(CardsP2Images,count)
table.insert(CardsP2Images,count,backside)
table.remove(CardsP2,count)
table.insert(CardsP2,count,"backside")

count = count + 1

drawGUI()

sounds("click")

sleep(0.20)

until count==6

CardsRevealP2 = false

sleep(0.20)

count = 1

repeat

table.remove(CardsP1Images,count)
table.insert(CardsP1Images,count,backside)
table.remove(CardsP1,count)
table.insert(CardsP1,count,"backside")

count = count + 1

drawGUI()

sounds("click")

sleep(0.20)

until count==6

sleep(0.3)

ButtonsOn = true

ShuffleCards()

end

function Help()

local CurrentRule = "Info"

function Info()

term.setBackgroundColour(colors.green)

term.clear()

DrawText(1,1,colors.green,colors.blue,"Picture Poker is a single-player minigame in")

DrawText(1,2,colors.green,colors.blue,"Super Mario 64 DS and New Super Mario Bros.")

DrawText(1,4,colors.green,colors.blue,"Get a better hand than Player 2 to win!")

DrawText(1,5,colors.green,colors.blue,"If you're confident that your hand's the best,")

DrawText(1,6,colors.green,colors.blue,"increase the number of coins you bet!")

DrawText(1,8,colors.green,colors.blue,"If the player's hand is better, they win a set")

DrawText(1,9,colors.green,colors.blue,"amount of coins based on both the rank of his or")

DrawText(1,10,colors.green,colors.blue,"her hand and the amount of coins bet.")

DrawText(1,11,colors.green,colors.blue,"Otherwise, you'll lose the coins you've bet.")

DrawText(1,17,colors.green,colors.blue,"Source: http://www.mariowiki.com/Picture_Poker")

DrawText(2,19,colors.orange,colors.blue," Back ")

DrawText(centered,19,colors.orange,colors.blue," Close ")

DrawText(45,19,colors.orange,colors.blue," Next ")

end

function Cards()

term.setBackgroundColour(colors.green)

term.clear()

DrawText(1,1,colors.green,colors.blue,"In the game, there are 6 different cards.")

DrawText(1,3,colors.green,colors.blue,"Here are the cards from best (left),")

DrawText(1,4,colors.green,colors.blue,"to worst (right).")

DrawText(3,8,colors.green,colors.blue,"Star")

DrawText(10,8,colors.green,colors.blue,"Diamond")

DrawText(19,8,colors.green,colors.blue,"Heart")

DrawText(27,8,colors.green,colors.blue,"Flower")

DrawText(35,8,colors.green,colors.blue,"Clover")

DrawText(43,8,colors.green,colors.blue,"Pike")

blittle.draw(starcard,2,10)

blittle.draw(diamondcard,10,10)

blittle.draw(heartcard,18,10)

blittle.draw(flowercard,26,10)

blittle.draw(clovercard,34,10)

blittle.draw(pikecard,42,10)

DrawText(2,19,colors.orange,colors.blue," Back ")

DrawText(centered,19,colors.orange,colors.blue," Close ")

DrawText(45,19,colors.orange,colors.blue," Next ")

end

function Values()

term.setBackgroundColour(colors.green)

term.clear()

DrawText(1,1,colors.green,colors.blue,"Here are the rankings and values.")

blittle.draw(starcard,2,3)

blittle.draw(starcard,10,3)

blittle.draw(starcard,18,3)

blittle.draw(starcard,26,3)

blittle.draw(starcard,34,3)

DrawText(44,6,colors.green,colors.blue,"= 16")

blittle.draw(starcard,2,11)

blittle.draw(starcard,10,11)

blittle.draw(starcard,18,11)

blittle.draw(starcard,26,11)

DrawText(44,15,colors.green,colors.blue,"= 8")

DrawText(2,19,colors.orange,colors.blue," Back ")

DrawText(centered,19,colors.orange,colors.blue," Close ")

DrawText(45,19,colors.orange,colors.blue," Next ")

end

function Values2()

term.setBackgroundColour(colors.green)

term.clear()

blittle.draw(starcard,2,3)

blittle.draw(starcard,10,3)

blittle.draw(starcard,18,3)

blittle.draw(diamondcard,26,3)

blittle.draw(diamondcard,34,3)

DrawText(44,6,colors.green,colors.blue,"= 6")

blittle.draw(starcard,2,11)

blittle.draw(starcard,10,11)

blittle.draw(starcard,18,11)

DrawText(44,15,colors.green,colors.blue,"= 4")

DrawText(2,19,colors.orange,colors.blue," Back ")

DrawText(centered,19,colors.orange,colors.blue," Close ")

DrawText(45,19,colors.orange,colors.blue," Next ")

end

function Values3()

term.setBackgroundColour(colors.green)

term.clear()

blittle.draw(starcard,2,3)

blittle.draw(starcard,10,3)

blittle.draw(diamondcard,18,3)

blittle.draw(diamondcard,26,3)

DrawText(44,6,colors.green,colors.blue,"= 3")

blittle.draw(starcard,2,11)

blittle.draw(starcard,10,11)

DrawText(44,15,colors.green,colors.blue,"= 2")

DrawText(2,19,colors.orange,colors.blue," Back ")

DrawText(centered,19,colors.orange,colors.blue," Close ")

DrawText(45,19,colors.orange,colors.blue," Next ")

end

function Scoring()

term.setBackgroundColour(colors.green)

term.clear()

DrawText(1,1,colors.green,colors.blue,"Here are the card rankings you can win with.")

DrawText(1,2,colors.green,colors.blue,"From best (top), to worst (bottom).")

DrawText(centered,5,colors.green,colors.blue,"Five Of A Kind")

DrawText(centered,7,colors.green,colors.blue,"Four Of A Kind")

DrawText(centered,9,colors.green,colors.blue,"Full House")

DrawText(centered,11,colors.green,colors.blue,"Three Of A Kind")

DrawText(centered,13,colors.green,colors.blue,"Two Pair")

DrawText(centered,15,colors.green,colors.blue,"One Pair")

DrawText(2,19,colors.orange,colors.blue," Back ")

DrawText(centered,19,colors.orange,colors.blue," Close ")

DrawText(45,19,colors.orange,colors.blue," Next ")

end

function Scoring2()

term.setBackgroundColour(colors.green)

term.clear()

DrawText(1,1,colors.green,colors.blue,"If both your and Player 2's cards are the exact")

DrawText(1,2,colors.green,colors.blue,"same, the match is a draw. In that case, you get")

DrawText(1,3,colors.green,colors.blue,"the money back you bet, and the match will restart.")

DrawText(1,5,colors.green,colors.blue,"Otherwise, if you and Player 2 have the same card")

DrawText(1,6,colors.green,colors.blue,"ranking, the program looks for the Player with the")

DrawText(1,7,colors.green,colors.blue,"best cards. For an example, go to the next page.")

DrawText(2,19,colors.orange,colors.blue," Back ")

DrawText(centered,19,colors.orange,colors.blue," Close ")

DrawText(45,19,colors.orange,colors.blue," Next ")

end

function Example()

term.setBackgroundColour(colors.green)

term.clear()

blittle.draw(flowercard,2,2)

blittle.draw(flowercard,10,2)

blittle.draw(flowercard,18,2)

blittle.draw(diamondcard,26,2)

blittle.draw(diamondcard,34,2)

DrawText(centered,1,colors.green,colors.blue,"Player 2's cards")

blittle.draw(starcard,2,10)

blittle.draw(starcard,10,10)

blittle.draw(starcard,18,10)

blittle.draw(diamondcard,26,10)

blittle.draw(diamondcard,34,10)

DrawText(centered,17,colors.green,colors.blue,"Your cards")

DrawText(1,18,colors.green,colors.blue,"You win, since star is better than flower.")

DrawText(2,19,colors.orange,colors.blue," Back ")

DrawText(centered,19,colors.orange,colors.blue," Close ")

DrawText(45,19,colors.orange,colors.blue," Next ")

end

function CardSelect()

term.setBackgroundColour(colors.green)

term.clear()

DrawText(1,1,colors.green,colors.blue,"To get rid of a card, simply click on the card")

DrawText(1,2,colors.green,colors.blue,"you want to get rid of. When you click on your")

DrawText(1,3,colors.green,colors.blue,"desired card, it is being drawn one pixel higher.")

DrawText(1,4,colors.green,colors.blue,"And the hold button changes into draw. If you want")

DrawText(1,5,colors.green,colors.blue,"to keep the card, simply click on the card again.")

DrawText(1,6,colors.green,colors.blue,"When you are ready, click on the hold/draw button.")

DrawText(2,19,colors.orange,colors.blue," Back ")

DrawText(centered,19,colors.orange,colors.blue," Close ")

DrawText(45,19,colors.orange,colors.blue," Next ")

end

function InstallSounds()

term.setBackgroundColour(colors.green)

term.clear()

DrawText(1,1,colors.green,colors.blue,"If you want to install sounds, that's possible!")

DrawText(1,3,colors.green,colors.blue,"1. Place a glass block on the ground, to the left")

DrawText(1,4,colors.green,colors.blue,"of the computer. Put a noteblock on top of the")

DrawText(1,5,colors.green,colors.blue,"glass. This will make the \"click\" noise.")

DrawText(1,7,colors.green,colors.blue,"2. Place a dirt block on the ground, to the right")

DrawText(1,8,colors.green,colors.blue,"of the computer. Put a noteblock on top of that")

DrawText(1,9,colors.green,colors.blue,"block. This will make the harp/piano noise.")

DrawText(1,11,colors.green,colors.blue,"3. Last, put a wood plank block on the ground,")

DrawText(1,12,colors.green,colors.blue,"at the back of the computer. This is the double")

DrawText(1,13,colors.green,colors.blue,"bass sound. It will play when you have lost.")

DrawText(1,15,colors.green,colors.blue,"4. Keep right-clicking the noteblock's to adjust")

DrawText(1,16,colors.green,colors.blue,"the pitch. After you done all that, restart the")

DrawText(1,17,colors.green,colors.blue,"game and the sounds has been installed.")

DrawText(2,19,colors.orange,colors.blue," Back ")

DrawText(centered,19,colors.orange,colors.blue," Close ")

end

Info()

while true do

local e = {os.pullEvent()}

if e[1]=="mouse_click" and e[2]==1 then 

if e[3] >=2 and e[3] <=7 and e[4]==19 then

if CurrentRule=="Info" then

drawGUI()

return

elseif CurrentRule=="Cards" then

CurrentRule = "Info"

Info()

elseif CurrentRule=="Values" then

CurrentRule = "Cards"

Cards()

elseif CurrentRule=="Values 2" then

CurrentRule = "Values"

Values()

elseif CurrentRule=="Values 3" then

CurrentRule = "Values 2"

Values2()

elseif CurrentRule=="Scoring" then

CurrentRule = "Values 3"

Values3()

elseif CurrentRule=="Scoring 2" then

CurrentRule = "Scoring"

Scoring()

elseif CurrentRule=="Example" then

CurrentRule = "Scoring 2"

Scoring2()

elseif CurrentRule=="CardSelect" then

CurrentRule = "Example"

Example()

elseif CurrentRule=="InstallSounds" then

CurrentRule = "CardSelect"

CardSelect()

end

elseif e[3] >=45 and e[3] <=50 and e[4]==19 then

if CurrentRule=="Info" then

CurrentRule = "Cards"

Cards()

elseif CurrentRule=="Cards" then

CurrentRule = "Values"

Values()

elseif CurrentRule=="Values" then

CurrentRule = "Values 2"

Values2()

elseif CurrentRule=="Values 2" then

CurrentRule = "Values 3" 

Values3()

elseif CurrentRule=="Values 3" then

CurrentRule = "Scoring"

Scoring()

elseif CurrentRule=="Scoring" then 

CurrentRule = "Scoring 2"

Scoring2()

elseif CurrentRule=="Scoring 2" then

CurrentRule = "Example"

Example()

elseif CurrentRule=="Example" then

CurrentRule = "CardSelect"

CardSelect()

elseif CurrentRule=="CardSelect" then

CurrentRule ="InstallSounds"

InstallSounds()

end

elseif e[3] >=21 and e[3] <=27 and e[4]==19 then

drawGUI()

return

end
  end
    end
  
end

function OrganizeCards()

count = 0

tCount = 1

sCount = 0

while sCount <=5 do

if StarAmmount >= FlowerAmmount and StarAmmount >= PikeAmmount and StarAmmount >= HeartAmmount and StarAmmount >= CloverAmmount and StarAmmount >= DiamondAmmount then

for r = 1,StarAmmount do

table.insert(CardsP1Organized,tCount,"starcard")

table.insert(CardsP1OrganizedImages,tCount,starcard)

tCount = tCount + 1

StarAmmount = StarAmmount - 1

end

StarAmmount = 0

count = count + 1

sCount = sCount + 1

elseif DiamondAmmount >= FlowerAmmount and DiamondAmmount >= CloverAmmount and DiamondAmmount >= StarAmmount and DiamondAmmount >= HeartAmmount and DiamondAmmount >= PikeAmmount then

for t = 1,DiamondAmmount do

table.insert(CardsP1Organized,tCount,"diamondcard")

table.insert(CardsP1OrganizedImages,tCount,diamondcard)

tCount = tCount + 1

DiamondAmmount = DiamondAmmount - 1

end

DiamondAmmount = 0

count = count + 1

sCount = sCount + 1

elseif HeartAmmount >= FlowerAmmount and HeartAmmount >= CloverAmmount and HeartAmmount >= DiamondAmmount and HeartAmmount >= StarAmmount and HeartAmmount >= PikeAmmount then 

for h = 1,HeartAmmount do

table.insert(CardsP1Organized,tCount,"heartcard")

table.insert(CardsP1OrganizedImages,tCount,heartcard)

tCount = tCount + 1

HeartAmmount = HeartAmmount - 1

end

HeartAmmount = 0

count = count + 1

sCount = sCount + 1

elseif FlowerAmmount >= HeartAmmount and FlowerAmmount >= CloverAmmount and FlowerAmmount >= DiamondAmmount and FlowerAmmount >= StarAmmount and FlowerAmmount >= PikeAmmount then

for f = 1,FlowerAmmount do

table.insert(CardsP1Organized,tCount,"flowercard")

table.insert(CardsP1OrganizedImages,tCount,flowercard)

tCount = tCount + 1

FlowerAmmount = FlowerAmmount - 1

end

FlowerAmmount = 0

count = count + 1

sCount = sCount + 1

elseif CloverAmmount >= HeartAmmount and CloverAmmount >= FlowerAmmount and CloverAmmount >= DiamondAmmount and CloverAmmount >= StarAmmount and CloverAmmount >= PikeAmmount then

for c = 1,CloverAmmount do

table.insert(CardsP1Organized,tCount,"clovercard")

table.insert(CardsP1OrganizedImages,tCount,clovercard)

tCount = tCount + 1

CloverAmmount = CloverAmmount - 1

end

CloverAmmount = 0

count = count + 1

sCount = sCount + 1

elseif PikeAmmount >= FlowerAmmount and PikeAmmount >= CloverAmmount and PikeAmmount >= StarAmmount and PikeAmmount >= HeartAmmount and PikeAmmount >= PikeAmmount then

for s = 1,PikeAmmount do

table.insert(CardsP1Organized,tCount,"pikecard")

table.insert(CardsP1OrganizedImages,tCount,pikecard)

tCount = tCount + 1

PikeAmmount = PikeAmmount - 1

end

PikeAmmount = 0

count = count + 1

sCount = sCount + 1

end
  end
  
CardsOrganized = true
  
drawGUI()

sleep(0.5)

MakeString()

end

function MakeString()

for i = 1,5 do

if CardsP1Organized[i]=="starcard" then

if #CardsP1Organized_str <=1 then 

CardsP1Organized_str = CardsP1Organized_str.."star"

else

CardsP1Organized_str = CardsP1Organized_str..",star"

end

elseif CardsP1Organized[i]=="diamondcard" then 

if #CardsP1Organized_str <=1 then 

CardsP1Organized_str = CardsP1Organized_str.."diamond"

else

CardsP1Organized_str = CardsP1Organized_str..",diamond"

end

elseif CardsP1Organized[i]=="heartcard" then 

if #CardsP1Organized_str <=1 then 

CardsP1Organized_str = CardsP1Organized_str.."heart"

else

CardsP1Organized_str = CardsP1Organized_str..",heart"

end

elseif CardsP1Organized[i]=="flowercard" then 

if #CardsP1Organized_str <=1 then 

CardsP1Organized_str = CardsP1Organized_str.."flower"

else

CardsP1Organized_str = CardsP1Organized_str..",flower"

end

elseif CardsP1Organized[i]=="clovercard" then 

if #CardsP1Organized_str <=1 then 

CardsP1Organized_str = CardsP1Organized_str.."clover"

else

CardsP1Organized_str = CardsP1Organized_str..",clover"

end

elseif CardsP1Organized[i]=="pikecard" then 

if #CardsP1Organized_str <=1 then 

CardsP1Organized_str = CardsP1Organized_str.."pike"

else

CardsP1Organized_str = CardsP1Organized_str..",pike"

end
  end
    end

OrganizeCardsP2()

end

function OrganizeCardsP2()
 
count = 0

tCount = 1

sCount = 0

while sCount <=5 do

if StarAmmountP2 >= FlowerAmmountP2 and StarAmmountP2 >= PikeAmmountP2 and StarAmmountP2 >= HeartAmmountP2 and StarAmmountP2 >= CloverAmmountP2 and StarAmmountP2 >= DiamondAmmountP2 then

for r = 1,StarAmmountP2 do

table.insert(CardsP2Organized,tCount,"starcard")

table.insert(CardsP2OrganizedImages,tCount,starcard)

tCount = tCount + 1

StarAmmountP2 = StarAmmountP2 - 1

end

StarAmmountP2 = 0

count = count + 1

sCount = sCount + 1

elseif DiamondAmmountP2 >= FlowerAmmountP2 and DiamondAmmountP2 >= CloverAmmountP2 and DiamondAmmountP2 >= StarAmmountP2 and DiamondAmmountP2 >= HeartAmmountP2 and DiamondAmmountP2 >= PikeAmmountP2 then

for t = 1,DiamondAmmountP2 do

table.insert(CardsP2Organized,tCount,"diamondcard")

table.insert(CardsP2OrganizedImages,tCount,diamondcard)

tCount = tCount + 1

DiamondAmmountP2 = DiamondAmmountP2 - 1

end

DiamondAmmountP2 = 0

count = count + 1

sCount = sCount + 1

elseif HeartAmmountP2 >= FlowerAmmountP2 and HeartAmmountP2 >= CloverAmmountP2 and HeartAmmountP2 >= DiamondAmmountP2 and HeartAmmountP2 >= StarAmmountP2 and HeartAmmountP2 >= PikeAmmountP2 then 

for h = 1,HeartAmmountP2 do

table.insert(CardsP2Organized,tCount,"heartcard")

table.insert(CardsP2OrganizedImages,tCount,heartcard)

tCount = tCount + 1

HeartAmmountP2 = HeartAmmountP2 - 1

end

HeartAmmountP2 = 0

count = count + 1

sCount = sCount + 1

elseif FlowerAmmountP2 >= HeartAmmountP2 and FlowerAmmountP2 >= CloverAmmountP2 and FlowerAmmountP2 >= DiamondAmmountP2 and FlowerAmmountP2 >= StarAmmountP2 and FlowerAmmountP2 >= PikeAmmountP2 then

for f = 1,FlowerAmmountP2 do

table.insert(CardsP2Organized,tCount,"flowercard")

table.insert(CardsP2OrganizedImages,tCount,flowercard)

tCount = tCount + 1

FlowerAmmountP2 = FlowerAmmountP2 - 1

end

FlowerAmmountP2 = 0

count = count + 1

sCount = sCount + 1

elseif CloverAmmountP2 >= HeartAmmountP2 and CloverAmmountP2 >= FlowerAmmountP2 and CloverAmmountP2 >= DiamondAmmountP2 and CloverAmmountP2 >= StarAmmountP2 and CloverAmmountP2 >= PikeAmmountP2 then

for c = 1,CloverAmmountP2 do

table.insert(CardsP2Organized,tCount,"clovercard")

table.insert(CardsP2OrganizedImages,tCount,clovercard)

tCount = tCount + 1

CloverAmmountP2 = CloverAmmountP2 - 1

end

CloverAmmountP2 = 0

count = count + 1

sCount = sCount + 1

elseif PikeAmmountP2 >= FlowerAmmountP2 and PikeAmmountP2 >= CloverAmmountP2 and PikeAmmountP2 >= StarAmmountP2 and PikeAmmountP2 >= HeartAmmountP2 and PikeAmmountP2 >= PikeAmmountP2 then

for s = 1,PikeAmmountP2 do

table.insert(CardsP2Organized,tCount,"pikecard")

table.insert(CardsP2OrganizedImages,tCount,pikecard)

tCount = tCount + 1

PikeAmmountP2 = PikeAmmountP2 - 1

end

PikeAmmountP2 = 0

count = count + 1

sCount = sCount + 1

end
  end

CardsOrganizedP2 = true
  
sleep(0.5)

CardsRevealP2 = true

sounds("harp")