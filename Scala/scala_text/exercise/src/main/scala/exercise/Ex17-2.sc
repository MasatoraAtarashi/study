implicit def optionToBool(arg: Option[Any]): Boolean = arg.isDefined

val a = None
if (a) {
  println("Some")
} else {
  println("None")
}
