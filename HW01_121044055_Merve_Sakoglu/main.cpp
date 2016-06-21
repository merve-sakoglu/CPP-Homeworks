/************************************/
*	CSE 241 HW01                *
*	MERVE SAKOGLU               *
*	121044055                   *
*	                            *
*                                   *
/************************************/

#include <iostream>

using namespace std;

int const MAXSIZE=20;

void initialBoard(char board[][MAXSIZE],int size);
int translateLetter(char letter);
int makeMove(char board[][MAXSIZE],int number,int letterNumber,char X,char O);
int player(char board[][MAXSIZE],int row,int col);
void computerMove(char board[][MAXSIZE]);
int finished(char board[MAXSIZE][MAXSIZE]);
void winner(char board[MAXSIZE][MAXSIZE]);
void printBoard(char board[][MAXSIZE]);

int main(){
	
	int size,letterNumber;
	char board[MAXSIZE][MAXSIZE];
	char letter;
	int number,temp=0;
	int play,finish;
	
	cout << "Tahta boyutunu giriniz\n" ;
	cin >> size;

	if((size%2) != 0){

        cout << "INVALID VALUE!!!\n" ;
		
	while((size%2) != 0){
	
		cout << "Tahta boyutunu giriniz\n" ;
		cin >> size;
	}
        }
	initialBoard( board, size);
	
	do{
	
		 cout << "Hangi hamleyi yapmak istiyorsunuz\n";
	         cin >> number;
	         cin >> letter;
        	 letterNumber = translateLetter(letter);
         	 makeMove(board, (number+(MAXSIZE-size)/2)-1,(letterNumber+(MAXSIZE-size)/2)-1,'X','O');
    		 printBoard( board);
	         computerMove( board);
         	 printBoard( board);
         	 finish = finished( board);
	   	 winner( board);
	   	 
        }while(finish==1); /*tahtada bos yer oldugu surece oynar*/
   
	return 0;
}
/*Tahtanin ilk halini cizdirir*/
void initialBoard(char board[][MAXSIZE],int size){
	
	int i,j,k=0;
	
	for(i=0 ; i<MAXSIZE ; i++){
	
		for(j=0 ; j<MAXSIZE; j++){
		
			board[i][j] = ' ';
		}
		cout << "\n";
	}

	for(i=((MAXSIZE-size)/2) ; i<(MAXSIZE+size)/2 ; i++){
	
		for(j=((MAXSIZE-size)/2) ;j<(MAXSIZE+size)/2 ; j++){
			
			board[i][j] = '.';
		}
		cout << endl;
	}
	
	board[9][9] = 'X';
	board[10][9] = 'O';
	board[9][10] = 'O';
	board[10][10] = 'X';
	
	for(i=0 ; i<MAXSIZE ; i++){
		
		for(j=0 ; j<MAXSIZE ; j++){
			
			 cout << board[i][j];
		}
		cout << endl;
	}
		
}
/*Consoldan girilen harfleri int degere cevirir*/
int translateLetter(char letter){
	
	int letterNumber;
	
	letterNumber = letter - 'A'+1;

	return letterNumber;
}
/*Girilmek istenilen noktanin sekiz kosesi kontrol edilir ve iki aynı harf
  arasi karakterler degistirilir*/	
