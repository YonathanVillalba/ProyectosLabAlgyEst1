data Forma = Piedra | Papel | Tijera 
type Nombre = String 
data Jugador = Mano Nombre Forma

leGana :: Forma -> Forma -> Bool

leGana Piedra Tijera = True
leGana Tijera Papel = True
leGana Papel Piedra = True
leGana _ _ = False

ganador :: Jugador -> Jugador -> Maybe Nombre

ganador (Mano n1 f1) (Mano n2 f2)   | leGana f1 f2 = Just n1
                                    | leGana f2 f1 = Just n2
                                    | otherwise = Nothing


quienJugo :: Forma -> [Jugador] -> [Nombre]

quienJugo _ [] = [] 
quienJugo f ((Mano n f1):xs) | mismaForma f f1 = n : quienJugo f xs 
                             | otherwise = quienJugo f xs


mismaForma :: Forma -> Forma -> Bool

mismaForma Piedra Piedra = True
mismaForma Tijera Tijera = True
mismaForma Papel Papel = True
mismaForma _ _ = False



data Temperatura = A | B | F | G | K | M | O deriving (Show)
data Luminicidad = SuperGigante | Gigante | SecuenciaPrincipal | Enana deriving (Show)
data Estructura = Rocoso | Gaseoso deriving (Show)

type NumSat = Int
type DistEstrella = Float

data Planeta = Planeta Estructura NumSat DistEstrella deriving (Show)
data Estrella = Estrella Luminicidad Temperatura Nombre String deriving (Show)

data Astro = AstroEstrella Estrella | AstroPlaneta Planeta deriving (Show)

masSatelites :: [Astro] -> Int -> [Astro]
masSatelites [] _ = []
masSatelites (x:xs) n
  | esPlanetaConMasSatelites x n = x : masSatelites xs n
  | otherwise = masSatelites xs n

esPlanetaConMasSatelites :: Astro -> Int -> Bool
esPlanetaConMasSatelites (AstroPlaneta (Planeta _ numSat _)) n = numSat >= n
esPlanetaConMasSatelites _ _ = False



data Nivel = Uno | Dos | Tres deriving (Show, Eq)
data NotasDeIngles = EvolucionDelEstudiante String Nivel Int Int Int NotasDeIngles
                    | NoHayMasEstudiantes deriving Show

pasaDeNivel :: NotasDeIngles -> String -> Bool
pasaDeNivel NoHayMasEstudiantes _ = False
pasaDeNivel (EvolucionDelEstudiante nombre Uno parcial1 parcial2 final _) estudiante
    | nombre == estudiante = (parcial1 > 8 || parcial2 > 8) && final >= 7
    | otherwise = False
pasaDeNivel (EvolucionDelEstudiante nombre Dos parcial1 parcial2 final _) estudiante
    | nombre == estudiante = (parcial1 > 8 || parcial2 > 8) && final >= 7
    | otherwise = False
pasaDeNivel (EvolucionDelEstudiante nombre Tres parcial1 parcial2 final _) estudiante
    | nombre == estudiante = parcial1 >= 6 && parcial2 >= 6 && final >= 7
    | otherwise = False
pasaDeNivel (EvolucionDelEstudiante _ _ _ _ _ resto) estudiante = pasaDeNivel resto estudiante

devolverNotaFinal :: NotasDeIngles -> String -> Maybe Int
devolverNotaFinal NoHayMasEstudiantes _ = Nothing
devolverNotaFinal (EvolucionDelEstudiante nombre _ _ _ final _) estudiante
    | nombre == estudiante = Just final
    | otherwise = devolverNotaFinal resto estudiante
