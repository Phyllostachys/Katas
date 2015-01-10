module Codewars.Anagram where

import Data.Char
import Data.List

isAnagramOf :: String -> String -> Bool
isAnagramOf test original = elem sortTest (tails sortOrig)
    where sortTest = sort $ map (toLower) test
          sortOrig = sort $ map (toLower) original
