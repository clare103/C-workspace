//
//  TFIDF.cpp
//  TFIDF
//
//  Created by David Clare on 4/30/15.
//  Copyright (c) 2015 David Clare. All rights reserved.
//

#include "TFIDF.h"
#include <string>


using namespace std;

TFIDF::TFIDF()
{
    string word = "Python is a 2000 made-for-TV horror movie directed by RichardClabaugh.Thefilmfeatures several cult favorite actors, including WilliamZabka of The Karate Kid fame, Wil Wheaton, Casper Van Dien, Jenny McCarthy,Keith Coogan, Robert Englund (best known for his role as Freddy Krueger in the A Nightmare on Elm Street series of films), Dana Barron, David Bowe, and Sean Whalen. The film concerns a genetically engineered snake, a python, that escapes and unleashes itself on a small town. It includes the classic final girl scenario evident in films like Friday the 13th. It was filmed in Los Angeles, California and Malibu, California. Python was followed by two sequels: Python II (2002) and Boa vs. Python (2004), both also made-for-TV films.";
    
    int length = word.size();
    set_word_length(length);
   
    
}

TFIDF::~TFIDF(){}

void TFIDF::set_word_length(int a)
{
    word_length = a;
}

int TFIDF::get_word_length()
{
    return word_length;
}

void TFIDF::kmp_search(char *text_searched, char *subword)
{
    int size_t = sizeof(text_searched);
    int size_w = sizeof(subword);
    int m =0;
    int i=0;
    int *fail_safe;
    while(m+i < size_t)
    {
        if(subword[i] == text_searched[m+i])
        {
            if(i== size_w-1)
            {
                //cout << m;
            }
            i+=1;
        }
        else
        {
            if(fail_safe[i] > -1)
            {
                m = m+1 - fail_safe[i];
                i = fail_safe[i];
            }
            else
            {
                i=0;
                m+=1;
            }
        }
    }
}