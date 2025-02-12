/* File:      proj1.cpp
Author:       Zia Animashaun
Date:         09/20/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to be creating a hashtag analyzer that will parse
a file of messages and a file of hashtags to see if the hashtags are used in the messages.
*/

/* #include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

const int NUM_HASHTAGS = 20;
const int MAX_MESSAGES = 20;

string* getHashtags(string file);
string* getMessages(string file);
int* findMatching(string* hashtags, string* messages); //Prints messages with a found hashtag and also returns the counts of how many times a hashtag was seen
void printHashtagCounts(string* hashtags, int* counts);

int main() {
    string* hashtags;
    string* messages;
    string hashtagFile, messageFile;
    int* matches;
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
        messages = getMessages(messageFile);
        cout << "Messages with matching hashtags:" << endl;
        matches = findMatching(hashtags, messages);
        cout << "Hashtag Stats:" << endl;
        printHashtagCounts(hashtags, matches);
        delete [] hashtags;
        delete [] messages;
        delete [] matches;
        cout << "Would you like to process another set of files? y/n" << endl;
        cin >> choice;
        if(choice == 'n' || choice == 'N') {
            playing = false;
        }
    }
    while (playing);
}


string* getHashtags(string file) {
    string* hashtags = new string[NUM_HASHTAGS];
    ifstream in(file);
    for(int i=0; i<NUM_HASHTAGS; i++) {
        in >> hashtags[i];
    }
    return hashtags;
}

string* getMessages(string file) {
    string* messages = new string[MAX_MESSAGES];
    ifstream in(file);
    string line;
    for(int i=0; i<MAX_MESSAGES; i++) {
        if(in && getline(in, line)) {
            messages[i] = line;
        }
        //else { break; } but I guess we can't use this?????
    }
    return messages;
}

int* findMatching(string* hashtags, string* messages) {
    int matchCount = 1;
    int* hashtagMatchCount = new int[NUM_HASHTAGS];
    for(int i=0; i<NUM_HASHTAGS; i++) {
        hashtagMatchCount[i] = 0; //initialize all hashtag counts to 0
    }
    for(int i=0; i<MAX_MESSAGES; i+=2) {
        if(messages[i] != "" && messages[i+1] != "") {
            //Attempt to find message[i], the hashtag for this message, within the array of hashtags
            bool alreadyfound = false;
            for (int j = 0; j < NUM_HASHTAGS; j++) {
                if (!alreadyfound && messages[i] == hashtags[j]) {
                    cout << matchCount << ". " << hashtags[j] << " " << messages[i + 1] << endl;
                    matchCount++;
                    hashtagMatchCount[j]++;
                    alreadyfound = true;
                }
            }
        }
    }
    return hashtagMatchCount;
}

void printHashtagCounts(string* hashtags, int* counts) {
    for(int i=0; i<NUM_HASHTAGS; i++) {
        cout << left << setw(4) << i+1 << "\t" << setw(16) << hashtags[i] << "\t" << setw(4) << counts[i] << endl;
    }
}
*/