int makeMove(char board[][MAXSIZE],int number,int letterNumber,char X,char O){
	
	int count=0,i,j;
	int temp = 0;
	
	
	if(board[number][letterNumber] == '.'){
		
		if(board[number-1][letterNumber-1] == X){
			
			i = number-1;
			j = letterNumber-1;
			/*arada kac karakter oldugunu sayar*/
			for(count=0 ; board[i][j] == X ; ++count){
			
				--i;
				--j;
			}
			/*o harften sonra count kadar ilerler ve ucunda ayni harf olup 
			 olmadıgını kontrol eder.Ayni ise degistirir*/
			 
			if(board[number-1-count][letterNumber-1-count] == O){
				
				temp = count;
				while(count != 0){
					
					board[number-1][letterNumber-1] = O;
					board[number][letterNumber] = O;
					--count;
					--number;
					--letterNumber;
				}
			}
			
		}if(board[number-1][letterNumber] == X){
			
			i= 0;
			i=number-1;
			while(board[i][letterNumber] == X){
				
				++count;
				--i;
			}
			if(board[number-1-count][letterNumber] == O){
				
				temp = temp + count;
				i=number-1 ;
				while(count != 0 ){
					
					board[i][letterNumber] = O;
					board[number][letterNumber] = O;
					--count;
					--i;
					
				}
			}
		}if(board[number-1][letterNumber+1] == X){
			
			i = 0; i = number-1;
			j = 0; j = letterNumber+1;
			for(count=0 ; board[i][j] == X ; ++count){
			
				--i;
				++j;
			}
			
			if(board[number-1-count][letterNumber+1+count] == O){
				
				temp = temp + count;
				while(count != 0){
					
					board[number-1][letterNumber+1] = O;
					board[number][letterNumber] = O;
					--count;
					--number;
					++letterNumber;
				}
			}
		}if(board[number][letterNumber-1] == X){
			
			j = 0; j = letterNumber-1;
			for(count=0 ; board[number][j] == X ; ++count){
			
				--j;
			}
			
			if(board[number][letterNumber-1-count] == O){
				
				temp = temp + count;
				while(count != 0){
					
					board[number][letterNumber-1] = O;
					board[number][letterNumber] = O;
					--count;
					--letterNumber;
				}
			}
		}if(board[number][letterNumber+1] == X){
			
			j = 0; j = letterNumber+1;
			for(count=0 ; board[number][j] == X ; ++count){
			
				++j;
			}
			
			if(board[number][letterNumber+1+count] == O){
				
				temp = temp + count;
				while(count != 0){
					
					board[number][letterNumber+1] = O;
					board[number][letterNumber] = O;
					--count;
					++letterNumber;
				}
			}
		}if(board[number+1][letterNumber-1] == X){
			
			i = 0; i = number+1;
			j = 0; j = letterNumber-1;
			for(count=0 ; board[i][j] == X ; ++count){
				
				++i;
				--j;
			}
			
			if(board[number+1+count][letterNumber-1-count] == O){
				
				temp = temp + count;
				while(count != 0){
					
					board[number+1][letterNumber-1] = O;
					board[number][letterNumber] = O;
					--count;
					++number;
					--letterNumber;
				}
			}
		}if(board[number+1][letterNumber] == X){
		
			i = 0; i = number+1;
			for(count=0 ; board[i][letterNumber] == X ; ++count){
				
				++i;
			}
			
			if(board[number+1+count][letterNumber] == O){
				
				temp = temp + count;
				while(count != 0){
					
					board[number+1][letterNumber] = O;
					board[number][letterNumber] = O;
					--count;
					++number;
				}
			}
		}if(board[number+1][letterNumber+1] == X){
			
			i = 0; i = number+1;
			j = 0; j = letterNumber+1;
			for(count=0 ; board[i][j] == X ; ++count){
				
				++i;
				++j;
			}
			
			if(board[number+1+count][letterNumber+1+count] == O){
				
				temp = temp + count;
				while(count != 0){
					
					board[number+1][letterNumber+1] = O;
					board[number][letterNumber] = O;
					--count;
					++number;
					++letterNumber;
				}
			}
		}
	
	}else{
	
		cout << "Move is not legal\n" << endl;
	}
    /*Kac harf degistirdigini return eder*/
	return temp;
}
/*Girilen noktaya oynayıp oynamadigini kontrol eder.Oynuyorsa 1 oynamiyorsa 
  0 return eder*/
