//
//  TFIDF.h
//  TFIDF
//
//  Created by David Clare on 4/30/15.
//  Copyright (c) 2015 David Clare. All rights reserved.
//

#ifndef __TFIDF__TFIDF__
#define __TFIDF__TFIDF__

#include <stdio.h>

using namespace std;

class TFIDF
{
public:
    TFIDF();
    ~TFIDF();
    
    void set_word_length(int a);
    int get_word_length();
    
    void kmp_search(char *text_searched, char* word);
    
    
    void set_TF_score();
    int get_tf_score();
    
    void set_IDF_score();
    int get_IDF_score();
    
    void set_count();
    int get_count();
    
    void set_TFIDF();
    int get_TFIDF();
    
    void set_n_containing();
    int get_n_containing();
    
    
    
    
    
private:
    int word_length, string_length, count;
    char *word, *text;
    
    
};

#endif /* defined(__TFIDF__TFIDF__) */
