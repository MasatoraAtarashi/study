def mkString[T](list: List[T])(sep: String): String = list match {
  case Nil => ""
  case x::xs => xs.foldLeft(x.toString)((a, b) => a + sep + b)
}


println(mkString(List(1,2,3,4,5))(","))
println(List(1,2,3,4,5).mkString(","))
