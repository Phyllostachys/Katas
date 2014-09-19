for line in io.lines(arg[1]) do
    if tonumber(line) % 2 == 0 then print("1")
    else print("0")
    end
end