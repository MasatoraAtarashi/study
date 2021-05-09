def sum(list: List[Int]): Int = list.foldRight(0)((a, b) => a + b)
println(sum(List(1, 2, 3, 4, 5)))
