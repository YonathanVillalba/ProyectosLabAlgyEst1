data ServicioMensajeria = WhatsApp | Telegram | Signal deriving (Show)

tiene_limites :: ServicioMensajeria -> Bool

tiene_limites WhatsApp = True
tiene_limites Telegram = True
tiene_limites Signal = False



type NombreGrupo = String
data Grupos = Ninguno | AgregarGrupo NombreGrupo ServicioMensajeria Grupos

existe_grupo :: NombreGrupo -> Grupos -> Bool

existe_grupo name Ninguno= False
existe_grupo name (AgregarGrupo n app resto) | n == name = True || existe_grupo name resto
                                             | otherwise = False || existe_grupo name resto



que_servicio :: NombreGrupo -> Grupos -> Maybe ServicioMensajeria

que_servicio name Ninguno = Nothing
que_servicio name (AgregarGrupo n app resto) | n == name = Just app
                                             | otherwise = que_servicio name resto



-- *Main> tiene_limites  WhatsApp 
-- True
-- *Main> tiene_limites  Signal 
-- False

-- *Main> existe_grupo  ("loleros") (AgregarGrupo "loleros" WhatsApp Ninguno)
-- True
-- *Main> existe_grupo "loleros" Ninguno
-- False

-- *Main> que_servicio ("loleros") (AgregarGrupo "loleros" Signal Ninguno)
-- Just Signal
-- *Main> que_servicio "loleros" Ninguno
-- Nothing



type Nombre = String
type Desarrollador = String
type Duracion = Int

data Genero = Aventura | Rpg | Deportes deriving (Show)
data Videojuego = Juego Nombre Desarrollador Genero Duracion deriving (Show)

solo_genero :: [Videojuego] -> Genero -> [Nombre]
solo_genero [] g = []
solo_genero ((Juego n d gen du) :xs) g | gen == g = n: solo_genero xs g
                                       | otherwise = solo_genero xs g

instance Eq Genero where
 Aventura == Aventura = True
 Rpg == Rpg = True
 Deportes == Deportes = True
 _ == _ = False

-- *Main> solo_genero [(Juego "lol" "riot" Rpg 2), (Juego "Diablo" "Blizzard" Rpg 3), (Juego "Fifa" "EA" Deportes 4)] Rpg 
-- ["lol","Diablo"]
-- *Main> solo_genero [(Juego "lol" "riot" Aventura 2)] Aventura
-- ["lol"]

solo_genero' :: [Videojuego] -> Genero -> [Nombre]
solo_genero' ((Juego n d Aventura du):xs) Aventura = n: solo_genero' xs Aventura
solo_genero' ((Juego n d Rpg du):xs) Rpg = n: solo_genero' xs Rpg
solo_genero' ((Juego n d Deportes du):xs) Deportes = n: solo_genero' xs Deportes
solo_genero' ((Juego n d Aventura du):xs) Rpg  = solo_genero' xs Rpg
solo_genero' ((Juego n d Aventura du):xs) Deportes  = solo_genero' xs Deportes
solo_genero' ((Juego n d Rpg du):xs) Aventura  = solo_genero' xs Aventura
solo_genero' ((Juego n d Rpg du):xs) Deportes  = solo_genero' xs Deportes
solo_genero' ((Juego n d Deportes du):xs) Aventura  = solo_genero' xs Aventura
solo_genero' ((Juego n d Deportes du):xs) Rpg  = solo_genero' xs Rpg

-- Si bien el programa compila me tira un error con el pattern ya que no cubre todos los casos, lo puse de esta manera ya que usando 
-- solo_genero' ((juego n d _ du):xs) _ = solo_genero' xs _ me tira error y ni compila que era la unica otra alternativa que se me ocurrio
-- ["lol"*** Exception: ParcialHaskellej2.hs:(25,1)-(33,68): Non-exhaustive patterns in function solo_genero'