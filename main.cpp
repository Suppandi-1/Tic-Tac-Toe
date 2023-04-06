#include<iostream>
#include<stdio.h>
#define X 'X'
#define O 'O'
using namespace std;

class TTT {
    string name;
    char p[5][5]  ={    {'_','_','_','_','_'},
                        {'_','_','_','_','_'}, 
                        {'_','_','_','_','_'},
                        {'_','_','_','_','_'},
                        {'_','_','_','_','_'},  };
    char ar[3][3] ={    {'_','_','_'},
                        {'_','_','_'}, 
                        {'_','_','_'},  };
    int cr1 ,cr2; //cursors
    
    public:

        void bord(){
            int k=0, n=0 ,t=1;

            for(int i=0; i<=11;i++){
                if(k==3) {k=0; n++;}

                cout<<"\t\t";

                for(int j=1;j<12;j++){
                    if(i==0 && j%3 ==0){
                        //cout<<t;
                        t++;
                    }
                    if ((i%4==0 || j%4==0)&&(i!=0)) {
                        cout<<'*';
                        }
                    else if (((i==2 || i==6 || i==10)  && (j==2 || j==6 || j==10 ))) {
                        cout<< p[k][n];
                        k++;
                        }
                    else 
                        cout<<" ";
                    }
                    cout<<"\n";
                }
            cout<<endl;
            }

        void player_turn(int x , int *c1 ,int *c2){
            int t1=0, t2=0;
            if (x==1) name = "X";
            else if (x==2) name = "O";

            cout<<"Turn : \""<<name<<"\"\n";

            while(t1<1|| t1>3)
            {
                fflush(stdin);
                cout<<"\t->Enter column number: ";cin>> t1;
                if (t1>=4||t1<=0) {cout<<"**wrong input**\nTry Again! \n";}
                else break;
            }
            while(t2<1|| t2>3)
            {   fflush(stdin);
                cout<<"\t->Enter row number: ";cin>> t2;
                if (t2>=4||t2<=0) {cout<<"**wrong input**\nTry Again! \n";}
                else break;
            }
            *c1=t1-1;
            *c2=t2-1;
            cr1=*c1;
            cr2=*c2;
        }

        void Get_Mark(int x){
            if(x==1){ar[cr1][cr2]='X';}
            else if(x==2){ar[cr1][cr2]='O';}
        }

        void Set_mark(int *y){
            if (p[cr1][cr2]=='_') {
                p[cr1][cr2]=ar[cr1][cr2];
                *y=1;
                cout<<"\t *Tic-Tac-Toe by Suppandi*\n\n\n";

                }

            else {
                cout<<"\t *Tic-Tac-Toe by Suppandi*\n\n";
                cout<<"**OVER-RIDE NOT ALLOWED** try again!!\n";
                *y=0;
            } 
            
            bord();
        }

        void  Declare_win(int *k){
            string w= " :Wins\n";
            int count;
            for(int i =0; i<3;i++){
                if(p[i][0]==X && p[i][1] == X && p[i][2]==X){
                cout<<X<<w;*k=0;break;}
                else if(p[0][i]==X && p[1][i] == X && p[2][i]==X){
                cout<<X<<w;*k=0;break;}
                else if(p[0][i]==X && p[1][i+1] == X && p[2][i+2]==X){
                cout<<X<<w;*k=0;break;}
                else if(p[i][0]==X && p[i+1][1] == X && p[i+2][2]==X){
                cout<<X<<w;*k=0;break;}

                else if(p[i][0]==O && p[i][1] == O && p[i][2]==O){
                cout<<O<<w;*k=0;break;}
                else if(p[0][i]==O && p[1][i] == O && p[2][i]==O){
                cout<<O<<w;*k=0;break;}
                else if(p[0][i]==O && p[1][i+1] == O && p[2][i+2]==O){
                cout<<O<<w;*k=0;break;}
                else if(p[i][0]==O && p[i+1][1] == O && p[i+2][2]==O){
                cout<<O<<w;*k=0;break;}
                else  {*k=1;break;}
                
            }
            
            
        }

        char Exit_Game(int lim ,int o){
            int e;
            while(o>lim&& o<9){
            cout<<"for Exit Game press \'E\'\n";
            cin>>e;
            system("\r");
            break;
        }
        return e;
        }
        

} ;
int main(){
    int cr1,cr2;
    int y=1,j=1,k=0;
    TTT T;
    char e;
    system("clear");
    cout<<"\t *Tic-Tac-Toe by Suppandi*\n\n\n";
    T.bord();
    

    for (int o=0;o<9;o++){
        do{
            T.player_turn(j,&cr1,&cr2); 
            T.Get_Mark(j);
            system("clear");
            T.Set_mark(&y);
            
            T.Declare_win(&k);
            
            
        }while(y==0 && k==1);
        if(o%2==0)
            j++;
        else
            j--;

        // e=T.Exit_Game(5,o);
        // if(e=='E'||e=='e')
        if (k==0) break;
        
    }
    return 0;
}