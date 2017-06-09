main :: IO()
main = do
  input <- getLine
  if (input /= "42")
    then (do
              putStrLn input
              main)
    else return ()
