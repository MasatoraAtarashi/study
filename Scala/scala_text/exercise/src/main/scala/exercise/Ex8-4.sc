for (i <- 1 to 1000) {
  var list = new scala.util.Random(new java.security.SecureRandom()).alphanumeric.take(5).toList
  list match {
    case List(a, b, c, d, e)  => println(a, b, c, d, a)
  }
}
