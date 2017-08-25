addTwoNumbers a b = a+b

main = do
    v1 <- readLn
    v2 <- readLn
    let sum = addTwoNumbers v1 v2
    print sum