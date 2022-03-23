#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> employee;

void roster(vector<string>& res, int cf){
    vector<string> ord;
    int idx=0;

    for(int i=0;i<N;i++) ord.push_back(employee[i]);

    while(!ord.empty()){
        idx=(idx+cf-1)%ord.size();
        res.push_back(ord[idx]);
        ord.erase(ord.begin()+idx);
    }

    return;
}

int main()
{
    string name;
    vector<string> weekday, weekend;
    char wk[7][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    int cfd, cfe;

    cout<<"<--- Roster maker --->\n\n";
    cout<<"> The number of employee : ";
    cin>>N;
    for(int i=0;i<N;i++){
        getchar();
        cout<<"> Name of Employee "<<i+1<<" : ";
        cin>>name;
        employee.push_back(name);
    }
    cout<<"> Rotation Number(weekday) : ";
    cin>>cfd;
    cout<<"> Rotation Number(weekend) : ";
    cin>>cfe;

    roster(weekday,cfd);
    roster(weekend,cfe);

    cout<<"\n> -- Results --\n";
    cout<<"\n> - Weekday -\n";
    for(int i=0;i<weekday.size();i++) cout<<wk[i%5]<<" : "<<weekday[i]<<"\n";
    cout<<"\n";
    cout<<"\n> - Weekend -\n";
    for(int i=0;i<weekend.size();i++) cout<<wk[(i%2)+5]<<" : "<<weekend[i]<<"\n";
}
