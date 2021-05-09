// foldleft版はできなかった
//def find[T](list: List[T])(f: T => Boolean): Option[T] = {
//  list.foldLeft()((a, b) => if (f(b)) return Some(b) else None)
//}

// recursive
def find[T](list: List[T])(f: T => Boolean): Option[T] = list match {
  case x::xs if (f(x)) => Some(x)
  case x::xs => find(xs)(f)
  case _ => None
}

find(List(1, 2, 3))(x => x == 2)

assert(Some(2) == find(List(1, 2, 3))(x => x == 2))
assert(None == find(List(1, 2, 3))(x => x > 3))
assert(Some(1) == find(List(1))(x => x == 1))
assert(None == find(List(1))(x => false))
assert(None == find(List[Int]())(x => x == 1))
