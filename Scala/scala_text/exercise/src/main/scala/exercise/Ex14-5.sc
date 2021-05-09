def mul(list: List[Int]): Int = list.foldRight(1)((a, b) => a * b)
println(mul(List(1, 2, 3, 4, 5)))
