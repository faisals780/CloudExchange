# SVG Practice Sheet — Rectangles, Squares & Circles

Every SVG starts the same way:

```html
<svg width="300" height="300" xmlns="http://www.w3.org/2000/svg">
  <!-- your shapes go here -->
</svg>
```

Write your code for each exercise below in a `.html` file and open it in your browser to check the result.

---

## Section 1 — Rectangles

**1.1** Draw a rectangle 150px wide, 80px tall, positioned at (20, 20), filled blue.

**1.2** Draw a rectangle 100px wide, 50px tall, with a red border (`stroke`) 3px thick and no fill (`fill="none"`).

**1.3** Draw a rectangle with rounded corners using `rx` and `ry` (try `rx="15"`).

---

## Section 2 — Squares

**2.1** Draw a square with side length 60px, filled green.

**2.2** Draw three squares of size 40px in a row, each 20px apart (hint: change the `x` value each time).

**2.3** Draw a square rotated 45° using the `transform="rotate(45, cx, cy)"` attribute.

---

## Section 3 — Circles

**3.1** Draw a circle with radius 50, centered at (100, 100), filled orange.

**3.2** Draw a circle with no fill and a black stroke 2px wide.

**3.3** Draw two overlapping circles with different `fill-opacity` values so you can see the overlap.

---

## Section 4 — Mix It Up

**4.1** Draw a simple "traffic light": one tall rounded rectangle (the box) with three circles inside (red, yellow, green) stacked vertically.

**4.2** Draw a smiley face:
- One big yellow circle (the face)
- Two small black circles (the eyes)
- One rectangle or curved shape for the mouth

**4.3** Draw a simple house:
- A square (the base)
- A rectangle (the door)
- Try adding a triangle using `<polygon>` for the roof (bonus — not covered yet, but give it a try!)

---

## Section 5 — Challenge

**5.1** Recreate this pattern: a 3×3 grid of circles, evenly spaced, alternating two colors.

**5.2** Draw a bullseye target using 4 concentric circles of alternating colors (largest to smallest).

---

### Quick Reference

| Shape | Tag | Key Attributes |
|---|---|---|
| Rectangle | `<rect>` | `x`, `y`, `width`, `height`, `rx`, `ry` |
| Circle | `<circle>` | `cx`, `cy`, `r` |
| Common to all | — | `fill`, `stroke`, `stroke-width`, `fill-opacity` |

Tip: `x`/`y` for `<rect>` is the **top-left corner**, but `cx`/`cy` for `<circle>` is the **center**. This trips up a lot of beginners!
