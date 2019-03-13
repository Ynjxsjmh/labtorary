{-
  Whereas patterns are a way of making sure a value conforms to some form and deconstructing it

  guards are a way of testing whether some property of a value (or several of them) are true or false. That sounds a lot like an if statement and it's very similar.

  The thing is that guards are a lot more readable when you have several conditions and they play really nicely with patterns.
-}
bmiTell :: (RealFloat a) => a -> String
bmiTell bmi
    | bmi <= 18.5 = "You're underweight, you emo, you!"
    | bmi <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly!"
    | bmi <= 30.0 = "You're fat! Lose some weight, fatty!"
    | otherwise   = "You're a whale, congratulations!"

{-
  Guards are indicated by pipes that follow a function's name and its parameters.

  Usually, they're indented a bit to the right and lined up.

  A guard is basically a boolean expression.
    If it evaluates to True, then the corresponding function body is used.
    If it evaluates to False, checking drops through to the next guard and so on.
-}


-- implement our own max function
max' :: (Ord a) => a -> a -> a

max' a b
     | a > b = a
     | otherwise = b


-- implement our own compare
myCompare :: (Ord a) => a -> a -> Ordering

a `myCompare` b
  | a > b = GT
  | a == b = EQ
  | otherwise = LT