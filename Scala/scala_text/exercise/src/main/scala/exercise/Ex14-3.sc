def reverse[T](list: List[T]): List[T] = {
  list.foldLeft(Nil: List[T])((x, y) => x.::(y) )
}

println(List(1, 2, 3, 4, 5).mkString)
println(reverse(List(1, 2, 3, 4, 5)).mkString)
// res26: List[Int] = List(5, 4, 3, 2, 1)
