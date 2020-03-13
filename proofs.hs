{-|
Functor laws:
fmap id = id
fmap (f . g)  ==  fmap f . fmap g

Reader functor definition:
fmap :: (a -> b) -> (r -> a) -> (r -> b)
fmap f g = f . g

Proof for the reader functor:
fmap id f g = f . (id g) = f . g = id(f . g)
fmap (f' . g') f g = f ((f' . g') g) = f (f'(g' g)) = fmap f' f(g' g) = 
    fmap f' (fmap g' (f g)) = fmap f' . fmap g' (f . g)

List functor:
fmap :: (a -> b) -> (List a -> List b)
fmap f (Cons x t) = Cons (f x) (fmap f t)

Proof for the list functor:
fmap id f (Cons x t) = Cons id (f x) (fmap f t) = Cons (f x) (fmap f t) =
    id Cons (f x) (fmap f t)
fmap (f' . g') f (Cons x t) = Cons ((f' . g') . f x) (fmap f t) =
    Cons (f'(g'(f x))) (fmap f t) = fmap f' Cons (g'(f x)) (fmap f t) =
    fmap f' (fmap g'(Cons (f x))) (fmap f t) =
    (fmap f' . fmap g') (Cons (f x)) (fmap f t)

-}