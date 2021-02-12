drawGUI()

MakeStringP2()

end

function MakeStringP2()

for i = 1,5 do

if CardsP2Organized[i]=="starcard" then

if #CardsP2Organized_str <=1 then 

CardsP2Organized_str = CardsP2Organized_str.."star"

else

CardsP2Organized_str = CardsP2Organized_str..",star"

end

elseif CardsP2Organized[i]=="diamondcard" then 

if #CardsP2Organized_str <=1 then 

CardsP2Organized_str = CardsP2Organized_str.."diamond"

else

CardsP2Organized_str = CardsP2Organized_str..",diamond"

end

elseif CardsP2Organized[i]=="heartcard" then 

if #CardsP2Organized_str <=1 then 

CardsP2Organized_str = CardsP2Organized_str.."heart"

else

CardsP2Organized_str = CardsP2Organized_str..",heart"

end

elseif CardsP2Organized[i]=="flowercard" then 

if #CardsP2Organized_str <=1 then 

CardsP2Organized_str = CardsP2Organized_str.."flower"

else

CardsP2Organized_str = CardsP2Organized_str..",flower"

end

elseif CardsP2Organized[i]=="clovercard" then 

if #CardsP2Organized_str <=1 then 

CardsP2Organized_str = CardsP2Organized_str.."clover"

else

CardsP2Organized_str = CardsP2Organized_str..",clover"

end

elseif CardsP2Organized[i]=="pikecard" then 

if #CardsP2Organized_str <=1 then 

CardsP2Organized_str = CardsP2Organized_str.."pike"

else

CardsP2Organized_str = CardsP2Organized_str..",pike"

end
  end
    end
	
DecideWinner()
	
      end

function MakeSets()

--[royal flush]--

if CardsP1Organized[1]=="starcard" then

for i = 1,5 do

if #rf_str <=1 then 

rf_str = rf_str.."star"

else

rf_str = rf_str..",star"

end
  end

elseif CardsP1Organized[1]=="diamondcard" then

for i = 1,5 do

if #rf_str <=1 then 

rf_str = rf_str.."diamond"

else

rf_str = rf_str..",diamond"

end
  end

elseif CardsP1Organized[1]=="heartcard" then

for i = 1,5 do

if #rf_str <=1 then 

rf_str = rf_str.."heart"

else

rf_str = rf_str..",heart"

end
  end

elseif CardsP1Organized[1]=="flowercard" then

for i = 1,5 do

if #rf_str <=1 then 

rf_str = rf_str.."flower"

else

rf_str = rf_str..",flower"

end
  end

elseif CardsP1Organized[1]=="clovercard" then

for i = 1,5 do

if #rf_str <=1 then 

rf_str = rf_str.."clover"

else

rf_str = rf_str..",clover"

end
  end

elseif CardsP1Organized[1]=="pikecard" then

for i = 1,5 do

if #rf_str <=1 then 

rf_str = rf_str.."pike"

else

rf_str = rf_str..",pike"

end
  end
    end

--[four of a kind]--

if CardsP1Organized[1]=="starcard" then

for i = 1,4 do

if #foak_str <=1 then 

foak_str = foak_str.."star"

else

foak_str = foak_str..",star"

end 
  end

elseif CardsP1Organized[1]=="diamondcard" then

for i = 1,4 do

if #foak_str <=1 then 

foak_str = foak_str.."diamond"

else

foak_str = foak_str..",diamond"

end 
  end

elseif CardsP1Organized[1]=="heartcard" then

for i = 1,4 do

if #foak_str <=1 then 

foak_str = foak_str.."heart"

else

foak_str = foak_str..",heart"

end 
  end

elseif CardsP1Organized[1]=="flowercard" then

for i = 1,4 do

if #foak_str <=1 then 

foak_str = foak_str.."flower"

else

foak_str = foak_str..",flower"

end 
  end

elseif CardsP1Organized[1]=="clovercard" then

for i = 1,4 do

if #foak_str <=1 then 

foak_str = foak_str.."clover"

else

foak_str = foak_str..",clover"

end 
  end

elseif CardsP1Organized[1]=="pikecard" then

for i = 1,4 do

if #foak_str <=1 then 

foak_str = foak_str.."pike"

else

foak_str = foak_str..",pike"

end 
  end  
    end

if CardsP1Organized[5]=="starcard" then

if #foak_str <=1 then 

foak_str = foak_str.."star"

else

foak_str = foak_str..",star"

end 

elseif CardsP1Organized[5]=="diamondcard" then

if #foak_str <=1 then 

foak_str = foak_str.."diamond"

else

foak_str = foak_str..",diamond"

end 

elseif CardsP1Organized[5]=="heartcard" then

if #foak_str <=1 then 

foak_str = foak_str.."heart"

else

foak_str = foak_str..",heart"

end 

elseif CardsP1Organized[5]=="flowercard" then

if #foak_str <=1 then 

foak_str = foak_str.."flower"

else

foak_str = foak_str..",flower"

end 

elseif CardsP1Organized[5]=="clovercard" then

if #foak_str <=1 then 

foak_str = foak_str.."clover"

else

foak_str = foak_str..",clover"

end 

elseif CardsP1Organized[5]=="pikecard" then

if #foak_str <=1 then 

foak_str = foak_str.."pike"

