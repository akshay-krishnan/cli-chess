#include<iostream>
#include<time.h>
#include<windows.h>
#include<math.h>
#include<conio.h>
#include<ctype.h>
#include "delay.h"
class rook;
class bishop;
class Queen;
class knight;
class king;
int matrix[8][8];
int bkingi=0, bkingj=4;
int wkingi=7, wkingj=4;

COORD coord={0,0};
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

class Pawn
{
private:

public:
    bool bmove(int source_i,int source_j,int dest_i,int dest_j)
    {
        int pdesti[4] = {99,99,99,99};
        int pdestj[4] = {99,99,99,99};
        if((source_i==1)&&(matrix[source_i+1][source_j]==0)&&(matrix[source_i+2][source_j]==0))
        {
           pdesti[0]=source_i+2;
           pdestj[0]=source_j;
        }
        if(matrix[source_i+1][source_j]==0)
        {
            pdesti[1]=source_i+1;
            pdestj[1]=source_j;
        }
        if(matrix[source_i+1][source_j-1]/10==2)
        {
            pdesti[2]=source_i+1;
            pdestj[2]=source_j-1;
        }
       if(matrix[source_i+1][source_j+1]/10==2)
       {
           pdesti[3]=source_i+1;
           pdestj[3]=source_j+1;
       }
      int flag = 0;
      for(int k=0;k<4;k++)
       {

           if((dest_i==pdesti[k])&&(dest_j==pdestj[k]))
           {
               flag=1;
               break;
           }


       }
       if(flag)
       {
           return true;
       }
       else
       {
           return false;
       }
       }

       bool wmove(int source_i,int source_j,int dest_i,int dest_j)
       {
        int pdesti[4]={99,99,99,99};
        int pdestj[4]={99,99,99,99};

        if((source_i==6)&&(matrix[source_i-1][source_j]==0)&&(matrix[source_i-2][source_j]==0))
        {
           pdesti[0]=source_i-2;
           pdestj[0]=source_j;
        }
        if(matrix[source_i-1][source_j]==0)
        {
            pdesti[1]=source_i-1;
            pdestj[1]=source_j;
        }
        if(matrix[source_i-1][source_j-1]/10==1)
        {
            pdesti[2]=source_i-1;
            pdestj[2]=source_j-1;
        }
       if(matrix[source_i-1][source_j+1]/10==1)
       {
           pdesti[3]=source_i-1;
           pdestj[3]=source_j+1;
       }

       int flag=0;
       for(int k=0;k<4;k++)
       {
           if((dest_i==pdesti[k])&&(dest_j==pdestj[k]))
           {
               flag=1;
               break;
           }
      }
       if(flag)
       {
           return true;
       }
       else
       {
           return false;
       }
       }
};



class knight
{

   public:
       bool wmove(int source_i,int source_j,int dest_i,int dest_j)
       {
           int pdesti[8]={99,99,99,99,99,99,99,99};
           int pdestj[8]={99,99,99,99,99,99,99,99};

           if((source_j>=1)&&(source_i>=2)&&(matrix[source_i-2][source_j-1]/10!=2))
           {
               pdesti[0]=source_i-2;
               pdestj[0]=source_j-1;
           }
           if(((source_j<=6)&&(source_i>=2))&&(matrix[source_i-2][source_j+1]/10!=2))
           {
               pdesti[1]=source_i-2;
               pdestj[1]=source_j+1;
           }
           if((source_j>=2)&&(source_i>=1)&&(matrix[source_i-1][source_j-2])/10!=2)
            {
               pdesti[2]=source_i-1;
               pdestj[2]=source_j-2;
            }

            if((source_j<=5)&&(source_i>=1)&&(matrix[source_i-1][source_j+2]/10!=2))
            {
                pdesti[3]=source_i-1;
                pdestj[3]=source_j+2;
            }
           if((source_j>=1)&&(source_i<=5)&&(matrix[source_i+2][source_j-1]/10!=2))
           {
               pdesti[4]=source_i+2;
               pdestj[4]=source_j-1;

           }
             if(((source_j<=6)&&(source_i<=5))&&(matrix[source_i+2][source_j+1]/10!=2))
           {
               pdesti[5]=source_i+2;
               pdestj[5]=source_j+1;

           }
           if((source_j>=2)&&(source_i<=6)&&(matrix[source_i+1][source_j-2])/10!=2)
            {
               pdesti[6]=source_i+1;
               pdestj[6]=source_j-2;
            }

            if(((source_j<=5)&&(source_i<=6))&&(matrix[source_i+1][source_j+2]/10!=2))
            {
                pdesti[3]=source_i+1;
                pdestj[3]=source_j+2;

            }

           int flag=0;
            for(int k=0;k<8;k++)
           {
           if((dest_i==pdesti[k])&&(dest_j==pdestj[k]))
           {
               flag=1;
               break;
           }
           }

       if(flag)
       {
           return true;
       }
       else
       {
          return false;
       }

   }


