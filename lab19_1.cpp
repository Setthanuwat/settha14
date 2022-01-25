#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>


using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades)
{
    ifstream data(filename);
    string s ;
    char format[] ="%[^:]: %d %d %d";
    int a;
    int b;
    int c;
    int score;
    char name[23];
    while (getline(data,s))
    {
        const char* cs = s.c_str();
       sscanf(cs,format,name,&a,&b,&c);
        score = a+b+c;
        scores.push_back(score);
        names.push_back(name);
        grades.push_back(score2grade(score));
    }
}

void getCommand(string &command,string &key)
{
    string s;
    char a[20], b[20];
    cout << "Please input your command: ";
    getline(cin,s);
    const char *text = s.c_str();
    char format[] = "%s %[^:] ";
    sscanf(text,format,&a,&b);
    command = a;
    key = b;
    

}

void searchName(vector<string>names, vector<int>scores, vector<char>grades, string key)
{
    ifstream data("name_score.txt");
    string s;
    string M;
    char format[] ="%[^:]: %d %d %d";
    int a,b,c;
    int i = 0;
    int x = 0;
    char name[23];
    cout << "---------------------------------\n";
    while (getline(data,s))
    {
        
        const char* cs = s.c_str();
       sscanf(cs,format,name,&a,&b,&c);
        M = toUpperStr(name);
        if(key == M)
        {
            cout << names[i] << "'s score = " <<scores[i] << "\n";
             cout << names[i] <<"'s grade = "<< grades[i] << "\n";
             x++;
        }
        i++;
    }
    if(x == 0)
    {  
            cout << "Cannot found." << endl;
    }
        cout << "---------------------------------\n";
}

void searchGrade(vector<string>names, vector<int>scores, vector<char>grades, string key)
{
    ifstream data("name_score.txt");
    string s;
    string M;
    char format[] ="%[^:]: %d %d %d";
    int a,b,c;
    int i = 0;
    int score;
    char grade;
    char name[23];
    cout << "---------------------------------\n";
    while (getline(data,s))
    {
        
        const char* cs = s.c_str();
       sscanf(cs,format,name,&a,&b,&c);
        score = a+b+c;
        grade = score2grade(score);
        if(key == "A" && grade == 'A')
            {
                cout << names[i] << " " <<"("<<scores[i] << ")" <<  "\n";
            }
        if(key == "B" && grade == 'B')
            {
                cout << names[i] << " " <<"("<<scores[i] << ")" <<  "\n";
            }
        if(key == "C" && grade == 'C')
            {
                cout << names[i] << " " <<"("<<scores[i] << ")" <<  "\n";
            }
        if(key == "D" && grade == 'D')
            {
                cout << names[i] << " " <<"("<<scores[i] << ")" <<  "\n";
            }
        if(key == "F" && grade == 'F')
            {
                cout << names[i] << " " <<"("<<scores[i] << ")" <<  "\n";
            } 
            i++;         
    }
    cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);

    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