else

foak_str = foak_str..",pike"

end 
  end
	
--[full house]--

if CardsP1Organized[1]=="starcard" then

for i = 1,3 do

if #fl_str <= 1 then

fl_str = fl_str.."star"

else

fl_str = fl_str..",star"

end
  end

elseif CardsP1Organized[1]=="diamondcard" then

for i = 1,3 do

if #fl_str <= 1 then

fl_str = fl_str.."diamond"

else

fl_str = fl_str..",diamond"

end
  end

elseif CardsP1Organized[1]=="heartcard" then

for i = 1,3 do

if #fl_str <= 1 then

fl_str = fl_str.."heart"

else

fl_str = fl_str..",heart"

end
  end

elseif CardsP1Organized[1]=="flowercard" then

for i = 1,3 do

if #fl_str <= 1 then

fl_str = fl_str.."flower"

else

fl_str = fl_str..",flower"

end
  end

elseif CardsP1Organized[1]=="clovercard" then

for i = 1,3 do

if #fl_str <= 1 then

fl_str = fl_str.."clover"

else

fl_str = fl_str..",clover"

end
  end

elseif CardsP1Organized[1]=="pikecard" then

for i = 1,3 do

if #fl_str <= 1 then

fl_str = fl_str.."pike"

else

fl_str = fl_str..",pike"

end
  end
    end

if CardsP1Organized[4]=="starcard" then

for i = 1,2 do

if #fl_str <= 1 then

fl_str = fl_str.."star"

else

fl_str = fl_str..",star"

end
  end

elseif CardsP1Organized[4]=="diamondcard" then

for i = 1,2 do

if #fl_str <= 1 then

fl_str = fl_str.."diamond"

else

fl_str = fl_str..",diamond"

end
  end

elseif CardsP1Organized[4]=="heartcard" then

for i = 1,2 do

if #fl_str <= 1 then

fl_str = fl_str.."heart"

else

fl_str = fl_str..","

end
  end

elseif CardsP1Organized[4]=="flowercard" then

for i = 1,2 do

if #fl_str <= 1 then

fl_str = fl_str.."flower"

else

fl_str = fl_str..",flower"

end
  end

elseif CardsP1Organized[4]=="clovercard" then

for i = 1,2 do

if #fl_str <= 1 then

fl_str = fl_str.."clover"

else

fl_str = fl_str..",clover"

end
  end

elseif CardsP1Organized[4]=="pikecard" then

for i = 1,2 do

if #fl_str <= 1 then

fl_str = fl_str.."pike"

else

fl_str = fl_str..",pike"

end
  end 
    end

--[3 of a kind]--
	
if CardsP1Organized[1]=="starcard" then

for i = 1,3 do

if #toak_str <= 1 then

toak_str = toak_str.."star"

else

toak_str = toak_str..",star"

end
  end
  
elseif CardsP1Organized[1]=="diamondcard" then

for i = 1,3 do

if #toak_str <= 1 then

toak_str = toak_str.."diamond"

else

toak_str = toak_str..",diamond"

end
  end
 
elseif CardsP1Organized[1]=="heartcard" then

for i = 1,3 do

if #toak_str <= 1 then

toak_str = toak_str.."heart"

else

toak_str = toak_str..",heart"

end
  end
 
elseif CardsP1Organized[1]=="flowercard" then

for i = 1,3 do

if #toak_str <= 1 then

toak_str = toak_str.."flower"

else

toak_str = toak_str..",flower"

end
  end

elseif CardsP1Organized[1]=="clovercard" then

for i = 1,3 do

if #toak_str <= 1 then

toak_str = toak_str.."clover"

else

toak_str = toak_str..",clover"

end
  end
 
elseif CardsP1Organized[1]=="pikecard" then

for i = 1,3 do

if #toak_str <= 1 then

toak_str = toak_str.."pike"

else

toak_str = toak_str..",pike"

end
  end
    end

if CardsP1Organized[4]=="starcard" then

if #toak_str <= 1 then

toak_str = toak_str.."star"

else

toak_str = toak_str..",star"

end
  
elseif CardsP1Organized[4]=="diamondcard" then

if #toak_str <= 1 then

toak_str = toak_str.."diamond"

else

toak_str = toak_str..",diamond"

end

elseif CardsP1Organized[4]=="heartcard" then

if #toak_str <= 1 then

toak_str = toak_str.."heart"

else

toak_str = toak_str..",heart"

end

elseif CardsP1Organized[4]=="flowercard" then

if #toak_str <= 1 then

toak_str = toak_str.."flower"

else

toak_str = toak_str..",flower"

end

elseif CardsP1Organized[4]=="clovercard" then

if #toak_str <= 1 then

toak_str = toak_str.."clover"

else

toak_str = toak_str..",clover"

end

elseif CardsP1Organized[4]=="pikecard" then

if #toak_str <= 1 then

toak_str = toak_str.."pike"

else

toak_str = toak_str..",pike"

end 
  end

if CardsP1Organized[5]=="starcard" then

if #toak_str <= 1 then

toak_str = toak_str.."star"

else

toak_str = toak_str..",star"

end
    
elseif CardsP1Organized[5]=="diamondcard" then

if #toak_str <= 1 then

toak_str = toak_str.."diamond"

else

