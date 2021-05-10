sealed abstract class Tree
case class Branch(value: Int, left: Tree, right: Tree) extends Tree
case object Empty extends Tree


val tree: Tree = Branch(1, Branch(2, Empty, Empty), Branch(3, Empty, Empty))
val tree2: Tree = Branch(3, Branch(4, Empty, Branch(5, Empty, Empty)), Branch(3, Empty, Empty))

// max
def max(tree: Tree): Int = tree match {
  case tree: Branch => List(tree.value, max(tree.left: Tree), max(tree.right: Tree)).max
  case _ => 0
}
max(tree)
max(tree2)

// min
def min(tree: Tree): Int = tree match {
  case tree: Branch => List(tree.value, min(tree.left: Tree), min(tree.right: Tree)).min
  case _ => 100000000
}
min(tree)
min(tree2)

// depth
def depth(tree: Tree): Int = tree match {
  case tree: Branch => 1 + List(depth(tree.left), depth(tree.right)).max
  case _ => 0
}
depth(Empty) == 0
depth(Branch(10, Empty, Empty)) == 1
depth(Branch(10, Branch(20,
  Empty,
  Empty
), Empty)) == 2
// 右のBranchの方が、左のBranchよりも深い
depth(Branch(10, Branch(20,
  Empty,
  Empty
), Branch(30,
  Branch(40,
    Empty,
    Empty
  ),
  Empty))) == 3
}
// sort
def sort(tree: Tree): Tree = tree match {
  case tree: Branch => {
    val l = tree.left match {
      case l: Branch => {
        val r = tree.right match {
          // B(B, B)
          case r: Branch => {
            val max = List(tree.value, l.value, r.value).max
            val min = List(tree.value, l.value, r.value).min
            val mid = List(tree.value, l.value, r.value).diff(List(max, min))(0)
            val new_l = Branch(value = min, left = l.left, right = l.right)
            val new_r = Branch(value = max, left = r.left, right = r.right)
            return Branch(value = mid, left = new_l, right = new_r)
          }
          // B(B,E)
          case _ => {
            val new_l = Branch(value = List(tree.value, l.value).min, left = l.left, right = l.right)
            return Branch(value = List(tree.value, l.value).max, left = new_l, right = Empty)
          }
        }
      }
      case _ => {
        val r = tree.right match {
          // B(E, B)
          case r: Branch => {
            val new_r = Branch(value = List(tree.value, r.value).max, left = r.left, right = r.right)
            return Branch(value = List(tree.value, r.value).min, left = Empty, right = new_r)
          }
          // B(E,E)
          case _ => return tree
        }
      }
    }
  }
  case _ => Empty
}
