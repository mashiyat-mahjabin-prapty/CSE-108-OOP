#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;

class String{
	char *s;  
	int len; 
public:  
	String(){
		s = NULL; 
		len = 0; 
		//cout << "Constructing....\n"; 
	}  
	String(char *p){
		len = strlen(p);
		s = new char[len+1];
		if(!s){
			cout << "Allocation error!";
			exit(1);
		}
		strcpy(s, p);
		//cout << "Constructing....\n";	
	} 
	/*String(const String &ob){
		//cout << "Calling copy constructor...\n";
		len = ob.len;
		s = new char[len+1];
		
		if(!s){
			cout << "Allocation error!";
			exit(1);
		}
		*s = '\0';
		strcpy(s, ob.s);
	}*/
	void setString(char *p){
		len = strlen(p);
		s = new char[len+1];
		if(!s){
			cout << "Allocation error!";
			exit(1);
		}
		strcpy(s, p);
	}
	int getLen(){
		return len;
	}
	String operator+(char *temp){
		String str;
		str.len = len+strlen(temp);
		str.s = new char[str.len+1];
		if(!str.s){
			cout << "Allocation error!";
			exit(1);
		}
		str.s = strcat(s, temp);
		// cout << str.s << endl;
		return str;
	}
	String operator+(int n){
		String str;
		char st[100];
		itoa(n, st, 10);
		str.len = len+strlen(st);
		str.s = new char[str.len+1];
		if(!str.s){
			cout << "Allocation error!";
			exit(1);
		}
		str.s = strcat(s, st);
		//cout << str.s << endl;
		return str;
	}
	String operator-(){
		String temp;
		temp.len = len;
		temp.s = new char[len+1];
		if(!temp.s){
			cout << "Allocation error!";
			exit(1);
		}
		for(int i = len-1, j = 0; i >= 0; i--, j++){
			temp.s[j] = s[i];
		}
		temp.s[temp.len] = '\0';
		//cout << temp.s << endl;
		return temp;
	}
	String operator*(int n){
		String temp;
		temp.len = len*n;
		temp.s = new char[temp.len+1];
		*temp.s = '\0';
		//cout << temp.s << endl;
		if(!temp.s){
			cout << "Allocation error!";
			exit(1);
		}
		for(int i = 0; i < n; i++){
			strcat(temp.s, s);
			//cout << temp.s << endl;
		}
		return temp;
	}
	char* getString(){
		return s;	
	}
	char &operator[](int index){
		return s[index];
	}
	String operator++(){
		String temp;
		temp.len = len;
		temp.s = new char[len];
		for(int i = 0; i < len; i++){
			temp.s[i] = ++s[i];
		}
		return temp;
	}
	String operator++(int notused){
		String temp;
		temp.len = len;
		temp.s = new char[len];
		for(int i = 0; i < len; i++){
			temp.s[i] = s[i]++;
		}
		return temp;
	}
	int operator>(String temp){
		int p = strcmp(s, temp.s);
		if(p == 1)
		return 1;
		else
		return 0;
	}
	int operator<(String temp){
		int p = strcmp(s, temp.s);
		if(p == -1)
		return 1;
		else
		return 0;
	}
	int operator==(String temp){
		int p = strcmp(s, temp.s);
		if(p == 0)
		return 1;
		else
		return 0;
	}
	/*~String(){
		delete[] s, s = NULL;
		//cout << "Destructing....\n";
	}*/
};

int binarySearch(String *array, int total, String p){
	int low = 0, high = total;
	while(low <= high){
		int mid = low + ((high-low)/2);
		if(array[mid] == p){
			return mid+1;
		}
		if (array[mid] < p)
            low = mid + 1; 
        else
            high = mid - 1; 
	}
	return -1;
}

void bubbleSort(String *arr, int total){
	for(int i = 0; i < total; i++){
		for(int j = 0; j < total-i-1; j++){
			if(arr[j] > arr[j+1]){
				String swap;
				swap = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = swap;
			}
		}
	}
}

String replaceAll(String str,char a,char b){ 
	for (int i=0;i<str.getLen();i++){
	 	if(str[i]==a){
			str[i]=b; 
		} 
	} 
	return str; 
}

int main(){  
	String s("BUET"),s1,s2; 
 
 	cout <<s.getString()<<endl;  
	// Should concat "CSE" at the end of "BUET"  
	s = s+"CSE";
	s1 = s;             
	cout<<s.getString()<<endl;  
	// Should concat "108" at the end of "BUETCSE"  
	s1 = s = s+108;   
	cout<<s1.getString()<<endl;  
	// Should reverse "BUETCSE108" and make it “801ESCTUEB”  
	s= - s;     
	cout<<s.getString()<<endl; 
	// s1 should be concatenated 3 times and stored in s2. If s1 contains “abc”, s2 should now contain “abcabcabc”  
	s2=s1*3;  
 	cout<<s2.getString()<<endl; 
 	
 	
 	char p[1000]; 
	String l("BUET"); 
	String strArray[20]; 
	for(int i=0;i<10;i++){ 
		cin>>p; 
		strArray[i].setString(p); 
	} 
	bubbleSort(strArray,10); 
	for(int i=0;i<10;i++){ 
		cout<<strArray[i].getString()<<endl; 
	} 
	cout<<binarySearch(strArray,10,l)<<endl; 
	l=replaceAll(l,'T','L'); // s should now contain "BUEL"
	cout<<(l++).getString()<<endl;
	// s should contain "CVFM" , but in the console the output should be "BUEL"
	cout<<l.getString()<<endl; // the output should be "CVFM"
} 
