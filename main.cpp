#include "iostream"
using namespace std;

struct emps{
    int empid;
    string empname,emppost,empdept;
    int empsal;
};


class emp{
    public:


        void delemp(emps arr[],int ID,int n){
            for(int i=0;i<(n+1);i++){
                if (arr[i].empid==ID){
                    for(int j=i;j<(n+1);j++){
                        arr[j].empid=arr[j+1].empid;
                        arr[j].empdept=arr[j+1].empdept;
                        arr[j].empname=arr[j+1].empname;
                        arr[j].emppost=arr[j+1].emppost;
                        arr[j].empsal=arr[j+1].empsal;
                    }
                    n--;
                }
                else{
                    cout<<"Record not found\n";
                }
            }
        }


        void addemp(int n,emps arr[]){
            cout<<"Enter employee ID: ";
            cin>>arr[n-1].empid;
            cout<<"Enter employee Name: ";
            cin>>arr[n-1].empname;
            cout<<"Enter employee Post: ";
            cin>>arr[n-1].emppost;
            cout<<"Enter employee Department: ";
            cin>>arr[n-1].empdept;
            cout<<"Enter employee Salary: ";
            cin>>arr[n-1].empsal;
        }

        void allemp(emps arr[],int n){
            for(int i=0;i<n;i++){
                cout<<"Employee ID: "<<arr[i].empid<<endl;
                cout<<"Employee Name:"<<arr[i].empname<<endl;
                cout<<"Employee's Post :"<<arr[i].emppost<<endl;
                cout<<"Employee's Department :"<<arr[i].empdept<<endl;
                cout<<"Employee's Salary :"<<arr[i].empsal<<endl;
                cout<<endl;
            }
        }

        void speicficemp(emps arr[],int id,int n){
            for(int i=0;i<n;i++){
                if(arr[i].empid==id){
                    cout<<"Employee ID: "<<arr[i].empid<<endl;
                    cout<<"Employee Name:"<<arr[i].empname<<endl;
                    cout<<"Employee's Post :"<<arr[i].emppost<<endl;
                    cout<<"Employee's Department :"<<arr[i].empdept<<endl;
                    cout<<"Employee's Salary :"<<arr[i].empsal<<endl;
                    cout<<endl;
                }
            }
        }

        void empdeptlist(emps arr[],string dept,int n){
            cout<<"Employees in "<<dept<<" are: \n";
            for(int i=0;i<n;i++){
                if(arr[i].empdept==dept){
                    cout<<arr[i].empname<<endl;
                }
                else{
                    cout<<"No records found\n";
                }
            }
            cout<<endl;
        }

};

void print(){
    cout<<"*******MENU*******\n";
    cout<<"Enter your option\n";
    cout<<"1 => Add a new record"<<endl;
    cout<<"2 => Search record from employee ID"<<endl;
    cout<<"3 => List employee Names of particular department"<<endl;
    cout<<"4 => Display all employees"<<endl;
    cout<<"5 => Delete an employee record"<<endl;
    cout<<"6 => Terminate the program"<<endl;
    cout<<"*******************\n\n";
}


int main(){
    struct emps empdata[100]={{701,"Raghav","Intern","IT",8000},{703,"Ritvik","SDE","IT",45000},{705,"Vanya","Specialist","Marketing",35000},{712,"Tanya","SDE","IT",45000}};
    emp e1;
    int n=4;
    string deptname1;
    int eid;
    int flag=1;

    while(flag!=0){
        int choice;
        print();
        cin>>choice;

        switch (choice){
            case 1:
                e1.addemp(++n,empdata);
                break;

            case 2:

                cout<<"Enter the specific employee ID to find: ";
                cin>>eid;
                e1.speicficemp(empdata,eid,n);
                break;

            case 3:

                cout<<"Enter the department name for list: ";
                cin>>deptname1;
                e1.empdeptlist(empdata,deptname1,n);
                break;


            case 4:
                e1.allemp(empdata,n);
                break;

            case 5:
                cout<<"Enter the employee ID to delete: ";
                int empID;
                cin>>empID;
                e1.delemp(empdata,empID,--n);
                break;

            case 6:
                flag=0;
                break;
            default:
                cout<<"Wrong input\n";
                break;

        }

    }

    return 0;
}


