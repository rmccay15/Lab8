#include <iostream>
#include <vector> 
#include <string> 
#include <cstring>
 
using namespace std; 
void menu();
class message{
	protected:  
		vector <char> message_input;
	public: 
		
		message();
		message(char* para_message); 
		~message(){};
		virtual void print_message(); 
};
		
message::message(char* para_message)
{
	int i=0;
	while(i<strlen(para_message))
	{
		message_input.push_back(para_message[i]);
		i++;	
	}
	
}
	
void message::print_message()
{
	int i=0;
	while(i<message_input.size())
	{
		cout<<message_input[i];
		i++;
	}
	
	

}		

message::message()
{
	char scan_message; 
	cout<<"Enter Message Consisting of Uppercase/Lowercase Letters, Numbers, or Symbols Respresented in the Morse Code Alphabet, End With An Asterisk: "<<endl;
	while(cin>>scan_message && scan_message!='*')
	{
		message_input.push_back(scan_message);
	}
}


class morseCodeMessage:public message
{
	private: 
		vector <string> morseMessage; 
	public: 
		void translate(); 
		void print_message();
		morseCodeMessage();
		morseCodeMessage(char* par_message);
		~morseCodeMessage(){}; 
		
};	
morseCodeMessage::morseCodeMessage():message(){}
morseCodeMessage::morseCodeMessage(char* par_message):message(par_message){}	

void morseCodeMessage::print_message()
{
	cout<<"\n*****************MESSAGE IN TEXT****************"<<endl;
	for(int i=0;i<message_input.size();i++)
	{
		cout<<message_input[i];
	}
	cout<<endl;
	cout<<"\n*****************MESSAGE IN MORSE CODE*****************"<<endl;
	for(int i=0;i<morseMessage.size();i++)
	{
		cout<<morseMessage[i]<<" ";
	}
}

void morseCodeMessage::translate()
{
	
	char text[68] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0','.',',',' '}; 
	string morse[68] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.","--.-", ".-.", "...", "-", "..-", "...-", ".--","-..-", "-.--", "--..",".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",".----",
                    "..---","...--","....-",".....","-....","--...","---..","----.","-----",".-.-.-","--..--","/"};
	int i=0;
	while(i<message_input.size())
	{
		
		for(int j=0;j<68;j++)
		{
			if(message_input[i] == text[j])
			{
				morseMessage.push_back(morse[j]);
				
			}
		}	
		
		i++;
	}
	
	
}



template <class any_message> 	
class Stack{
	private: 
		Stack *top=NULL;
		Stack *current; 
	public: 
		Stack(any_message &obj);
		void pop();
		void push();
		void print_stack();
};
template <class any_message> Stack<any_message>::Stack(any_message &obj)
{
	
	int choice;
	cout<<endl;
	cout<<"\n==============MENU================\n1. Push()\n2. Pop()\n3. Print_Stack()\n0. Exit: "<<endl;
	cin>>choice;
	while(choice!=0)
	{
		switch(choice)
		{
			case 1: 
				
				push();
				break;
			case 2:
				
				break;
			case 3: 
				
				break;
			default: 
				break;
		}
		cout<<"\n==============MENU================\n1. Push()\n2. Pop()\n3. Print_Stack()\n0. Exit: "<<endl;
			cin>>choice;	
		
	}
	
}
template <class any_message> void Stack<any_message>::push()
{
	
}
		
template <class any_message> void Stack<any_message>::pop()
{
	
}	
	
template <class any_message> void Stack <any_message>::print_stack()
{
}

int main(int argc,char* argv[])
{
	if(argc==1){
		message note;
		note.print_message();
		Stack <message> mess(note);
		 
	}else{
		char* help;
		help = argv[1];
		
		for(int i=2;i<argc;i++)
		{
			help = strcat(help," ");
			help = strcat(help,argv[i]);
		}
		help = strcat(help," ");
		morseCodeMessage mess1(help);

		mess1.translate();
		mess1.print_message();
		Stack <morseCodeMessage> mess2(mess1);
		 
	}
	return 0;
}	