def count[T](list: List[T])(f: T => Boolean): Int = {
  list.foldLeft(0)((a, b) => if (f(b)) a + 1 else a)
}

count(List(1, 2, 3, 3, 2, 2))(x => x == 2)
assert(3 == count(List(1, 2, 3, 3, 2, 2))(x => x == 2))
assert(1 == count(List(1, 2, 3, 3, 2, 2))(x => x == 1))
assert(2 == count(List(1, 2, 3, 3, 2, 2))(x => x == 3))
assert(0 == count(List(1, 2, 3, 3, 2, 2))(x => x == 5))
