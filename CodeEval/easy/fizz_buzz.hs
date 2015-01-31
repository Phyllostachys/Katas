import System.Environment

main :: IO ()
main = do
    [inpFile] <- getArgs
    input <- readFile inpFile
    mapM_ (putStrLn . unwords) $ map processInput $ map words $ lines input

processInput (x:y:z:[]) = map (fizzbuzz (read x) (read y)) [1..(read z)]

fizzbuzz :: Int -> Int -> Int -> String
fizzbuzz x y n = case (mod n x == 0, mod n y == 0) of
                    (True, True) -> "FB"
                    (True, False) -> "F"
                    (False, True) -> "B"
                    (False, False) -> show n
