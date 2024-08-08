#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <time.h>

struct piece {
    short int position;
    short int group;
    short int p_index;
    short int is_board;  
}; 

int currIndex = -1;
int getNextIndex(){
   // currIndex = currIndex +1;
    return (++currIndex)%4;
}

struct dice {
    short current_value;
    //int past_value;
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
    strcpy(R1->group, "RED1");

    struct piece *p_piece[16] = {
        R1 , G1 , Y1 , B1, 
        R2 , G2 , Y2 , B2, 
        R3 , G3 , Y3 , B3,             
        R4 , G4 , Y4 , B4, 
    };
    for(int i = 0 ; i < 16 ; i++){            
        p_piece[i]->group = i%4;            
        p_piece[i]->is_board = 0;
        p_piece[i]->p_index = i%4;
        p_piece[i]->position = 0;            

    }
}
///index update
int update_index(int index){

}
/// Function to run the game cycle based on the starting player
void game_cycle() {
    // int index = game_start_ptr(),
    int i=0;
    //printf("index: %d\n", index);
    while(i<10){
        int nIndex = getNextIndex();
        switch(nIndex){
            case 0: //call func
                printf("case 0\n");
                break;
            case 1: //call func
                printf("case 1\n");
                break;
            case 2: //call func/////////////////////////////////////can be replace from single function
                printf("case 2\n");
                break;
            case 3: //call func
                printf("case 3\n");
                break;
        }
    i++;
    }
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
        
        int fristPlayerIndex = -1;
        if (first_red == 6) {
            printf("RED has been got %d So, it is going to start game!\n", first_red);
            fristPlayerIndex = 0;
            
        } else if (first_green == 6) {
            printf("GREEN has been got %d So, it is going to start game!\n", first_green);
            fristPlayerIndex = 1;
        
        } else if (first_yellow == 6) {
            printf("YELLOW has been got %d So, it is going to start game!\n", first_yellow);
            fristPlayerIndex = 2;
            
        } else if (first_blue == 6) {
            printf("BLUE has been got %d So, it is going to start game!\n", first_blue);
            fristPlayerIndex = 3;
            
        }
        //update group Piece
        //...
        //...
        return fristPlayerIndex;

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
    currIndex = start_round();
    game_cycle();

    return 0;
}



