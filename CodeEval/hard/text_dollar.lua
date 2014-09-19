ones = {"One", "Two", "Three",
        "Four", "Five",  "Six",
        "Seven", "Eight", "Nine"}

tens = {[10] = "Ten",      [11] = "Eleven",   [12] = "Twelve",  [13] = "Thirteen",
        [14] = "Fourteen", [15] = "Fifteen",  [16] = "Sixteen", [17] = "Seventeen",
        [18] = "Eighteen", [19] = "Nineteen", [20] = "Twenty",  [30] = "Thirty",
        [40] = "Forty",    [50] = "Fifty",    [80] = "Eighty"}

function getOnesWord(number)
  return ones[number]
end

function getTensWord(number)
  if number < 10 then
    return getOnesWord(number)
  elseif tens[number] ~= nil then
    return tens[number]
  else
    local test = tens[number - (number % 10)]
    if test ~= nil then
      return test .. getOnesWord(number % 10)
    else
      local quot = math.floor(number / 10)
      local rem = math.floor(number % 10)
      if rem == 0 then
        return getOnesWord(quot) .. "ty"
      else
        return getOnesWord(quot) .. "ty" .. getOnesWord(rem)
      end
    end
  end
end

function getHundredsWord(number)
  if number < 100 then
    return getTensWord(number)
  end

  s = getOnesWord(math.floor(number / 100)) .. "Hundred"
  if number % 100 ~= 0 then
    return s .. getTensWord(number % 100)
  else
    return s
  end
end

function intToDollars(number)
  local res = ""

  -- get millions
  if math.floor(number / 1000000) > 0 then
    res = getHundredsWord(math.floor(number / 1000000)) .. "Million"
    number = number % 1000000
  end

  -- get thousands
  if math.floor(number / 1000) > 0 then
    res = res .. getHundredsWord(math.floor(number / 1000)) .. "Thousand"
    number = number % 1000
  end

  -- get hundreds and less
  if number > 0 then
    res = res .. getHundredsWord(number)
  end

  return res .. "Dollars"
end

for line in io.lines(arg[1]) do
  --if not line == '' then
    print(intToDollars(tonumber(line)))
  --end
end
