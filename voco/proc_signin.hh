/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/study-material/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
// credential
string _cred(string arg1, string arg2) {
 /* variable(s)
 [v1] temporary-folder
 [v2] PASS-text-file-content
 [v3] DB-text-file-content
 */
 string v1 = ts();
 string v2 = "";
 string v3 = cat("db").txt;
 vector<string> v2 = split(v1, "\n");
 for (int i = 0; i < v2.size(); i++)
  if (split(v2[i],",")[0] == arg1) {
   sys("7z -y -p" + quote(arg2) + " -o" + quote(tmp1) + " x " + quote(split(v2[i],",")[1] + ".zip") + " 1>/dev/null 2>/dev/null");
   w = cat(tmp1 + "/PASS").txt;
   //rm(tmp1);
   return w;
  }
 return "ACCOUNT NOT FOUND!";
}
// security-log
void _log(string arg1, string arg2, string arg3) {
 drop(ts(true) + "," + arg1 + "," + arg2 + "," + arg3, "SECURITY_LOG.csv");
}
// timed-out
void T(int arg1) {
 sleep(arg1);
 cout << mark("yellow", "[WARNING] ") + "timed-out!" << endl;
 exit(1);
}
// main
void login(bool arg1) {
 /* variable(s)
 [v1] username
 [v2] password
 */
 string v1, v2 = "";
 // op(s)
 note("Username: ");
 cin >> v1;
 if (not has(v1, "ACCOUNT-DB.txt")) {
  cout << mark("yellow", "[WARNING] ") + "account NOT FOUND!" << endl;
  _log(v1, "", "FAIL");
  exit(1);
 }
 if (has(v1, "ACCOUNT-DB.txt")) {
  note("Password: ");
  cin >> v2;
  if (v2 == _cred(v1)) {
   cout << mark("green", "[OK] ") + "access granted." << endl;
   _log(v1, v2, "OK");
   sleep(1);
   exit(0);
  }
  cout << mark("red", "[FAILED] ") + "access denied!" << endl;
  _log(v1, v2, "FAIL");
  sleep(1);
  exit(1);
 }
}
void main() {
 thread t1(T, 8);
 thread t2(login, true);
 t2.join();
 t1.join();
}
