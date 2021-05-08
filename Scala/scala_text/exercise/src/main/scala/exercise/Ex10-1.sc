class Unko(private val size: Int, private[this] val parent: String)

object Unko {
  def printSize(): Unit = {
    val unko1 = new Unko(3, "masatora")
    print(unko1.size)
  }

  def printParent(): Unit = {
    val unko2 = new Unko(3, "masatora")
    print(unko2.parent)
  }
}

Unko.printSize()
Unko.printParent()
