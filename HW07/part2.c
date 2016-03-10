/*##################################################################*/
/*HW07_<IlaydaZeynep>_<Ozdemir>_<131044022>_part2.c                 */
/*_____________________________________                             */
/*Written by Ilayda Ozdemir                                         */
/*Input:                                                            */
/*  -Number of stairs                                               */
/*Output:                                                           */
/*  -Total number of different ways                                 */
/*##################################################################*/
#include <stdio.h>

int combination (int n , int k);

int ways (int n);

int recursive_ways(int n,int k);

/***************************************************************/
/*                       MAIN                                  */
/***************************************************************/

int main(void)
{

    int total_ways,n,x;

    
    printf("Please write number of stairs (as a 'n') »\n");
    scanf("%d",&n);
    total_ways=ways(n);

    printf("\n× %d different ways (for %d)×\n\n",total_ways,n);
    return 0;
}


/*function to calculate combination    */
/* -n choose k- and returns the result */
/*recursive*/
int combination (int n , int k)
{
int result;
    if(n==k || k==0)
        result=1;
        
    else
        result=combination(n-1,k-1)+combination(n-1,k);

return result;
}

/*function to call recursive_ways and keep k=0*/
/*iterative*/
int ways (int n)
{
    int result;
    int k=0;

    result=recursive_ways(n,k);


return result;
}

/*function to calculate and return*/ 
/*total number of ways            */
/*revursive*/
int recursive_ways(int n,int k)
{
    int result;

    if(n==k || (n-k)==1)/*durma kosulu*/
    {    
        if(n-k==1)
            result=n;
        
        else
            result=1;
        /*printf("C(%d,%d)",n,k);*/
    }
    else if (n>k) 
    {  
        /*printf("C(%d,%d)+",n,k);*/
        result=combination(n,k)+recursive_ways(n-1,k+1); 

    }

return result;
}

/*##################################################################*/
/*    End of HW07_<IlaydaZeynep>_<Ozdemir>_<131044022>_part2.c      */
/*##################################################################*/