toak_str = toak_str..",diamond"

end

elseif CardsP1Organized[5]=="heartcard" then

if #toak_str <= 1 then

toak_str = toak_str.."heart"

else

toak_str = toak_str..",heart"

end

elseif CardsP1Organized[5]=="flowercard" then

if #toak_str <= 1 then

toak_str = toak_str.."flower"

else

toak_str = toak_str..",flower"

end

elseif CardsP1Organized[5]=="clovercard" then

if #toak_str <= 1 then

toak_str = toak_str.."clover"

else

toak_str = toak_str..",clover"

end

elseif CardsP1Organized[5]=="pikecard" then

if #toak_str <= 1 then

toak_str = toak_str.."pike"

else

toak_str = toak_str..",pike"

end
  end

--[2 pair]--
 
if CardsP1Organized[1]=="starcard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."star"

else

tp_str = tp_str..",star"

end
  end
    
elseif CardsP1Organized[1]=="diamondcard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."diamond"

else

tp_str = tp_str..",diamond"

end
  end

elseif CardsP1Organized[1]=="heartcard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."heart"

else

tp_str = tp_str..",heart"

end
  end

elseif CardsP1Organized[1]=="flowercard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."flower"

else

tp_str = tp_str..",flower"

end
  end

elseif CardsP1Organized[1]=="clovercard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."clover"

else

tp_str = tp_str..",clover"

end
  end

elseif CardsP1Organized[1]=="pikecard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."pike"

else

tp_str = tp_str..",pike"

end
  end  
	end

if CardsP1Organized[3]=="starcard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."star"

else

tp_str = tp_str..",star"

end
  end
  
elseif CardsP1Organized[3]=="diamondcard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."diamond"

else

tp_str = tp_str..",diamond"

end
  end

elseif CardsP1Organized[3]=="heartcard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."heart"

else

tp_str = tp_str..",heart"

end
  end

elseif CardsP1Organized[3]=="flowercard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."flower"

else

tp_str = tp_str..",flower"

end
  end

elseif CardsP1Organized[3]=="clovercard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."clover"

else

tp_str = tp_str..",clover"

end
  end

elseif CardsP1Organized[3]=="pikecard" then
 
for i = 1,2 do

if #tp_str <= 1 then

tp_str = tp_str.."pike"

else

tp_str = tp_str..",pike"

end
  end
    end

if CardsP1Organized[5]=="starcard" then

if #tp_str <= 1 then

tp_str = tp_str.."star"

else

tp_str = tp_str..",star"

end
  
elseif CardsP1Organized[5]=="diamondcard" then

if #tp_str <= 1 then

tp_str = tp_str.."diamond"

else

tp_str = tp_str..",diamond"

end
  
elseif CardsP1Organized[5]=="heartcard" then

if #tp_str <= 1 then

tp_str = tp_str.."heart"

else

tp_str = tp_str..",heart"

end
  
elseif CardsP1Organized[5]=="flowercard" then

if #tp_str <= 1 then

tp_str = tp_str.."flower"

else

tp_str = tp_str..",flower"

end
  
elseif CardsP1Organized[5]=="clovercard" then

if #tp_str <= 1 then

tp_str = tp_str.."clover"

else

tp_str = tp_str..",clover"

end
  
elseif CardsP1Organized[5]=="pikecard" then

if #tp_str <= 1 then

tp_str = tp_str.."pike"

else

tp_str = tp_str..",pike"

end
  end

--[1 pair]--
  
if CardsP1Organized[1]=="starcard" then

for i = 1,2 do

if #op_str <= 1 then

op_str = op_str.."star"

else

op_str = op_str..",star"

end
  end
    
elseif CardsP1Organized[1]=="diamondcard" then

for i = 1,2 do

if #op_str <= 1 then

op_str = op_str.."diamond"

else

op_str = op_str..",diamond"

end
  end
	
elseif CardsP1Organized[1]=="heartcard" then

for i = 1,2 do

if #op_str <= 1 then

op_str = op_str.."heart"

else

op_str = op_str..",heart"

end
  end
	
elseif CardsP1Organized[1]=="flowercard" then

for i = 1,2 do

if #op_str <= 1 then

op_str = op_str.."flower"

else

op_str = op_str..",flower"

end
  end
	
elseif CardsP1Organized[1]=="clovercard" then

for i = 1,2 do

if #op_str <= 1 then

op_str = op_str.."clover"

else

op_str = op_str..",clover"

end
  end
	
elseif CardsP1Organized[1]=="pikecard" then

for i = 1,2 do

if #op_str <= 1 then

op_str = op_str.."pike"

else

op_str = op_str..",pike"

end
  end
	end

if CardsP1Organized[3]=="starcard" then

if #op_str <= 1 then

op_str = op_str.."star"

else

op_str = op_str..",star"

end
  
elseif CardsP1Organized[3]=="diamondcard" then

if #op_str <= 1 then

op_str = op_str.."diamond"

else

op_str = op_str..",diamond"

end  
 
elseif CardsP1Organized[3]=="heartcard" then

if #op_str <= 1 then

op_str = op_str.."heart"

else

op_str = op_str..",heart"

end  
 
elseif CardsP1Organized[3]=="flowercard" then

if #op_str <= 1 then

op_str = op_str.."flower"

else

