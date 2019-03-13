{-
In Haskell, lists are a homogenous data structure.
It stores several elements of `the same type`.
-}


{- set comprehensions | 集合构建表达式
   S = {2・x | x ⊆ N, x <= 10}

   ghci> [x*2 | x <- [1..10]]
   [2,4,6,8,10,12,14,16,18,20]
-}


boomBangs xs = [ if x < 10 then "BOOM!" else "BANG!" | x <- xs, odd x]


-- Let's write our own version of length! We'll call it length'.
-- _ means that we don't care what we'll draw from the list anyway so instead of writing a variable name that we'll never use, we just write _.
length' xs = sum [1 | _ <- xs]

-- Here's a function that takes a string and removes everything except uppercase letters from it.
removeNonUppercase st = [ c | c <- st, c `elem` ['A'..'Z']]

