/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/study-material/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
//#include "proc_add.hh"
//#include "proc_edit.hh"
#include "proc_help.hh"
//#include "proc_remove.hh"
//#include "proc_search.hh"
//#include "proc_travers.hh"
//#include "proc_login.hh"
#include "proc_signup.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] switch
 */
 int v1 = 0;
 // op(s)
 int e = 0;
 if (str(argv[1]) == "--help") {
  proc_help();
  exit(0);
 }
 while(true) {
  #ifdef __linux__
  sys("clear");
  #endif
  #ifdef _WIN32
  sys("cls");
  #endif
  cout <<
  "1. Sign Up""\n"
  "2. Sign In""\n"
  "0. Quit"
  << endl;
  note("[ENTRY]: ");
  cin >> v1;
  if (v1 == 1) proc_signup();
  if (v1 == 2) {cout << "\nSIGN-IN" << endl; pausee(true);}
//  if (v1 == 2) {
//   e = proc_signin();
//   if (not e) break;
//  }
  if (v1 == 0) exit(0);
 }
 if (not e)
  while(true) {
   #ifdef __linux__
   sys("clear");
   #endif
   #ifdef _WIN32
   sys("cls");
   #endif
   cout <<
   "1. add""\n"
   "2. search""\n"
   "3. enlist""\n"
   "4. remove""\n"
   "5. sign-out""\n"
   << endl;
   note("[ENTRY]: ");
   cin >> v1;
   if (v1 == 1) {cout << "\nADD" << endl; pausee();}
   if (v1 == 2) {cout << "\nSEARCH" << endl; pausee();}
   if (v1 == 3) {cout << "\nENLIST" << endl; pausee();}
   if (v1 == 4) {cout << "\nREMOVE" << endl; pausee();}
   if (v1 == 5) exit(0);
  }
}
