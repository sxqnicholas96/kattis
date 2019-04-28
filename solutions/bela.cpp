#include <stdio.h>

int numtovalue(char);

int main(void){
    char trump,num,suit;
    int hands,i,score=0;
    
    scanf("%d %c ", &hands, &trump);
    
    for(i=0;i<hands*4;i++){
        scanf("%c %c ", &num, &suit);
        if(numtovalue(num) == 2 && suit == trump){
            score += 20;
        }
        else if(numtovalue(num) == 1){
            if(suit == trump){
                score +=14;
            }
        }
        else{
            score += numtovalue(num);
        }
        
    }
    printf("%d", score);
    return 0;
}

int numtovalue(char num){
    switch(num){
        case 'A':
        return 11;
        case 'K':
        return 4;
        case 'Q':
        return 3;
        case 'J':
        return 2;
        case 'T':
        return 10;
        case '9':
        return 1;
        default:
        return 0;
    }
}