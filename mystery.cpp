#include <iostream>
#include <vector>

using namespace std;

    void print(auto A)
    {
       for (auto a : A) 
            cout <<a<<" ";

       cout<<endl;
    }
    void mystery1(auto& Data)
    {
      cout<<endl<<"Mystery 1"<<endl<<"---------------------"<<endl;

      int passes = 0;
      for (int i = 0; i < Data.size(); i++)
      {
    
        if (i >= 1) { passes++; }
        if (passes > 0)
        {
          cout << endl << "Pass: " << passes << ", i = " << i << endl;
          print(Data);
        }
        else
        {
          cout << endl << "Original:(start)" << ", i = " << i << endl;
          print(Data);
          cout << endl;
        }

        for (int j = 0; j < i; j++)
        {
          if (Data[i] < Data[j])
          {
            swap(Data[i], Data[j]);
          }
        }

      }//end outer for (this brace is needed to include the print statement)

    }
    void mystery2(auto& Data)
    {
      cout << endl << "Mystery 2" << endl << "---------------------" << endl;
      int passes = 0;

      for (int i = 0; i < Data.size(); i++)
      {

        if (i >= 1) { passes++; }
        if (passes > 0)
        {
          cout << endl << "Pass: " << passes << ", i = " << i << endl;
          print(Data);
        }
        else
        {
          cout << endl << "Original:(start)" << ", i = " << i << endl;
          print(Data);
          cout << endl;
        }



        for (int j = 0; j < Data.size() - 1; j++)
        {
          if (Data[j + 1] < Data[j])
          {
            swap(Data[j + 1], Data[j]);
          }
        }

      }//end outer for (this brace is needed to include the print statement)

    }
    void mystery3(auto& Data)
    {
      cout << endl << "Mystery 3" << endl << "---------------------" << endl;
      int passes = 0;

      for (int i = 0; i < Data.size(); i++)
      {


        if (i >= 1) { passes++; }
        if (passes > 0)
        {
          cout << endl << "Pass: " << passes << ", i = " << i << endl;
          print(Data);
        }
        else
        {
          cout << endl << "Original:(start)" << ", i = " << i << endl;
          print(Data);
          cout << endl;
        }



        for (int j = i; j < Data.size() - 1; j++)
        {
          if (Data[j] < Data[i])
          {
            swap(Data[i], Data[j]);
          }
        }

      }//end outer for (this brace is needed to include the print statement)

    }

int main()
{
  vector<int> Data = {36, 18, 22, 30, 29, 25, 12};

  vector<int> D1 = Data;
  vector<int> D2 = Data;
  vector<int> D3 = Data;

  cout << endl << "Question a" << endl;
  cout << endl << "(a) For each of the \"mystery\" code segments provided, show the contents of the Data vector after each pass (of the outer loop). In each case assume that the vector Data = {36, 18, 22, 30, 29, 25, 12} initially." << endl;

  cout << endl << "Mystery 1" << endl;
  cout << "for (int i = 0; i < Data.size(); i++)" << endl << "{" << endl << "\t for (int j = 0; j < i; j++)" << endl << "\t{" << endl << "\t\tif (Data[i] < Data[j])" << endl << "\t\t{" << endl << "\t\t\tswap(Data[i], Data[j]);" << endl << "\t\t}" << endl << "\t}" << endl << "}" << endl;

  cout << endl << "Mystery 2" << endl;
  cout << "for (int i = 0; i < Data.size(); i++)" << endl << "{" << endl << "\t for (int j = 0; j < Data.size()-1; j++)" << endl << "\t{" << endl << "\t\tif (Data[j+1] < Data[j])" << endl << "\t\t{" << endl << "\t\t\tswap(Data[j+1], Data[j]);" << endl << "\t\t}" << endl << "\t}" << endl << "}" << endl;

  cout << endl << "Mystery 3" << endl;
  cout << "for (int i = 0; i < Data.size(); i++)" << endl << "{" << endl << "\t for (int j = i; j < Data.size(); j++)" << endl << "\t{" << endl << "\t\tif (Data[j] < Data[i])" << endl << "\t\t{" << endl << "\t\t\tswap(Data[i], Data[j]);" << endl << "\t\t}" << endl << "\t}" << endl << "}" << endl;

  mystery1(D1);
  mystery2(D2);
  mystery3(D3);

  cout << endl << "Question b" << endl;
  cout << endl << "(b) Hence, state the name of the algorithm (taught during the course) each code segment most closely resembles in behavior. Explain your answer in each case." << endl;

  cout << endl << "Mystery 1 closely Resembles the: bubble sort, but the first pass does nothing to the element list, this happens because the code starts off as i = 0 and also j = 0, so the condition j < i (0 < 0) makes the code segment waste a 'pass' and the element list has wasn't updated/changed" << endl << "then when i = 1, j = 0 and the condition j < i (0 < 1) is true so the loop proceeds to the if statement and checks the condition 'if' (Data[j+i] < Data[j])" << endl << "Data at index 'j' or '0' is 18" << endl << "so the condition is true so a swap is performed, then j = 1 and also  i = 1" << endl << "so the condition is not met so instead of several swaps per pass 'n- (pass #)' the code elements are only swapped once per pass" << endl;
  cout << "Mystery 2 closely Resembles the: bubble sort" << endl << "\t because after each pass the highest element is at the right most position (end) of the element list" << endl;
  cout << "Mystery 3 closely Resembles the: selection sort because it compares a single value to the majority of the elements in the list similar to how the smallest element in a list is held on too and compared to other elements in the selection sort" << endl << "in the code segment i = 0, j = i (j = 0) so the condition of (Data[j] < Data[i]) '36 < 36' will not work so no swap was done for the first iteration of j, on the second iteration i = 0, j = 1 so the condition Data[j] < Data[i] '18 < 36' was met and a swap was made creating {18,36,22,30,29,25,12}" << endl;

  cout << endl << "Question c" << endl;
  cout << endl << "(c) State the maximum number of iterations of the Binary Search algorithm when run on 'n' elements." << endl << "The maximum number of iterations of the Binary Search algorithm when run on 'n' elements is 'n-1'" << endl;

  return 0;
}
