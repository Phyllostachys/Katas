module JoinedWords where

joinS :: [[Char]] -> [Char] -> [Char]
joinS [] _ = ""
joinS [str] _ = str
joinS strList "" = concat strList
joinS strList string = (strList !! 0) ++ string ++ joinS (tail strList) string
