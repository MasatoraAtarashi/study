def joinByComma(start: Int, end: Int): String = {
  (start to end).mkString(",")
}

println(joinByComma(1,5))
