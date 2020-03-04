/*

###############################################################################
#                                                                             #
#                 LICHEM: Layered Interacting CHEmical Models                 #
#                 By: Eric G. Kratz, Hatice Gokcan, Alice Walker,             #
#                     Erik Montelongo Vazquez, G. Andres Cisneros             #
#                                                                             #
#                      Symbiotic Computational Chemistry                      #
#                                                                             #
###############################################################################

 Text formatting functions for LICHEM.

 NB: These functions were written to make LICHEM text formatting consistent
 while not requiring additional libraries.

*/

//Number formatting functions
template<typename T>
string LICHEMFormFloat(T inpVal, int wid)
{
  //Resizes a floating-point number to a set number of characters
  //NB: This was a product of my frustration with stream settings
  stringstream oldValue;
  string newValue;
  //Initialize settings
  oldValue.str("");
  oldValue << fixed;
  oldValue.precision(wid);
  //Save input value to the string
  oldValue << inpVal;
  newValue = oldValue.str();
  //Check for a decimal place
  bool hasDot = 0;
  for (unsigned int i=0;i<newValue.length();i++)
  {
    if (newValue[i] == '.')
    {
      hasDot = 1;
    }
  }
  if (!hasDot)
  {
    //Fix integers
    if (LICHEMCount(newValue) < (wid-2))
    {
      //Add a decimal point
      newValue += ".";
    }
    else
    {
      //Escape if the integer is too long
      return newValue;
    }
  }
  int NChars = newValue.length();
  //Resize string
  if (NChars > wid)
  {
    //Delete characters
    newValue.erase(newValue.begin()+wid,newValue.end());
  }
  else
  {
    //Pad with zeros
    int diff = wid-NChars;
    for (int i=0;i<diff;i++)
    {
      //Add a zero
      newValue += "0";
    }
  }
  return newValue;
};

//String formatting functions
template<typename T> int LICHEMCount(T origVal)
{
  //Function to count the number of characters in a string or int
  stringstream origText; //Stream to convert origval to a string
  origText << origVal;
  string intText = origText.str();
  //Count characters and return
  int NChar = intText.length();
  return NChar;
};

void LICHEMLowerText(string& origText) // Mark Hix:  modified to use tolower() instead of individual case checks.
{
  //Function to switch a string to lowercase letters
  stringstream newText;
  newText.str("");
  for (unsigned int i=0;i<origText.length();i++)
  {
    //Check and change case
    newText << tolower(origText[i])
  }
  //Overwrite original string
  origText = newText.str();
  return;
};

void LICHEMUpperText(string& origText) // Mark Hix:  modified to use toupper() instead of individual case checks.
{
  //Function to switch a string to uppercase letters
  stringstream newText;
  newText.str("");
  for (unsigned int i=0;i<origText.length();i++)
  {
    //Check and change case
    newText << toupper(origText[i])
  }
  //Overwrite original string
  origText = newText.str();
  return;
};

void LICHEMFixSciNot(string& origText)
{
  //Function change D scientific notation to E notation
  for (unsigned int i=0;i<origText.length();i++)
  {
    //Check and change case
    if ((origText[i] == 'D') or (origText[i] == 'd'))
    {
      origText[i] = 'e';
    }
    if (origText[i] == 'E')
    {
      origText[i] = 'e';
    }
  }
  return;
};
