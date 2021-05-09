def map[T, U](list: List[T])(f: T => U): List[U] = list.foldLeft(Nil: List[U])((a, b: T) => f(b) :: a).reverse

map(List(1, 2, 3))(x => x + 1)
assert(List(2, 3, 4) == map(List(1, 2, 3))(x => x + 1))
assert(List(2, 4, 6) == map(List(1, 2, 3))(x => x * 2))
assert(Nil == map(List[Int]())(x => x * x))
assert(List(0, 0, 0)  == map(List(1, 2, 3))(x => 0))
