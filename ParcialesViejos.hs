-- Parcial 1 2022 (tema F)

data Color = Rojo | Verde | Azul | Negro | Blanco
type Nombre = String
type Costo = Int
type Daño = Int
type Resistencia = Int
data CartaMagic = CartaDeTerreno Nombre Color | CartaDeCriatura Nombre Costo Daño Resistencia 

mismoColor:: Color -> Color -> Bool

mismoColor Rojo Rojo = True
mismoColor Verde Verde = True
mismoColor Azul Azul = True
mismoColor Negro Negro = True
mismoColor Blanco Blanco = True
mismoColor _ _ = False


cuantoDaño :: CartaMagic -> Int

cuantoDaño (CartaDeTerreno n1 c) = 0
cuantoDaño (CartaDeCriatura n2 cost d r) = d


cartaMagicOrd :: CartaMagic -> CartaMagic -> Bool

cartaMagicOrd (CartaDeTerreno _ _) _ = False
cartaMagicOrd _ (CartaDeTerreno _ _) = True
cartaMagicOrd (CartaDeCriatura n1 cost d r) (CartaDeCriatura n2 cost2 d2 r2) = d>=d2



soloTerreno :: [CartaMagic] -> Color -> [Nombre]

soloTerreno [] _ = []  
soloTerreno ((CartaDeTerreno n c):xs) col
                                           | igualColor (CartaDeTerreno n c) col = n : soloTerreno xs col
                                           | otherwise = soloTerreno xs col
soloTerreno (_:xs) col = soloTerreno xs col  


igualColor :: CartaMagic -> Color -> Bool

igualColor (CartaDeTerreno n c) col = mismoColor c col
igualColor (CartaDeCriatura n2 cost d r) col = False




-- Definición del tipo de datos lista asociativa
data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving (Show, Eq)

-- Función que devuelve una lista con los nodos que tienen el segundo valor menor que un valor dado
la_menores :: Ord b => ListaAsoc a b -> b -> ListaAsoc a b
la_menores Vacia _ = Vacia  -- Caso base: lista vacía
la_menores (Nodo a b l) x
    | b < x    = Nodo a b (la_menores l x)  -- Si la condición es verdadera
    | otherwise = la_menores l x  -- Si no se cumple la condición



--Parcial 1 2022 (tema E)

type Cantidad = Int
data Dedicacion = Simple | Semi | Full | Investigador

mismaDedicacion :: Dedicacion -> Dedicacion -> Bool

mismaDedicacion Simple Simple = True
mismaDedicacion Semi Semi = True
mismaDedicacion Full Full = True
mismaDedicacion Investigador Investigador = True
mismaDedicacion _ _ = False


la_misma_valor :: Eq b => ListaAsoc a b -> b -> ListaAsoc a b

la_misma_valor Vacia _ = Vacia
la_misma_valor (Nodo a b l) x | b == x = Nodo a b (la_misma_valor l x)
                         | otherwise = (la_misma_valor l x)




-- Parcial 1 2023 (tema B)

type Titulo = String
type Precio = Int
type AñoAgenda = Int

data Categoria = Literatura | Infantiles | AutoAyuda | Comics deriving (Show)
data Editorial = Altea | Minotauro | Panini deriving (Show)
data Marca = Monoblock | Papikra deriving (Show)

data Libro = Libro Categoria Editorial Titulo Precio deriving (Show)
data Agenda = Agenda Marca AñoAgenda Precio deriving (Show)
data Cuaderno = Cuaderno Marca Precio deriving (Show)

data ArticulosLibreria =
    ArticuloLibro Libro
  | ArticuloAgenda Agenda
  | ArticuloCuaderno Cuaderno
  deriving (Show)

librosBaratos :: [ArticulosLibreria] -> Precio -> [ArticulosLibreria]
librosBaratos [] _ = []
librosBaratos (x:xs) p
  | precioMenor x p = x : librosBaratos xs p
  | otherwise = librosBaratos xs p

precioMenor :: ArticulosLibreria -> Int -> Bool
precioMenor (ArticuloLibro (Libro _ _ _ p1)) precio = p1 <= precio
precioMenor (ArticuloAgenda (Agenda _ _ p2)) precio = p2 <= precio
precioMenor (ArticuloCuaderno (Cuaderno _ p3)) precio = p3 <= precio

instance Eq Categoria where 
 Literatura == Literatura = True 
 Infantiles == Infantiles = True 
 AutoAyuda == AutoAyuda = True 
 Comics == Comics = True 
 _ == _ = False 

instance Eq Editorial where 
 Altea == Altea = True 
 Minotauro == Minotauro = True 
 Panini == Panini = True 
 _ == _ = False 

instance Eq Marca where 
 Monoblock == Monoblock = True 
 Papikra == Papikra = True 
 _ == _ = False 

instance Eq Libro where 
 (Libro cat1 ed1 tit1 pre1) == (Libro cat2 ed2 tit2 pre2) = cat1 == cat2 && ed1 == ed2 && tit1 == tit2 && pre1 == pre2 

instance Eq Agenda where 
 (Agenda mar1 año1 pre1) == (Agenda mar2 año2 pre2) = mar1 == mar2 && año1 == año2 && pre1 == pre2 

instance Eq Cuaderno where 
 (Cuaderno mar1 pre1) == (Cuaderno mar2 pre2) = mar1 == mar2 && pre1 == pre2 

instance Eq ArticulosLibreria where 
 (ArticuloLibro libro1) == (ArticuloLibro libro2) = libro1 == libro2 
 (ArticuloAgenda agenda1) == (ArticuloAgenda agenda2) = agenda1 == agenda2 
 (ArticuloCuaderno cuaderno1) == (ArticuloCuaderno cuaderno2) = cuaderno1 == cuaderno2 
 _ == _ = False  

