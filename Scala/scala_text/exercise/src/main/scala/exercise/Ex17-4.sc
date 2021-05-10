//m: Additive[T]と値t1: T, t2: T, t3: Tは、次の条件を満たす必要があります。
//
//m.plus(m.zero, t1) == t1  // 単位元
//m.plus(t1, m.zero) == t1  // 単位元
//m.plus(t1, m.plus(t2, t3)) == m.plus(m.plus(t1, t2), t3) // 結合則
//このような条件を満たす型Tと単位元zero、演算plusを探し出し、Additive[T]を定義しましょう。この際、条件が満たされていることをいくつかの入力に対して確認してみましょう。また、定義したAdditive[T]をimplicitにして、Tの合計値を先ほどのsumで計算できることを確かめてみましょう。
//
//ヒント：このような条件を満たすものは無数にありますが、思いつかない人はたとえばx座標とy座標からなる点を表すクラスPointを考えてみると良いでしょう。

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