         bool bmove(int source_i,int source_j,int dest_i,int dest_j)
       {
           int pdesti[8]={99,99,99,99,99,99,99,99};
           int pdestj[8]={99,99,99,99,99,99,99,99};

           if((source_j>=1)&&(source_i>=2)&&(matrix[source_i-2][source_j-1]/10!=1))
           {
               pdesti[0]=source_i-2;
               pdestj[0]=source_j-1;

           }
           if(((source_j<=6)&&(source_i>=2))&&(matrix[source_i-2][source_j+1]/10!=1))
           {
               pdesti[1]=source_i-2;
               pdestj[1]=source_j+1;

           }
           if((source_j>=2)&&(source_i>=1)&&(matrix[source_i-1][source_j-2])/10!=1)
            {
               pdesti[2]=source_i-1;
               pdestj[2]=source_j-2;
            }

            if((source_j<=5)&&(source_i>=1)&&(matrix[source_i-1][source_j+2]/10!=1))
            {
                pdesti[3]=source_i-1;
                pdestj[3]=source_j+2;
            }
           if((source_j>=1)&&(source_i<=5)&&(matrix[source_i+2][source_j-1]/10!=1))
           {
               pdesti[4]=source_i+2;
               pdestj[4]=source_j-1;

           }
             if(((source_j<=6)&&(source_i<=5))&&(matrix[source_i+2][source_j+1]/10!=1))
           {
               pdesti[5]=source_i+2;
               pdestj[5]=source_j+1;

           }
           if((source_j>=2)&&(source_i<=6)&&(matrix[source_i+1][source_j-2]/10!=1))
            {
               pdesti[6]=source_i+1;
               pdestj[6]=source_j-2;
            }

            if((source_j<=5)&&(source_i<=6)&&(matrix[source_i+1][source_j+2]/10!=1))
            {
                pdesti[7]=source_i+1;
                pdestj[7]=source_j+2;
            }

      int flag=0;
      for(int k=0;k<8;k++)
       {
           if((dest_i==pdesti[k])&&(dest_j==pdestj[k]))
           {
               flag=1;
               break;
           }
       }
       if(flag)
       {
          return true;
       }
       else
       {
           return false;
       }
       }
};

class rook
{
    public:
    bool wmove(int source_i,int source_j,int dest_i,int dest_j)
    {
    int pdest[4]={99,99,99,99};
    for(int k=source_j;k>=0;k--)
    {
        if(matrix[source_i][k]/10==1 || (k-1<0))
           {
             pdest[0]=k;
             break;
           }
         if(matrix[source_i][k]/10==2)
         {
             pdest[0]=k+1;
             break;
         }
    }
    for(int k=source_j;k<=7;k++)
    {
       if(matrix[source_i][k]/10==1 || (k+1>7))
           {
             pdest[1]=k;
             break;
           }
         if(matrix[source_i][k]/10==2)
         {
             pdest[1]=k-1;
             break;
         }
    }
    for(int k=source_i;k<=7;k++)
    {
         if(matrix[k][source_j]/10==1 || (k+1>7))
           {
             pdest[2]=k;
             break;
           }
         if(matrix[k][source_j]/10==2)
         {
             pdest[2]=k-1;
             break;
         }
    }

    for(int k=source_i;k>=0;k--)
    {
         if(matrix[k][source_j]/10==1 || (k-1<0))
           {
             pdest[3]=k;
             break;
           }
         if(matrix[k][source_j]/10==2)
         {
             pdest[3]=k+1;
             break;
         }
    }
    for(int h = 0; h<4; h++)
    {
        std::cout<<pdest[h]<<std::endl;
    }
    if(source_i==dest_i)
    {
    if(dest_j<=pdest[1]||dest_j>=pdest[0])
        return true;
    else
        return false;
    }
    else if(source_j==dest_j)
    {
    if(dest_i<=pdest[2]||dest_j>=pdest[3])
        return true;
    else
        return false;
    }
    else
        return false;
    }

bool bmove(int source_i,int source_j,int dest_i,int dest_j)
    {
    int pdest[4]={99,99,99,99};
     for(int k=source_j;k>=0;k--)
    {
        if(matrix[source_i][k]/10==2 || (k-1<0))
           {
             pdest[0]=k;
             break;
           }
         if(matrix[source_i][k]/10==1)
         {
             pdest[0]=k+1;
             break;

         }
    }
    for(int k=source_j;k<=7;k++)
    {
       if(matrix[source_i][k]/10==2 || (k+1>7))
           {
             pdest[1]=k;
             break;
           }
         if(matrix[source_i][k]/10==1)
         {
             pdest[1]=k-1;
             break;
         }
    }

    for(int k=source_i;k<=7;k++)
    {
         if(matrix[k][source_j]/10==2 || (k+1>7))
           {
             pdest[2]=k;
             break;

           }
         if(matrix[k][source_j]/10==1)
         {
             pdest[2]=k-1;
             break;
         }
    }

    for(int k=source_i;k>=0;k--)
    {
         if(matrix[k][source_j]/10==2|| (k-1<0))
           {
             pdest[3]=k;
             break;
           }
         if(matrix[k][source_j]/10==1 )
         {
             pdest[3]=k+1;
             break;
         }
    }

if(source_i==dest_i)
{
    if(dest_j<=pdest[1]||dest_j>=pdest[0])
        return true;
    else
        return false;

}
else if(source_j==dest_j)
{
    if(dest_i<=pdest[2]||dest_j>=pdest[3])
        return true;
    else
        return false;
}
else
    return false;
}
};