op_str = op_str..",flower"

end  
 
elseif CardsP1Organized[3]=="clovercard" then

if #op_str <= 1 then

op_str = op_str.."clover"

else

op_str = op_str..",clover"

end  
 
elseif CardsP1Organized[3]=="pikecard" then

if #op_str <= 1 then

op_str = op_str.."pike"

else

op_str = op_str..",pike"

end  
  end

if CardsP1Organized[4]=="starcard" then

if #op_str <= 1 then

op_str = op_str.."star"

else

op_str = op_str..",star"

end
  
elseif CardsP1Organized[4]=="diamondcard" then

if #op_str <= 1 then

op_str = op_str.."diamond"

else

op_str = op_str..",diamond"

end  
 
elseif CardsP1Organized[4]=="heartcard" then

if #op_str <= 1 then

op_str = op_str.."heart"

else

op_str = op_str..",heart"

end  
 
elseif CardsP1Organized[4]=="flowercard" then

if #op_str <= 1 then

op_str = op_str.."flower"

else

op_str = op_str..",flower"

end  
 
elseif CardsP1Organized[4]=="clovercard" then

if #op_str <= 1 then

op_str = op_str.."clover"

else

op_str = op_str..",clover"

end  
 
elseif CardsP1Organized[4]=="pikecard" then

if #op_str <= 1 then

op_str = op_str.."pike"

else

op_str = op_str..",pike"

end  
  end

if CardsP1Organized[5]=="starcard" then

if #op_str <= 1 then

op_str = op_str.."star"

else

op_str = op_str..",star"

end
  
elseif CardsP1Organized[5]=="diamondcard" then

if #op_str <= 1 then

op_str = op_str.."diamond"

else

op_str = op_str..",diamond"

end  
 
elseif CardsP1Organized[5]=="heartcard" then

if #op_str <= 1 then

op_str = op_str.."heart"

else

op_str = op_str..",heart"

end  
 
elseif CardsP1Organized[5]=="flowercard" then

if #op_str <= 1 then

op_str = op_str.."flower"

else

op_str = op_str..",flower"

end  
 
elseif CardsP1Organized[5]=="clovercard" then

if #op_str <= 1 then

op_str = op_str.."clover"

else

op_str = op_str..",clover"

end  
 
elseif CardsP1Organized[5]=="pikecard" then

if #op_str <= 1 then

op_str = op_str.."pike"

else

op_str = op_str..",pike"

end  
  end
	end

function MakeSetsP2()
	
--[royal flush]--

if CardsP2Organized[1]=="starcard" then

for i = 1,5 do

if #rf_str_p2 <=1 then 

rf_str_p2 = rf_str_p2.."star"

else

rf_str_p2 = rf_str_p2..",star"

end
  end

elseif CardsP2Organized[1]=="diamondcard" then

for i = 1,5 do

if #rf_str_p2 <=1 then 

rf_str_p2 = rf_str_p2.."diamond"

else

rf_str_p2 = rf_str_p2..",diamond"

end
  end

elseif CardsP2Organized[1]=="heartcard" then

for i = 1,5 do

if #rf_str_p2 <=1 then 

rf_str_p2 = rf_str_p2.."heart"

else

rf_str_p2 = rf_str_p2..",heart"

end
  end

elseif CardsP2Organized[1]=="flowercard" then

for i = 1,5 do

if #rf_str_p2 <=1 then 

rf_str_p2 = rf_str_p2.."flower"

else

rf_str_p2 = rf_str_p2..",flower"

end
  end

elseif CardsP2Organized[1]=="clovercard" then

for i = 1,5 do

if #rf_str_p2 <=1 then 

rf_str_p2 = rf_str_p2.."clover"

else

rf_str_p2 = rf_str_p2..",clover"

end
  end

elseif CardsP2Organized[1]=="pikecard" then

for i = 1,5 do

if #rf_str_p2 <=1 then 

rf_str_p2 = rf_str_p2.."pike"

else

rf_str_p2 = rf_str_p2..",pike"

end
  end
    end

--[four of a kind]--

if CardsP2Organized[1]=="starcard" then

for i = 1,4 do

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."star"

else

foak_str_p2 = foak_str_p2..",star"

end 
  end

elseif CardsP2Organized[1]=="diamondcard" then

for i = 1,4 do

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."diamond"

else

foak_str_p2 = foak_str_p2..",diamond"

end 
  end

elseif CardsP2Organized[1]=="heartcard" then

for i = 1,4 do

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."heart"

else

foak_str_p2 = foak_str_p2..",heart"

end 
  end

elseif CardsP2Organized[1]=="flowercard" then

for i = 1,4 do

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."flower"

else

foak_str_p2 = foak_str_p2..",flower"

end 
  end

elseif CardsP2Organized[1]=="clovercard" then

for i = 1,4 do

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."clover"

else

foak_str_p2 = foak_str_p2..",clover"

end 
  end

elseif CardsP2Organized[1]=="pikecard" then

for i = 1,4 do

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."pike"

else

foak_str_p2 = foak_str_p2..",pike"

end 
  end  
    end

if CardsP2Organized[5]=="starcard" then

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."star"

else

foak_str_p2 = foak_str_p2..",star"

end 

elseif CardsP2Organized[5]=="diamondcard" then

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."diamond"

