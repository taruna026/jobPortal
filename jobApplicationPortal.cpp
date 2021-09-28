#include<iostream>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
 
using namespace std;

class company{

    public:
    int id;
    char name[40];
    char description[40]; 
    void addCompanyDetails();
    void showAllCompanies();
    void updateCompanyDetails();
};

company companies[1000];
int n=0;
map<string, vector<int> > jobLocationIdMap;
map<string, vector<int> > jobSkillIdMap;

class jobPostion{
    public:
    int id;
    char title[40];
    set<string> skills;
    char description[100];
    char location[40];
    company companyDetails;

    void addJobPosting();
    void searchJobByLocation();
    void searchJobById();
    void searchJobBySkills();
    void showAllJobs();
    void updateJobPosition();
};

class jobAplicant{
    public:
    char name[40];
    char description[100];
    jobPostion jobApplied;

    void applyForAJob();
};

jobAplicant jobApplications[1000];
int k=0;

jobPostion jobs[1000];
int m=0;

void showCompanyData(int k)
{
	cout<<"\nID Number: "<<companies[k].id;
	cout<<"\nName: "<<companies[k].name;
	cout<<"\nDescription: "<<companies[k].description;
}

void addCompanyDetails(){

    cout<<"\n\nEnter Company's id: ";
	cin>>companies[n].id;
	cout<<"\n\nEnter Company's Name: ";
	cin.ignore();
	cin.getline(companies[n].name,50);
	cout<<"\n\nEnter Company's Description: ";
	cin.ignore();
	cin.getline(companies[n].description,50);
    n++;
    cout<<"\n\nCompany Data Has Been Created ";
	cin.ignore();
	cin.get();   
}

void showAllCompanies(){
    cout << "----------------Companies LIST-------------------";
    for(int i=0; i<n; i++){
        cout << "Id: " << companies[i].id << " " << endl;
        cout << "Name: " << companies[i].name << " " << endl;
        cout << "Description: " << companies[i].description << " " << endl;
    }
	cin.ignore();
	cin.get();
}

void addJobPosting(){
    cout<<"\nEnter the Job Id ";
	cin>>jobs[m].id;
	cout<<"\n\nEnter Job's Title: ";
	cin.ignore();
	cin.getline(jobs[m].title,50);
	cout<<"\n\nEnter Job's Description: ";
	cin.ignore();
	cin.getline(jobs[m].description,50);
    string skill;
    cout<<"\n\nEnter Comma Seperated Job Skills That you want to search for: ";
	cin>>skill;
    stringstream ss(skill);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        jobs[m].skills.insert(substr);
        jobSkillIdMap[substr].push_back(jobs[m].id);
    }
    cout<<"\n\nEnter Job Location: ";
	cin.ignore();
	cin.getline(jobs[m].location,50);
    jobLocationIdMap[jobs[m].location].push_back(jobs[m].id);
    cout<<"\nEnter the Company Id ";
	cin>>jobs[m].companyDetails.id;
    m++;
    cout<<"\n\nJob Data Has Been Created ";
    cin.ignore();
	cin.get();  
}

void showAllJobs(){
    for(int i=0; i<m; i++){
        cout << jobs[i].id << endl;
        cout << jobs[i].location << endl;
        for(auto j:jobs[i].skills){
                cout << j << endl;
            }
    }
    cin.ignore();
	cin.get();  
}

void searchJobByLocation(){
    char jobLocation[50];
    cout << "Enter JOb Location" << endl;
    cin.ignore();
    cin.getline(jobLocation,50);
    cout << "Job Ids with Location " << jobLocation << endl;
    for(int i=0; i<jobLocationIdMap[jobLocation].size(); i++){
        cout << jobLocationIdMap[jobLocation][i] << endl;
    }
    cin.ignore();
	cin.get();  
}

void searchJobById(){
    int jobId;
    cout << "Enter JOb Id" << endl;
    cin >> jobId;

    for(int i=0; i<m; i++){
        if(jobs[i].id == jobId){
            cout << "Details Of Job With this Job id " << jobId << endl;
            cout << jobs[i].title << endl;
            cout << jobs[i].location << endl;
            for(auto i:jobs[i].skills){
                cout << i << endl;
            }
        }
    }
    cin.ignore();
	cin.get();  
}

void searchJobBySkills(){
    string skill;
    cout<<"\n\nEnter Comma Seperated Job Skills That you want to search for: ";
	cin.ignore();
	cin>>skill;
    stringstream ss(skill);

    vector<string> vec;
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        vec.push_back(substr);
    }
    for(int i=0; i<vec.size(); i++){
        cout << "Job Ids having Skill " << vec[i] << endl;
        for(int j=0; j<jobSkillIdMap[vec[i]].size(); j++){
            cout << jobSkillIdMap[vec[i]][j] << endl;
        }
    }
    cin.ignore();
	cin.get(); 
}

void applyForAJob(){
	cout<<"\n\nEnter Applicant Name: ";
	cin.ignore();
	cin.getline(jobApplications[k].name,50);
	cout<<"\n\nEnter Applicants Description: ";
	cin.ignore();
	cin.getline(companies[k].description,50);
    cout<<"\nEnter the Job Id that you want to apply for: ";
	cin>>jobApplications[k].jobApplied.id;
    k++;
    cout<<"\nYour application is successfully submitted: ";
    cin.ignore();
	cin.get();  
}

void searchJobBySkillAndLocation(){
    string skill;
    cout<<"\n\nEnter Space Seperated Job Skills That you want to search for: ";
	cin.ignore();
	cin>>skill;
    stringstream ss(skill);

    vector<string> vec;
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        vec.push_back(substr);
    }
    char jobLocation[50];
    cout << "Enter JOb Location" << endl;
    cin.ignore();
    cin.getline(jobLocation,50);

    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<jobSkillIdMap[vec[i]].size(); j++){
            for(int k=0; k<jobLocationIdMap[jobLocation].size(); k++){
                if(jobSkillIdMap[vec[i]][j] == jobLocationIdMap[jobLocation][k]){
                    cout << "Job with location " << jobLocation << " and skill " << vec[i] << " is " << jobSkillIdMap[vec[i]][j] << endl;
                }
            }
        }
    }
    cin.ignore();
	cin.get(); 
}

 
int main(){
    char ch;
	int num;
	do
	{
	system("cls");
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\n\t1.Add New Company Details";
    cout<<"\n\n\t2.Show All Company Details";
	cout<<"\n\n\t3.Add New Job Posting ";
	cout<<"\n\n\t4.Search For a Job By Location";
    cout<<"\n\n\t5.Search For a Job By Id";
    cout<<"\n\n\t6.Search For a Job By Skills";
    cout<<"\n\n\t7.Get Lis Of all Jobs";
    cout<<"\n\n\t8.Apply for a Job";
    cout<<"\n\n\t9.Search For a Job By Location and Skills";
	cout<<"\n\n\t10. EXIT";
	cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\n\tPlease Enter Your Choice (1-9): ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	addCompanyDetails(); break;
	case '2':	showAllCompanies(); break;
	case '3':	addJobPosting(); break;
	case '4':   searchJobByLocation();break;
    case '5':   searchJobById();break;
    case '6':   searchJobBySkills();break;
    case '7':   showAllJobs();break;
    case '8':   applyForAJob();break;
    case '9':   searchJobBySkillAndLocation();break;
	default:	cout<<"\a"; 
		
    }
	}while(ch!='10');
 
	return 0;
}



