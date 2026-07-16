#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "header/csv.h"
int main(int argc, char* argv[]) {
    
   if (argc < 2) {
      std::cerr << "Usage: " << argv[0] << " /path/to/jacoco.csv" << std::endl;
      return 1;
   }
   std::string filename = argv[1];
   bool state = std::filesystem::exists(filename);
   if (state){
     
      io::CSVReader<10> in(filename);
      in.read_header(io::ignore_extra_column,"INSTRUCTION_MISSED","INSTRUCTION_COVERED","BRANCH_MISSED","BRANCH_COVERED","LINE_MISSED","LINE_COVERED","COMPLEXITY_MISSED","COMPLEXITY_COVERED","METHOD_MISSED","METHOD_COVERED");
      int INSTRUCTION_MISSED;
      int INSTRUCTION_COVERED;
      int BRANCH_MISSED;
      int BRANCH_COVERED;
      int LINE_MISSED;
      int LINE_COVERED;
      int COMPLEXITY_MISSED;
      int COMPLEXITY_COVERED;
      int METHOD_MISSED;
      int METHOD_COVERED;

      //Totals
      int INSTRUCTION_MISSED_Total = 0;
      int INSTRUCTION_COVERED_Total = 0;
      int BRANCH_MISSED_Total = 0;
      int BRANCH_COVERED_Total = 0;
      int LINE_MISSED_Total = 0;
      int LINE_COVERED_Total = 0;
      int COMPLEXITY_MISSED_Total = 0;
      int COMPLEXITY_COVERED_Total = 0;
      int METHOD_MISSED_Total = 0;
      int METHOD_COVERED_Total = 0;

      while (in.read_row(INSTRUCTION_MISSED,INSTRUCTION_COVERED,BRANCH_MISSED,BRANCH_COVERED,LINE_MISSED,LINE_COVERED,COMPLEXITY_MISSED,COMPLEXITY_COVERED,METHOD_MISSED,METHOD_COVERED)){
       
        INSTRUCTION_COVERED_Total+=INSTRUCTION_COVERED;
        INSTRUCTION_MISSED_Total+=INSTRUCTION_MISSED;
        BRANCH_COVERED_Total+=BRANCH_COVERED;
        BRANCH_MISSED_Total+=BRANCH_MISSED;
        LINE_COVERED_Total+=LINE_COVERED;
        LINE_MISSED_Total+=LINE_MISSED;
        COMPLEXITY_COVERED_Total+=COMPLEXITY_COVERED;
        COMPLEXITY_MISSED_Total+=COMPLEXITY_MISSED;
        METHOD_COVERED_Total+=METHOD_COVERED;
        METHOD_MISSED_Total+=METHOD_MISSED;

         
      }
      float INSTRUCTION_TOTAL=INSTRUCTION_COVERED_Total+INSTRUCTION_MISSED_Total;
      float BRANCH_TOTAL=BRANCH_COVERED_Total+BRANCH_MISSED_Total;
      float LINE_TOTAL=LINE_COVERED_Total+LINE_MISSED_Total;
      float COMPLEX_TOTAL=COMPLEXITY_COVERED_Total+COMPLEXITY_MISSED_Total;
      float METHOD_TOTAL=METHOD_COVERED_Total+METHOD_MISSED_Total;

      std::cout<<"Instruction Coverage:,"<<(INSTRUCTION_COVERED_Total/INSTRUCTION_TOTAL)*100<<"%"<< std::endl;
      std::cout<<"Branch Coverage:,"<<(BRANCH_COVERED_Total/BRANCH_TOTAL)*100<<"%"<< std::endl;
      std::cout<<"Line Coverage:,"<<(LINE_COVERED_Total/LINE_TOTAL)*100<<"%"<< std::endl;
      std::cout<<"Complexity Coverage:,"<<(COMPLEXITY_COVERED_Total/COMPLEX_TOTAL)*100<<"%"<< std::endl;
      std::cout<<"Method Coverage:,"<<(METHOD_COVERED_Total/METHOD_TOTAL)*100<<"%"<< std::endl;


     
      
   }
   else{
      std::cerr<<"file not found please point to the path of the jacoco.csv file"<<std::endl;
   }
   

  

   

   
}