else

foak_str_p2 = foak_str_p2..",diamond"

end 

elseif CardsP2Organized[5]=="heartcard" then

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."heart"

else

foak_str_p2 = foak_str_p2..",heart"

end 

elseif CardsP2Organized[5]=="flowercard" then

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."flower"

else

foak_str_p2 = foak_str_p2..",flower"

end 

elseif CardsP2Organized[5]=="clovercard" then

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."clover"

else

foak_str_p2 = foak_str_p2..",clover"

end 

elseif CardsP2Organized[5]=="pikecard" then

if #foak_str_p2 <=1 then 

foak_str_p2 = foak_str_p2.."pike"

else

foak_str_p2 = foak_str_p2..",pike"

end 
  end
	
--[full house]--

if CardsP2Organized[1]=="starcard" then

for i = 1,3 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."star"

else

fl_str_p2 = fl_str_p2..",star"

end
  end

elseif CardsP2Organized[1]=="diamondcard" then

for i = 1,3 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."diamond"

else

fl_str_p2 = fl_str_p2..",diamond"

end
  end

elseif CardsP2Organized[1]=="heartcard" then

for i = 1,3 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."heart"

else

fl_str_p2 = fl_str_p2..","

end
  end

elseif CardsP2Organized[1]=="flowercard" then

for i = 1,3 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."flower"

else

fl_str_p2 = fl_str_p2..",flower"

end
  end

elseif CardsP2Organized[1]=="clovercard" then

for i = 1,3 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."clover"

else

fl_str_p2 = fl_str_p2..",clover"

end
  end

elseif CardsP2Organized[1]=="pikecard" then

for i = 1,3 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."pike"

else

fl_str_p2 = fl_str_p2..",pike"

end
  end
    end

if CardsP2Organized[4]=="starcard" then

for i = 1,2 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."star"

else

fl_str_p2 = fl_str_p2..",star"

end
  end

elseif CardsP2Organized[4]=="diamondcard" then

for i = 1,2 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."diamond"

else

fl_str_p2 = fl_str_p2..",diamond"

end
  end

elseif CardsP2Organized[4]=="heartcard" then

for i = 1,2 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."heart"

else

fl_str_p2 = fl_str_p2..","

end
  end

elseif CardsP2Organized[4]=="flowercard" then

for i = 1,2 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."flower"

else

fl_str_p2 = fl_str_p2..",flower"

end
  end

elseif CardsP2Organized[4]=="clovercard" then

for i = 1,2 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."clover"

else

fl_str_p2 = fl_str_p2..",clover"

end
  end

elseif CardsP2Organized[4]=="pikecard" then

for i = 1,2 do

if #fl_str_p2 <= 1 then

fl_str_p2 = fl_str_p2.."pike"

else

fl_str_p2 = fl_str_p2..",pike"

end
  end 
    end

--[3 of a kind]--
	
if CardsP2Organized[1]=="starcard" then

for i = 1,3 do

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."star"

else

toak_str_p2 = toak_str_p2..",star"

end
  end
  
elseif CardsP2Organized[1]=="diamondcard" then

for i = 1,3 do

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."diamond"

else

toak_str_p2 = toak_str_p2..",diamond"

end
  end
 
elseif CardsP2Organized[1]=="heartcard" then

for i = 1,3 do

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."heart"

else

toak_str_p2 = toak_str_p2..",heart"

end
  end
 
elseif CardsP2Organized[1]=="flowercard" then

for i = 1,3 do

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."flower"

else

toak_str_p2 = toak_str_p2..",flower"

end
  end

elseif CardsP2Organized[1]=="clovercard" then

for i = 1,3 do

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."clover"

else

toak_str_p2 = toak_str_p2..",clover"

end
  end
 
elseif CardsP2Organized[1]=="pikecard" then

for i = 1,3 do

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."pike"

else

toak_str_p2 = toak_str_p2..",pike"

end
  end
    end

if CardsP2Organized[4]=="starcard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."star"

else

toak_str_p2 = toak_str_p2..",star"

end
  
elseif CardsP2Organized[4]=="diamondcard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."diamond"

else

toak_str_p2 = toak_str_p2..",diamond"

end

elseif CardsP2Organized[4]=="heartcard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."heart"

else

toak_str_p2 = toak_str_p2..",heart"

end

elseif CardsP2Organized[4]=="flowercard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."flower"

else

toak_str_p2 = toak_str_p2..",flower"

end

elseif CardsP2Organized[4]=="clovercard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."clover"

else

toak_str_p2 = toak_str_p2..",clover"

end

elseif CardsP2Organized[4]=="pikecard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."pike"

else

toak_str_p2 = toak_str_p2..",pike"

end 
  end

if CardsP2Organized[5]=="starcard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."star"

else

toak_str_p2 = toak_str_p2..",star"

end
    
elseif CardsP2Organized[5]=="diamondcard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."diamond"

else

toak_str_p2 = toak_str_p2..",diamond"

end

elseif CardsP2Organized[5]=="heartcard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."heart"

else

toak_str_p2 = toak_str_p2..",heart"

end

elseif CardsP2Organized[5]=="flowercard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."flower"

else

toak_str_p2 = toak_str_p2..",flower"

end

elseif CardsP2Organized[5]=="clovercard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."clover"

else

