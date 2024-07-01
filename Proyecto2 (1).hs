--1)

--a) Implementa el tipo Carrera como esta definido arriba.
data Carrera = Matematica | Fisica | Computacion | Astronomia deriving (Eq, Show)

--b) Definı la siguiente funcion, usando pattern matching: titulo :: Carrera -> String
--que devuelve el nombre completo de la carrera en forma de string.
titulo :: Carrera -> String
titulo Matematica = "Lic en Matematica"
titulo Fisica = "Lic en Fisica"
titulo Computacion = "Lic en Computacion"
titulo Astronomia = "Lic en Astronomia"

-- *Main> titulo Matematica 
-- "Lic en Matematica"
-- *Main> titulo Fisica 
-- "Lic en Fisica"

--c) Definir el tipo NotaBasica con constructores Do, Re, Mi, Fa, Sol, La y Si
--data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si

--d) Programar usando pattern matching la funcion cifradoAmericano que relaciona las notas Do, Re, Mi, Fa, Sol, La y Si con los caracteres ’C’ , ’D’, ’E’,
-- ’F’, ’G’, ’A’ y ’B’ respectivamente.

cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B'

-- *Main> titulo Matematica 
-- "Lic en Matematica"
-- *Main> titulo Fisica 
-- "Lic en Fisica"

--2) Completar la definicion del tipo NotaBasica para que las expresiones sean validas y no generen error.

--Para completar la definicion de nota basica es necesario agregar un deriving Eq y Ord para poder comparar las notas
data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si deriving (Show,Eq,Ord)

--3) Polimorfismo ad hoc

--a) Definir usando polimorfismo ad hoc la funcion minimoElemento que calcula (de manera
--recursiva) cual es el menor valor de una lista de tipo [a]. Asegurarse que solo este
--definida para listas no vacias.
minimoElemento :: Ord a=> [a] -> a
minimoElemento [x] = x
minimoElemento (x:xs) = min x (minimoElemento xs)

-- *Main> minimoElemento [2, 3, 4, 1]
-- 1
-- *Main> minimoElemento [2]
-- 2

--b) Definir la funcion minimoElemento’ de manera tal que el caso base de la recursion
--sea el de la lista vacıa. Para ello revisar la clase Bounded.
minimoElemento' :: (Bounded a, Ord a) => [a] -> a
minimoElemento' [] = maxBound
minimoElemento' (x:xs) = min x (minimoElemento' xs)

-- *Main> minimoElemento' ([1,2,3,4]::[Int])
-- 1
-- *Main> minimoElemento' ([]::[Int])
-- 9223372036854775807

--c)-Usar la funcion minimoElemento para determinar la nota mas grave de la melodıa:
--[Fa, La, Sol, Re, Fa]

--minimoElemento [Fa, La, Sol, Re, Fa] = Re

--4) Sinonimo de tipos; constructores con parametros.

type Altura = Int
type NumCamiseta = Int

data Zona = Arco | Defensa | Mediocampo | Delantera   deriving (Eq, Show)
data TipoReves =  DosManos | UnaMano  deriving (Eq, Show)
data Modalidad = Carretera | Pista | Monte | BMX  deriving (Eq, Show)
data PiernaHabil = Izquierda | Derecha  deriving (Eq, Show)

type ManoHabil = PiernaHabil

data Deportista = Ajedrecista
                | Ciclista Modalidad
                | Velocista Altura
                | Tenista TipoReves ManoHabil Altura
                | Futbolista Zona NumCamiseta PiernaHabil Altura deriving (Eq, Show)


--a) Implementa el tipo Deportista y todos sus accesorios como esta definido arriba.

--b) ¿Cual es el tipo del constructor Ciclista?
--El tipo del constructor Ciclista es Deportista

--c) Programar la funcion contar_velocistas

contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0
contar_velocistas ((Velocista _) :xs) = 1 + contar_velocistas xs
contar_velocistas ((Ajedrecista) :xs) = contar_velocistas xs
contar_velocistas ((Ciclista _) :xs) = contar_velocistas xs
contar_velocistas ((Tenista _ _ _) :xs) = contar_velocistas xs
contar_velocistas ((Futbolista _ _ _ _) :xs) = contar_velocistas xs

-- *Main> contar_velocistas [Ajedrecista, Ajedrecista, Ciclista BMX, Ciclista Carretera ]
-- 0
-- *Main> contar_velocistas [Ajedrecista , Ciclista BMX, Velocista 2]
-- 1

