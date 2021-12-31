# sm64-platform-max-tilt-brute-forcer
A tool for identifying valid position ranges for Mario to tilt the inverted pyramid platform to an upwarp-compatible normal.

A lot of this code came from previous brute forcers from folks like SpudY2K, AnthonyC4 and myself, as well as SM64 decomp.
I made changes to some files I copied over for this specific project.
Thanks to Modiseus and SpudY2K for the boundary distance logic. I made some edits there as well.

This tool is simple enough: given a starting platform normal, iterate over a range of starting Mario poaitions for 100 frames, and keep track of how close to the upwarp boundary Mario is able to tilt the normal to.
The best boundary distance (usually negative) is recorded for each starting position. Filtering only positive values for these will return the upwarp-compatible starting positions.
Values are returned in a csv for convenience.

Developed in VS 2019
