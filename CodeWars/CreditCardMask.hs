module Maskify where

maskify :: String -> String
maskify str
    | listLen < 4 = str
    | otherwise = hashes ++ endFirst ++ endSecond ++ endThird ++ endFourth
    where listLen = length str
          hashes = concat $ replicate (listLen - 4) "#"
          endFirst = [str !! (listLen - 4)]
          endSecond = [str !! (listLen - 3)]
          endThird = [str !! (listLen - 2)]
          endFourth = [str !! (listLen - 1)]
