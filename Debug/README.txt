********* README *********

SCOMPRESS - The General Purpose Compression Utility

3/23/2011
v 0.1 Alpha Release

This program is developed by Soham Chakraborty. The project started as a College Project but later
 became more important than that!!!!   :)
This Program uses Both RUN LENGTH ENCODING and LEMPEL-ZIV-WELCH Algorithms using BWT for General Purpose Text compressions
 .

There are certain Shortcomings in this Alpha release :

1) In LZW Compression scheme, NEWLINES can't be detected. I'm trying to figure that out on adding
 the detection, but for now try replacing NEWLINE with an underscore.

2) Also, in LZW the Data Structure defined by me uses unsigned characters to store new nodes.
 Hence a maximum of 256 nodes ( out of which only 100 can be actually accessed in this release dute to 2 digit int references used )can be stores in this release which restricts the maximum operable FILE
 SIZE.

3) The CHUNK Fragmentation service of Huge Files is dropped in this release for simplicity and testing purpose.
 I will be adding that in future releases.

4) In both LZW and RLE, numbers cannot be used. " Bummer " !!!!!
ALL of the above except no. 4 are applicable to LZW compression. The RLE is working as Expected.
Trying to find better ADT to represent the LZW dictionary.


thank you for trying this software.
Suggestions are always Welcomes!!!!!

- Soham Chakraborty
  computer enthusiast   :)