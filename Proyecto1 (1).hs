{-# LANGUAGE NPlusKPatterns #-}
--Ejercicio 1
--a)
esCero :: Int -> Bool
esCero x = x==0 

-- *Main> esCero 2
-- False
-- *Main> esCero 0
-- True

--Ejercicio 1
--b)
esPositivo :: Int -> Bool
esPositivo x = x>0

-- *Main> esPositivo 2
-- True
-- *Main> esPositivo (-4)
-- False

--Ejercicio 1
--c)
esVocal :: Char -> Bool
esVocal x | x == 'a' = True
          | x == 'e' = True
          | x == 'i' = True
          | x == 'o' = True
          | x == 'u' = True
          | otherwise = False

-- *Main> esVocal 'a'
-- True
-- *Main> esVocal 't'
-- False

--Ejercicio 1
--d)
valorAbsoluto :: Int -> Int
valorAbsoluto x | x>=0 = x
                | x<0 = x*(-1)

-- *Main> valorAbsoluto 2
-- 2
-- *Main> valorAbsoluto (-2)
-- 2

--Ejercicio 2
--a)
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) | x == True = paratodo xs
                | otherwise = False

-- *Main> paratodo [True, True, True]
-- True
-- *Main> paratodo [True, False, True]
-- False

--Ejercicio 2
--b)
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

-- *Main> sumatoria  [2, 10, 20]
-- 32
-- *Main> sumatoria []
-- 0

--Ejercicio 2
--c)
productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs

-- *Main> productoria [2, 4, 5]
-- 40
-- *Main> productoria []
-- 1

--Ejercicio 2
--d)
factorial :: Int -> Int
factorial 0 = 1
factorial x = x * factorial (x-1)

-- *Main> factorial 5
-- 120
-- *Main> factorial 3
-- 6

--Ejercicio 2
--e)
promedio :: [Int] -> Int
promedio [] = 0
promedio (x:xs) = div (x + sumatoria xs) (1 + contador xs)

contador :: [Int] -> Int
contador [] = 0
contador (_:xs) = 1 + contador xs

-- *Main> promedio [2, 4]
-- 3
-- *Main> promedio [7, 6, 8]
-- 7

-- Ejercicio 3
pertenece :: Int -> [Int] -> Bool
pertenece y [] = False
pertenece y (x:xs) | y == x = True 
                   | otherwise = pertenece y xs

-- *Main> pertenece 2 [4,6]
-- False
-- *Main> pertenece 2 [2, 4]
-- True

-- Ejercicio 4
-- a)
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] p = True
paratodo' (x:xs) p = (p x) && paratodo' xs p

-- *Main> paratodo' [0, 0, 0, 0] esCero 
-- True
-- *Main> paratodo' [2, 4, (-6)] esPositivo 
-- False

-- Ejercicio 4
-- b)
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] p = False
existe' (x:xs) p = (p x) || existe' xs p

-- *Main> existe' [0, 1, 0] esCero 
-- True
-- *Main> existe' [(-3), (-6)] esPositivo 
-- False

-- Ejercicio 4
-- c)
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] p = 0
sumatoria' (x:xs) p = (p x) + sumatoria' xs p

-- sumatoria' [2, (-2)] valorAbsoluto 
-- 4
-- *Main> sumatoria' [2, (-2), (-6), 4] valorAbsoluto 
-- 14

-- Ejercicio 4
-- d)
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] p = 1
productoria' (x:xs) p  = (p x) * productoria' xs p

-- *Main> productoria' [2, (-5), 3] valorAbsoluto 
-- 30
-- *Main> productoria' [2, (-5), 3, (-10)] valorAbsoluto 
-- 300

-- Ejercicio 5
paratodo'' :: [Bool] -> Bool
paratodo'' xs = paratodo' xs id

-- *Main> paratodo'' [False, True, True]
-- False
-- *Main> paratodo'' [True, True, True]
-- True

-- Ejercicio 6
--a)
todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs esPar

esPar :: Int -> Bool
esPar x = (mod x 2)== 0

-- *Main> todosPares [2, 4, 6]
-- True
-- *Main> todosPares [2, 4, 7]
-- False

-- Ejercicio 6
--b)
hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo y xs = existe' xs (encontrarMultiplo y)

encontrarMultiplo :: Int -> Int -> Bool
encontrarMultiplo x y = (mod y x)==0

-- *Main> hayMultiplo 2 [2, 0, 3]
-- True
-- *Main> hayMultiplo 3 [2, 4, 6]
-- True

-- Ejercicio 6
-- c)
sumaCuadrados :: Int -> Int
sumaCuadrados x = sumatoria' [1..x] calcularCuadrados

calcularCuadrados :: Int -> Int
calcularCuadrados x = x*x

-- *Main> sumaCuadrados 4
-- 30
-- *Main> sumaCuadrados 3
-- 14

-- Ejercicio 6
-- d)
existeDivisor::Int-> [Int] -> Bool
existeDivisor y xs = existe' xs (esDivisor y)

esDivisor :: Int -> Int -> Bool
esDivisor x y = (mod x y) == 0

-- *Main> existeDivisor 20 [2, 5, 10]
-- True
-- *Main> existeDivisor 17 [2, 5, 10]
-- False

-- Ejercicio 6
-- e)
esPrimo:: Int -> Bool
esPrimo x = x>1 && not(existeDivisor x [2..x-1])

