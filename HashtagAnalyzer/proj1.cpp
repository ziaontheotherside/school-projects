/* File:      proj1.cpp
Author:       Zia Animashaun
Date:         09/20/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to be creating a hashtag analyzer that will parse
a file of messages and a file of hashtags to see if the hashtags are used in the messages.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_HASHTAGS = 20;
const int MAX_MESSAGES = 20;

string turnStringArraytoString(string arr[]);
string turnIntArraytoString(int arr[]);
string getHashtags(string file);
string findMatching(string hashtags, string messages[]); //Prints messages with a found hashtag and also returns the counts of how many times a hashtag was seen
void printHashtagCounts(string hashtags, string counts);

int main() {
    string hashtags; //"#Google#Amazon#TheZucc
    string messages[MAX_MESSAGES];
    string hashtagFile, messageFile;
    string matches; //10101
    bool playing = true;
    char choice;
    do {
        bool validFile = false;
        do {
            cout << "What file of hashtags do you want to use?" << endl;
            cin >> hashtagFile;
            ifstream in(hashtagFile);
            if(!in) {
                cout << "File could not be opened, please try again.\n";
            }
            else {
                validFile = true;
                in.close();
            }
        } while(!validFile);
        validFile = false;
        do {
            cout << "What line of messages do you want to use?" << endl;
            cin >> messageFile;
            ifstream in(messageFile);
            if(!in) {
                cout << "File could not be opened, please try again.\n";
            }
            else {
                validFile = true;
                in.close();
            }
        } while(!validFile);
        hashtags = getHashtags(hashtagFile);


        ifstream in(messageFile);
        string line;
        for(int i=0; i<MAX_MESSAGES; i++) {
            if(in && getline(in, line)) {
                messages[i] = line;
            }
            //else { break; } but I guess we can't use this?????
        }


        cout << "Messages with matching hashtags:" << endl;
        matches = findMatching(hashtags, messages);
        cout << "Hashtag Stats:" << endl;
        printHashtagCounts(hashtags, matches);
        cout << "Would you like to process another set of files? y/n" << endl;
        cin >> choice;
        if(choice == 'n' || choice == 'N') {
            playing = false;
        }
    }
    while (playing);
}


string turnStringArraytoString(string arr[]){

    string thestring = "";
    for(int i =0; i<NUM_HASHTAGS; i++){
        thestring += arr[i];
    }
    return thestring;
}

string turnIntArraytoString(int arr[]){
    string thestring ="";
    for(int i =0; i<NUM_HASHTAGS; i++){
        thestring += to_string(arr[i]);
    }
    return thestring;
}
string getHashtags(string file) {
    string hashtags [NUM_HASHTAGS]; //pointer
    ifstream in(file);
    for(int i=0; i<NUM_HASHTAGS; i++) {
        in >> hashtags[i];
    }
    string stringhashtag = turnStringArraytoString(hashtags);
    return stringhashtag;
}



string findMatching(string hashtags, string messages[]) {
    int matchCount = 1;
    int hashtagMatchCount [NUM_HASHTAGS];



    for(int i=0; i<NUM_HASHTAGS; i++) {
        hashtagMatchCount[i] = 0; //initialize all hashtag counts to 0
    }
    for(int i=0; i<MAX_MESSAGES; i+=2) {
        if(messages[i] != "" && messages[i+1] != "") {
            //Attempt to find message[i], the hashtag for this message, within the array of hashtags
            bool alreadyfound = false;
            stringstream theHashtags(hashtags);
            string thefirsthash;
            getline(theHashtags, thefirsthash, '#');
            for (int j = 0; j < NUM_HASHTAGS; j++) {
                string thehashtagstring;
                getline(theHashtags, thehashtagstring, '#');
                thehashtagstring = '#' + thehashtagstring;
                if (!alreadyfound && messages[i] == thehashtagstring) {
                    cout << matchCount << ". " << thehashtagstring << " " << messages[i + 1] << endl;
                    matchCount++;
                    hashtagMatchCount[j]++;
                    alreadyfound = true;
                }
            }
        }
    }

    string stringOfMatches = turnIntArraytoString(hashtagMatchCount);

    return stringOfMatches;
}


void printHashtagCounts(string hashtags, string counts) {
    string thefirsthash;
    stringstream theHashtags(hashtags);
    getline(theHashtags, thefirsthash, '#');
    for(int i=0; i<NUM_HASHTAGS; i++) {
        string thehashtagstring;
        getline(theHashtags, thehashtagstring, '#');
        thehashtagstring = '#' + thehashtagstring;
        cout << left << setw(4) << i+1 << "\t" << setw(16) << thehashtagstring<< "\t" << setw(4) << counts.at(i) << endl;
    }
}