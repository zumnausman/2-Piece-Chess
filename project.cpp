#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

//--------------initializing functions and variables-------------
void start();
void queen(int r, int c);
void king(int r, int c);
int const size=8;
char array[size][size];

int main()
{
	start();        //calls start function
	return 0;
}

void start()
{
    int kingrow, kingcolumn ,queenrow, queencolumn,choice2,choice0,lastchoice,n, m;
    do
    {

        cout<<"Press 1 to play your next move\nPress 2 to play save the king\nPress anything else to exit=\n";      //prints 1st menu of plays
        cin>>choice0;

        switch (choice0)
        {
        case 1:
        {

            int choice1;
            cout<<"Press 1 to choose king and 2 bishops\nPress 2 to choose king and 2 rocks\nPress 3 to choose king and 2 knights\nPress 4 to choose king and 1 queen\n";       //prints menu of choices
            cin>>choice1;
            while (choice1 != 4)    //only king and queen is assigned to me
            {
                cout<<"This program does not provide functionality for the given choice. Enter choice again= ";
                cin>>choice1;
            }
            //---------asks for initial positions of both pieces---------
            cout<<"\nINITIAL Postion of king\n\nEnter row of choice= ";
            cin>>kingrow;
            while (kingrow > 8 || kingrow < 1)
            {
                cout<<"This position is not available in the grid. Enter row again= ";
                cin>>kingrow;
            }
            cout<<"\nEnter column of choice= ";
            cin>>kingcolumn;
            while (kingcolumn > 8 || kingcolumn < 1)
            {
                cout<<"This position is not available in the grid. Enter column again= ";
                cin>>kingcolumn;
            }
            cout<<"\nINITIAL Postion of queen\n\nEnter row of choice= ";
            cin>>queenrow;
            while (queenrow > 8 || queenrow < 1)
            {
                cout<<"This position is not available in the grid. Enter row again= ";
                cin>>queenrow;
            }
            cout<<"\nEnter column of choice= ";
            cin>>queencolumn;
            while (queencolumn > 8 || queencolumn < 1)
            {
                cout<<"This position is not available in the grid. Enter column again= ";
                cin>>queencolumn;
            }
            //--------checks that initial position of king and queen should be different-------
            while (queenrow==kingrow)
            {
                cout<<"King and queen can not have same initial position. Enter row of queen again= ";
                cin>>queenrow;
            }
             while (queencolumn==kingcolumn)
            {
                cout<<"King and queen can not have same initial position. Enter column of queen again= ";
                cin>>queencolumn;
            }
            //assigns character to pieces
            array[kingrow][kingcolumn] = 'K';
            array[queenrow][queencolumn] = 'Q';
            //----------prints grid---------
            cout<<endl;
            cout<<"\t";
            for (int i = 1; i<=8; i++ )
            {
                cout<<i<<"\t";
            }
            cout<<endl;
            for (int j=1; j<=8 ; j++)
            {
                cout<<j;
                for (int k = 1; k<=8; k++)
                {
                    cout<<"\t"<<array[j][k];
                }
                cout<<endl<<endl;
            }

            cout<<"\nPress 1 to choose king\nPress 2 to choose queen\n";        //asks user to choose a piece
            cin>>choice2;

            while (choice2 < 1 || choice2 > 2)
            {
                cout<<"This program does not provide functionality for the given choice. Enter choice again= ";
                cin>>choice2;
            }
            do
			{
            switch (choice2)
            {
            case 1:
                cout<<endl<<"Next possible positions are shown by +";
                king(kingrow , kingcolumn);         //calls function of king
                n= kingrow;
                m=kingcolumn;
                cout<<"Enter the new row and column for king :"<<endl;      //asks for new position of piece
                cin>>kingrow>>kingcolumn;
                while (kingrow <n-1 || kingrow>n+1)     //checks if move is possible
                {
                   cout<<"This move is not possible. Enter king row again= ";
                   cin>>kingrow;
                }
                while (kingcolumn <m-1 || kingcolumn>m+1)        //checks if move is possible
                {
                   cout<<"This move is not possible. Enter king column again= ";
                   cin>>kingcolumn;
                }
            break;
            case 2:
                 cout<<endl<<"Next possible positions are shown by +";
                 queen(queenrow , queencolumn);             //calls function of queen

                 cout<<endl<<"Enter the new row and column for queen :"<<endl;          //asks for new position of piece
                 cin>>queenrow>>queencolumn;
                 n= queenrow;
                 m=queencolumn;
                 while (queenrow <n-1 || queenrow>n+1)     //checks if move is possible
                {
                   cout<<"This move is not possible. Enter queen row again= ";
                   cin>>queenrow;
                }
                while (queencolumn <m-1 || queencolumn>m+1)        //checks if move is possible
                {
                   cout<<"This move is not possible. Enter queen column again= ";
                   cin>>queencolumn;
                }
            break;
            }
            cout<<"If u want to exit press 0 else click any button"<<endl;      //asks user if she wants to move or quit
            cin>>lastchoice;
        	}
        	while(lastchoice!=0);
        }

        }
    }
    while (choice0 == 1 || choice0 == 2);
}
 void king(int r, int c)        //function of king
{
            cout<<endl;
            cout<<"\t";
            for (int i = 1; i<=8; i++ )
            {
                cout<<i<<"\t";
            }
            cout<<endl;
            for (int j=1; j<=8 ; j++)
            {
                cout<<endl;
                cout<<j<<"\t";
                for (int k = 1; k<=8; k++)
                {
                    //checks for all possible moves of king
                    if (r==j && c==k)
                    {
                        cout<<'K'<<"\t";
                    }
                        else if (j==r-1 && k==c-1)
                        {
                            cout<<'+'<<"\t";
                        }
                            else if (j==r-1 && k==c)
                            {
                                cout<<'+'<<"\t";
                            }
                                else if (j==r-1 && k==c+1)
                                {
                                    cout<<'+'<<"\t";
                                }
                                    else if (j==r && k==c-1)
                                    {
                                        cout<<'+'<<"\t";
                                    }
                                        else if (j==r && k==c+1)
                                        {
                                            cout<<'+'<<"\t";
                                        }
                                            else if (j==r+1 && k==c-1)
                                            {
                                                cout<<'+'<<"\t";
                                            }
                                                else if (j==r+1 && k==c)
                                                {
                                                    cout<<'+'<<"\t";
                                                }
                                                    else if (j==r+1 && k==c+1)
                                                    {
                                                        cout<<'+'<<"\t";
                                                    }
                                                        else
                                                        {
                                                            cout << "\t";
                                                        }
                }
                cout<<endl<<endl;
            }
}
void queen(int r, int c)
{
	 cout<<endl;
            cout<<"\t";
            //-------------prints grid for queen----------
            for (int i = 1; i<=8; i++ )
            {
                cout<<i<<"\t";
            }
            for (int j=1; j<=8 ; j++)
            {
                cout<<endl<<endl;
                cout<<j<<"\t";
                for (int k = 1; k<=8; k++)
                {
                    for(int x=1; x<=8; x++)         //for diagonal moves
                    {
                        if (((j==r-x && k==c+x ) || (j==r-x && k==c-x )) &&(k>=1 && k<=8) && (j>=1 && j<=8))
                        {
                            cout<<'+';
                        }
                            else if (((j==r+x && k==c-x) || (j==r+x && k==c+x )) &&(k>=1 && k<=8) && (j>=1 && j<=8))
                            {
                                cout<<'+';
                            }

                    }

                              if (j==r && k==c)     //for placement of queen
                            {
                                cout<<'Q'<<"\t";
                            }
                                else if(j==r && (k>=1 && k<=8))     //for horizontal line moves
                                {
                                    cout<<'+'<<"\t";
                                }
                                     else if (j != r && k != c)     //for empty spaces
                                    {
                                        cout<<" \t";
                                    }
                                         else if (k==c && (j>=1 && j<=8))       //for vertical line moves
                                        {
                                            cout<<'+'<<"\t";
                                        }


        		}

    		}

}


