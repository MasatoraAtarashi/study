abstract class Shape {
  def area: Double
}
/*
 * RectangleとCircleの定義
 */

class Rectangle(val w: Double, val h: Double) extends Shape {
  override def area: Double = {
    w * h
  }
}

class Circle(val r: Double) extends Shape {
  override def area: Double = {
    r * r * math.Pi
  }
}

var shape: Shape = new Rectangle(10.0, 20.0)
println(shape.area)
shape = new Circle(2.0)
println(shape.area)