class bishop
{
        int pdesti[4]={99,99,99,99};
        int pdestj[4]={99,99,99,99};

        public:
        bool wmove(int source_i,int source_j,int dest_i,int dest_j)
        {
        for(int k=1;((source_i-k)>=0)&&((source_j+k)<=7);k++)
        {
            if(matrix[source_i-k][source_j+k]/10==2)
                {
                pdesti[0]=source_i-k+1;
                pdestj[0]=source_j+k-1;
                break;
                }
           if(matrix[source_i-k][source_j+k]/10==1 ||((source_i-k-1<0)||(source_j+k+1>7)))
                {
                pdesti[0]=source_i-k;
                pdestj[0]=source_j+k;
                break;
                }
        }
        for(int k=1;((source_i-k)>=0)&&((source_j-k)>=0);k++)
        {
            if(matrix[source_i-k][source_j-k]/10==2)
                {
                pdesti[1]=source_i-k+1;
                pdestj[1]=source_j-k+1;
                break;
                }
           if(matrix[source_i-k][source_j-k]/10==1||((source_i-k-1<0)||(source_j-k-1<0)))
                {
                pdesti[1]=source_i-k;
                pdestj[1]=source_j-k;
                break;
                }
        }
for(int k=1;((source_i+k)<=7)&&((source_j+k)<=7);k++)
        {
            if(matrix[source_i+k][source_j+k]/10==2)
                {
                pdesti[2]=source_i+k-1;
                pdestj[2]=source_j+k-1;
                break;
                }
           if(matrix[source_i+k][source_j+k]/10==1 || ((source_i+k+1>7)||(source_j+k+1>7)))
                {
                pdesti[2]=source_i+k;
                pdestj[2]=source_j+k;
                break;
                }
        }
for(int k=1;((source_i+k)<=7)&&((source_j-k)>=0);k++)
        {
            if(matrix[source_i+k][source_j-k]/10==2)
                {
                pdesti[3]=source_i+k-1;
                pdestj[3]=source_j-k+1;
                break;
                }
            if(matrix[source_i+k][source_j-k]/10==1 || ((source_i+k+1>7)||(source_j-k-1<0)))
                {
                pdesti[3]=source_i+k;
                pdestj[3]=source_j-k;
                break;
                }
        }
        int diffi, diffj;
        diffi = dest_i - source_i;
        diffj = dest_j - source_j;

        if(diffi == diffj || (((diffi + diffj)==0)&& diffi !=0))
        {
            {
                if(((dest_i>= pdesti[0]) && (dest_j <= pdestj[0])) || ((dest_i>= pdesti[1]) && (dest_j >= pdestj[1])) || ((dest_i<= pdesti[2]) && (dest_j <= pdestj[2])) || ((dest_i<= pdesti[3]) && (dest_j >= pdestj[3])))
                    while(1)
                        std::cout<<"true";
                    //return true;
                else
                {
                    while(1)
                        std::cout<<"false";
                   return false;
                }
            }
        }
        else
            while(1)
                        std::cout<<"false";
            return false;
}