-- *Main> esPrimo 5
-- True
-- *Main> esPrimo 17
-- True
-- *Main> esPrimo 4
-- False

-- Ejercicio 6
-- f)
factorial' :: Int -> Int
factorial' x = productoria' [1..x] id

-- factorial' 3
-- 6
-- factorial' 4
-- 24

-- Ejercicio 6)
-- g)
multiplicaPrimos :: [Int] -> Int
multiplicaPrimos xs = productoria' (filter esPrimo xs) id

-- *Main> multiplicaPrimos [2, 3, 6]
-- 6
-- *Main> multiplicaPrimos [2, 6, 8]
-- 2

-- Ejercicio 6
-- h)
esFib :: Int -> Bool
esFib x = pertenece x (map fib [0..(x+1)])

fib :: Int -> Int
fib x | x<=1 = x
      |otherwise = fib(x-1) + fib(x-2)

-- *Main> esFib 2
-- True
-- *Main> esFib 89
-- True

-- Ejercicio 6
-- i)
todosFib :: [Int] -> Bool
todosFib xs = paratodo' xs esFib

-- *Main> todosFib [1, 2, 3]
-- True
-- *Main> todosFib [1, 4, 3]
-- False

-- Ejercicio 7

-- ¿Que hacen estas funciones (map y filter)?

-- Las funciones map y filter tienen funcionamientos similares pero presentan pequeñas variaciones. La funcion map se encarga 
-- de aplicarle una funcion especifica a todos los elementos de una lista devolviendo una lista de la misma longitud, ya que no se perderia ningun valor
-- Por su parte la funcion filter, se encarga de aplicar un predicado eliminativo a todos los elementos de la lista, por lo tanto, la lista resultante puede variar en longitud con respecto a la original 
-- Por lo tanto estas dos formas de funciones se encargan de aplicar un predicado a todos los elementos de la lista. 


-- ¿A que equivale la expresion map succ [1, -4, 6, 2, -8], donde succ n = n+1?

-- map succ [1, -4, 6, 2, -8] ---> [2,-3,7,3,-7] la Funcion succ sumada a map le suma 1 a todos los elementos de la lista 


-- ¿Y la expresion filter esPositivo [1, -4, 6, 2, -8]?

-- filter esPositivo [1, -4, 6, 2, -8] ---> [1,6,2] La funcion esPositivo sumada a filter devuelve una lista solamente con los elementos que devuelvan true al termino aplicado, por eso la lista no tiene la misma longitud que la original 

-- Ejercicio 8
-- a)
duplica :: [Int] -> [Int]
duplica [] = []
duplica (x:xs) = x*2 : duplica xs

-- *Main> duplica [2, 4, 10]
-- [4,8,20]

-- b)
duplica' :: [Int] -> [Int]
duplica' xs = (map multiplicarPorDos xs)

multiplicarPorDos :: Int -> Int
multiplicarPorDos x = x*2

-- *Main> duplica' [2, 4, 10]
-- [4,8,20]

-- Ejercicio 9
-- a)
primosFilter :: [Int] -> [Int]
primosFilter [] = []
primosFilter (x:xs) | esPrimo x == True = x : primosFilter xs
                    | esPrimo x == False = primosFilter xs

-- *Main> primosFilter [2, 3, 6]
-- [2,3]
-- *Main> primosFilter [4, 6, 8]
-- []

-- b)
primosFilter' :: [Int] -> [Int]
primosFilter' xs = filter esPrimo xs

-- *Main> primosFilter' [2, 5, 7]
-- [2,5,7]
-- *Main> primosFilter' [2, 4, 6]
-- [2]

--c)
multiplicaPrimos' :: [Int] -> Int
multiplicaPrimos' xs = productoria (primosFilter' xs)

-- *Main> multiplicaPrimos' [2, 3, 4]
-- 6
-- *Main> multiplicaPrimos' [2, 4]
-- 2

-- Ejercicio 10
-- a)
primIgualesA :: Eq a => a -> [a] -> [a]
primIgualesA _ [] = []
primIgualesA y (x:xs) | y == x = x : primIgualesA y xs
                     | otherwise = []

-- primIgualesA 3 [3,3,4,1] = [3,3]
-- primIgualesA 3 [4,3,3,4,1] = []
-- primIgualesA 3 [] = []
-- primIgualesA 'a' "aaadaa" = "aaa"

-- b)
primIgualesA' :: Eq a => a -> [a] -> [a]
primIgualesA' y xs = takeWhile (== y) xs

-- primIgualesA' 3 [3,3,4,1] = [3,3]
-- primIgualesA' 3 [4,3,3,4,1] = []
-- primIgualesA' 3 [] = []
-- primIgualesA' 'a' "aaadaa" = "aaa"

-- Ejercicio 11
-- a)
primIguales :: Eq a => [a] -> [a]
primIguales [] = []
primIguales [a] = [a]
primIguales (x:(y:xs)) | (x == y) = x : primIguales (y:xs)
                       | (x /= y) = primIguales [x]

-- primIguales [3,3,4,1] = [3,3]
-- primIguales [4,3,3,4,1] = [4]
-- primIguales [] = []
-- primIguales "aaadaa" = "aaa"

-- b)
primIguales' :: Eq a => [a] -> [a]
primIguales' (x:xs) = primIgualesA' x (x:xs)

-- primIguales [3,3,4,1] = [3,3]
-- primIguales [4,3,3,4,1] = [4]
-- primIguales [] = []
-- primIguales "aaadaa" = "aaa"