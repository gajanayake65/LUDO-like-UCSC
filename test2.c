#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX2(a, b) ((a) > (b) ? (a) : (b))
#define MAX4(a, b, c, d) (MAX2(MAX2(a, b), MAX2(c, d)))
//terminal colours
#define Red "\033[31m" 
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define RESET "\033[0m"

struct piece {
    short int position;
    short int group;
    short int p_index;
    short int is_board;  
}; 

// Declare the global array
struct piece p_piece[16];

int currIndex = -1;

int getNextIndex() {
    return (++currIndex) % 4;
}

/// Dice roll function
int dice() {
    short int min = 1;
    short int max = 6;
    return (rand() % (max - min + 1)) + min;
}

/// Moves a piece by a random number of steps
int move_step() {
    return dice();
}

/// Define pieces
void piecedefine(struct piece *p_piece) {
    for(int i = 0; i < 16; i++) {
                 
        p_piece[i].group = i/4 ;            
        p_piece[i].is_board = 0;
        p_piece[i].p_index = i % 4 + 1;
        p_piece[i].position = 0;            
}
}

/// Determine who starts the game
int start_round(struct piece *p_piece) {
    while (1) {
        int first_red = dice();
        int first_green = dice();
        int first_yellow = dice();
        int first_blue = dice();

        if (first_red == 6) {
            printf(Red"RED got %d, so it is going to start the game!\n"RESET, first_red);
            p_piece[0].position = 1;
            p_piece[0].is_board = 1;
            printf("Live Position: %d\n\n", p_piece[0].position);
            return 0;
        } else if (first_green == 6) {
            printf(Green"GREEN got %d, so it is going to start the game!\n"RESET, first_green);
            p_piece[4].position = 14;
            p_piece[4].is_board = 1;
            printf("Live Position: %d\n", p_piece[4].position);
            return 1;
        } else if (first_yellow == 6) {
            printf(Yellow"YELLOW got %d, so it is going to start the game!\n"RESET, first_yellow);
            p_piece[8].position = 27;
            p_piece[8].is_board = 1;
            printf("Live Position: %d\n\n", p_piece[8].position);
            return 2;
        } else if (first_blue == 6) {
            printf(Blue"BLUE got %d, so it is going to start the game!\n"RESET, first_blue);
            p_piece[12].position = 40;
            p_piece[12].is_board = 1;
            printf("Live Position: %d\n\n", p_piece[12].position);
            return 3;
        }
    }
}
short int give_dice_value() {
    short int dice_tep = move_step();
    if (dice_tep == 6) {
        dice_tep += move_step();
        if (dice_tep == 12) {
            short int dice_tep2 = move_step();
            dice_tep += (dice_tep2 == 6) ? 0 : dice_tep2;
        }
    }
    return dice_tep;
}
////win model design
void control_win(struct piece *p_piece,short int group){
        for(short int k=group*4;k<(group*4)+4;k++){
      //  printf("test\n\n");
        if (group==0){
            if(45<=p_piece[k].position<=51){
                short int tep_position;
                
            }
        //    printf("\ntest2\n\n");
            p_piece[k].position=p_piece[k].position-52;
        }
            }
}
//my converter is special desing for me
void my_convertor(struct piece *p_piece,short int group){
    for(short int k=group*4;k<(group*4)+4;k++){
      //  printf("test\n\n");
        if (p_piece[k].position>=53){
        //    printf("\ntest2\n\n");
            p_piece[k].position=p_piece[k].position-52;
        }
            }
}
///in this above function include (cutting ,of update position)
short int set_of_operations(struct piece *p_piece, short int group) {
    short int dice_tep=give_dice_value();
    //printf("group;---%d \t dice:-%d\n",group,dice_tep); //................................................................edit
    for (short int i = group * 4; i < (group * 4) + 4; i++) {
        if (p_piece[i].is_board == 1) {
            for (short int j = 0; j < 16; j++) {
                if (dice_tep == (p_piece[j].position*p_piece[j].is_board - p_piece[i].position)) {                    ///////////////////////changed
                    if (p_piece[i].group != p_piece[j].group && p_piece[j].is_board) {
                        p_piece[i].position += dice_tep;
                        my_convertor(p_piece,group);
                        p_piece[j].position = 0;
                        p_piece[j].is_board = 0;
                        printf("\t\t>>>%s (%d) piece ate %d group item...\n", (group == 0) ? "RED" : (group == 1) ? "GREEN" : (group == 2) ? "YELLOW" : "BLUE", p_piece[i].p_index, p_piece[j].group);
                        printf("\t\t>>>New Position of %s (%d) is: %d\n", (group == 0) ? "RED" : (group == 1) ? "GREEN" : (group == 2) ? "YELLOW" : "BLUE", p_piece[i].p_index, p_piece[i].position);
                        printf("\t\t>>>%s (%d) piece sent to base\n", (group ==0) ? "RED" : (group == 1) ? "GREEN" : (group == 2) ? "YELLOW" : "BLUE", p_piece[j].p_index);
                        return 0;
                    }
                }
                else if(dice_tep != (p_piece[j].position - p_piece[i].position) && dice_tep==6){
                    printf("<<<There is no some one to cut\n");//.................................................edit
                                                            for (short int k=group*4;k<(group*4)+4;k++){
                                            if (p_piece[k].is_board==0){
                                                p_piece[k].is_board=1;
                                                printf("\t\t>>>%s (%d) is on the ground Now!!\n",(group == 0) ? "RED" : (group == 1) ? "GREEN" : (group == 2) ? "YELLOW" : "BLUE",p_piece[k].p_index);
                                                p_piece[k].position=(group == 0) ? 1 : (group == 1) ? 14 : (group == 2) ? 27 : 40 ;////////////////////////////////////red start position
                                                printf("\t\t>>>Position of %s (%d)  --> %d \n",(group == 0) ? "RED" : (group == 1) ? "GREEN" : (group == 2) ? "YELLOW" : "BLUE",p_piece[k].p_index,p_piece[k].position);
                                                return 0;///////////////////////////////////////////////errro
                                            }
                                           // break;
                                        }
                                           // break;
                                    }
                                    
                                                                 
                else{
                    printf("Chance to move piece\n");//..........................................................................edit
                    int max_value = MAX4 (p_piece[(group*4)].position,p_piece[(group*4)+1].position,p_piece[(group*4)+2].position,p_piece[(group*4)+3].position);
                    //printf("max:- %d\n",max_value);//........................................edit
                    if (max_value==p_piece[(group*4)].position){
                        p_piece[(group*4)].position+=p_piece[(group*4)].is_board*dice_tep;
                        my_convertor(p_piece,group);
                        printf("\t\t>>>Position of %s (%d) --> %d\n",(group == 0) ? "RED" : (group == 1) ? "GREEN" : (group == 2) ? "YELLOW" : "BLUE",p_piece[(group*4)].p_index,p_piece[(group*4)].position);
                    }
                    if (max_value==p_piece[(group*4)+1].position){
                        p_piece[(group*4)+1].position+=p_piece[(group*4)+1].is_board*dice_tep;
                        my_convertor(p_piece,group);
                        printf("\t\t>>>Position of %s (%d) --> \n",(group == 0) ? "RED" : (group == 1) ? "GREEN" : (group == 2) ? "YELLOW" : "BLUE",p_piece[(group*4)+1].p_index,p_piece[(group*4)+1].position);
                    }
                    if (max_value==p_piece[(group*4)+2].position){
                        p_piece[(group*4)+2].position+=p_piece[(group*4)+2].is_board*dice_tep;
                        my_convertor(p_piece,group);
                        printf("\t\t>>>Position of %s (%d) --> \n",(group == 0) ? "RED" : (group == 1) ? "GREEN" : (group == 2) ? "YELLOW" : "BLUE",p_piece[(group*4)+2].p_index,p_piece[(group*4)+2].position);
                    }
                    if (max_value==p_piece[(group*4)+3].position){
                        p_piece[(group*4)+3].position+=p_piece[(group*4)+3].is_board*dice_tep;
                        my_convertor(p_piece,group);
                        printf("\t\t>>>Position of %s (%d) --> \n",(group == 0) ? "RED" : (group == 1) ? "GREEN": (group == 2) ? "YELLOW" : "BLUE",p_piece[(group*4)+3].p_index,p_piece[(group*4)+3].position);
                    }
                    return 0;
                
            }
        }
    }}

    return 0;
}
/// Function to run the game cycle based on the starting player
void game_cycle(struct piece *p_piece) {
    printf("_____________________________LET'S START GAME_______________________________\n");
    int i = 0;
    while (i<20) {
        int nIndex = getNextIndex();
        switch (nIndex) {
            case 0:
            printf(Red"\t\t\t>>>Chance of RED colour player<<<\n\n"RESET);
                if (p_piece[0].is_board == 1 || p_piece[1].is_board == 1 || p_piece[2].is_board == 1 || p_piece[3].is_board == 1) {
                    // printf("Case 0: Move step = %d\n", dice());
                    int group=0;
                  //  my_convertor(p_piece,group);
                    set_of_operations(p_piece,group);
                    printf("\t\t\t>>>Give Next Chance to GREEN Player<<<\n\n");
                } else {
                   // printf("call return dice red\n");//.........................................edit
                    int tep_roll = dice();
                    printf("Roll for Enter to Ground:%d\n",tep_roll);//.........................................edit
                    if (tep_roll == 6) {
                        p_piece[0].position = 1;
                        p_piece[0].is_board = 1;
                        printf("RED (%d) is entering the game!\n", p_piece[0].p_index);
                        printf("Position of RED (%d) --> %d \n\t\t\t>>>Give Next Chance to GREEN Player<<<\n\n", p_piece[0].p_index, p_piece[0].position);
                    }
                }
                break;
            case 1:
                    printf(Green"\t\t\t>>>Chance of GREEN colour player<<<\n\n"RESET);//...............................................edit
                if (p_piece[4].is_board == 1 || p_piece[5].is_board == 1 || p_piece[6].is_board == 1 || p_piece[7].is_board == 1) {
                    //printf("Case 1: Move step = %d\n", dice());
                    short int  group=1;
               //// my_convertor(p_piece,group);
                   set_of_operations(p_piece,group);
                    printf("\t\t\t>>>Give Next Chance to YELLOW Player<<<\n\n");
                } else {
                    // printf("call return dice green\n");//.........................................edit
                    int tep_roll = dice();
                    printf("Roll for Enter to Ground:%d\n",tep_roll);//.........................................edit
                    if (tep_roll == 6) {
                        p_piece[4].position = 14;/// end 14+51
                        p_piece[4].is_board = 1;
                        printf("GREEN (%d) is entering the game!\n", p_piece[4].p_index);
                        printf("Position of GREEN (%d) --> %d \n\t\t\t>>>Give Next Chance to YELLOW Player<<<\n\n", p_piece[4].p_index, p_piece[4].position);
                    }
                }
                break;
            case 2:
            printf(Yellow"\t\t\t>>>Chance of YELLOW colour player\n\n"RESET);//...................................................................edit
                if (p_piece[8].is_board == 1 || p_piece[9].is_board == 1 || p_piece[10].is_board == 1 || p_piece[11].is_board == 1) {
                   // printf("Case 2: Move step = %d\n", dice());
                   int group=2;
                  // my_convertor(p_piece,group);
                   set_of_operations(p_piece,group);
                   printf("\t\t\t>>>Give Next Chance to BLUE Player<<<\n\n");
                } else {
                   // printf("call return dice yellow\n");//.........................................edit
                    int tep_roll = dice();
                    printf("Roll for Enter to Ground:%d\n",tep_roll);//.........................................edit
                       if (tep_roll == 6) {
                        p_piece[8].position = 27;///end 27=51
                        p_piece[8].is_board = 1;
                        printf("YELLOW (%d) is entering the game!\n", p_piece[8].p_index);
                        printf("Position of YELLOW (%d) --> %d \n\t\t\t>>>Give Next Chance to BLUE Player<<<\n\n", p_piece[8].p_index, p_piece[8].position);
                    }
                }
                break;
            case 3:
            printf(Blue"\t\t\t>>>Chance of BLUE colour player\n\n"RESET);//.........................................................................edit
                if (p_piece[12].is_board == 1 || p_piece[13].is_board == 1 || p_piece[14].is_board == 1 || p_piece[15].is_board == 1) {
                    // printf("Case 3: Move step = %d\n", dice());
                    int group=3;
                  //  my_convertor(p_piece,group);
                   set_of_operations(p_piece,group);
                   printf("\t\t\t>>>Give Next Chance to RED Player<<<\n\n");
                } else {
                     //printf("call return dice blue\n");//.........................................edit
                    int tep_roll = dice();
                     printf("Roll for Enter to Ground:%d\n",tep_roll);//.........................................edit
                    if (tep_roll == 6) {
                        p_piece[12].position = 40;/// end  40+51
                        p_piece[12].is_board = 1;
                        printf("BLUE (%d) is entering the game!\n", p_piece[12].p_index);
                        printf("Position of BLUE (%d) --> %d \n\t\t\t>>>Give Next Chance to RED Player<<<\n\n", p_piece[12].p_index, p_piece[12].position);
                    }
                }
                break;
        }
        i++;
    }
}



int main() {
    /// Initialize the pieces
    piecedefine(p_piece);
    srand(time(NULL));
    /// Check who starts the game
    currIndex = start_round(p_piece);
    game_cycle(p_piece);
    return 0;
}

