type Punto = (Float, Float)
type Radio = Float

data Figura = Circulo Punto Radio 
       | Rectangulo Punto Punto

area :: Figura -> Float -- recuerden la defincion
area (Circulo p r)    = 3.1416 * r * r
area (Rectangulo p q) = base * altura
                        where base   = fst q - fst p
                              altura = snd q - snd p


instance Eq Figura 
  where
       Circulo p r1 == Circulo q r2 =
         area (Circulo p r1) == area (Circulo q r2)
       Rectangulo p1 p2 == Rectangulo p3 p4 =
         area (Rectangulo p1 p2) == area (Rectangulo p3 p4)
       Circulo p r1 == Rectangulo p1 p2 =
         area (Circulo p r1) == area (Rectangulo p1 p2)
       Rectangulo p1 p2 == Circulo p r1 =
         area (Circulo p r1) == area (Rectangulo p1 p2)

