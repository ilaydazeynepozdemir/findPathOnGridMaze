/*##################################################################*/
/*HW07_<IlaydaZeynep>_<Ozdemir>_<131044022>_part3.c                 */
/*_____________________________________                             */
/*Written by Ilayda Ozdemir                                         */
/* Input:                                                           */    
/*  -x,y location                                                   */
/*  -one matrix                                                     */
/* Output:                                                          */
/*  -Output path                                                    */    
/*##################################################################*/

#include <stdio.h>
#define COL_SIZE 10
#define ROW_SIZE 10
typedef enum {notavailable,available,right_down}Grid_t;
typedef enum {FALSE,TRUE}Bool;


void read_table(FILE *input_file,Grid_t table[][COL_SIZE]);
void print_path(char path[][COL_SIZE], int n);
Bool find_path(Grid_t table[][COL_SIZE], char path[][COL_SIZE],
int size, int location_x, int location_y);

/***************************************************************/
/*                       MAIN                                  */
/***************************************************************/

int main(void)
{
    Grid_t table[ROW_SIZE][COL_SIZE];
    int i,j;
    Bool check;
    char path[ROW_SIZE][COL_SIZE];
    FILE *iptr;
    if((iptr=fopen("table.txt","r"))==NULL)
    {   
        printf("Error!! Check text file!\n");
        return 1;
    }
    
        for(i=0;i<ROW_SIZE;++i)
    {
        for(j=0;j<COL_SIZE;++j)
        {
            path[i][j]='-';
        }   
    }  
    read_table(iptr,table);
    check=find_path(table,path,5,0,0);
    if(check==TRUE)
    {
    printf("\n~~Output path~~\n");
    print_path(path,5);
    } 
    else
        printf("Wrong way!!!Could not find output path\n");
    fclose(iptr);
    return 0;
}
/*read N×N array in text file.*/
/*iterative*/
void read_table(FILE *input_file,Grid_t table[][COL_SIZE])
{   
    int i,j,status;
    int int_value; 
    printf("\n««Maze»»\n");
    for(i=0;i<ROW_SIZE;++i)
    {
        for(j=0;j<COL_SIZE;++j)
        {
            fscanf(input_file,"%d",&int_value);           
            table[i][j]=(Grid_t)int_value;/*integer deger Grid_t tipine cast edilir*/
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }    
}
/*print true path */
/*iterative*/
void print_path(char path[][COL_SIZE], int n)
{
    int i,j;
    for(i=0;i<ROW_SIZE;++i)
    {
        for(j=0;j<COL_SIZE;++j)
        {
            printf("%c",path[i][j]);/*iki boyutlu array yazdirilir*/
        }
        printf("\n");
    }    
}
/*creative path*/
/*recursive*/
Bool find_path(Grid_t table[][COL_SIZE], char path[][COL_SIZE],int size, int location_x, int location_y)
{
    Bool res=FALSE;
    Grid_t where,where_y_x1,where_y1_x,where_y1_x1;
    if(location_y==(ROW_SIZE-1) && location_x==(COL_SIZE-1))/*y satir,x sutun*/
    {                                                       /*durma kosulu   */    
        path[ROW_SIZE-1][COL_SIZE-1]='*';
        res=TRUE;
    }
    else 
    {
        where=table[location_y][location_x];
        switch(where)
        {    
            case available: /*durum available ise*/
            {               
                path[location_y][location_x]='*';
                if(table[location_y][location_x+1] != notavailable)
                {
                    if(table[location_y][location_x+2] == notavailable   && table[location_y][location_x+1] == right_down)
                        res=find_path(table,path,size,location_x+1,location_y);
                    else if (table[location_y][location_x+2] == notavailable   && (table[location_y][location_x+1] == available && table[location_y+1][location_x+1]==notavailable))
                        res=find_path(table,path,size,location_x,location_y+1);
                    else
                        res=find_path(table,path,size,location_x+1,location_y);
                    
                }    
                else if(table[location_y+1][location_x] != notavailable)
                    res=find_path(table,path,size,location_x,location_y+1);
            }  
            break;  
            /*durum notavailable ise bu case'in islevi yok!Cunku sifir oldugu durumları ele almıyor*/
            case notavailable:  path[location_y][location_x]=' ';   break;
            
            case right_down: /*durum right_down ise*/
            {
                path[location_y][location_x]='*';
                if(table[location_y+1][location_x+1] != notavailable )
                     res=find_path(table,path,size,location_x+1,location_y+1);
                else 
                {
                     if(table[location_y][location_x+1] != notavailable )
                        res=find_path(table,path,size,location_x+1,location_y);  
                     if(table[location_y+1][location_x] != notavailable )
                        res=find_path(table,path,size,location_x,location_y+1); 
               } 
            }
            break;
        }
    }
    return res;
}
/*##################################################################*/
/*    End of HW07_<IlaydaZeynep>_<Ozdemir>_<131044022>_part3.c      */
/*##################################################################*/
