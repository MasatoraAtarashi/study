def swapArray[T] (arr: Array[T])(i: Int, j: Int): Unit = {
  val tmp = arr(j)
  arr(j) = arr(i)
  arr(i) = tmp
}

val arr = Array(1, 2, 3, 4, 5)
// arr: Array[Int] = Array(5, 4, 3, 2, 1)

swapArray(arr)(0, 4)

arr
// res5: Array[Int] = Array(5, 4, 3, 2, 1)

swapArray(arr)(1, 3)

arr
// res7: Array[Int] = Array(5, 4, 3, 2, 1)
