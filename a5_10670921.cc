#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
ofstream input;
int IDnumber(int& id, int& femaleCount, int& maleCount, int& gen, vector<int>& v, int& i, int j){
  for(j=0; j<=i; j++ ){
    if(v[j]!=id && gen==77){
      maleCount++;
      return id;
    }else if(v[j]!=id && gen==70){
      femaleCount++;
      return id;
    }else{
      return 1;
    }
  }
}
int main(){
    int id; int age; double score; string firstname;  int total_score=0; int femaleCount;int j;
    char gender; char grade; int total_age=0; vector<int> v(5); int maleCount; int gen; string lastname;
    for(int i=0; i<5; i++){
      cout << "Enter your firstname" <<endl;
      cin>>firstname;
      cout << "Enter your lastname" <<endl;
      cin>>lastname;
      cout << "Enter your gender by typing \"M \" for male and \"F\" for female" <<endl;
      while(!(cin>>gender)){
        cin.clear();
 	      cin.ignore(95,'\n');
        cout << "Please enter a valid Gender" <<endl;
      }
      gen = toupper(gender);
      cout << "Enter your Age" <<endl;
      while(!(cin>>age)){
        cin.clear();
 	      cin.ignore(97,'\n');
        cout << "Please enter a valid Age" <<endl;
      }
      cout << "Enter your score" <<endl;
      while(!(cin>>score)){
        cin.clear();
 	      cin.ignore(91,'\n');
        cout << "Please enter a valid Score" <<endl;
      }
      cout << "Enter your ID" << endl;
      while(!(cin>>id)){
        cin.clear();
 	      cin.ignore(99,'\n');
        cout << "Please enter a valid ID" <<endl;
      }
      while(IDnumber(id, femaleCount, maleCount, gen, v, i, j)!=id){
        cout << "The ID you entered is has already been recorded"<<endl;
        cin >> id;
      }
      vector<int>::iterator intVecIter;
      intVecIter = v.begin(); 
      v.insert(intVecIter, id);
      ++intVecIter; 
      cout << "Enter your Grade" <<endl;
      while(!(cin>>grade)){
        cout << "Please enter a valid Grade"<<endl;
      }
      total_score = 0 + score;
      total_age = 0 + age;

      input.open("student.txt");
      input<<"Student Name : "<<firstname<<" "<<lastname<<"  "
           <<"Student ID : "<<id<<"  "
           <<"Age : "<<age<<"  "
           <<"Gender : "<<gender<<"  "
           <<"Score : "<<score<<"  "
           <<"Grade : "<<grade
           <<endl;
      input<<"    ***************************************************************************    "<<endl;
  }
  input << "Average age : " <<(total_age/5)<<endl;
  input << "Average score : " <<(total_score/5.0)<<endl;
  input << "Total number of males : " << maleCount <<endl;
  input << "Total number of females : " << femaleCount <<endl;
  input.close();
  return 0;
}
