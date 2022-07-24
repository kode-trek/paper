/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/study-material/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
int f1() {
 /* variable(s)
 [v1] username
 [v2] password
 [v3] repeated-password
 [v4] user-folder
 */
 string v1 = "";
 string v2 = "";
 string v3 = "";
 string v4 = "DIC_" + ts();
 // command(s)
 string cmd1 = "zip -y -q -r -P" + quote(v2) + " " + v4 + ".zip" + " " + v4;
 // op(s)
 cout <<
 "Creat Account""\n"
 "============="
 << endl;
 cout << "Username: ";
 cin >> v1;
 if (has(cat("ACCOUNT-DB.txt").txt, v1)) {
  cout << mark("yellow", "[WARNING] ") + "Username already exists." << endl;
  pausee(true);
  return 1;
 }
 if (has(v1, ',')) {
  cout <<
  mark("yellow", "[WARNING] ") + "Username must not contain commas."
  << endl;
  pausee(true);
  return 1;
 }
 cout << "Password: ";
 cin >> v2;
 cout << "Repeat Password: ";
 cin >> v3;
 cout << endl;
 if (quote(v2) != quote(v3)) {
  cout << mark("yellow", "[WARNING] ") + "Passwords don't match." << endl;
  pausee(true);
  return 1;
 }
 md(v4);
 drop("ACCOUNT-DB.txt", v1 + "," + v4 + "\n");
 drop(v4 + "/PASS", v2);
 cmd1 = "zip -y -q -r -P" + quote(v2) + " " + v4 + ".zip" + " " + v4;
 sys(cmd1 + " 2>/dev/null");
 rm(v4);
 cout << mark("green", "[OK] ") + "Account has been created." << endl;
 pausee(true);
 return 0;
}
void proc_signup() {
 #ifdef __linux__
 sys("clear");
 #endif
 #ifdef _WIN32
 sys("cls");
 #endif
 f1();
}
