import scala.io.Source
def withFile[A](filename: String)(f: Source => A): A = {
  val s = Source.fromFile(filename)
  try {
    f(s)
  } finally {
    s.close()
  }
}

def printFile(filename: String): Unit = withFile(filename)(s => s.getLines.foreach(println))

printFile("/Users/MasatoraAtarashi/environment/study/Scala/scala_text/exercise/src/main/scala/exercise/Ex13-1.sc")
