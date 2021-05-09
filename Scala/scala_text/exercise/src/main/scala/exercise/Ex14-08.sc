def filter[T](list: List[T])(f: T => Boolean): List[T] = {
  list.foldLeft(Nil: List[T])((a, b) => if (f(b)) b :: a else a).reverse
}

filter(List(1, 2, 3))(x => x % 2 == 0)
assert(List(2) == filter(List(1, 2, 3))(x => x % 2 == 0))
assert(List(1, 3) == filter(List(1, 2, 3))(x => x % 2 == 1))
assert(Nil == filter(List(1, 2, 3))(x => x > 3))
assert(List(1) == filter(List(1))(x => x == 1))
assert(Nil == filter(List[Int]())(x => false))
