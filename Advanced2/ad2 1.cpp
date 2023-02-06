#include <iostream>

enum suit_t { CLUBS =0 , DIAMONDS =1 , HEARTS =2 , SPADES =3};

void print_suit ( const suit_t suit ) {
 const char * names [] = {" Clubs ", " Diamonds ",
 " Hearts ", " Spades "};
 std::cout << names[suit];
 }

int main(){
     suit_t card;
     card=DIAMONDS;
 print_suit(card);
 return 0;
 }