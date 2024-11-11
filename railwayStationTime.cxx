#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	//string time = "23:59";
	//cout << time.length();
	cout << "Welcom to train!\n";
	
	int departureHour = 0;
	int departureMinute = 0;
	int arrivalHour = 0;
	int arrivalMinute = 0;
	bool correct = true;
	
	do {		
		string error = "ERROR!\nTime is specified in the format of HH:MM\n";
		if (!correct) 
			cout << error;
		
		cout << "Enter the departure time(HH:MM): ";
		string departureTime = "\0";
		cin >> departureTime;
		
		cout << "Enter the arrival time(HH:MM): ";
		string arrivalTime = "\0";
		cin >> arrivalTime;
		
		/*for (int i = 0; i < 5; i++) {
			cout << i << " : " <<departureTime[i] << endl;
			cout << i << " : " << arrivalTime[i] << endl;
		}*/
		
		//проверяю на длину массива, что бы потом не былоьошибок
		if (departureTime.length() != 5 || arrivalTime.length() != 5) {
			correct = false;
			continue;
		} else {
			correct = true;
		}
		
		//проверяю на корректность цифр как символов
		for (int i = 0; i < 5; i++) {
			i == 2 ? ++i : i;
			if ((departureTime[i] >= 48 && departureTime[i] <= 57) || (arrivalTime[i] >= 48 && arrivalTime[i] <= 57)) {
				correct = true;
				continue;
			} else {
				correct = false;
				break;
			}
		}
		
		//проверяю что третий символ - двоеточие
		if (departureTime[2] != ':' || arrivalTime[2] != ':') {
			correct = false;
			continue;
		} else {
			correct = true;
		}
		
		//проверяю правильность ввода часов и минут (23 часа и 59 минут)
		departureHour = (departureTime[0] - 48) * 10 + (departureTime[1] - 48);
		departureMinute = (departureTime[3] - 48) * 10 + (departureTime[4] - 48);
		arrivalHour = (arrivalTime[0] - 48) * 10 + (arrivalTime[1] - 48);
		arrivalMinute = (arrivalTime[3] - 48) * 10 + (arrivalTime[4] - 48);
		
		//cout << departureHour << ':' << departureMinute << endl;
		//cout << arrivalHour << ':' << arrivalMinute << endl;
		
		if (departureHour >= 24 || departureMinute >= 60 || arrivalHour >= 24 || arrivalMinute >= 60 ) {
			cout << "Not correct time format\n";
			correct = false;
			continue;
		} else {
			cout << "~~~Waiting~~~\n";
			correct = true;
		}
			
	} while (!correct);
	
	int  departureTime = departureHour * 60 + departureMinute;
	int arrivalTime = arrivalHour * 60 + arrivalMinute;
	if (departureTime > arrivalTime) 
		arrivalTime += 24 * 60;
	int travelTime = arrivalTime - departureTime;
	
	//перевожу число в строку
	string travelHour = to_string(travelTime / 60);
	if (travelTime / 60 < 10) 
		travelHour = '0' + travelHour;
	string travelMinute = to_string(travelTime % 60);
	if (travelTime % 60 < 10)
		travelMinute = '0' + travelMinute;
	string travel = travelHour + ':' + travelMinute;
	
	cout << "Travel time: " << travel << endl;
	
	//cout << correct;
	//cout << departureTime << endl << arrivalTime << endl;

	return 0;
}