for line in io.lines(arg[1]) do
    local sum = 0
    for i = 1,# line do
        local c = line:sub(i,i)
        if c ~= '\n' then
            sum = sum + tonumber(c)
        end
    end

    print(sum)
end