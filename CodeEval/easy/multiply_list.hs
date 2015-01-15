import System.Environment (getArgs)

main :: IO ()
main = do
    [filename] <- getArgs
    fileContent <- readFile filename
    let linesList = lines fileContent
    let resultList = map parseLine linesList
    mapM_ printResults resultList
    where parseLine xs = let numList = words xs
                             firstHalf = map (\x -> read x :: Int) $ take (fromEnum ((fromIntegral (length numList - 1)) / 2)) numList
                             secondHalf = map (\x -> read x :: Int) $ drop (fromEnum ((fromIntegral (length numList + 1)) / 2)) numList
                         in multiplyList firstHalf secondHalf
          printResults xs = putStrLn $ unwords $ map show xs

multiplyList :: Num a => [a] -> [a] -> [a]
multiplyList [] _ = []
multiplyList _ [] = []
multiplyList (x:[]) (y:[]) = x*y : []
multiplyList (x:xs) (y:ys) = x*y : multiplyList xs ys
