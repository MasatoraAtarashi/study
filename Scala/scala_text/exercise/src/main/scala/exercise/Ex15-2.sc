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
  case _ => 2^31-1
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

def toList(tree: Tree): List[Int] = tree match {
  case Empty => Nil
  case Branch(v, l, r) => toList(l) ++ List(v) ++ toList(r)
}

// sort
def sort(tree: Tree): Tree = {
  def fromList(list: List[Int]): Tree = {
    def insert(value: Int, tree: Tree): Tree = tree match {
      case Empty => Branch(value, Empty, Empty)
      case Branch(v, l, r) => {}
        if (value <= v) {
          Branch(v, insert(value, l), r)
        } else Branch(v, l, insert(value, r))
    }
    list.foldLeft(Empty:Tree)((t, v) => insert(v, t))
  }
  fromList(toList(tree))
}
sort(tree)
sort(tree2)
