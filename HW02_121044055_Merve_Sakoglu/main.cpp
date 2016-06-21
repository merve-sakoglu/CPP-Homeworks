/********************************
*	CSE 241 HW02            *
*	MERVE SAKOGLU           *
*	121044055               *
*	                        *
*                               *
********************************/
#include<iostream>
#include <cstdlib>
#include<cstring>
using namespace std;

class DayOfYear{
	public:
		int day;
		int month;
		int year;
		void output();
};
typedef struct{

	char name[50];
	int age;

}Person;
//Int arrayleri karsilastirir
bool equalsInt(const void *num1,const void *num2);
//Double arrayleri karsilastirir
bool equalsDouble(const void *num1,const void *num2);
//Char arrayleri karsilastirir
bool equalsChar(const void *num1,const void *num2);
//Person icin isim ve yaslari karsilastirir
bool equalsPerson(const void *num1,const void *num2);
//DayOfYear icin gun ay ve yil karsilastiri
bool equalsDayOfYear(const void *num1,const void *num2);
int return_mode (const void * base, size_t num, size_t size,
                 bool (* equals) (const void *, const void *));

int main(){
	
	int intArr[] = {1,1,1,2,7,2,8,9,10,4};
	double doubleArr[] = {1.1,3.2,6.3,1.1,3.2,5.6,6.7,1.3,6.3,6.4};
	char charArr[] = "abbdefddd";
	Person person[] = {{"ela",15},{"ela",15},{"ali",3},{"sude",3}};
	DayOfYear day[] = {{1,8,1994},{1,8,1994},{2,10,1995},{2,10,1996},{2,10,1995}};
	int temp =0;
	
	cout << "**********INTEGER TEST**********\n";
        
        //int array size ini bulur
        int sizeofInt = sizeof(intArr) / sizeof(int);

	cout << "Array Elemanlari\n";
	for(int i=0 ; i<sizeofInt; ++i){
		
		cout << intArr[i] << "  ";
	}
	cout << endl;
	
	temp = return_mode (intArr,sizeofInt, sizeof(int),equalsInt);
	cout << temp << ". Adress\n\n\n" ;
	
	
	cout << "**********DOUBLE TEST**********\n";
        
        //Double array size ini bulur
        int sizeofDouble = sizeof(doubleArr) / sizeof(double);

	cout << "Array Elemanlari\n";
	for(int j=0 ; j<sizeofDouble ; ++j){
		
		cout << doubleArr[j] << "  ";
	}
	cout << endl;
	
	temp = 0;
	temp = return_mode (doubleArr,sizeofDouble, sizeof(double),equalsDouble);
	cout << temp << ". Adress\n\n\n" ;
	
	
	cout << "**********CHAR TEST**********\n";

        int sizeofChar = sizeof(charArr) / sizeof(char);

	cout << "Array Elemanlari\n";
	for(int k=0 ; k<sizeofChar ; ++k){
		
		cout << charArr[k] << "  ";
	}
	cout << endl;
	
	temp = 0;
	temp = return_mode (charArr,sizeofChar, sizeof(char),equalsChar);
	cout << temp << ". Adress\n\n\n" ;
	
	
	cout << "**********PERSON TEST**********\n";

        int sizeofPerson = sizeof(person) / sizeof(Person);

	cout << "Array Elemanlari\n";
	for(int l=0 ; l<sizeofPerson ; ++l){
		
		cout << person[l].name << "  " << person[l].age << endl;
	}
	cout << endl;
	
	temp = 0;
	temp = return_mode (person,sizeofPerson, sizeof(Person),equalsPerson);
	cout << temp << ". Adress\n\n\n" ;
	
	
	cout << "**********DAYOFYEAR TEST**********\n";
        
        int sizeofDay = sizeof(day) / sizeof(DayOfYear);

	cout << "Array Elemanlari\n";
	for(int m=0 ; m<sizeofDay ; ++m){
		 
	     cout << day[m].day << " ";
	     day[m].output();
	     cout << " ";
	     cout << day[m].year << endl;
	}
	cout << endl;
	
	temp = 0;
	temp = return_mode (day,sizeofDay, sizeof(DayOfYear),equalsDayOfYear);
	cout << temp << ". Adress\n" ;
	
	return 0;
}
bool equalsInt(const void *num1,const void *num2){
	
	//int sayilar esitse true degilse false dondurur
	if(*(int*) num1 == *(int*) num2)
		return true;
        else
                return false;
	
}
bool equalsDouble(const void *num1,const void *num2){
	
	if(*(double*) num1 == *(double*) num2)
		return true;
        else
                return false;
	
}
bool equalsChar(const void *num1,const void *num2){
	
	char ch1 = *(char*)num1;
	char ch2 = *(char*)num2;
	
	if(ch1 == ch2)
		return true;
	else
		return false;
}
bool equalsPerson(const void *num1,const void *num2){

	 Person person1 = *(Person*)num1;
	 Person person2 = *(Person*)num2;
	 
	 if((strcmp(person1.name , person2.name) == 0) && (person1.age == person2.age))
	 	return true;
	 else
	 	return false;

}
bool equalsDayOfYear(const void *num1,const void *num2){
	
	DayOfYear date1 = *(DayOfYear*)num1;
	DayOfYear date2 = *(DayOfYear*)num2;
	
	if((date1.day == date2.day) && (date1.month == date2.month) && (date1.year == date2.year))
		return true;
	else
		return false;

}
void DayOfYear::output(){
	
	switch(month){
		
		case(1):
			cout << "January";
			break;
		case(2):
			cout << "February";
			break;
		case(3):
			cout << "March";
			break;
		case(4):
			cout << "April";
			break;
		case(5):
			cout << "May";
			break;
		case(6):
			cout << "June";
			break;
		case(7):
			cout << "July";
			break;
		case(8):
			cout << "August";
			break;
		case(9):
			cout << "September";
			break;
		case(10):
			cout << "October";
			break;
		case(11):
			cout << "November";
			break;
		case(12):
			cout << "December";
			break;
		
		default:
			cout << "Invalid Value\n";	
	}
	
}
int return_mode (const void * base, size_t num, size_t size,
                 bool (* equals) (const void *, const void *)){
                 
	int count = 0,newcount =0;
	char *elem = (char*)base;
	int j = 0;
	int adress = 0;
	       
	//Array bos ise uyari yazisi yazar        
	if((base == NULL) || (num == 0)){
		
		cout << "Empty Array!!!\n";
                return -1;
	//Array tek elemanli ise ilk adresi dondurur	
	}else if(num == 1){
		
		return false;
	}else{
		
		//Array elemanlari icinde dolanir
		for(int i=0; i<num ;++i){
			
			//Arrayde her index icin elemani icin saydiktan sonra count u sıfırlar
			count = 0;
			for(j=i + 1; j<num ; ++j){
					
					//Array elemanlari esitse true doner ve count u bir artirir
					if(equals(elem + (size*i), elem + (size*j)) == true){
						++count;
					}
				
			}
			//En buyuk count u bulur
			if(count > newcount){
				
				//En buyuk count un index ini adress e atar
				adress = i;
				newcount = count;
			}
		
		}
	} 
    
    //Index i dondurur
    return adress;     
}

