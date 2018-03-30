//============================================================================
// Name        : BPokhrel4.cpp
// Author      : Baivab Pokhrel
// Version     :
// Copyright   : Your copyright notice
// Description : Justification
//============================================================================

#include <iostream>
#include <vector>
#include<cstring>
using namespace std;


void Adjust (vector<string>& s) //function to maintain the adjustment given by user
{
	while (true)//infinite loop going through whole program and breaking if the user input is 0
 {
		int width;//to get the user input
		int begin=0;
		int words=0;

		vector<string> input_word1;
		cout << "Enter the width of text: " ;//prompt to ask for user input
		cin >> width;//to store user input in width
		if (width == 0)//if user input is 0 we need to break and get out of loop as it is a infinite loop
		  {
			break;
		  }

		for (int i = 0; i < width; ++i) //function to print the top half of the border
		  {
			if (i == 0) cout << "|" ;
			cout << "-" ;
			if (i == width - 1) cout << "|" << endl ;
		  }

		for (int i = 0; i < s.size(); ++i)//loop that goes through all the words in our vector where we stored our tokanized words
		 {
			int space;
			int white;

			words += s[i].length();//adding words with out vector size,i.e number of words entered
			space = i - begin;  //giving spaces a value by assuming there is a space after each word
			white = words + space;//total letters in a line with spaces.


			if (width - white >= 0) //check if we have space to put more words as compared with user input width
			 {
				input_word1.push_back(s[i]);//adding i(th) word to our new vector
				if (i == s.size() - 1)//to check if our word fits in the line
				  {
					  white = width - words;//to see remaining spaces after out word in the given width


					  while (white > 0)//if can fit more than one space as until it can fit no spaces evenly
					   {
						   for (int j = 0; j < input_word1.size(); ++j)//loop to add spaces after loop
						     {
							    if (white == 0)
							     {
								    break;//break if no more spaces available
							     }
							    input_word1[j] += " ";//add space after our word
							    white -= 1;//reducing the width remaining by one
						     }
					     }



					   for (int j = 0; j < input_word1.size(); ++j)//loop to print the word
					     {
						  if (j == 0) cout << "|";
						  cout << input_word1[j];//output our word in vector with their space
						  if (j == input_word1.size() - 1) cout << "|" << endl;
					      }

					   input_word1.clear();//clearing our vector for second try
					   begin = i;//beginning from one next we started from
					   words = 0;//making words zero to use it for next loop
			 	  }
			    }


			if (width - white < 0)//to check if it has few more entries left after previous try
			 {
			   white = width - (words - s[i].length());//remaining spaces


			    while (white > 0) //loop to run until there is room
				  {
					for (int j = 0; j < input_word1.size(); ++j)//loop to see if there is room and add space to  that word
					  {
						if (white == 0 || j == input_word1.size() - 1)
						  {
							break;//break if undesired condition
						  }
						input_word1[j] += " ";
						white -= 1;
					  }
				   }


				 for (int j = 0; j < input_word1.size(); ++j)//loop to print the line
				  {
					if (j == 0) cout << "|";
					cout << input_word1[j];//printing the word along with the space
					if (j == input_word1.size() - 1) cout << "|" << endl;
				   }

				 input_word1.clear();//clearing the vector
				 begin = i;//changing begin by 1 if reaches this case
				 words = 0;
				 i -= 1;//reducing i by 1 if reaches this case
			}
		}

		for (int i = 0; i < width; ++i)//loop to output the lower half of the border
		 {
			if (i == 0) cout << "|" ;
			cout << "-" ;
			if (i == width - 1) cout << "|" << endl;
		 }

 }

}
int main()
{
    string content;//to store input sentence
    vector<string> input_word;//vector to store every words in input
    cout << "Enter text, empty return will quit the input" << endl << "> ";//outpput prompt for asking user a input
    while(getline(cin,content)) //loop to get the input
    {
        string word;
        
        if (content == "")
        {
            break;//break the loop if input is empty
        }
        
        cout << "> ";
        for (int i = 0; i < content.length(); ++i)//loop to add entered string as token to a vector if its not a space
        {
            
            if (content[i] != ' ' && content[i] != '\t' )//check the input word if its space or not and if it is not a space add that letter to a empty string
            {
                word += content[i];
            }
            
            if ((i != 0 && content[i] == ' ' && content[i-1] != ' ') || i == content.length() - 1)//add that string to our vector if it has space as next character
            {
                input_word.push_back(word);//adding that word to our vector
                word.clear();// clearing our word  so that we could use it for next loop
            }
        }
    }
    Adjust(input_word);    //vector containing all the  words as single unit of vector is now sent to our function o adjust it as user input
    
    
    return 0;
}



