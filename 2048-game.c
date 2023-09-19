#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int i, j, array[4][4] = {};

int score(int array[4][4])
{
    int max = array[0][0];
    int static sum = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (array[i][j] > max)
            {
                max = array[i][j];
            }
        }
    }

    sum += max;
    return sum;
}

void interface(int array[4][4])
{
    int b[2] = {2, 4}, c[4] = {0, 1, 2, 3}, sum, n, m;
    do
    {
        srand((int)time(NULL));
        m = c[rand() % 4];
        n = c[rand() % 4];

        if (array[m][n] == 0)
        {
            array[m][n] = b[rand() % 2];
            break;
        }
    } while (1);

    printf("\bNewly added in row %d and column %d is %d\n", m + 1, n + 1, array[m][n]);

    for (i = 0; i < 4; i++)
    {
        printf("-----------------------------------------------------------------\n");

        for (j = 0; j < 4; j++)
        {
            if ((m == i) && (n == j))
            {
                printf("|\t%d\t", array[m][n]);
            }
            else
            {
                if (array[i][j] > 0)
                {
                    printf("|\t%d\t", array[i][j]);
                }
                else
                {
                    printf("|\t\t");
                }
            }
        }
        printf("|\n");
    }
    printf("-----------------------------------------------------------------\n");
    printf("      score :%d\n", sum = score(array));
}

void mergeUp(int array[4][4])
{
    int m;
    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 3; i++)
        {
            if (array[i][j] > 0)
            {
                if (array[i][j] == array[i + 1][j] && array[i][j] != 0)
                {
                    {
                        array[i][j] = 2 * array[i][j];
                        if (i == 2)
                        {
                            array[i + 1][j] = 0;
                        }
                        else
                        {
                            for (m = i + 1; m < 3; m++)
                            {
                                array[m][j] = array[m + 1][j];
                                array[m + 1][j] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

void mergeDown(int array[4][4])
{
    int m;
    for (j = 0; j < 4; j++)
    {
        for (i = 3; i > 0; i--)
        {
            if (array[i][j] > 0)
            {
                if (array[i][j] == array[i - 1][j])
                {
                    array[i][j] = 2 * array[i][j];
                    if (i == 1)
                    {
                        array[i - 1][j] = 0;
                    }
                    else
                    {
                        for (m = i - 1; m > 0; m--)
                        {
                            array[m][j] = array[m - 1][j];
                            array[m - 1][j] = 0;
                        }
                    }
                }
            }
        }
    }
}

void mergeLeft(int array[4][4])
{
    int m;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (array[i][j] > 0)
            {
                if (array[i][j] == array[i][j + 1])
                {
                    array[i][j] = 2 * array[i][j];
                    if (j == 2)
                    {
                        array[i][j + 1] = 0;
                    }
                    else
                    {
                        for (m = j + 1; m < 3; m++)
                        {
                            array[i][m] = array[i][m + 1];
                            array[i][m + 1] = 0;
                        }
                    }
                }
            }
        }
    }
}

void mergeRight(int array[4][4])
{
    int m;
    for (i = 0; i < 4; i++)
    {
        for (j = 3; j > 0; j--)
        {
            if (array[i][j] > 0)
            {
                if (array[i][j] == array[i][j - 1])
                {
                    array[i][j] = 2 * array[i][j];
                    if (j == 1)
                    {
                        array[i][j - 1] = 0;
                    }
                    else
                    {
                        for (m = j - 1; m > 0; m--)
                        {
                            array[i][m] = array[i][m - 1];
                            array[i][m - 1] = 0;
                        }
                    }
                }
            }
        }
    }
}

void mergeMove(char move)
{
    int x, m;
    switch (move)
    {
    case 'w':
        for (j = 0; j < 4; j++)
        {
            for (i = 1; i <= 3; i++)
            {
                for (x = i, m = i; x > 0; x--, m--)
                {
                    if (array[m - 1][j] > 0)
                        break;
                    else
                    {
                        array[m - 1][j] = array[m][j];
                        array[m][j] = 0;
                    }
                }
            }
        }

        mergeUp(array);
        break;
    case 's':
        for (j = 0; j < 4; j++)
        {
            for (i = 2; i >= 0; i--)
            {
                for (x = 3 - i, m = i; x > 0; x--, m++)
                {
                    if (array[m + 1][j] > 0)
                        break;
                    else
                    {
                        array[m + 1][j] = array[m][j];
                        array[m][j] = 0;
                    }
                }
            }
        }

        mergeDown(array);
        break;
    case 'a':
        for (i = 0; i < 4; i++)
        {
            for (j = 1; j <= 3; j++)
            {
                for (x = j, m = j; x > 0; x--, m--)
                {
                    if (array[i][m - 1] > 0)
                        break;
                    else
                    {
                        array[i][m - 1] = array[i][m];
                        array[i][m] = 0;
                    }
                }
            }
        }
        mergeLeft(array);
        break;
    case 'd':
        for (i = 0; i < 4; i++)
        {
            for (j = 2; j >= 0; j--)
            {
                for (x = 3 - j, m = j; x > 0; x--, m++)
                {
                    if (array[i][m + 1] > 0)
                        break;
                    else
                    {
                        array[i][m + 1] = array[i][m];
                        array[i][m] = 0;
                    }
                }
            }
        }
        mergeRight(array);
        break;
    }
}

int main()
{
    int loop = 1;
    int option;
    char move;

    printf("Welcome to 2048\n");
mainMenu:;
    printf("\nChoose your options\n");
    printf("  1. Start \n");
    printf("  2. Help \n");
    printf("  3. Quit \n");
    option = 0;
    scanf("%d", &option);
    getchar();
    printf("\n");
    if (option == 1)
    {
        while (loop == 1)
        {
            interface(array);
            move = getchar();
            getchar();
            printf("\n");
            mergeMove(move);

            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (array[i][j] == 0)
                    {
                        loop = 1;
                        goto end;
                    }
                    else
                    {
                        loop = 0;
                    }
                }
            }
        end:;
        }
    }
    else if (option == 2)
    {
        printf(" Rules of the game:\n\n");
        printf(" 1. By clicking <w>,<s>,<a>,<d> Key to move the Numbers up, down, left and right.\n");
        printf(" 2. Add the same Numbers. \n");
        printf(" 3. The sum of the Numbers in each cell will be scored. \n");
        printf(" 4. Invalid moves does not affect you moves and gameplay running continuous. \n");
        printf(" \n\nEnter any key to return to main menu.\n");
        getchar();
        getchar();
        goto mainMenu;
    }
    else if (option == 3)
    {
        printf("Game Exit\a\n");
        goto endl;
    }
    else
    {
        printf(" ! Invalid Choice ! \n\n");
        goto mainMenu;
    }
    printf("      Nice Try  \a\n");
    printf("      Game over \a\n");
endl:;
    return 0;
}