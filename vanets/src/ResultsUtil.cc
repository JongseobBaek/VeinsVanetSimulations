//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "ResultsUtil.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;


double ResultsUtil::totalAvg(const char* fileName, string resultType){

		
    string word = "";
	string value = "";
	stringstream lineStream;
	double currentAvg = 0;
	double newValue = 0; 
	double numOfValues = 0; 
	
	ifstream myFile;
 	myFile.open(fileName);
	
	if(myFile.is_open()){
		while(myFile>>word){
			cout<<"***********Word: " << word << endl;
			cout<<"*****ResultType: " << resultType<<endl; 
			if (word.compare(resultType)==0){
				myFile >> value;
				newValue = (double) atof(value.c_str());
				currentAvg = ((currentAvg*numOfValues) +newValue)/(numOfValues+1);
				numOfValues++;  
			}

		}
	
		myFile.close();			
	}else{
	
		wcerr<<"ERROR: Cannot open : "<<fileName <<endl; 
	}
     
	return currentAvg; 

}

ResultsUtil::~ResultsUtil(){

}
