local a, b, n

for line in io.lines(arg[1]) do
    local temp = string.gmatch(line, "%S+")
    a = tonumber(temp())
    b = tonumber(temp())
    n = tonumber(temp())
    
    for i = 1, n-1 do
      if i % a == 0 and i % b == 0 then
        io.write("FB")
      elseif i % a == 0 then
        io.write("F")
      elseif i % b == 0 then
        io.write("B")
      else
        io.write(i)
      end
      io.write(" ")
    end
    
    if n % a == 0 and n % b == 0 then
      io.write("FB")
    elseif n % a == 0 then
      io.write("F")
    elseif n % b == 0 then
      io.write("B")
    else
      io.write(n)
    end
    
    io.write('\n')
end