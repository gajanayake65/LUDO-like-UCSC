#include<stdio.h>
int pop(int array[]){
    int y=array[0];
    for(int i=0;i<10;i++){
        array[i]=array[i+1];

    }
    }
    return y;
}

void move_red(int arr1[], int size, int *red_live_point)
{
    int current_value = arr1[*red_live_point];
    int next_position = dice() + *red_live_point;
    printf("next:%d\n", next_position);
    arr1[*red_live_point] = 0;
    arr1[next_position] = current_value;
    *red_live_point = next_position;
}

void main()
{
    srand(time(NULL));
    int red_live_point = 0;
    int red[4] = {1, 1, 1, 1};
    int path[52] = {0};
    printf("%d\n", pop(red, 4));
    path[0] = pop(red, 4);
    for (int h = 0; h < 4; h++)
    {
        move_red(path, 52, &red_live_point);
        for (int i = 0; i < 52; i++)
        {
            printf("%d\t", path[i]);
        }
        printf("\n");
    }
}
