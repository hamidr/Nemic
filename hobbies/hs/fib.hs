-- This one has its function inside.
fib1 :: (Num a, Ord a) => a -> a
fib1 n
    | n <= 0 = 0
    | n <= 2 = 1
    | otherwise = cache2 + cache1
    where
        fibo n
            | n <= 2 = (1, 1)
            | otherwise = (p, pp + p) 
            where (pp, p) = fibo (n-1)

        (cache1, cache2) = fibo (n-1)

-- This one has it seperated.
fib' :: (Num a, Ord a) => a -> (a, a)
fib' 2 = (1,1)
fib' n = (p, pp+p)
    where (pp, p) = fib'(n-1)

fib2 :: (Num a, Ord a) => a -> a
fib2 n
    | n <= 2 = 1
    | otherwise = cache1 + cache2
    where ( cache1, cache2 ) = fib'(n-1)

{- 
    Which one do you haskellers prefer?
    Do Think are both of them in bad style? If it is so, then would you write a better one? 
-}