        bool bmove(int source_i,int source_j,int dest_i,int dest_j)
        {
        for(int k=1;((source_i-k)>=0)&&((source_j+k)<=7);k++)
        {
           if(matrix[source_i-k][source_j+k]/10==1)
                {
                    pdesti[0]=source_i-k+1;
                    pdestj[0]=source_j+k-1;
                    break;
                }
           if(matrix[source_i-k][source_j+k]/10==2 ||((source_i-k-1<0)||(source_j+k+1>7)))
                {
                pdesti[0]=source_i-k;
                pdestj[0]=source_j+k;
                break;
                }
        }
for(int k=1;((source_i-k)>=0)&&((source_j-k)>=0);k++)
        {
            if(matrix[source_i-k][source_j-k]/10==1)
                {
                pdesti[1]=source_i-k+1;
                pdestj[1]=source_j-k+1;
                break;
                }
           if(matrix[source_i-k][source_j-k]/10==2||((source_i-k-1<0)||(source_j-k-1<0)))
                {
                pdesti[1]=source_i-k;
                pdestj[1]=source_j-k;
                break;
                }
        }
for(int k=1;((source_i+k)<=7)&&((source_j+k)<=7);k++)
        {
            if(matrix[source_i+k][source_j+k]/10==1)
                {
                pdesti[2]=source_i+k-1;
                pdestj[2]=source_j+k-1;
                break;
                }
           if(matrix[source_i+k][source_j+k]/10==2 || ((source_i+k+1>7)||(source_j+k+1>7)))
                {
                pdesti[2]=source_i+k;
                pdestj[2]=source_j+k;
                break;
                }
        }
for(int k=1;((source_i+k)<=7)&&((source_j-k)>=0);k++)
        {
            if(matrix[source_i+k][source_j-k]/10==1)
                {
                pdesti[3]=source_i+k-1;
                pdestj[3]=source_j-k+1;
                break;
                }
            if(matrix[source_i+k][source_j-k]/10==2 || ((source_i+k+1>7)||(source_j-k-1<0)))
                {
                pdesti[3]=source_i+k;
                pdestj[3]=source_j-k;
                break;
                }
        }
        int diffi, diffj;
        diffi = dest_i - source_i;
        diffj = dest_j - source_j;
char c;
        std::cout<<pdesti[0]<<" "<<pdesti[1]<<" "<<pdesti[2]<<" "<<pdesti[3];
        std::cout<<pdestj[0]<<" "<<pdestj[1]<<" "<<pdestj[2]<<" "<<pdestj[3];
        std::cin>>c;
        if(diffi == diffj || (((diffi + diffj)==0)&& diffi !=0))
        {

                if(((dest_i>= pdesti[0]) && (dest_j <= pdestj[0]) &&((pdesti[0]-dest_i == pdestj[0]-dest_j)||(pdesti[0]-dest_i == dest_j-pdestj[0]))&&(abs(source_i - pdesti[0])>= abs(source_i-dest_i))) ||
                   ((dest_i>= pdesti[1]) && (dest_j >= pdestj[1])&&((pdesti[1]-dest_i == pdestj[1]-dest_j)||(pdesti[1]-dest_i == dest_j-pdestj[1]))&&(abs(source_i - pdesti[1])>= abs(source_i-dest_i))) ||
                   ((dest_i<= pdesti[2]) && (dest_j <= pdestj[2])&&((pdesti[2]-dest_i == pdestj[2]-dest_j)||(pdesti[2]-dest_i == dest_j-pdestj[2]))&&(abs(source_i - pdesti[2])>= abs(source_i-dest_i))) ||
                   ((dest_i<= pdesti[3]) && (dest_j >= pdestj[3])&&((pdesti[3]-dest_i == pdestj[3]-dest_j)||(pdesti[3]-dest_i == dest_j-pdestj[3]))&&(abs(source_i - pdesti[3])>= abs(source_i-dest_i))))
                {
                    std::cout<<"true";
                    std::cin>>c;
                    return true;
                }

                    //
                else
                {
                    std::cout<<"false";
                   std::cin>>c;
                   return false;
                }
        }
        else
        {

            std::cin>>c;
            std::cout<<"ret false";
            return false;
        }
            }
};

 class Queen
 {
           bishop b;
           rook r;
    public:
            bool wmove(int source_i,int source_j,int dest_i,int dest_j)
            {
                std::cout<<"queen called";
                if(b.wmove(source_i,source_j,dest_i,dest_j)||r.wmove(source_i,source_j,dest_i,dest_j))
                {
                    return true;
                }
                else
                    return false;
            }

            bool bmove(int source_i,int source_j,int dest_i,int dest_j)
            {
                if(b.wmove(source_i,source_j,dest_i,dest_j)||r.wmove(source_i,source_j,dest_i,dest_j))
                {
                    return true;
                }
                else
                    return false;
            }
 };


////////////////////////////////////////insert boundary condition for king
class king
{
public:
           bool wmove(int source_i,int source_j,int dest_i,int dest_j)
           {
               if((abs(dest_i-source_i)<=1)&&(abs(dest_j-source_j)<=1) && (matrix[dest_i][dest_j]/10!=2))
                    return true;
               else
                    return false;
           }

            bool bmove(int source_i,int source_j,int dest_i,int dest_j)
           {
               if((abs(dest_i-source_i)<=1)&&(abs(dest_j-source_j)<=1) && (matrix[dest_i][dest_j]/10!=1))
               return true;
               else
                return false;
           }
};

class board
{
private:
    rook rook1;
    knight knight1;
    bishop bishop1;
    king king1;
    Queen queen1;
    Pawn pawn1;

    public:
    bool turn=1;
    board()
    {
        int i,j;
        for(i = 0; i<8; i++ )
            for(j = 0; j<8; j++)
            {
            if(i==2 || i==3 || i==4 || i ==5)
                matrix[i][j] =0;
            else
                if(i == 1)
                matrix[i][j] = 19;
            else
                if(i == 0)
                matrix[i][j] = 11+j;
            else
                if(i == 6)
                matrix[i][j] =29;
            else
                if(i == 7)
                matrix[i][j] = 21+j;
        }
    }

