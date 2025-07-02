#include<bits/stdc++.h>
using namespace std;
string n1=" ";
string n2=" ";
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};//global array
 //elements are empty space positions of grid
int row;
int column;
char token='X';// use X and O
bool stie=false;

void f1(){
  
    cout<<"   |    |   \n";
    cout<< " "<< space[0][0]<<" | "<< space[0][1] <<"  | "<<space[0][2]<<endl;
    cout<<"___|____|___\n";
    cout<<"   |    |   \n";
    cout<< " "<< space[1][0]<<" | "<< space[1][1] <<"  | "<<space[1][2]<<endl;
    cout<<"___|____|___\n";
    cout<<"   |    |   \n";
    cout<< " "<< space[2][0]<<" | "<< space[2][1] <<"  | "<<space[2][2]<<endl;
    cout<<"   |    |   \n";

    return ;
}

void f2(){
    int digit;
    if(token=='X'){
        cout<<n1<<" please enter";
        cin>>digit;

    }
    if(token=='O'){
        cout<<n2<<" please enter";
        cin>>digit;
        
    }
    if(digit==1){
        row=0;
        column=0;
    }
    if(digit==2){
        row=0;
        column=1;
    }
    if(digit==3){
        row=0;
        column=2;
    }
    if(digit==4){
        row=1;
        column=0;
    }
    if(digit==5){
        row=1;
        column=1;
    }
    if(digit==6){
        row=1;
        column=2;
    }
    if(digit==7){
        row=2;
        column=0;
    }
    if(digit==8){
        row=2;
        column=1;
    }
    if(digit==9){
        row=2;
        column=2;
    }
    else{cout<<"Invalid!!"<<endl;}

    if(token=='X'&& space[row][column]!='X' && space[row][column]!='O'){
        space[row][column]='X';
        token='O';
    }//if player 1 turn
    else if(token=='O'&& space[row][column]!='X' && space[row][column]!='O'){
        space[row][column]='O';
        token='X';
    }//player 2 turn
    else if(digit<1 || digit>9){
        cout<<"This position is already used.\n";
        f2();
    }
    f1();

}

bool f3(){//check conditions of win
    for (int i=0; i<3;i++){//checks for all three rows and column matches
        if((space[i][0]==space[i][1]&&space[i][0]==space[i][2])||(space[0][i]==space[1][i]&&space[0][i]==space[2][i])){
            return true;
        }
    }
    if(space[0][0]==space[1][1]&&space[1][1]==space[2][2]|| space[0][2]==space[1][1]&&space[1][1]==space[2][0]){
        return true;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (space[i][j]!='X'&& space[i][j]!='O'){
                return false;
            }
        }
    }
    stie=true;
    return false;
}

int main(){
     cout<<"Enter name of first player:"<<endl;
    getline(cin,n1);
    cout<<"Enter name of second player:"<<endl;
    getline(cin,n2);
    cout<<n1<<" is player 1, hence will go first \n";
    cout<<n2<<" is player 2, hence will play second \n";
    while(!f3){
        f1();
        f2();
        f3();
    }
    if (token=='X'&& stie==false){
        cout<<n2<<" wins!"<<endl;

    }
    else if(token=='O'&& stie==false){
        cout<<n1<<" wins!!"<<endl;
    }
    else{
        cout<<"It is a draw match."<<endl;
    }
    return 0;
}