#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Dip Tandel"s State Machine

int main(int argc, char * argv[])
{
    char states[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char nextStates[2][8] = { {states[4], states[2], states[5], states[0], states[7], states[3], states[1], states[6]},
                               {states[3], states[4], states[0], states[7], states[2], states[1], states[5], states[7]} 
                            };
    /*
    char[][] states = { {"A", "B", "C", "D", "E", "F", "G", "H"},
                        {"E", "C", "F", "A", "H", "D", "B", "G"},
                        {"D", "E", "A", "H", "C", "B", "F", "H"} };
    */
    
    /*format: nextStates[0][x] results in state from state "x" after pressing 0
              nextStates[1][x] results in state from state "x" after pressing 1 */


    int presentIndex = 4;
    char currentState = states[presentIndex];
    fprintf(stdout, "The current state is %c\n", currentState);

    char garb[8];

    int cont = 1;
    while(cont == 1) {
        char in1;
        int in2;
        char in3;
        
        //read inputs continuously
        scanf(" %c", &in1);
        if (in1 == 'c') {
            //change state command initiated by 'c'
            //fprintf(stderr, "Now Enter: <nextInt> <nextState>\n");
            scanf(" %d %c", &in2, &in3);
            if ((in2 == 0 || in2 == 1) && (in3 == 'A' || in3 == 'B' || in3 == 'C' || in3 == 'D' || in3 == 'E' || in3 == 'F' || in3 == 'G' || in3 == 'H')) {
                //ascii int values of "A" and beyond start at 65
                int ascii = in3;
                nextStates[in2][presentIndex] = states[ascii-65];
                fprintf(stdout, "changed next state %d from %c to %c\n", in2, currentState, nextStates[in2][presentIndex]);
            }
            else {
                fprintf(stdout, "incorrect command input, please only use uppercase letters for states\nHold ctrl and press c to end program. Read README for more.\n");
                continue;
            }
        }
        else if (in1 == '0' || in1 == '1') {
            //just "0" or "1" must print to stdout the name of the next state given the supplied input, and update the current state
            int input = atoi(&in1);//convert to int
            currentState = nextStates[input][presentIndex];
            int ascii = currentState;
            presentIndex = ascii-65;
            fprintf(stdout, "The current state is now %c\n", currentState);
        }
        else if (in1 == 'p') {
            //prints the machine
            for (int i = 0; i < 8; i++) {
                fprintf(stdout, "%c  %c  %c\n", states[i], nextStates[0][i], nextStates[1][i]); 
            }
        }
        else if (in1 == 'g') {
            //garbage detect
            garb[0] = 'A'; garb[1] = 'B'; garb[2] = 'C'; garb[3] = 'D'; garb[4] = 'E'; garb[5] = 'F'; garb[6] = 'G'; garb[7] = 'H';
            int save = presentIndex;
            for (int k = 0; k < 2; k++) {
                for (int i = 0; i < 8; i++) {
                    if (nextStates[k][presentIndex] != NULL) {
                        currentState = nextStates[0][presentIndex];
                        int ascii = currentState;
                        presentIndex = ascii-65;
                        for (int j = 0; j < 8; j++) {
                            if (garb[j] == currentState) {
                                garb[j] = NULL;
                                }
                        }
                    }
                }
            }
            if (strlen(garb) == 0) {
                fprintf(stdout, "No garbage\n");
            }
            else {
                fprintf(stdout, "Garbage: ");
                for (int l = 0; l < 8; l++) {
                    fprintf(stdout, "%c ", garb[l]);
                }
                fprintf(stdout, "\n");
            }
        }
        else if (in1 == 'd') {
            //delete garbage
            if (strlen(garb) == 0) {
                fprintf(stdout, "No garbage to delete\n");
            }
            else {
                fprintf(stdout, "Deleted: ");
                for (int l = 0; l < 8; l++) {
                    fprintf(stdout, "%c ", garb[l]);
                    char del = garb[l];
                    int key = del;
                    key = key-65;
                    states[key] = NULL;
                    nextStates[0][key] = NULL;
                    nextStates[1][key] = NULL;
                }
                fprintf(stdout, "\n");
            }
        }
        //error commands
        else {
            fprintf(stdout, "incorrect command input, please only use uppercase letters for states\nHold ctrl and press c to end program. Read README for more.\n");
            continue;
        }
        
    }
    exit(0);
}

