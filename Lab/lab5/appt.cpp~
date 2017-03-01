// appt.cpp
// Purpose: To make a simple appointment calendar
//      By: Rui Qin
//    Date: 3/2/2016

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

struct Time {
	int hour;
	int minutes;
	bool AM;
};

struct Appointment {
	// TODO: STUDENT CODE HERE
	 Time time;
	 int duration;
	 string name, email;
	 bool cancelled;
};

const int MAX_APPTS = 100;
const string FILENAME = "appointments.data";

// function definitions (written already)
int read_appointments(Appointment appointments[],const string filename);
void program_menu(Appointment appointments[], int len);
void name_search(Appointment apps[], int len);
void update_appts(Appointment appointments[],int len, Appointment single_appt);

// function definitions (students write code at the bottom of the file)
void print_one_appointment(Appointment app);
void print_all_appointments(Appointment apps[], int len);
Appointment cancel_appointment(Appointment app);
Appointment search_for_appointment(Appointment apps[], int len, string name);

int main()
{
	int length;
	Appointment appointments[MAX_APPTS];
	length = read_appointments(appointments,FILENAME);
	program_menu(appointments,length);
	return 0;
}

// purpose: to read in the appointments from a file.
// arguments: An Appointment array with empty entries
// return value: the number of entries read
int read_appointments(Appointment appointments[], const string filename)
{
	string line;
	int appt_count = 0;
	// read in the data one line at a time
	ifstream appt_file (filename.c_str());
	if (appt_file.is_open()){
		while ( getline (appt_file,line) )
		{
			// the first line is a time hours (e.g., 10)
			appointments[appt_count].time.hour = atoi(line.c_str());

			// the second line is a time minutes (e.g., 30)
			getline (appt_file,line);
			appointments[appt_count].time.minutes
				= atoi(line.c_str());

			// the third line is either AM or PM
			getline (appt_file,line);
			appointments[appt_count].time.AM = (line == "AM");

			// the fourth line is a duration
			getline (appt_file,line);
			appointments[appt_count].duration = atoi(line.c_str());

			// the fifth line is a name
			getline (appt_file,line);
			appointments[appt_count].name = line;

			// the sixth line is an email
			getline (appt_file,line);
			appointments[appt_count].email = line;

			// the seventh line is a cancellation (true or false)
			getline (appt_file,line);
			appointments[appt_count].cancelled 
                                = (line == "true");

			appt_count++;
		}
		appt_file.close();
	}
	else {
		cout << "Unable to open file" << endl;
		exit(1);
	}
	return appt_count;
}

// purpose: to have a program menu that asks for tasks.
// arguments: An Appointment array and a length of the array
// return value: none (void function)
void program_menu(Appointment appointments[], int len)
{
	char input = ' ';

	cout << "Welcome to the Appointment Scheduler." << endl;
	cout << "I have read in your appointments." << endl;

	while (input != 'q') {
		cout << "Menu:" << endl;
		cout << "\t(p)rint all pending appointments" << endl;
		cout << "\t(s)earch for an appointment" << endl;
		cout << "\t(q)uit the program" << endl << endl;

		cout << "Please choose from the menu above: ";
		cin >> input;

		switch(input) {
			case 'p' : cout << endl;
				   print_all_appointments(appointments,len);
				   break;

			case 's' : name_search(appointments, len);
				   break;

			case 'q' : return;
				   break;
		}
	}
}

// purpose: Ask for a name and perform a search
//          then ask if they want to cancel the appointment
// arguments: An Appointments array, a length of the array
// return value: none (void)
void name_search(Appointment apps[], int len)
{
	Appointment single_appt;
	string name;
	char answer;

	cin.ignore(256, '\n'); // ignore newline due to character input
	cout << "Name? ";
	getline(cin,name);

	single_appt = search_for_appointment(apps,len,name);
	if (single_appt.name == "--NOT FOUND--") {
		cout << "Name not found." << endl;
	}
	else {
		print_one_appointment(single_appt);
		if (single_appt.cancelled) {
			cout << "*****This appointment has been cancelled.*****"
			     << endl;
		}
		else {
			cout << "Would you like to ";
			cout << "cancel this appointment? (y/n)";
			cin >> answer;
			if (answer == 'y') {
				single_appt = cancel_appointment(single_appt);
				update_appts(apps,len,single_appt);
				cout << "Appointment for "
				     << single_appt.name
				     << " canceled." << endl;
			}
		}
	}
}

// purpose: replace the appointment in all[] with app
//          based on the name of the appointment-holder
// arguments: Appointment array, length of the array, and an appointment
// return value: none (void function)
void update_appts(Appointment all[],int len,Appointment app)
{
	for (int i=0; i < len; i++) {
		if (all[i].name == app.name) {
			all[i] = app;
			return;
		}
	}
}

// ********************** TODO: STUDENT CODE BELOW THIS LINE ************************
// purpose: prints out an appointment in the following form:
//          Appointment time: XX:XX PM    (or AM)
//          Duration: XX minutes
//          Name: NAME
//          Email: EMAIL
//          (blank line)
// arguments: An Appointment to print
// return value: none (void function)
void print_one_appointment(Appointment app)
{	if (app.time.AM){
	cout << "Appointment time: " << app.time.hour << ":" << app.time.minutes << " " << "AM" << endl;
	}
	else{
	cout << "Appointment time: " << app.time.hour << ":" << app.time.minutes << " " << "PM" << endl;
	}
	
	cout << "Duration: " << app.duration<< "minutes" << endl;
	cout << "Name: " << app.name << endl;
	cout << "Email: " << app.email<< endl;
	cout << endl;
	// TODO: STUDENT CODE HERE
}

// purpose: prints out all appointments THAT ARE NOT CANCELLED
//          and uses print_one_appointment() to do so.
// arguments: An Appointment array and a length of the array
// return value: none (void function)
void print_all_appointments(Appointment apps[], int len)
{	
	for(int i=0;i<len;i++){
		if (apps[i].cancelled == false){
			print_one_appointment(apps[i]);
		}
	
	}
	
	
	// TODO: STUDENT CODE HERE
}


// purpose: cancels an appointment
// arguments: An Appointment
// return value: an Appointment with the updated cancellation
Appointment cancel_appointment(Appointment app)
{	
	
	app.cancelled = true;
	return app;
	
	
	// TODO: STUDENT CODE HERE
}

// purpose: Searches for an appointment by the person's name
//          and returns the appointment
// arguments: An Appointments array, a length of the array,
//            and a string with the name
// return value: The appointment of the person searched for
// Notes: If the person is not found, return an empty Appointment
//        with the name equal to "--NOT FOUND--"
Appointment search_for_appointment(Appointment apps[], int len, string name)
{
	for(int i=0;i<len;i++){
		if(apps[i].name == name){
			return apps[i];
		}
	}
		
		
		Appointment err;
		err.name = "--NOT FOUND--";
		return err;
	
	
	
	// TODO: STUDENT CODE HERE
}