     void nextTurn()
     {
         turn = !turn;
     }
////////////////////////////////////////////////////////////////////destination boundary check
     bool pmove(int source_i, int source_j, int dest_i,int dest_j)
     {
         int dpiecno = matrix[dest_i][dest_j];      //piece at destination
         int piecno = matrix[source_i][source_j];   // piece at source
         bool valid;                                //valid move flag
         if((turn == 0)&&((piecno/10)==1))          // if its blacks turn and the piece moved is black
            {
                    if((piecno/10)!=(dpiecno/10))   //if the piece at the destination is not black
                    switch(piecno%10)
                {
                    case 8:
                    case 1: valid = rook1.bmove(source_i, source_j, dest_i, dest_j);
                            break;
                    case 7:
                    case 2: valid=knight1.bmove(source_i, source_j, dest_i, dest_j);
                            break;
                    case 6:
                    case 3: valid=bishop1.bmove(source_i, source_j, dest_i, dest_j);
                            break;
                    case 4: valid=queen1.bmove(source_i, source_j, dest_i, dest_j);
                            break;
                    case 5: valid=king1.bmove(source_i, source_j, dest_i, dest_j);
                            break;
                    case 9: valid=pawn1.bmove(source_i, source_j, dest_i, dest_j);
                            break;
                }
            }

            else if((turn == 1)&&((piecno/10)==2))
            {
                        if((piecno/10)!=(dpiecno/10))
                    switch(piecno%10)
                {
                    case 8:
                    case 1: valid = rook1.wmove(source_i, source_j, dest_i, dest_j);
                            break;
                    case 7:
                    case 2: valid=knight1.wmove(source_i, source_j, dest_i, dest_j);
                            break;
                    case 6:
                    case 3: valid=bishop1.wmove(source_i, source_j, dest_i, dest_j);
                            break;
                    case 4: valid=queen1.wmove(source_i, source_j, dest_i, dest_j);
                            break;
                    case 5: valid=king1.wmove(source_i, source_j, dest_i, dest_j);
                            break;
                    case 9: valid=pawn1.wmove(source_i, source_j, dest_i, dest_j);
                            break;
                }
            }
            bool check_status;
            if(turn == 1 && valid == 1)
            {
                matrix[dest_i][dest_j] = matrix[source_i][source_j];
                matrix[source_i][source_j] = 0;
                if(matrix[dest_i][dest_j] == 25)
                {
                    wkingi = dest_i;
                    wkingj = dest_j;
                }
                check_status = iswcheck(wkingi, wkingj);
                if(check_status)
                    valid = 0;
            }
            else if(turn == 0 && valid == 1)
            {
                matrix[dest_i][dest_j] = matrix[source_i][source_j];
                matrix[source_i][source_j] = 0;
                if(matrix[dest_i][dest_j]==15)
                {
                    bkingi = dest_i;
                    bkingj = dest_j;
                }
                check_status = isbcheck(bkingi, bkingj);
                if(check_status)
                    valid = 0;
            }
            if(valid)
            {
                return 1;
            }
            else
            {
                if(check_status == 1)
                {
                    matrix[source_i][source_j] = matrix[dest_i][dest_j];
                matrix[dest_i][dest_j] = 0;
                if(matrix[source_i][source_j]==15)
                {
                    bkingi = source_i;
                    bkingj = source_j;
                }
                else if(matrix[source_i][source_j]==25)
                {
                    wkingi = source_i;
                    wkingj = source_j;
                }
                }
                gotoxy(80, 30);
                std::cout<<"invalid move";
                return 0;
     }
     }

