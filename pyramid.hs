import System.Environment as Env

-- Generating next value of stream accoring to the privious ones
nextPy (_,_,leaves) _ (_,_,fooling) = (leaves, stays, joins)
	where
		joins = 2 * fooling 
		stays = joins - leaves

-- Pyramid Stream :)
pyramid :: [(Int,Int,Int)]
pyramid = (0,0,0):(0,0,0):(0,0,1):zipWith3 nextPy fst snd thrd
   where
        fst  = pyramid
        snd  = tail fst
        thrd = tail snd

-- Inserts ',' from start by separating every three 3 char
putComma :: Int -> String -> String -> String
putComma _ [] word = word
putComma i ( char : chars ) word
	| i == 0 = putComma (i+1) chars ( char : word ) -- I don't like this :|
	| mod i 3 == 0 = putComma (i+1) chars ( char :',': word )
	| otherwise = putComma (i+1) chars ( char : word )


--  Converts e.g.: 123456789 => "123,456,789"
sciNum i =  putComma 0 ( reverse $ show i ) ""


-- humanize the threeple :)
wrap :: (Int, Int, Int) -> String
wrap (left, stayed, joined ) =  "left: " ++ sciNum left ++
				"  fooling: " ++ sciNum stayed ++
				"  joined: " ++ sciNum joined ++ "\n"

-- Unite the words and number each word
number words = number' 0 words ""

-- ^
number' :: Int -> [String] -> String -> String
number' _ [] last = last
number' i ( word : words ) last = number' (i+1) words (last ++ finalWord)
	where finalWord = show i ++ " :: " ++ word

main = do {
	putStr $ number $ map wrap $drop 1 $ takeWhile (\(a,b,c) -> c >= b ) pyramid
}
	
