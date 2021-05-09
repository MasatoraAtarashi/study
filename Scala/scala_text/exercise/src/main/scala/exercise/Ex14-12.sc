def map[T, U](list: List[T])(f: T => U): List[U] = list.foldLeft(Nil: List[U])((a, b: T) => f(b) :: a).reverse

def flatMap[T, U](list: List[T])(f: T => List[U]): List[U] = list match {
  case x::xs => f(x) ++ flatMap(xs)(f)
  case _ => Nil
}

flatMap(List(1, 2))(x =>
  map(List(3, 4))(y => x * y)
)
assert(List(1, 2, 3) == flatMap(List(1, 2, 3))(x => List(x)))
assert(
  List(3, 4, 6, 8) == flatMap(List(1, 2))(x =>
    map(List(3, 4))(y => x * y)
  )
)