     bool iswcheck(int source_i,int source_j)
      {
        //queen&bishop
        for(int k=1;((source_i-k)>=0)&&((source_j+k)<=7);k++)
       {
         if(matrix[source_i-k][source_j+k]==13||matrix[source_i-k][source_j+k]==16||matrix[source_i-k][source_j+k]==14)
        {
            return true;
        }
        if(matrix[source_i-k][source_j+k]!=0)
        {
            break;
        }
       }

     for(int k=1;((source_i-k)>=0)&&((source_j-k)>=0);k++)
     {
         if(matrix[source_i-k][source_j-k]==13||matrix[source_i-k][source_j-k]==16||matrix[source_i-k][source_j-k]==14)
         {
            return true;
         }
        if(matrix[source_i-k][source_j-k]!=0)
        {
            break;
        }
     }

     for(int k=1;((source_i+k)<=7)&&((source_j-k)>=0);k++)
     {
         if(matrix[source_i+k][source_j-k]==13||matrix[source_i+k][source_j-k]==16||matrix[source_i+k][source_j-k]==14)
         {
            return true;
         }
        if(matrix[source_i+k][source_j-k]!=0)
        {
            break;
        }
     }

     for(int k=1;((source_i+k)<=7)&&((source_j+k)<=70);k++)
     {
         if(matrix[source_i+k][source_j+k]==13||matrix[source_i+k][source_j+k]==16||matrix[source_i+k][source_j+k]==14)
         {
            return true;
         }
        if(matrix[source_i+k][source_j+k]!=0)
        {
        break;
        }
     }

     //rook

     for(int k=1;(source_j-k)>=0;k++)
     {
         if(matrix[source_i][source_j-k]==11||matrix[source_i][source_j-k]==18)
             {
              return true;
             }
        if(matrix[source_i][source_j-k]!=0)
        {
        break;
        }
     }
     for(int k=1;(source_j+k)<=7;k++)
     {
         if(matrix[source_i][source_j+k]==11||matrix[source_i][source_j+k]==18)
             {
              return true;
             }
        if(matrix[source_i][source_j+k]!=0)
        {
        break;
        }
     }

     for(int k=1;(source_i-k)>=0;k++)
           {
      if(matrix[source_i-k][source_j]==11||matrix[source_i-k][source_j]==18)
             {
              return true;
             }
      if(matrix[source_i-k][source_j]!=0)
        {
      break;
        }
     }
  for(int k=1;(source_i+k)<=7;k++)
     {
         if(matrix[source_i+k][source_j]==11||matrix[source_i+k][source_j]==18)
             {
              return true;
             }
        if(matrix[source_i+k][source_j]!=0)
        {
        break;
        }
     }
//pawn
if((source_i - 1>=0)&&(source_j-1>=0)&&(matrix[source_i-1][source_j-1]==19))
   {
       return true;
   }
if((source_i - 1>=0)&&(source_j+1<=7)&&(matrix[source_i-1][source_j+1]==19))
{
    return true;
}

//knight
if((source_i - 1>=0)&&(source_j+2<=7)&&((matrix[source_i-1][source_j+2]==12)||(matrix[source_i-1][source_j+2]==17)))
{
    return true;
}
if((source_i - 1>=0)&&(source_j-2>=0)&&((matrix[source_i-1][source_j-2]==12)||(matrix[source_i-1][source_j-2]==17)))
{
    return true;
}
if((source_i - 2>=0)&&(source_j+1<=7)&&((matrix[source_i-2][source_j+1]==12)||(matrix[source_i-2][source_j+1]==17)))
{
    return true;
}
if((source_i - 2>=0)&&(source_j-1>=0)&&((matrix[source_i-2][source_j-1]==12)||(matrix[source_i-2][source_j-1]==17)))
{
    return true;
}
if((source_i +1<=7)&&(source_j+2<=7)&&((matrix[source_i+1][source_j+2]==12)||(matrix[source_i+1][source_j+2]==17)))
{
    return true;
}
if((source_i + 1<=7)&&(source_j-2>=0)&&((matrix[source_i+1][source_j-2]==12)||(matrix[source_i+1][source_j-2]==17)))
{
    return true;
}
if((source_i +2<=7)&&(source_j+1<=7)&&((matrix[source_i+2][source_j+1]==12)||(matrix[source_i+2][source_j+1]==17)))
{
    return true;
}
if((source_i +2<=7)&&(source_j-1>=0)&&((matrix[source_i+2][source_j-1]==12)||(matrix[source_i+2][source_j-1]==17)))
{
    return true;
}
//king
   if((source_i-1 >=0)&&(source_j-1>=0)&&matrix[source_i-1][source_j-1]==15)
   {
       return true;}

   else if((source_i-1 >=0)&&(source_j+1<=7)&&matrix[source_i-1][source_j+1]==15)

   {return true;
   }
    else if((source_i+1<=7)&&(source_j-1>=0)&&matrix[source_i+1][source_j-1]==15)
    {
    return true;}
     else if((source_i+1<=7)&&(source_j+1<=7)&&matrix[source_i+1][source_j+1]==15)
    {
    return true;}
   else if((source_j+1>=0)&&matrix[source_i][source_j+1]==15)
   {
   return true;}
   else if((source_j+1<=7)&&matrix[source_i][source_j+1]==15)
   {
   return true;}
    else if((source_i+1<=7)&&matrix[source_i+1][source_j]==15)
   {    return true;}
    else if((source_i-1>=0)&&matrix[source_i-1][source_j]==15)
      {
           return true;
           }
    else
        return false;
}

bool isbcheck(int source_i,int source_j)
      {
        //queen&bishop
        for(int k=1;((source_i-k)>=0)&&((source_j+k)<=7);k++)
       {
         if(matrix[source_i-k][source_j+k]==23||matrix[source_i-k][source_j+k]==26||matrix[source_i-k][source_j+k]==24)
        {
            return true;
        }
        if(matrix[source_i-k][source_j+k]!=0)
        {
            break;
        }
      }


     for(int k=1;((source_i-k)>=0)&&((source_j-k)>=0);k++)
     {
         if(matrix[source_i-k][source_j-k]==23||matrix[source_i-k][source_j-k]==26||matrix[source_i-k][source_j-k]==24)
         {
            return true;
         }
        if(matrix[source_i-k][source_j-k]!=0)
        {
        break;
        }
     }

     for(int k=1;((source_i+k)<=7)&&((source_j-k)>=0);k++)
     {
         if(matrix[source_i+k][source_j-k]==23||matrix[source_i+k][source_j-k]==26||matrix[source_i+k][source_j-k]==24)
         {
            return true;
         }
        if(matrix[source_i+k][source_j-k]!=0)
        {
        break;
        }
     }

     for(int k=1;((source_i+k)<=7)&&((source_j+k)<=70);k++)
     {
         if(matrix[source_i+k][source_j+k]==23||matrix[source_i+k][source_j+k]==26||matrix[source_i+k][source_j+k]==24)
         {
            return true;
         }
        if(matrix[source_i+k][source_j+k]!=0)
        {
        break;
        }
     }

     //rooke

     for(int k=1;(source_j-k)>=0;k++)
     {
         if(matrix[source_i][source_j-k]==21||matrix[source_i][source_j-k]==28)
             {
              return true;
             }
        if(matrix[source_i][source_j-k]!=0)
        {
        break;
        }
     }
     for(int k=1;(source_j+k)<=7;k++)
     {
         if(matrix[source_i][source_j+k]==21||matrix[source_i][source_j+k]==28)
             {
              return true;
             }
        if(matrix[source_i][source_j+k]!=0)
        {
        break;
        }
     }

     for(int k=1;(source_i-k)>=0;k++)
           {
         if(matrix[source_i-k][source_j]==21||matrix[source_i-k][source_j]==28)
             {
              return true;
             }
        if(matrix[source_i-k][source_j]!=0)
        {
        break;
        }
     }
  for(int k=1;(source_i+k)<=7;k++)
     {
         if(matrix[source_i+k][source_j]==21||matrix[source_i+k][source_j]==28)
             {
              return true;
             }
        if(matrix[source_i+k][source_j]!=0)
        {
        break;
        }
     }
//pawn
if((source_i + 1<=7)&&(source_j-1>=0)&&(matrix[source_i+1][source_j-1]==29))
   {
       return true;
   }
if((source_i +1<=7)&&(source_j+1<=7)&&(matrix[source_i+1][source_j+1]==29))
{
    return true;
}

//knight
if((source_i - 1>=0)&&(source_j+2<=7)&&((matrix[source_i-1][source_j+2]==22)||(matrix[source_i-1][source_j+2]==27)))
{
    return true;
}
if((source_i - 1>=0)&&(source_j-2>=0)&&((matrix[source_i-1][source_j-2]==22)||(matrix[source_i-1][source_j-2]==27)))
{
    return true;
}
if((source_i - 2>=0)&&(source_j+1<=7)&&((matrix[source_i-2][source_j+1]==22)||(matrix[source_i-2][source_j+1]==27)))
{
    return true;
}
if((source_i - 2>=0)&&(source_j-1>=0)&&((matrix[source_i-2][source_j-1]==22)||(matrix[source_i-2][source_j-1]==27)))
{
    return true;
}
if((source_i +1<=7)&&(source_j+2<=7)&&((matrix[source_i+1][source_j+2]==22)||(matrix[source_i+1][source_j+2]==27)))
{
    return true;
}
if((source_i + 1<=7)&&(source_j-2>=0)&&((matrix[source_i+1][source_j-2]==22)||(matrix[source_i+1][source_j-2]==27)))
{
    return true;
}
if((source_i +2<=7)&&(source_j+1<=7)&&((matrix[source_i+2][source_j+1]==22)||(matrix[source_i+2][source_j+1]==27)))
{
    return true;
}
if((source_i +2<=7)&&(source_j-1>=0)&&((matrix[source_i+2][source_j-1]==22)||(matrix[source_i+2][source_j-1]==27)))
{
    return true;
}
//king
   if((source_i-1 >=0)&&(source_j-1>=0)&&matrix[source_i-1][source_j-1]==25)
   {
       return true;}

   else if((source_i-1 >=0)&&(source_j+1<=7)&&matrix[source_i-1][source_j+1]==25)

   {return true;
   }
    else if((source_i+1<=7)&&(source_j-1>=0)&&matrix[source_i+1][source_j-1]==25)
    {
    return true;}
     else if((source_i+1<=7)&&(source_j+1<=7)&&matrix[source_i+1][source_j+1]==25)
    {
    return true;}
   else if((source_j+1>=0)&&matrix[source_i][source_j+1]==25)
   {
   return true;}
   else if((source_j+1<=7)&&matrix[source_i][source_j+1]==25)
   {
   return true;}
    else if((source_i+1<=7)&&matrix[source_i+1][source_j]==25)
   {    return true;}
    else if((source_i-1>=0)&&matrix[source_i-1][source_j]==25)
      {
           return true;
           }
    else
        return false;
}