toak_str_p2 = toak_str_p2..",clover"

end

elseif CardsP2Organized[5]=="pikecard" then

if #toak_str_p2 <= 1 then

toak_str_p2 = toak_str_p2.."pike"

else

toak_str_p2 = toak_str_p2..",pike"

end
  end

--[2 pair]--
 
if CardsP2Organized[1]=="starcard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."star"

else

tp_str_p2 = tp_str_p2..",star"

end
  end
    
elseif CardsP2Organized[1]=="diamondcard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."diamond"

else

tp_str_p2 = tp_str_p2..",diamond"

end
  end

elseif CardsP2Organized[1]=="heartcard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."heart"

else

tp_str_p2 = tp_str_p2..",heart"

end
  end

elseif CardsP2Organized[1]=="flowercard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."flower"

else

tp_str_p2 = tp_str_p2..",flower"

end
  end

elseif CardsP2Organized[1]=="clovercard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."clover"

else

tp_str_p2 = tp_str_p2..",clover"

end
  end

elseif CardsP2Organized[1]=="pikecard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."pike"

else

tp_str_p2 = tp_str_p2..",pike"

end
  end  
	end

if CardsP2Organized[3]=="starcard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."star"

else

tp_str_p2 = tp_str_p2..",star"

end
  end
  
elseif CardsP2Organized[3]=="diamondcard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."diamond"

else

tp_str_p2 = tp_str_p2..",diamond"

end
  end

elseif CardsP2Organized[3]=="heartcard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."heart"

else

tp_str_p2 = tp_str_p2..",heart"

end
  end

elseif CardsP2Organized[3]=="flowercard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."flower"

else

tp_str_p2 = tp_str_p2..",flower"

end
  end

elseif CardsP2Organized[3]=="clovercard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."clover"

else

tp_str_p2 = tp_str_p2..",clover"

end
  end

elseif CardsP2Organized[3]=="pikecard" then
 
for i = 1,2 do

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."pike"

else

tp_str_p2 = tp_str_p2..",pike"

end
  end
    end

if CardsP2Organized[5]=="starcard" then

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."star"

else

tp_str_p2 = tp_str_p2..",star"

end
  
elseif CardsP2Organized[5]=="diamondcard" then

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."diamond"

else

tp_str_p2 = tp_str_p2..",diamond"

end
  
elseif CardsP2Organized[5]=="heartcard" then

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."heart"

else

tp_str_p2 = tp_str_p2..",heart"

end
  
elseif CardsP2Organized[5]=="flowercard" then

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."flower"

else

tp_str_p2 = tp_str_p2..",flower"

end
  
elseif CardsP2Organized[5]=="clovercard" then

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."clover"

else

tp_str_p2 = tp_str_p2..",clover"

end
  
elseif CardsP2Organized[5]=="pikecard" then

if #tp_str_p2 <= 1 then

tp_str_p2 = tp_str_p2.."pike"

else

tp_str_p2 = tp_str_p2..",pike"

end
  end

--[1 pair]--
  
if CardsP2Organized[1]=="starcard" then

for i = 1,2 do

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."star"

else

op_str_p2 = op_str_p2..",star"

end
  end
    
elseif CardsP2Organized[1]=="diamondcard" then

for i = 1,2 do

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."diamond"

else

op_str_p2 = op_str_p2..",diamond"

end
  end
	
elseif CardsP2Organized[1]=="heartcard" then

for i = 1,2 do

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."heart"

else

op_str_p2 = op_str_p2..",heart"

end
  end
	
elseif CardsP2Organized[1]=="flowercard" then

for i = 1,2 do

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."flower"

else

op_str_p2 = op_str_p2..",flower"

end
  end
	
elseif CardsP2Organized[1]=="clovercard" then

for i = 1,2 do

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."clover"

else

op_str_p2 = op_str_p2..",clover"

end
  end
	
elseif CardsP2Organized[1]=="pikecard" then

for i = 1,2 do

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."pike"

else

op_str_p2 = op_str_p2..",pike"

end
  end
	end

if CardsP2Organized[3]=="starcard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."star"

else

op_str_p2 = op_str_p2..",star"

end
  
elseif CardsP2Organized[3]=="diamondcard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."diamond"

else

op_str_p2 = op_str_p2..",diamond"

end  
 
elseif CardsP2Organized[3]=="heartcard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."heart"

else

op_str_p2 = op_str_p2..",heart"

end  
 
elseif CardsP2Organized[3]=="flowercard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."flower"

else

op_str_p2 = op_str_p2..",flower"

end  
 
elseif CardsP2Organized[3]=="clovercard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."clover"

else

op_str_p2 = op_str_p2..",clover"

end  
 
elseif CardsP2Organized[3]=="pikecard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."pike"

else

op_str_p2 = op_str_p2..",pike"

end  
  end

if CardsP2Organized[4]=="starcard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."star"

else

op_str_p2 = op_str_p2..",star"

end
  
elseif CardsP2Organized[4]=="diamondcard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."diamond"

else

op_str_p2 = op_str_p2..",diamond"

end  
 
elseif CardsP2Organized[4]=="heartcard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."heart"

else

op_str_p2 = op_str_p2..",heart"

end  
 
elseif CardsP2Organized[4]=="flowercard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."flower"

else

