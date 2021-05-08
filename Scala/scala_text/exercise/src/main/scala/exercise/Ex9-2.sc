abstract class Shape {
  def area: Double
}
/*
 * RectangleとCircleの定義
 */

class Rectangle(val width: Double, val height: Double) extends Shape {
  override def area: Double = width * height
}

class Circle(val radius: Double) extends Shape {
  override def area: Double = radius * radius * math.Pi
}

var shape: Shape = new Rectangle(10.0, 20.0)
println(shape.area)
shape = new Circle(2.0)
println(shape.area)
