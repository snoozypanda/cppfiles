#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Patient
{
    string name;
    int age;
    int id;
    string gender;
    string blood_group;
    string medical_condition;
    string date;
    string modif_date;
    bool otp;
};

void help();
const int MAX = 100000; 
Patient patients[MAX];
string f;



class AdminSystem {
protected: 
    string docUsername[50];
    string docPass[50];
    int doc_id[50];
    int doc_caunt;
    int doc_trial[50];
    bool doc_otp[50];
    
    string cardmager_username[15];
    string cardmanger_pass[15];
    int card_id[15];
    int card_caunt;
    int card_trial[15];
    bool card_otp[15];

private:
    bool exitt1;
    bool found2;
    bool exitt;
    bool found;
    bool much3;
    int choice;
    bool choice2;
    string admin_pass;
    string ch;
    string adminPassword;
    string newpass;
    string confpass;


   

public:

    AdminSystem() {
    
    doc_caunt = 0;
    card_caunt = 0;
    exitt1=true;
    found2=false;
    exitt=true; 
    found=false;
    choice=0;
    choice2= true;
    //string adminPassword;
  
    much3=true;
    //adminPassword = "default";
    // Initialize arrays with zeros
    for (int i = 0; i < 50; i++) {
        doc_trial[i] = 0;
        doc_otp[i] = true;
    }

    for (int i = 0; i < 15; i++) {
        card_trial[i] = 0;
        card_otp[i]=true;
    }
    cout << "******************************************************************\n";
    cout << "******************* Patient Recording Software *******************\n";
    cout << "******************************************************************\n";
    cout << "               Welcome to the setup process.\n";
    cout << "          Please set a password for the administrator.\n";
    cout << "   Forgetting this password implies losing all stored data.\n";


                        while(much3){
                                cout<<"\nEnter new PassWord: ";
                                cin>>newpass;
                                cout<<"\nEnter the new password again to Confirm it: \n";
                                cin>>confpass;
                                if(newpass==confpass){

    
                                            cout<<"\nPassword changed successfuly!\n"; 
                                            cout<<"You can proceed..."<<endl;
                                            
                                            adminPassword= newpass;
                                            much3=false;
                                            break;

                                                     }
                                else
                                        {
                                    cout<<"\nPassword didn't much! \n";
                                    cout<<"Try Again!";
                                    continue;
                                        }

                                }

return; 




}
    void admin();
    

private:
    void addNewDoctor() {
        string a;
        cout << "\nEnter new doctors username: ";
        cin >> docUsername[doc_caunt];
        cout<<"are you sure you want to create the user?"<<endl;
        cout<<"press 1 if you are sure, otherwise press any other key ";
        cin>>a;
        if(a=="1")
        {

        
        docPass[doc_caunt] = docUsername[doc_caunt] + "@sis";
      
        
        cout << "\nNew Doctor with Username: \"" << docUsername[doc_caunt] << "\" Has been created\n";
        doc_id[doc_caunt] = doc_caunt;

        
        cout << "His ID: " << doc_id[doc_caunt] << endl;
        cout << "His default Password or OTP: "<<docPass[doc_caunt]<<endl;;

        ++doc_caunt;
        }
        else 
        docUsername[doc_caunt]= " ";

    }
    void addNewCardManager() {

        string a;
        cout << "\nEnter The New  CardManager's UserName: ";
        cin >> cardmager_username[card_caunt];
        cout<<"Are you sure you want to create the user ?"<<endl;
        cout<<"Press 1 if you are sure,otherwise press any other key!";
        cin>>a;
        if(a=="1")
        {

        
        cardmanger_pass[card_caunt] = cardmager_username[card_caunt] + "@sis";
      
        
        cout << "\nNew Card Manager with Username: \"" << cardmager_username[card_caunt] << "\" Has been created\n";
        card_id[card_caunt] = card_caunt;

        
        cout << "ID: " << card_id[card_caunt] << endl;
        cout << "Default Password or OTP: "<< cardmanger_pass[card_caunt]<<endl;;

        ++card_caunt;
        }
        else 
        cardmager_username[card_caunt]= " ";
    }
    void unlockUsers() {
       
        found = false; 
        exitt= true; 
        string choice = "1"; 
        while(choice == "1") {
        
        while (exitt) {
            cout << "\n******************* Trial Reset Form *******************\n\n";
            cout << "                 1. For Card Manager\n";
            cout << "                   2. For Doctor\n";
            cout << "      Press any other key to exit this page.\n";

            int b;
            int c;
            cin >> b;
            choice = "1"; 
            switch (b) {
                case 2:
                    cout << "Enter ID of the doctor: ";
                    cin >> c;

                    for (int i = 0; i < 50; i++) {
                        if (c == doc_id[i]) {
                            found = true;
                            int sure;
                            cout << "\nThe Doctor with ID number '" << doc_id[i] << "':\n"
                                  << "Name: "<<docUsername[i]<<"\n"
                                  <<"is Found!\n";
            
                                  cout<<"Are you sure you want to reset his trial?\n";
                                  cout<<"...press '1' if you are and any other key if you are not. ";
                                  cin>>sure;
                                  if(sure == 1){
                                        doc_trial[i] = 0;
                                         cout<< "\nGood the trial is set to 3. He can access his account";
                                         break;
                                  }
                                  else
                                  break;
                         
                        }
                    
                    }
                    if (!found)
                        cout << "User with such ID is not found";
                    break;
                    

                case 1:
                        cout << "Enter ID of the Card Manager : ";
                    cin >> c;

                    for (int i = 0; i < 50; i++) {
                        if (c == card_id[i]) {
                            found = true;
                            int sure;
                            cout << "\nCard Manager User with ID number '" << card_id[i] << "':\n"
                                  << "Name: "<<cardmager_username[i]<<" "
                                  <<"is Found!\n";
            
                                 cout << "Are you certain you wish to reset their trial to the default settings?\n";
                                 cout << "Press '1' to confirm, or any other key to cancel.";

                                  cin>>sure;
                                  if(sure == 1){
                                        doc_trial[i] = 0;
                                         cout<< "\nThe trial is set to 3. He can access his account";
                                         break;
                                  }
                                  else
                                  break;
                         
                        }
                    
                    }
                    if (!found)
                        cout << "Card Manager User with such ID is not found";
                    break;
                    

                default:
                    exitt = false;
                    break;
        
        }
        break;
        }
       
       cout<<" press '1' if you want to stay in this page or otherwise press anyother key";
       cin>>choice;
       
        }
       
        }
    void deleteSystemUsers() {
      bool found = false; 
         bool exitt;
        string choice = "1"; 
        while(choice == "1") {
        exitt= true; 
        while (exitt) {
            cout << "\n--------------- User Deletion Form--------------\n";
            cout << "1. Delete Card Manager User\n";
            cout << "2. Delete Doctor User\n";
            cout << "....Press any other key to exit this Page\n";

            int b;
            int c;
            cin >> b;
            choice = "1"; 
            switch (b) {
                case 2:
                    cout << "Enter ID of the doctor: ";
                    cin >> c;

                    for (int i = 0; i < 50; i++) {
                        if (c == doc_id[i]) {
                            found = true;
                            int sure;
                            cout << "\nThe Doctor with ID number '" << doc_id[i] << "':\n"
                                  << "Name: "<<docUsername[i]<<"\n"
                                  <<"is Found!\n";
            
                                  cout<<"Are you sure you want to Erase this user Form the sysytem? \n";
                                  cout<<"...press '1' if you are Sure and any other key if you are not. ";
                                  cin>>sure;
                                  if(sure == 1){
                                        docUsername[i] = docUsername[i] + " -deleted user";
                                        docPass[i] = rand();
                                         cout<< "\nDone!\n the user is successfuly deleted";
                                         break;
                                  }
                                  else
                                  break;
                         
                        }
                    
                    }
                    if (!found)
                        cout << "User with such ID is not found";
                    break;
                    

                case 1:
                        cout << "Enter ID of the Card Manager : ";
                    cin >> c;

                    for (int i = 0; i < 50; i++) {
                        if (c == card_id[i]) {
                            found = true;
                            int sure;
                            cout << "\nCard Manager User with ID number '" << card_id[i] << "':\n"
                                  << "Name: "<<cardmager_username[i]<<" "
                                  <<"is Found!\n";
            
                                  cout<<"Are you sure you want to reset his/her trial to the defaults ?\n";
                                  cout<<"...press '1' if you are and any other key if you are not.";
                                  cin>>sure;
                                  if(sure == 1){
                                        doc_trial[i] = 0;
                                         cout<< "\nGood the trial is set to 3. He can access his account";
                                         break;
                                  }
                                  else
                                  break;
                         
                        }
                    
                    }
                    if (!found)
                        cout << "Card Manager User with such ID is not found";
                    break;
                    

                default:
                    exitt = false;
                    break;
        
        }
        break;
        }
       
       cout<<" Do you want to Stay?\n 1 for /'yes/', any other key for /'NO/'";
       cin>>choice;
       
        }
       
}

};
 void AdminSystem::admin() {
       
        choice = 0; 
        choice2 = true;
        while (choice2 == true) {
        
                cout << "Enter the admin code: ";
                cin >> admin_pass;
    
              if (admin_pass == adminPassword) {
        while (choice != 5) {
           cout << "\n************************ Admin Menu ************************\n"
                << "*            ****************************************     *\n"
                << "* Please choose an option from the Admin menu:             *\n"
                << "* 1. Add new doctor                                       *\n"
                << "* 2. Add new card manager                                 *\n"
                << "* 3. Unlock locked out users                              *\n"
                << "* 4. Delete system users                                  *\n"
                << "* 5. Exit this page                                       *\n"
                << "* ******************************************************** *\n";


            cout << "\nEnter your choice: ";
            cin >> choice;

                         switch (choice) {
                case 1:
                    addNewDoctor();
                    break;

                case 2:
                    addNewCardManager();
                    break;

                case 3:
                    unlockUsers();
                    break;

                case 4:
                    deleteSystemUsers();
                    break;

                case 5:
                    choice2=false;
                    cout << "Exiting this page..." << endl;
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
                             }
    } 
                 else {
                cout << "Incorrect admin code!" << endl;
                cout << " If you want to try again press 1, else press any other key ";
                cin >>ch;

                if(ch=="1"){ continue;}
                else choice2=false;
                cout<<"Exiting this page...";
                      }
        } 
         
               
        }


class PatientManagement{
private:

   const int MAX;
    int counnt; 
   

public:
    PatientManagement() : counnt(0),MAX(100000)  {}
    
    
    void add_patient();
    void search_patient();
    void modify_patient_menu();
    void display_patients();
    void modify_patient(int a, string b);
    string search_is_found(int a, string b);
};
void PatientManagement::add_patient() {
    if (counnt < MAX) {
        patients[counnt].id= counnt;
        cout << "\nPatient: ";
        cin.ignore();
        getline(cin, patients[counnt].name);

        cout << "Patient Age: ";
        cin >> patients[counnt].age;

        cout << "Enter the gender of the patient (M/F): ";
        cin >> patients[counnt].gender;

        cout << "Enter the blood group of the patient: ";
        cin.ignore();
        getline(cin, patients[counnt].blood_group);

        cout << "Enter the medical condition of the patient: ";
        getline(cin, patients[counnt].medical_condition);


        time_t now = time(0);  // Gets the current time
        string timeString = ctime(&now);  // Converts the time to a string
        timeString.pop_back();  // Removes the newline character
        patients[counnt].date = timeString;
       

        cout << "\nThe new patient Has been added successfull.";
        cout << "Patients ID is: " << patients[counnt].id<<"\n";
        cout << " Name: "<<patients[counnt].name<<"\n";
        cout <<" Age at a time of Regestriation: "<< patients[counnt].age<<"\n";
        cout << "Date of Registration: " <<  patients[counnt].date<<endl;
        counnt++;

    }
    else {
        cout << "\n The system is full. Cannot add more records.\n";
    }
}
void PatientManagement::search_patient(){
    
        int choice,choice2;         // To store the user's choice
        bool found = false; // To indicate if a record is not found
        string name;        // To store the name to search
        int id;
 // Check if there are any records in the array
    if (counnt > 0)
    {
    
        // Display a menu with options to search by name or blood group
       while(choice != 3 ){

            cout << "\n====================== Search for a Patient Record ======================\n";
            cout << "Choose an option to search for the patient:\n\n";
            cout << "               1. Search by Name\n";
            cout << "               2. Search by ID\n";
            cout << "               3. Exit this Page\n";


        
    
        cout << "\nEnter your choice: ";
        cin >> choice;

        
        switch (choice)
        {
        case 1:
            // Prompt the user to enter the name to search
            cout << "\nEnter the name of the patient: ";
            cin.ignore();       // Ignore any leftover input
            getline(cin, name); // Read a line of input as name

            // Loop through the array and compare each name with the input
            for (int i = 0; i < counnt; i++)
            {
                // If the name matches, display the record and set the //found flag to true
                if (patients[i].name == name)
                {
                     found = true;
                    cout << "\nThe patient record with name\' "
                         << name << "\' is found:\n";
                    cout << "\nPatient ID"
                         << patients[i].id
                         << "\nName: "
                         << patients[i].name
                         << "\nAge: "
                         << patients[i].age
                         << "\nGender: "
                         << patients[i].gender
                         << "\nBlood Group: "
                         << patients[i].blood_group
                         << "\nMedical Condition: "
                         << patients[i].medical_condition
                         << "\nDate of registration: "
                         << patients[i].date
                         << endl;
                    
                    if (patients[i].modif_date.empty())
                        break;
                    else
                        cout << "Lastest Recoreded data on:" << patients[i].modif_date << endl;
                        cout<<"********************************************************";
                   
                 

                    
                }
            }


            if (!found)
            {
                cout << "\nThe patient record with name: "
                     << name
                     << " is not found.\n";
            }

            break;

        case 2:
            cout << "\nEnter the ID number on the patient: ";
            cin.ignore(); 
            cin >> id;    

        
            for (int i = 0; i < counnt; i++)
            {
                
                if (i == id)
                {
                      found = true;
                    cout << "\nThe patient with ID number '"
                         << patients[i].id << "'"
                         << " is found:\n";
                    cout << "Name: "
                         << patients[i].name << endl
                         << "Age: "
                         << patients[i].age << endl
                         << "Gender: "
                         << patients[i].gender << endl
                         << "Blood Group: "
                         << patients[i].blood_group << endl
                         << "Medical Condition: "
                         << patients[i].medical_condition<<endl
                         << "date of registration"
                         << patients[i].date
                         << endl;

                    if (patients[i].modif_date.empty())
                        break;
                    else
                        cout << "Last modifid at" << patients[i].modif_date << endl;
                  
                }
            }

            // If the found  is false, display a message that the record is not found
            if (!found)
            {
                cout << "\nThe patient record with ID number "<<"\'"
                     << id<<"\'"
                     << "is not found.\n";
            }
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
    }
    
    
    
    
    else
    {
        // Display a message that there are no records
        cout << "\nThere are no patient records in the system.\n";
    }
    }
string PatientManagement::search_is_found(int a = -1 , string b = "defualt"){
    bool found = true;
    if (counnt > 0 && found == true)
    {
    
            for (int i = 0; i < counnt; i++)
            {
                if (( patients[i].id == a ) || ((patients[i].name) == b))
                {
                     return "is found";
                     found = true;
                }

            }
            if(!found)
            return "is not found";
    }
   
    else
         return "the record is empty";
    return "0";
    
}
void PatientManagement::modify_patient(int a = 100001, string b = "default"){
        
        int idNum = a;
        string name = b;
         
         for(int i = 0; i<=counnt; i++){
                    
                    if (patients[i].name == name )
                    {
                        idNum = i;
                        break;
                    }
         }


         time_t now = time(0);  // Gets the current time
        string timeString = ctime(&now);  // Converts the time to a string
        timeString.pop_back();  // Removes the newline character
         patients[idNum].modif_date = timeString;


            cout << "\npatient Information: " <<endl;
            cout << "Name: " << patients[idNum].name << endl;
            cout << "Age: " << patients[idNum].age << endl;
            cout << "Gender: " << patients[idNum].gender << endl;
            cout << "Blood Group: " << patients[idNum].blood_group << endl;
            cout << "Medical Condition: " << patients[idNum].medical_condition << endl;
          
        
           
            cout << "\n-----------Enter the new information-------------\n";
            cout << "Enter the new age of the patient: ";
            cin >> patients[idNum].age;

            cout << "Enter the new gender of the patient (M/F): ";
            cin >> patients[idNum].gender;

            cout << "Enter the new blood group of the patient: ";
            cin.ignore();
            getline(cin, patients[idNum].blood_group);

            cout << "Enter the new medical condition of the patient: ";


            f = "At " + patients[idNum].modif_date + " :- "  + patients[idNum].medical_condition + ": ";

            getline(cin, patients[idNum].medical_condition);
            



           cout <<"\nThe patient record has been modified successfully!\n";   

           patients[idNum].medical_condition = f + "\nThe Added info: "  + patients[idNum].medical_condition;
           cout<< patients[idNum].medical_condition; 
          
          
           return;


}
void PatientManagement::modify_patient_menu(){


int choice = 1;// seting the defualt to none 3 number;

int id_num;
string P_name;
bool loop= true;

while(loop){


cout <<"Search By: \n"
     << "1. By ID \n"
     << "2. By Name\n";
cout << "3. Exit this page\n";
cin  >>choice; 
switch(choice)
{
        case 1:
             cout << "\nEnter the ID of the patient to be modified: ";
             cin >> id_num;
           if (search_is_found(id_num) == "is found")
                {
            modify_patient(id_num);
                }
           else if (search_is_found(id_num) == "is not found")
           {

             cout<< "patient with ID number: "<<id_num<<"is not found\n";
           }
           else
            cout<<"Try again";

           break;



        case 2:
        cout << "\nEnter the full Name of the patient to be modified: ";
        cin  >> P_name;
           if ((search_is_found(100001,P_name)) == "is found"){

            modify_patient(100001,P_name);
           }
           else if ((search_is_found(100001,P_name)) == "is not found"){

             cout<< "patient with  name: "<<P_name<<" is not found\n";


           }
           else
           cout<<"Try Again";
            break;

      
        default: 
            cout<< "  Exsiting this Page...\n";
            loop = false;
            break;
}
}
}
void PatientManagement::display_patients(){
    if (counnt > 0)
    {
    
        cout << "+--------+----------+-------------+-----------------------------+--------+-----------------------------+--------+\n";
        cout << "| " << setw(8) << left << "ID"
             << "| " << setw(10) << left << "Name"
             << "| " << setw(13) << left << "Blood Group"
             << "| " << setw(29) << left << "Date last Modified"
             << "| " << setw(8) << left << "Age"
             << "| " << setw(29) << left << "Date of Registration"
             << "| " << setw(8) << left << "Gender" << "|\n";
        cout << "+--------+----------+-------------+-----------------------------+--------+-----------------------------+--------+\n";

       
        for (int i = 0; i < counnt; i++)
        {
            cout << "| " << setw(8) << left << patients[i].id
                 << "| " << setw(10) << left << patients[i].name
                 << "| " << setw(13) << left << patients[i].blood_group
                 << "| " << setw(29) << left << patients[i].modif_date
                 << "| " << setw(8) << left << patients[i].age
                 << "| " << setw(29) << left << patients[i].date
                 << "| " << setw(8) << left << patients[i].gender << "|\n";
            cout << "+--------+----------+-------------+-----------------------------+--------+-----------------------------+--------+\n";
        }
    }
    else
        cout << "\nThere are no patient records in the system.\n";
}





class Stuff : public AdminSystem, public PatientManagement {
private:
  int trial;
    string t;
    int left_trial;
    int choice;
    string password;
    int id;
    string user_name;
    string current_pass;
    string new_pass;
    string conf_pass;



public:
    // Constructor
    Stuff() {
        // You can initialize any attributes specific to the Stuff class here
    }
 
    // Member function for the doctor
    void doctor();
    void card_manager();
};

void Stuff::doctor() {
    bool back2 = false;
    bool much = true;
    bool much2 = true;
    string choice3;
    
    cout << "**********************************************************\n";
    cout << "*                    Doctor Login Page                   *\n";
    cout << "*                   ******************                   *\n";
    cout << "**********************************************************\n";



    for (int trialCount = 1; trialCount <= 3; ++trialCount) {
        cout << "Enter Username: \n";
        cin >> user_name;
        cout << "Enter the Pin: \n";
        cin >> password;
        cout << "Enter your ID: ";
        cin >> id;

        trial = doc_trial[id]++;

        for (int j = 0; j < 50; j++) {
            if (doc_id[j] == id && docPass[j] == password && docUsername[j] == user_name) {
                doc_trial[id] = 0; 
                
                do {
                    if(doc_otp[id]==true)
                    {
                        while(much2){
                                cout<<"\nEnter new PassWord: \n";
                                cin>>new_pass;
                                cout<<"Enter the new password again to Confirm it: \n";
                                cin>>conf_pass;
                                if(new_pass==conf_pass){

                                            docPass[id]=new_pass;
                                            cout<<"Password changed successfuly!\n"; 
                                            cout<<"you can proceed..."<<endl;
                                        
                                            much2=false;
                                            doc_otp[id]=false;
                                            break;

                                }
                                else
                                            {
                                    cout<<"\npassword didn't much! \n";
                                    cout<<"Try Again!";
                                    continue;
                                            }

                                }
                        
                    }
                    
                        cout << "************************* Doctor Menu *****************************\n";
                        cout << "*            *******************************                      *\n";
                        cout << "* ************ Please choose an option from the menu: *************\n";
                        cout << "* Logged In as - Username: " << user_name <<"\n";
                        cout << "* 1. Add a new patient record                                     *\n";
                        cout << "* 2. Display all patient records                                  *\n";
                        cout << "* 3. Search for a patient record                                  *\n";
                        cout << "* 4. Modify an existing patient record                            *\n";
                        cout << "* 5. Change Login password                                        *\n";
                        cout << "* 6. Exit doctor's menu                                           *\n";
                        cout << "* *****************************************************************\n";


                        cout << "\nEnter your choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 1:
                                add_patient();
                                break;
                            case 2:
                                display_patients();
                                break;
                            case 3:
                                search_patient();
                                break;
                            case 4:
                                modify_patient_menu();
                                break;
                            case 5:
                            while(!back2){
                                cout<<"\nEnter the your current password: \n";
                                cin>>current_pass; 
                               
                                if(current_pass == docPass[id]){
                                     while(much){
                                cout<<"\nEnter new PassWord: \n";
                                cin>>new_pass;
                                cout<<"Enter the new password again to Confirm it: \n";
                                cin>>conf_pass;
                                if(new_pass==conf_pass){

                                            docPass[id]=new_pass;
                                            cout<<"Password changed successfuly!\n"; 
                                            back2=true;
                                            much=false;
                                            break;

                                }
                                else
                                    cout<<"\npassword didn't much!";
                                    continue;

                                }
                                }
                                else{

                                cout<<"\nincorrect! \n";
                                cout<< "Do you want to try agin? \n";
                                cout<< " 1 for yes and any other key to exit \n";
                                cin>>choice3;

                                        if(choice3 == "1"){
                                            continue;
                                        }
                                        else
                                            back2 = true;
                                            break;
                                
                                }
                                
    
                                }
                                break;
                            case 6:
                                cout << "Exiting doctors menu...\n";
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                                break;
                        }
                    }
              
                     while (choice != 6);
               return;
            }
        }

        if (doc_trial[id] < 3) {
            left_trial = 3 - doc_trial[id];
            cout << "Incorrect user information!\n";
            cout << left_trial << " trials left\n";
            cout << "If you want to try again, type '1'. Otherwise, press any other key: ";
            cin >> t;

            if (t != "1") {
                cout << "Returning to the main menu...\n";
                return; // Exit the function if the user chooses not to try again
            }
        } 
        else {
            cout << "Too many tries. Contact the Administrators.\n";
            cout << "Returning to the main menu...\n";
            return; // Exit the function after too many failed attempts
        }
    }

    cout << "Exiting Doc Login page...\n";
}
void Stuff::card_manager() {

 bool back2 = false;
 bool much = true;
 bool much2 = true;
string choice3;
    cout << "***********************************************************\n";
    cout << "*                  Card Manager Login Page                *\n";
    cout << "*                   *******************                   *\n";
    cout << "***********************************************************\n";

    for (int trialCount = 1; trialCount <= 3; ++trialCount) {
        cout << "|Enter Username: ";
        cin >> user_name;
        cout << "\nEnter the Pin: ";
        cin >> password;
        cout << "\nEnter your ID: ";
        cin >> id;

        trial = card_trial[id]++;

        for (int j = 0; j < 15; j++) {
            if (card_id[j] == id && cardmanger_pass[j] == password && cardmager_username[j] == user_name) {
                doc_trial[id] = 0; // Resetting default value to 0
                
                do {

                    if(card_otp[id]==true)
                    {
                        while(much2){
                                cout << "To proceed to your profile, you are required to update your password.\n";
                                cout << "Please enter your new password: ";
                                cin >> new_pass;

                                cout << "Please re-enter the new password to confirm: ";
                                cin >> conf_pass;

                                if(new_pass==conf_pass){

                                            cardmanger_pass[id]=new_pass;
                                            cout << "Password changed successfully!\n";
                                            cout << "You can proceed...\n";

                                        
                                            much2=false;
                                            doc_otp[id]=false;
                                            break;

                                }
                                else
                                    cout<<"\nPassword didn't much! \n";
                                    cout<<"Try Again!";
                                    continue;

                                }
                        
                    }
                    
                    cout << "*************************************************************\n";
                    cout << "*                 Card Manager Menu                         *\n";
                    cout << "*                    ------------------                     *\n";
                    cout << "*   Please choose an option from the menu:                  *\n";
                    cout << "*   Logged in as-           Username: " << user_name<<endl;         
                    cout << "*   1. Add a new patient record                             *\n";
                    cout << "*   2. Display all patient records                          *\n";
                    cout << "*   3. Search for a patient record                          *\n";
                    cout << "*   4. Change Password                                      *\n";
                    cout << "*   5. Exit this page...                                    *\n";
                    cout << "*************************************************************\n";

                        cin >> choice;

                        switch (choice) {
                            case 1:
                                add_patient();
                                break;
                            case 2:
                                display_patients();
                                break;
                            case 3:
                                search_patient();
                                break;
                            case 4:
                            while(!back2){
                                cout<<"\nEnter the your current password: \n";
                                cin>>current_pass; 
                               
                                if(current_pass == cardmanger_pass[id]){
                                     while(much){
                                cout<<"\nEnter new PassWord: \n";
                                cin>>new_pass;
                                cout<<"Enter the new password again to Confirm it: \n";
                                cin>>conf_pass;
                                if(new_pass==conf_pass){

                                            cardmanger_pass[id]=new_pass;
                                            cout<<"Password changed successfuly!\n"; 
                                            back2=true;
                                            much=false;
                                            break;

                                }
                                else
                                    cout<<"password didn't much!\n";
                                    continue;

                                }
                                }
                                else{

                                cout << "Oops, incorrect!\n";
                                cout << "Would you like to try again?\n";
                                cout << "Press '1' for yes, or any other key to exit.\n";

                                cin>>choice3;

                                        if(choice3 == "1"){
                                            continue;
                                        }
                                        else
                                            back2 = true;
                                            break;
                                
                                }
 
   
                                }
                               break;
                            case 5:
                               cout << "Exiting Card Manager's menu...\n";
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                                break;
                        }

                    }while (choice != 5);
               return;
            }
        }

        if (card_trial[id] < 3) {
            left_trial = 3 - card_trial[id];
            cout << "Incorrect user information!\n";
            cout << left_trial << " trials left\n";
            cout << "If you want to try again, type '1'. Otherwise, press any other key: ";
            cin >> t;

            if (t != "1") {
                cout << "Returning to the main menu...\n";
                return; // Exit the function if the user chooses not to try again
            }
        } 
        else {
            cout << "Too many tries. Contact the Administrators.\n";
            cout << "Returning to the main menu...\n";
            return; // Exit the function after too many failed attempts
        }
    }

    cout << "Exiting Card Manager Login page...\n";
}

void help()
{
    cout << " Patient's Medical Information Recording System Help page\n";
    cout << "---------------------------------------------------------------------\n";
    cout << "This program allows you to manage patient medical records.\n";
    cout << "You can choose from the following options:\n";
    cout << "1. Add: This option allows you to enter the information for a new patient and add it to the system.\n";   
    cout << "2. Display: : This option displays all the patient records currently stored in the system.\n";
    cout << "3. Search: This option allows you to search for a specific patient record by entering the patient's name.\n";
    cout << "4. Modify: This option allows you to modify the information of an existing patient record.\n";
    cout << "5. delete:This option allows you to delete the information of an existing patient record.\n";
    cout << "and To choose an option, enter the corresponding number and press Enter.\n";
    cout << "-------------------------------------------------------contact us: +2519*******9, domain@example.com ";
}




int main()
{
    
   
    Stuff adm;
 bool exit = true ;
   

    int choice;       
  
    while (exit)
    {
    cout << "***********************************************************\n";
    cout << "*   Welcome to the Patient's Medical Information          *\n";
    cout << "*                  Recording System                       *\n";
    cout << "***********************************************************\n\n";
    cout << "      ----------------------------------------------\n";
    cout << "      |      Please choose an option from the menu: |\n";
    cout << "      ----------------------------------------------\n";
    cout << "                1. Card Manager Login page\n";
    cout << "                2. Doctor Login page\n";
    cout << "                3. Admin\n";
    cout << "                4. Help\n";
    cout << "                5. Exit the program\n";
    cout << "      ----------------------------------------------\n\n";
        

        cout <<"\nEnter your choice: ";
        cin >> choice;
switch (choice)
        {
        case 1:
         adm.card_manager();
            break;
        case 2:
           adm.doctor();
            break;
        
        case 3:
            adm.admin();
            break;
        case 4:
            help();
            break;
        case 5:
            exit = false;
            cout << "\nThank you for using the system. Goodbye!\n";
            break;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }


    }

    return 0;
}                                                                                                                                          