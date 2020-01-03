#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//the working functions
char menu()
{
    char choice;
    cout<<"************************************************************************************************************************"<<endl;
    cout<<"                                                Department of Road & safety                                             "<<endl;
    cout<<"************************************************************************************************************************"<<endl;


    cout<<"                                      _____________________MENU________________________\n";
    cout<<"                                     |            1. Capture vehicle detials          |\n";
    cout<<"                                     |                                                |\n";
    cout<<"                                     |            2. View unsorted data               |\n";
    cout<<"                                     |                                                |\n";
    cout<<"                                     |            3. Sorted record, ascending order   |\n";
    cout<<"                                     |                                                |\n";
    cout<<"                                     |            4. Search for the record            |\n";
    cout<<"                                     |                                                |\n";
    cout<<"                                     |            5. Exit                             |\n";
    cout<<"                                      _________________________________________________\n";

    cout<<"choose number from the list \n";
    cin>>choice;

    return choice;
}

//capturing the vahicle detials
class VehicleCapture
{
    public: int registrationNUm;
            string name;
            int distance;
            string maker;
            string model;
            int year;
            string color;
            int doors;
            int seats;

            int i;
            int no;

            //string heavyWeight;
            int weight;
            int totalAmount;

            //entering the amount records
            int numX()
            {
                cout<<"The number of the records you will enter"<<endl;
                cin>>no;

                return no;
            }
            //string names[x];

            //string *p;
            void capture(int num)
            {
                ofstream writer("file1.txt");
                if(writer.is_open())
                {

                    while(num)
                    {
                        cout<<"Enter the driver name"<<endl;
                        cin>>name;
                        writer<<"Name :"<<name<<" ";

                        cout<<"enter the reg number of your vehicle"<<endl;
                        cin>>registrationNUm;
                        writer<<"Registration number :"<<registrationNUm<<" ";

                        cout<<"enter the distance travelled"<<endl;
                        cin>>distance;
                        writer<<"Distance travelled :"<<distance<<" ";

                        cout<<"enter the vehicle maker"<<endl;
                        cin>>maker;
                        writer<<"vehicle maker :"<<maker<<" ";

                        cout<<"enter the vehicle model"<<endl;
                        cin>>model;
                        writer<<"model :"<<model<<" ";

                        cout<<"enter the year manufactured"<<endl;
                        cin>>year;
                        writer<<"manufactured on"<<year<<" ";

                        cout<<"enter the color of the vehicle"<<endl;
                        cin>>color;
                        writer<<"color of car :"<<color<<" ";

                        cout<<"enter the number of doors"<<endl;
                        cin>>doors;
                        writer<<"number of doors :"<<doors;

                        cout<<"enter the number of seats"<<endl;
                        cin>>seats;
                        writer<<"Number of seats :"<<seats;

                        //entering the details for computing data
                        cout<<"Enter the vehicle wieght"<<endl;
                        cin>>weight;

                        if(weight <= 3500)
                        {
                            totalAmount = weight * 100;
                            //cout<<""
                            writer<<"Light weight "<<totalAmount<<endl;
                        }
                        else
                        {
                            totalAmount = weight * 100;
                            writer<<"heavy weight "<<totalAmount<<endl;
                        }


                        cout<<"The record entered has been succefully saved"<<endl;

                        num--;
                    }
                }
                else
                {
                    cout<<"the file was not opened"<<endl;
                }

            }
};

//viewing the unsorted data
void unsorted()
{
    string data;
	ifstream input_file;

	//!infile.eof
	input_file.open ("file1.txt");
        while(getline(input_file,data)) // To get you all the lines.
        {
             // Prints our STRING.
	        cout<<data<<endl;

        }
        //closing the file
	input_file.close();
}

//checking how many records in file
int numberOfLines()
{
    int number_of_lines = 0;
    string line;
    ifstream myfile("file1.txt");

    while (getline(myfile, line))
        ++number_of_lines;

    return number_of_lines;
}

//this is the additions
void readFromFile(char filename[],string storage[],int &noOfEn)
{
    ifstream take(filename);
    take>>noOfEn;

    for(int i=0;i<noOfEn;i++)
    {
        take>>storage[i];
    }
}

