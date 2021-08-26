#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <regex>


using namespace std;

// title, author
typedef pair<string, string> ss;


int 
search_insert_index(vector<ss> v, ss book) {
  int start=0, end=v.size()-1, mid; 
  if (start>end)
    return 0;

  while(start<=end) {
    mid = start+(end-start)/2;
    if (start==end) {
      return (book>=v[mid]) ? mid+1:mid;
    }
    if(book==v[mid]) {
      return mid+1;
    } else if(book>v[mid]) {
      start = mid+1;
    } else {
      end = mid-1;
    }
  }
  return mid; 
}

int 
find_title_binary(vector<ss> v, string title) {
  int start=0, end=v.size()-1, mid; 
  if (start>end)
    return -1;

  while(start<=end) {
    mid = start+(end-start)/2;
    if (start==end) {
      return (title==v[mid].first) ? mid:-1;
    }
    if(title==v[mid].first) {
      return mid;
    }
    else if(title>v[mid].first) {
      start = mid+1;
    }
    else
      end = mid-1;
  }
  return -1;
}

int 
find_title_linear(vector<ss> v, string title) {
  for(size_t i=0; i<v.size(); ++i) {
    if(title==v[i].second) {
      return i;
    }
  }
  return -1;
}

int main() {
  string book;
  vector<ss> instock, outstock, returns;

  //placing all the books on the shelves
  while(getline(cin, book), book!="END") {
    smatch matches; 
    regex_search(book, matches, regex("(\".*\") by (.*)"));
    string title(matches[1].str()), 
           author(matches[2].str());
    int idx = search_insert_index(instock, ss(author, title));
    instock.insert(instock.begin()+idx, ss(author, title));
  }



  string instruction;
  while(getline(cin, instruction), instruction!="END") {
    istringstream iss(instruction);
    string command; iss >> command;
    if(command == "BORROW") {
      smatch matches; 
      regex_search(instruction, matches, regex("(\".*\")"));
      string title(matches[1].str());
      size_t idx = find_title_linear(instock, title);
      size_t idx1 = search_insert_index(outstock, ss(instock[idx].second, instock[idx].first));
      outstock.insert(outstock.begin()+idx1, ss(instock[idx].second, instock[idx].first));
      instock.erase(instock.begin()+idx);
    } else if (command == "RETURN") {
      smatch matches; 
      regex_search(instruction, matches, regex("(\".*\")"));
      string title(matches[1].str());
      size_t idx = find_title_binary(outstock, title);
      size_t idx1 = search_insert_index(returns, ss(outstock[idx].second, outstock[idx].first));
      returns.insert(returns.begin()+idx1, ss(outstock[idx].second, outstock[idx].first));
      outstock.erase(outstock.begin()+idx);
    } else {
      for(int i=0; i<returns.size(); ++i) {
        size_t idx = search_insert_index(instock, returns[i]);
        if(idx > 0) {
          cout 
            << "Put "
            << returns[i].second
            <<  " after "
            << instock[idx-1].second << endl;
        } else {
          cout 
            << "Put "
            << returns[i].second
            <<  " first\n";
        }
        instock.insert(instock.begin()+idx, returns[i]);
      }
      cout << "END\n";
      returns.clear();
    }
  }
    
}
