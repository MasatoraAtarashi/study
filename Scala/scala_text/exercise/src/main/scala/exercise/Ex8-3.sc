import scala.math.pow
for(a <- 1 to 1000; b <- 1 to 1000; c <- 1 to 1000 if pow(a, 2.0) == pow(b, 2.0) + pow(c, 2.0)){
  println("a: " + a + " b: " + b + " c: " + c)
}
