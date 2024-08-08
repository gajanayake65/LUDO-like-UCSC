#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct piece {
    int position;
    char group[8];
}; 

struct dice {
    int current_value;
    int past_value;
};

/// Dice roll function
int dice() {
    int min = 1;
    int max = 6;
    int out_dice_num = (rand() % (max - min + 1)) + min;
    return out_dice_num;
}

/// Define pieces
void piecedefine(struct piece *R1, struct piece *R2, struct piece *R3, struct piece *R4, 
                 struct piece *G1, struct piece *G2, struct piece *G3, struct piece *G4, 
                 struct piece *Y1, struct piece *Y2, struct piece *Y3, struct piece *Y4, 
                 struct piece *B1, struct piece *B2, struct piece *B3, struct piece *B4) {
    // Define red pieces
    R1->position = 0;
    strcpy(R1->group, "RED1");
    R2->position = 0;
    strcpy(R2->group, "RED2");
    R3->position = 0;
    strcpy(R3->group, "RED3");
    R4->position = 0;
    strcpy(R4->group, "RED4");
    // Define green pieces
    G1->position = 0;
    strcpy(G1->group, "GREEN1");
    G2->position = 0;
    strcpy(G2->group, "GREEN2");
    G3->position = 0;
    strcpy(G3->group, "GREEN3");
    G4->position = 0;
    strcpy(G4->group, "GREEN4");
    // Define yellow pieces
    Y1->position = 0;
    strcpy(Y1->group, "YELLOW1");
    Y2->position = 0;
    strcpy(Y2->group, "YELLOW2");
    Y3->position = 0;
    strcpy(Y3->group, "YELLOW3");
    Y4->position = 0;
    strcpy(Y4->group, "YELLOW4");
    // Define blue pieces
    B1->position = 0;
    strcpy(B1->group, "BLUE1");
    B2->position = 0;
    strcpy(B2->group, "BLUE2");
    B3->position = 0;
    strcpy(B3->group, "BLUE3");
    B4->position = 0;
    strcpy(B4->group, "BLUE4");
}
///index update
int update_index(int index){

}
/// Function to run the game cycle based on the starting player
int game_cycle(int (*game_start_ptr)()) {
    int index = game_start_ptr(),i=0;
    //printf("index: %d\n", index);
    while(i<10){
        switch(index){
        case 1:
            //
            printf("case 1 \n");
            index++;
            break;
        
        case 2: 
            //
            prinft("case 2 \n");
            index++;
            break;
        
        case 3:
            //
            printf("case 3\n");
            index++;
            break;
        
        case 4:
            //
            printf("case 4\n");
            index=index-3;
            break;
        
    
    }
    i++;
    }
    return index;
}

/// Determine who starts the game
int start_round() {
    int while_var = 0;
    int first_red, first_green, first_yellow, first_blue;
    
    do {
        first_red = dice();
        first_green = dice();
        first_yellow = dice();
        first_blue = dice();
        
        if (first_red == 6) {
            printf("RED has been got %d So, it is going to start game!\n", first_red);
            return 1;
        } else if (first_green == 6) {
            printf("GREEN has been got %d So, it is going to start game!\n", first_green);
            return 2;
        } else if (first_yellow == 6) {
            printf("YELLOW has been got %d So, it is going to start game!\n", first_yellow);
            return 3;
        } else if (first_blue == 6) {
            printf("BLUE has been got %d So, it is going to start game!\n", first_blue);
            return 4;
        }
    } while (while_var < 1);

    return 0; // Default return, though theoretically unreachable
}

int main() {
    struct piece R1, R2, R3, R4;
    struct piece G1, G2, G3, G4;
    struct piece Y1, Y2, Y3, Y4;
    struct piece B1, B2, B3, B4;

    /// Initialize the pieces
    piecedefine(&R1, &R2, &R3, &R4, &G1, &G2, &G3, &G4, &Y1, &Y2, &Y3, &Y4, &B1, &B2, &B3, &B4);
    srand(time(NULL));

    /// Check who starts the game
    int (*game_start_ptr)() = start_round;
    game_cycle(game_start_ptr);

    return 0;
}


int getNextIndex(int index){
    static int currIndex = -1;
    if(currIndex == -1) currIndex = index;
    return (++index)%4;
}

getNextIndex(3);
getNextIndex(1);