op_str_p2 = op_str_p2..",flower"

end  
 
elseif CardsP2Organized[4]=="clovercard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."clover"

else

op_str_p2 = op_str_p2..",clover"

end  
 
elseif CardsP2Organized[4]=="pikecard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."pike"

else

op_str_p2 = op_str_p2..",pike"

end  
  end

if CardsP2Organized[5]=="starcard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."star"

else

op_str_p2 = op_str_p2..",star"

end
  
elseif CardsP2Organized[5]=="diamondcard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."diamond"

else

op_str_p2 = op_str_p2..",diamond"

end  
 
elseif CardsP2Organized[5]=="heartcard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."heart"

else

op_str_p2 = op_str_p2..",heart"

end  
 
elseif CardsP2Organized[5]=="flowercard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."flower"

else

op_str_p2 = op_str_p2..",flower"

end  
 
elseif CardsP2Organized[5]=="clovercard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."clover"

else

op_str_p2 = op_str_p2..",clover"

end  
 
elseif CardsP2Organized[5]=="pikecard" then

if #op_str_p2 <= 1 then

op_str_p2 = op_str_p2.."pike"

else

op_str_p2 = op_str_p2..",pike"

end  
  end
    end
	
function DecideWinner()

MakeSets()

MakeSetsP2()

if CardsP1Organized_str == rf_str then 

CardsP1Set = "Five Of A Kind"

Reward = rf_reward

elseif CardsP1Organized_str == fl_str then

CardsP1Set = "Full House"

Reward = fl_reward

elseif CardsP1Organized_str == foak_str then

CardsP1Set = "Four Of A Kind"

Reward = foak_reward

elseif CardsP1Organized_str == toak_str then

CardsP1Set = "Three Of A Kind"

Reward = toak_reward

elseif CardsP1Organized_str == tp_str then

CardsP1Set = "Two Pair"

Reward = tp_reward

elseif CardsP1Organized_str == op_str then

CardsP1Set = "One Pair"

Reward = op_reward

end

if CardsP2Organized_str == rf_str_p2 then 

CardsP2Set = "Five Of A Kind"

elseif CardsP2Organized_str == fl_str_p2 then

CardsP2Set = "Full House"

elseif CardsP2Organized_str == foak_str_p2 then

CardsP2Set = "Four Of A Kind"

elseif CardsP2Organized_str == toak_str_p2 then

CardsP2Set = "Three Of A Kind"

elseif CardsP2Organized_str == tp_str_p2 then

CardsP2Set = "Two Pair"

elseif CardsP2Organized_str == op_str_p2 then

CardsP2Set = "One Pair"

end

if CardsP1Organized_str == CardsP2Organized_str then

CardsP1Set = "Draw"

CardsP2Set = "Draw"

end

DrawText(10,19,colors.green,colors.blue,"P1: "..CardsP1Set)

DrawText(10,1,colors.green,colors.blue,"P2: "..CardsP2Set)

if CardsP2Set == "" then

Winner = "Player 1"

elseif CardsP1Set == "" then

Winner = "Player 2"

end

if CardsP2Set == "One Pair" and CardsP1Set == "Two Pair" or CardsP1Set == "Three Of A Kind" or CardsP1Set == "Four Of A Kind" or CardsP1Set == "Full House" or CardsP1Set == "Five Of A Kind" then

Winner = "Player 1"

elseif CardsP1Set == "One Pair" and CardsP2Set == "Two Pair" or CardsP2Set == "Three Of A Kind" or CardsP2Set == "Four Of A Kind"  or CardsP2Set == "Full House" or CardsP2Set == "Five Of A Kind" then

Winner = "Player 2"

end

if CardsP2Set == "Two Pair" and CardsP1Set == "Three Of A Kind" or CardsP1Set == "Four Of A Kind"  or CardsP1Set == "Full House" or CardsP1Set == "Five Of A Kind" then

Winner = "Player 1"

elseif CardsP1Set == "Two Pair" and CardsP2Set == "Three Of A Kind" or CardsP2Set == "Four Of A Kind"  or CardsP2Set == "Full House" or CardsP2Set == "Five Of A Kind" then

Winner = "Player 2"

end

if CardsP2Set == "Three Of A Kind" and CardsP1Set == "Four Of A Kind" or CardsP1Set == "Full House" or CardsP1Set == "Five Of A Kind" then

Winner = "Player 1"

elseif CardsP1Set == "Three Of A Kind" and CardsP2Set == "Four Of A Kind" or CardsP2Set == "Full House" or CardsP2Set == "Five Of A Kind" then

Winner = "Player 2"

end

if CardsP2Set == "Four Of A Kind" and CardsP1Set == "Five Of A Kind" then

Winner = "Player 1"

elseif CardsP1Set == "Four Of A Kind" and CardsP2Set == "Five Of A Kind" then

Winner = "Player 2"

end

if CardsP2Set == "Full House" and CardsP1Set == "Five Of A Kind" then

Winner = "Player 1"

elseif CardsP1Set == "Full House" and CardsP2Set == "Five Of A Kind" then

Winner = "Player 2"

end

if CardsP1Set == CardsP2Set then

for i = 1,5 do

if CardsP1Organized[i]=="starcard" then

CardsP1Worth = CardsP1Worth + 6 

