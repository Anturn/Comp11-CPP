//  over_avg.cpp - reads in years and pritns how many are over the avg val
//          Date - October 6, 2015
//        By - STUDENT TWO
//VARIABLES
#include<iostream>
using namespace std ;

const int SPACE  = 6;		// DO NOT CHANGE THIS LINE IN ANY WAY
const int SENTINEL = -1 ;
//INTERFACE
double average(int years[]);
int over_avg(int years[], double avg);

//FUNCTIONS
int main(){
    int years[SPACE] ;		// DO NOT CHANGE THIS LINE IN ANY WAY
    int pos = 0;
    for (int i = 0 ; i < SPACE ; i ++){
        cin >> years[i] ;}
    do {    if (pos > (SPACE-1)){
        cout << "too much input" << endl ;
        return 1 ;
    }
        else{
        cin >> years[pos] ; 
        }
        pos++ ; 
    }while(years[pos-1] != SENTINEL) ;
    double avg = average(years);
    int ovavg = over_avg(years, avg);
    if (years[0] == 0){
        cout << 0 << endl ;
    }
    else {
    cout << ovavg << endl ;
    }

    if (pos < SPACE){
        return 0 ;
    }  
}
//computes the average of the array
//returns the average as a double
double average(int years[]){
    double avg ;    
    double count = 0 ;
    double amt = 5;
    for (int i = 0 ; i < SPACE ; i ++ ){
        if (years[i] == -1){
            i = SPACE;
            }
        else{
            count += years[i] ;
        amt += 1;   // counts how many years are actually in array
        }
    }
    
    avg = count / amt ; 
    return avg;
}   
//checks how many years are over the average
//requires and array and the average
//returns an int
//int over_avg(int years[],double avg){
int over_avg(int years[],double avg){
    int years_over_avg = 0;
    
    for (int i = 0 ; i < SPACE ; i++ ) {
        if (years[i] > avg){
            years_over_avg ++ ;
        } 
    }
    return years_over_avg ;
} 
