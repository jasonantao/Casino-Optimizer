    // ECE 108 Lab 3 
    //Jason Antao

    #include <iostream>
    using namespace std;
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <vector>

    //Initializing deck as global, so that it can be used in all functions.
    int deck[52];
    int countnumglobal=52;

    int reset=0;

    int remainingcards(){
        //Possible error with array being called.
            int size = *(&deck + 1) - deck;
            cout << "The size of the remaining deck is: " << countnumglobal << endl;
            return countnumglobal;
    }



    int deckShuffler(int *arr, int n)
    {

        reset=0;

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

        // for (int i = 0; i < n; i++)
        // {
        //     cout << deck[i] << " ";
        // }
        // if (deck[n-1] == 0){
        //     deckShuffler(deck, n); 
        // }

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
        return lastcard;
    }

      int deal2(){
        if(countnumglobal == 0){
            deckShuffler(deck, 52);
            countnumglobal = 52;
        }
        int lastcard = deck[countnumglobal-1];
        if (lastcard >=10){
            //
            reset = reset-1;
        }
        if ((lastcard>=2)&&(lastcard<=6)){
            reset=reset+1;
        }
        //lastcard = deckShuffler(deck, (countnumglobal));
    
    //  cout << "Your random card value is: " << lastcard << endl;
    // deck[countnumglobal-1]=0;
    
        //countnum = countnum-1;
        //countnumglobal=countnum;
        //return countnum;
        countnumglobal--;
        return lastcard;
    }

    bool cardcounter(int limit){
        int dealsum=0;
        int psum=0;
        int bet=0;

        if (reset>=2){
            bet=3;
        }
        else if(reset<=-2){
            bet=0;
        }
        else{
            bet = 1;
        }

        dealsum = deal2();
        deal2();
        deal2();
        deal2();
        deal2();
        deal2();
        deal2();

        psum=deal2();
        psum+=deal2();

        if(psum==21){
            if(bet==3){
                return true;
            }
            else{
                return false;
            }
        }

        while(true){
            if(psum==21){
                if(bet==3){
                    return true;
                }
                else{
                    return false;
                }
            }
            if(psum>=limit){
                break;
            }
            if(psum>21){
                if(bet==0){
                    return true;
                }
                else{
                    return false;
                }
            }
            int card = deal2();
            if((psum != 10) && card==11){
                psum+=1;
            }
            else{
                psum+=card;
            }
            //psum+=deal2();
        }

        //Dealer Below
           while(true){
            if(dealsum==21){
                if(bet==0){
                    return true;
                }
                else{
                    return false;
                }
            }
            if(dealsum>=17){
                break;
            }
            if(dealsum>21){
                if(bet==3){
                    return true;
                }
                else{
                    return false;
                }
            }
            if(dealsum>psum){
                if(bet==0){
                    return true;
                }
                else{
                    return false;
                }
            }
            int card = deal2();
            if((dealsum != 10) && card==11){
                dealsum+=1;
            }
            else{
                dealsum+=card;
            }
            //psum+=deal2();
        }

        if((psum>dealsum)){
            if (bet ==3){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if (bet==0){
                return true;
            }
            else{
                return false;
            }
        }
    }

    int bust(int limit){
    
    int eleven = 0;
    int sum = 0;
    int currcard=0;
    vector<int> hand;

    while(sum<limit){
        if (countnumglobal<=0){
            countnumglobal = 52;
            deckShuffler(deck, 52);
        }
        currcard=deal(countnumglobal);
        

    }
    //     // for (int j=0; j<limit; j++){
            
    //     //     array[j] = deal(countnumglobal);
    //     //     sum += array[j];
    //     // }
    // // cout << "Last Card Pull: " << (deal(countnumglobal)+sum) << endl;

    //     while (sum<limit){
    //         if (countnumglobal<=0){
    //                 countnumglobal = 52;
    //             deckShuffler(deck, 52);
    //         }
    //         if ((sum>=limit)){
    //             return 1;
    //         }
    //         int i = deal(countnumglobal);
    //         if(i==11){
    //             eleven=1;
    //         }
    //         if ((sum ==11)&&(i==11)){
    //             sum = sum+1;
    //             continue;
    //         }
    //         if (((i+sum)>=limit)&&((i+sum)<=21)){
    //             return 1;
    //         }
    //     //   cout << " I Value : " << i << " CountNum : " << countnumglobal << endl;
    //         if ((i+sum) <= limit){
    //             sum = (i+sum);
    //         // cout << deal(countnumglobal) << endl;
    //         // countnumglobal++;

    //         //PUT IN NEW
    //         continue;
    //         }

    //         if ((i+sum) > limit){
    //             if (i == 11){
    //                 //Ace Case
    //                 if ((1+sum)<=limit){
    //                     sum = 1+sum;
    //                     continue;
    //                     //countnumglobal++;
    //                 }
    //                 if ((1+sum)>limit){
    //                     sum = sum+1;
    //                     if (sum<=21){
            
    //                          //    cout << "Win 1 " << sum << endl;
    //                          // cout << "Sum " << sum << endl;
    //                         return 1;
                        
    //                     }
    //                     if (sum>21){
    //                          //     cout << "Bust 1 " << sum << endl;
    //                         //   cout << "Bust 1 " << sum << endl;

    //                     if(eleven==1){
    //                         sum = sum - 10;
    //                         eleven = 0;
    //                         continue;
    //                     }

    //                     else{
    //                          return 0;
    //                     }
                            
    //                     }
    //                 }
    //             }
                
    //         if ((i+sum)<21){
    //             sum = i + sum;
    //             //   cout << "Win 2 " << sum << endl;
    //             // cout << "Sum " << sum << endl;
    //             return 1;
    //         }     
    //         if ((i+sum)>21 && sum != 11 && i != 11){
    //             // sum = i+sum;
    //             //cout << "Bust 2 " << sum << endl;
    //            // cout << "Bust 2, i " << sum << " : " << i << endl;
    //             return 0;
    //         }
    //         }

                        
    // }
    // return 1;
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
    //deckShuffler(deck, 52);

        int countavaliable = 52;
    deckShuffler(deck, 52);
        for (countavaliable; countavaliable>1; countavaliable--){
        
    // deal(countavaliable);
    //    int i = deckShuffler(deck, countavaliable);
    //     while (i==0){
    //         i=deckShuffler(deck, countavaliable);
    //     }
    //int i = deal(countnumglobal);
    // cout << "Your random card value is: " << i << endl;

    // cout << countnumglobal << endl;
    // remainingcards(deal(countavaliable));
        }
        float count10=0;
        float count11=0;
        float count12=0;
        float count13=0;
        float count14=0;
        float count15=0;
            float count16=0;
            float count17=0;
            float count18=0;
            float count19=0;
                float count20=0;
        float size = 100000;

         bust(10);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            bust(10);
            if (bust(10)==0){
                count10++;
            }
           
        }
         cout << "Fractional Value 10: " << (count10/size) << endl;
        bust(11);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            bust(11);
            if (bust(11)==0){
                count11++;
            }
        }
        cout << "Fractional Value 11: " << (count11/size) << endl;
        bust(12);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            bust(12);
            if (bust(12)==0){
                count12++;
            }
           
        }
        cout << "Fractional Value 12: " << (count12/size) << endl;
       // return 0;
        bust(13);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            
            bust(13);
            if (bust(13)==0){
                count13++;
            }
           
        }
        cout << "Fractional Value 13: " << (count13/size) << endl;
    
        bust(14);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            bust(14);
            if (bust(14)==0){
                count14++;
            }
        }
        cout << "Fractional Value 14: " << (count14/size) << endl;

        
        bust(15);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            bust(15);
            if (bust(15)==0){
                count15++;
            }
        }
        cout << "Fractional Value 15: " << (count15/size) << endl;

        
        bust(16);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            bust(16);
            if (bust(16)==0){
                count16++;
            }
        }
        cout << "Fractional Value 16: " << (count16/size) << endl;

        
        bust(17);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            bust(17);
            if (bust(17)==0){
                count17++;
            }
        }
        cout << "Fractional Value 17: " << (count17/size) << endl;

    bust(18);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            bust(18);
            if (bust(18)==0){
                count18++;
            }
        }
        cout << "Fractional Value 18: " << (count18/size) << endl;
        
        bust(19);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            bust(19);
            if (bust(19)==0){
                count19++;
            }
        }
        cout << "Fractional Value 19: " << (count19/size) << endl;

        bust(20);
        for (int j=0;j<size; j++){
            //deckShuffler(deck, 52);
            bust(20);
            if (bust(20)==0){
                count20++;
            }
        }
        cout << "Fractional Value 20: " << (count20/size) << endl;


    float pwin=0;
     for(int i = 0;i<10000;i++){
         if((cardcounter(18)==true)){
             pwin++;
         }
     }
     cout << "Fractional Win for Card Counting: " <<  (pwin/10000.0) << endl;
    }