module Main (main) where

fizzbuzz :: (Show a, Integral a) => a -> String
fizzbuzz x
  = case (mod x 3 == 0, mod x 5 == 0) of
        (True, True) -> "FizzBuzz\n"
        (True, False) -> "Fizz\n"
        (False, True) -> "Buzz\n"
        (False, False) -> show x ++ "\n"

flatten :: [String] -> String
flatten [] = []
flatten xs = concat xs

main :: IO ()
main = putStrLn . flatten $ map fizzbuzz [1 .. 100]