 bool iswcheckmate(int ki,int kj)
 {
     bool mateflag = true;
     int pdesti[8]={99,99,99,99,99,99,99,99};
     int pdestj[8]={99,99,99,99,99,99,99,99};
     int temp = matrix[ki-1][kj-1];
     if((ki -1 >= 0)&&(kj -1 >= 0) && pmove(ki, kj, ki-1, kj -1))
        {
        std::cout<<"entered 1";
        delay(2000);
        matrix[ki-1][kj-1] = temp;
        matrix[ki][kj] = 15;
        mateflag = false;
        }
     temp = matrix[ki-1][kj];
     if((ki -1 >= 0)&&(kj >= 0) && pmove(ki, kj, ki-1, kj))
        {
        std::cout<<"entered 2";
        delay(2000);
        matrix[ki-1][kj] = temp;
        matrix[ki][kj] = 15;
        mateflag = false;
        }
     temp = matrix[ki-1][kj+1];
     if((ki -1 >= 0)&&(kj +1 <=7) && pmove(ki, kj, ki-1, kj +1))
        {
        std::cout<<"entered 3";
        delay(2000);
        matrix[ki-1][kj+1] = temp;
        matrix[ki][kj] = 15;
        mateflag = false;
        }
     temp = matrix[ki][kj-1];
     if((ki  >= 0)&&(kj -1 >= 0) && pmove(ki, kj, ki, kj -1))
        {
            std::cout<<"entered 4";
        delay(2000);
        matrix[ki][kj-1] = temp;
        matrix[ki][kj] = 15;
        mateflag = false;
        }
     temp = matrix[ki][kj+1];
     if((ki  >= 0)&&(kj +1 <= 7) && pmove(ki, kj, ki, kj +1))
        {
        std::cout<<"entered 5";
        delay(2000);
        matrix[ki][kj+1] = temp;
        matrix[ki][kj] = 15;
        mateflag = false;
        }
     temp = matrix[ki+1][kj-1];
     if((ki +1<=7)&&(kj -1 >= 0) && pmove(ki, kj, ki+1, kj -1))
        {
        std::cout<<"entered 6";
        delay(2000);
        matrix[ki+1][kj-1] = temp;
        matrix[ki][kj] = 15;
        mateflag=false;
        }
     temp = matrix[ki+1][kj];
     if((ki +1 <=7)&&(kj >= 0) && pmove(ki, kj, ki+1, kj))
        {
        std::cout<<"entered 7";
        delay(2000);
        matrix[ki+1][kj] = temp;
        matrix[ki][kj] = 15;
        mateflag=false;
        }
     temp = matrix[ki+1][kj+1];
     if((ki+1<=7)&&(kj+1 <= 7) && pmove(ki, kj, ki+1, kj+1))
        {
        std::cout<<"entered 8";
        delay(2000);
        matrix[ki+1][kj+1] = temp;
        matrix[ki][kj] = 15;
        mateflag=false;
        }
    if(mateflag==true)
    {
        bool possible = false;
        int temp1, temp2;
        for(int g=0; g<=7 && (possible == false); g++)
            for (int h =0; h <=7;h++)
            if(matrix[g][h]/10 == 2)
            {
            temp1 = matrix[g][h];
            for(int y=0; y<=7;y++)
                for(int x= 0; x<=7; x++)
                {
                    temp2 = matrix[y][x];
                    if(pmove(g,h,y,x))
                        possible = true;
                    matrix[g][h] = temp1;
                    matrix[y][x] = temp2;
                }
            }
    mateflag=!possible;
    }
    return mateflag;
 }

