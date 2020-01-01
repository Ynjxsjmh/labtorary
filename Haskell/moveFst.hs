-- Use `runghc moveFst.hs` first to generate `moveFst.exe`
-- Then use `.\moveFst example.txt` to get the formatted `result.txt`

import System.Environment (getArgs)
import System.IO
import Data.List

main = do
  args <- getArgs
  file <- openFile (head args) ReadMode
  -- value of encoding see https://hackage.haskell.org/package/base-4.12.0.0/docs/System-IO.html#t:TextEncoding
  hSetEncoding file utf8
  text <- hGetContents file

  outh <- openFile ((getDir . head $ args) ++ "result.txt") WriteMode
  hSetEncoding outh utf8

  let modified = map findFst (lines text)
      in hPutStrLn outh (unlines modified)
  hClose file
  hClose outh

getDir :: String -> String
getDir str
  | length dirs > 1 = compl '\\' (init dirs)
  | otherwise = ""
  where dirs = wordsWhen (=='\\') str

-- 判断第一个符号是不是指定的符号
findFst :: String -> String
findFst [] = []
findFst (fst:line)
  | fst == '>' || fst == '<' = moveFst fst line
  | otherwise = [fst] ++ line

-- 相当于 unlines，不过要添加 >
-- ++ "delimter" 是因为 wordsWhen 删去了所有 delimter，这里补回来
myconcat :: Char -> Char -> [String] -> String
myconcat delimter fst xs = head xs ++ [delimter] ++ [fst] ++ (compl delimter . tail $ xs)

-- 补回 delimter
compl :: Char -> [String] -> String
compl _ [] = []
compl delimter (x:xs) = x ++ [delimter] ++ compl delimter xs

-- 根据指定符号分割 String
wordsWhen :: (Char -> Bool) -> String -> [String]
wordsWhen p s =  case dropWhile p s of
                      "" -> []
                      s' -> w : wordsWhen p s''
                            where (w, s'') = break p s'

-- 将开头的字符移到第一个 > 之后
moveFst :: Char -> String -> String
moveFst fst line = let words = wordsWhen (=='>') line
                       in myconcat '>' fst words

