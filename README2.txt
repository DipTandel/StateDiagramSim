Dip Tandel's State Machine:

Works perfectly except inputs have to be specific:
start code by writing simState in terminal;
If you want to change states you must write 'c' on its own first, <nextInt> <nextState>. You may also type 'c' <nextInt> <nextState> in a single line.
the program can run into errors if anything else is done such as typing 'c1a',
If you want to print just write 'p'.
If you want to go to nextState write 0 or 1.
the ideal execution would be:
c
1
A
.Keeping in mind to not use caps for p, c, d, or g, but indeed using caps for state names.

Also if you delete the garbage states and then try to change the next state to a deleted state, it will change to NULL and therefore soft-break the program.