--d) Programas la funcion contar_futbolista

contar_futbolista :: [Deportista] -> Zona -> Int
contar_futbolista [] z = 0
contar_futbolista (x:xs) z | esFutbolista z x = 1 + contar_futbolista xs z
                           | otherwise = contar_futbolista xs z

-- *Main> contar_futbolista [Ajedrecista , Futbolista Defensa 2 Derecha 1, Futbolista Defensa 4 Izquierda 2] Defensa
-- 2
-- *Main> contar_futbolista [Ajedrecista , Futbolista Defensa 2 Derecha 1, Futbolista Defensa 4 Izquierda 2] Arco 
-- 0

esFutbolista :: Zona -> Deportista -> Bool
esFutbolista z (Futbolista zona _ _ _) = z==zona
esFutbolista _ _ = False

--d) ¿La funcion anterior usa filter? Si no es ası, reprogramala para usarla.
contar_futbolista' :: [Deportista] -> Zona -> Int
contar_futbolista' [] z = 0
contar_futbolista' xs z = length (filter (esFutbolista z) xs)

-- *Main> contar_futbolista [Ajedrecista , Futbolista Defensa 2 Derecha 1, Futbolista Defensa 4 Izquierda 2] Defensa
-- 2
-- *Main> contar_futbolista [Ajedrecista , Futbolista Defensa 2 Derecha 1, Futbolista Defensa 4 Izquierda 2] Arco 
-- 0

--5) Definicion de clases.

--b-c) Implementa los tipos NotaMusical, Alteracion y la funcion sonido como estan
--definidos arriba.
data Alteracion = Bemol | Sostenido | Natural deriving (Eq, Ord)
data NotaMusical = Nota NotaBasica Alteracion deriving (Eq, Ord)

--a)
sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 1
sonidoNatural Re = 3
sonidoNatural Mi = 5
sonidoNatural Fa = 6
sonidoNatural Sol = 8
sonidoNatural La = 10
sonidoNatural Si = 12

-- *Main> sonidoNatural Do
-- 1
-- *Main> sonidoNatural Re
-- 3

--d) Definı la funcion sonidoCromatico :: NotaMusical -> Int que devuelve el sonido
--de una nota, incrementando en uno su valor si tiene la alteracion Sostenido, decre-
--mentando en uno si tiene la alteracion Bemol y dejando su valor intacto si la alteracion
--es Natural
sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota n a) | a==Bemol = (sonidoNatural n) - 1
                           | a==Sostenido = (sonidoNatural n) +1
                           | a==Natural = sonidoNatural n

-- *Main> sonidoCromatico (Nota Sol Natural)
-- 8
-- *Main> sonidoCromatico (Nota Re Sostenido)
-- 4

--6) Tipos enumerados con polimorfismo.

--a) Definir la funcion primerElemento que devuelve el primer elemento de una lista no
--vacıa, o Nothing si la lista es vacıa.
primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:xs) = Just x

-- *Main> primerElemento [2,3,4]
-- Just 2
-- *Main> primerElemento  []
-- Nothing

--7) Tipos recursivos. Programa las siguientes funciones

data Cola = VaciaC | Encolada Deportista Cola deriving Show

--a) atender :: Cola -> Maybe Cola, que elimina de la cola a la persona que esta
--en la primer posicion de una cola, por haber sido atendida. Si la cola esta vacıa,
--devuelve Nothing.
atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada d c) = Just c

-- *Main> atender (Encolada (Ciclista BMX) VaciaC)
-- Just VaciaC
-- *Main> atender (Encolada (Ciclista BMX) (Encolada Ajedrecista VaciaC))
-- Just (Encolada Ajedrecista VaciaC)

--b) encolar :: Deportista -> Cola -> Cola
encolar :: Deportista -> Cola -> Cola
encolar d VaciaC = Encolada d VaciaC
encolar d (Encolada h c) = Encolada h (encolar d c)


-- *Main> encolar Ajedrecista VaciaC
-- Encolada Ajedrecista VaciaC
-- *Main> encolar (Ciclista BMX) (Encolada Ajedrecista VaciaC)
-- Encolada Ajedrecista (Encolada (Ciclista BMX) VaciaC)
-- *Main> encolar Ajedrecista (Encolada (Ciclista BMX) (Encolada (Velocista 180) VaciaC))
-- Encolada (Ciclista BMX) (Encolada (Velocista 180) (Encolada Ajedrecista VaciaC))


