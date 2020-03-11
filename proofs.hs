{-|
Functor laws:
fmap id = id
fmap (f . g)  ==  fmap f . fmap g

Reader functor:
fmap :: (a -> b) -> (r -> a) -> (r -> b)

fmap f g = f . g
fmap id f g = f . (id g) = f . g = id(f . g)

fmap (f' . g') f g = f ((f' . g') g) = f (f'(g' g)) = fmap f' f(g' g) = 
    fmap f' (fmap g' (f g)) = fmap f' . fmap g' (f . g)

-}