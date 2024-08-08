#include<stdio.h>
int j=0,v;
int jump(int j){
    printf("Jump step: \n");
    scanf("%d",&j);
    v=j;
    return j;
}
struct color_array{
    char c;
    int i;};

void main (){
    struct color_array red[5],green[5],blue[5],yellow[5];

    red [0].c='R';
    red [1].i=1;
    red [2].i=1;
    red [3].i=1;
    red [4].i=1;

    green [0].c='G';
    green [1].i=1;
    green [2].i=1;
    green [3].i=1;
    green [4].i=1;

    blue [0].c='B';
    blue [1].i=1;
    blue [2].i=1;
    blue [3].i=1;
    blue [4].i=1;

    yellow [0].c='Y';
    yellow [1].i=1;
    yellow [2].i=1;
    yellow [3].i=1;
    yellow [4].i=1;

///full array
int full[52];
/// for red
full[0]=red[1].i;
red[1].i=0;
//jump function
for (int t=0;t<5;t++){
int targetposition_1=j+jump(j);
full[targetposition_1]=1;
int uvalue= targetposition_1-v;
full[uvalue]=0;
for (int i=0;i<52;i++){
    printf("%d\t",full[i]);
}
}
}