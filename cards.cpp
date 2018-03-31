// ECE 108 Lab 3 
//Jason Antao

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Initializing deck as global, so that it can be used in all functions.
int deck[52];
int countnumglobal=52;

int remainingcards(){
    //Possible error with array being called.
        int size = *(&deck + 1) - deck;
        cout << "The size of the remaining deck is: " << countnumglobal << endl;
        return countnumglobal;
}



int deckShuffler(int *arr, int n)
{
    srand ((unsigned int)time(NULL));
  
    
//    // int a[n];
//     int ind[n];
//     for (int i = 0; i < n; i++)
//         ind[i] = 0;
//     int index;
 
    for (int i = 0; i < n; i++)
    {
        int temp = deck[i];
        int index = i + rand() / ((RAND_MAX)/(51-i+1)+1);
        deck[i]=deck[index];
        deck[index] = temp;
    //     do
    //     {
    //        index = rand() % n;
    //         //cout << "Random Value: " << index << endl;
    //     }
    //     while (ind[index] != 0);
 
    //     ind[index] = 1;
    //     int temp = deck[i];

    //     deck[i] = *(arr + index);
    //     deck[index] = temp;
     }

    for (int i = 0; i < n; i++)
    {
        cout << deck[i] << " ";
    }



   

    int returncard = deck[n-1];
   // deck[n-1] = 0;

    return returncard;

  //  a[n]=0;
   // cout << "Hello"<< endl;
}

int deal(int countnum){
    int lastcard = deck[countnumglobal-1];
    //lastcard = deckShuffler(deck, (countnumglobal));
   
  //  cout << "Your random card value is: " << lastcard << endl;
   // deck[countnumglobal-1]=0;
   
    //countnum = countnum-1;
    //countnumglobal=countnum;
    //return countnum;
    countnumglobal--;
    cout << "Last Card " << lastcard << endl;
    return lastcard;
}

int bust(int limit){
    //Begin by distributing 13 cards to each person and Player A.
    //  int * array;
    // array = new int [limit];
     int sum = 0;
    // for (int j=0; j<limit; j++){
        
    //     array[j] = deal(countnumglobal);
    //     sum += array[j];
    // }
    cout << "Last Card Pull: " << (deal(countnumglobal)+sum) << endl;

    while (sum<limit){
        if ((deal(countnumglobal)+sum) < limit){
            sum = (deal(countnumglobal)+sum);
           // cout << deal(countnumglobal) << endl;
            countnumglobal++;
        }
        else if ((deal(countnumglobal)+sum) > 21){
            if (deal(countnumglobal) == 11){
                //Ace Case
                if ((1+sum)<limit){
                    sum = 1+sum;
                    countnumglobal++;
                }
                else{
                    cout << "bust" << endl;
                    sum = (deal(countnumglobal)+sum);
                    cout << "Sum: " << sum << endl;
                    
                }
            }
            else{
                cout << "bust" << endl;
                sum = (deal(countnumglobal)+sum);
                cout << "Sum: " << sum << endl;
               
            }
        }
    }

    if (sum>21){
        cout << "BUST ERROR" << endl;
         cout << "Sum " << sum << endl;
    }
    cout << "Stand: WIN" << endl;
    cout << "Sum " << sum << endl;
}

int main (){

//Creating array of cards...
//2 to 10 are numbers
//Jack, Queen, King are 10
//Ace is default to 11
    for (int i=0;i<4;i++){
        deck[i]=2;
    }
    for (int i=4;i<8;i++){
        deck[i]=3;
    }
    for (int i=8;i<12;i++){
        deck[i]=4;
    }
    for (int i=12;i<16;i++){
        deck[i]=5;
    }
    for (int i=16;i<20;i++){
        deck[i]=6;
    }
    for (int i=20;i<24;i++){
        deck[i]=7;
    }
    for (int i=24;i<28;i++){
        deck[i]=8;
    }
    for (int i=28;i<32;i++){
        deck[i]=9;
    }
    for (int i=32;i<36;i++){
        deck[i]=10;
    }
    for (int i=36;i<40;i++){
        //Jack
        deck[i]=10;
    }
    for (int i=40;i<44;i++){
        //King
        deck[i]=10;
    }
    for (int i=44;i<48;i++){
        //Queen
        deck[i]=10;
    }
    for (int i=48;i<52;i++){
        //Ace
        deck[i]=11;
    }


//  for (int i=0; i<52; i++){
//         cout << deck[i] << " " << endl;
//      }
 deckShuffler(deck, 52);

    int countavaliable = 52;
   
    for (countavaliable; countavaliable>1; countavaliable--){
    
   // deal(countavaliable);
//    int i = deckShuffler(deck, countavaliable);
//     while (i==0){
//         i=deckShuffler(deck, countavaliable);
//     }
 //int i = deal(countnumglobal);

//     cout << "Your random card value is: " << i << endl;

   // cout << countnumglobal << endl;
   // remainingcards(deal(countavaliable));
    }

   // bust(12);
    
}