trait Additive[A] {
  def plus(a: A, b: A): A
  def zero: A
}

case class Point(x: Int, y: Int)

object Point {
  implicit object PointAdditive extends Additive[Point] {
    def plus(a: Point, b: Point): Point = {
      if (a == zero) {
        b
      } else if (b == zero) {
        a
      } else {
        Point(a.x + b.x, a.y + b.y)
      }
    }

    def zero: Point = Point(0, 0)
  }
}

def sum[A](lst: List[A])(implicit m: Additive[A]) = lst.foldLeft(m.zero)((x, y) => m.plus(x, y))

sum(List(Point(0, 0), Point(2, 2)))
sum(List(Point(1, 1), Point(0, 0)))
sum(List(Point(1, 1), Point(2, 2)))
