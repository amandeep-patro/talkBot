#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include <ctime>
#include <cmath>
#include<stdlib.h>
using namespace std;
class main{
public:
    string input;
};
class FileOpener : public main {
public:
    void open() {
        string l;
        cout << "Enter the file path: ";
        getline(cin, l);
        ShellExecute(NULL, "open", l.c_str(), NULL, NULL, SW_NORMAL);
    }
};

class SystemManager : public main {
public:
    void shutdown() {
        system("C:\\WINDOWS\\System32\\shutdown -s -t 5");
    }

    void restart() {
        system("C:\\WINDOWS\\System32\\shutdown -r -t 5");
    }
};

class InternetBrowser : public main  {
public:
    void search() {
        string query;
        cout << "Enter a search query: ";
        getline(cin, query);
        string url1 = "https://www.google.com/search?q=" + query;
        string url2 = "https://www.youtube.com/search?q=" + query;
        ShellExecute(NULL, "open", url1.c_str(), NULL, NULL, SW_SHOWNORMAL);
        ShellExecute(NULL, "open", url2.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }
};

class ChatBot : public main  {
public:
    void chat() {
        cout<<"WELCOME SIR"<<endl;
        const int MAX_RESPONSES = 1000;
        string filename = "responses.txt";
        string inputs[MAX_RESPONSES];
        string responses[MAX_RESPONSES];
        int num_responses = 0;

        ifstream infile(filename);
        if (infile.is_open()) {
            string input, response;
            while (getline(infile, input) && num_responses < MAX_RESPONSES) {
                getline(infile, response);
                inputs[num_responses] = input;
                responses[num_responses] = response;
                num_responses++;
            }
            infile.close();
        }

        string input;
        while (true) {
            cout << "You: ";
            getline(cin, input);
            if (input == "exit") {
                cout << "Chatbot: Goodbye!" << endl;
                exit(0);
            }
            bool found_response = false;
            for (int i = 0; i < num_responses; i++) {
                if (inputs[i] == input) {
                    cout << "Chatbot: " << responses[i] << endl;
                    found_response = true;
                    break;
                }
            }

            if (!found_response) {
                string response;
                cout << "Chatbot: I don't know the answer. Please provide a response: ";
                getline(cin, response);
                inputs[num_responses] = input;
                responses[num_responses] = response;
                num_responses++;

                ofstream outfile(filename, ios_base::app);
                if (outfile.is_open()) {
                    outfile << input << endl;
                    outfile << response << endl;
                    outfile.close();
                } else {
                    cout << "Error: unable to open file for writing." << endl;
                }
                cout << "Chatbot: Thanks! I'll remember that." << endl;
            }
        }
    }
};

class Calculator : public main  {
    public:
        void calc(){
            int choice;
            double result, num;

            cout << "Scientific Calculator\n";
            cout << "---------------------\n";
            cout << "Enter your choice:\n";
            cout << "1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication\n";
            cout << "4. Division\n";
            cout << "5. Power function\n";
            cout << "6. Square root function\n";
            cout << "7. Sine function\n";
            cout << "8. Cosine function\n";
            cout << "9. Tangent function\n";
            cout << "10. Logarithm function\n";
            cout << "11. Factorial function\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    cout << "Enter two numbers: ";
                    double num1, num2;
                    cin >> num1 >> num2;
                    result = num1 + num2;
                    cout << "Result: " << result << endl;
                    break;
                case 2:
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    result = num1 - num2;
                    cout << "Result: " << result << endl;
                    break;
                case 3:
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    result = num1 * num2;
                    cout << "Result: " << result << endl;
                    break;
                case 4:
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    if (num2 == 0) {
                        cout << "Error: division by zero\n";
                    } else {
                        cout << "Result: " << num1 / num2 << endl;
                    }
                    break;
                case 5:
                    cout << "Enter a number and its power: ";
                    cin >> num1 >> num2;
                    result = pow(num1, num2);
                    cout << "Result: " << result << endl;
                    break;
                case 6:
                    cout << "Enter a number: ";
                    cin >> num1;
                    if (num1 < 0) {
                        cout << "Error: cannot take square root of negative number\n";
                    } else {
                        result = sqrt(num1);
                        cout << "Result: " << result << endl;
                    }
                    break;
                case 7:
                    cout << "Enter an angle in degrees: ";
                    cin >> num1;
                    result = sin(num1 * M_PI / 180.0);
                    cout << "Result: " << result << endl;
                    break;
                case 8:
                    cout << "Enter an angle in degrees: ";
                    cin >> num1;
                    result = cos(num1 * M_PI / 180.0);
                    cout << "Result: " << result << endl;
                    break;
                case 9:
                    cout << "Enter an angle in degrees: ";
                    cin >> num1;
                    if (cos(num1 * M_PI / 180.0) == 0) {
                        cout << "Error: tangent undefined\n";
                    } else {
                        result = tan(num1 * M_PI / 180.0);
                        cout << "Result: " << result << endl;
                    }
                    break;
                case 10:
                    cout << "Enter a number and its base: ";
                    cin >> num1 >> num2;
                    if (num1 <= 0 || num2 <= 0) {
                        cout << "Error: arguments must be positive\n";
                    } else {
                        result = log(num1) / log(num2);
                        cout << "Result: " << result << endl;
                    }
                    break;
                case 11:
                    cout << "Enter a non-negative integer: ";
                    int n;
                    cin >> n;
                    if (n < 0) {
                        cout << "Error: argument must be non-negative\n";
                    } else {
                        result = 1;
                        for (int i = 1; i <= n; i++) {
                            result *= i;
                        }
                        cout << "Result: " << result << endl;
                    }
                    break;
            }
    }
};
int main() {
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    cout << "Date  " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
    cout << "Time  " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<< endl;
     cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::WELCOME:::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"EVERYDAY IS A NEW BEGINNING. LET\'S BEGIN!.....";
    cout<<endl<<endl;
    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. Open a file" << endl;
        cout << "2. Shutdown computer" << endl;
        cout << "3. Restart computer" << endl;
        cout << "4. Search the internet" << endl;
        cout << "5. Talk to the chatbot" << endl;
        cout << "6. Calculator" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                FileOpener f;
                f.open();
                break;
            }
            case 2: {
                SystemManager s;
                s.shutdown();
                break;
            }
            case 3: {
                SystemManager s;
                s.restart();
                break;
            }
            case 4: {
                InternetBrowser i;
                i.search();
                break;
            }
            case 5: {
                ChatBot c;
                c.chat();
                break;
            }
            case 6: {
                Calculator cl;
                cl.calc();
                break;
            }
            case 7: {
                cout << "Goodbye!" << endl;
                exit(0);
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                break;
            }
        }
        string kk;
        cin>>kk;
        if (kk=="`"){
            system("CLS");
            time_t t = time(NULL);
            tm* timePtr = localtime(&t);
            cout << "Date  " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
            cout << "Time  " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<< endl<<endl<<endl;
        }
    }
    return 0;
}