 bool isbcheckmate(int ki,int kj)
 {
     bool mateflag = 1;
     int pdesti[8]={99,99,99,99,99,99,99,99};
     int pdestj[8]={99,99,99,99,99,99,99,99};

     if((ki -1 >= 0)&&(kj -1 >= 0) && matrix[ki-1][kj-1]/10!=1)
        {
        pdesti[0] = ki-1;
        pdestj[0] = kj-1;
        }
     if((ki -1 >= 0)&&(kj = 0) && matrix[ki-1][kj]/10!=1)
        {
        pdesti[1] = ki-1;
        pdestj[1] = kj ;
        }
     if((ki -1 >= 0)&&(kj+1 <= 7) && matrix[ki-1][kj+1]/10!=1)
        {
        pdesti[2] = ki-1;
        pdestj[2] = kj +1;
        }
     if((ki  >= 0)&&(kj -1 >= 0) && matrix[ki][kj-1]/10!=1)
     {
         pdesti[3] = ki;
         pdestj[3] = kj -1;
     }
     if((ki  >= 0)&& (kj +1 >= 0) && matrix[ki][kj+1]/10!=1)
     {
        pdesti[4] = ki;
        pdestj[4] = kj +1;
     }
     if((ki +1 >= 0)&&(kj >= 0) && matrix[ki+1][kj]/10!=1)
     {
        pdesti[5] = ki +1;
        pdestj[5] = kj ;
     }
     if((ki +1 >= 0)&&(kj +1>= 0) && matrix[ki+1][kj+1]/10!=1)
     {
        pdesti[6] = ki+1;
        pdestj[6] = kj+1;
     }
     if((ki +1 >= 0)&&(kj -1>= 0) && matrix[ki+1][kj-1]/10!=1)
     {
        pdesti[7] = ki+1;
        pdestj[7] = kj-1;
     }
     for(int k=0; k<=7; k++)
     {

         if(!isbcheck(ki, kj))
            {
            mateflag = 0;
            break;
            }
     }
     if(mateflag)
     {
         std::cout<<"checkmate";
     }
 }
};
