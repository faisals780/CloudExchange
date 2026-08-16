# SVG Practice Sheet 2 — Lines, Polygons & Paths

You've got rect/circle down. This sheet covers the shapes that let you draw anything with straight edges or curves: `<line>`, `<polygon>`, `<polyline>`, and `<path>`.

---

## Section 1 — Lines

**1.1** Draw a single diagonal line from (20,20) to (200,150), black, 3px thick.

**1.2** Draw a horizontal "ruler" — 5 parallel vertical lines evenly spaced, all the same length.

**1.3** Draw an X shape using two crossing lines, each with a different color.

*Reference: `<line x1="" y1="" x2="" y2="" stroke="" stroke-width="" />` — no `fill` attribute, lines are stroke-only.*

---

## Section 2 — Polygons

**2.1** Draw a triangle using `<polygon points="x1,y1 x2,y2 x3,y3">`, filled orange.

**2.2** Draw a diamond (rotated square) using 4 points.

**2.3** Draw a five-pointed star using `<polygon>`. (Hint: it needs 10 points — alternating outer and inner radius points.)

**2.4** Draw a hexagon using 6 points, filled purple with a black stroke.

*Reference: `<polygon>` auto-closes the shape (connects the last point back to the first) and can be filled. `<polyline>` does NOT auto-close and is stroke-only — good for zigzags or open shapes like a mountain skyline.*

---

## Section 3 — Intro to Path

`<path>` is the most powerful shape — it can draw straight lines AND curves using a `d` attribute with commands:
- `M x,y` — move to (start point, no line drawn)
- `L x,y` — draw a straight line to this point
- `Q cx,cy x,y` — draw a curve using one control point (`cx,cy`) toward end point `x,y`
- `Z` — close the path (draw a line back to the start)

**3.1** Recreate a triangle using `<path>` instead of `<polygon>` — use `M`, `L`, `L`, `Z`.

**3.2** Draw one smooth curved line using `M` and `Q` — this is your first curve!

**3.3** Now go back and fix the smiley face from the last worksheet: replace the straight-line mouth with a curved smile using `<path d="M x,y Q x,y x,y">`.

---

## Section 4 — Combine Everything

**4.1** Draw a simple mountain range: use `<polyline>` for a jagged skyline (no fill, just an outline), then add a `<circle>` sun in the corner.

**4.2** Draw a speech bubble: a rounded `<rect>` with a small `<polygon>` triangle "tail" pointing out of one corner.

**4.3** Draw a simple arrow: a `<line>` for the shaft plus a `<polygon>` triangle for the arrowhead.

---

### Quick Reference

| Shape | Tag | Key Attributes | Closes automatically? |
|---|---|---|---|
| Line | `<line>` | `x1`, `y1`, `x2`, `y2` | — (never fillable) |
| Polyline | `<polyline>` | `points="x,y x,y ..."` | No |
| Polygon | `<polygon>` | `points="x,y x,y ..."` | Yes |
| Path | `<path>` | `d="M... L... Q... Z"` | Only with `Z` |

Tip: for `<path>`, whitespace and commas between numbers are interchangeable — `M 10,10 L 20,20` and `M10 10 L20 20` both work. Pick one style and stay consistent so your code stays readable.