int player(char board[][MAXSIZE],int row,int col){
	
	int i=0,j=0;
	int play,count=0;
	
	if(board[row][col] == '.'){
		
		if(board[row-1][col-1] == 'O'){
			
			i = row-1;
			j = col-1;
			for(count=0 ; board[i][j] == 'O' ; ++count){
			
				--i;
				--j;
			}
			if(board[row-1-count][col-1-count] == 'X'){
				
				play = 1;
				
			}
		}if(board[row-1][col] == 'O'){
			
			i= 0;
			i=row-1;
			while(board[i][col] == 'O'){
				
				++count;
				--i;
			}
			if(board[row-1-count][col] == 'X'){
				
				play = 1;
			}
		}if(board[row-1][col+1] == 'O'){
			
			i = 0; i = row-1;
			j = 0; j = col+1;
			for(count=0 ; board[i][j] == 'O' ; ++count){
			
				--i;
				++j;
			}
			
			if(board[row-1-count][col+1+count] == 'X'){
				
				play = 1;
				
			}
		}if(board[row][col-1] == 'O'){
			
			j = 0; j = col-1;
			for(count=0 ; board[row][j] == 'O' ; ++count){
			
				--j;
			}
			
			if(board[row][col-1-count] == 'X'){
				
				play = 1;
			}
		}if(board[row][col+1] == 'O'){
			
			j = 0; j = col+1;
			for(count=0 ; board[row][j] == 'O' ; ++count){
			
				++j;
			}
			
			if(board[row][col+1+count] == 'X'){
				
				play = 1;
			}
		}if(board[row+1][col-1] == 'O'){
			
			i = 0; i = row+1;
			j = 0; j = col-1;
			for(count=0 ; board[i][j] == 'O' ; ++count){
				
				++i;
				--j;
			}
			if(board[row+1+count][col-1-count] == 'X'){
				
				play = 1;
			}
		}if(board[row+1][col] == 'O'){
			
			i = 0; i = row+1;
			for(count=0 ; board[i][col] == 'O' ; ++count){
				
				++i;
			}
			
			if(board[row+1+count][col] == 'X'){
				
				play = 1;
			}
		}if(board[row+1][col+1] == 'O'){
			
			i = 0; i = row+1;
			j = 0; j = col+1;
			for(count=0 ; board[i][j] == 'O' ; ++count){
				
				++i;
				++j;
			}
			
			if(board[row+1+count][col+1+count] == 'X'){
				
				play = 1;
			}
	   }

  }else{
		
		play = 0;
  }
  
  return play;
}	
/*COmputeri oynatir*/
void computerMove(char board[][MAXSIZE]){
	
	int row=0,col=0;
	int temp1=0, temp2=0;
	int play,score=0,newscore=0;
	char temp_board[MAXSIZE][MAXSIZE]; 
	
	for(int i=0 ; i<20 ; ++i){
	
		for(int j=0 ; j<20 ; ++j){
			
			
			for(int x = 0; x < 20; x++){
        		 for(int y = 0; y < 20; y++){
        		 	/*Arrayi başka bir arraye kopyalar*/
           			temp_board[x][y] = board[x][y];
           		 }
           }
           
			play = player(temp_board,i,j);
			/*OYnayabilecegi bir yerse kac tas degistirdigini sayar*/
			if(play == 1){
			
				score = makeMove( temp_board,i,j,'O','X');
			}
			if(score > newscore){
				
				newscore = score;
				temp1 = i;
				i = row;
				row = temp1;
				
				temp2 = j;
				j = col;
				col = temp2;
			}
		
		}
	
	}
	/*En fazla score daki row ve col degerleriyle computeri oynatir*/
	makeMove(board,row,col,'O','X');

}
/*Tahtada oynanacak yer olup olmadigini kontrol eder.'.' olup olmadigini 
  kontrol eder*/
int finished(char board[MAXSIZE][MAXSIZE]){ 
  	int i,j,temp=1;
  
   for(i=1;i<=20;i++){
   
      for(j=1;j<=20;j++){
      
		    if(board[i][j] == '.'){
		    	
		     	return 1;
      		}
     }    
   }
   
   return 0;
}
/*Tahtadaki computer ve user degerleri saydirip skorlari yazdirir*/
void winner(char board[MAXSIZE][MAXSIZE]){
   int user=0, computer=0;
   
   for(int i=0 ; i<MAXSIZE ; ++i){
   		for(int j=0 ; j<MAXSIZE ; ++j){
   			
   			if(board[i][j]=='X'){
          		 computer++;
            }else if(board[i][j]=='O'){
           		 user++;
            }
   		}
   
   }
   cout << "Computer:" << computer <<"   ";
   cout << "User:" << user <<"   \n";
   
   /*
   if(computer > user){
   
   		cout << "Computer wins :" << computer;
   }else{
   
  	    cout << "User wins :" << user;
   }
*/
}
/*Arrayi ekrana basar*/
void printBoard(char board[][MAXSIZE]){
	
	for(int i=0 ; i<MAXSIZE ; i++){
		
		for(int j=0 ; j<MAXSIZE ; j++){
			
			 cout << board[i][j];
		}
		cout << endl;
	}
}
