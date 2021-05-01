package exercise

object Main extends App {
  val obj: Any = List("a")
  // obj: Any = List("a")
  obj match {
    case v: List[Int]    => println("List[Int]")
    case v: List[String] => println("List[String]")
  }
  // List[Int]
}
