# Converting from a text file into a `PDF`

If you want to visualize a maze, you can convert the raw text file into a PDF.  This will be useful to visualize what your program is doing.  The script `draw-grid.py` can do this conversion for you.  

``` {code-block} py
############################################
# file: draw-grid.py
# to use: copy code and paste as python file
############################################

import sys
import numpy as np
from PIL import Image, ImageDraw

def draw_grid(fname, max_w):
    grid = np.loadtxt(fname, dtype=int)
    w, h = max_w, int(max_w/(grid.shape[1]/grid.shape[0]))
    cols = np.linspace(0, w-1, grid.shape[1]+1)
    rows = np.linspace(0, h-1, grid.shape[0]+1)
    img = Image.new('L', size=(w,h), color=255)
    draw = ImageDraw.Draw(img)
    for i in range(grid.shape[0]):
        for j in range(grid.shape[1]):
            draw_box(cols[j], rows[i], cols[j+1], rows[i+1], grid[i,j], draw)
    img.save(fname+'.pdf')

def draw_box(x1, y1, x2, y2, val, draw):    
    if val & 8: # NORTH
        draw.line([(x1,y1),(x2,y1)], fill=0)
    if val & 4: # SOUTH
        draw.line([(x1,y2),(x2,y2)], fill=0)
    if val & 2: # EAST
        draw.line([(x2,y1),(x2,y2)], fill=0)
    if val & 1: # WEST
        draw.line([(x1,y1),(x1,y2)], fill=0)

if __name__ == "__main__":
    draw_grid(sys.argv[1], 400)
```

In the example below, the script will automatically convert `test.txt` into `test.txt.pdf`.  You can specify any file name and the extension `.pdf` will be automatically added to the output file.

```bash
$ python3 draw-grid.py test.txt
```

After running the command above you can now open `test.txt.pdf` and visualize the image.

## Using the scripts inside CS50 IDE

CS50 IDE comes with a pre-installed version of `python`.  However a few steps are necessary to install the libraries used by the scripts explained above.  **This is a one-time setup**.  Type the commands below in the terminal window and you should be all set.

```bash
$ pip3 install --upgrade pip
$ pip3 install numpy
$ pip3 install Pillow
```
