package main

import (
	"fmt"

	"golang.org/x/tour/tree"
)

// Walk walks the tree t sending all values
// from the tree to the channel ch.
func Walk(t *tree.Tree) {
	if t.Left != nil {
		Walk(t.Left)
	}
	fmt.Println(t.Value)
	if t.Right != nil {
		Walk(t.Right)
	}
}

// Same determines whether the trees
// t1 and t2 contain the same values.
func Same(t1, t2 *tree.Tree) bool {
	return true
}

func main() {
	Walk(tree.New(1))
}
