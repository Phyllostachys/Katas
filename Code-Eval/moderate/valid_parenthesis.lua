match = {["("] = ")", ["{"] = "}", ["["] = "]"}

for parens in io.lines(arg[1]) do
  pStack = {}
  answer = "True"

  for i = 1, # parens do
    local p = parens:sub(i,i)
    --print(parens, type(parens), p)
    if p == "(" or p == "{" or p == "[" then
      table.insert(pStack, p)
    elseif p == ")" or p == "}" or p == "]" then
      if # pStack == 0 or p ~= match[pStack[# pStack]] then
        answer = "False"
        break
      else
        table.remove(pStack)
      end
    end
  end

  if # pStack ~= 0 then
    answer = "False"
  end
  print(answer)
end
