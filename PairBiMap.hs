module PairBiMap where

data PairBMap a b = PairBMap a b
bimap :: (a -> b) -> (c -> d) -> PairBMap a c -> PairBMap b d
bimap f g (PairBMap x y) = PairBMap (f x) (g y)

first :: (a -> c) -> PairBMap a b -> PairBMap c b
first g (PairBMap x y) = PairBMap (g x) y

second :: (b -> d) -> PairBMap a b -> PairBMap a d
second g (PairBMap x y) = PairBMap x (g y)