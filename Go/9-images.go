package main

import (
	"image"
	"image/color"

	"golang.org/x/tour/pic"
)

type Image struct{}

func (img Image) Bounds() image.Rectangle {
	w, h := 300, 300
	rec := image.Rect(0, 0, w, h)
	return rec
}

func (img Image) ColorModel() color.Model {
	return color.RGBA64Model
}

func (img Image) At(x, y int) color.Color {
	v := uint8(x * y)
	return color.RGBA{v, v, 255, 255}
}

func main() {
	m := Image{}
	pic.ShowImage(m)
}
