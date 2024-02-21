#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    

    srand(time(NULL));
    int low = 1, top = 3, move;
    int back[3][3] = {0}, sat, sut, p=2, g, z;
    char front[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    printf("Bir insana karsi mi yoksa bilgisayara karsi mi oynamak istersin?\nbilgisayar icin 1, insan icin 2'yi tusla: ");
    scanf("%d", &g);

    if (g==1)
    {
         printf("Kolay mod icin 1i, zor mod icin 2'yi tusla: ");
        scanf("%d", &z);
    }
    

    if(g == 2)
    {
        while (1)
        {
            if (p == 11)
            {
                printf("\n\n\nOyun berabere bitti :(\n");
                break;
            }
            
            
            
            for (int i = 0; i < 3; i++)
            {
                printf("| ");
                for (int j = 0; j < 3; j++)
                {
                    printf(" %c  | ", front[i][j]);
                }
                printf("\n-------------------\n");
            }
            printf("%d'inci oyuncunun hamle sirasi!", p%2+1);
            scanf("%d", &sat);
            scanf("%d", &sut);
    
            if (p%2+1 == 1)
            {
                if(back[sat-1][sut-1] == 0)
                {
                front[sat-1][sut-1] = 'O';
                back[sat-1][sut-1] = 2;
                p++;
                }
            }
            else if (p%2+1 == 2)
            {
                if(back[sat-1][sut-1] == 0)
                {
                front[sat-1][sut-1] = 'X';
                back[sat-1][sut-1] = -2;
                p++;
                }
            }

            if (back[0][0] + back[0][1] + back[0][2] == 6 ||
                back[1][0] + back[1][1] + back[1][2] == 6 ||
                back[2][0] + back[2][1] + back[2][2] == 6 ||
                back[0][0] + back[1][0] + back[2][0] == 6 ||
                back[0][1] + back[1][1] + back[2][1] == 6 ||
                back[0][2] + back[1][2] + back[2][2] == 6 ||
                back[0][0] + back[1][1] + back[2][2] == 6 ||
                back[0][2] + back[1][1] + back[2][0] == 6)
            {
                printf("%d'inci oyuncu kazandi!\n",(p-1)%2 +1);
                break;
            }
            else if (back[0][0] + back[0][1] + back[0][2] == -6 ||
                    back[1][0] + back[1][1] + back[1][2] == -6 ||
                    back[2][0] + back[2][1] + back[2][2] == -6 ||
                    back[0][0] + back[1][0] + back[2][0] == -6 ||
                    back[0][1] + back[1][1] + back[2][1] == -6 ||
                    back[0][2] + back[1][2] + back[2][2] == -6 ||
                    back[0][0] + back[1][1] + back[2][2] == -6 ||
                    back[0][2] + back[1][1] + back[2][0] == -6)
            {
                printf("%d'inci oyuncu kazandi!\n",(p-1)%2 +1);
                break;
            }
        }
        
            for (int i = 0; i < 3; i++)
        {
            printf("| ");
            for (int j = 0; j < 3; j++)
            {
                printf(" %c  | ", front[i][j]);
            }
            printf("\n-------------------\n");
        }
    }  
    else if (g==1)
    {
        if(z==1)
        {  
            while (1)
            {
                move = 1;
                if (p == 11)
                {
                    printf("\n\n\nOyun berabere bitti :(\n");
                    break;
                }
                
                
                
                for (int i = 0; i < 3; i++)
                {
                    printf("| ");
                    for (int j = 0; j < 3; j++)
                    {
                        printf(" %c  | ", front[i][j]);
                    }
                    printf("\n-------------------\n");
                }
                
                if (p%2+1 == 1)
                {
                    printf("Sira sende! ");
                    scanf("%d", &sat);
                    scanf("%d", &sut);
                }
                
                if (p%2+1 == 1)
                {
                    if(back[sat-1][sut-1] == 0)
                    {
                    front[sat-1][sut-1] = 'O';
                    back[sat-1][sut-1] = 2;
                    p++;
                    }
                }
                else if (p%2+1 == 2)
                {

                    while(move == 1){
                        
                        sat = rand() % (top - low + 1) + low;
                        sut = rand() % (top - low + 1) + low;
                        printf(" %d %d \n", sat , sut);
                        if(back[sat-1][sut-1] == 0)
                        {
                        front[sat-1][sut-1] = 'X';
                        back[sat-1][sut-1] = -2;
                        p++;
                        move = 0;
                        }
                    }    
                }

                if (back[0][0] + back[0][1] + back[0][2] == 6 ||
                    back[1][0] + back[1][1] + back[1][2] == 6 ||
                    back[2][0] + back[2][1] + back[2][2] == 6 ||
                    back[0][0] + back[1][0] + back[2][0] == 6 ||
                    back[0][1] + back[1][1] + back[2][1] == 6 ||
                    back[0][2] + back[1][2] + back[2][2] == 6 ||
                    back[0][0] + back[1][1] + back[2][2] == 6 ||
                    back[0][2] + back[1][1] + back[2][0] == 6)
                {
                    printf("%d'inci oyuncu kazandi!\n",(p-1)%2 +1);
                    break;
                }
                else if (back[0][0] + back[0][1] + back[0][2] == -6 ||
                        back[1][0] + back[1][1] + back[1][2] == -6 ||
                        back[2][0] + back[2][1] + back[2][2] == -6 ||
                        back[0][0] + back[1][0] + back[2][0] == -6 ||
                        back[0][1] + back[1][1] + back[2][1] == -6 ||
                        back[0][2] + back[1][2] + back[2][2] == -6 ||
                        back[0][0] + back[1][1] + back[2][2] == -6 ||
                        back[0][2] + back[1][1] + back[2][0] == -6)
                {
                    printf("Kazanan bilgisayar!!!\n");
                    break;
                }
            }
        }
        else if(z==2)
        {
            while (1)
            {
                printf("Under Construction...\n");
                break;
                
                move = 1;
                if (p == 11)
                {
                    printf("\n\n\nOyun berabere bitti :(\n");
                    break;
                }
                                                
                for (int i = 0; i < 3; i++)
                {
                    printf("| ");
                    for (int j = 0; j < 3; j++)
                    {
                        printf(" %c  | ", front[i][j]);
                    }
                    printf("\n-------------------\n");
                }
                
                if (p%2+1 == 1)
                {
                    printf("Sira sende! ");
                    scanf("%d", &sat);
                    scanf("%d", &sut);
                }
                
                if (p%2+1 == 1)
                {
                    if(back[sat-1][sut-1] == 0)
                    {
                    front[sat-1][sut-1] = 'O';
                    back[sat-1][sut-1] = 2;
                    p++;
                    }
                }
                else if (p%2+1 == 2)
                {

                    while(move == 1){
                        
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }
                        if ((back[0][0] + back[0][1] == 4) && back[0][2] == 0)
                        {
                            sat = 1;
                            sut = 3;
                        }                                                
                        else
                        {                       
                            sat = rand() % (top - low + 1) + low;
                            sut = rand() % (top - low + 1) + low;
                        }

                        if(back[sat-1][sut-1] == 0)
                        {
                            front[sat-1][sut-1] = 'X';
                            back[sat-1][sut-1] = -2;
                            p++;
                            move = 0;
                        }
                    }    
                }

                if (back[0][0] + back[0][1] + back[0][2] == 6 ||
                    back[1][0] + back[1][1] + back[1][2] == 6 ||
                    back[2][0] + back[2][1] + back[2][2] == 6 ||
                    back[0][0] + back[1][0] + back[2][0] == 6 ||
                    back[0][1] + back[1][1] + back[2][1] == 6 ||
                    back[0][2] + back[1][2] + back[2][2] == 6 ||
                    back[0][0] + back[1][1] + back[2][2] == 6 ||
                    back[0][2] + back[1][1] + back[2][0] == 6)
                {
                    printf("%d'inci oyuncu kazandi!\n",(p-1)%2 +1);
                    break;
                }
                else if (back[0][0] + back[0][1] + back[0][2] == -6 ||
                        back[1][0] + back[1][1] + back[1][2] == -6 ||
                        back[2][0] + back[2][1] + back[2][2] == -6 ||
                        back[0][0] + back[1][0] + back[2][0] == -6 ||
                        back[0][1] + back[1][1] + back[2][1] == -6 ||
                        back[0][2] + back[1][2] + back[2][2] == -6 ||
                        back[0][0] + back[1][1] + back[2][2] == -6 ||
                        back[0][2] + back[1][1] + back[2][0] == -6)
                {
                    printf("Kazanan bilgisayar!!!\n");
                    break;
                }
            }
        }
        
            for (int i = 0; i < 3; i++)
        {
            if (z == 2)
            {
                break;
            }
            
            
            printf("| ");
            for (int j = 0; j < 3; j++)
            {
                printf(" %c  | ", front[i][j]);
            }
            printf("\n-------------------\n");
        }
    }
     
    




}