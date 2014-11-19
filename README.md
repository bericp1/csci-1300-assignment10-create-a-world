# Create-A-World

Generate a world from its name and size. Every generation is deterministic based
on its name and size. All possible map tiles are stored in the `*_map_plots`
directory and the possible names in the `*_names` files.

## Running

A pre-built binary that should run in all 32-bit-capable linux can be found
nested in the `dest` directory.

## Building

To build from source, only C++11 and boost headers are required. To install
the boost header in the VM, run the following command:

    $ sudo apt-get install libboost-dev

    $ cd /wherever/you/extracted/me
    $ make

Then, a binary build is outputted nested in the `dist` directory

## Netbeans Project

You can also open this directory in netbeans with the C++ plugin installed to
build/run/debug

## Files

### The Map Plots

Each plot in a map consists of 32 ASCII characters in 4 rows of 8 characters
each. Generally, `*_map_plots` files are formatted so that every 4 lines starting
from the beginning is a separate plot.

#### Background Plots

**File:** `background_map_plots`

**Format:** regular

**Note:** The more often a specific tile appears in the file, the more likely it is
to be placed. This is not a very efficient means to weight certain background
tiles over others but it'll have to do since the original assignment is capped
at 200 lines.

#### Foreground Plots

**File:** `foreground_map_plots`

**Format:** 5 lines per plot; first line is the type of building, item, etc and
the next 4 are the actual plot's rows as normal.

**Note:** Each foreground plot has the same chance of being placed in a random
position on the map.

#### Character Plots

**File:** `character_map_plots`

**Format:** 5 lines per plot; first line is the activity conveyed by the plot's
character and the next 4 are the actual plot's rows as normal. This is a little
weird but it gives each character more diversity among generations and justify's
the existence of a separate subclass for this kind of map plot to meet the
assignment's requirements.

**Note:** Each character plot has the same chance of being placed in a random
position on the map and has a random name associated with it.

### Names

Possible first names are stored one on each line in `first_names`. Possible last
names are likewise stored in `last_names`.

## License

The MIT License (MIT)

Copyright (c) 2014 Brandon Eric Phillips

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.