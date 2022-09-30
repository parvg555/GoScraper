#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define wh(t) ll t;cin>>t;while(t--)
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define f(i,a,b) for(ll i=a;i<b;++i)

// aditya ranaut - phoenix_aditya

class project{
    public:
    string proj_name;
    int duration;
    int score;
    int best_before;
    int num_roles;
    int currently_assigned;
    float points;
    vector< pair<string, int> > roles;

    project(){
        proj_name = "";
        duration = 0;
        score = 0;
        best_before = 0;
        num_roles = 0;
        points = 0;
    }
    project(string proj, int dur, int sco, int best, int rol){
        proj_name = proj;
        duration = dur;
        score = sco;
        best_before = best;
        num_roles = rol;
        points = 1.0*((score*best)/duration);
    }

    void calc_points(){
        points = 1.0*((score*best_before)/duration);
    }
};


class dev{
    public:
    string name;
    int num_skills;
    map<string, int> dev_skills;
    dev(){
        name = "";
        num_skills = 0;
    }
    dev(string na, int n){
        name = na;
        num_skills = n;
    }
};

bool comp_project(project a, project b){
    return a.points<b.points;
}

string best_dev(vector<dev>& devs, string sname, int level, set<string> already_assigned){

    string dd = "";
    dev temp = dev();
    for(int i=0;i<devs.size();i++){
        if(dd == "" && devs[i].dev_skills[sname]>=level && !already_assigned.count(devs[i].name)){
            temp = devs[i];
            dd = devs[i].name;
        }
        else if(devs[i].dev_skills[sname]>=level && !already_assigned.count(devs[i].name) && devs[i].dev_skills[sname]<temp.dev_skills[sname]){
            // if(devs[i].dev_skills[sname]>=level){
            //     devs[i].dev_skills[sname]++;
            // }
            temp = devs[i];
            dd = temp.name;
        }
    }
    return dd;
}

void increase_score(vector<dev>& devs, string name_of_dev, string skill, int lvl){
    for(int i=0;i<devs.size();i++){
        if(devs[i].name == name_of_dev && devs[i].dev_skills[skill]==lvl){
            devs[i].dev_skills[skill]++;
        }
    }
}

struct answer{
    string proj_name;
    vector<string> assigned;
};

void solve(){
    ll c,p;
    cin>>c>>p;

    vector<dev> devs(c);
    vector<project> projects(p);

    

    string temp, name;
    int tt;

    for(int i=0;i<c;i++){
        cin>>devs[i].name;
        cin>>devs[i].num_skills;

        for(int j=0;j<devs[i].num_skills;j++){
            cin>>temp>>tt;
            devs[i].dev_skills.insert(make_pair(temp,tt));
        }
    }

    for(int i=0;i<p;i++){
        cin>>projects[i].proj_name>>projects[i].duration>>projects[i].score>>projects[i].best_before>>projects[i].num_roles;
        for(int j=0;j<projects[i].num_roles;j++){
            cin>>temp>>tt;
            projects[i].roles.push_back(make_pair(temp, tt));
        }
        projects[i].calc_points();
    }

    sort(projects.begin(), projects.end(), comp_project);

    // checking proper storing
    // for(int i=0;i<projects.size();i++){
    //     cout<<projects[i].proj_name<<" ";
    // }cout<<endl;

    // for(int i=0;i<devs.size();i++){
    //     cout<<devs[i].name<<" ";
    // }

    vector<answer> final_ans;
    // cout<<projects.size()<<endl;
    for(int i=0;i<projects.size();i++){
        // cout<<projects[i].proj_name<<"\n";

        set<string> assigned;
        bool flag = false;
        answer temp_ans;
        temp_ans.proj_name = projects[i].proj_name;
        
        for(int j=0;j<projects[i].roles.size();j++){
            string needed_skill = projects[i].roles[j].first;
            int needed_lvl = projects[i].roles[j].second;
            string temp = best_dev(devs, needed_skill, needed_lvl, assigned);
            if(temp == ""){
                flag = true;
                break;
            }
            
            increase_score(devs,temp, needed_skill, needed_lvl);
            
            assigned.insert(temp);
            temp_ans.assigned.push_back(temp);
        }
        if(flag == true){
            continue;
        }
        final_ans.push_back(temp_ans);
        // for(int j=0;j<devs.size();j++){
        //     cout<<devs[j].name<<" ";
        //     std::map<std::string, int>::iterator it = devs[j].dev_skills.begin();
        //     while( it != devs[j].dev_skills.end()){
        //         cout<<it->first<<" "<<it->second<<" "; 
        //         it++;
        //     }
        // }cout<<endl;
    }
    cout<<final_ans.size()<<endl;
    for(int i=0;i<final_ans.size();i++){
        cout<<final_ans[i].proj_name<<"\n";
        for(int j=0;j<final_ans[i].assigned.size();j++){
            cout<<final_ans[i].assigned[j]<<" ";
        }cout<<endl;
    }
}


int main(){
    fast;
    freopen("a_an_example.in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    
    
    return 0;
}