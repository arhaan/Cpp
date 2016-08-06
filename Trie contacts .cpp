#include <vector>
#include <iostream>
#include<sstream>
#include <algorithm>
#include<string>
using namespace std;

class TrieNode{
  public: 
      bool is_end;
      int prefix_cnt;
      vector<TrieNode*> child;        
  
      TrieNode(){
          is_end=false;
          prefix_cnt=0;          
          child=vector<TrieNode*> (26, NULL);
      }
};

class Trie{
private:
   TrieNode *root;
public:
      Trie(){
		  root=new TrieNode();		  
       }
    
    void insertWord(const string & word){
          TrieNode *curr=root;
		  curr->prefix_cnt++;
		  for(int i=0;i<(int)word.size();i++){
		       int index= (int)word[i]-(int)'a';
			   if(curr->child[index]==NULL){
				   curr->child[index]=new TrieNode();   
			   }

			   curr->child[index]->prefix_cnt++;
			   curr=curr->child[index];
			   
		  }

		  curr->is_end=true;
    }

	bool searchWord(const string &word){
	    
		  TrieNode *curr=root;
		  for(int i=0;i<(int)word.size();i++){
		       int index= (int)word[i]-(int)'a';
			   if(curr->child[index]==NULL){
				   return false; 
			   }
			   curr=curr->child[index];

		  }

		  return curr->is_end;

	}

	int countWordsWithPrefix(const string &word){
	      TrieNode *curr=root;
		  for(int i=0;i<(int)word.size();i++){
		       int index= (int)word[i]-(int)'a';
			   if(curr->child[index]==NULL){
				   return 0; 
			   }
			   curr=curr->child[index];

		  }

		  return curr->prefix_cnt;
	
	}


    
};


int main() {
     int n;
     cin>>n;
      Trie t;
      while(n--){
         string line;
        
		 while (getline(cin, line)){
            
			stringstream ss(line);
            string first;
            string second;
            
            if (ss >> first >> second)
                        
            if(first=="add"){
                t.insertWord(second);
            }
             else{
                cout<<t.countWordsWithPrefix(second)<<endl; 
             }
          
      }
   }
    
    return 0;
}

/*
Trie tr;
	tr.insertWord("asad");
	tr.insertWord("salman");
	tr.insertWord("vinod");
	tr.insertWord("asa");
	tr.insertWord("sad");
	tr.insertWord("sadaf");
	tr.insertWord("arhaan");
	tr.insertWord("ali");
	tr.insertWord("hac");
	tr.insertWord("hacker");
	tr.insertWord("hackerrank");
	
	if(tr.searchWord("asad")){
	   cout<<"word asad found in the trie"<<endl;
	}
	else{
	   cout<<"word asad NOT found in the trie"<<endl;
	}

	cout<<"-------------------------------------------------------->"<<endl;

	if(tr.searchWord("aristocrat")){
	    cout<<"word asad found in the trie"<<endl;
	}
	else{
	   cout<<"word asad NOT found in the trie"<<endl;
	}

	cout<<"-------------------------------------------------------->"<<endl;

	cout<<"Number of words starting from the prefix hac is "<<tr.countWordsWithPrefix("as")<<endl;


    return 0;
*/
