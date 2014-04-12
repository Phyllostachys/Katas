local sum = 0

for line in io.lines(arg[1]) do
    sum = sum + tonumber(line)
end

io.write(sum)