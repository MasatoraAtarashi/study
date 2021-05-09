def takeWhile[T](list: List[T])(f: T => Boolean): List[T] = list match {
  case x::xs if f(x) => x :: takeWhile(xs)(f)
  case _ => Nil
}

takeWhile(List(1, 2, 3, 4, 5))(x => x <= 3)
assert(List(1, 2, 3) == takeWhile(List(1, 2, 3, 4, 5))(x => x <= 3))
assert(List(1) == takeWhile(List(1, 2, 3, 3, 4, 5))(x => x == 1))
assert(List(1, 2, 3, 4)  == takeWhile(List(1, 2, 3, 4, 5))(x => x < 5))
assert(Nil == takeWhile(List(1, 2, 3, 3, 2, 2))(x => false))
assert(Nil == takeWhile(List(4, 2, 3, 4, 5))(x => x <= 3))
