{-
  :: is read as "has type of".
  Explicit types are always denoted with the first letter in capital case.
  The parameters are separated with ->
  and there's no special distinction between the parameters and the return type.
  The return type is the last item in the declaration
  Everything before the => symbol is called a `class constraint`.
-}
lucky :: (Intergral a) => a -> String
lucky 7 = "LUCKY NUMBER SEVEN!"
lucky x = "Sorry, you're out of luck, pal!"


factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial n = n * factorial (n - 1)


{-
  we wanted to make a function that takes two vectors in a 2D space (that are in the form of pairs) and adds them together
-}
-- if we didn't know about pattern matching
addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
addVectors a b = (fst a + fst b, snd a + snd b)


-- uses pattern matching
addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)


{-
  since [1,2,3] is just syntactic sugar for 1:2:3:[], you can also use the former pattern.
  A pattern like x:xs will bind the head of the list to x and the rest of it to xs,
  even if there's only one element so xs ends up being an empty list.
-}

-- make our own implementation of the head function
head' :: [a] -> a
head' [] = error "Can't call head on an empty list, dummy!"
head' (x:_) = x


-- Let's make a trivial function that tells us some of the first elements of the list in (in)convenient English form.
tell :: (Show a) => [a] -> String
tell [] = "This list is empty"
tell (x:[]) = "The list has one element:" ++ show x
tell (x:y:[]) = "The list has two elments:" ++ show x ++ "and" ++ show y
tell (x:y:_) = "This list is long. The first two elements are:" ++ show x ++ "and" ++ show y
--  Note that (x:[]) and (x:y:[]) could be rewriten as [x] and [x,y] (because its syntatic sugar, we don't need the parentheses).


-- implemented our own length function using pattern matching and a little recursion
length' :: (Num b) => [a] -> b
length' [] = 0
length' (x:xs) = 1 + length' xs


-- implement sum
sum' :: (Num a) => [a] -> a
sum' [] = 0
sum' (x:xs) = x + sum' xs


{-
  There's also a thing called as patterns.
  Those are a handy way of breaking something up according to a pattern and binding it to names whilst still keeping a reference to the whole thing.
  You do that by putting a name and an @ in front of a pattern.

  For instance, the pattern xs@(x:y:ys).
  This pattern will match exactly the same thing as x:y:ys but you can easily get the whole list via xs instead of repeating yourself by typing out x:y:ys in the function body again.
  Here's a quick and dirty example:
-}
capital :: String -> String
capital "" = "Empty string, whoops!"
capital all@(x:xs) = "The first letter of " ++ all ++ " is " ++ [x]