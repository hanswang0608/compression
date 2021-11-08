#include <stdio.h>
#include <map>
#include <unordered_map>
#include <iostream>
#include <iomanip>
# include <fstream>

#include "Tree.h"
#include "Huffman.h"

int main ( int argc, char **argv );
void handle ( char file_in_name[] );

int main(int argc, char** argv){
  std::cout << "Starting" << std::endl;

  // Hashtable that stores the frequency of each character read from the input
  std::unordered_map<char, int> freq_table;

  // Hashtable that stores the variable length huffman codes for each character
  std::unordered_map<char, std::string> codes_table;

  //credit to the code below and the handle function goes to https://people.sc.fsu.edu/~jburkardt/cpp_src/hexdump/hexdump.html 
  char file_in_name[80];
  int i;

  // If the input file was not specified, get it now.
  if ( argc <= 1 ) {
    std::cout << "\n";
    std::cout << "std::hexDUMP:\n";
    std::cout << "  Please enter the name of a file to be analyzed.\n";

    std::cin.getline ( file_in_name, sizeof ( file_in_name ) );

    handle ( file_in_name );
  }

  // Otherwise, get the file(s) from the argument list. 
  else {
    for ( i = 1 ; i < argc ; ++i ) 
    {
      handle ( argv[i] );
    }
  } 

  return 0;
}

void handle ( char file_in_name[] )

{
  long int addr;
  unsigned char buffer[20];
  long int cnt;
  long int cnt2;
  std::ifstream file_in;
  long n;

  // Open the file.
  file_in.open ( file_in_name );

  if ( !file_in ) {
    std::cout << "\n";
    std::cout << "HANDLE - Fatal error!\n";
    std::cout << "  Cannot open \"" << file_in_name << "\"\n";
    return;
  }
     
  std::cout << "\n";

  // Dump the file contents.
  while ( 1 ){
    file_in.read ( ( char * ) buffer, 16 );

    cnt = file_in.gcount();

    if ( cnt <= 0 )
    {
      break;
    }

    // Print 16 data items, in pairs, in std::hexastd::decimal.
    cnt2 = 0;
    for ( n = 0; n < 16; n++ ){   
      cnt2 = cnt2 + 1;
      if ( cnt2 <= cnt ){

        //Actual hex code value
        std::cout << std::hex << std::setw(2) << std::setfill ( '0' ) << ( int ) buffer[n];
      }
      else{
        std::cout << "  ";
      }
      std::cout << " ";
    }

    std::cout << std::setfill (' ');
    std::cout << "\n";

  }

  // Close the file.
  file_in.close();

  return;
}
