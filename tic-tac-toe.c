#include <stdio.h>
#include <stdlib.h> 
// I went to TA Hours and got help from Phuong, Adrianna   

int main () {
  // declaration of variables                                                                                                                                          
  int player1;
  int player2;
  int boardChoice;
  char outputChoice;
  int xChoice;
  int yChoice;
  char ** outputArray;
  int i, j, x, y;
  
  void draw(){
      int bottomLine;
    // first dashed line                                                                                                                                               
    for (i= 0; i < ((4*boardChoice)+1); i++){
      printf("-");
    }
    printf("\n");
    //printing on location of the row and column number                                                                                                                
    for (i=0; i < boardChoice; i++){
      for(j=0; j < boardChoice; j++){
        printf("| %c ",outputArray[i][j]);
      }
       printf("|\n");
      // the bottom dashed line                                                                                                                                        
      for (bottomLine = 0; bottomLine < ((4*boardChoice)+1); bottomLine++){
        printf("-");
      }
      printf("\n");
    }
  }
  // 1 for true & 2 for false this is for when I am setting it to a variable(player1win or player2win)
  // if i am returning an int it is for 1=player 1, 2= player 2, and 3 = no one
 int checkRight(){
    int Player1win;
    int Player2win;
    for( x= 0; x < boardChoice; x++){
        Player1win = 1;
        Player2win = 1;
        for (y = 0; y < boardChoice; y++){
            if(outputArray[x][y] == ' '){
                Player1win = 2;
                Player2win = 2;
                break; 
            }
            else if(outputArray[x][y] == 'O' ){
                Player2win = 2;
            }
            else{
                Player1win = 2;
            }
        }
        if (Player1win == 1){
            return 1;
        }
        else if (Player2win == 1){
            return 2;
        }
    }
    return 3;
 }
 
int checkDown(){
    int Player1win;
    int Player2win;
    for( x= 0; x < boardChoice; x++){
        Player1win = 1;
        Player2win = 1;
        for ( y = 0; y < boardChoice; y++){
            if(outputArray[y][x] == ' '){
                Player1win = 2;
                Player2win = 2;
                break; 
            }
            else if(outputArray[y][x] == 'O' ){
                Player2win = 2;
            }
            else{
                Player1win = 2;
            }
        }
        if (Player1win == 1){
            return 1;
        }
        else if (Player2win == 1){
            return 2;
        }
    }
    return 3;
 }
 
 int checkAcross(){
    int Player1win = 1;
    int Player2win = 1;
    // first diagonal
    for ( x = 0; x < boardChoice; x++){
        if(outputArray[x][x] == ' ' ){
            Player2win = Player1win = 2;
            break;
        }
        else if (outputArray[x][x] == 'O' ){
            Player2win = 2;
        }
        else {
             Player1win = 2;
        }
    }
    
     if (Player1win == 1){
        return 1;
    }
    else if (Player2win == 1){
        return 2;
    }
// other side of diagonal
    Player1win = 1;
    Player2win = 1;
    for ( x = 0; x < boardChoice; x++){
        if(outputArray[x][boardChoice-x -1] == ' ' ){
            Player2win = Player1win = 2;
            break;
        }
        else if (outputArray[x][boardChoice-x -1] == 'O' ){
            Player2win = 2;
        }
        else {
             Player1win = 2;
        }
    }
    if (Player1win == 1){
        return 1;
    }
    else if (Player2win == 1){
        return 2;
    }
    return 3;
 }
 // if there is an space then the tie is false 
 int checkTie(){
    for(i=0; i < boardChoice; i++){
        for(j= 0; j < boardChoice; j++)
            if (outputArray[i][j] == ' '){
                return 1;
            }
        }
    return 0;
 }
// if value is bigger than the boardChoice or less than 0
// or if the space is taken up.. aka not empty
int incorrectValue(int x, int y){
        if (x >= boardChoice || y >= boardChoice || y < 0 || x < 0 ){
              return 1;
          }
          else if(outputArray[x][y] != ' '){
              return 1;
          }
    
    return 0;
 }

int gameOver(){
        if (checkRight() == 1 || checkDown() == 1 || checkAcross() == 1){
            printf("Player 1 is the winner.\n");
            return 1;
        }
        else if(checkRight() == 2 || checkDown() == 2 || checkAcross() == 2) {
            printf("Player 2 is the winner.\n");
            return 1;
        }
        else if (checkTie() == 0){
            printf("Who wins?? Nobody!\n");
            return 1;
        }
    return 0;
}
   
    // getting the input needed for the board and output                                                                                                               
    printf ("Board Size (3..N):\n");
    scanf("%d", &boardChoice);
    if (boardChoice <= 2){
        printf("Inappropriate value. Goodbye.\n");
        return 0;
    }
    printf ("Output Play (y/n):\n");
    scanf(" %c", &outputChoice);
    if (outputChoice != 'y' && outputChoice != 'n'){
        printf("Inappropriate value. Goodbye.\n");
        return 0;
    }

    printf("You entered %d %c.\n",boardChoice,outputChoice);
    printf("Starting game with %d x %d board.\n",boardChoice,boardChoice);
    printf("Each player should enter\na row and col num (eg: 2 0).\n");
    
    //allocated the space for the array, slide 29 in 2.4 PowerPoint                                                                                                    
    outputArray = (char**) malloc((boardChoice) * sizeof(char*));
    for (i = 0; i < boardChoice; i++) {
      outputArray[i] = malloc(sizeof(int) * boardChoice);
    }
    for (i=0; i < (boardChoice); i++){
      for(j=0; j < boardChoice; j++){
        outputArray[i][j] = ' ';
      }
    }
    
int choiceMade(int playerNumber, char playerSymbol){
    int invaild = 1;
    // until invaild is true you get the choices of the players(if it is invaild it does not print the values that were chosen)
    while(invaild == 1){
        printf("Player %d:\n", playerNumber);
        scanf("%d %d", &xChoice , &yChoice);
        invaild = incorrectValue(xChoice,yChoice);
        if (invaild == 1){
        printf("Incorrect value, try again.\n");
        }
        else{
        printf("Player %d entered %d %d.\n", playerNumber, xChoice, yChoice);
        }
    }
        
        outputArray[xChoice][yChoice] = playerSymbol;
        if(xChoice == -1){
            return 1;
        }
        if (outputChoice == 'y'){
            draw();
        }
        return 0;
}

    while (1){
        // sets player 1 to O and player 2 to X
        // if the gameOver function returned a 1 then that means there was a winner or tie, which results in a break 
        if (choiceMade(1,'O') == 1 || gameOver() == 1){
            break;
        }
        if ( choiceMade(2,'X')== 1 || gameOver() == 1){
            break;
        }
        
    }
    draw();
    
    // slide 9 Powerpoint 2.4 
    for (i = 0; i < boardChoice; i++) {
      free(outputArray[i]);
      outputArray[i] = NULL;
    }
    free(outputArray);                                                                                                                                              
    outputArray = NULL;                                                                                                                                             
    return 0;
    
}
