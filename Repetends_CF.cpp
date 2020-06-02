/****************************
 *                          *
 *      CHRIS FLORES        *
 *                          *
 ***************************/
#include <iostream>
#include <string>
#include <vector>

int findRepetend(int, std::vector<short>);

int main()
{
  int remainder, dividend, divisor;
  std::vector<short> decimalDigs, rep;
  std::cout << "Enter a dividend and divisor:";
  std::cin>>dividend>>divisor;
  for(int i = 0; i < 200; i++){
  decimalDigs.push_back(dividend/divisor);
   remainder = dividend%divisor;
  dividend = 10 * remainder;
  while(remainder != 0){
  rep.push_back(remainder);
  }
  }
  std::cout<<"Here are the digits of the quotient computed: ";
  for(int i = 0; i < decimalDigs.size(); i++){
  std::cout<<decimalDigs[i];
  }
  std::cout <<"The repetend is of length: " << findRepetend(decimalDigs);
}

int findRepetend(int divisor, std::vector<short> decimalDigs){
    for(int n = 1; n < divisor; n++){
    for (int i = 0; decimalDigs[i] == decimalDigs[i + n]; i++){
        if(i >divisor * 2){
            return n;
        }
    }
}
}
