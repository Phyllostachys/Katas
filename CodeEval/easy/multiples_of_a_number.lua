for line in io.lines(arg[1]) do
    nums = {}
    for i in line:gmatch("%d+") do
        table.insert(nums, tonumber(i))
    end

    local n = nums[2]
    while n < nums[1] do
        n = n + nums[2]
    end

    print(n)
end