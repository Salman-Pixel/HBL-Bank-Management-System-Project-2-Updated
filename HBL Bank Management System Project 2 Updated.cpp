//Code by Salman-Pixel

#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
char in;
class Bnk{
	private:
		float id,rating,pages;
		string name,gender,language,issueDate,issueTo;
		vector<string> myvec;
	public:
		Bnk(){
			id=00;
			rating=00;
			pages=000;
			name=" ";
			gender=" ";
			language=" ";
			issueDate=" ";
		}
		void addAcc(){
			do{
			ofstream myfile;
  			myfile.open ("Store.txt" ,ios::out | ios::app | ios::binary);
  			
  			cout<<"Enter CNIC ID of the customer: ";
  			cin>>id;
  			cout<<"Enter Name of the customer: ";
  			cin>>name;
  			cout<<"Enter gender: ";
  			cin>>gender;
  			cout<<"Enter language for the user: ";
  			cin>>language;
  			cout<<"Enter issue Date of the account: ";
  			cin>>issueDate;
  			myfile <<id<<"\t"<<name<<"\t"<<gender<<"\t"<<language<<"\t"<<issueDate<<"\n";
  			myfile.close();
  			cout<<"\nSuccess!!\nDo you want to do another entry? (y or n) ";
  			cin>>in;
  			
  		} while(in=='y');
  			Bnk l1;
		    l1.menu();
		}
		void display(){
			cout<<"\nDisplay Section: "<<endl;
			string myText;
			ifstream MyReadFile("Store.txt");
			while (getline (MyReadFile, myText)) {		
			  myvec.push_back(myText);
			}
			MyReadFile.close();
		   
		   for(int i=0; i<myvec.size();i++){
		   	   cout<<myvec[i]<<endl;   
		   }	
		   Bnk l1;
		   l1.menu();
		}
		void search(){
			char ssID;
			bool flag = false;
			cout<<"\nSearch Section: "<<endl;
			cout<<"Enter ID of the account to search: ";
			cin>>ssID;
			string myText;
			ifstream MyReadFile("Store.txt");
			while (getline (MyReadFile, myText)) {
			  if(myText[0]==ssID){
			  	cout<<"Account Found!!"<<endl;
			  	flag = true;
			  	cout<<myText;
			  	Bnk l1; 
				l1.menu();   
			  	break;
			  }
			}
			if(!flag){
				cout<<"Account Not Found";
			}
			MyReadFile.close();
			Bnk l1;
			l1.menu();
		}
		void delet(){
			cout<<"\nDelete Section: "<<endl;
			char sID;
			bool flag = false;
			cout<<"Enter ID of the account to Delete: ";
			cin>>sID;			
			string myText;
			ifstream MyReadFile("Store.txt");
			while (getline (MyReadFile, myText)) {
			if(myText[0]!=sID){
			  	  myvec.push_back(myText);
			  }
			}
			MyReadFile.close();
			
			ofstream myfile;
			myfile.open ("Store.txt");
			
			for(int i=0;i<myvec.size();i++){
				myfile<<myvec[i]<<"\n";
			}
			cout<<"\nSucessfully Deleted!!\n";
			Bnk l3;
		    l3.menu();
		}
	int menu(){  
	int choice;
    do{
    	
    	cout<<"\n\tSelect one option below: "<<endl;
        cout<<"\n\t [ Press 1 ]: Add a new account.";
        cout<<"\n\t [ Press 2 ]: Display Records.";
        cout<<"\n\t [ Press 3 ]: Search Records.";
        cout<<"\n\t [ Press 4 ]: Delete Records";
        cout<<"\n\t [ Press 5 ]: Quit";
        cout<<"\n\n\tEnter your choice: ";
    	
        cin>>choice;
        
        Bnk l1;
        switch(choice){
            case 1:
				l1.addAcc(); 
				break;
            case 2: 
				l1.display(); 
				break;
            case 3: 
				l1.search(); 
				break;
            case 4: 
				l1.delet(); 
				break;
			case 5:
				return 0;
        }
    } while(choice==6);
	}
};
int main(){
	
	cout << "\n\t\t\t[]      [] [][][][]  []" <<endl;
    cout << "\t\t\t[]      [] []     [] []" <<endl;
    cout << "\t\t\t[]      [] []     [] []" <<endl;
    cout << "\t\t\t[][][][][] [][][][]  []" <<endl;
    cout << "\t\t\t[]      [] []     [] []" <<endl;
    cout << "\t\t\t[]      [] []     [] []" <<endl;
    cout << "\t\t\t[]      [] [][][][]  [][][][]"<<endl;
	  
     cout<<"\n\n\t\t GROUP:"<<" Dime Programmers";
     cout<<"\n\n\t\t PROJECT:"<<" Bank Management System (HBL)";
     cout<<"\n\n\t\t SUBJECT:"<<" Object Oriented Programming (LAB)";
     cout<<"\n\t\t";
     cout<<"\n\t\t Instructor:"<<" MUHAMMAD TOUQEER ALI";
     cout<<"\n\t\t DEPERTMENT:"<<" Computer Science BSCS-2B";
     cout<<"\n\n\t\t [ Note: This is an Incrementel Project. ]"<<endl;
     cout<<"\n\t\t GROUP MEMBERS:" ;
		cout<<"\n\t\t\t\t"<<"Salman Karim       2012185";
		cout<<"\n\t\t\t\t"<<"Zaryaab KHAN       2012171";
		cin.get();
	
	Bnk l1;
	l1.menu();
	
	return 0;
}


