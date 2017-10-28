#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, const char * argv[])
{
    printf("Please input size of first matrix\n");
    int m=0,n=0,e=0;
    srand(time(NULL));
    scanf("%d %d",&m,&n);
    while(m<3 || n<4){
        printf("---!!!The size of the matrix is less than the minimum! \nInput '1' than try again  or '2' to exit.!!!---\n");
        scanf("%d",&e);
        if(e==1){
            scanf("%d %d",&m,&n);
        }
        else {
            return EXIT_FAILURE;
        }
    }
    
    
    
    int matr1[m][n];
    
    int i = 0;
    int j = 0;
    
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            matr1[i][j] = rand() % 9;
        }
    }
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("%d ",matr1[i][j]);
            if(j == n-1)
                printf("\n");
        }
    }
    printf("\n");
    
    for(i=0;i<n;++i)
    {
        int a = 0;
        a = matr1[0][i];
        matr1[0][i] = matr1[m-1][i];
        matr1[m-1][i] = a;
    }
    
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("%d ",matr1[i][j]);
            if(j == n-1)
                printf("\n");
        }
    }
    int a_1 = 0;
    int b_1 = 0;
    int k = n-1;
    for (i=0;i<n;i++)
    {
        if (k!=i)
        {
            
            a_1 = matr1[0][i];
            matr1[0][i] = matr1[0][k];
            matr1[0][k] = a_1;
            b_1 = matr1[m-1][i];
            matr1[m-1][i] = matr1[m-1][k];
            matr1[m-1][k] = b_1;
            k--;
        }
        else
            break;
    }
    printf("\n");

    printf("*** Deployed matrix ***\n\n");
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("%d ",matr1[i][j]);
            if(j == n-1)
                printf("\n");
        }
    }
    int min = 10;
    
    int m1 = 0, n1 = 0;
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            if(matr1[i][j] < min)
            {
                min = matr1[i][j];
                m1 = i; n1 = j;
            }
        }
    }
    
    printf("\n");
    
    printf("Minimal number is:===> %d <===  \nline %d column %d \n",min,m1+1,n1+1);
    printf("\n");
    k=0;
    int l=0;
    int rematr1 [m-1] [n-1];
    for(i=0;i<m;i++)
    {
        if (i!=m1){
            for (j=0;j<n;j++)
            {
                if (j!=n1)
                {
                    rematr1[k][l] = matr1[i][j];
                    l++;
                }
            }
            l=0;
            k++;
        }
    }
    
    for(i=0;i<m-1;++i)
    {
        for(j=0;j<n-1;++j)
        {
            printf("%d ",rematr1[i][j]);
            if(j == n-2)
                printf("\n");
        }
    }
    int g,h;
    printf("\n");
    printf("Please input size of second matrix\n");
    scanf("%d %d",&g,&h);
    printf("Please input value for matrix\n");
    int s, em,en;
    em = g;
    en = h;
    int new[em][en],ed;
    char input;
    for (i = 0; i<em; i++)
    {
        for (j = 0; j<en; j++)
        {
            new[i][j]= 0;
            
        }
    }
    s=0;
    i=0;
    j=0;
    ed=0;
    while (ed==0)
    {
        input=getchar();
        switch (input)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                s=s*10+input-'0';
                break;
            case ' ':
                new[i][j]=s;
                if (j<en)
                {
                    j++;
                    s=0;
                }
                else
                {
                    printf("End of line, please use ',' or '.'\n");
                    j=en;
                    s=0;
                }
                break;
                
            case ',':
                new[i][j]=s;
                j=0;
                if (i<em)
                {
                    i++;
                    s=0;
                }
                else
                {
                    printf("End of column! Use '.'\n");
                    s=0;
                    i=em;
                    
                }
                break;
            case '.':
                new[i][j]=s;
                ed=1;
                break;
        }
    }
    printf("\n");
    for(i=0;i<em;++i)
    {
        for(j=0;j<en;++j)
        {
            printf("%d ",new[i][j]);
            if(j == en-1)
                printf("\n");
        }
        
        
    }
    printf("\n");
    int mult_matrix[em][en];
    if (em!=n-1)
    {
         printf("*** This matrix not for multiplication ***\n");
    }
    else
    {
    
    printf("*** Multiplied matrix ***\n");
        for(i = 0; i < m-1; i++)
            for(j = 0; j < en; j++)
            {
                mult_matrix[i][j] = 0;
                for(k = 0; k < n-1; k++)
                    mult_matrix[i][j] += rematr1[i][k] * new[k][j];
                    printf("%d ",mult_matrix[i][j]);
                if (j==en-1)
                {
                    printf("\n");
                }
            }
            printf("\n");
        }

}

