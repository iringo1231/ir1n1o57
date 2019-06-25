#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#define vi vector<int>
#define el else
#define ei else if
#define rs random_shuffle
#define rd rand
#define sr srand
#define sw swap

using namespace std;

vi datain(vi tmp0) {
  for(int tmp1 = 1;tmp1 <= 40; tmp1++) {
    tmp0[tmp1 - 1] = tmp1;
  }
  
  return tmp0;
}

vi shuffle(vi tmp0) {
  sr(time(NULL));
  int tmp1 = rd() % 10001;
  
  for(int tmp2 = 0; tmp2 < tmp1;tmp2++) {
    rs(tmp0.begin(), tmp0.end());
  }
  
  return tmp0;
}

vi swap_edit(vi tmp0) {
  int me, sweet, left, front, blank1, blank2;
  
  for(int tmp1 = 0; tmp1 < 40; tmp1++) {
  	/*
    if(tmp0[tmp1] == 13) {
      me = tmp1;
    }
    
    if(tmp0[tmp1] == 36) {
      sweet = tmp1;
    }
    */
    
    if(tmp0[tmp1] == 35) {
      left = tmp1;
    }
    
    if(tmp0[tmp1] == 10) {
      front = tmp1;
    }
    
    if(tmp0[tmp1] == 19) {
      blank1 = tmp1;
    }
    
    if(tmp0[tmp1] == 40) {
      blank2 = tmp1;
    }
  }

  sr(time(NULL));
  int tmp2 = rand() % 1001;
  int tmp3 = tmp2 % 4;
  int tmp4 = tmp2 % 5;
  int pfront = tmp2 % 19;
  int pleft = tmp3 + 8 * tmp4;

  if(pleft != left) {
    sw(tmp0[pleft], tmp0[left]);
  }

  /*remove if necessary
  if(me % 2 == 0) {
    sw(tmp0[me + 1], tmp0[sweet]);
  } else {
    sw(tmp0[me - 1], tmp0[sweet]);
  }
  */

  sw(tmp0[pfront], tmp0[front]);
  sw(tmp0[32], tmp0[blank1]);
  sw(tmp0[33], tmp0[blank2]);
  return tmp0;
}

void output(vi tmp0) {
  cout << "+--+--+--+--+--+--+--+--+" << endl;

  for(int tmp1 = 1 ; tmp1 <= 40; tmp1++) {
    cout << "|";
    if(tmp1 % 8 == 0) {
      if(tmp0[tmp1 - 1] < 10) {
        cout << "0" << tmp0[tmp1 - 1] << "|" << endl;
        cout << "+--+--+--+--+--+--+--+--+" << endl;
      } el {
        cout << tmp0[tmp1 - 1] << "|" << endl;
        cout << "+--+--+--+--+--+--+--+--+" << endl;
      }
    } el {
      if(tmp0[tmp1 - 1] < 10) {
        cout << "0" << tmp0[tmp1 - 1];
      } el {
        cout << tmp0[tmp1 - 1];
      }
    }
  }
}

int main(void) {
  cout << "席替えプログラム Ver.8" << endl << endl;
  vi students(40);
  students = datain(students);
  students = shuffle(students);
  students = swap_edit(students);
  output(students);
  return 0;
}