elseif CardsP1Organized[i]=="diamondcard" then

CardsP1Worth = CardsP1Worth + 5

elseif CardsP1Organized[i]=="heartcard" then

CardsP1Worth = CardsP1Worth + 4

elseif CardsP1Organized[i]=="flowercard" then

CardsP1Worth = CardsP1Worth + 3

elseif CardsP1Organized[i]=="clovercard" then

CardsP1Worth = CardsP1Worth + 2

elseif CardsP1Organized[i]=="pikecard" then

CardsP1Worth = CardsP1Worth + 1

end
  end

for i = 1,5 do

if CardsP2Organized[i]=="starcard" then

CardsP2Worth = CardsP2Worth + 6 

elseif CardsP2Organized[i]=="diamondcard" then

CardsP2Worth = CardsP2Worth + 5

elseif CardsP2Organized[i]=="heartcard" then

CardsP2Worth = CardsP2Worth + 4

elseif CardsP2Organized[i]=="flowercard" then

CardsP2Worth = CardsP2Worth + 3

elseif CardsP2Organized[i]=="clovercard" then

CardsP2Worth = CardsP2Worth + 2

elseif CardsP2Organized[i]=="pikecard" then

CardsP2Worth = CardsP2Worth + 1

end
  end 
    
if tonumber(CardsP1Worth) >= tonumber(CardsP2Worth) then

Winner = "Player 1"
	
elseif tonumber(CardsP2Worth) >= tonumber(CardsP1Worth) then

Winner = "Player 2"

end
  end

if Winner=="Player 1" then

sleep(1.5)

Reward = Reward * pod

RewardCounter = Reward

DrawText(20,10,colors.green,colors.blue,"You win!")

sounds("harp")

sleep(1.5)

drawGUI()

DrawText(16,10,colors.yellow,colors.black,"$")

DrawText(17,10,colors.green,colors.black," + ")

DrawText(20,10,colors.green,colors.black,RewardCounter)

sleep(1)

repeat

if RewardCounter <= 10 then

paintutils.drawPixel(21,10,colors.green)

end

DrawText(1,10,colors.green,colors.black,"Money: ")

DrawText(8,10,colors.yellow,colors.black,"$")

DrawText(9,10,colors.green,colors.black,Money)

DrawText(16,10,colors.yellow,colors.black,"$")

DrawText(17,10,colors.green,colors.black," + ")

DrawText(20,10,colors.green,colors.black,RewardCounter)

Money = Money + 1

RewardCounter = RewardCounter - 1

sleep(0.15)

until RewardCounter == 0

DrawText(1,10,colors.green,colors.black,"Money: ")

DrawText(8,10,colors.yellow,colors.black,"$")

DrawText(9,10,colors.green,colors.black,Money)

DrawText(16,10,colors.yellow,colors.black,"$")

DrawText(17,10,colors.green,colors.black," + ")

DrawText(20,10,colors.green,colors.black,RewardCounter)

Save()

sleep(1.5)

count = 1

shell.setDir("")

shell.run(shell.getRunningProgram())

shell.setDir(CurrentDir)

error()

elseif Winner == "Player 2" then 

sleep(1.5)

sounds("bass")

DrawText(20,10,colors.green,colors.red,"You lose.")

sleep(1.5)

drawGUI()

DrawText(16,10,colors.yellow,colors.black,"$")

DrawText(17,10,colors.green,colors.black," - ")

DrawText(20,10,colors.green,colors.black,pod)

sleep(1)

LoseCounter = pod

repeat

DrawText(1,1,colors.green,colors.black,"Pod: ")

DrawText(6,1,colors.yellow,colors.black,"$")

DrawText(7,1,colors.green,colors.black,pod)

DrawText(16,10,colors.yellow,colors.black,"$")

DrawText(17,10,colors.green,colors.black," - ")

DrawText(20,10,colors.green,colors.black,LoseCounter)

pod = pod - 1

LoseCounter = LoseCounter - 1

sleep(0.15)

until LoseCounter == 0

DrawText(1,1,colors.green,colors.black,"Pod: ")

DrawText(6,1,colors.yellow,colors.black,"$")

DrawText(7,1,colors.green,colors.black,pod)

DrawText(16,10,colors.yellow,colors.black,"$")

DrawText(17,10,colors.green,colors.black," - ")

DrawText(20,10,colors.green,colors.black,LoseCounter)

Save()

sleep(1.5)

if tonumber(Money)==0 then

term.clear()

term.setBackgroundColor(colors.green)

term.setTextColor(colors.blue)

term.setCursorPos(25 - 10 / 2,10)

print("Game Over!")

sleep(2)

count = 1

shell.setDir("")

shell.run(shell.getRunningProgram())

shell.setDir(CurrentDir)

error()

end

count = 1

shell.setDir("")

shell.run(shell.getRunningProgram())

shell.setDir(CurrentDir)

error()

end
  end

if tonumber(Money) <= 0 then

local file = fs.open(fs.getDir(shell.getRunningProgram()).."/sv.cc","w")

file.write("10")

file.close()

local file = fs.open(fs.getDir(shell.getRunningProgram()).."/sv.cc","r")
local SVData = file.readLine()

local Money = SVData

file.close()

shell.setDir("")

shell.run(shell.getRunningProgram())

else

begin()

end