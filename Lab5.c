#include <stdio.h>
class time12
{
private:
bool pm; //true = pm, false = am
int hrs; //1 to 12
int mins; //0 to 59
public:
//YOUR CODE
void display() const //format: 11:59 p.m.
{
cout << hrs << ':';
if(mins < 10)
cout << '0'; //extra zero for "01" 
cout << mins << ' ';
string am_pm = pm ? "p.m." : "a.m.";
cout << am_pm;
}
};

class time24
{
private:
int hours; //0 to 23
int minutes; //0 to 59
int seconds; //0 to 59
public:
//YOUR CODE
void display() const //format: 23:15:01
{
if(hours < 10) cout << '0';
cout << hours << ':';
if(minutes < 10) cout << '0';
cout << minutes << ':';
if(seconds < 10) cout << '0';
cout << seconds;
}
};

int main()
{
int h, m, s;
while(true)
{ //get 24-hr time from user
cout << "Enter 24-hour time: \n";
cout << " Hours (0 to 23): "; cin >> h;
if(h > 23) //quit if hours > 23
return(1);
cout << " Minutes: "; cin >> m;
cout << " Seconds: "; cin >> s;
time24 t24(h, m, s); //make a time24
cout << "You entered: "; //display the time24
t24.display();
time12 t12 = t24; //convert time24 to time12
cout << "\n12-hour time: "; //display equivalent time12
t12.display();
cout << "\n\n";
}
return 0;
}

