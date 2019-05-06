1. In Designer, try to reproduce a layout of buttons resembling that in Figure 9.13.

2. The 15 puzzle (or n2–1 puzzle) involves an 4x4 (nxn) grid that contains 15 tiles numbered 1 to 15 (1 to n2–1), and one empty space. The only tiles that can move are those next to the empty space.
 * Create a 15 puzzle with QPushButtons in a QGridLayout.
 * At the start of the game, the tiles are presented to the player in "random" order. The object of the game is to rearrange them so that they are in ascending order, with the lowest numbered tile in the upper-left corner.
 * If the player solves the puzzle, pop up a QMessageBox saying "YOU WIN!" (or something more clever).
 * Add some buttons:

  * Shuffle – Randomize the tiles, by performing a large number (at least 50) of legal tile-slides.
  * Quit – Terminate the game.

![Fig. 9.13](https://www.ics.com/designpatterns/slides/src/puzzle/15-puzzle.png)