--c) busca :: Cola -> Zona -> Maybe Deportista
busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC n = Nothing
busca (Encolada (Futbolista h num p a) c) n | (h==n) = Just (Futbolista h num p a) 
                                            | otherwise = busca c n
busca (Encolada _ c) n = busca c n

-- *Main> busca VaciaC Arco
-- Nothing
-- *Main> busca (Encolada (Ciclista BMX) (Encolada (Futbolista Defensa 2 Izquierda 1) (Encolada Ajedrecista VaciaC))) Defensa 
-- Just (Futbolista Defensa 2 Izquierda 1)

--d) ¿A que otro tipo se parece Cola?.
-- el tipo cola es parecido a una lista, ya que se le pueden agregar o quitar elementos a la misma y tambien hacer un llamado a un elemento en especial.


--8) Tipos recursivos y polimorficos.

data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving (Show)

type Diccionario = ListaAsoc String String
type Padron = ListaAsoc Int String

--a) ¿Como se debe instanciar el tipo ListaAsoc para representar la informacion almacenada
--en una guıa telefonica?
type GuiaTelef = ListaAsoc String Int


--b) Programa las siguientes funciones:

--1) Programar la funcion la_long :: ListaAsoc a b -> Int que devuelve la can-
--tidad de datos en una lista.
la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo a b l) = 1+ (la_long l)

-- *Main> la_long Vacia
-- 0
-- *Main> la_long (Nodo 2 3 Vacia)
-- 1
-- *Main> la_long (Nodo 2 3 (Nodo 4 5 Vacia))
-- 2

--2) la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b, que de-
--vuelve la concatenacion de dos listas de asociacion.
la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat Vacia l = l 
la_concat (Nodo a b l) m = Nodo a b (la_concat l m)

-- *Main> la_concat Vacia Vacia
-- Vacia
-- *Main> la_concat Vacia (Nodo 1 2 Vacia)
-- Nodo 1 2 Vacia
-- *Main> la_concat (Nodo 1 2 Vacia) (Nodo 3 4 Vacia)
-- Nodo 1 2 (Nodo 3 4 Vacia)

--3) la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b, que
--agrega un nodo a la lista de asociaciones si la clave no esta en la lista, o actualiza
--el valor si la clave ya se encontraba.
la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia a1 b1 = Nodo a1 b1 Vacia
la_agregar (Nodo a b l) a1 b1 | a==a1 = (Nodo a b1 l)
                              | a/=a1 = (Nodo a b (Nodo a1 b1 l))

-- *Main> la_agregar Vacia 1 2
-- Nodo 1 2 Vacia
-- *Main> la_agregar (Nodo 1 2 Vacia) 1 3
-- Nodo 1 3 Vacia
-- *Main> la_agregar (Nodo 1 2 Vacia) 3 4
-- Nodo 1 2 (Nodo 3 4 Vacia)

--4) la_pares :: ListaAsoc a b -> [(a, b)] que transforma una lista de asocia-
--cion en una lista de pares clave-dato.
la_pares :: ListaAsoc a b -> [(a, b)]
la_pares Vacia = []
la_pares (Nodo a b l) = (a,b) : la_pares l

-- *Main> la_pares Vacia
-- []
-- *Main> la_pares (Nodo 1 2 (Nodo 3 4 Vacia))
-- [(1,2),(3,4)]

--5) la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b que dada una lista
--y una clave devuelve el dato asociado, si es que existe. En caso contrario devuelve
--Nothing.
la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia x = Nothing
la_busca (Nodo a b l) x | a==x = Just b
                        | otherwise = la_busca l x

-- *Main> la_busca Vacia 2
-- Nothing
-- *Main> la_busca (Nodo 1 2 Vacia) 1
-- Just 2

--6) la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b que dada
--una clave a elimina la entrada en la lista.
la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar x Vacia = Vacia
la_borrar x (Nodo a b l) | (a==x) = la_borrar x l
                         | otherwise = (Nodo a b (la_borrar x l))

-- *Main> la_borrar 1 Vacia
-- Vacia
-- *Main> la_borrar 1 (Nodo 1 2 Vacia)
-- Vacia
-- *Main> la_borrar 1 (Nodo 1 2 (Nodo 3 4 Vacia))
-- Nodo 3 4 Vacia