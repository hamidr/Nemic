{- foo :: Int -> Int -> Int
foo m 0 = m
foo m n = let x = m `mod` n in foo n x

sum' :: Num a => [a] -> a
sum' [] = 0
sum' (x:xs) = x + sum' xs


reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:ys) = (reverse' ys ) ++ [x]


bar (x:ys) = x : bar ys

join' :: [a] -> [a] -> [a]
join' xs [] = xs
join' [] ys = ys
join' xs (y:ys) =  bar xs -}

import System.Environment ( getArgs )
import Data.Char ( isNumber )

collatz :: Integral a => a -> a
collatz n
	| even n = n `div` 2
	| otherwise = 3 * n + 1

collatzSeq :: Integral a => a -> [a]
collatzSeq n 
	| n > 1 = let b = collatz n 
		in b : collatzSeq b
	| otherwise = []

catchBugs :: [String] -> Bool
catchBugs ( str:[] ) = all isNumber str
catchBugs _ = False

main = do 
	args <- getArgs
	if ( catchBugs args )
		then 
			let number = read ( args !! 0 ) :: Int
			in putStrLn $ show $ collatzSeq number
		else putStrLn "what?"
	