void show(int entries , string arr[])
{
    for(int i = 0;i<entries;i++)
    {
        cout<<arr[i]<<'\t';
        if(!(i%10))
            cout<<endl;
    }
}
int main()
{
    //int number;
    //int weight;

   ifstream input_file("file1.txt");
    string search;
    int set = numberOfLines();
    string line;
    string file_records;
    //string* pointer;

    VehicleCapture cap;
    int num;
    int i;

    ifstream database("file1.txt");
    string spacex;

    char choice = menu();

    switch(choice)
    {
        case '1':num = cap.numX();
                cap.capture(num);

                break;
        case '2':cout<<"View Unsorted"<<endl;
                    cout<<"*********************************"<<endl;
                    unsorted();
                    break;
                break;
        case '3':{ cout<<"view unsorted data in ascending"<<endl;
                    cout<<"-----------------------------------------"<<endl;
                   int count ;
                    string stor[1000];
                    char filename[10] = {"file1.txt"};
                    readFromFile(filename,stor,count);
                    show(count,stor);
                    cout<<endl;

                    string temp;
                    int iteration;
                    int index;
                    for (iteration=0; iteration<count; iteration++)
                    {
                        for (index=0; index<count-iteration; index++)
                        {
                            if (stor[index] > stor[index+1])
                                        {
                                temp = stor[index];
                                stor[index] = stor[index+1];
                                    stor[index+1] = temp;
                            }
                        }
                   }

                   cout<<"view sorted data in ascending"<<endl;
                    cout<<"-----------------------------------------"<<endl;
                   show(count,stor);
                   cout<<endl;
                   cout<<endl;


                break;}
        case '4': cout << "Enter word to search for: ";
                    cin >>search;
                    // open file to search
                    if(input_file.is_open()) {
                        unsigned int cLine = 0;
                        while(getline(input_file, line)) { // I changed this, see below
                            cLine++;
                            if (set = line.find(search, 0) != string::npos) {
                                cout << "found: " << search << "line: " << cLine << endl;
                            }
                        }
                        input_file.close();
                    }
            else cout << "Unable to open file.";
                    break;
        case '5': cout<<"Exit"<<endl;
                    break;
        default:   cout<<"number entered is invalid"<<endl;
    }




    int cont;
        cout<<"Enter 1 if you want to continue else 0"<<endl;
        cin>>cont;



        //code for continueing the execution


        if(cont == 1)
        {

            while(3)
            {
                 char num = menu();

                    if(num=='1')
                    {
                        int z = cap.numX();
                        cap.capture(z);
                    }
                    else if(num == '2')
                    {
                        cout<<"Unsorted data is diplayed below"<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        unsorted();
                    }
                    else if(num== '3')
                    {
                        cout<<"view unsorted data in ascending"<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        int count ;
                        string stor[1000];
                        char filename[10] = {"file1.txt"};
                        readFromFile(filename,stor,count);
                        show(count,stor);
                        cout<<endl;

                        string temp;
                        int iteration;
                        int index;
                        for (iteration=0; iteration<count; iteration++)
                        {
                            for (index=0; index<count-iteration; index++)
                            {
                                if (stor[index] > stor[index+1])
                                            {
                                    temp = stor[index];
                                    stor[index] = stor[index+1];
                                        stor[index+1] = temp;
                                }
                            }
                       }

                       cout<<"view sorted data in ascending"<<endl;
                        cout<<"-----------------------------------------"<<endl;
                       show(count,stor);
                       cout<<endl;
                       cout<<endl;
                    }
                    else if(num== '4')
                    {
                        cout << "Enter word to search for: ";
                        cin >>search;
                        // open file to search
                        if(input_file.is_open()) {
                            unsigned int cLine = 0;
                            while(getline(input_file, line)) { // I changed this, see below
                                cLine++;
                                if (set = line.find(search, 0) != string::npos) {
                                    cout << "found: " << search << "line: " << cLine << endl;
                                }
                            }
                            input_file.close();
                        }
                    }
                    else if(num=='5')
                    {
                        int exit;
                        //checking if the user did not choose this by mistake
                        cout<<"you have choosen to exit the system, please reply 1 to comfirm or else 0"<<endl;
                        cin>>exit;

                        if(exit == 1)
                        {
                            cout<<"Thank you for using our system, Good Day"<<endl;
                            break;
                        }
                    }
                    else
                    {
                        cout<<"the number entered was invalid"<<endl;
                        break;
                    }
                    num--;
            }
        }
        else
        {
            cout<<"Thank you for using our system"<<endl;
        }
    return 0;
    return 0;
}
