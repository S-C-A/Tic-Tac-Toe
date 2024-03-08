#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void human(int[][3], char[][3]);
void computer_easy(int[][3], char[][3]);
void computer_hard(int[][3], char[][3]);
void print_screen(int[][3], char[][3]);
int check_result(int[][3], int, int);
int row_cross(int[][3]);
int column_cross(int[][3]);
int diagonal_cross(int[][3]);
void move(int[][3], char[][3], int);
void com_easy_move(int[][3], char[][3]);
void com_hard_move(int[][3], char[][3]);
int row_double(int[][3], char[][3]);
int column_double(int[][3], char[][3]);
int diagonal_double(int[][3], char[][3]);


int main(){

    srand(time(NULL));
    int background[3][3] = {0};
    char game_screen[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int game_mode, difficulty;

    printf("Press 1 to play against a human\nPress 2 to play against the computer\nYour Choice: ");
    scanf("%d", &game_mode);

    if (game_mode == 2)
    {
        printf("Press 1 for easy mode \nPress 2 for hard mode\nYour Choice: ");
        scanf("%d", &difficulty);
    }

    if (game_mode == 1)
    {
        human(background,game_screen);
    }
    else if (difficulty == 1)
    {
        computer_easy(background,game_screen);
    }
    else if (difficulty == 2)
    {
        computer_hard(background,game_screen);
    }
       
}

void human(int background[][3], char game_screen[][3]){

    static int turn = 2;
    print_screen(background, game_screen);
    if (check_result(background,turn,0) == 1)
    {
        return;
    }
    move(background, game_screen, turn);
    turn++;
    human(background, game_screen);
}

void computer_easy(int background[][3], char game_screen[][3]){

    static int turn = 2;
    print_screen(background, game_screen);
    if (check_result(background, turn, turn%2 == 0? 0 : 1) == 1)
    {
        return;
    }
    if (turn%2 == 0)
    {
        move(background, game_screen, turn);
    }
    else if (turn%2 == 1)
    {
        com_easy_move(background, game_screen);
    }
    turn++;
    computer_easy(background, game_screen);

}

void computer_hard(int background[][3], char game_screen[][3]){

    static int turn = 2;
    print_screen(background, game_screen);
    if (check_result(background, turn, turn%2 == 0? 0 : 1) == 1)
    {
        return;
    }
    if (turn%2 == 0)
    {
        move(background, game_screen, turn);
    }
    else if (turn%2 == 1)
    {
        com_hard_move(background, game_screen);
    }
    turn++;
    computer_hard(background, game_screen);

}

void print_screen(int background[][3], char game_screen[][3]){
     
    printf("\n\t   %c   |   %c   |  %c  \n", game_screen[0][0], game_screen[0][1], game_screen[0][2]);
    printf("\t-----------------------\n");
    printf("\t   %c   |   %c   |  %c  \n", game_screen[1][0], game_screen[1][1], game_screen[1][2]);
    printf("\t-----------------------\n");
    printf("\t   %c   |   %c   |  %c  \n", game_screen[2][0], game_screen[2][1], game_screen[2][2]);
  
    return;    
}

int check_result(int background[][3], int turn, int player){

    if (row_cross(background) == 1)
    {
        if(player == 1)
        {
            printf("PLAYER %d WON!!", (turn-1)%2+1);
        }
        else if (player == 0)
        {
            printf("THE COMPUTER WON!!");
        }        
        return 1;
    }
    else if (column_cross(background) == 1)
    {
        if(player == 1)
        {
            printf("PLAYER %d WON!!", (turn-1)%2+1);
        }
        else if (player == 0)
        {
            printf("THE COMPUTER WON!!");
        }        
        return 1;
    }
    else if(diagonal_cross(background) == 1)
    {
        if(player == 1)
        {
            printf("PLAYER %d WON!!", (turn-1)%2+1);
        }
        else if (player == 0)
        {
            printf("THE COMPUTER WON!!");
        }        
        return 1;
    }    
    else if (turn == 11)
    {
        printf("DRAW!");
        return 1;
    }
    else
    {
        return 0;
    }
}

int row_cross(int background[][3]){

    for (int i = 0; i < 3; i++)
    {
        if (background[i][0] == background[i][1] &&
            background[i][1] == background[i][2] &&
            background[i][0] != 0)
        {
            return 1;
        }    
    }
    return 0;
}

int column_cross(int background[][3]){

    for (int i = 0; i < 3; i++)
    {
        if (background[0][i] == background[1][i] &&
            background[1][i] == background[2][i] &&
            background[0][i] != 0)
        {
            return 1;
        }    
    }
    return 0;
}

int diagonal_cross(int background[][3]){

    if (background[0][0] == background[1][1] &&
        background[1][1] == background[2][2] && 
        background[0][0] != 0)
    {
        return 1;
    }         
    if (background[0][2] == background[1][1] &&
        background[1][1] == background[2][0] &&
        background[0][2] != 0)
    {
        return 1;
    }
    return 0;
}

void move(int background[][3], char game_screen[][3], int turn){

    int  row=0, column=0;
    do
    {
        printf("The %dth players move:",turn%2+1);
        scanf("%d %d", &row, &column);
        row -= 1;
        column -= 1;
        if (background[row][column] == 0)
        {
            background[row][column] = turn%2+1 == 1? 1 : -1;
            game_screen[row][column] = turn%2+1 == 1? '0' : 'X';
            return;
        }
        print_screen(background, game_screen);
        printf("That spot is taken!\n");
    } while (1);
}

void com_easy_move(int background[][3], char game_screen[][3]){
   
    int  row=0, column=0;
    do
    {
        row = rand() % 3;
        column = rand() % 3;
        if (background[row][column] == 0)
        {
            background[row][column] = -1;
            game_screen[row][column] = 'X';
            return;
        }
    } while (1);
}

void com_hard_move(int background[][3], char game_screen[][3]){
   
    int  row=0, column=0;
    if (background[1][1] == 0)
    {
            background[1][1] = -1;
            game_screen[1][1] = 'X';
            return;
    }    
    if (row_double(background, game_screen) == 1)
    {
        return;
    }
    if (diagonal_double(background, game_screen) == 1)
    {
        return;
    }    
    if (column_double(background, game_screen) == 1)
    {
        return;
    }    
    do
    {
        row = rand() % 3;
        column = rand() % 3;
        if (background[row][column] == 0)
        {
            background[row][column] = -1;
            game_screen[row][column] = 'X';
            return;
        }
    } while (1);
}

int row_double(int background[][3], char game_screen[][3]){

    for (int i = 0; i < 3; i++)
    {
        if (background[i][0] == -1 && background[i][1] == -1 && background[i][2] == 0)
        {
            background[i][2] = -1;
            game_screen[i][2] = 'X'; 
            return 1;
        }
        else if (background[i][0] == -1 && background[i][2] == -1 && background[i][1] == 0)
        {
            background[i][1] = -1;
            game_screen[i][1] = 'X'; 
            return 1;
        }        
        else if (background[i][1] == -1 && background[i][2] == -1 && background[i][0] == 0)
        {
            background[i][0] = -1;
            game_screen[i][0] = 'X'; 
            return 1;
        }                
    }
    for (int i = 0; i < 3; i++)
    {
        if (background[i][0] == 1 && background[i][1] == 1 && background[i][2] == 0)
        {
            background[i][2] = -1;
            game_screen[i][2] = 'X'; 
            return 1;
        }
        else if (background[i][0] == 1 && background[i][2] == 1 && background[i][1] == 0)
        {
            background[i][1] = -1;
            game_screen[i][1] = 'X'; 
            return 1;
        }        
        else if (background[i][1] == 1 && background[i][2] == 1 && background[i][0] == 0)
        {
            background[i][0] = -1;
            game_screen[i][0] = 'X'; 
            return 1;
        }                
    }
    return 0;
}

int column_double(int background[][3], char game_screen[][3]){

    for (int i = 0; i < 3; i++)
    {
        if (background[0][i] == -1 && background[1][i] == -1 && background[2][i] == 0)
        {
            background[2][i] = -1;
            game_screen[2][i] = 'X'; 
            return 1;
        }
        else if (background[0][i] == -1 && background[2][i] == -1 && background[1][i] == 0)
        {
            background[1][i] = -1;
            game_screen[1][i] = 'X'; 
            return 1;
        }        
        else if (background[1][i] == -1 && background[2][i] == -1 && background[0][i] == 0)
        {
            background[0][i] = -1;
            game_screen[0][i] = 'X'; 
            return 1;
        }                
    }
    for (int i = 0; i < 3; i++)
    {
        if (background[0][i] == 1 && background[1][i] == 1 && background[2][i] == 0)
        {
            background[2][i] = -1;
            game_screen[2][i] = 'X'; 
            return 1;
        }
        else if (background[0][i] == 1 && background[2][i] == 1 && background[1][i] == 0)
        {
            background[1][i] = -1;
            game_screen[1][i] = 'X'; 
            return 1;
        }        
        else if (background[1][i] == 1 && background[2][i] == 1 && background[0][i] == 0)
        {
            background[0][i] = -1;
            game_screen[0][i] = 'X'; 
            return 1;
        }  
    }
    return 0;
}

int diagonal_double(int background[][3], char game_screen[][3]){


    if (background[0][0] == -1 && background[1][1] == -1 && background[2][2] == 0)
    {
        background[2][2] = -1;
        game_screen[2][2] = 'X'; 
        return 1;
    }
    else if (background[0][0] == -1 && background[2][2] == -1 && background[1][1] == 0)
    {
        background[1][1] = -1;
        game_screen[1][1] = 'X'; 
        return 1;
    }        
    else if (background[1][1] == -1 && background[2][2] == -1 && background[0][0] == 0)
    {
        background[0][0] = -1;
        game_screen[0][0] = 'X'; 
        return 1;
    }                
    
    if (background[0][2] == 1 && background[1][1] == 1 && background[2][0] == 0)
    {
        background[2][0] = -1;
        game_screen[2][0] = 'X';    
        return 1;
    }
    else if (background[0][2] == 1 && background[2][0] == 1 && background[1][1] == 0)
    {
        background[1][1] = -1;
        game_screen[1][1] = 'X'; 
        return 1;
    }        
    else if (background[1][1] == 1 && background[2][0] == 1 && background[0][2] == 0)
    {
        background[0][0] = -1;
        game_screen[0][0] = 'X'; 
        return 1;
    }
    return 0;     
}