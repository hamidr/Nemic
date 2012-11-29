data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show, Read, Eq)

singleton a = Node a EmptyTree EmptyTree

treeInsert a EmptyTree = singleton a
treeInsert x (Node a left right ) 
	| x == a = Node a left right
	| x < a  = Node a ( treeInsert x left ) right
	| x > a  = Node a left ( treeInsert x right )


